RP614v4 (RTL865x) Linux Software and Tools Readme

This file documents the directory structure and contents of the Software
and Tools for the RP614v4 (RTL865x). 


1. Directory structure

	This package contains Realtek's Rome Driver v3.6-3.
	
	linux-2.4.x/
		This directory contains a full source of our patches Linux kernel.

	linux-2.4.x/drivers/net/re865x
		NIC driver for RTL865X's built-in NIC. With source code.

	linux-2.4.x/drivers/net/re865x/rtl865x
		The ROME driver. 

    	lib/
   		uClibc library for user application. since 0.5.8, source code of uClibc
   		is included in uClibc/
   		
	user/
		There are some user mode applications ready for your choice.
	
	user/boa/
		System initialization code and web server.
	
	user/boa/src/www_PR/
		Webpages RP614v4
	
	images/
   		Default runtime image built from SDK "run.bix" is here. 
		
	vendor/			
		Default configuration
		

2. Install toolchain
	
	You must install GNU toolchain before you can start build your customized
	runtime image from our SDK. Please read the README file under toolchain/ 
	directory.
	
	put this toolchain to /uclibc/: 
	# cd/
	# mkdir uclibc
	# cd uclibc
	# tar jxvf toolchain_mips_20050831.tar.bz2
	# mv toolchain_mips.pv.0831 toolchain_mips
	
	

3. Install the Source.
   
   	Untar the file RP614v4_V0.1.8_09.08PR_src.tar.bz2
	and type the command:

	tar -xjvf RP614v4_V0.1.8_09.08PR_src.tar.bz2
	You will see a sub directory RP614v4_xxx/ created.
	xxx -> V0.1.8_09.08PR (version-date)


4. Build runtime image from source code

	Change working directory to RP614v4_xxx/


	===================
	a. Type "make menuconfig", customize your kernel config options.

	If you are building runtime image for the first time ,be sure to save the config
	when leaving "make menuconfig", even if you make no changes to default settings.

	b. Type "make dep"

	c. (Optional) If you need to customize busybox, goto 
	   uClinux-dist/user/busybox/, and type "make menuconfig" to select
	   user level application you need. Then go back to uClinux-dist/, 
	   and type "make dep" again. This would update all dependencies.

	d. Type "make" 
		This would build the kernel, user apps, and create image file run.bix
		under RP614v4_xxx/images/ directory. 



5. Module List

Module			Package				Version

NAT/NAPT		RomeDriver-Realtek		3.6.3

RIPv1/RIPv2		Copyright 2005, DNI

DHCP 			udhcpd/udhcpd			0.9.10
Server/Client 		of Busybox V1.00-pre2

DNS Proxy		dnrd				2.17.2

Dynamic DNS		ez-ipupdate			3.0.11b7

Web Server		BOA				0.94

UPNP			Copyright 2005, DNI

Telstra's Big Pond	bpalogin			

Email			smtpclient			

Schedule		crond 
			of Busybox V1.00-pre2

PPP/PPPoE		pppd				2.3.8

PPTP Client		pptp-client			1.3.1

ntpclient		Copyright 2005, DNI

Miscellaneous		Copyright 2005, DNI	

