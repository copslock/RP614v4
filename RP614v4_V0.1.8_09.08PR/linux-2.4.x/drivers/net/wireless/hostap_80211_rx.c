#include <linux/etherdevice.h>

#include "hostap_80211.h"
#include "hostap.h"

void hostap_dump_rx_80211(const char *name, struct sk_buff *skb,
			  struct hostap_80211_rx_status *rx_stats)
{
	struct hostap_ieee80211_hdr *hdr;
	u16 fc;

	hdr = (struct hostap_ieee80211_hdr *) skb->data;

	printk("%s: RX signal=%d noise=%d rate=%d len=%d "
	       "jiffies=%ld\n",
	       name, rx_stats->signal, rx_stats->noise, rx_stats->rate,
	       skb->len, jiffies);

	if (skb->len < 2)
		return;

	fc = le16_to_cpu(hdr->frame_control);
	printk("   FC=0x%04x (type=%d:%d)%s%s",
	       fc, WLAN_FC_GET_TYPE(fc), WLAN_FC_GET_STYPE(fc),
	       fc & WLAN_FC_TODS ? " [ToDS]" : "",
	       fc & WLAN_FC_FROMDS ? " [FromDS]" : "");

	if (skb->len < IEEE80211_DATA_HDR3_LEN) {
		printk("\n");
		return;
	}

	printk(" dur=0x%04x seq=0x%04x\n", le16_to_cpu(hdr->duration_id),
	       le16_to_cpu(hdr->seq_ctrl));

	printk("   A1=" MACSTR " A2=" MACSTR " A3=" MACSTR,
	       MAC2STR(hdr->addr1), MAC2STR(hdr->addr2), MAC2STR(hdr->addr3));
	if (skb->len >= 30)
		printk(" A4=" MACSTR, MAC2STR(hdr->addr4));
	printk("\n");
}


/* Send RX frame to netif with 802.11 (and possible prism) header.
 * Called from hardware or software IRQ context. */
int prism2_rx_80211(struct net_device *dev, struct sk_buff *skb,
		    struct hostap_80211_rx_status *rx_stats, int type)
{
	struct hostap_interface *iface = dev->priv;
	local_info_t *local = iface->local;
	int hdrlen, phdrlen, head_need, tail_need;
	u16 fc;
	int prism_header, ret;
	struct hostap_ieee80211_hdr *hdr;

	dev->last_rx = jiffies;

	if (dev->type == ARPHRD_IEEE80211_PRISM) {
		if (local->monitor_type == PRISM2_MONITOR_PRISM) {
			prism_header = 1;
			phdrlen = sizeof(struct linux_wlan_ng_prism_hdr);
		} else { /* local->monitor_type == PRISM2_MONITOR_CAPHDR */
			prism_header = 2;
			phdrlen = sizeof(struct linux_wlan_ng_cap_hdr);
		}
	} else {
		prism_header = 0;
		phdrlen = 0;
	}

	hdr = (struct hostap_ieee80211_hdr *) skb->data;
	fc = le16_to_cpu(hdr->frame_control);

	if (type == PRISM2_RX_MGMT && (fc & WLAN_FC_PVER)) {
		printk(KERN_DEBUG "%s: dropped management frame with header "
		       "version %d\n", dev->name, fc & WLAN_FC_PVER);
		dev_kfree_skb_any(skb);
		return 0;
	}

	hdrlen = hostap_80211_get_hdrlen(fc);

	/* check if there is enough room for extra data; if not, expand skb
	 * buffer to be large enough for the changes */
	head_need = phdrlen;
	tail_need = 0;
#ifdef PRISM2_ADD_BOGUS_CRC
	tail_need += 4;
#endif /* PRISM2_ADD_BOGUS_CRC */

#if (LINUX_VERSION_CODE < KERNEL_VERSION(2,4,0))
	if (head_need > skb_headroom(skb) || tail_need > skb_tailroom(skb)) {
		struct sk_buff *nskb;

		nskb = dev_alloc_skb(skb->len + head_need + tail_need);
		if (nskb == NULL) {
			dev_kfree_skb_any(skb);
			return 0;
		}

		skb_reserve(nskb, head_need);
		memcpy(skb_put(nskb, skb->len), skb->data, skb->len);
		dev_kfree_skb_any(skb);
		skb = nskb;
	}
#else /* Linux 2.4.0 or newer */
	head_need -= skb_headroom(skb);
	tail_need -= skb_tailroom(skb);

	if (head_need > 0 || tail_need > 0) {
		if (pskb_expand_head(skb, head_need > 0 ? head_need : 0,
				     tail_need > 0 ? tail_need : 0,
				     GFP_ATOMIC)) {
			printk(KERN_DEBUG "%s: prism2_rx_80211 failed to "
			       "reallocate skb buffer\n", dev->name);
			dev_kfree_skb_any(skb);
			return 0;
		}
	}
#endif

	/* We now have an skb with enough head and tail room, so just insert
	 * the extra data */

#ifdef PRISM2_ADD_BOGUS_CRC
	memset(skb_put(skb, 4), 0xff, 4); /* Prism2 strips CRC */
#endif /* PRISM2_ADD_BOGUS_CRC */

	if (prism_header == 1) {
		struct linux_wlan_ng_prism_hdr *hdr;
		hdr = (struct linux_wlan_ng_prism_hdr *)
			skb_push(skb, phdrlen);
		memset(hdr, 0, phdrlen);
		hdr->msgcode = LWNG_CAP_DID_BASE;
		hdr->msglen = sizeof(*hdr);
		memcpy(hdr->devname, dev->name, sizeof(hdr->devname));
#define LWNG_SETVAL(f,i,s,l,d) \
hdr->f.did = LWNG_CAP_DID_BASE | (i << 12); \
hdr->f.status = s; hdr->f.len = l; hdr->f.data = d
		LWNG_SETVAL(hosttime, 1, 0, 4, jiffies);
		LWNG_SETVAL(mactime, 2, 0, 0, rx_stats->mac_time);
		LWNG_SETVAL(channel, 3, 1 /* no value */, 4, 0);
		LWNG_SETVAL(rssi, 4, 1 /* no value */, 4, 0);
		LWNG_SETVAL(sq, 5, 1 /* no value */, 4, 0);
		LWNG_SETVAL(signal, 6, 0, 4, rx_stats->signal);
		LWNG_SETVAL(noise, 7, 0, 4, rx_stats->noise);
		LWNG_SETVAL(rate, 8, 0, 4, rx_stats->rate / 5);
		LWNG_SETVAL(istx, 9, 0, 4, 0);
		LWNG_SETVAL(frmlen, 10, 0, 4, skb->len - phdrlen);
#undef LWNG_SETVAL
	} else if (prism_header == 2) {
		struct linux_wlan_ng_cap_hdr *hdr;
		hdr = (struct linux_wlan_ng_cap_hdr *)
			skb_push(skb, phdrlen);
		memset(hdr, 0, phdrlen);
		hdr->version    = htonl(LWNG_CAPHDR_VERSION);
		hdr->length     = htonl(phdrlen);
		hdr->mactime    = __cpu_to_be64(rx_stats->mac_time);
		hdr->hosttime   = __cpu_to_be64(jiffies);
		hdr->phytype    = htonl(4); /* dss_dot11_b */
		hdr->channel    = htonl(local->channel);
		hdr->datarate   = htonl(rx_stats->rate);
		hdr->antenna    = htonl(0); /* unknown */
		hdr->priority   = htonl(0); /* unknown */
		hdr->ssi_type   = htonl(3); /* raw */
		hdr->ssi_signal = htonl(rx_stats->signal);
		hdr->ssi_noise  = htonl(rx_stats->noise);
		hdr->preamble   = htonl(0); /* unknown */
		hdr->encoding   = htonl(1); /* cck */
	}

	ret = skb->len - phdrlen;
	skb->dev = dev;
	skb->mac.raw = skb->data;
	skb_pull(skb, hdrlen);
	if (prism_header)
		skb_pull(skb, phdrlen);
	skb->pkt_type = PACKET_OTHERHOST;
	skb->protocol = __constant_htons(ETH_P_802_2);
	memset(skb->cb, 0, sizeof(skb->cb));
	netif_rx(skb);

	return ret;
}


/* Called only as a tasklet (software IRQ) */
static void monitor_rx(struct net_device *dev, struct sk_buff *skb,
		       struct hostap_80211_rx_status *rx_stats)
{
	struct net_device_stats *stats;
	int len;

	len = prism2_rx_80211(dev, skb, rx_stats, PRISM2_RX_MONITOR);
	stats = hostap_get_stats(dev);
	stats->rx_packets++;
	stats->rx_bytes += len;
}


/* Called only as a tasklet (software IRQ) */
static struct prism2_frag_entry *
prism2_frag_cache_find(local_info_t *local, unsigned int seq,
		       unsigned int frag, u8 *src, u8 *dst)
{
	struct prism2_frag_entry *entry;
	int i;

	for (i = 0; i < PRISM2_FRAG_CACHE_LEN; i++) {
		entry = &local->frag_cache[i];
		if (entry->skb != NULL &&
		    time_after(jiffies, entry->first_frag_time + 2 * HZ)) {
			printk(KERN_DEBUG "%s: expiring fragment cache entry "
			       "seq=%u last_frag=%u\n",
			       local->dev->name, entry->seq, entry->last_frag);
			dev_kfree_skb(entry->skb);
			entry->skb = NULL;
		}

		if (entry->skb != NULL && entry->seq == seq &&
		    (entry->last_frag + 1 == frag || frag == -1) &&
		    memcmp(entry->src_addr, src, ETH_ALEN) == 0 &&
		    memcmp(entry->dst_addr, dst, ETH_ALEN) == 0)
			return entry;
	}

	return NULL;
}


/* Called only as a tasklet (software IRQ) */
static struct sk_buff *
prism2_frag_cache_get(local_info_t *local, struct hostap_ieee80211_hdr *hdr)
{
	struct sk_buff *skb = NULL;
	u16 sc;
	unsigned int frag, seq;
	struct prism2_frag_entry *entry;

	sc = le16_to_cpu(hdr->seq_ctrl);
	frag = WLAN_GET_SEQ_FRAG(sc);
	seq = WLAN_GET_SEQ_SEQ(sc);

	if (frag == 0) {
		/* Reserve enough space to fit maximum frame length */
		skb = dev_alloc_skb(local->dev->mtu +
				    sizeof(struct hostap_ieee80211_hdr) +
				    8 /* LLC */ +
				    2 /* alignment */ +
				    8 /* WEP */ + ETH_ALEN /* WDS */);
		if (skb == NULL)
			return NULL;

		entry = &local->frag_cache[local->frag_next_idx];
		local->frag_next_idx++;
		if (local->frag_next_idx >= PRISM2_FRAG_CACHE_LEN)
			local->frag_next_idx = 0;

		if (entry->skb != NULL)
			dev_kfree_skb(entry->skb);

		entry->first_frag_time = jiffies;
		entry->seq = seq;
		entry->last_frag = frag;
		entry->skb = skb;
		memcpy(entry->src_addr, hdr->addr2, ETH_ALEN);
		memcpy(entry->dst_addr, hdr->addr1, ETH_ALEN);
	} else {
		/* received a fragment of a frame for which the head fragment
		 * should have already been received */
		entry = prism2_frag_cache_find(local, seq, frag, hdr->addr2,
					       hdr->addr1);
		if (entry != NULL) {
			entry->last_frag = frag;
			skb = entry->skb;
		}
	}

	return skb;
}


/* Called only as a tasklet (software IRQ) */
static int prism2_frag_cache_invalidate(local_info_t *local,
					struct hostap_ieee80211_hdr *hdr)
{
	u16 sc;
	unsigned int seq;
	struct prism2_frag_entry *entry;

	sc = le16_to_cpu(hdr->seq_ctrl);
	seq = WLAN_GET_SEQ_SEQ(sc);

	entry = prism2_frag_cache_find(local, seq, -1, hdr->addr2, hdr->addr1);

	if (entry == NULL) {
		printk(KERN_DEBUG "%s: could not invalidate fragment cache "
		       "entry (seq=%u)\n",
		       local->dev->name, seq);
		return -1;
	}

	entry->skb = NULL;
	return 0;
}


static inline int
hostap_rx_frame_mgmt(local_info_t *local, struct sk_buff *skb,
		     struct hostap_80211_rx_status *rx_stats, u16 type,
		     u16 stype)
{
	if (local->iw_mode == IW_MODE_MASTER) {
		hostap_update_sta_ps(local, (struct hostap_ieee80211_hdr *)
				     skb->data);
	}

	if (local->hostapd && type == WLAN_FC_TYPE_MGMT) {
		if (stype == WLAN_FC_STYPE_BEACON &&
		    local->iw_mode == IW_MODE_MASTER) {
			struct sk_buff *skb2;
			/* Process beacon frames also in kernel driver to
			 * update STA(AP) table statistics */
			skb2 = skb_clone(skb, GFP_ATOMIC);
			//TRACE(3);
			if (skb2)
				hostap_rx(skb2->dev, skb2, rx_stats);
		}

		/* send management frames to the user space daemon for
		 * processing */
		local->apdevstats.rx_packets++;
		local->apdevstats.rx_bytes += skb->len;
		prism2_rx_80211(local->apdev, skb, rx_stats, PRISM2_RX_MGMT);
		return 0;
	}

	if (local->iw_mode == IW_MODE_MASTER) {
		if (type != WLAN_FC_TYPE_MGMT && type != WLAN_FC_TYPE_CTRL) {
			printk(KERN_DEBUG "%s: unknown management frame "
			       "(type=0x%02x, stype=0x%02x) dropped\n",
			       skb->dev->name, type, stype);
			return -1;
		}

		//TRACE(3);
		hostap_rx(skb->dev, skb, rx_stats);
		
		return 0;
	} else {
		printk(KERN_DEBUG "%s: hostap_rx_frame_mgmt: management frame "
		       "received in non-Host AP mode\n", skb->dev->name);
		return -1;
	}
}


/* Called only as a tasklet (software IRQ) */
static inline struct net_device *prism2_rx_get_wds(local_info_t *local,
						   u8 *addr)
{
	struct hostap_interface *iface = NULL;
	struct list_head *ptr;

	read_lock_bh(&local->iface_lock);
	list_for_each(ptr, &local->hostap_interfaces) {
		iface = list_entry(ptr, struct hostap_interface, list);
		if (iface->type == HOSTAP_INTERFACE_WDS &&
		    memcmp(iface->u.wds.remote_addr, addr, ETH_ALEN) == 0)
			break;
		iface = NULL;
	}
	read_unlock_bh(&local->iface_lock);

	return iface ? iface->dev : NULL;
}


static inline int
hostap_rx_frame_wds(local_info_t *local, struct hostap_ieee80211_hdr *hdr,
		    u16 fc, struct net_device **wds)
{
	/* FIX: is this really supposed to accept WDS frames only in Master
	 * mode? What about Repeater or Managed with WDS frames? */
	if ((fc & (WLAN_FC_TODS | WLAN_FC_FROMDS)) !=
	    (WLAN_FC_TODS | WLAN_FC_FROMDS) &&
	    (local->iw_mode != IW_MODE_MASTER || !(fc & WLAN_FC_TODS)))
		return 0; /* not a WDS frame */

	/* Possible WDS frame: either IEEE 802.11 compliant (if FromDS)
	 * or own non-standard frame with 4th address after payload */
	if (memcmp(hdr->addr1, local->dev->dev_addr, ETH_ALEN) != 0 &&
	    (hdr->addr1[0] != 0xff || hdr->addr1[1] != 0xff ||
	     hdr->addr1[2] != 0xff || hdr->addr1[3] != 0xff ||
	     hdr->addr1[4] != 0xff || hdr->addr1[5] != 0xff)) {
		/* RA (or BSSID) is not ours - drop */
		PDEBUG(DEBUG_EXTRA, "%s: received WDS frame with "
		       "not own or broadcast %s=" MACSTR "\n",
		       local->dev->name, fc & WLAN_FC_FROMDS ? "RA" : "BSSID",
		       MAC2STR(hdr->addr1));
		return -1;
	}

	/* check if the frame came from a registered WDS connection */
	*wds = prism2_rx_get_wds(local, hdr->addr2);
	if (*wds == NULL && fc & WLAN_FC_FROMDS &&
	    (local->iw_mode != IW_MODE_INFRA ||
	     !(local->wds_type & HOSTAP_WDS_AP_CLIENT) ||
	     memcmp(hdr->addr2, local->bssid, ETH_ALEN) != 0)) {
		/* require that WDS link has been registered with TA or the
		 * frame is from current AP when using 'AP client mode' */
		PDEBUG(DEBUG_EXTRA, "%s: received WDS[4 addr] frame "
		       "from unknown TA=" MACSTR "\n",
		       local->dev->name, MAC2STR(hdr->addr2));
		if (local->ap && local->ap->autom_ap_wds)
			hostap_wds_link_oper(local, hdr->addr2, WDS_ADD);
		return -1;
	}

	if (*wds && !(fc & WLAN_FC_FROMDS) && local->ap &&
	    hostap_is_sta_assoc(local->ap, hdr->addr2)) {
		/* STA is actually associated with us even though it has a
		 * registered WDS link. Assume it is in 'AP client' mode.
		 * Since this is a 3-addr frame, assume it is not (bogus) WDS
		 * frame and process it like any normal ToDS frame from
		 * associated STA. */
		*wds = NULL;
	}

	return 0;
}


static int hostap_is_eapol_frame(local_info_t *local,
				 struct hostap_ieee80211_hdr *hdr, u8 *buf,
				 int len)
{
	struct net_device *dev = local->dev;
	u16 fc, ethertype;

	fc = le16_to_cpu(hdr->frame_control);

	/* check that the frame is unicast frame to us */
	if ((fc & (WLAN_FC_TODS | WLAN_FC_FROMDS)) == WLAN_FC_TODS &&
	    memcmp(hdr->addr1, dev->dev_addr, ETH_ALEN) == 0 &&
	    memcmp(hdr->addr3, dev->dev_addr, ETH_ALEN) == 0) {
		/* ToDS frame with own addr BSSID and DA */
	} else if ((fc & (WLAN_FC_TODS | WLAN_FC_FROMDS)) == WLAN_FC_FROMDS &&
		   memcmp(hdr->addr1, dev->dev_addr, ETH_ALEN) == 0) {
		/* FromDS frame with own addr as DA */
	} else
		return 0;

	if (len < 8)
		return 0;

	/* check for port access entity Ethernet type */
	ethertype = (buf[6] << 8) | buf[7];
	if (ethertype == ETH_P_PAE)
		return 1;

	return 0;
}


/* Called only as a tasklet (software IRQ) */
static inline int
hostap_rx_frame_decrypt(local_info_t *local, int iswep, struct sk_buff *skb)
{
	struct hostap_ieee80211_hdr *hdr;
	struct prism2_crypt_data *crypt;
	void *sta = NULL;
	int ret = 0, olen, len, hdrlen;
	char *payload;

	hdr = (struct hostap_ieee80211_hdr *) skb->data;
	hdrlen = hostap_80211_get_hdrlen(le16_to_cpu(hdr->frame_control));

	len = skb->len - hdrlen;
	payload = ((char *) (hdr)) + hdrlen;
	crypt = local->crypt;
	sta = NULL;

	/* Use station specific key to override default keys if the receiver
	 * address is a unicast address ("individual RA"). If bcrx_sta_key
	 * parameter is set, station specific key is used even with
	 * broad/multicast targets (this is against IEEE 802.11, but makes it
	 * easier to use different keys with stations that do not support WEP
	 * key mapping). */
	if (!(hdr->addr1[0] & 0x01) || local->bcrx_sta_key)
		(void) hostap_handle_sta_crypto(local, hdr, &crypt, &sta);

	/* allow NULL decrypt to indicate an station specific override for
	 * default encryption */
	if (crypt && (crypt->ops == NULL || crypt->ops->decrypt == NULL))
		crypt = NULL;

	if (!crypt && iswep) {
		printk(KERN_DEBUG "%s: WEP decryption failed (not set) (SA="
		       MACSTR ")\n", local->dev->name, MAC2STR(hdr->addr2));
		local->comm_tallies.rx_discards_wep_undecryptable++;
		ret = -1;
		goto done;
	}

	if (!crypt)
		goto done;

	if (!iswep && !local->open_wep) {
		if (local->ieee_802_1x &&
		    hostap_is_eapol_frame(local, hdr, payload, len)) {
			/* pass unencrypted EAPOL frames even if encryption is
			 * configured */
			printk(KERN_DEBUG "%s: RX: IEEE 802.1X - passing "
			       "unencrypted EAPOL frame\n", local->dev->name);
			goto done;
		}
		printk(KERN_DEBUG "%s: encryption configured, but RX frame "
		       "not encrypted (SA=" MACSTR ")\n",
		       local->dev->name, MAC2STR(hdr->addr2));
		ret = -1;
		goto done;
	}

	/* decrypt WEP part of the frame: IV (4 bytes), encrypted
	 * payload (including SNAP header), ICV (4 bytes) */
	atomic_inc(&crypt->refcnt);
	olen = crypt->ops->decrypt(payload, len, crypt->priv);
	atomic_dec(&crypt->refcnt);
	if (olen < 0) {
		printk(KERN_DEBUG "%s: WEP decryption failed (SA=" MACSTR
		       ")\n", local->dev->name, MAC2STR(hdr->addr2));
		local->comm_tallies.rx_discards_wep_undecryptable++;
		ret = -1;
		goto done;
	}

	skb_trim(skb, skb->len - (len - olen));

 done:
	if (sta)
		hostap_handle_sta_release(sta);

	return ret;
}


/* All received frames are sent to this function. @skb contains the frame in
 * IEEE 802.11 format, i.e., in the format it was sent over air.
 * This function is called only as a tasklet (software IRQ). */
void hostap_80211_rx(struct net_device *dev, struct sk_buff *skb,
		     struct hostap_80211_rx_status *rx_stats)
{
	struct hostap_interface *iface = dev->priv;
	local_info_t *local = iface->local;
	struct hostap_ieee80211_hdr *hdr;
	size_t hdrlen;
	u16 fc, type, stype, sc;
	struct net_device *wds = NULL;
	struct net_device_stats *stats;
	unsigned int frag;
	u8 *payload;
	struct sk_buff *skb2 = NULL;
	u16 ethertype;
	int frame_authorized = 0;
	int from_assoc_ap = 0;
	u8 dst[ETH_ALEN];
	u8 src[ETH_ALEN];
	//TRACE(3);
	hdr = (struct hostap_ieee80211_hdr *) skb->data;
	stats = hostap_get_stats(dev);

	if (skb->len < 10)
		goto rx_dropped;

	fc = le16_to_cpu(hdr->frame_control);
	type = WLAN_FC_GET_TYPE(fc);
	stype = WLAN_FC_GET_STYPE(fc);
	sc = le16_to_cpu(hdr->seq_ctrl);
	frag = WLAN_GET_SEQ_FRAG(sc);
	hdrlen = hostap_80211_get_hdrlen(fc);

#if WIRELESS_EXT > 15
	/* Put this code here so that we avoid duplicating it in all
	 * Rx paths. - Jean II */
#ifdef IW_WIRELESS_SPY		/* defined in iw_handler.h */
	/* If spy monitoring on */
	if (iface->spy_data.spy_number > 0) {
		struct iw_quality wstats;
		wstats.level = rx_stats->signal;
		wstats.noise = rx_stats->noise;
		wstats.updated = 6;	/* No qual value */
		/* Update spy records */
		wireless_spy_update(dev, hdr->addr2, &wstats);
	}
#endif /* IW_WIRELESS_SPY */
#endif /* WIRELESS_EXT > 15 */

	if (local->iw_mode == IW_MODE_MONITOR) {
		monitor_rx(dev, skb, rx_stats);
		return;
	}

	if (type != WLAN_FC_TYPE_DATA) {
		if (type == WLAN_FC_TYPE_MGMT && stype == WLAN_FC_STYPE_AUTH &&
		    fc & WLAN_FC_ISWEP && local->host_decrypt &&
		    hostap_rx_frame_decrypt(local, fc & WLAN_FC_ISWEP, skb)) {
			printk(KERN_DEBUG "%s: failed to decrypt mgmt::auth "
			       "from " MACSTR "\n", dev->name,
			       MAC2STR(hdr->addr2));
			/* TODO: could inform hostapd about this so that it
			 * could send auth failure report */
			goto rx_dropped;
		}
		if (hostap_rx_frame_mgmt(local, skb, rx_stats, type, stype))
			goto rx_dropped;
		else
			goto rx_exit;
	}

	/* Data frame - extract src/dst addresses */
	if (skb->len < IEEE80211_DATA_HDR3_LEN)
		goto rx_dropped;

	switch (fc & (WLAN_FC_FROMDS | WLAN_FC_TODS)) {
	case WLAN_FC_FROMDS:
		memcpy(dst, hdr->addr1, ETH_ALEN);
		memcpy(src, hdr->addr3, ETH_ALEN);
		break;
	case WLAN_FC_TODS:
		memcpy(dst, hdr->addr3, ETH_ALEN);
		memcpy(src, hdr->addr2, ETH_ALEN);
		break;
	case WLAN_FC_FROMDS | WLAN_FC_TODS:
		if (skb->len < IEEE80211_DATA_HDR4_LEN)
			goto rx_dropped;
		memcpy(dst, hdr->addr3, ETH_ALEN);
		memcpy(src, hdr->addr4, ETH_ALEN);
		break;
	case 0:
		memcpy(dst, hdr->addr1, ETH_ALEN);
		memcpy(src, hdr->addr2, ETH_ALEN);
		break;
	}

	if (hostap_rx_frame_wds(local, hdr, fc, &wds))
		goto rx_dropped;
	if (wds) {
		skb->dev = dev = wds;
		stats = hostap_get_stats(dev);
	}

	if (local->iw_mode == IW_MODE_MASTER && !wds &&
	    (fc & (WLAN_FC_TODS | WLAN_FC_FROMDS)) == WLAN_FC_FROMDS &&
	    local->stadev &&
	    memcmp(hdr->addr2, local->assoc_ap_addr, ETH_ALEN) == 0) {
		/* Frame from BSSID of the AP for which we are a client */
		skb->dev = dev = local->stadev;
		stats = hostap_get_stats(dev);
		from_assoc_ap = 1;
	}

	dev->last_rx = jiffies;

	if (local->iw_mode == IW_MODE_MASTER && !from_assoc_ap) {
		switch (hostap_handle_sta_rx(local, dev, skb, rx_stats,
					     wds != NULL)) {
		case AP_RX_CONTINUE_NOT_AUTHORIZED:
			frame_authorized = 0;
			break;
		case AP_RX_CONTINUE:
			frame_authorized = 1;
			break;
		case AP_RX_DROP:
			goto rx_dropped;
		case AP_RX_EXIT:
			goto rx_exit;
		}
	} else if (local->iw_mode == IW_MODE_REPEAT ||
		   local->wds_type & HOSTAP_WDS_AP_CLIENT)
		hostap_update_rx_stats(local->ap, hdr, rx_stats);

	/* Nullfunc frames may have PS-bit set, so they must be passed to
	 * hostap_handle_sta_rx() before being dropped here. */
	if (stype != WLAN_FC_STYPE_DATA &&
	    stype != WLAN_FC_STYPE_DATA_CFACK &&
	    stype != WLAN_FC_STYPE_DATA_CFPOLL &&
	    stype != WLAN_FC_STYPE_DATA_CFACKPOLL) {
		if (stype != WLAN_FC_STYPE_NULLFUNC)
			printk(KERN_DEBUG "%s: RX: dropped data frame "
			       "with no data (type=0x%02x, subtype=0x%02x)\n",
			       dev->name, type, stype);
		goto rx_dropped;
	}

	/* skb: hdr + (possibly fragmented, possibly encrypted) payload */

	if (local->host_decrypt &&
	    hostap_rx_frame_decrypt(local, fc & WLAN_FC_ISWEP, skb))
		goto rx_dropped;

	/* skb: hdr + (possibly fragmented) plaintext payload */

	if (local->host_decrypt && (fc & WLAN_FC_ISWEP) &&
	    (frag != 0 || (fc & WLAN_FC_MOREFRAG))) {
		int flen;
		struct sk_buff *frag_skb =
			prism2_frag_cache_get(local, hdr);
		if (!frag_skb) {
			printk(KERN_DEBUG "%s: Rx cannot get skb from "
			       "fragment cache (morefrag=%d seq=%u frag=%u)\n",
			       dev->name, (fc & WLAN_FC_MOREFRAG) != 0,
			       WLAN_GET_SEQ_SEQ(sc), frag);
			goto rx_dropped;
		}

		flen = skb->len;
		if (frag != 0)
			flen -= hdrlen;

		if (frag_skb->tail + flen > frag_skb->end) {
			printk(KERN_WARNING "%s: host decrypted and "
			       "reassembled frame did not fit skb\n",
			       dev->name);
			prism2_frag_cache_invalidate(local, hdr);
			goto rx_dropped;
		}

		if (frag == 0) {
			/* copy first fragment (including full headers) into
			 * beginning of the fragment cache skb */
			memcpy(skb_put(frag_skb, flen), skb->data, flen);
		} else {
			/* append frame payload to the end of the fragment
			 * cache skb */
			memcpy(skb_put(frag_skb, flen), skb->data + hdrlen,
			       flen);
		}
		dev_kfree_skb(skb);
		skb = NULL;

		if (fc & WLAN_FC_MOREFRAG) {
			/* more fragments expected - leave the skb in fragment
			 * cache for now; it will be delivered to upper layers
			 * after all fragments have been received */
			goto rx_exit;
		}

		/* this was the last fragment and the frame will be
		 * delivered, so remove skb from fragment cache */
		skb = frag_skb;
		hdr = (struct hostap_ieee80211_hdr *) skb->data;
		prism2_frag_cache_invalidate(local, hdr);
	}

	/* skb: hdr + (possible reassembled) full plaintext payload */

	payload = skb->data + hdrlen;
	ethertype = (payload[6] << 8) | payload[7];

	/* If IEEE 802.1X is used, check whether the port is authorized to send
	 * the received frame. */
	if (local->ieee_802_1x && local->iw_mode == IW_MODE_MASTER) {
		if (ethertype == ETH_P_PAE) {
			printk(KERN_DEBUG "%s: RX: IEEE 802.1X frame\n",
			       dev->name);
			if (local->hostapd && local->apdev) {
				/* Send IEEE 802.1X frames to the user
				 * space daemon for processing */
				prism2_rx_80211(local->apdev, skb, rx_stats,
						PRISM2_RX_MGMT);
				local->apdevstats.rx_packets++;
				local->apdevstats.rx_bytes += skb->len;
				goto rx_exit;
			}
		} else if (!frame_authorized) {
			printk(KERN_DEBUG "%s: dropped frame from "
			       "unauthorized port (IEEE 802.1X): "
			       "ethertype=0x%04x\n",
			       dev->name, ethertype);
			goto rx_dropped;
		}
	}

	/* convert hdr + possible LLC headers into Ethernet header */
	if (skb->len - hdrlen >= 8 &&
	    ((memcmp(payload, rfc1042_header, 6) == 0 &&
	      ethertype != ETH_P_AARP && ethertype != ETH_P_IPX) ||
	     memcmp(payload, bridge_tunnel_header, 6) == 0)) {
		/* remove RFC1042 or Bridge-Tunnel encapsulation and
		 * replace EtherType */
		skb_pull(skb, hdrlen + 6);
		memcpy(skb_push(skb, ETH_ALEN), src, ETH_ALEN);
		memcpy(skb_push(skb, ETH_ALEN), dst, ETH_ALEN);
	} else {
		u16 len;
		/* Leave Ethernet header part of hdr and full payload */
		skb_pull(skb, hdrlen);
		len = htons(skb->len);
		memcpy(skb_push(skb, 2), &len, 2);
		memcpy(skb_push(skb, ETH_ALEN), src, ETH_ALEN);
		memcpy(skb_push(skb, ETH_ALEN), dst, ETH_ALEN);
	}

	if (wds && ((fc & (WLAN_FC_TODS | WLAN_FC_FROMDS)) == WLAN_FC_TODS) &&
	    skb->len >= ETH_HLEN + ETH_ALEN) {
		/* Non-standard frame: get addr4 from its bogus location after
		 * the payload */
		memcpy(skb->data + ETH_ALEN,
		       skb->data + skb->len - ETH_ALEN, ETH_ALEN);
		skb_trim(skb, skb->len - ETH_ALEN);
	}

	stats->rx_packets++;
	stats->rx_bytes += skb->len;

	if (local->iw_mode == IW_MODE_MASTER && !wds &&
	    local->ap->bridge_packets) {
		if (dst[0] & 0x01) {
			/* copy multicast frame both to the higher layers and
			 * to the wireless media */
			local->ap->bridged_multicast++;
			skb2 = skb_clone(skb, GFP_ATOMIC);
			if (skb2 == NULL)
				printk(KERN_DEBUG "%s: skb_clone failed for "
				       "multicast frame\n", dev->name);
		} else if (hostap_is_sta_assoc(local->ap, dst)) {
			/* send frame directly to the associated STA using
			 * wireless media and not passing to higher layers */
			local->ap->bridged_unicast++;
			skb2 = skb;
			skb = NULL;
		}
	}

	if (skb2 != NULL) {
		/* send to wireless media */
		skb2->protocol = __constant_htons(ETH_P_802_3);
		skb2->mac.raw = skb2->nh.raw = skb2->data;
		/* skb2->nh.raw = skb2->data + ETH_HLEN; */
		dev_queue_xmit(skb2);
	}

	if (skb) {
		skb->protocol = eth_type_trans(skb, dev);
		memset(skb->cb, 0, sizeof(skb->cb));
		skb->dev = dev;
		netif_rx(skb);
	}

 rx_exit:
	return;

 rx_dropped:
	dev_kfree_skb(skb);

	stats->rx_dropped++;
	goto rx_exit;
}


EXPORT_SYMBOL(hostap_80211_rx);
