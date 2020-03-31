# 1 "rtl8651_multicast.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "rtl8651_multicast.c"
# 11 "rtl8651_multicast.c"
# 1 "rtl_types.h" 1
# 204 "rtl_types.h"
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/config.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/config.h" 1



# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/autoconf.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/autoconf.h" 1
# 5 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/config.h" 2
# 5 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/config.h" 2
# 205 "rtl_types.h" 2
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/ctype.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/ctype.h" 1
# 18 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/ctype.h"
# 18 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/ctype.h"
extern unsigned char _ctype[];
# 37 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/ctype.h"
# 37 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/ctype.h"
static inline unsigned char __tolower(unsigned char c)
{
        if ((((_ctype[(int)(unsigned char)(c)])&(0x01)) != 0))
                c -= 'A'-'a';
        return c;
}

static inline unsigned char __toupper(unsigned char c)
{
        if ((((_ctype[(int)(unsigned char)(c)])&(0x02)) != 0))
                c -= 'a'-'A';
        return c;
}
# 206 "rtl_types.h" 2
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/module.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/module.h" 1
# 11 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/module.h"
# 11 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/module.h"
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/spinlock.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/spinlock.h" 1





# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/system.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/system.h" 1
# 16 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/system.h"
# 16 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/system.h"
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/sgidefs.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/sgidefs.h" 1
# 17 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/system.h" 2
# 17 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/system.h" 2

# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/kernel.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/kernel.h" 1
# 10 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/kernel.h"
# 10 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/kernel.h"
# 1 "/uclibc/toolchain_mips/lib/gcc-lib/mips-linux/3.2/include/stdarg.h" 1 3
# 43 "/uclibc/toolchain_mips/lib/gcc-lib/mips-linux/3.2/include/stdarg.h" 3
typedef __builtin_va_list __gnuc_va_list;
# 110 "/uclibc/toolchain_mips/lib/gcc-lib/mips-linux/3.2/include/stdarg.h" 3
typedef __gnuc_va_list va_list;
# 11 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/kernel.h" 2
# 11 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/kernel.h" 2
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/linkage.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/linkage.h" 1
# 12 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/kernel.h" 2
# 12 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/kernel.h" 2
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/stddef.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/stddef.h" 1
# 13 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/kernel.h" 2
# 13 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/kernel.h" 2
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/types.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/types.h" 1
# 15 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/types.h"
# 15 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/types.h"
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/posix_types.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/posix_types.h" 1
# 36 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/posix_types.h"
# 36 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/posix_types.h"
typedef struct {
        unsigned long fds_bits [(1024/(8 * sizeof(unsigned long)))];
} __kernel_fd_set;


typedef void (*__kernel_sighandler_t)(int);



typedef int __kernel_key_t;



# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/posix_types.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/posix_types.h" 1
# 17 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/posix_types.h"
# 17 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/posix_types.h"
typedef unsigned int __kernel_dev_t;
typedef unsigned long __kernel_ino_t;
typedef unsigned int __kernel_mode_t;
typedef unsigned long __kernel_nlink_t;
typedef long __kernel_off_t;
typedef int __kernel_pid_t;
typedef int __kernel_ipc_pid_t;
typedef int __kernel_uid_t;
typedef int __kernel_gid_t;
typedef unsigned int __kernel_size_t;
typedef int __kernel_ssize_t;
typedef int __kernel_ptrdiff_t;
typedef long __kernel_time_t;
typedef long __kernel_suseconds_t;
typedef long __kernel_clock_t;
typedef long __kernel_daddr_t;
typedef char * __kernel_caddr_t;

typedef unsigned short __kernel_uid16_t;
typedef unsigned short __kernel_gid16_t;
typedef int __kernel_uid32_t;
typedef int __kernel_gid32_t;
typedef __kernel_uid_t __kernel_old_uid_t;
typedef __kernel_gid_t __kernel_old_gid_t;


typedef long long __kernel_loff_t;


typedef struct {
        long val[2];
} __kernel_fsid_t;




static __inline__ void __FD_SET(unsigned long __fd, __kernel_fd_set *__fdsetp)
{
        unsigned long __tmp = __fd / (8 * sizeof(unsigned long));
        unsigned long __rem = __fd % (8 * sizeof(unsigned long));
        __fdsetp->fds_bits[__tmp] |= (1UL<<__rem);
}


static __inline__ void __FD_CLR(unsigned long __fd, __kernel_fd_set *__fdsetp)
{
        unsigned long __tmp = __fd / (8 * sizeof(unsigned long));
        unsigned long __rem = __fd % (8 * sizeof(unsigned long));
        __fdsetp->fds_bits[__tmp] &= ~(1UL<<__rem);
}


static __inline__ int __FD_ISSET(unsigned long __fd, const __kernel_fd_set *__p)
{
        unsigned long __tmp = __fd / (8 * sizeof(unsigned long));
        unsigned long __rem = __fd % (8 * sizeof(unsigned long));
        return (__p->fds_bits[__tmp] & (1UL<<__rem)) != 0;
}






static __inline__ void __FD_ZERO(__kernel_fd_set *__p)
{
        unsigned long *__tmp = __p->fds_bits;
        int __i;

        if (__builtin_constant_p((1024/(8 * sizeof(unsigned long))))) {
                switch ((1024/(8 * sizeof(unsigned long)))) {
                case 16:
                        __tmp[ 0] = 0; __tmp[ 1] = 0;
                        __tmp[ 2] = 0; __tmp[ 3] = 0;
                        __tmp[ 4] = 0; __tmp[ 5] = 0;
                        __tmp[ 6] = 0; __tmp[ 7] = 0;
                        __tmp[ 8] = 0; __tmp[ 9] = 0;
                        __tmp[10] = 0; __tmp[11] = 0;
                        __tmp[12] = 0; __tmp[13] = 0;
                        __tmp[14] = 0; __tmp[15] = 0;
                        return;

                case 8:
                        __tmp[ 0] = 0; __tmp[ 1] = 0;
                        __tmp[ 2] = 0; __tmp[ 3] = 0;
                        __tmp[ 4] = 0; __tmp[ 5] = 0;
                        __tmp[ 6] = 0; __tmp[ 7] = 0;
                        return;

                case 4:
                        __tmp[ 0] = 0; __tmp[ 1] = 0;
                        __tmp[ 2] = 0; __tmp[ 3] = 0;
                        return;
                }
        }
        __i = (1024/(8 * sizeof(unsigned long)));
        while (__i) {
                __i--;
                *__tmp = 0;
                __tmp++;
        }
}
# 50 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/posix_types.h" 2
# 50 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/posix_types.h" 2
# 16 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/types.h" 2
# 16 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/types.h" 2
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/types.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/types.h" 1
# 14 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/types.h"
# 14 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/types.h"
typedef unsigned short umode_t;






typedef __signed__ char __s8;
typedef unsigned char __u8;

typedef __signed__ short __s16;
typedef unsigned short __u16;

typedef __signed__ int __s32;
typedef unsigned int __u32;
# 38 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/types.h"
# 38 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/types.h"
typedef __signed__ long long __s64;
typedef unsigned long long __u64;
# 49 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/types.h"
# 49 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/types.h"
typedef __signed char s8;
typedef unsigned char u8;

typedef __signed short s16;
typedef unsigned short u16;

typedef __signed int s32;
typedef unsigned int u32;
# 66 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/types.h"
# 66 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/types.h"
typedef __signed__ long long s64;
typedef unsigned long long u64;
# 77 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/types.h"
# 77 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/types.h"
typedef u32 dma_addr_t;

typedef u64 dma64_addr_t;




typedef unsigned long phys_t;
# 17 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/types.h" 2
# 17 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/types.h" 2



typedef __kernel_fd_set fd_set;
typedef __kernel_dev_t dev_t;
typedef __kernel_ino_t ino_t;
typedef __kernel_mode_t mode_t;
typedef __kernel_nlink_t nlink_t;
typedef __kernel_off_t off_t;
typedef __kernel_pid_t pid_t;
typedef __kernel_daddr_t daddr_t;
typedef __kernel_key_t key_t;
typedef __kernel_suseconds_t suseconds_t;


typedef __kernel_uid32_t uid_t;
typedef __kernel_gid32_t gid_t;
typedef __kernel_uid16_t uid16_t;
typedef __kernel_gid16_t gid16_t;
# 52 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/types.h"
# 52 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/types.h"
typedef __kernel_loff_t loff_t;
# 61 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/types.h"
# 61 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/types.h"
typedef __kernel_size_t size_t;




typedef __kernel_ssize_t ssize_t;




typedef __kernel_ptrdiff_t ptrdiff_t;




typedef __kernel_time_t time_t;




typedef __kernel_clock_t clock_t;




typedef __kernel_caddr_t caddr_t;



typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned long u_long;


typedef unsigned char unchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;




typedef __u8 u_int8_t;
typedef __s8 int8_t;
typedef __u16 u_int16_t;
typedef __s16 int16_t;
typedef __u32 u_int32_t;
typedef __s32 int32_t;



typedef __u8 uint8_t;
typedef __u16 uint16_t;
typedef __u32 uint32_t;


typedef __u64 uint64_t;
typedef __u64 u_int64_t;
typedef __s64 int64_t;
# 130 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/types.h"
# 130 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/types.h"
struct ustat {
        __kernel_daddr_t f_tfree;
        __kernel_ino_t f_tinode;
        char f_fname[6];
        char f_fpack[6];
};
# 14 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/kernel.h" 2
# 14 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/kernel.h" 2
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/compiler.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/compiler.h" 1
# 15 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/kernel.h" 2
# 15 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/kernel.h" 2
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/byteorder.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/byteorder.h" 1
# 23 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/byteorder.h"
# 23 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/byteorder.h"
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/byteorder/big_endian.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/byteorder/big_endian.h" 1
# 11 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/byteorder/big_endian.h"
# 11 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/byteorder/big_endian.h"
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/byteorder/swab.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/byteorder/swab.h" 1
# 159 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/byteorder/swab.h"
# 159 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/byteorder/swab.h"
static __inline__ __const__ __u16 __fswab16(__u16 x)
{
        return ({ __u16 __tmp = (x) ; ({ __u16 __x = (__tmp); ((__u16)( (((__u16)(__x) & (__u16)0x00ffU) << 8) | (((__u16)(__x) & (__u16)0xff00U) >> 8) )); }); });
}
static __inline__ __u16 __swab16p(__u16 *x)
{
        return ({ __u16 __tmp = (*(x)) ; ({ __u16 __x = (__tmp); ((__u16)( (((__u16)(__x) & (__u16)0x00ffU) << 8) | (((__u16)(__x) & (__u16)0xff00U) >> 8) )); }); });
}
static __inline__ void __swab16s(__u16 *addr)
{
        do { *(addr) = ({ __u16 __tmp = (*((addr))) ; ({ __u16 __x = (__tmp); ((__u16)( (((__u16)(__x) & (__u16)0x00ffU) << 8) | (((__u16)(__x) & (__u16)0xff00U) >> 8) )); }); }); } while (0);
}

static __inline__ __const__ __u32 __fswab24(__u32 x)
{
        return ({ __u32 __tmp = (x) ; ({ __u32 __x = (__tmp); ((__u32)( ((__x & (__u32)0x000000ffUL) << 16) | (__x & (__u32)0x0000ff00UL) | ((__x & (__u32)0x00ff0000UL) >> 16) )); }); });
}
static __inline__ __u32 __swab24p(__u32 *x)
{
        return ({ __u32 __tmp = (*(x)) ; ({ __u32 __x = (__tmp); ((__u32)( ((__x & (__u32)0x000000ffUL) << 16) | (__x & (__u32)0x0000ff00UL) | ((__x & (__u32)0x00ff0000UL) >> 16) )); }); });
}
static __inline__ void __swab24s(__u32 *addr)
{
        do { *(addr) = ({ __u32 __tmp = (*((addr))) ; ({ __u32 __x = (__tmp); ((__u32)( ((__x & (__u32)0x000000ffUL) << 16) | (__x & (__u32)0x0000ff00UL) | ((__x & (__u32)0x00ff0000UL) >> 16) )); }); }); } while (0);
}

static __inline__ __const__ __u32 __fswab32(__u32 x)
{
        return ({ __u32 __tmp = (x) ; ({ __u32 __x = (__tmp); ((__u32)( (((__u32)(__x) & (__u32)0x000000ffUL) << 24) | (((__u32)(__x) & (__u32)0x0000ff00UL) << 8) | (((__u32)(__x) & (__u32)0x00ff0000UL) >> 8) | (((__u32)(__x) & (__u32)0xff000000UL) >> 24) )); }); });
}
static __inline__ __u32 __swab32p(__u32 *x)
{
        return ({ __u32 __tmp = (*(x)) ; ({ __u32 __x = (__tmp); ((__u32)( (((__u32)(__x) & (__u32)0x000000ffUL) << 24) | (((__u32)(__x) & (__u32)0x0000ff00UL) << 8) | (((__u32)(__x) & (__u32)0x00ff0000UL) >> 8) | (((__u32)(__x) & (__u32)0xff000000UL) >> 24) )); }); });
}
static __inline__ void __swab32s(__u32 *addr)
{
        do { *(addr) = ({ __u32 __tmp = (*((addr))) ; ({ __u32 __x = (__tmp); ((__u32)( (((__u32)(__x) & (__u32)0x000000ffUL) << 24) | (((__u32)(__x) & (__u32)0x0000ff00UL) << 8) | (((__u32)(__x) & (__u32)0x00ff0000UL) >> 8) | (((__u32)(__x) & (__u32)0xff000000UL) >> 24) )); }); }); } while (0);
}


static __inline__ __const__ __u64 __fswab64(__u64 x)
{

        __u32 h = x >> 32;
        __u32 l = x & ((1ULL<<32)-1);
        return (((__u64)(__builtin_constant_p((__u32)(l)) ? ({ __u32 __x = ((l)); ((__u32)( (((__u32)(__x) & (__u32)0x000000ffUL) << 24) | (((__u32)(__x) & (__u32)0x0000ff00UL) << 8) | (((__u32)(__x) & (__u32)0x00ff0000UL) >> 8) | (((__u32)(__x) & (__u32)0xff000000UL) >> 24) )); }) : __fswab32((l)))) << 32) | ((__u64)((__builtin_constant_p((__u32)(h)) ? ({ __u32 __x = ((h)); ((__u32)( (((__u32)(__x) & (__u32)0x000000ffUL) << 24) | (((__u32)(__x) & (__u32)0x0000ff00UL) << 8) | (((__u32)(__x) & (__u32)0x00ff0000UL) >> 8) | (((__u32)(__x) & (__u32)0xff000000UL) >> 24) )); }) : __fswab32((h)))));



}
static __inline__ __u64 __swab64p(__u64 *x)
{
        return ({ __u64 __tmp = (*(x)) ; ({ __u64 __x = (__tmp); ((__u64)( (__u64)(((__u64)(__x) & (__u64)0x00000000000000ffULL) << 56) | (__u64)(((__u64)(__x) & (__u64)0x000000000000ff00ULL) << 40) | (__u64)(((__u64)(__x) & (__u64)0x0000000000ff0000ULL) << 24) | (__u64)(((__u64)(__x) & (__u64)0x00000000ff000000ULL) << 8) | (__u64)(((__u64)(__x) & (__u64)0x000000ff00000000ULL) >> 8) | (__u64)(((__u64)(__x) & (__u64)0x0000ff0000000000ULL) >> 24) | (__u64)(((__u64)(__x) & (__u64)0x00ff000000000000ULL) >> 40) | (__u64)(((__u64)(__x) & (__u64)0xff00000000000000ULL) >> 56) )); }); });
}
static __inline__ void __swab64s(__u64 *addr)
{
        do { *(addr) = ({ __u64 __tmp = (*((addr))) ; ({ __u64 __x = (__tmp); ((__u64)( (__u64)(((__u64)(__x) & (__u64)0x00000000000000ffULL) << 56) | (__u64)(((__u64)(__x) & (__u64)0x000000000000ff00ULL) << 40) | (__u64)(((__u64)(__x) & (__u64)0x0000000000ff0000ULL) << 24) | (__u64)(((__u64)(__x) & (__u64)0x00000000ff000000ULL) << 8) | (__u64)(((__u64)(__x) & (__u64)0x000000ff00000000ULL) >> 8) | (__u64)(((__u64)(__x) & (__u64)0x0000ff0000000000ULL) >> 24) | (__u64)(((__u64)(__x) & (__u64)0x00ff000000000000ULL) >> 40) | (__u64)(((__u64)(__x) & (__u64)0xff00000000000000ULL) >> 56) )); }); }); } while (0);
}
# 12 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/byteorder/big_endian.h" 2
# 12 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/byteorder/big_endian.h" 2
# 82 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/byteorder/big_endian.h"
# 82 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/byteorder/big_endian.h"
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/byteorder/generic.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/byteorder/generic.h" 1
# 149 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/byteorder/generic.h"
# 149 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/byteorder/generic.h"
extern __u32 ntohl(__u32);
extern __u32 htonl(__u32);
extern unsigned short int ntohs(unsigned short int);
extern unsigned short int htons(unsigned short int);
# 83 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/byteorder/big_endian.h" 2
# 83 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/byteorder/big_endian.h" 2
# 24 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/byteorder.h" 2
# 24 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/byteorder.h" 2
# 16 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/kernel.h" 2
# 16 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/kernel.h" 2
# 41 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/kernel.h"
# 41 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/kernel.h"
extern int console_printk[];
# 58 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/kernel.h"
# 58 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/kernel.h"
struct completion;

extern struct notifier_block *panic_notifier_list;
 void panic(const char * fmt, ...)
        __attribute__ ((noreturn, format (printf, 1, 2)));
 void do_exit(long error_code)
        __attribute__((noreturn));
 void complete_and_exit(struct completion *, long)
        __attribute__((noreturn));
extern int abs(int);
extern unsigned long simple_strtoul(const char *,char **,unsigned int);
extern long simple_strtol(const char *,char **,unsigned int);
extern unsigned long long simple_strtoull(const char *,char **,unsigned int);
extern long long simple_strtoll(const char *,char **,unsigned int);
extern int sprintf(char * buf, const char * fmt, ...)
        __attribute__ ((format (printf, 2, 3)));
extern int vsprintf(char *buf, const char *, va_list);
extern int snprintf(char * buf, size_t size, const char * fmt, ...)
        __attribute__ ((format (printf, 3, 4)));
extern int vsnprintf(char *buf, size_t size, const char *fmt, va_list args);

extern int sscanf(const char *, const char *, ...)
        __attribute__ ((format (scanf,2,3)));
extern int vsscanf(const char *, const char *, va_list);

extern int get_option(char **str, int *pint);
extern char *get_options(char *str, int nints, int *ints);
extern unsigned long long memparse(char *ptr, char **retptr);
extern void dev_probe_lock(void);
extern void dev_probe_unlock(void);

extern int session_of_pgrp(int pgrp);

 int printk(const char * fmt, ...)
        __attribute__ ((format (printf, 1, 2)));

static inline void console_silent(void)
{
        (console_printk[0]) = 0;
}

static inline void console_verbose(void)
{
        if ((console_printk[0]))
                (console_printk[0]) = 15;
}

extern void bust_spinlocks(int yes);
extern int oops_in_progress;

extern int tainted;
extern const char *print_tainted(void);

extern void dump_stack(void);
# 174 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/kernel.h"
# 174 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/kernel.h"
extern void __out_of_line_bug(int line) __attribute__((noreturn));





struct sysinfo {
        long uptime;
        unsigned long loads[3];
        unsigned long totalram;
        unsigned long freeram;
        unsigned long sharedram;
        unsigned long bufferram;
        unsigned long totalswap;
        unsigned long freeswap;
        unsigned short procs;
        unsigned short pad;
        unsigned long totalhigh;
        unsigned long freehigh;
        unsigned int mem_unit;
        char _f[20-2*sizeof(long)-sizeof(int)];
};
# 19 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/system.h" 2
# 19 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/system.h" 2

# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/addrspace.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/addrspace.h" 1
# 21 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/system.h" 2
# 21 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/system.h" 2
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/ptrace.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/ptrace.h" 1
# 14 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/ptrace.h"
# 14 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/ptrace.h"
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/isadep.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/isadep.h" 1
# 15 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/ptrace.h" 2
# 15 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/ptrace.h" 2
# 31 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/ptrace.h"
# 31 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/ptrace.h"
struct pt_regs {

        unsigned long pad0[6];


        unsigned long regs[32];


        unsigned long cp0_status;
        unsigned long lo;
        unsigned long hi;
        unsigned long cp0_badvaddr;
        unsigned long cp0_cause;
        unsigned long cp0_epc;
};
# 102 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/ptrace.h"
# 102 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/ptrace.h"
extern void show_regs(struct pt_regs *);
# 22 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/system.h" 2
# 22 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/system.h" 2

__asm__ (
        ".macro\t__sti\n\t"
        ".set\tpush\n\t"
        ".set\treorder\n\t"
        ".set\tnoat\n\t"
        "mfc0\t$1,$12\n\t"
        "ori\t$1,0x1f\n\t"
        "xori\t$1,0x1e\n\t"
        "mtc0\t$1,$12\n\t"
        ".set\tpop\n\t"
        ".endm");

static __inline__ void
__sti(void)
{
        __asm__ __volatile__(
                "__sti"
                :
                :
                : "memory");
}
# 52 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/system.h"
# 52 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/system.h"
__asm__ (
        ".macro\t__cli\n\t"
        ".set\tpush\n\t"
        ".set\tnoat\n\t"
        "mfc0\t$1,$12\n\t"
        "ori\t$1,1\n\t"
        "xori\t$1,1\n\t"
        ".set\tnoreorder\n\t"
        "mtc0\t$1,$12\n\t"
        "sll\t$0, $0, 1\t\t\t# nop\n\t"
        "sll\t$0, $0, 1\t\t\t# nop\n\t"
        "sll\t$0, $0, 1\t\t\t# nop\n\t"
        ".set\tpop\n\t"
        ".endm");

static __inline__ void
__cli(void)
{
        __asm__ __volatile__(
                "__cli"
                :
                :
                : "memory");
}

__asm__ (
        ".macro\t__save_flags flags\n\t"
        ".set\tpush\n\t"
        ".set\treorder\n\t"
        "mfc0\t\\flags, $12\n\t"
        ".set\tpop\n\t"
        ".endm");






__asm__ (
        ".macro\t__save_and_cli result\n\t"
        ".set\tpush\n\t"
        ".set\treorder\n\t"
        ".set\tnoat\n\t"
        "mfc0\t\\result, $12\n\t"
        "ori\t$1, \\result, 1\n\t"
        "xori\t$1, 1\n\t"
        ".set\tnoreorder\n\t"
        "mtc0\t$1, $12\n\t"
        "sll\t$0, $0, 1\t\t\t# nop\n\t"
        "sll\t$0, $0, 1\t\t\t# nop\n\t"
        "sll\t$0, $0, 1\t\t\t# nop\n\t"
        ".set\tpop\n\t"
        ".endm");
# 113 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/system.h"
# 113 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/system.h"
__asm__ (
        ".macro\t__save_and_sti result\n\t"
        ".set\tpush\n\t"
        ".set\treorder\n\t"
        ".set\tnoat\n\t"
        "mfc0\t\\result, $12\n\t"
        "ori\t$1, \\result, 1\n\t"
        ".set\tnoreorder\n\t"
        "mtc0\t$1, $12\n\t"
        ".set\tpop\n\t"
        ".endm");
# 132 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/system.h"
# 132 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/system.h"
__asm__(".macro\t__restore_flags flags\n\t"
        ".set\tnoreorder\n\t"
        ".set\tnoat\n\t"
        "mfc0\t$1, $12\n\t"
        "andi\t\\flags, 1\n\t"
        "ori\t$1, 1\n\t"
        "xori\t$1, 1\n\t"
        "or\t\\flags, $1\n\t"
        "mtc0\t\\flags, $12\n\t"
        "sll\t$0, $0, 1\t\t\t# nop\n\t"
        "sll\t$0, $0, 1\t\t\t# nop\n\t"
        "sll\t$0, $0, 1\t\t\t# nop\n\t"
        ".set\tat\n\t"
        ".set\treorder\n\t"
        ".endm");
# 263 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/system.h"
# 263 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/system.h"
extern void *resume(void *last, void *next);



struct task_struct;
# 278 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/system.h"
# 278 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/system.h"
static __inline__ unsigned long xchg_u32(volatile int * m, unsigned long val)
{
# 300 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/system.h"
# 300 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/system.h"
        unsigned long flags, retval;

        __asm__ __volatile__( "__save_and_cli\t%0" : "=r" (flags) : : "memory");
        retval = *m;
        *m = val;
        do { unsigned long __tmp1; __asm__ __volatile__( "__restore_flags\t%0" : "=r" (__tmp1) : "0" (flags) : "memory"); } while(0);
        return retval;

}




static __inline__ unsigned long
__xchg(unsigned long x, volatile void * ptr, int size)
{
        switch (size) {
                case 4:
                        return xchg_u32(ptr, x);
        }
        return x;
}

extern void *set_except_vector(int n, void *addr);
extern void per_cpu_trap_init(void);

extern void __die(const char *, struct pt_regs *, const char *file,
        const char *func, unsigned long line) __attribute__((noreturn));
extern void __die_if_kernel(const char *, struct pt_regs *, const char *file,
        const char *func, unsigned long line);
# 7 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/spinlock.h" 2
# 7 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/spinlock.h" 2
# 42 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/spinlock.h"
# 42 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/spinlock.h"
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/stringify.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/stringify.h" 1
# 43 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/spinlock.h" 2
# 43 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/spinlock.h" 2
# 77 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/spinlock.h"
# 77 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/spinlock.h"
  typedef struct { } spinlock_t;
# 141 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/spinlock.h"
# 141 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/spinlock.h"
  typedef struct { } rwlock_t;
# 172 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/spinlock.h"
# 172 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/spinlock.h"
typedef struct {
    spinlock_t lock;
} spinlock_cacheline_t;
# 12 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/module.h" 2
# 12 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/module.h" 2
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/list.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/list.h" 1





# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/prefetch.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/prefetch.h" 1
# 13 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/prefetch.h"
# 13 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/prefetch.h"
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h" 1
# 15 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h"
# 15 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h"
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/cache.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/cache.h" 1




# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/cache.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/cache.h" 1
# 6 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/cache.h" 2
# 6 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/cache.h" 2
# 16 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h" 2
# 16 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h" 2
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/isadep.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/isadep.h" 1
# 17 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h" 2
# 17 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h" 2







# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/smp.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/smp.h" 1
# 25 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h" 2
# 25 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h" 2
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/threads.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/threads.h" 1
# 26 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h" 2
# 26 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h" 2

# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/cachectl.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/cachectl.h" 1
# 28 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h" 2
# 28 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h" 2
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/cpu.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/cpu.h" 1
# 29 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h" 2
# 29 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h" 2
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/mipsregs.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/mipsregs.h" 1
# 18 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/mipsregs.h"
# 18 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/mipsregs.h"
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/hazards.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/hazards.h" 1
# 19 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/mipsregs.h" 2
# 19 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/mipsregs.h" 2
# 839 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/mipsregs.h"
# 839 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/mipsregs.h"
static inline void tlb_probe(void)
{
        do { } while (0);
        __asm__ __volatile__(
                ".set noreorder\n\t"
                "tlbp\n\t"
                ".set reorder");
        do { } while (0);
}

static inline void tlb_read(void)
{
        do { } while (0);
        __asm__ __volatile__(
                ".set noreorder\n\t"
                "tlbr\n\t"
                ".set reorder");
        do { } while (0);
}

static inline void tlb_write_indexed(void)
{
        do { } while (0);
        __asm__ __volatile__(
                ".set noreorder\n\t"
                "tlbwi\n\t"
                ".set reorder");
        do { } while (0);
}

static inline void tlb_write_random(void)
{
        do { } while (0);
        __asm__ __volatile__(
                ".set noreorder\n\t"
                "tlbwr\n\t"
                ".set reorder");
        do { } while (0);
}
# 920 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/mipsregs.h"
# 920 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/mipsregs.h"
static inline unsigned int set_c0_status(unsigned int set) { unsigned int res; res = ({ int __res; if (0 == 0) __asm__ __volatile__( "mfc0\t%0, " "$12" "\n\t" : "=r" (__res)); else __asm__ __volatile__( ".set\tmips32\n\t" "mfc0\t%0, " "$12" ", " "0" "\n\t" ".set\tmips0\n\t" : "=r" (__res)); __res; }); res |= set; do { if (0 == 0) __asm__ __volatile__( "mtc0\t%z0, " "$12" "\n\t" : : "Jr" (res)); else __asm__ __volatile__( ".set\tmips32\n\t" "mtc0\t%z0, " "$12" ", " "0" "\n\t" ".set\tmips0" : : "Jr" (res)); } while (0); return res; } static inline unsigned int clear_c0_status(unsigned int clear) { unsigned int res; res = ({ int __res; if (0 == 0) __asm__ __volatile__( "mfc0\t%0, " "$12" "\n\t" : "=r" (__res)); else __asm__ __volatile__( ".set\tmips32\n\t" "mfc0\t%0, " "$12" ", " "0" "\n\t" ".set\tmips0\n\t" : "=r" (__res)); __res; }); res &= ~clear; do { if (0 == 0) __asm__ __volatile__( "mtc0\t%z0, " "$12" "\n\t" : : "Jr" (res)); else __asm__ __volatile__( ".set\tmips32\n\t" "mtc0\t%z0, " "$12" ", " "0" "\n\t" ".set\tmips0" : : "Jr" (res)); } while (0); return res; } static inline unsigned int change_c0_status(unsigned int change, unsigned int new) { unsigned int res; res = ({ int __res; if (0 == 0) __asm__ __volatile__( "mfc0\t%0, " "$12" "\n\t" : "=r" (__res)); else __asm__ __volatile__( ".set\tmips32\n\t" "mfc0\t%0, " "$12" ", " "0" "\n\t" ".set\tmips0\n\t" : "=r" (__res)); __res; }); res &= ~change; res |= (new & change); do { if (0 == 0) __asm__ __volatile__( "mtc0\t%z0, " "$12" "\n\t" : : "Jr" (res)); else __asm__ __volatile__( ".set\tmips32\n\t" "mtc0\t%z0, " "$12" ", " "0" "\n\t" ".set\tmips0" : : "Jr" (res)); } while (0); return res; }
static inline unsigned int set_c0_cause(unsigned int set) { unsigned int res; res = ({ int __res; if (0 == 0) __asm__ __volatile__( "mfc0\t%0, " "$13" "\n\t" : "=r" (__res)); else __asm__ __volatile__( ".set\tmips32\n\t" "mfc0\t%0, " "$13" ", " "0" "\n\t" ".set\tmips0\n\t" : "=r" (__res)); __res; }); res |= set; do { if (0 == 0) __asm__ __volatile__( "mtc0\t%z0, " "$13" "\n\t" : : "Jr" (res)); else __asm__ __volatile__( ".set\tmips32\n\t" "mtc0\t%z0, " "$13" ", " "0" "\n\t" ".set\tmips0" : : "Jr" (res)); } while (0); return res; } static inline unsigned int clear_c0_cause(unsigned int clear) { unsigned int res; res = ({ int __res; if (0 == 0) __asm__ __volatile__( "mfc0\t%0, " "$13" "\n\t" : "=r" (__res)); else __asm__ __volatile__( ".set\tmips32\n\t" "mfc0\t%0, " "$13" ", " "0" "\n\t" ".set\tmips0\n\t" : "=r" (__res)); __res; }); res &= ~clear; do { if (0 == 0) __asm__ __volatile__( "mtc0\t%z0, " "$13" "\n\t" : : "Jr" (res)); else __asm__ __volatile__( ".set\tmips32\n\t" "mtc0\t%z0, " "$13" ", " "0" "\n\t" ".set\tmips0" : : "Jr" (res)); } while (0); return res; } static inline unsigned int change_c0_cause(unsigned int change, unsigned int new) { unsigned int res; res = ({ int __res; if (0 == 0) __asm__ __volatile__( "mfc0\t%0, " "$13" "\n\t" : "=r" (__res)); else __asm__ __volatile__( ".set\tmips32\n\t" "mfc0\t%0, " "$13" ", " "0" "\n\t" ".set\tmips0\n\t" : "=r" (__res)); __res; }); res &= ~change; res |= (new & change); do { if (0 == 0) __asm__ __volatile__( "mtc0\t%z0, " "$13" "\n\t" : : "Jr" (res)); else __asm__ __volatile__( ".set\tmips32\n\t" "mtc0\t%z0, " "$13" ", " "0" "\n\t" ".set\tmips0" : : "Jr" (res)); } while (0); return res; }
static inline unsigned int set_c0_config(unsigned int set) { unsigned int res; res = ({ int __res; if (0 == 0) __asm__ __volatile__( "mfc0\t%0, " "$16" "\n\t" : "=r" (__res)); else __asm__ __volatile__( ".set\tmips32\n\t" "mfc0\t%0, " "$16" ", " "0" "\n\t" ".set\tmips0\n\t" : "=r" (__res)); __res; }); res |= set; do { if (0 == 0) __asm__ __volatile__( "mtc0\t%z0, " "$16" "\n\t" : : "Jr" (res)); else __asm__ __volatile__( ".set\tmips32\n\t" "mtc0\t%z0, " "$16" ", " "0" "\n\t" ".set\tmips0" : : "Jr" (res)); } while (0); return res; } static inline unsigned int clear_c0_config(unsigned int clear) { unsigned int res; res = ({ int __res; if (0 == 0) __asm__ __volatile__( "mfc0\t%0, " "$16" "\n\t" : "=r" (__res)); else __asm__ __volatile__( ".set\tmips32\n\t" "mfc0\t%0, " "$16" ", " "0" "\n\t" ".set\tmips0\n\t" : "=r" (__res)); __res; }); res &= ~clear; do { if (0 == 0) __asm__ __volatile__( "mtc0\t%z0, " "$16" "\n\t" : : "Jr" (res)); else __asm__ __volatile__( ".set\tmips32\n\t" "mtc0\t%z0, " "$16" ", " "0" "\n\t" ".set\tmips0" : : "Jr" (res)); } while (0); return res; } static inline unsigned int change_c0_config(unsigned int change, unsigned int new) { unsigned int res; res = ({ int __res; if (0 == 0) __asm__ __volatile__( "mfc0\t%0, " "$16" "\n\t" : "=r" (__res)); else __asm__ __volatile__( ".set\tmips32\n\t" "mfc0\t%0, " "$16" ", " "0" "\n\t" ".set\tmips0\n\t" : "=r" (__res)); __res; }); res &= ~change; res |= (new & change); do { if (0 == 0) __asm__ __volatile__( "mtc0\t%z0, " "$16" "\n\t" : : "Jr" (res)); else __asm__ __volatile__( ".set\tmips32\n\t" "mtc0\t%z0, " "$16" ", " "0" "\n\t" ".set\tmips0" : : "Jr" (res)); } while (0); return res; }
# 30 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h" 2
# 30 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h" 2
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/reg.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/reg.h" 1
# 31 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h" 2
# 31 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h" 2





struct cache_desc {
        unsigned short linesz;
        unsigned short ways;
        unsigned short sets;
        unsigned int waysize;
        unsigned int waybit;
        unsigned int flags;
};
# 53 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h"
# 53 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h"
struct cpuinfo_mips {
        unsigned long udelay_val;
        unsigned long *pgd_quick;
        unsigned long *pte_quick;
        unsigned long pgtable_cache_sz;
        unsigned long asid_cache;



        unsigned long options;
        unsigned int processor_id;
        unsigned int fpu_id;
        unsigned int cputype;
        int isa_level;
        int tlbsize;
        struct cache_desc icache;
        struct cache_desc dcache;
        struct cache_desc scache;
        struct cache_desc tcache;
} __attribute__((aligned(16)));
# 106 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h"
# 106 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h"
extern struct cpuinfo_mips cpu_data[];


extern void cpu_probe(void);
extern void cpu_report(void);




extern void (*cpu_wait)(void);

extern unsigned int vced_count, vcei_count;
# 151 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h"
# 151 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h"
struct mips_fpu_hard_struct {
        double fp_regs[32];
        unsigned int control;
};







typedef u64 fpureg_t;
struct mips_fpu_soft_struct {
        fpureg_t regs[32];
        unsigned int sr;
};

union mips_fpu_union {
        struct mips_fpu_hard_struct hard;
        struct mips_fpu_soft_struct soft;
};





typedef struct {
        unsigned long seg;
} mm_segment_t;




struct thread_struct {

        unsigned long reg16;
        unsigned long reg17, reg18, reg19, reg20, reg21, reg22, reg23;
        unsigned long reg29, reg30, reg31;


        unsigned long cp0_status;


        union mips_fpu_union fpu;


        unsigned long cp0_badvaddr;
        unsigned long cp0_baduaddr;
        unsigned long error_code;
        unsigned long trap_no;


        unsigned long mflags;
        mm_segment_t current_ds;
        unsigned long irix_trampoline;
        unsigned long irix_oldctx;
};
# 244 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h"
# 244 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/processor.h"
extern int arch_kernel_thread(int (*fn)(void *), void * arg, unsigned long flags);





struct mips_frame_info {
        int frame_offset;
        int pc_offset;
};
extern struct mips_frame_info schedule_frame;



static inline unsigned long thread_saved_pc(struct thread_struct *t)
{
        extern void ret_from_fork(void);


        if (t->reg31 == (unsigned long) ret_from_fork)
                return t->reg31;

        if (schedule_frame.pc_offset < 0)
                return 0;
        return ((unsigned long *)t->reg29)[schedule_frame.pc_offset];
}




extern void start_thread(struct pt_regs * regs, unsigned long pc, unsigned long sp);

struct task_struct;
unsigned long get_wchan(struct task_struct *p);
# 14 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/prefetch.h" 2
# 14 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/prefetch.h" 2
# 43 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/prefetch.h"
# 43 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/prefetch.h"
static inline void prefetch(const void *x) {;}




static inline void prefetchw(const void *x) {;}
# 7 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/list.h" 2
# 7 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/list.h" 2
# 18 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/list.h"
# 18 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/list.h"
struct list_head {
        struct list_head *next, *prev;
};
# 37 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/list.h"
# 37 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/list.h"
static inline void __list_add(struct list_head *new,
                              struct list_head *prev,
                              struct list_head *next)
{
        next->prev = new;
        new->next = next;
        new->prev = prev;
        prev->next = new;
}
# 55 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/list.h"
# 55 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/list.h"
static inline void list_add(struct list_head *new, struct list_head *head)
{
        __list_add(new, head, head->next);
}
# 68 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/list.h"
# 68 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/list.h"
static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
        __list_add(new, head->prev, head);
}
# 80 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/list.h"
# 80 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/list.h"
static inline void __list_del(struct list_head *prev, struct list_head *next)
{
        next->prev = prev;
        prev->next = next;
}






static inline void list_del(struct list_head *entry)
{
        __list_del(entry->prev, entry->next);
        entry->next = (void *) 0;
        entry->prev = (void *) 0;
}





static inline void list_del_init(struct list_head *entry)
{
        __list_del(entry->prev, entry->next);
        do { (entry)->next = (entry); (entry)->prev = (entry); } while (0);
}






static inline void list_move(struct list_head *list, struct list_head *head)
{
        __list_del(list->prev, list->next);
        list_add(list, head);
}






static inline void list_move_tail(struct list_head *list,
                                  struct list_head *head)
{
        __list_del(list->prev, list->next);
        list_add_tail(list, head);
}





static inline int list_empty(struct list_head *head)
{
        return head->next == head;
}

static inline void __list_splice(struct list_head *list,
                                 struct list_head *head)
{
        struct list_head *first = list->next;
        struct list_head *last = list->prev;
        struct list_head *at = head->next;

        first->prev = head;
        head->next = first;

        last->next = at;
        at->prev = last;
}






static inline void list_splice(struct list_head *list, struct list_head *head)
{
        if (!list_empty(list))
                __list_splice(list, head);
}
# 172 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/list.h"
# 172 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/list.h"
static inline void list_splice_init(struct list_head *list,
                                    struct list_head *head)
{
        if (!list_empty(list)) {
                __list_splice(list, head);
                do { (list)->next = (list); (list)->prev = (list); } while (0);
        }
}
# 13 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/module.h" 2
# 13 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/module.h" 2
# 25 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/module.h"
# 25 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/module.h"
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/atomic.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/atomic.h" 1
# 19 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/atomic.h"
# 19 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/atomic.h"
typedef struct { volatile int counter; } atomic_t;
# 58 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/atomic.h"
# 58 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/atomic.h"
static __inline__ void atomic_add(int i, atomic_t * v)
{
        unsigned long flags;

        __asm__ __volatile__( "__save_and_cli\t%0" : "=r" (flags) : : "memory");
        v->counter += i;
        do { unsigned long __tmp1; __asm__ __volatile__( "__restore_flags\t%0" : "=r" (__tmp1) : "0" (flags) : "memory"); } while(0);
}
# 75 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/atomic.h"
# 75 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/atomic.h"
static __inline__ void atomic_sub(int i, atomic_t * v)
{
        unsigned long flags;

        __asm__ __volatile__( "__save_and_cli\t%0" : "=r" (flags) : : "memory");
        v->counter -= i;
        do { unsigned long __tmp1; __asm__ __volatile__( "__restore_flags\t%0" : "=r" (__tmp1) : "0" (flags) : "memory"); } while(0);
}

static __inline__ int atomic_add_return(int i, atomic_t * v)
{
        unsigned long flags;
        int temp;

        __asm__ __volatile__( "__save_and_cli\t%0" : "=r" (flags) : : "memory");
        temp = v->counter;
        temp += i;
        v->counter = temp;
        do { unsigned long __tmp1; __asm__ __volatile__( "__restore_flags\t%0" : "=r" (__tmp1) : "0" (flags) : "memory"); } while(0);

        return temp;
}

static __inline__ int atomic_sub_return(int i, atomic_t * v)
{
        unsigned long flags;
        int temp;

        __asm__ __volatile__( "__save_and_cli\t%0" : "=r" (flags) : : "memory");
        temp = v->counter;
        temp -= i;
        v->counter = temp;
        do { unsigned long __tmp1; __asm__ __volatile__( "__restore_flags\t%0" : "=r" (__tmp1) : "0" (flags) : "memory"); } while(0);

        return temp;
}
# 26 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/module.h" 2
# 26 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/module.h" 2


struct exception_table_entry;


struct kernel_sym
{
        unsigned long value;
        char name[60];
};

struct module_symbol
{
        unsigned long value;
        const char *name;
};

struct module_ref
{
        struct module *dep;
        struct module *ref;
        struct module_ref *next_ref;
};


struct module_persist;

struct module
{
        unsigned long size_of_struct;
        struct module *next;
        const char *name;
        unsigned long size;

        union
        {
                atomic_t usecount;
                long pad;
        } uc;

        unsigned long flags;

        unsigned nsyms;
        unsigned ndeps;

        struct module_symbol *syms;
        struct module_ref *deps;
        struct module_ref *refs;
        int (*init)(void);
        void (*cleanup)(void);
        const struct exception_table_entry *ex_table_start;
        const struct exception_table_entry *ex_table_end;






        const struct module_persist *persist_start;
        const struct module_persist *persist_end;
        int (*can_unload)(void);
        int runsize;
        const char *kallsyms_start;
        const char *kallsyms_end;
        const char *archdata_start;
        const char *archdata_end;
        const char *kernel_data;
};

struct module_info
{
        unsigned long addr;
        unsigned long size;
        unsigned long flags;
        long usecount;
};
# 183 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/module.h"
# 183 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/module.h"
extern void inter_module_register(const char *, struct module *, const void *);
extern void inter_module_unregister(const char *);
extern const void *inter_module_get(const char *);
extern const void *inter_module_get_request(const char *, const char *);
extern void inter_module_put(const char *);

struct inter_module_entry {
        struct list_head list;
        const char *im_name;
        struct module *owner;
        const void *userdata;
};

extern int try_inc_mod_count(struct module *mod);
# 331 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/module.h"
# 331 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/module.h"
extern struct module *module_list;
# 207 "rtl_types.h" 2
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/string.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/string.h" 1
# 19 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/string.h"
# 19 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/string.h"
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/string.h" 1
# 1 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/string.h" 1
# 15 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/string.h"
# 15 "../../../../../../uClinux-dist/linux-2.4.x/include/asm/string.h"
static __inline__ char *strcpy(char *__dest, __const__ char *__src)
{
  char *__xdest = __dest;

  __asm__ __volatile__(
        ".set\tnoreorder\n\t"
        ".set\tnoat\n"
        "1:\tlbu\t$1,(%1)\n\t"
        "addiu\t%1,1\n\t"
        "sb\t$1,(%0)\n\t"
        "bnez\t$1,1b\n\t"
        "addiu\t%0,1\n\t"
        ".set\tat\n\t"
        ".set\treorder"
        : "=r" (__dest), "=r" (__src)
        : "0" (__dest), "1" (__src)
        : "memory");

  return __xdest;
}


static __inline__ char *strncpy(char *__dest, __const__ char *__src, size_t __n)
{
  char *__xdest = __dest;

  if (__n == 0)
    return __xdest;

  __asm__ __volatile__(
        ".set\tnoreorder\n\t"
        ".set\tnoat\n"
        "1:\tlbu\t$1,(%1)\n\t"
        "subu\t%2,1\n\t"
        "sb\t$1,(%0)\n\t"
        "beqz\t$1,2f\n\t"
        "addiu\t%0,1\n\t"
        "bnez\t%2,1b\n\t"
        "addiu\t%1,1\n"
        "2:\n\t"
        ".set\tat\n\t"
        ".set\treorder"
        : "=r" (__dest), "=r" (__src), "=r" (__n)
        : "0" (__dest), "1" (__src), "2" (__n)
        : "memory");

  return __xdest;
}


static __inline__ int strcmp(__const__ char *__cs, __const__ char *__ct)
{
  int __res;

  __asm__ __volatile__(
        ".set\tnoreorder\n\t"
        ".set\tnoat\n\t"
        "lbu\t%2,(%0)\n"
        "1:\tlbu\t$1,(%1)\n\t"
        "addiu\t%0,1\n\t"
        "bne\t$1,%2,2f\n\t"
        "addiu\t%1,1\n\t"
        "bnez\t%2,1b\n\t"
        "lbu\t%2,(%0)\n\t"

        "nop\n\t"

        "move\t%2,$1\n"
        "2:\tsubu\t%2,$1\n"
        "3:\t.set\tat\n\t"
        ".set\treorder"
        : "=r" (__cs), "=r" (__ct), "=r" (__res)
        : "0" (__cs), "1" (__ct));

  return __res;
}


static __inline__ int
strncmp(__const__ char *__cs, __const__ char *__ct, size_t __count)
{
        int __res;

        __asm__ __volatile__(
        ".set\tnoreorder\n\t"
        ".set\tnoat\n"
        "1:\tlbu\t%3,(%0)\n\t"
        "beqz\t%2,2f\n\t"
        "lbu\t$1,(%1)\n\t"
        "subu\t%2,1\n\t"
        "bne\t$1,%3,3f\n\t"
        "addiu\t%0,1\n\t"
        "bnez\t%3,1b\n\t"
        "addiu\t%1,1\n"
        "2:\n\t"

        "nop\n\t"

        "move\t%3,$1\n"
        "3:\tsubu\t%3,$1\n\t"
        ".set\tat\n\t"
        ".set\treorder"
        : "=r" (__cs), "=r" (__ct), "=r" (__count), "=r" (__res)
        : "0" (__cs), "1" (__ct), "2" (__count));

        return __res;
}


extern void *memset(void *__s, int __c, size_t __count);


extern void *memcpy(void *__to, __const__ void *__from, size_t __n);


extern void *memmove(void *__dest, __const__ void *__src, size_t __n);





static __inline__ void *memscan(void *__addr, int __c, size_t __size)
{
        char *__end = (char *)__addr + __size;
        unsigned char __uc = (unsigned char) __c;

        __asm__(".set\tpush\n\t"
                ".set\tnoat\n\t"
                ".set\treorder\n\t"
                "1:\tbeq\t%0,%1,2f\n\t"
                "addiu\t%0,1\n\t"
                "lbu\t$1,-1(%0)\n\t"
                "bne\t$1,%z4,1b\n"
                "2:\t.set\tpop"
                : "=r" (__addr), "=r" (__end)
                : "0" (__addr), "1" (__end), "Jr" (__uc));

        return __addr;
}
# 20 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/string.h" 2
# 20 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/string.h" 2


extern char * ___strtok;
extern char * strpbrk(const char *,const char *);
extern char * strtok(char *,const char *);
extern char * strsep(char **,const char *);
extern __kernel_size_t strspn(const char *,const char *);
# 36 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/string.h"
# 36 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/string.h"
extern char * strcat(char *, const char *);


extern char * strncat(char *, const char *, __kernel_size_t);
# 48 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/string.h"
# 48 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/string.h"
extern int strnicmp(const char *, const char *, __kernel_size_t);


extern char * strchr(const char *,int);


extern char * strrchr(const char *,int);


extern char * strstr(const char *,const char *);


extern __kernel_size_t strlen(const char *);


extern __kernel_size_t strnlen(const char *,__kernel_size_t);
# 79 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/string.h"
# 79 "../../../../../../uClinux-dist/linux-2.4.x/include/linux/string.h"
extern int memcmp(const void *,const void *,__kernel_size_t);


extern void * memchr(const void *,int,__kernel_size_t);
# 208 "rtl_types.h" 2
# 309 "rtl_types.h"
typedef unsigned long long uint64;
typedef long long int64;
typedef unsigned int uint32;
typedef int int32;
typedef unsigned short uint16;
typedef short int16;
typedef unsigned char uint8;
typedef char int8;


typedef uint32 memaddr;
typedef uint32 ipaddr_t;
typedef struct {
    uint16 mac47_32;
    uint16 mac31_16;
    uint16 mac15_0;
} macaddr_t;


typedef struct ether_addr_s {
        uint8 octet[6];
} ether_addr_t;
# 12 "rtl8651_multicast.c" 2
# 1 "rtl8651_multicast_local.h" 1
# 14 "rtl8651_multicast_local.h"
# 1 "assert.h" 1
# 15 "rtl8651_multicast_local.h" 2
# 1 "types.h" 1
# 16 "rtl8651_multicast_local.h" 2





# 1 "rtl_queue.h" 1
# 22 "rtl8651_multicast_local.h" 2
# 1 "rtl_errno.h" 1
# 23 "rtl8651_multicast_local.h" 2

# 1 "rtl8651_timer.h" 1





extern uint32 _sysUpSeconds;
# 246 "rtl8651_timer.h"
struct rtl8651_timer_list {
        struct list_head list;
        uint32 expires;
        uint32 data;
        void (*function)(uint32);
};

int _rtl8651_del_timer(struct rtl8651_timer_list * timer);
int _rtl8651_mod_timer(struct rtl8651_timer_list *timer, uint32 expires);
void _rtl8651_init_timer(struct rtl8651_timer_list * timer);
# 25 "rtl8651_multicast_local.h" 2
# 1 "rtl8651_tblDrvProto.h" 1
# 21 "rtl8651_tblDrvProto.h"
struct ether_header {
        uint8 ether_dhost[6];
        uint8 ether_shost[6];
        uint16 ether_type;
};
# 36 "rtl8651_tblDrvProto.h"
struct ether_addr {
        uint8 octet[6];
};


typedef struct pppoeHdr_s {



        uint8 ver:4, type:4;

        uint8 code;
        uint16 sessionId,
                        length;
        uint16 proto;
} pppoeHdr_t;





struct in_addr{
        uint32 s_addr;
};







struct ip {
# 90 "rtl8651_tblDrvProto.h"
        uint8 ip_vhl;


        uint8 ip_tos;
        uint16 ip_len;
        uint16 ip_id;
        uint16 ip_off;
        uint8 ip_ttl;
        uint8 ip_p;
        uint16 ip_sum;
        struct in_addr ip_src,ip_dst;
};
typedef struct ip ip_t;
# 114 "rtl8651_tblDrvProto.h"
struct icmp_ra_addr {
        uint32 ira_addr;
        uint32 ira_preference;
};

struct icmp {
        uint8 icmp_type;
        uint8 icmp_code;
        uint16 icmp_cksum;
        union {
                uint8 ih_pptr;
                struct in_addr ih_gwaddr;
                struct ih_idseq {
                        uint16 icd_id;
                        uint16 icd_seq;
                } ih_idseq;
                uint32 ih_void;


                struct ih_pmtu {
                        uint16 ipm_void;
                        uint16 ipm_nextmtu;
                } ih_pmtu;

                struct ih_rtradv {
                        uint8 irt_num_addrs;
                        uint8 irt_wpa;
                        uint16 irt_lifetime;
                } ih_rtradv;
        } icmp_hun;
# 154 "rtl8651_tblDrvProto.h"
        union {
                struct id_ts {
                        uint32 its_otime;
                        uint32 its_rtime;
                        uint32 its_ttime;
                } id_ts;
                struct id_ip {
                        struct ip idi_ip;

                } id_ip;
                struct icmp_ra_addr id_radv;
                uint32 id_mask;
                int8 id_data[1];
        } icmp_dun;







};
# 228 "rtl8651_tblDrvProto.h"
struct igmp_gr {
        uint8 igmp_gr_rt;
        uint8 igmp_gr_auxlen;
        uint16 igmp_gr_nofs;
        ipaddr_t igmp_gr_group;
        ipaddr_t src_list;

 };
struct igmp {
        uint8 igmp_type;
        uint8 igmp_code;
        uint16 igmp_cksum;

        union {
                struct in_addr group;
                struct v3_report{
                        uint16 resv;
                        uint16 nofg;
                } v3_report;
        } grp;

        union {
                struct query {
                        uint8 rsq;



                        uint8 qqic;
                        uint16 nofs;
                        ipaddr_t src_list;
                } query;
                struct report {
                        struct igmp_gr gr_list;
                } report;
        } un_v3;
# 276 "rtl8651_tblDrvProto.h"
};
# 304 "rtl8651_tblDrvProto.h"
typedef uint32 tcp_seq;
struct tcphdr {
        uint16 th_sport;
        uint16 th_dport;
        tcp_seq th_seq;
        tcp_seq th_ack;
# 320 "rtl8651_tblDrvProto.h"
        uint8 th_off_x;



        uint8 th_flags;
# 335 "rtl8651_tblDrvProto.h"
        uint16 th_win;
        uint16 th_sum;
        uint16 th_urp;
# 362 "rtl8651_tblDrvProto.h"
};





struct udphdr
{
        uint16 uh_sport;
        uint16 uh_dport;
        uint16 uh_ulen;
        uint16 uh_sum;
};





struct tftpRequest {
        uint16 opcode;
        char *string;
};
# 394 "rtl8651_tblDrvProto.h"
typedef struct espHdr_s
{
        uint32 spi;
        uint32 seq;
} espHdr_t;

typedef struct cbcHdr64_s
{
        uint32 iv[2];
} cbcHdr64_t;

typedef struct cbcHdr128_s
{
        uint32 iv[4];
} cbcHdr128_t;
# 26 "rtl8651_multicast_local.h" 2
# 1 "rtl8651_tblDrvLocal.h" 1
# 22 "rtl8651_tblDrvLocal.h"
# 1 "mbuf.h" 1
# 30 "mbuf.h"
struct rtl_mBuf
{



        struct rtl_mBuf *m_next;

        struct rtl_pktHdr *m_pkthdr;

        uint16 m_len;
        int8 m_flags;





        int8 m_unused1;

        uint8 *m_data;



        uint8 *m_extbuf;
        uint32 m_extClusterId;
        void *m_unused2;
        uint16 m_extsize;

        uint8 m_reserved[2];
};


struct ifnet;




struct rtl_pktHdr
{




        union
        {
                struct rtl_pktHdr *pkthdr_next;
                struct rtl_mBuf *mbuf_first;
        }PKTHDRNXT;




        uint16 ph_len;
        uint16 ph_flags;
# 127 "mbuf.h"
        uint16 ph_proto:3;
        uint16 ph_vlanTagged:1;
        uint16 ph_LLCTagged:1;
        uint16 ph_pppeTagged:1;
        uint16 ph_pppoeIdx:3;



        uint16 ph_vlanIdx:3;
        uint16 ph_reserved2:4;
# 148 "mbuf.h"
        uint16 ph_reason;


        uint8 ph_extPortList;

        uint8 ph_srcExtPortNum;

        uint16 ph_portlist;






        uint32 ph_reserved;


        struct rtl_pktHdr *ph_nextHdr;
        uint32 ph_sip, ph_dip;


        int8 ph_routeIdx;
        uint8 ph_iphdrOffset;
        int16 ph_rxdesc;
# 186 "mbuf.h"
        int16 ph_rxmbufdesc;

        union {
                struct {
                       uint16 _ph_dataLen;
                        uint16 _ph_fragOffset;
                        uint8 _ph_unnumber;
                        uint8 _ph_dsid;
                        uint16 _ph_sport;
                        uint8 _ph_priority;
                        uint8 _ph_procFlag;
                        uint8 _ph_reserved1;
                        uint8 _ph_reserved2;
                } ROMEDRV_USG;
                union {

                        struct {
                                uint16 _ph_category;
                                uint16 _ph_reserved1;
                                uint16 _ph_reserved2;
                                uint16 _ph_reserved3;
                        } TO_PS;

                        struct {
                                uint32 _ph_pkt_property;
                                uint16 _ph_reserved1;
                                uint16 _ph_reserved2;
                        } FROM_PS;
                } PS_USG;
        } ph_un_sw;
# 236 "mbuf.h"
};

struct rtl_mBufStatus
{
        uint32 m_totalmbufs;
        uint32 m_totalclusters;
        uint32 m_totalpkthdrs;
        uint32 m_freembufs;
        uint32 m_freeclusters;
        uint32 m_freepkthdrs;
        uint32 m_msize;
        uint32 m_mclbytes;
        uint32 m_pkthdrsize;

        uint32 m_wait;
};
# 268 "mbuf.h"
extern int32 m_clusterSize;
# 289 "mbuf.h"
extern int32 mBuf_init(uint32, uint32, uint32, uint32, uint32);
# 310 "mbuf.h"
extern int32 mBuf_getBufStat(struct rtl_mBufStatus *mbs);
# 321 "mbuf.h"
extern int32 mBuf_leadingSpace(struct rtl_mBuf *m);
# 335 "mbuf.h"
extern int32 mBuf_trailingSpace(struct rtl_mBuf *m);
# 349 "mbuf.h"
extern int32 mBuf_clusterIsWritable(struct rtl_mBuf *m);
# 364 "mbuf.h"
extern uint32 mBuf_getPktlen(struct rtl_mBuf *m);
# 376 "mbuf.h"
extern struct rtl_mBuf *mBuf_data2Mbuf(int8 * x);
# 400 "mbuf.h"
extern struct rtl_mBuf *mBuf_get(int32 how, int32 unused, uint32 Nbuf);
# 435 "mbuf.h"
extern struct rtl_mBuf *mBuf_getCleared(int32 how, int32 unused, uint32 Nbuf);
# 459 "mbuf.h"
extern uint32 mBuf_driverGet(uint32 Nmbuf,struct rtl_mBuf **ppFirstMbuf, struct rtl_mBuf **ppLastMbuf);
# 482 "mbuf.h"
extern struct rtl_mBuf *mBuf_getm(struct rtl_mBuf *m, uint32 len, int32 how, int32 unused);
# 516 "mbuf.h"
extern struct rtl_mBuf *mBuf_getPkthdr(struct rtl_mBuf *m, int32 how);
# 543 "mbuf.h"
extern uint32 mBuf_driverGetPkthdr(uint32 Npkthdr,struct rtl_pktHdr **ppHeadPkthdr, struct rtl_pktHdr **ppTailPkthdr);
# 566 "mbuf.h"
extern void mBuf_freeMbuf(struct rtl_mBuf *m);
# 582 "mbuf.h"
extern int32 mBuf_attachCluster(struct rtl_mBuf *m, void *buffer, uint32 id, uint32 size, uint16 datalen, uint16 align);
# 601 "mbuf.h"
extern int32 mBuf_freeOneMbufPkthdr(struct rtl_mBuf *m, void **buffer, uint32 *id, uint16 *size);
# 625 "mbuf.h"
extern struct rtl_mBuf *mBuf_freeOne(struct rtl_mBuf *m);
# 644 "mbuf.h"
extern uint32 mBuf_freeMbufChain(register struct rtl_mBuf *m);
# 667 "mbuf.h"
extern uint32 mBuf_driverFreeMbufChain(struct rtl_mBuf *pFirstMbuf);
# 691 "mbuf.h"
extern void mBuf_freePkthdr(struct rtl_pktHdr *ph);
# 703 "mbuf.h"
uint32 mBuf_driverFreePkthdr(struct rtl_pktHdr *ph, uint32 Npkthdr, struct rtl_pktHdr **ppHeadPkthdr);
# 717 "mbuf.h"
extern struct rtl_mBuf *mBuf_adjHead(struct rtl_mBuf *, uint32 req_len);
# 736 "mbuf.h"
extern struct rtl_mBuf *mBuf_adjTail(struct rtl_mBuf *, uint32 req_len);
# 755 "mbuf.h"
extern struct rtl_mBuf *mBuf_trimHead(struct rtl_mBuf *, uint32 req_len);
# 775 "mbuf.h"
extern struct rtl_mBuf *mBuf_trimTail(struct rtl_mBuf *, uint32 req_len);
# 797 "mbuf.h"
extern int32 mBuf_copyToMbuf(struct rtl_mBuf *, uint32 offset, uint32 len, int8 *cp);
# 832 "mbuf.h"
extern int32 mBuf_copyToUserBuffer(struct rtl_mBuf *m, uint32 off, uint32 len, int8 * cp);
# 856 "mbuf.h"
extern struct rtl_mBuf *mBuf_cloneMbufChain(struct rtl_mBuf *pThisMbuf, int32 iOffset,
                                                        int32 iLength, int32 iWait);
# 888 "mbuf.h"
extern struct rtl_mBuf *mBuf_dupMbufChain(struct rtl_mBuf *pMbufChain, int32 iOffset, int32 iLength, int32 flag);
# 920 "mbuf.h"
extern struct rtl_mBuf *mBuf_clonePacket(struct rtl_mBuf *pMbuf, int32 iHow);
# 945 "mbuf.h"
extern struct rtl_mBuf *mBuf_dupPacket(struct rtl_mBuf *pMbuf, int32 iHow);
# 974 "mbuf.h"
extern struct rtl_mBuf *mBuf_prepend(struct rtl_mBuf *m, uint32 plen, int32 how);
# 1007 "mbuf.h"
extern struct rtl_mBuf *mBuf_padding(struct rtl_mBuf *m, uint32 plen, int32 how);
# 1037 "mbuf.h"
extern struct rtl_mBuf *mBuf_cat(struct rtl_mBuf *m, struct rtl_mBuf *n);
# 1054 "mbuf.h"
extern int32 mBuf_pullup(struct rtl_mBuf *, int32);
# 1096 "mbuf.h"
struct rtl_mBuf *mBuf_split(register struct rtl_mBuf *m0, uint32 len0, int32 wait);
# 1119 "mbuf.h"
void mBuf_getBMjmpTable(uint8 *pat, uint16 *jump_tbl,uint16 patLen, uint8 caseSensitive);
int32 mBuf_BMpatternMatch(struct rtl_mBuf *m, uint32 len, uint8 *delimiter, uint32 delimitLen, uint16 *jmp_tbl, uint8 caseSensitive);
# 1135 "mbuf.h"
 struct rtl_mBuf *mBuf_attachHeader(void *buffer, uint32 id, uint32 bufsize,uint32 datalen, uint16 align);
int32 mBuf_setNICRxRingSize(uint32 size);
# 23 "rtl8651_tblDrvLocal.h" 2



# 1 "rtl8651_layer2.h" 1
# 82 "rtl8651_layer2.h"
extern uint32 rtl8651_tblDrvCpuMirrorPortMask;
extern int32 rtl8651_totalExtPortNum;
extern int32 rtl8651_allExtPortMask;
extern int32 rtl8651_bridgeEnable;



extern uint32 fake_DisableFlowControl[];
extern uint32 prePortState[];




int32 rtl8651_installPortStatusChangeNotifier(void (*notifier)(uint32 port, int8 linkUp));
int32 rtl8651_getEthernetPortLinkStatus(uint32 port, int8 * linkUp, uint16 *speed, int8 *fullduplex, int8 *autoNeg);
int32 rtl8651_setEthernetPortDuplexMode(uint32 port, int8 fullDuplex);
int32 rtl8651_setEthernetPortSpeed(uint32 port, uint32 speed);
int32 rtl8651_setEthernetPortAutoNegotiation(uint32 port, int8 autoNegotiation, uint32 advCapability);
int32 rtl8651_setEthernetPortBandwidthControl(uint32 port, int8 input, uint32 rate);




int32 rtl8651_addSpanningTreeInstance(uint16 sid);
int32 rtl8651_setSpanningTreeInstanceProtocolWorking(uint16 sid, int8 working);
int32 rtl8651_delSpanningTreeInstance(uint16 sid);
int32 rtl8651_setSpanningTreeInstancePortState(uint16 stid, uint16 port, uint8 portState);


int32 rtl8651_addFilterDatabase(uint16 fid);
int32 rtl8651_delFilterDatabase(uint16 fid);
int32 rtl8651_specifyFilterDatabaseSpanningTreeInstance(uint16 fid, uint16 sid);
int32 rtl8651_addFilterDatabaseEntry(uint16 fid, ether_addr_t * macAddr, uint32 type, uint32 portMask);
int32 rtl8651_delFilterDatabaseEntry(uint16 fid, ether_addr_t * macAddr);
int32 rtl8651_installFDBEntryChangeNotifier( void (*notify)(void *l2entry_t,void *arg));





int32 rtl8651_setAggregatorIndividual(uint16 aggregator, int8 individual);
int32 rtl8651_setPortAggregator(uint32 port, uint16 aggregator);
int32 rtl8651_getAggregatorActiveStatus(uint16 aggregator, int8 * isActive);
int32 rtl8651_setPvid(uint32 aggregator, uint16 vid);



int32 rtl8651_addVlan(uint16 vid);

int32 rtl8651_delVlan(uint16 vid);

int32 rtl8651_allocateVlanMacAddress(uint16 vid, uint16 macAddrNumber);
int32 rtl8651_getVlanMacAddress(uint16 vid, ether_addr_t * macAddr, uint16 * macAddrNumber);

int32 rtl8651_assignVlanMacAddress(uint16 vid, ether_addr_t * macAddress, uint16 macAddrNumber);
int32 rtl8651_delVlanPortMember(uint16 vid, uint32 port);
int32 rtl8651_addVlanPortMember(uint16 vid, uint32 port);
int32 rtl8651_specifyVlanFilterDatabase(uint16 vid, uint16 fid);


int32 rtl8651_setVlanPromiscuous(uint16 vid, int8 isPromiscuous);
int32 rtl8651_setVlanFwdTxMirror(uint16 vid, int8 isFwdTxMirror);
int32 rtl8651_getVlanActiveStatus(uint16 vid, int8 * isActive);
int32 rtl8651_setVlanPortUntag(uint16 vid, uint32 port, int8 untag);



int32 rtl8651_pureSoftwareFwd(int8 isSoftFwd);

int32 rtl8651_addProtoTrap(uint8 protoType, uint16 protoContent);
int32 rtl8651_delProtoTrap(uint8 protoType, uint16 protoContent);

int32 rtl8651_enableBroadCastStormPrevention(int8 enable);
struct rtl_pktHdr;
struct rtl_mBuf;
void rtl8651_installArpAgent(int32 (*arpAgent)(struct rtl_pktHdr *pkthdrPtr,struct rtl_mBuf *mbufPtr,uint16 vid));

int32 rtl8651_resetRxTxMirror(void);
int32 rtl8651_addRxTxMirror(int8 isRxMirror, uint32 port);
int32 rtl8651_addMirrorPort(uint32 port);
int32 rtl8651_delMirrorPort(uint32 port);

extern uint32 rtl8651_l2protoPassThrough;





extern int8 rtl8651_drvDropUnknownPppoePADT;
extern struct ether_header rtl8651_knownPppoePassthruEthHdr;
# 27 "rtl8651_tblDrvLocal.h" 2
# 1 "rtl8651_tblDrv.h" 1
# 23 "rtl8651_tblDrv.h"
# 1 "rtl8651_debug.h" 1
# 24 "rtl8651_tblDrv.h" 2
# 136 "rtl8651_tblDrv.h"
typedef struct rtl8651_tblDrvInitPara_s {
        uint32 macAddressDbSize;
        uint32 filterDbSize;
        uint32 networkIntfTableSize;
        uint32 ipIntfEntryNumber;
        uint32 ipIntfIpAddrNumber;
        uint32 arpTableSize;
        uint32 routingTableSize;
        uint32 natSize;
        uint32 natCtlSize;
        uint32 naptServerPortEntryNumber;
        uint32 naptTcpUdpFlowSize;
        uint32 naptIcmpFlowSize;
        uint32 aclSize;
        uint32 algSize;
        uint32 urlfilterDBSize;
        uint32 urlfilterStringLen;
        uint32 pathfilterStringLen;
        uint32 urlPktfilterDBSize;
        uint32 dialSessionNumber;
        uint32 dmzHostsNum;
        uint32 policyRules;
        uint32 dynamicPolicy;
        uint32 pptpSize;
        uint32 l2tpSize;
        uint32 pppoePassthruSize;
        uint32 protocolBasedNatSize;
        uint32 mCastTblSize;
        uint32 macAccessControllSize;
        uint32 ipUnnumberSize;




        uint32 urlfilterTrustedUserEntryCnt;


} rtl8651_tblDrvInitPara_t;


typedef struct ___rtl8651_tblDrvPolicyRoute_t
{
        int type;
        union
        {
                uint32 ip_s;
                uint32 ip_d;

                struct {
                        uint16 start ;
                        uint16 end;
                }dport;

                struct {
                        ipaddr_t sip;
                        ipaddr_t dip;
                } sipDipPair;

        }trigger;
        uint32 ip_start;
        uint32 ip_end;
        uint32 ip_alias;

} rtl8651_tblDrvPolicyRoute_t;
typedef struct __rtl8651_tblDrvPolicyRoute_t
{
        int type;
        union
        {
                uint32 ip_s;
                uint32 ip_d;
                struct {
                        uint16 start ;
                        uint16 end;
                }dport;

                struct {
                        ipaddr_t sip;
                        ipaddr_t dip;
                } sipDipPair;

        } trigger;
        uint32 ip_start;
        uint32 ip_end;
        uint32 ip_alias;
        void *rt;


        struct __rtl8651_tblDrvPolicyRoute_t *timenext;
        struct __rtl8651_tblDrvPolicyRoute_t *timeprev;
        struct __rtl8651_tblDrvPolicyRoute_t *linknext;
        struct __rtl8651_tblDrvPolicyRoute_t *linkprev;
        uint32 fullAge;
        uint32 age;

} _rtl8651_tblDrvPolicyRoute_t;
# 251 "rtl8651_tblDrv.h"
typedef struct __rtl8651_tblDrvDemandRoute_t
{
        int type;
        union
        {
                int ip_s;
                int ip_d;
                struct {
                        uint16 start ;
                        uint16 end;
                }dport;
        }trigger;
        uint32 ip_start;
        uint32 ip_end;
        int identity;
        int32 (*p_handler)(uint32);
} rtl8651_tblDrvDemandRoute_t;





typedef struct rtl8651_tblDrvPolicy_s {
        uint32 proto;
        ipaddr_t sip, sipMask,
                                dip, dipMask;
        uint16 sport_start, sport_end,
                                dport_start, dport_end;
        ipaddr_t naptip;

} rtl8651_tblDrvPolicy_t;
# 297 "rtl8651_tblDrv.h"
typedef struct rtl8651_tblDrvAclRule_s {
        union {

                struct {
                        ether_addr_t _dstMac, _dstMacMask;
                        ether_addr_t _srcMac, _srcMacMask;
                        uint16 _typeLen, _typeLenMask;
                } MAC;

                struct {
                        uint8 _gidxSel;
                } IFSEL;

                struct {
                        ipaddr_t _srcIpAddr, _srcIpAddrMask;
                        ipaddr_t _dstIpAddr, _dstIpAddrMask;
                        uint8 _tos, _tosMask;
                        union {

                                struct {
                                        uint8 _proto, _protoMask, _flagMask;


                                        uint32 _FOP:1, _FOM:1, _httpFilter:1, _httpFilterM:1, _identSrcDstIp:1, _identSrcDstIpM:1;

                                        union {
                                                uint8 _flag;
                                                struct {
                                                        uint8 pend1:5,
                                                                 pend2:1,
                                                                 _DF:1,
                                                                 _MF:1;
                                                } s;
                                        } un;
                                } ip;

                                struct {
                                        uint8 _type, _typeMask, _code, _codeMask;
                                } icmp;

                                struct {
                                        uint8 _type, _typeMask;
                                } igmp;

                                struct {
                                        ether_addr_t _l2srcMac, _l2srcMacMask;
                                        uint8 _flagMask;
                                        uint16 _srcPortUpperBound, _srcPortLowerBound;
                                        uint16 _dstPortUpperBound, _dstPortLowerBound;
                                        union {
                                                uint8 _flag;
                                                struct {
                                                        uint8 _pend:2,
                                                                  _urg:1,
                                                                  _ack:1,
                                                                  _psh:1,
                                                                  _rst:1,
                                                                  _syn:1,
                                                                  _fin:1;
                                                }s;
                                        }un;
                                }tcp;

                                struct {
                                        ether_addr_t _l2srcMac, _l2srcMacMask;
                                        uint16 _srcPortUpperBound, _srcPortLowerBound;
                                        uint16 _dstPortUpperBound, _dstPortLowerBound;
                                }udp;
                        }is;
                }L3L4;



                struct {
                        ether_addr_t _srcMac, _srcMacMask;
                        uint16 _srcPort, _srcPortMask;
                        uint16 _srcVlanIdx, _srcVlanIdxMask;
                        ipaddr_t _srcIpAddr, _srcIpAddrMask;
                        uint16 _srcPortUpperBound, _srcPortLowerBound;
                        uint32 _ignoreL4:1,
                                        _ignoreL3L4:1;
                } SRCFILTER;

                struct {
                        ether_addr_t _dstMac, _dstMacMask;
                        uint16 _vlanIdx, _vlanIdxMask;
                        ipaddr_t _dstIpAddr, _dstIpAddrMask;
                        uint16 _dstPortUpperBound, _dstPortLowerBound;
                        uint32 _ignoreL4:1,
                                         _ignoreL3L4:1;
                } DSTFILTER;

        }un_ty;

        uint32 ruleType_:4;
        uint32 actionType_:4;

        uint32 pktOpApp:3;

        uint32 isEgressRateLimitRule_: 1;
        uint32 matchType_;
} rtl8651_tblDrvAclRule_t;
# 541 "rtl8651_tblDrv.h"
typedef struct rtl865x_tblDrv_basicCounterParam_s {
        uint32 txPackets;
        uint32 txBytes;
        uint32 rxPackets;
        uint32 rxBytes;
        uint32 rxErrors;
        uint32 drops;
} rtl865x_tblDrv_basicCounterParam_t;







void rtl8651_realtimeSchedule(void);
void rtl8651_timeUpdate(uint32 dummy);
int32 rtl8651_enableNaptAutoAdd(int8 enable);


int32 rtl8651a_addAclRule(uint32 SessionID,int8 * ifName, int8 Ingress, rtl8651_tblDrvAclRule_t *rule);

int32 rtl8651a_delAclRule(uint32 SessionID,int8 *ifName, int8 Ingress, rtl8651_tblDrvAclRule_t *rule);

int32 rtl8651a_addAclRuleExt(uint32 sessionId, int8 *ifName, int8 Ingress, rtl8651_tblDrvAclRule_t *rule);

int32 rtl8651a_delAclRuleExt(uint32 sessionID,int8 *ifName, int8 Ingress, rtl8651_tblDrvAclRule_t *rule);



int32 rtl8651a_flushAclRule(uint32 SessionID,int8 *ifName, int8 Ingress);

int32 rtl8651a_setDefaultAcl(uint32 SessionID,int8 *ifName, int8 defAction);




int32 rtl8651_addPppoeSession(uint32 SessionID, uint16 vid);
int32 rtl8651_delPppoeSession(uint32 SessionID);

int32 rtl8651_setPppoeSessionProperty(uint32 SessionID, uint16 sid, ether_addr_t * macAddr, uint32 port);


int32 rtl8651_resetPppoeSessionProperty(uint32 SessionID);
int32 rtl8651_getPppoeSessionMac(uint32 SessionID, ether_addr_t * macAddr);
int32 rtl8651_bindPppoeSession(ipaddr_t ipaddr, uint32 SessionID);
int32 rtl8651_setPppoeSessionHangUp(uint32 SessionID, int32 enable, uint32 sec, int32 (*p_callBack)(uint32));

uint32 * rtl8651_getNextPppoeSession(uint32 * curSessionId, uint32 *retSessionId);
int32 rtl8651_getPppoeCounter(uint32 curSessionId, rtl865x_tblDrv_basicCounterParam_t * counter);
int32 rtl8651_setPppoeSessionHangUp(uint32 SessionID, int32 enable, uint32 sec, int32 (*p_callBack)(uint32)) ;
int32 rtl8651_setPppoeDefaultSessionId(uint32 SessionID);
int32 rtl8651_addDemandRoute(rtl8651_tblDrvDemandRoute_t * rtAdd, int identity,int32(*p_callBack)(uint32));
uint32 _rtl8651_getDemandRoutingEntry(uint32 ip_s,uint32 ip_d,uint8 proto,uint16 ip_dp);
int32 rtl8651_flushDemandRoute(int identity);
int32 _rtl8651_softIcmpPolicyRoute(ipaddr_t sip, uint16 sID, ipaddr_t dip, ipaddr_t *gip, uint16 *gID);




int32 _rtl8651_softNaptPolicyRoute(int type, ipaddr_t ip_s, ipaddr_t ip_d,uint16 ip_dp,
                                int *ip_alias, uint16 *ip_aliasp);
int32 rtl8651_flushPolicyRoute(uint32 ip);
int32 rtl8651_addPolicyRoute(rtl8651_tblDrvPolicyRoute_t *rtAdd);






int32 rtl8651_addNetworkIntf(int8 *ifName);

int32 rtl8651_delNetworkIntf(int8 *ifName);

int32 rtl8651_setNetIfAclMismatchDrop(int8 *ifName, int8 isDrop);
int32 rtl8651_addExtNetworkInterface(int8 * ifName);

int32 rtl8651_delExtNetworkInterface(int8 * ifName);



int32 rtl8651_addDmzNetworkInterface(int8 *ifName);
int32 rtl8651_delDmzNetworkInterface(int8 *ifName);
int32 rtl8651_specifyNetworkIntfLinkLayerType(int8 * ifName, uint32 llType, uint16 vid);
int32 rtl8651_removeNetworkIntfLinkLayerType(int8 * ifName);


int32 rtl8651_addIpIntf(int8 * ifName, ipaddr_t ipAddr, ipaddr_t ipMask);
int32 rtl8651_delIpIntf(int8 * ifName, ipaddr_t ipAddr, ipaddr_t ipMask);


int32 rtl8651_addArp(ipaddr_t ipAddr, ether_addr_t * macAddr, int8 * ifName, uint32 port);
int32 rtl8651_delArp(ipaddr_t ipAddr);
int32 rtl8651_setArpAgingTime(uint16 agTime);


int32 rtl8651_addNatMapping(ipaddr_t extIpAddr, ipaddr_t intIpAddr);
int32 rtl8651_delNatMapping(ipaddr_t extIpAddr, ipaddr_t intIpAddr);


int32 rtl8651_addLocalServer(ipaddr_t ipAddr);
int32 rtl8651_delLocalServer(ipaddr_t ipAddr);


int32 rtl8651_addRoute(ipaddr_t ipAddr, ipaddr_t ipMask, int8 * ifName, ipaddr_t nextHop);
int32 rtl8651_delRoute(ipaddr_t ipAddr, ipaddr_t ipMask);


int32 rtl8651_addNaptMapping(ipaddr_t extIpAddr);
int32 rtl8651_delNaptMapping(ipaddr_t extIpAddr);
int32 rtl8651_setNaptIcmpTimeout(uint32 timeout);
int32 rtl8651_setNaptIcmpFastTimeout(uint32 timeout);
int32 rtl8651_setNaptUdpTimeout(uint32 timeout);
int32 rtl8651_setNaptTcpLongTimeout(uint32 timeout);
int32 rtl8651_setNaptTcpMediumTimeout(uint32 timeout);
int32 rtl8651_setNaptTcpFastTimeout(uint32 timeout);
int32 rtl8651_setNaptTcpUdpPortRange(uint16 start, uint16 end);
int32 rtl8651_is4WayHashEnable(uint8 *isEnable);
int32 rtl8651_enable4WayHash(uint8 isEnable);





int32 rtl8651a_addNaptServerPortMapping(uint32 SessionID,int8 isTcp, ipaddr_t extIpAddr, uint16 extPort, ipaddr_t intIpAddr, uint16 intPort);

int32 rtl8651a_delNaptServerPortMapping(uint32 SessionID,int8 isTcp, ipaddr_t extIpAddr, uint16 extPort, ipaddr_t intIpAddr, uint16 intPort);

int32 rtl8651a_addNaptServerPortRange(uint32 SessionID,int8 isTcp, ipaddr_t extIp, uint16 extPort, ipaddr_t intIp, uint16 intPort, uint16 nCount);

int32 rtl8651a_delNaptServerPortRange(uint32 SessionID,int8 isTcp, ipaddr_t extIp, uint16 extPort, ipaddr_t intIp, uint16 intPort, uint16 nCount);

int32 rtl8651_flushNaptServerPortbyExtIp(ipaddr_t extIp);



int32 rtl8651_flushAllNaptConnections(void);
int32 rtl8651_addNaptConnection(int16 assigned, int8 flowType, ipaddr_t insideLocalIpAddr, uint16 insideLocalPort,
                        ipaddr_t *insideGlobalIpAddr, uint16 *insideGlobalPort, ipaddr_t dstIpAddr, uint16 dstPort);
# 690 "rtl8651_tblDrv.h"
int32 rtl8651_delNaptConnection(int8 isTcp, ipaddr_t insideLocalIpAddr,
                        uint16 insideLocalPort, ipaddr_t dstIpAddr, uint16 dstPort);
void rtl8651_updateAsicNaptTable(void);
int32 rtl8651_addNaptIcmpFlow(int8 assigned, ipaddr_t insideLocalIpAddr, uint16 insideLocalId,
                        ipaddr_t *insideGlobalIpAddr, uint16 *insideGlobalId, ipaddr_t dstIpAddr);
int32 rtl8651_delNaptIcmpFlow(ipaddr_t insideLocalIpAddr, uint16 insideLocalId, ipaddr_t dstIpAddr);
void rtl8651_updateAsicIcmpTable(void);
struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s;
void _rtl8651_refillOrClearAsicNaptEntry(uint32 tblIdx,struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s * selectedRefillFlow);



int32 rtl8651_addALGRule(uint16 startPort, uint16 endPort, int8 isTcp, int8 isServer, int8 isClient);
int32 rtl8651_delALGRule(uint16 startPort, uint16 endPort, int8 isTcp, int8 isServer, int8 isClient);
# 715 "rtl8651_tblDrv.h"
typedef void (*rtl8651_tblDrv_urlFiltering_CallBackFunc_t)(uint32 sessionId, struct rtl_pktHdr *pkt, struct ip *iphdr, const char *urlFiltered, const char *pathFiltered);

typedef struct rtl8651_tblDrv_urlFilter_s {
        int8 *urlFilterString;
        int32 urlFilterStrLen;
        uint8 urlExactlyMatch;
        int8 *pathFilterString;
        int32 pathFilterStrLen;
        uint8 pathExactlyMatch;
        uint32 sessionId;

        uint8 ruleType:1;

} rtl8651_tblDrv_urlFilter_t;

typedef struct rtl8651_tblDrv_urlPktFilter_s {
        uint32 rule_type;

        ipaddr_t sip_start;
        ipaddr_t sip_end;

        ether_addr_t smac;

} rtl8651_tblDrv_urlPktFilter_t;

int32 rtl8651a_delURLfilterString(uint32 SessionID,int8 *string, int32 strlen);

int32 rtl8651a_delURLExactlyfilterString(uint32 SessionID,int8 *string, int32 strlen);

int32 rtl8651a_addURLfilterString(uint32 SessionID,int8 *string, int32 strlen);

int32 rtl8651a_addURLExactlyfilterString(uint32 SessionID,int8 *string, int32 strlen);

int32 rtl8651_addURLFilterRule(uint32 sessionId, int8 *string, int32 strlen, ipaddr_t ip_start, ipaddr_t ip_end);
int32 rtl8651_addURLExactlyFilterRule(uint32 sessionId, int8 *string, int32 strlen, ipaddr_t ip_start, ipaddr_t ip_end);
int32 rtl8651_delURLFilterRule(uint32 sessionId, int8 *string, int32 strlen, ipaddr_t ip_start, ipaddr_t ip_end);
int32 rtl8651_delURLExactlyFilterRule(uint32 sessionId, int8 *string, int32 strlen, ipaddr_t ip_start, ipaddr_t ip_end);
int32 rtl8651_addGenericURLFilterRule(rtl8651_tblDrv_urlFilter_t *urlFilter, rtl8651_tblDrv_urlPktFilter_t *pktFilter);
int32 rtl8651_delGenericURLFilterRule(rtl8651_tblDrv_urlFilter_t *urlFilter, rtl8651_tblDrv_urlPktFilter_t *pktFilter);
int32 rtl8651_registerURLFilterCallBackFunction(rtl8651_tblDrv_urlFiltering_CallBackFunc_t callBackFunc);

int32 rtl8651_urlUnknownTypeCaseSensitive(int8 enable);



int rtl8651_addUrlFilterTrustedUser(uint32 ipaddr);
void rtl8651_flushUrlFilterTrustedUser(void);
# 855 "rtl8651_tblDrv.h"
typedef struct rtl8651_logInfo_s {
        uint32 infoType;

        union {
                struct urlLogInfo {
                        uint32 dsid;
                        uint8 protocol;
                        uint8 direction;
                        ipaddr_t sip;
                        ipaddr_t dip;
                        uint16 sport;
                        uint16 dport;
                        char * string;

                        char * pathString;
                        char * urlFilterString;
                        char * pathFilterString;

                } url;
                struct packetLogInfo {
                        uint32 dsid;
                        uint8 protocol;
                        uint8 direction;
                        ipaddr_t sip;
                        ipaddr_t dip;
                        uint16 sport;
                        uint16 dport;
                        uint8 icmpType;
                        uint16 icmpId;
                } pkt;
        }un;
# 910 "rtl8651_tblDrv.h"
        uint32 action;
} rtl8651_logInfo_t;
# 930 "rtl8651_tblDrv.h"
typedef int32 (*rtl8651_loggingFuncPtr_t)
(
        uint32 moduleId,
        uint32 logNo,
        rtl8651_logInfo_t* info
);


int32 rtl8651_installLoggingFunction(void * pMyLoggingFunc);
int32 rtl8651a_enableLogging(uint32 SessionID,uint32 moduleId,int8 enable);

extern rtl8651_loggingFuncPtr_t _pUserLoggingFunc;



int32 rtl8651_tblDrvReset(void);
int32 rtl8651_tblDrvReinit(void);

int32 rtl8651_tblDrvInit(rtl8651_tblDrvInitPara_t * configPara);

int32 rtl8651_getPppoeSessionSourceMac(uint32 SessionID, ether_addr_t * macAddr);
ipaddr_t _rtl8651_getNaptInsideGlobalIpAddr(int8 isTcp, ipaddr_t insideLocalIpAddr, uint16 insideLocalPortOrId, ipaddr_t dstIpAddr, uint16 dstPort);



int32 rtl8651a_addDmzHost(uint32 SessionID,ipaddr_t naptIp, ipaddr_t dmzHostIp);

int32 rtl8651a_delDmzHost(uint32 SessionID,ipaddr_t naptIp);



int32 rtl8651_addIpUnnumbered(int8 *wanIfName, int8 *lanIfName, ipaddr_t netMask);
int32 rtl8651_delIpUnnumbered(int8 *wanIfName, int8 *lanIfName);
int32 rtl8651_getIpUnnumbered(int8 *wanIfName, int8 *ifName, ipaddr_t *netMask);
int32 rtl8651_setLanSideExternalIpInterface(int8 * ifName, ipaddr_t ipAddr, ipaddr_t ipMask, int8 isExternal);


int32 rtl8651_setFlowControl(uint32 port, int8 enable);
int32 rtl8651_setQueueScheduling(uint32 type, uint32 weight);
int32 rtl8651_setPortPriorityQueue(uint32 port, int8 highPriority);
int32 rtl8651_setDiffServDSCP(uint32 dscp, int8 highPriority);
int32 rtl8651_getMNQueueEntry(rtl8651_tblDrvAclRule_t *rule,uint32 GroupId,uint32 index);


int8 rtl8651_EnablePppoePassthru( int8 enable );
int8 rtl8651_enableDropUnknownPppoePADT( int8 enable );
int32 rtl8651_getPppoePassthruVid(void);
int32 rtl8651_getExternalInterfaceforPPPoEPassthru(void);


int8 rtl8651_EnableIpv6Passthru(int8 enable);
int32 rtl8651_getIpv6PassthruVid(void);
int32 rtl8651_getExternalInterfaceforIPv6Passthru(void);


int8 rtl8651_EnableIpxPassthru(int8 enable);
int32 rtl8651_getIpxPassthruVid(void);
int32 rtl8651_getExternalInterfaceforIPXPassthru(void);


int8 rtl8651_EnableNetbiosPassthru(int8 enable);
int32 rtl8651_getNetbiosPassthruVid(void);
int32 rtl8651_getExternalInterfaceforNetbiosPassthru(void);


int32 rtl8651_transformPasstheuVlanId( uint32 oldVlanIdx, uint32* newVlanIdx );

void rtl8651_setMtu(uint16 mtu);
int32 rtl8651_setNetMtu(int8 *ifName, uint16 mtu);
void rtl8651_getMtu(uint16 * mtu);

uint8 rtl8651_EnableProtocolBasedNAT( uint8 enable );
int32 rtl8651_addProtocolBasedNAT( uint8 protocol, ipaddr_t ExtIp, ipaddr_t IntIp );
int32 rtl8651_delProtocolBasedNAT( uint8 protocol, ipaddr_t ExtIp, ipaddr_t IntIp );

int32 rtl8651_enableMacAccessControl(int8 enable);
int32 rtl8651_setMacAccessControlDefaultPermit(int8 isPermit);
int32 rtl8651_delMacAccessControl(ether_addr_t *sMac, ether_addr_t *macMask);
int32 rtl8651_flushMacAccessControl(void);
int32 rtl8651_addMacAccessControl(ether_addr_t *sMac, ether_addr_t *macMask, int8 isPermit);



int32 rtl8651_addExternalMulticastPort(uint32 extMPort);
int32 rtl8651_delExternalMulticastPort(uint32 extMPort);

int32 rtl8651_autoCrossOverDetect(uint32 isEnable);
int32 rtl8651_portAutoCrossOverDetect(uint32 port, uint32 isEnable);
int32 rtl8651_setMdiMdix(uint32 isMdi);
int32 rtl8651_setPortMdiMdix(uint32 port, uint32 isMdi);




extern int8 rtl8651_tblDrv_Id[];
extern int8 rtl8651_tblDrvFwd_Id[];
# 1109 "rtl8651_tblDrv.h"
typedef struct rtl8651_PS_Action_Entry_s {
        ipaddr_t dstIp;
        ipaddr_t lowerIp;
        ipaddr_t upperIp;
        uint16 orgPort;
        uint16 orgPortEnd;
        uint16 fwdPort;
        uint8 protocol;
        uint8 action;
        uint8 role;
} rtl8651_PS_Action_Entry_t;

extern int32 wlan_acc_debug;



extern uint8 rtl8651_gPPPoEExternalVlanIndex;
extern ether_addr_t rtl8651_gPPPoEExternalGatewayMAC;
extern uint16 rtl8651_gPPPoEPassthruVlanID;




uint32 _rtl8651_setPPPoEPassthruTimeout( uint32 timeout );
int32 rtl8651_addPPPoEPassthru( uint16 sid, ether_addr_t* clientMac, ether_addr_t* serverMac,
                                uint16 clientVid, uint16 serverVid );
int32 rtl8651_getPPPoEPassthru( uint16 sid, ether_addr_t* clientMac, ether_addr_t* serverMac,
                                uint16 *clientVid, uint16 *serverVid, int32 updateTouch );
int32 rtl8651_delPPPoEPassthru( uint16 sid );

extern uint32 gPPPoEPassthruTimeout;




extern uint8 rtl8651_gIPv6ExternalVlanIndex;
extern ether_addr_t rtl8651_gIPv6ExternalGatewayMAC;
extern uint16 rtl8651_gIPv6PassthruVlanID;
extern uint32 rtl8651_pbv_ipv6passthru;





extern uint8 rtl8651_gIPXExternalVlanIndex;
extern ether_addr_t rtl8651_gIPXExternalGatewayMAC;
extern uint16 rtl8651_gIPXPassthruVlanID;
extern uint32 rtl8651_pbv_ipxpassthru;





extern uint8 rtl8651_gNetbiosExternalVlanIndex;
extern ether_addr_t rtl8651_gNetbiosExternalGatewayMAC;
extern uint16 rtl8651_gNetbiosPassthruVlanID;
extern uint32 rtl8651_pbv_netbiospassthru;




extern int8 rtl8651_drvProtocolBasedNatEnable;
# 1187 "rtl8651_tblDrv.h"
typedef struct rtl8651_sessionHangUp_s {
        int32 enable;
        uint32 sessionID;
        uint32 idleTimeout_sec;
        int32 (*idleTimeout_callBack)(uint32);
} rtl8651_sessionHangUp_t;

int32 rtl8651_setSessionHangUp(rtl8651_sessionHangUp_t *param);
# 28 "rtl8651_tblDrvLocal.h" 2



# 1 "rtl8651_aclLocal.h" 1
# 34 "rtl8651_aclLocal.h"
typedef struct rtl8651_tblDrv_aclAsicArrangementEntry_s {
        uint16 vidOrNum;
        uint16 inOrOut;
        int32 identy;
} rtl8651_tblDrv_aclAsicArrangementEntry_t;



typedef struct _rtl8651_tblDrvAclRule_s {
        union {

                struct {
                        ether_addr_t _dstMac, _dstMacMask;
                        ether_addr_t _srcMac, _srcMacMask;
                        uint16 _typeLen, _typeLenMask;
                } MAC;

                struct {
                        uint8 _gidxSel;
                } IFSEL;

                struct {
                        ipaddr_t _srcIpAddr, _srcIpAddrMask;
                        ipaddr_t _dstIpAddr, _dstIpAddrMask;
                        uint8 _tos, _tosMask;
                        union {

                                struct {
                                        uint8 _proto, _protoMask, _flagMask;

                                        uint32 _FOP:1, _FOM:1, _httpFilter:1, _httpFilterM:1, _identSrcDstIp:1, _identSrcDstIpM:1;

                                        union {
                                                uint8 _flag;
                                                struct {
                                                        uint8 pend1:5,
                                                                 pend2:1,
                                                                 _DF:1,
                                                                 _MF:1;
                                                } s;
                                        } un;
                                } ip;

                                struct {
                                        uint8 _type, _typeMask, _code, _codeMask;
                                } icmp;

                                struct {
                                        uint8 _type, _typeMask;
                                } igmp;

                                struct {
                                        ether_addr_t _l2srcMac, _l2srcMacMask;
                                        uint8 _flagMask;
                                        uint16 _srcPortUpperBound, _srcPortLowerBound;
                                        uint16 _dstPortUpperBound, _dstPortLowerBound;
                                        union {
                                                uint8 _flag;
                                                struct {
                                                        uint8 _pend:2,
                                                                  _urg:1,
                                                                  _ack:1,
                                                                  _psh:1,
                                                                  _rst:1,
                                                                  _syn:1,
                                                                  _fin:1;
                                                }s;
                                        }un;
                                }tcp;

                                struct {
                                        ether_addr_t _l2srcMac, _l2srcMacMask;
                                        uint16 _srcPortUpperBound, _srcPortLowerBound;
                                        uint16 _dstPortUpperBound, _dstPortLowerBound;
                                }udp;
                        }is;
                }L3L4;


                struct {
                        ether_addr_t _srcMac, _srcMacMask;
                        uint16 _srcPort, _srcPortMask;
                        uint16 _srcVlanIdx, _srcVlanIdxMask;
                        ipaddr_t _srcIpAddr, _srcIpAddrMask;
                        uint16 _srcPortUpperBound, _srcPortLowerBound;
                        uint32 _ignoreL3L4:1,
                                         _ignoreL4:1;
                } SRCFILTER;

                struct {
                        ether_addr_t _dstMac, _dstMacMask;
                        uint16 _vlanIdx, _vlanIdxMask;
                        ipaddr_t _dstIpAddr, _dstIpAddrMask;
                        uint16 _dstPortUpperBound, _dstPortLowerBound;
                        uint32 _ignoreL4:1,
                                   _ignoreL3L4:1;
                } DSTFILTER;

        }un_ty;
        uint32 ruleType_:4;
        uint32 actionType_:4;

        uint32 pktOpApp:3;

        uint32 isEgressRateLimitRule_:1;
        uint32 matchType_;

        uint32 dsid;
        uint32 dvid_:3;
        uint32 priority_:1;
        uint32 nextHop_:10;
        uint32 pppoeIdx_:3;
        uint32 isIPRange_:1;
        uint32 isRateLimitCounter_:1;

        uint16 nhIndex;
        uint16 rlIndex;


        uint32 aclIdx;
        struct { struct _rtl8651_tblDrvAclRule_s *tqe_next; struct _rtl8651_tblDrvAclRule_s **tqe_prev; } nextRule;
} _rtl8651_tblDrvAclRule_t;
# 185 "rtl8651_aclLocal.h"
void _rtl8651_arrangeAllACL(void);
# 32 "rtl8651_tblDrvLocal.h" 2
# 1 "rtl8651_layer2local.h" 1
# 21 "rtl8651_layer2local.h"
typedef struct rtl8651_tblAsic_ethernet_s {
        uint8 linkUp:1;
} rtl8651_tblAsic_ethernet_t;
# 35 "rtl8651_layer2local.h"
typedef struct rtl8651_tblDrv_ethernet_s {
        uint32 speed:2,
                        duplex:1,
                        autoNegotiation:1,
                        fake_forceMode:1,
                        autoAdvCapability:3,
                        inputBandwidthControl:4,
                        outputBandwidthControl:4,
                        linkUp:1;
        uint16 aggregatorIndex;
} rtl8651_tblDrv_ethernet_t;

typedef struct rtl8651_tblDrv_linkAggregation_s {
        uint16 pvid;
        uint16 individual:1,
                        aggregated:1;
        uint32 ethernetPortMask;
        uint32 ethernetPortUpStatus;
} rtl8651_tblDrv_linkAggregation_t;
# 64 "rtl8651_layer2local.h"
typedef struct rtl8651_tblDrv_filterDbTableEntry_s {
        ether_addr_t macAddr;
        uint16 l2type;
        uint16 process:2,

                        refCount:8,
                        configToAsic:1,
                        asicPos:2;
        uint16 vid;
        uint32 linkId;




        uint32 memberPortMask;
        struct { struct rtl8651_tblDrv_filterDbTableEntry_s *sle_next; } nextFDB;
} rtl8651_tblDrv_filterDbTableEntry_t;
# 91 "rtl8651_layer2local.h"
typedef struct rtl8651_tblDrv_filterDbTable_s {
        uint16 sid;
        uint32 valid:1;
        struct { struct rtl8651_tblDrv_filterDbTableEntry_s *slh_first; } database[256];
} rtl8651_tblDrv_filterDbTable_t;

typedef struct rtl8651_tblDrv_spanningTreeTable_s {
        uint32 protocolWorking:1,
                        valid:1;

        int8 portState[9];
} rtl8651_tblDrv_spanningTreeTable_t;


typedef struct rtl8651_tblDrv_macAddressEntry_s {
        ether_addr_t mac;
        uint16 vid;
        uint32 valid:1,
                        allocated:1;
} rtl8651_tblDrv_macAddressEntry_t;



struct rtl8651_tblDrv_networkIntfTable_s;
typedef struct rtl8651_tblDrv_vlanTable_s {
        ether_addr_t macAddr;
        uint32 memberPortMask;
        uint32 memberPortUpStatus;
        uint32 untagPortMask;
        uint16 macAddrNumber;
        uint16 vid;
        uint16 fid;
        uint32 inAclStart, inAclEnd, outAclStart, outAclEnd;
        uint16 mtu;
        uint16 internal:1,
                        ipAttached:1,
                        manualAssign:1,
                        promiscuous:1,
                        fwdTxMirror:1,
                        DMZflag:1,
                        valid:1,
                        softRoute:1,
                        broadcastToCpu:1;
        struct rtl8651_tblDrv_vlanTable_s *fvlan_t;



        struct rtl8651_tblDrv_networkIntfTable_s *netif_t;

} rtl8651_tblDrv_vlanTable_t;
# 156 "rtl8651_layer2local.h"
extern uint32 peripheralExtPortMask;
# 190 "rtl8651_layer2local.h"
typedef struct rtl8651_tblDrv_miiTunneling_s {
        uint32 valid;
        uint16 wanPort;
        uint16 wanVid;
        uint16 loopbackPort;
        uint16 loopBackVid;
} rtl8651_tblDrv_miiTunneling_t;

int32 rtl8651_setAsicAclRule(uint32 index, _rtl8651_tblDrvAclRule_t *rule);
int32 rtl8651_getAsicAclRule(uint32 index, _rtl8651_tblDrvAclRule_t *rule);
extern rtl8651_tblDrv_miiTunneling_t tunnel;
# 33 "rtl8651_tblDrvLocal.h" 2
# 1 "rtl8651_layer3local.h" 1
# 21 "rtl8651_layer3local.h"
struct rtl8651_tblDrv_ipUnnumbered_s;
# 52 "rtl8651_layer3local.h"
typedef struct rtl8651_tblDrv_ipIntfIpAddrEntry_s {
        ipaddr_t ipAddr;
        struct { struct rtl8651_tblDrv_ipIntfIpAddrEntry_s *sle_next; } nextIpAddr;
}rtl8651_tblDrv_ipIntfIpAddrEntry_t;
# 66 "rtl8651_layer3local.h"
struct rtl8651_tblDrvSession_s;

typedef struct rtl8651_tblDrv_pppTable_s {
        struct rtl8651_tblDrv_networkIntfTable_s *netif_t;
        struct rtl8651_tblDrvSession_s *session_t;
        uint32 sessionId;
        uint32 mss;
        uint16 vid;
        uint16 type:5,
                        valid:1,
                        initiated:1;
        rtl8651_tblDrv_filterDbTableEntry_t * macInfo;
        uint8 dsid;
        uint32 txPackets, txBytes;
        uint32 rxPackets, rxBytes, rxErrors;
        uint32 drops;
        union {
                struct {
                        uint16 pppoeSessionId__;
                } pppoe;
                struct {
                        uint16 callId__;
                        uint16 peerCallId__;
                        uint32 lastSeq__;
                        uint32 lastAck__;
                        uint32 delta__;
                        uint32 lastReceiveSeq__;
                        ipaddr_t serverIp__;
                        ipaddr_t defaultGwIp__;
                        uint8* greBuf1__;
                        uint8* greBuf2__;
                        uint8 greOffset2__;
                } pptp;
                struct {
                        uint16 tunnelId__;
                        uint16 l2tpSessionId__;
                        ipaddr_t serverIp__;
                        ipaddr_t defaultGwIp__;
                        uint8* l2tpBuf1__;
                        uint8 l2tpLengthBit__;
                        uint8 l2tpOffset__;
                        uint8 l2tpBuf1State__;
                        uint8* l2tpBuf2__;
                        uint8 l2tpOffset2__;
                } l2tp;
        } un;
} rtl8651_tblDrv_pppTable_t;
# 137 "rtl8651_layer3local.h"
typedef struct rtl8651_tblDrvSession_s {
        rtl8651_tblDrv_pppTable_t *session_t;
        rtl8651_tblDrv_ipIntfIpAddrEntry_t *ip_t;
        struct { struct rtl8651_tblDrvSession_s *tqe_next; struct rtl8651_tblDrvSession_s **tqe_prev; } nextSession;
} rtl8651_tblDrvSession_t;





typedef struct rtl8651_tblDrv_arpEntry_s {
        ipaddr_t ipAddr;
        rtl8651_tblDrv_filterDbTableEntry_t * macInfo;
        uint32 routingTablePos;
        uint16 vid;
        uint32
                        fromDrv:1,
                        fromApp:1,
                        dmzIpPending:1,
                        isBcArp:1,
                        routeAllocated:1;
        uint32 age;
        struct { struct rtl8651_tblDrv_arpEntry_s *sle_next; } next;
} rtl8651_tblDrv_arpEntry_t;


typedef struct rtl8651_tblDrv_ipIntfEntry_s {
        ipaddr_t ipMask;
        uint32 arpAllocated:1,
                        routeAllocated:1,
                        lanSideExternal:1,
                        networkType:3;
        uint32 arpStartPos, arpEndPos;
        uint32 routingTablePos;
        struct rtl8651_tblDrv_ipUnnumbered_s *ipUnnumber;
        struct { struct rtl8651_tblDrv_ipIntfIpAddrEntry_s *slh_first; } ipAddr;
        struct { struct rtl8651_tblDrv_ipIntfIpAddrEntry_s *slh_first; } localServer;
        struct { struct rtl8651_tblDrv_ipIntfEntry_s *sle_next; } nextIp;
        struct { struct rtl8651_tblDrv_arpEntry_s *slh_first; } nextArp;
} rtl8651_tblDrv_ipIntfEntry_t;

typedef struct rtl8651_tblDrv_natEntry_s {
        ipaddr_t localIp;
        ipaddr_t globalIp;
        struct { struct rtl8651_tblDrv_natEntry_s *sle_next; } nextNatEntry;
} rtl8651_tblDrv_natEntry_t;




struct rtl8651_tblDrv_ipEntry_s;
typedef struct rtl8651_tblDrv_nextHopEntry_s {
        uint16 dvid;
        uint16 nextHopType:3,
                        rt_flag:1,
                        valid:1,
                        v:1;
        uint32 refcount;
        uint32 entryIndex;
        ipaddr_t nexthop;
        void *nexthop_t;
        struct rtl8651_tblDrv_ipEntry_s *ip_t;
        struct { struct rtl8651_tblDrv_nextHopEntry_s *sle_next; } next;
} rtl8651_tblDrv_nextHopEntry_t;
# 222 "rtl8651_layer3local.h"
typedef struct rtl8651_ipUnnumbered_ctrlBlock_s {
        uint32 ip_unnumber_LS_budget;
        uint32 ip_unnumber_ACL_budget;
} rtl8651_ipUnnumbered_ctrlBlock_t;


typedef struct rtl8651_tblDrv_ipUnnumbered_s {
        ipaddr_t ipAddr;
        ipaddr_t ipMask;

        uint32 ip_as_LS;
        uint8 ip_as_ACL_budget;
        rtl8651_tblDrv_ipIntfEntry_t *ipIntf_t;
        struct { struct rtl8651_tblDrv_ipUnnumbered_s *sle_next; } nextIpUnnumberEntry;
} rtl8651_tblDrv_ipUnnumbered_t;
# 249 "rtl8651_layer3local.h"
typedef struct rtl8651_tblDrv_ipEntry_s {
        ipaddr_t intip;
        ipaddr_t extip;
        uint32 type:2,
                                def_flag:1,
                                valid:1;
        uint32 ref_cnt;
        struct rtl8651_tblDrv_nextHopEntry_s *nextHop_t;
} rtl8651_tblDrv_ipEntry_t;
# 278 "rtl8651_layer3local.h"
struct rtl8651_tblDrv_rateLimit_s;
typedef struct rtl8651_tblDrv_networkIntfTable_s {
        int8 ifName[16];
        uint16 vid;
        uint32 valid:1,
                        flag:1,



                        linkLayerType:3;
        uint32 pppoeAge;
        uint16 mtu;
        int8 defAclAction;
        ipaddr_t netMask;
        struct { struct rtl8651_tblDrv_ipIntfEntry_s *slh_first; } IpHead;
        struct { struct rtl8651_tblDrv_natEntry_s *slh_first; } nextNat;
        struct { struct rtl8651_tblDrv_naptServerPortEntry_s *slh_first; } nextNaptServerPort;
        struct { struct rtl8651_tblDrvSession_s *tqh_first; struct rtl8651_tblDrvSession_s **tqh_last; int tqh_count;} sessionHead;
        struct { struct _rtl8651_tblDrvAclRule_s *tqh_first; struct _rtl8651_tblDrvAclRule_s **tqh_last; int tqh_count;} inAclHead;
        struct { struct _rtl8651_tblDrvAclRule_s *tqh_first; struct _rtl8651_tblDrvAclRule_s **tqh_last; int tqh_count;} outAclHead;
        struct { struct _rtl8651_tblDrvPolicy_s *tqh_first; struct _rtl8651_tblDrvPolicy_s **tqh_last; int tqh_count;} policyQosHead;
        struct { struct _rtl8651_tblDrvAclRule_s *tqh_first; struct _rtl8651_tblDrvAclRule_s **tqh_last; int tqh_count;} inRateLimitHead;
        struct { struct _rtl8651_tblDrvAclRule_s *tqh_first; struct _rtl8651_tblDrvAclRule_s **tqh_last; int tqh_count;} outRateLimitHead;
        struct { struct _rtl8651_tblDrvAclRule_s *tqh_first; struct _rtl8651_tblDrvAclRule_s **tqh_last; int tqh_count;} mnqHead;
} rtl8651_tblDrv_networkIntfTable_t;
# 311 "rtl8651_layer3local.h"
struct rtl8651_tblDrv_policyRoute_s;
typedef struct rtl8651_tblDrv_routeTable_s {
        ipaddr_t ipAddr;
        ipaddr_t ipMask;
        ipaddr_t nextHop;
        uint32 process:4,
                                ifrt_flag:1,
                                nextHopType:5,
                                ipClass:1,
                                valid:1;
        uint16 dvid;
        rtl8651_tblDrv_ipIntfEntry_t *ipintf_t;
        rtl8651_tblDrv_networkIntfTable_t *netif_t;


        union {
                struct {
                        uint32 arpsta;
                        uint32 arpend;
                } arp;
                struct {
                        union {
                                struct {
                                        rtl8651_tblDrv_arpEntry_t *arp_t;
                                } direct;
                                struct {
                                        rtl8651_tblDrv_pppTable_t *session_t;
                                } session;
                        } un1;
                        rtl8651_tblDrv_nextHopEntry_t *start_t;
                        rtl8651_tblDrv_nextHopEntry_t *end_t;
                        rtl8651_tblDrv_nextHopEntry_t *next_t;
                        uint8 nhalog;
                        uint8 ipDomain;
                } nxthop;
                struct {
                        struct rtl8651_tblDrv_policyRoute_s *policy_t;
                } policy;
        } un;
        rtl8651_tblDrv_nextHopEntry_t *rt_nexthop_t;
} rtl8651_tblDrv_routeTable_t;
# 406 "rtl8651_layer3local.h"
typedef struct ipClassABMonitorTable_s {
        ipaddr_t dip;
        uint32 value;
        rtl8651_tblDrv_arpEntry_t *arp_t;
} ipClassABMonitorTable_t;
# 421 "rtl8651_layer3local.h"
typedef struct rtl8651_tblDrv_arpAsicArrangementEntry_s {
        int16 valid;
} rtl8651_tblDrv_arpAsicArrangementEntry_t;
# 435 "rtl8651_layer3local.h"
typedef struct _rtl8651_tblDrvPolicy_s {
        uint32 proto;
        ipaddr_t sip, sipMask,
                                dip, dipMask;
        uint16 sport_start, sport_end,
                                dport_start, dport_end;
        ipaddr_t naptip;


        rtl8651_tblDrv_nextHopEntry_t *nexthop_t;
        rtl8651_tblDrv_pppTable_t *pppoe_t;
        int32 (*p_handler)(uint32);

        struct { struct _rtl8651_tblDrvPolicy_s *cqe_next; struct _rtl8651_tblDrvPolicy_s *cqe_prev; } nextTime_t;
        struct { struct _rtl8651_tblDrvPolicy_s *tqe_next; struct _rtl8651_tblDrvPolicy_s **tqe_prev; } nextPolicy_t;
} _rtl8651_tblDrvPolicy_t;

typedef struct _rtl8651_tblDrvDynamicPolicy_s {
        _rtl8651_tblDrvPolicy_t *policy_t;
        struct { struct _rtl8651_tblDrvPolicy_s *tqh_first; struct _rtl8651_tblDrvPolicy_s **tqh_last; } *hashTable;
        struct { struct _rtl8651_tblDrvPolicy_s *cqh_first; struct _rtl8651_tblDrvPolicy_s *cqh_last; } dyHead;
} _rtl8651_tblDrvDynamicPolicy_t;





int32 _rtl8651_addPolicyRoute(rtl8651_tblDrvPolicyRoute_t *rtAdd, uint32 dynamicPolicyRtAge);
# 475 "rtl8651_layer3local.h"
typedef struct rtl8651_tblDrv_mCast_s {
        ipaddr_t sip;
        ipaddr_t dip;
        uint16 svid;
        uint16 port;
        uint32 mbr;
        uint16 age;
        uint16 cpu;
        rtl8651_tblDrv_ipEntry_t *ipEntry_t;
        uint32 vlanMask;
        uint32 count;
        uint32 flag;
        uint32 inAsic;
        struct { struct rtl8651_tblDrv_mCast_s *tqe_next; struct rtl8651_tblDrv_mCast_s **tqe_prev; } nextMCast;
} rtl8651_tblDrv_mCast_t;






typedef struct rtl8651_tblDrv_macACEntry_s {
        ether_addr_t mac;
        ether_addr_t macMask;
        uint32 actionType;
        struct { struct rtl8651_tblDrv_macACEntry_s *tqe_next; struct rtl8651_tblDrv_macACEntry_s **tqe_prev; } nextMAC;
} rtl8651_tblDrv_macACEntry_t;


typedef struct rtl8651_tblDrv_macContrl_s {
        uint16 def_permit;
        uint16 enable;
        struct { struct rtl8651_tblDrv_macACEntry_s *tqh_first; struct rtl8651_tblDrv_macACEntry_s **tqh_last; int tqh_count;} macAccessControl;
} rtl8651_tblDrv_macContrl_t;
# 519 "rtl8651_layer3local.h"
typedef struct rtl8651_tblDrv_rateLimit_s {




        uint32 maxToken;
        uint32 rateMappedToken;



        uint32 lastConfigToken;
        uint32 sliceIncrementToken;
        uint32 accumulatedToken;
        uint32 vRate;
        int32 eagerCounter;

        uint32 isByteCount;
        uint32 addToken;
        uint32 interval;

        uint32 groupId;
        uint8 queueType;
        uint8 dscp;
        uint8 mark;
        uint8 nQueueNeedProcess;
        uint32 ref_count;
        uint32 ratio;
        rtl8651_tblDrv_networkIntfTable_t *netif_t;
} rtl8651_tblDrv_rateLimit_t;
# 561 "rtl8651_layer3local.h"
typedef struct rtl8651_tblDrv_rateLimitCounter_s {
        uint8 valid;
        uint8 counterType;
        uint32 rateLimitIndex;
        rtl8651_tblDrv_networkIntfTable_t *netif_t;
} rtl8651_tblDrv_rateLimitCounter_t;






typedef struct rtl8651_tblDrv_mnqueue_sys_s {
        uint32 wanBandwidth;
        uint32 mVRate, mEVRate, nVRate;
        uint32 nAvailableRate;
        uint32 eagerNQueueNumber, nQueueNumber;
} rtl8651_tblDrv_mnqueue_sys_t;



rtl8651_tblDrv_networkIntfTable_t *GET_NETWORK_INTERFACE(int8 *ifname, uint32 *ifIdx);





typedef struct rtl8651_tblDrv_protocolBasedNat_s
{
        uint8 protocol;
        ipaddr_t ExtIp;
        ipaddr_t IntIp;

        struct { struct rtl8651_tblDrv_protocolBasedNat_s *sle_next; } next;
} rtl8651_tblDrv_protocolBasedNat_t;
# 34 "rtl8651_tblDrvLocal.h" 2
# 1 "rtl8651_layer4local.h" 1
# 21 "rtl8651_layer4local.h"
struct ip;
struct rtl_pktHdr;





typedef struct rtl8651_tblDrv_global_s {
        uint32 icmpTimeout;
        uint32 icmpFastTimeout;
        uint32 udpTimeout;
        uint32 tcpLongTimeout;
        uint32 tcpMediumTimeout;
        uint32 tcpFastTimeout;
        uint32 tcpFinTimeout;
        uint16 l4PortRangeStart, l4PortRangeEnd;
        uint16 l4NaptFindEmptyAsicRetry;
} rtl8651_tblDrv_global_t;

typedef struct rtl8651_tblDrv_naptServerPortEntry_s {
        ipaddr_t localIp;
        ipaddr_t globalIp;
        uint16 localPort, globalPort;
        uint16 endLocalPort, endGlobalPort;
        uint32 asicTablePos;
        uint32 tcp:1,
                        udp:1,
                        toAsic:1;
        struct { struct rtl8651_tblDrv_naptServerPortEntry_s *sle_next; } nextServerPort;
} rtl8651_tblDrv_naptServerPortEntry_t;



typedef struct rtl8651DmzHostStruct_s {





        ipaddr_t naptIp[6];
        ipaddr_t dmzHost[6];
} rtl8651DmzHostStruct_t;


typedef int32 (*alg_funcptr_t)(struct rtl_pktHdr * , struct ip*, struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s *);
typedef struct rtl8651_tblDrv_algEntry_s {
        uint16 startPort, endPort;
        uint32 tcpServer:1,
                        tcpClient:1,
                        udpServer:1,
                        udpClient:1,

                        toAsic:1,

                        fwEngAdd:1;



        alg_funcptr_t alg_outboundClientcb;
        alg_funcptr_t alg_outboundServercb;
        alg_funcptr_t alg_inboundClientcb;
        alg_funcptr_t alg_inboundServercb;


        struct { struct rtl8651_tblDrv_algEntry_s *sle_next; } nextAlgEntry;
} rtl8651_tblDrv_algEntry_t;



struct l4ack_data_record
{
        uint32 ack_old;
        uint32 ack_new;
        int32 delta;
        int32 active;
};
# 113 "rtl8651_layer4local.h"
typedef struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s {
        ipaddr_t insideLocalIpAddr;
        ipaddr_t insideGlobalIpAddr;
        ipaddr_t dstIpAddr;
        uint16 insideLocalPort;
        uint16 insideGlobalPort;
        uint16 dstPort;

        uint16 alive:1;
        uint16 tcp:1;
        uint16 hashing:2;
        uint16 tcpFlag:3;
        uint16 quiet:1;
        uint16 fromDrv:1;

        uint16 col1:1;
        uint16 col2:1;
        uint16 isStatic:1;
        uint16 asicSnapshot:1;



        uint16 pureSoftware:1;
        uint16 interfaceRoute:1;
        uint16 newlyAddedHash2Udp:1;
        uint16 holdForCdrouter:1;

        uint16 urlFiltered:1;

        uint16 connectionType:2;
        uint16 toProtocolStack:1;
        uint16 dosEnCount:1;
        uint16 dosFromInternal:1;




        uint32 age;
        int16 outboundTblIdx;
        int16 inboundTblIdx;
        uint32 pps;
        uint16 createTimeStamp;
        uint8 outListType:4;
        uint8 inListType:4;
        uint16 selEIdx;

        int8 inExtIpIdx;
        int8 outExtIpIdx;


        uint8 tcpStateINdex:4;
        uint8 tcpAckModified:1;
        uint8 tcpFtpLastLineCRLFTermed:1;
        uint8 natlink:1;
        uint8 h245tunnel:1;

        int32 (*alg_client_in)(struct rtl_pktHdr *, struct ip *,struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s *);
        int32 (*alg_client_out)(struct rtl_pktHdr *, struct ip *,struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s *);
        int32 (*alg_server_in)(struct rtl_pktHdr *, struct ip *,struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s *);
        int32 (*alg_server_out)(struct rtl_pktHdr *, struct ip *,struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s *);

        struct l4ack_data_record ack[2];



        void *out_rt_t;
        void *in_rt_t;
        void *out_macInfo_t;
        void *in_macInfo_t;
        uint8 dsid;


        struct { struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s *sle_next; } nextOut;
        struct { struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s *sle_next; } nextIn;
        struct { struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s *tqe_next; struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s **tqe_prev; } next;
} rtl8651_tblDrv_naptTcpUdpFlowEntry_t;
# 215 "rtl8651_layer4local.h"
struct naptEntryListHead {
        struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s *slh_first;
};


typedef struct rtl8651DrvNaptLine_s {
        uint8 forcedCollision1:1;
        uint8 forcedCollision2:1;
        struct naptEntryListHead list[8];
} rtl8651DrvNaptLine_t;
# 234 "rtl8651_layer4local.h"
typedef struct rtl8651_tblDrv_naptIcmpFlowEntry_s {
        ipaddr_t insideLocalIpAddr;
        ipaddr_t insideGlobalIpAddr;
        ipaddr_t dstIpAddr;
        uint16 insideLocalId;
        uint16 insideGlobalId;
        uint32 age;
        uint16 count;


        uint32 staticEntry:1,
                        protoDel:1,
                        alive:1,
                        toAsic:1,
                        fromAsic:1,
                        fromDrv:1,
                        canAsic:1;


        uint8 dsid;



        struct rtl8651_tblDrv_naptIcmpFlowEntry_s * next;
} rtl8651_tblDrv_naptIcmpFlowEntry_t;

typedef struct rtl8651_tblDrv_serverPortAsicArrangementEntry_s {
        uint16 valid:1;
        rtl8651_tblDrv_naptServerPortEntry_t *servPort_t;
} rtl8651_tblDrv_serverPortAsicArrangementEntry_t;

typedef struct rtl8651_tblDrv_algAsicArrangementEntry_s {
        uint16 port;
        uint16 valid:1;
} rtl8651_tblDrv_algAsicArrangementEntry_t;
# 277 "rtl8651_layer4local.h"
typedef struct urlPktFiltering_s {

        uint32 rule_type;


        ipaddr_t sip_start;
        ipaddr_t sip_end;


        ether_addr_t smac;


        struct { struct urlPktFiltering_s *sle_next; } nextUse;
        struct { struct urlPktFiltering_s *sle_next; } next;
} urlPktFiltering_t;

typedef void (*urlFiltering_CallBackFunc_t)(uint32 sessionId, struct rtl_pktHdr *pkt, struct ip *iphdr, const char *urlFiltered, const char *pathFiltered);


typedef struct urlFiltering_s {

        int32 urlFilterCount;
        uint16 urlHdrJmpTbl[256];
        uint16 urlHostJmpTbl[256];
        uint16 urlGetJmpTbl[256];
        uint16 urlGet1JmpTbl[256];
        uint16 urlhttpJmpTbl[256];
        uint16 pathGetJmpTbl[256];

        int8 **urlFilterDB;
        int8 **pathFilterDB;
        uint16 **urlFilterJmpTbl;
        uint16 **pathFilterJmpTbl;
        int32 *urlFilterStrLen;
        int32 *pathFilterStrLen;
        uint32 *sessionId;
        uint8 *urlExactlyMatch;
        uint8 *pathExactlyMatch;
        int8 urlString[128];

        int8 log_pathString[128];
        int8 log_urlFilterString[128];
        int8 log_pathFilterString[128];



        uint8 *ruleType;


        urlFiltering_CallBackFunc_t callBackFunc;

        struct { struct urlPktFiltering_s *slh_first; } pktFilter[256];
} urlFiltering_t;


typedef struct _rtl8651_sessionHangUp_s {
        uint32 last_received;
        uint32 last_transmit;
        uint32 idletime_limit;




        int32 (*p_callBack)(uint32);





        uint32 sessionID;


} _rtl8651_sessionHangUp_t;
# 35 "rtl8651_tblDrvLocal.h" 2
# 44 "rtl8651_tblDrvLocal.h"
struct rtl8651_driverTables {


        rtl8651_tblDrv_ethernet_t *phyPort;
        rtl8651_tblDrv_linkAggregation_t *aggregator;
        rtl8651_tblDrv_filterDbTable_t *filterDB;
        rtl8651_tblDrv_spanningTreeTable_t *spanningTree;

        rtl8651_tblDrv_vlanTable_t *vlan;



        rtl8651_tblDrv_networkIntfTable_t *netIface;
        rtl8651_tblDrv_routeTable_t *route;
        rtl8651_tblDrv_ipEntry_t *iptbl;

        rtl8651_tblDrv_naptIcmpFlowEntry_t **icmp;
        rtl8651DrvNaptLine_t * tcpudp;

        _rtl8651_tblDrvDynamicPolicy_t dynamicPolicy;
        rtl8651_tblDrv_pppTable_t *pppoe;
        rtl8651_tblDrv_pppTable_t *pptp;
        rtl8651_tblDrv_pppTable_t *l2tp;

        rtl8651_tblDrv_macContrl_t *macACInfo;
        rtl8651_tblDrv_rateLimit_t *rateLimit;
        rtl8651_tblDrv_nextHopEntry_t *nhtbl;



        struct freeEntryList_s {

                struct _FreeFDBEntry { struct rtl8651_tblDrv_filterDbTableEntry_s *slh_first; } filterDBentry;
                struct _FreeAclEntry_t { struct _rtl8651_tblDrvAclRule_s *tqh_first; struct _rtl8651_tblDrvAclRule_s **tqh_last; int tqh_count;} aclRule;
                struct _FreeMACAccessEntry { struct rtl8651_tblDrv_macACEntry_s *tqh_first; struct rtl8651_tblDrv_macACEntry_s **tqh_last; int tqh_count;} freeMacAccessControl;
                struct _FreeArpEntry { struct rtl8651_tblDrv_arpEntry_s *slh_first; int slh_count;} arp;
                struct _FreeIpIfaceEntry { struct rtl8651_tblDrv_ipIntfEntry_s *slh_first; } ipIface;
                struct _FreeIpAddrEntry { struct rtl8651_tblDrv_ipIntfIpAddrEntry_s *slh_first; } ipAddr;
                struct _FreeNatEntry { struct rtl8651_tblDrv_natEntry_s *slh_first; } natMapping;

                struct _FreeAlgEntry { struct rtl8651_tblDrv_algEntry_s *slh_first; } alg;
                struct _FreeAlgSlot { struct rtl8651_tblDrv_algSlot_t *slh_first; int slh_count;} asicAlgSlot;
                struct _FreeServerPortEntry { struct rtl8651_tblDrv_naptServerPortEntry_s *slh_first; } serverPort;
                rtl8651_tblDrv_naptIcmpFlowEntry_t *icmp;
                struct _FreeNaptEntry { struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s *tqh_first; struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s **tqh_last; int tqh_count;} tcpudp;

                struct _FreeSessionEntry { struct rtl8651_tblDrvSession_s *tqh_first; struct rtl8651_tblDrvSession_s **tqh_last; } freeSession;

                struct _FreePolicyEntry { struct _rtl8651_tblDrvPolicy_s *tqh_first; struct _rtl8651_tblDrvPolicy_s **tqh_last; } freePolicy;
                struct _FreeMultiCastEntry { struct rtl8651_tblDrv_mCast_s *tqh_first; struct rtl8651_tblDrv_mCast_s **tqh_last; } freeMultiCast;

                struct _FreeProtocolBasedNat { struct rtl8651_tblDrv_protocolBasedNat_s *slh_first; } protocolBasedNat;
                struct _FreeNextHopEntry { struct rtl8651_tblDrv_nextHopEntry_s *slh_first; } nexthop;

                struct _FreeIpUnnumberEntry { struct rtl8651_tblDrv_ipUnnumbered_s *slh_first; } freeIpUnnumber;

                struct _FreeUrlPktFilterEntry { struct urlPktFiltering_s *slh_first; } freeUrlPktFilter;
        } freeList;

        struct inuseEntryList_s {
                struct _InuseAlgEntry { struct rtl8651_tblDrv_algEntry_s *slh_first; } alg;
                struct _InuseNaptEntry { struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s *tqh_first; struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s **tqh_last; int tqh_count;} tcpudp;


                struct _InusePolicyEntry { struct _rtl8651_tblDrvPolicy_s *tqh_first; struct _rtl8651_tblDrvPolicy_s **tqh_last; } policyRoute;


                struct _InuseMCast { struct rtl8651_tblDrv_mCast_s *tqh_first; struct rtl8651_tblDrv_mCast_s **tqh_last; } *mCastTbl;
                struct _InuseProtocolBasedNat { struct rtl8651_tblDrv_protocolBasedNat_s *slh_first; } protocolBasedNat;
                struct _InuseNextHopEntry { struct rtl8651_tblDrv_nextHopEntry_s *slh_first; } nexthop;

                struct _InuseIpUnnumberEntry { struct rtl8651_tblDrv_ipUnnumbered_s *slh_first; } ipUnnumber;

                struct _InuseUrlPktFilterEntry { struct urlPktFiltering_s *slh_first; } urlPktFilter;
        } inuseList;

};

struct AsicTableUsage_S{
        rtl8651_tblDrv_macAddressEntry_t * mac;

        rtl8651_tblDrv_arpAsicArrangementEntry_t * arp;

        rtl8651_tblDrv_serverPortAsicArrangementEntry_t *serverPort;
        rtl8651_tblDrv_algAsicArrangementEntry_t *alg;


};






extern rtl8651_tblDrv_global_t rtl8651GlobalControl;
extern void (*rtl8651_linkStatusNotifier)(uint32 port, int8 linkUp);
extern struct AsicTableUsage_S AsicTableUsage;
extern uint32 linkChangePendingCount;
extern int32 miiPhyAddress;
extern rtl8651_tblAsic_ethernet_t rtl8651AsicEthernetTable[9];
extern rtl8651_tblDrvInitPara_t rtl8651_tblDrvPara;
extern uint32 arpAgingTime;
extern struct rtl8651_driverTables DrvTbl;
extern uint32 *_loggingModule;
extern int8 pureSoftFwd;
extern void (* rtl8651_tblDrvFwdSend)(void * data);
extern ether_addr_t cachedDA;
extern uint32 phyPortLinkStatus;
extern struct rtl8651_driverTables DrvTbl;
extern uint32 _sysUpSeconds;

extern int32 (*p_mtuHandler)(struct rtl_pktHdr *);
extern int32 rtl8651_mss;
extern uint16 pppoe_mss[];

extern int32 _urlFilterAclRuleNum;

extern uint32 rtl8651_externalMulticastPortMask;


extern uint32 rtl8651_tblDrvSpanningTreeEnable;
extern uint32 rtl8651_tblDrvSpanningTreePortFwdStatus;


extern _rtl8651_sessionHangUp_t rtl8651_sessionHangUp[2];


extern urlFiltering_t _urlFilter;
# 212 "rtl8651_tblDrvLocal.h"
int32 _rtl8651_findUrlFiltering(rtl8651_tblDrv_urlFilter_t *urlFilter);

int32 rtl8651_fwdEngineL2Input(struct rtl_pktHdr *pkthdrPtr,rtl8651_tblDrv_vlanTable_t *local_vlanp, uint8 *m_data, uint16 ethtype);
int32 _rtl8651_delVlanRefFilterDatabaseEntry(uint16 l2Type, uint16 fid, ether_addr_t * macAddr);
int8 * _strncpy(int8 *dst0, const int8 *src0, int32 count);
int32 _strncmp(const int8 *s1, const int8 *s2, int32 n);


rtl8651_tblDrv_ipEntry_t *_rtl8651_getIPTableEntry(ipaddr_t extip, ipaddr_t intip, uint8 attr);
rtl8651_tblDrv_arpEntry_t * _rtl8651_getArpEntry(rtl8651_tblDrv_networkIntfTable_t *netif_t, ipaddr_t ipAddr, int8 isRefresh);
rtl8651_tblDrv_networkIntfTable_t * _rtl8651_getNetworkIntfEntryByAddr(ipaddr_t ipAddr);
rtl8651_tblDrv_networkIntfTable_t * _rtl8651_getNetworkIntfEntryByVid(uint16 vid);
rtl8651_tblDrv_ipIntfEntry_t * _rtl8651_getIpIntfEntryByAddr(ipaddr_t ipAddr);
int32 _rtl8651_addLocalArp(int8 fromDrv, ipaddr_t ipAddr, ether_addr_t * macAddr, rtl8651_tblDrv_networkIntfTable_t *netIfPtr, uint32 port);
int8 _rtl8651_addLocalArpSpecifyNetworkInterface(int8 fromDrv, ipaddr_t ipAddr, ether_addr_t * macAddr, rtl8651_tblDrv_networkIntfTable_t * netIntfPtr, uint32 port);
int8 _rtl8651_getNetworkIntfLinkLayerType(int8 *ifName, uint32 *llType, uint32 *llIndex);
int8 _rtl8651_extIpAddr(ipaddr_t ipAddr, uint32 *netIdx);
int8 _rtl8651_extNetIpAddr(ipaddr_t ipAddr, uint32 *netIdx);
int8 _rtl8651_localServerIpAddr(ipaddr_t ipAddr);
int8 _rtl8651_intIpAddr(ipaddr_t ipAddr);
int8 _rtl8651_intNetIpAddr(ipaddr_t ipAddr);
int8 _rtl8651_isInternal(uint16 vid);
int32 _rtl8651_queryProtoTrap(uint8 protoType, uint16 protoContent);
int8 _rtl8651_getUsableExtIpAndPort(int8 , ipaddr_t , uint16 , ipaddr_t , uint16 , ipaddr_t *, uint16 *);
int8 _rtl8651_getIcmpUsableExtIpAndID(ipaddr_t sip, uint16 sID, ipaddr_t dip, ipaddr_t *gip, uint16 *gID);
int8 _rtl8651_getAllNatMapping(int32 *entry, rtl8651_tblDrv_natEntry_t *natMap);
int8 _rtl8651_getAllServerPort(int32 *entry, rtl8651_tblDrv_naptServerPortEntry_t *serverPort);
int8 _rtl8651_getUsableExtIpAndPort(int8 isTcp, ipaddr_t sip, uint16 sport, ipaddr_t dip, uint16 dport, ipaddr_t *extip, uint16 *extport);
int8 _rtl8651_getVIDByGWIpAddr(ipaddr_t gwIpAddr, uint32 *vid);
rtl8651_tblDrv_naptTcpUdpFlowEntry_t * _rtl8651_addNaptAlgConnection(int8 force, int8 flowType, ipaddr_t insideLocalIpAddr, uint16 insideLocalPort,
                ipaddr_t *insideGlobalIpAddr, uint16 *insideGlobalPort, ipaddr_t dstIpAddr, uint16 dstPort);
int32 _rtl8651_addNaptConnection(int8 fromDrv, int16 assigned, int8 flowType, ipaddr_t insideLocalIpAddr, uint16 insideLocalPort,
                        ipaddr_t *insideGlobalIpAddr, uint16 *insideGlobalPort, ipaddr_t dstIpAddr, uint16 dstPort);
inline int32 _rtl8651_addAndGetNaptConnection(int8 fromDrv, int16 assigned, int8 flowType, ipaddr_t insideLocalIpAddr, uint16 insideLocalPort,
                        ipaddr_t *insideGlobalIpAddr, uint16 *insideGlobalPort, ipaddr_t dstIpAddr, uint16 dstPort,
                        struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s **ppe );
inline int32 _rtl8651_delNaptConnection( rtl8651_tblDrv_naptTcpUdpFlowEntry_t *delConn);
int32 _rtl8651_removeNaptConnectionByIP( ipaddr_t ip );
int32 _rtl8651_countNaptConnectionByIP( ipaddr_t ip, uint32 *tcpCnt, uint32 *udpCnt );
rtl8651_tblDrv_naptTcpUdpFlowEntry_t * _rtl8651_findNaptConnectionByExtIpPort( int8 isTcp, ipaddr_t ExtIp, uint16 ExtPort,
                                        ipaddr_t remoteIp, uint16 remotePort );
rtl8651_tblDrv_naptTcpUdpFlowEntry_t * _rtl8651_findNaptConnection( uint32 tblIndex, int8 isTcp, ipaddr_t intIp, uint16 intPort,
                                                          ipaddr_t remoteIp, uint16 remotePort );
int8 _rtl8651_addNaptIcmpCandidateFlow(int8 fromDrv, ipaddr_t insideLocalIpAddr, uint16 insideLocalId,
                        ipaddr_t insideGlobalIpAddr, uint16 insideGlobalId, ipaddr_t dstIpAddr);






        rtl8651_tblDrv_natEntry_t * _rtl8651_getNatExternalMappingEntry(ipaddr_t extIpAddr,struct rtl_pktHdr *phdr);
        rtl8651_tblDrv_natEntry_t * _rtl8651_getNatInternalMappingEntry(ipaddr_t intIpAddr,struct rtl_pktHdr *phdr);


rtl8651_tblDrv_naptServerPortEntry_t * _rtl8651_getOutsideNaptServerPortMapping(int8 isTcp, ipaddr_t extIpAddr, uint16 extPort);
rtl8651_tblDrv_naptServerPortEntry_t * _rtl8651_getInsideNaptServerPortMapping(int8 isTcp, ipaddr_t intIpAddr, uint16 intPort);
rtl8651_tblDrv_algEntry_t *_rtl8651_getAlgEntry(int8 isTcp, int8 *isServer, int8 *isClient, uint16 sport, uint16 eport);
rtl8651_tblDrv_routeTable_t * _rtl8651_getRoutingEntry(ipaddr_t dstIpAddr);
rtl8651_tblDrv_routeTable_t * _rtl8651_getSoftRoutingEntry(uint32,uint32,uint8,int);
int32 _rtl8651_getOutboundNaptFlow(int8 isTcp, ipaddr_t sip, uint16 sport, ipaddr_t dip, uint16 dport, struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s **ppEntry);
int32 _rtl8651_getInboundNaptFlow(int8 isTcp, ipaddr_t gip, uint16 gport, ipaddr_t dip, uint16 dport, struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s **ppEntry);
rtl8651_tblDrv_naptIcmpFlowEntry_t * _rtl8651_getInsideNaptIcmpEntry(ipaddr_t sip, uint16 sID, ipaddr_t dip, int8 isRefresh, int8 needFastFin);
rtl8651_tblDrv_naptIcmpFlowEntry_t * _rtl8651_getOutsideNaptIcmpEntry(ipaddr_t gip, uint16 gID, ipaddr_t dip, int8 isRefresh, int8 needFastFin);
void _rtl8651_collideNaptEntry(rtl8651DrvNaptLine_t *line,int32 *c1, int32 *c2);
_rtl8651_tblDrvAclRule_t * _rtl8651_aclLookUp(uint32 dsid,rtl8651_tblDrv_networkIntfTable_t *, int8 , uint32, int8 *, int8 *, int8 *, uint32, uint32);
int32 _rtl8651_getDefaultAcl(int8 *ifName, int8 *defAction);
rtl8651_tblDrv_pppTable_t *_rtl8651_getPppoeSessionByIpAddr(ipaddr_t ipaddr);
rtl8651_tblDrv_pppTable_t * _rtl8651_getPppoeSessionByPppoeSessionId(uint16 pppoeSessionId);
rtl8651_tblDrv_pppTable_t *_rtl8651_getPppoeSessionByDsid(uint32 dsid);
int32 _rtl8651_getDmzHost(uint32 dsid,ipaddr_t naptIp, ipaddr_t *dmzHostIp);
int32 _rtl8651_fromDmzHost(uint32 dsid, ipaddr_t dmzHostIp, ipaddr_t *naptIp);
int32 _rtl8651_isLocalBcastAddr(uint32 vid, ipaddr_t ipAddr);
int32 _rtl8651_enableDoS(uint32 dostype, int8 enable, uint32 vlanMask);
uint32 _rtl8651_SessionIDToDSID(uint32 SessionID);
int32 _rtl8651_urlFilter(uint32 dsid,struct rtl_pktHdr * phdr,struct ip * pip,uint8 dir, int8 * string,int32 * strlen);
 void _rtl8651_refillOrClearAsicNaptEntry(uint32 tblIdx,struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s * selectedRefillFlow);
 int32 _rtl8651_addVlanRefFilterDatabaseEntry(uint16 l2Type, uint16 fid, uint16 vid, ether_addr_t * macAddr, uint32 type, uint32 portMask);
 int32 _rtl8651_modifyVlanRefFilterDatabaseEntry(uint32 fid, ether_addr_t *mac, uint32 *memberPortMask, uint16 *process, uint32 *linkId, uint32 attr);
int32 _rtl8651_addVlanRefFilterDatabaseEntry(uint16 l2Type, uint16 fid, uint16 vid, ether_addr_t * macAddr, uint32 type, uint32 portMask) ;
 rtl8651_tblDrv_filterDbTableEntry_t * _rtl8651_getVlanFilterDatabaseEntry(uint16 vid, ether_addr_t * macAddr);
void _rtl8651_removeArpAndNaptFlowWhenLinkDown(int32 port, uint32 *linkId) ;
void _rtl8651_removeArpByL2Entry(rtl8651_tblDrv_filterDbTableEntry_t *l2entry_t);


int32 _rtl8651_delVlanRefFilterDatabaseEntry(uint16 l2Type, uint16 fid, ether_addr_t * macAddr);

rtl8651_tblDrv_algEntry_t*_rtl8651_l4FindLinkAlg(uint16 , uint16 );

int32 _rtl8651_updateNaptConnection(struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s *, int8 , uint32 );
int32 _rtl8651_getOutboundAlgConnection(int8 , ipaddr_t , uint16 , ipaddr_t , uint16 , struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s **);

int32 _rtl8651_getPppoeTblPtr(uint32 pppoeId,rtl8651_tblDrv_pppTable_t ** pppoePtr_P);
void _rtl8651_naptTimerAdaptiveAdjust(int8 enabled, uint32 threshold, uint32 secPassed);
void _rtl8651_naptSmartFlowSwapByPPS(int8 enabled, uint32 threshold);
int32 _rtl8651_isMacAccessControlPermit(ether_addr_t *sMac);


int32 _rtl8651_setLanSideExternalIpInterface(rtl8651_tblDrv_networkIntfTable_t *netif_t, ipaddr_t ipAddr, ipaddr_t ipMask, int8 isExternal);
void _rtl8651_reArrangeLanSideExternalIpInterfacePatch(void);


void _rtl8651_arrangeMulticastPortStatus(void);

void _rtl8651_arrangeAllMulticast(void);
# 345 "rtl8651_tblDrvLocal.h"
extern uint32 _rtl8651_DefaultDialSessionId;






int32 _rtl8651_removeNaptConnectionByIntIPandPort( int8 isTcp, ipaddr_t intIp, uint16 intPort );


extern uint32 tuRemind;
extern uint32 accJiffies;
extern uint32 timer1Sec;
# 371 "rtl8651_tblDrvLocal.h"
typedef int32 (*acldb_callback_t) (int32 , struct rtl_pktHdr *, struct ip *, void *);

struct rtl8651_ACLDB_s
{
        acldb_callback_t func;
        void *userDefined;
        uint32 count;
};
typedef struct rtl8651_ACLDB_s rtl8651_ACLDB_t;

extern rtl8651_ACLDB_t acldb[];

int32 _rtl8651_resetACLDB(void);
int32 _rtl8651_registerACLDB( int32 ruleNo,
                              acldb_callback_t func,
                              void *userDefined );
int32 _rtl8651_jumptoACLDB( int32 ruleNo, struct rtl_pktHdr *pkthdr, struct ip *pip );




int32 _rtl8651_addRateLimitCounter(rtl8651_tblDrv_networkIntfTable_t *netif_t, uint8 counterType);
int32 _rtl8651_delRateLimitCounter(rtl8651_tblDrv_networkIntfTable_t *netif_t, uint8 counterType);
int32 _rtl8651_getRateLimitCounter(rtl8651_tblDrv_networkIntfTable_t *netif_t, uint8 counterType, uint8 refill);
int32 _rtl8651_addRateLimitCounterRule(rtl8651_tblDrvAclRule_t *rule, rtl8651_tblDrv_networkIntfTable_t *netif_t, uint8 counterType);
int32 _rtl8651_delRateLimitCounterRule(rtl8651_tblDrvAclRule_t *rule, rtl8651_tblDrv_networkIntfTable_t *netif_t, uint8 counterType);
void _rtl8651_rateLimitCounterTimeUpdate(uint32 secpassed);
void _rtl8651_flushRateLimitCounter(void);

int32 _rtl8651_changeNaptIpAndPort( struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s * thisFlow,
                                    ipaddr_t newIntIp, uint16 newIntPort,
                                    ipaddr_t newExtIp, uint16 newExtPort,
                                    ipaddr_t newRemIp, uint16 newRemPort
                                    );


rtl8651_tblDrv_networkIntfTable_t *_rtl8651_getIpInfo(ipaddr_t ipaddr, rtl8651_tblDrv_ipIntfEntry_t **ipintf_t, int8 *is_gip, int8 *is_gwip);


void _rtl8651_recordTraffic(int32 dsid, int32 isXmit);
int32 _rtl8651_setSessionHangUp(rtl8651_sessionHangUp_t *param);
# 27 "rtl8651_multicast_local.h" 2
# 1 "rtl8651_multicast.h" 1
# 17 "rtl8651_multicast.h"
struct ip;
struct igmp;
# 58 "rtl8651_multicast.h"
typedef struct rtl8651_tblDrvMCastPara_s {
        uint32 MCastMember_ExpireTime;
        uint32 MCastUpstream_Timeout;
        uint32 igmp_qi;
        uint32 igmp_qri;
        uint32 igmp_oqpi;
        uint32 igmp_sqc;
        uint32 igmp_sqi;
        uint32 igmp_lmqc;
        uint32 igmp_lmqi;
        uint32 igmp_gmi;
        uint32 igmp_group_query_interval;
        uint32 igmp_response_tolerance_delay;
} rtl8651_tblDrvMCastPara_t;
# 91 "rtl8651_multicast.h"
void MCast_DumpMCast(void);

int32 rtl8651_multicast_AddFilter(ipaddr_t gip, uint32 action);
int32 rtl8651_multicast_RemoveFilter(ipaddr_t gip, uint32 action);



void rtl8651_multicastReinit(void);
void rtl8651_multicast_FilterReinit(void);
int32 rtl8651_multicastSetPara(rtl8651_tblDrvMCastPara_t *);
int32 rtl8651_multicastSetUpStream(int8*, uint32);
int32 rtl8651_multicastPeriodicQuery(int8 enable);
# 28 "rtl8651_multicast_local.h" 2
# 1 "rtl8651_tblDrvFwdLocal.h" 1
# 169 "rtl8651_tblDrvFwdLocal.h"
# 1 "assert.h" 1
# 170 "rtl8651_tblDrvFwdLocal.h" 2
# 180 "rtl8651_tblDrvFwdLocal.h"
# 1 "rtl8651_tblDrvFwd_utility.h" 1
# 181 "rtl8651_tblDrvFwdLocal.h" 2


# 1 "rtl8651_tblDrvFwd.h" 1
# 790 "rtl8651_tblDrvFwd.h"
typedef struct rtl8651_fwdEngineInitPara_s {

        uint32 MaxFragPktCnt;
        uint32 MaxFragSubPktCnt;
        uint32 MaxNegativeListEntryCnt;
        uint32 MaxPositiveListEntryCnt;
        uint32 MaxFragPoolCnt;
        uint32 MaxFragTimeOut;
        uint32 MaxNegativeListTimeOut;

        uint32 MCastDefaultVersion;
        uint32 MCastProcessOption;
        uint32 MaxMCastCnt;
        uint32 MaxMCastMemberCnt;
        uint32 MaxMCastTotalMemberCnt;
        uint32 MaxMCastTotalSourceCnt;
        uint32 MCastMember_ExpireTime;
        uint32 MCastUpstream_Timeout;
        uint32 MCastFilterEntryCnt;
        uint32 igmp_qi;
        uint32 igmp_qri;
        uint32 igmp_oqpi;
        uint32 igmp_sqc;
        uint32 igmp_sqi;
        uint32 igmp_lmqc;
        uint32 igmp_lmqi;
        uint32 igmp_gmi;
        uint32 igmp_group_query_interval;
        uint32 igmp_response_tolerance_delay;


        uint32 dos_SynFlood_trackCnt;
        uint32 dos_StealthFin_trackCnt;
        uint32 dos_UdpFlood_trackCnt;
        uint32 dos_IcmpFlood_trackCnt;
        uint32 dos_total_trackCnt;

        uint32 dos_total_portScan_trackCnt;

        uint32 dos_TcpConn_trackCnt;
        uint32 dos_UdpConn_trackCnt;
        uint32 dos_TcpUdpConn_trackCnt;
        uint32 dos_totalConn_trackCnt;

        uint32 dosProc_sipblock_count;

        uint32 pppoeActiveSessionTrackingNumber;
        uint32 mbufHeadroom;


        uint32 redirectTblSize;
        uint32 redirectFlowCacheSize;


        uint32 pptpHdrCacheSize;


        uint32 protoStackMaxActions;


        uint32 trappingPktDispatchTblSize;


        uint32 dns_dnsDB_processCnt;
        uint32 dns_dnsDB_tblSize;
        uint32 dns_dnsDB_cnameMapTblSize;
        uint32 dns_dnsDB_cnameMapTimeout;

        uint32 domainBlock_tblSize;
        uint32 domainBlock_maxBlockEntryCnt;
        uint32 domainBlock_blockEntryTimeout;



        uint32 triggerPortEntryCnt;
        uint32 triggerPortCacheSize;


} rtl8651_fwdEngineInitPara_t;




int32 rtl8651_fwdEngineInit(struct rtl8651_fwdEngineInitPara_s *);
int32 rtl8651_fwdEngineReinit(void);




int32 rtl8651_fwdEngineInput(void * pkthdr);
int32 rtl8651_fwdEngineExtPortRecv(void *id, uint8 *data, uint32 len, uint16 myvid, uint32 myportmask, uint32 linkId);




int32 rtl8651_fwdEngineDropPktCase(uint32 fwdengDropCase, int32 *flag);
int32 rtl8651_fwdEngineSend(void * pkthdr, int16 dvid, int32 iphdrOffset);
int32 rtl8651_fwdEngineQosSend(void *pkthdr, int16 dvid, int32 iphdrOffset, int32 qualityId);
int32 rtl8651_fwdEngineArp(int8 enable);
int32 rtl8651_fwdEngineIcmp(int8 enable);
int32 rtl8651_fwdEngineIcmpRoutingMsg(int8 enable);
int32 rtl8651_fwdEngineAlwaysReplyICMPErrForFragment(int8 enable);
int32 rtl8651_fwdEngineDMZHostIcmpPassThrough(int8 enable);
int32 rtl8651_fwdEngineArpProxy(int8 enable);
int32 rtl8651_fwdEngineProcessL34(int8 routingEnable);
int32 rtl8651_fwdEngineProcessIPFragment(int8 enable);
int32 rtl8651_fwdEngineProcessIPMulticast(int8 enable);
int32 rtl8651_fwdEnginePppoeNotExistedSessionTermination(int8 enable);
int32 rtl8651_fwdEngineProcessPortBouncing(int8 enable);
int32 rtl8651_fwdEngineProcessUpnpPortBouncing(int8 enable);
int32 rtl8651_fwdEngineEnableWDS(int32 flag);
int32 rtl8651_fwdEngineRemoveHostsOnExtLinkID(uint32 linkID);
int32 rtl8651_fwdEngineEnableWanRouting(int8 enable);
int32 rtl8651_fwdEngineFwdGeneralL4ToDMZ(int8 enable);
int32 rtl8651_fwdEngineFwdUnicastIGMPPkt(int8 enable);
int32 rtl8651_fwdEnginePortBouncingDoProtocolStackAction(int8 enable);
int32 rtl8651_fwdEngineTrapPktDemandRouteTrigger(int8 enable);


int32 rtl8651_fwdEngineInexactUdpFlow(int8 enable);

int32 rtl8651_fwdEngineUdpStaticNaptPortTranslation(int8 enable);
int32 rtl8651_fwdEngineTcpStaticNaptPortTranslation(int8 enable);



int32 rtl8651_fwdEngineWeakTcpNaptProcess(int8 enable);


int32 rtl8651_fwdEnginePsDontTimeout(int enable);
int32 rtl8651_fwdEnginePsToWanErrMsgDontTimeout(int enable);

int32 rtl8651_fwdEngineDynamicRemoteHostPolicyRT(int enable);




typedef int32 (*alg_funcptr)(struct rtl_pktHdr *pkthdr , void *ipheader, void *);
int32 rtl8651_fwdEngineRegisterAlgModule(uint16 , uint16 ,
        int32 (*alg_init)(void *),
        alg_funcptr alg_outboundClientcb,
        alg_funcptr alg_inboundClientcb,
        alg_funcptr alg_outboundServercb,
        alg_funcptr alg_inboundServercb
);
int32 rtl8651_fwdEngineRemoveAlgModule(uint16 , uint16 );


int32 rtl8651_fwdEngineAddWlanSTA(uint8 *smac,uint16 myvid, uint32 myportmask, uint32 linkId);
int32 rtl8651_fwdEngineDelWlanSTA(uint8 *mac,uint16 myvid);
int32 rtl8651_fwdEngineExtPortUcastFastRecv(struct rtl_pktHdr *pkt,uint16 myvid, uint32 myportmask);



typedef struct rtl8651_tblDrvFwdEngineCounts_s {
        uint32 arpReceive, arpAddSuccess, arpAddFail, arpDelete, arpReply, arpGenerate;
        uint32 ipReceive, ipErrorReceive;
        uint32 icmpReceive, icmpErrorReceive, icmpReply, icmpReplyFailed, icmpDrop, icmpSend;
        uint32 igmpReceive, igmpErrorReceive;
        uint32 udpReceive, udpErrorReceive,udpSend;
        uint32 tcpReceive, tcpErrorReceive,tcpSend;
        uint32 l34actionLookupFailed, l34actionFailed;
        uint32 pppoeDiscoveryReceive, pppoeDiscoveryProcessed;
        uint32 pppoeSessionReceive, pppoeSessionProcessed;
        uint32 inAclDrop, inAclPermit,inAclCpu;
        uint32 outAclDrop, outAclPermit, outAclCpu;
        uint32 dmzDrop;
        uint32 natdrop, wlan2lanRelay, lan2wlanRelay;
        uint32 dosDrop;
        uint32 fastFragUdpMeetCount, fastFragUdpMissCount;
} rtl8651_tblDrvFwdEngineCounts_t;
int32 rtl8651_getFwdEngineCounter(rtl8651_tblDrvFwdEngineCounts_t * counter);
# 975 "rtl8651_tblDrvFwd.h"
void rtl8651_addUpnpMap(uint32 ,ipaddr_t , uint16 , ipaddr_t , uint16 , ipaddr_t , uint16 );
void rtl8651_addUpnpMapLeaseTime(uint32, ipaddr_t, uint16, ipaddr_t, uint16, ipaddr_t, uint16,uint32);
void rtl8651_delUpnpMap(uint32 ,ipaddr_t , uint16 , ipaddr_t , uint16 , ipaddr_t , uint16 );
uint32 rtl8651_queryUpnpMapTimeAge(uint32, ipaddr_t, uint16 , ipaddr_t, uint16);







typedef struct _rtl8651_triggerPort_param_s
{
        uint8 isStaticMapping;
        uint32 age;

        union {
                struct {
                        uint8 __outType;
                        ipaddr_t __triggeringInsideLocalIpAddrStart;
                        ipaddr_t __triggeringInsideLocalIpAddrEnd;
                        uint16 __outPortStart;
                        uint16 __outPortEnd;
                } DYNAMIC_MAPPING;
                struct {
                        ipaddr_t __mappedInsideLocalIpAddr;
                        uint8 __isStatic;
                } STATIC_MAPPING;
        } UN_MAPPING;
# 1014 "rtl8651_tblDrvFwd.h"
}_rtl8651_triggerPort_param_t;



void rtl8651a_flushTriggerPortRules(uint32 netIntfId);
void rtl8651_flushTriggerPortRules(void);
int32 rtl8651a_addTriggerPortRule(uint32 netIntfId, uint8 inType, uint16 inPortStart, uint16 inPortEnd, uint8 outType,uint16 outPortStart,uint16 outPortEnd, ipaddr_t localIpAddr);
int32 rtl8651_addTriggerPortRule(uint8 inType, uint16 inPortStart, uint16 inPortEnd, uint8 outType,uint16 outPortStart,uint16 outPortEnd, ipaddr_t localIpAddr);



void rtl8651a_setUdpSizeThreshValue(uint32 dsid, uint32 value);
# 1036 "rtl8651_tblDrvFwd.h"
void rtl8651_flushProtoStackActions(void);
int32 rtl8651_addProtoStackActions(ipaddr_t ip,ipaddr_t mask,uint8 action,uint8 role,uint8 protocol,uint16 orgPort,uint16 fwdPort);
# 1050 "rtl8651_tblDrvFwd.h"
void rtl8651a_setUdpSizeThreshValue(uint32 SessionID, uint32 value);
# 1059 "rtl8651_tblDrvFwd.h"
int32 rtl8651_registerTrappingDispatchEntry(uint8 l4Proto, ipaddr_t srcIp, ipaddr_t dstIp, int32 srcPort, int32 dstPort, uint16 category);
int32 rtl8651_unregisterTrappingDispatchEntry(uint8 l4Proto, ipaddr_t srcIp, ipaddr_t dstIp, int32 srcPort, int32 dstPort);





int32 rtl8651_registerRedirectOutboundNaptFlow(
                uint8 isTcp,
                ipaddr_t sip,
                uint16 sport,
                ipaddr_t originalDip,
                uint16 originalDport,
                ipaddr_t newDip,
                int32 newDport
);
int32 rtl8651_unregisterRedirectOutboundNaptFlow(
                uint8 isTcp,
                ipaddr_t sip,
                uint16 sport,
                ipaddr_t originalDip,
                uint16 originalDport,
                ipaddr_t newDip,
                int32 newDport
);
int32 rtl8651_queryRedirectOutboundNaptFlow(
                uint8 isTcp,
                ipaddr_t sip,
                uint16 sport,
                ipaddr_t *pOriginalDip,
                uint16 *pOriginalDport,
                ipaddr_t newDip,
                uint16 newDport
);
int32 rtl8651_registerRedirectOutboundNaptExceptionList(
                uint8 isTcp,
                ipaddr_t sip,
                uint16 sport,
                ipaddr_t dip,
                uint16 dport
);
int32 rtl8651_unregisterRedirectOutboundNaptExceptionList(
                uint8 isTcp,
                ipaddr_t sip,
                uint16 sport,
                ipaddr_t dip,
                uint16 dport
);





int32 rtl8651_updateCounter1( void );






int32 rtl8651_offloadEngineL3Send(void * pPkt, uint32 L3PktLength, uint32 l34CkumOffload, int32 highPriority);
# 184 "rtl8651_tblDrvFwdLocal.h" 2
# 1 "rtl8651_ipQueue_local.h" 1
# 14 "rtl8651_ipQueue_local.h"
# 1 "rtl8651_tblDrvFwdLocal.h" 1
# 15 "rtl8651_ipQueue_local.h" 2
# 32 "rtl8651_ipQueue_local.h"
int32 _rtl8651_IpFragQueueInit(rtl8651_fwdEngineInitPara_t *para);



inline int32 _rtl8651_frag_NeedFragmentProcess(uint16 id, ipaddr_t sip, ipaddr_t dip, uint8 l4proto);
# 185 "rtl8651_tblDrvFwdLocal.h" 2
# 1 "rtl8651_multicast_local.h" 1
# 186 "rtl8651_tblDrvFwdLocal.h" 2







enum _RTL8651_HOSTTYPE {
        _RTL8651_HOST_NPI = 0,
        _RTL8651_HOST_NI,
        _RTL8651_HOST_LP,
        _RTL8651_HOST_RP,
        _RTL8651_HOST_NPE,
        _RTL8651_HOST_NE,
        _RTL8651_HOST_MAX,
        _RTL8651_HOST_NONE,
};






enum _RTL8651_DECISIONTYPE {
        _RTL8651_DEC_NONE = 0,

        _RTL8651_DEC_RT_LR,
        _RTL8651_DEC_RT_RL,
        _RTL8651_DEC_RT_LNP,
        _RTL8651_DEC_RT_NPL,
        _RTL8651_DEC_RT_LN,
        _RTL8651_DEC_RT_NL,
        _RTL8651_DEC_RT_LL,
        _RTL8651_DEC_RT_NN,
        _RTL8651_DEC_RT_NPNP,
        _RTL8651_DEC_RT_NPN,
        _RTL8651_DEC_RT_NNP,
        _RTL8651_DEC_RT_RR,

        _RTL8651_DEC_NT,
        _RTL8651_DEC_NTR,
        _RTL8651_DEC_NTBC_NP,
        _RTL8651_DEC_NTBC_N,
        _RTL8651_DEC_NTBC_L,
        _RTL8651_DEC_NPT,
        _RTL8651_DEC_NPTR,
        _RTL8651_DEC_NPTBC_NP,
        _RTL8651_DEC_NPTBC_N,
        _RTL8651_DEC_NPTBC_L,

        _RTL8651_DEC_DP,

        _RTL8651_DEC_MAX
};
# 257 "rtl8651_tblDrvFwdLocal.h"
void _rtl8651_fwdEngineTimeUpdate(uint32 secPassed);




int32 _rtl8651_ingressAcl(uint32 dsid,uint32 startIdx, rtl8651_tblDrv_vlanTable_t *pVlan,int32 vid, uint8 *m_data, uint8 *ip, uint32 matchType, uint32 optLayer);
int32 _rtl8651_egressAcl(uint32 dsid,rtl8651_tblDrv_vlanTable_t *pVlan,int32 vid, uint8 *ethHdr, uint8 *ip);
# 273 "rtl8651_tblDrvFwdLocal.h"
int32 rtl8651_fwdEngineL2Input(struct rtl_pktHdr *pkthdrPtr,rtl8651_tblDrv_vlanTable_t *local_vlanp, uint8 *m_data, uint16 ethtype);
int32 _rtl8651_fwdEngineSend(uint32 property, void * data, int16 dvid, int32 iphdrOffset);




int32 _rtl8651_l3FastActRouting(uint32 property, struct rtl_pktHdr *pkthdrPtr, ipaddr_t dst_ip, struct ip *ip, void **);







typedef struct _rtl8651_l34AdditionalExec_s
{
        uint8 property;
} _rtl8651_l34AdditionalExec_t;


int32 _rtl8651_l34AdditionalExec_setParam(uint32 srcType, uint32 dstType, _rtl8651_l34AdditionalExec_t *para);

int32 _rtl8651_l34AdditionalExec_getParam(uint32 srcType, uint32 dstType, _rtl8651_l34AdditionalExec_t *para);
# 311 "rtl8651_tblDrvFwdLocal.h"
typedef struct _rtl8651_FragmentShortestPathFwdCache_s
{

        uint8 status;
        ipaddr_t sip;
        ipaddr_t dip;
        uint16 id;

        uint8 mode;
        ipaddr_t aliasIp;

        struct ether_addr smac;
        struct ether_addr dmac;
        uint16 vlanIdx;
        uint16 portList;
        uint8 extPortList;
        uint8 srcExtPortNum;
        uint16 pppoeIdx;
        uint16 flags;

        uint8 age;
} _rtl8651_FragmentShortestPathFwdCache_t;



inline void _rtl8651_fragmentShortestPathCacheSet_secondHalf(struct rtl_pktHdr *pkthdr, uint8 *m_data, struct ip*pip);
extern _rtl8651_FragmentShortestPathFwdCache_t fragmentShortestPathCache[32];






typedef struct _rtl8651_IcmpPktField_s{
        uint8 ic_type;
        uint8 ic_code;
        union{
                uint16 next_mtu;
        } ic_hun;

} _rtl8651_IcmpPktField_t;
int32 _rtl8651_drvIcmpErrorGeneration(struct rtl_pktHdr *, struct ip*, _rtl8651_IcmpPktField_t *, uint16);





struct _RTL8651_UPNP_ENTRY{
        ipaddr_t remote_ip;
        uint16 remote_port;
        ipaddr_t alias_ip;
        uint16 alias_port;
        ipaddr_t local_ip;
        uint16 local_port;

        uint32 flags;
        uint32 age;
        uint32 algIdx;
};
# 381 "rtl8651_tblDrvFwdLocal.h"
void _rtl8651_addAlgQosUpnpMap(uint32, ipaddr_t, uint16, ipaddr_t, uint16, ipaddr_t, uint16, uint32);
# 394 "rtl8651_tblDrvFwdLocal.h"
struct _rtl8651_triggerPort_cache_s;

typedef struct _rtl8651_triggerPort_entry_s
{
        uint32 netIntfId;

        uint8 inType;
        uint8 outType;
        uint16 inPortStart;
        uint16 inPortEnd;
        uint16 outPortStart;
        uint16 outPortEnd;
        ipaddr_t triggeringInsideLocalIpAddrStart;
        ipaddr_t triggeringInsideLocalIpAddrEnd;





        uint32 cacheAge;



        struct _rtl8651_triggerPort_entry_s **hdr;
        struct _rtl8651_triggerPort_entry_s *next;
        struct _rtl8651_triggerPort_entry_s *prev;


        struct _rtl8651_triggerPort_cache_s *normalCache;
} _rtl8651_triggerPort_entry_t;

typedef struct _rtl8651_triggerPort_cache_s
{
        uint32 netIntfId;
        ipaddr_t localIpAddr;
        ipaddr_t ExternalIpAddr;

        uint8 inType;
        uint16 inPortStart;
        uint16 inPortEnd;
# 450 "rtl8651_tblDrvFwdLocal.h"
        uint8 isStatic;
        uint32 age;
        uint32 maxAge;



        struct _rtl8651_triggerPort_cache_s **hdr;
        struct _rtl8651_triggerPort_cache_s *prev;
        struct _rtl8651_triggerPort_cache_s *next;


        struct _rtl8651_triggerPort_entry_s *entryHdr;
        struct _rtl8651_triggerPort_cache_s *entryList_prev;
        struct _rtl8651_triggerPort_cache_s *entryList_next;


        struct _rtl8651_triggerPort_cache_s *lru_prev;
        struct _rtl8651_triggerPort_cache_s *lru_next;

} _rtl8651_triggerPort_cache_t;
# 479 "rtl8651_tblDrvFwdLocal.h"
struct _RTL8651_PORT_BOUNCING_ENTRY{

        ipaddr_t clientIpAddr;
        ipaddr_t gatewayIpAddr;
        ipaddr_t serverIpAddr;
        uint16 clientPort;
        uint16 gatewayPort;
        uint16 serverPort;
        uint16 id;
        uint16 flowType;
        uint32 tcpFlag;
        uint32 age;
};
# 509 "rtl8651_tblDrvFwdLocal.h"
typedef struct _rtl8651_frag {

        ipaddr_t new_ip;
        int8 routeIdx;
        void *napt_entry_t;
        uint8 dsid;

        uint8 age;

        uint16 ip_id;
        ipaddr_t org_sip;
        ipaddr_t org_dip;
} _rtl8651_frag_t;





typedef struct _rtl8651_pppoeActiveSession_entry_s {
        uint16 sessionId;
        uint16 keepAlive;
        struct _rtl8651_pppoeActiveSession_entry_s * next;
} _rtl8651_pppoeActiveSession_entry_t;
# 545 "rtl8651_tblDrvFwdLocal.h"
extern rtl8651_fwdEngineInitPara_t rtl8651_fwdEnginePara;
# 567 "rtl8651_tblDrvFwdLocal.h"
typedef struct _rtl8651_trapping_dispatch_entry_s
{
        uint8 l4Proto;


        ipaddr_t srcIp;
        ipaddr_t dstIp;


        int32 srcPort;
        int32 dstPort;


        uint16 category;


        struct _rtl8651_trapping_dispatch_entry_s *prev;
        struct _rtl8651_trapping_dispatch_entry_s *next;
} _rtl8651_trapping_dispatch_entry_t;

typedef struct _rtl8651_trapping_dispatch_cache_s
{
        uint8 l4Proto;
        ipaddr_t srcIp;
        ipaddr_t dstIp;
        uint16 srcPort;
        uint16 dstPort;

        _rtl8651_trapping_dispatch_entry_t *ptr;

} _rtl8651_trapping_dispatch_cache_t;
# 610 "rtl8651_tblDrvFwdLocal.h"
struct _RTL8651_QUEUE_PACKET_ENTRY
{
        uint8 q_type;
        uint8 q_time;
        uint16 q_id;
        uint32 q_waitIp;
        struct rtl_pktHdr * q_pkthdrPtr;
        struct ip * q_ip;
};





uint16 _rtl8651_ipChecksum(struct ip * pip);
uint16 _rtl8651_icmpChecksum(struct ip * pip);
uint16 _rtl8651_tcpChecksum(struct ip * pip);
# 699 "rtl8651_tblDrvFwdLocal.h"
struct wan_gre_header {
  uint8 flags;
  uint8 ver;
  uint16 protocol;
  uint16 payload_len;
  uint16 call_id;
  uint32 seq;
  uint32 ack;

};
# 731 "rtl8651_tblDrvFwdLocal.h"
struct wan_l2tp_header {

  uint16 flags_type:1;
  uint16 flags_length:1;
  uint16 flags_rsv1:2;
  uint16 flags_sequence:1;
  uint16 flags_rsv2:1;
  uint16 flags_offset:1;
  uint16 flags_priority:1;
  uint16 flags_rsv3:4;
  uint16 flags_version:4;

  uint16 length;
  uint16 tunnel_id;
  uint16 session_id;
};
# 803 "rtl8651_tblDrvFwdLocal.h"
typedef struct _rtl8651_naptRedirectEntry_s
{
        uint8 isExceptionList;
        uint8 isTcp;
        ipaddr_t sip;
        uint16 sport;
        ipaddr_t dip;
        uint16 dport;
        ipaddr_t newDip;
        int32 newDport;

        struct _rtl8651_naptRedirectEntry_s *next;
} _rtl8651_naptRedirectEntry_t;


typedef struct _rtl8651_naptRedirectFlow_s
{
        uint8 isTcp;
        ipaddr_t sip;
        uint16 sport;
        ipaddr_t dip;
        uint16 dport;
        ipaddr_t newDip;
        uint16 newDport;
        uint32 age;
        uint32 queryCnt;

        struct _rtl8651_naptRedirectFlow_s *next;
} _rtl8651_naptRedirectFlow_t;






typedef struct _rtl8651_pptpHdrCacheEntry_s
{

        uint8 type;
        uint32 seq;
        uint32 ack;

        uint16 id;
        uint16 offset;

        struct _rtl8651_pptpHdrCacheEntry_s **hdr;
        struct _rtl8651_pptpHdrCacheEntry_s *prev;
        struct _rtl8651_pptpHdrCacheEntry_s *next;
        struct _rtl8651_pptpHdrCacheEntry_s *lru_prev;
        struct _rtl8651_pptpHdrCacheEntry_s *lru_next;
} _rtl8651_pptpHdrCacheEntry_t;
# 863 "rtl8651_tblDrvFwdLocal.h"
void _rtl8651_pptpHdrCache_Add(uint16 ip_id, uint16 ip_off, uint32 seq, uint32 ack, uint8 type);




int32 _rtl8651_mtuFragment(uint32 property, struct rtl_pktHdr *pkthdrPtr, uint32 mtu, uint16 dvid, int8 isNapt, uint16 srcPortList);
# 901 "rtl8651_tblDrvFwdLocal.h"
extern int8 rtl8651_drvMulticastProcessEnable;
extern int8 rtl8651_drvPacketFastSend;
extern int8 rtl8651_drvIcmpRoutingMsgEnable;
extern int8 rtl8651_drvSoftwareBroadcastEnable[8];
extern rtl8651_tblDrvFwdEngineCounts_t rtl8651_fwdEngineCounter;




inline void _rtl8651_l4TcpAdjustMss(struct ip *ip, struct tcphdr *tc, ipaddr_t intfIp, int32 delta);
int32 _rtl8651_isdigit(int32);
int32 _rtl8651_isspace(int32);
void _rtl8651_l4AddSeq(struct ip *pip, rtl8651_tblDrv_naptTcpUdpFlowEntry_t *tb, int32 delta);
int32 _rtl8651_l4GetDeltaSeqOut(struct ip * pip, struct tcphdr *tc, rtl8651_tblDrv_naptTcpUdpFlowEntry_t *tb);




int _rtl8651_markDiffserv( int32, struct rtl_pktHdr *, struct ip *, void * );
# 29 "rtl8651_multicast_local.h" 2
# 129 "rtl8651_multicast_local.h"
struct rtl8651_tblDrvMCastMember_s;
struct rtl8651_tblDrvMCast_s;
struct rtl8651_tblDrvMCastMember_s;


typedef struct rtl8651_tblDrvMCastSource_s {
        uint8 _type;

        ipaddr_t source;
        struct rtl8651_timer_list timer;

        struct rtl8651_tblDrvMCastMember_s * mbr;
        struct rtl8651_tblDrvMCastSource_s * prev;
        struct rtl8651_tblDrvMCastSource_s * next;
} rtl8651_tblDrvMCastSource_t;


typedef struct rtl8651_tblDrvMCastMember_s {
        uint8 _type;


        rtl8651_tblDrv_vlanTable_t * vlan;
        uint16 portMask;


        uint8 MulticastRouterVersion;
        struct rtl8651_timer_list timer_filterMode;
        struct rtl8651_timer_list timer_state;
        struct rtl8651_timer_list timer_query;
        struct rtl8651_timer_list timer_query_expire;
        uint8 state;
        uint8 remainingQuery;
        uint8 isForwarder;
        uint8 FilterMode;


        struct rtl8651_tblDrvMCast_s * m_entry;
        struct rtl8651_tblDrvMCastMember_s * prev;
        struct rtl8651_tblDrvMCastMember_s * next;
        struct rtl8651_tblDrvMCastSource_s * slist;
} rtl8651_tblDrvMCastMember_t;






typedef struct rtl8651_tblDrvMCast_s {
        uint8 _type;

        ipaddr_t mcast_addr;


        struct rtl8651_timer_list timer_upstream;
        rtl8651_tblDrv_vlanTable_t * up_vlan;
        uint16 up_portMask;
        uint8 MulticastRouterVersion;

        uint8 FilterMode;
        rtl8651_tblDrvMCastSource_t * slist;


        rtl8651_tblDrvMCastMember_t * member;
        uint32 memberCnt;


        struct rtl8651_tblDrvMCast_s * prev;
        struct rtl8651_tblDrvMCast_s * next;
} rtl8651_tblDrvMCast_t;





typedef struct rtl8651_tblDrvMCastRouteInfo_s {
        ipaddr_t m_addr;
        rtl8651_tblDrv_vlanTable_t *vlan;
        uint8 isPortMask;
        uint16 port;
        rtl8651_tblDrv_networkIntfTable_t *netif;
        uint32 ifInfo;
} rtl8651_tblDrvMCastRouteInfo_t;




typedef struct rtl8651_tblDrvMCastUpStreamInfo_s {
        uint8 isSet;
        rtl8651_tblDrv_networkIntfTable_t *netif;
        rtl8651_tblDrv_vlanTable_t *vlan;
        uint16 portMask;
        union {
                ipaddr_t intfIp;
                rtl8651_tblDrvSession_t *pppoesessionPtr;
                rtl8651_tblDrvSession_t *sessionPtr;
        } MUpStreamInfo_un;





} rtl8651_tblDrvMCastUpStreamInfo_t;




typedef struct rtl8651_tblDrvMCastGlobal_s {
        struct rtl8651_timer_list query_timer;
        uint8 remainingQuery;
        rtl8651_tblDrvMCastUpStreamInfo_t MCastUpStream;
} rtl8651_tblDrvMCastGlobal_t;





typedef struct rtl8651_tblDrvMCastFilter_s {
        ipaddr_t gip;
        uint32 action;

        struct rtl8651_tblDrvMCastFilter_s *next;
} rtl8651_tblDrvMCastFilter_t;
# 265 "rtl8651_multicast_local.h"
int32 _rtl8651_multicastInit(rtl8651_fwdEngineInitPara_t *);
int32 _rtl8651_multicast_FilterInit(rtl8651_fwdEngineInitPara_t *);



int32 _rtl8651_igmp_process(struct rtl_pktHdr *, struct ip *, struct igmp *);
int32 _rtl8651_multicast_process(struct rtl_pktHdr *, struct ip *);
int32 _rtl8651_multicast_Fastfwd(struct rtl_pktHdr *, struct ip *, rtl8651_tblDrv_vlanTable_t *);
# 13 "rtl8651_multicast.c" 2
# 24 "rtl8651_multicast.c"
static uint16 system_id = 1;
# 34 "rtl8651_multicast.c"
static rtl8651_tblDrvMCastGlobal_t rtl8651_GlobalVariable;
static rtl8651_tblDrvMCast_t * rtl8651_MCastTable = ((void *)0);
static uint32 rtl8651_drvMaxMCastCnt = 20;
static uint32 rtl8651_drvMaxMCastMemberCnt = 6;
static uint32 rtl8651_drvMaxTotalMemberCnt = 120;
static uint32 rtl8651_drvMaxTotalSourceCnt = 200;

static uint32 rtl8651_drvMCastMember_ExpireTime = 180;
static uint32 rtl8651_drvMCastUpstream_Timeout = 125;
static uint8 rtl8651_drvMCastVersion = 3;

static uint32 rtl8651_igmp_qi = 125;
static uint32 rtl8651_igmp_qri = 10;
static uint32 rtl8651_igmp_oqpi = 255;


static uint32 rtl8651_igmp_sqc = 3;
static uint32 rtl8651_igmp_sqi = 25;

static uint32 rtl8651_igmp_lmqc = 2;
static uint32 rtl8651_igmp_lmqi = 5;

static uint32 rtl8651_igmp_gmi = 135;
static uint32 rtl8651_igmp_lmqt = (2 * 5);



static uint32 rtl8651_igmp_general_query = 0;
static uint32 rtl8651_igmp_group_query_interval = 125;
static uint32 rtl8651_igmp_response_tolerance_delay = 5;

static uint32 rtl8651_MCastEntryCnt = 0;
static uint32 rtl8651_MemberCnt = 0;
static uint32 rtl8651_SourceListCnt = 0;
static uint8 system_enable = 1;
# 77 "rtl8651_multicast.c"
static uint32 rtl8651_SystemMCastMemberCnt = ((120>(20*6))?(20*6):120);
static uint32 rtl8651_SystemMCastSourceCnt = (5 * 200);





static uint32 rtl8651_multicastProcessOptions = 0;
# 94 "rtl8651_multicast.c"
static rtl8651_tblDrvMCast_t *MCastEntryPool = ((void *)0);
static rtl8651_tblDrvMCastMember_t *MCastMemberPool = ((void *)0);
static rtl8651_tblDrvMCastSource_t *MCastSourcePool = ((void *)0);

static rtl8651_tblDrvMCast_t *MCastEntryPoolPtr = ((void *)0);
static rtl8651_tblDrvMCastMember_t *MCastMemberPoolPtr = ((void *)0);
static rtl8651_tblDrvMCastSource_t *MCastSourcePoolPtr = ((void *)0);





static rtl8651_tblDrvMCastFilter_t *MCastFilter[32] = {((void *)0)};
static rtl8651_tblDrvMCastFilter_t *MCastFilter_FreeHdr = ((void *)0);







static __inline__ int32 _rtl8651_multicastSetInitPara(rtl8651_fwdEngineInitPara_t *);



static __inline__ int32 MCastPool_init(void);
static __inline__ void MCastPool_reinit(void);
static void *MCast_malloc(uint32);
static void MCast_free(void *);



static uint16 MCast_igmpChecksum(struct ip *);
static void MCast_BroadCastQuery(void);
static int32 MCast_setPkthdrProperty(struct rtl_pktHdr *, int32);




static rtl8651_tblDrvMCast_t *MCast_FindMCastEntry(ipaddr_t, uint8, uint8);
static rtl8651_tblDrvMCast_t *MCast_CreateMCastEntry(ipaddr_t);
static __inline__ uint8 MCast_MCastEntryMinVersion(rtl8651_tblDrvMCast_t *);
static __inline__ void MCast_SetMCastEntryUpStream(rtl8651_tblDrvMCast_t *,rtl8651_tblDrv_vlanTable_t *, uint16, uint8);
static void MCast_ClrMCastEntryUpStream(uint32);
static void MCast_RemoveMCastEntry(rtl8651_tblDrvMCast_t *);
static __inline__ void MCast_Entrylink(rtl8651_tblDrvMCast_t *);
static __inline__ void MCast_EntryUnlink(rtl8651_tblDrvMCast_t *);

static rtl8651_tblDrvMCastMember_t *MCast_FindMember(rtl8651_tblDrvMCast_t *, rtl8651_tblDrv_vlanTable_t *, uint16, uint8, uint8, uint8);
static rtl8651_tblDrvMCastMember_t *MCast_CreateMember(rtl8651_tblDrvMCast_t *, rtl8651_tblDrv_vlanTable_t *, uint16, uint8);
static void MCast_RemoveMember(rtl8651_tblDrvMCast_t *, rtl8651_tblDrvMCastMember_t *);
static void MCast_DestroyMember(rtl8651_tblDrvMCastMember_t *);
static __inline__ void MCast_MemberLink(rtl8651_tblDrvMCast_t *, rtl8651_tblDrvMCastMember_t *);
static __inline__ int32 MCast_MemberUnLink(rtl8651_tblDrvMCastMember_t *);
static void MCast_MemberExcludeExpire(uint32);
static void MCast_MemberExpire(uint32);
static void MCast_MemberSendQuery(rtl8651_tblDrvMCastMember_t *);

static __inline__ rtl8651_tblDrvMCastSource_t *MCast_SourceList_Create(void);
static __inline__ void MCast_SourceList_Link(rtl8651_tblDrvMCast_t *, rtl8651_tblDrvMCastMember_t *, rtl8651_tblDrvMCastSource_t *);
static __inline__ void MCast_SourceList_UnLink(rtl8651_tblDrvMCastSource_t *);
static rtl8651_tblDrvMCastSource_t* MCast_SourceList_inList(ipaddr_t , rtl8651_tblDrvMCastSource_t *);
static __inline__ uint32 MCast_SourceList_EntryCnt(rtl8651_tblDrvMCastSource_t *);
static rtl8651_tblDrvMCastSource_t *MCast_SourceList_freeCurrent(rtl8651_tblDrvMCastSource_t *);
static void MCast_SourceList_freeAll(rtl8651_tblDrvMCastSource_t *);
static uint32 MCast_SourceList_removal(rtl8651_tblDrvMCastSource_t *,uint8 ,uint8 ,rtl8651_tblDrvMCastSource_t *,uint8 ,uint8 ,rtl8651_tblDrvMCastSource_t **);
static void MCast_SourceList_addList(rtl8651_tblDrvMCastMember_t *, rtl8651_tblDrvMCastSource_t *, uint8, uint8);
static int32 MCast_SourceList_dup(rtl8651_tblDrvMCastMember_t *, rtl8651_tblDrvMCastSource_t *, rtl8651_tblDrvMCastSource_t **);
static void MCast_SourceList_Expire(rtl8651_tblDrvMCastSource_t *);
static uint32 MCast_SourceList_getCache(rtl8651_tblDrvMCast_t *, rtl8651_tblDrvMCastSource_t **);



static __inline__ ipaddr_t MCast_GetIpByVlan(rtl8651_tblDrv_vlanTable_t *, uint32);
static __inline__ int32 MCast_SetRouteInfoAndGetIntfIp(ipaddr_t *, rtl8651_tblDrvMCastRouteInfo_t *);
static int32 MCast_query(struct rtl_pktHdr *, struct ip *, struct igmp *);
static int32 MCast_report(struct rtl_pktHdr *, struct ip *, struct igmp *);
static int32 MCast_leave(struct rtl_pktHdr *, struct ip *, struct igmp *);

static int32 MCast_QueryPack(rtl8651_tblDrvMCastMember_t *,rtl8651_tblDrvMCastRouteInfo_t *, uint8, rtl8651_tblDrvMCastSource_t *, uint16, struct rtl_pktHdr *);
static int32 MCast_ReportPack(rtl8651_tblDrvMCast_t *, uint8, uint8, rtl8651_tblDrvMCastSource_t *, uint8, rtl8651_tblDrvMCastSource_t *, struct rtl_pktHdr *);

static int32 MCast_LeavePack(rtl8651_tblDrvMCast_t *, struct rtl_pktHdr *);
static int32 MCast_l3ActRouting(struct rtl_pktHdr *, rtl8651_tblDrvMCastRouteInfo_t *);

static __inline__ void MCast_Proc_ISIN(rtl8651_tblDrvMCastMember_t*, rtl8651_tblDrvMCastSource_t *, uint16 ,uint8);
static __inline__ void MCast_Proc_ISEX(rtl8651_tblDrvMCastMember_t*, rtl8651_tblDrvMCastSource_t *, uint16 ,uint8);
static __inline__ void MCast_Proc_TOIN(rtl8651_tblDrvMCastMember_t*, rtl8651_tblDrvMCastSource_t *, uint16 ,uint8);
static __inline__ void MCast_Proc_TOEX(rtl8651_tblDrvMCastMember_t*, rtl8651_tblDrvMCastSource_t *, uint16 ,uint8);
static __inline__ void MCast_Proc_ALLOW(rtl8651_tblDrvMCastMember_t*, rtl8651_tblDrvMCastSource_t *, uint16 ,uint8);
static __inline__ void MCast_Proc_BLOCK(rtl8651_tblDrvMCastMember_t*, rtl8651_tblDrvMCastSource_t *, uint16 ,uint8);




static __inline__ uint32 _rtl8651_multicast_Filter_Hash(ipaddr_t);
rtl8651_tblDrvMCastFilter_t *_rtl8651_multicast_FindFilter(ipaddr_t);






static __inline__ int32 MCastPool_init(void)
{
        int32 retval = 0;

        rtlglue_drvMutexLock();

        if ( (rtl8651_drvMaxMCastCnt == 0) ||
                (rtl8651_SystemMCastMemberCnt == 0) ||
                (rtl8651_SystemMCastSourceCnt == 0) )
        {
                goto out;
        }


        MCastEntryPool = (rtl8651_tblDrvMCast_t *)rtlglue_malloc(sizeof(rtl8651_tblDrvMCast_t) * rtl8651_drvMaxMCastCnt);
        MCastMemberPool =
                (rtl8651_tblDrvMCastMember_t *)rtlglue_malloc(sizeof(rtl8651_tblDrvMCastMember_t) * rtl8651_SystemMCastMemberCnt);
        MCastSourcePool =
                (rtl8651_tblDrvMCastSource_t *)rtlglue_malloc(sizeof(rtl8651_tblDrvMCastSource_t) * rtl8651_SystemMCastSourceCnt);

        if ( (MCastEntryPool == ((void *)0)) ||
                (MCastMemberPool == ((void *)0)) ||
                (MCastSourcePool == ((void *)0)) )
        {

                retval = -1;
                goto out;
        }

        MCastPool_reinit();



out:
        rtlglue_drvMutexUnlock();

        return retval;
}
void MCastPool_reinit(void)
{
        uint32 idx;
        rtl8651_tblDrvMCast_t *mCastPtr;
        rtl8651_tblDrvMCastMember_t *mCastMemberPtr;
        rtl8651_tblDrvMCastSource_t *mCastSourcePtr;

        rtlglue_drvMutexLock();


        bzero(MCastEntryPool, (rtl8651_drvMaxMCastCnt * sizeof(rtl8651_tblDrvMCast_t)));
        MCastEntryPoolPtr = MCastEntryPool;
        mCastPtr = MCastEntryPool;
        for (idx = 0 ; idx < rtl8651_drvMaxMCastCnt ; idx ++, mCastPtr ++)
        {
                if (idx == (rtl8651_drvMaxMCastCnt - 1))
                        mCastPtr->next = ((void *)0);
                else
                        mCastPtr->next = mCastPtr + 1;
        }

        bzero(MCastMemberPool, (rtl8651_SystemMCastMemberCnt * sizeof(rtl8651_tblDrvMCastMember_t)));
        MCastMemberPoolPtr = MCastMemberPool;
        mCastMemberPtr = MCastMemberPool;
        for (idx = 0 ; idx < rtl8651_SystemMCastMemberCnt ; idx ++, mCastMemberPtr ++)
        {
                if (idx == (rtl8651_SystemMCastMemberCnt - 1))
                        mCastMemberPtr->next = ((void *)0);
                else
                        mCastMemberPtr->next = mCastMemberPtr + 1;
        }

        bzero(MCastSourcePool, (rtl8651_SystemMCastSourceCnt * sizeof(rtl8651_tblDrvMCastSource_t)));
        MCastSourcePoolPtr = MCastSourcePool;
        mCastSourcePtr = MCastSourcePool;
        for (idx = 0 ; idx < rtl8651_SystemMCastSourceCnt ; idx ++, mCastSourcePtr ++)
        {
                if (idx == (rtl8651_SystemMCastSourceCnt - 1))
                        mCastSourcePtr->next = ((void *)0);
                else
                        mCastSourcePtr->next = mCastSourcePtr + 1;
        }

        rtlglue_drvMutexUnlock();
}
# 290 "rtl8651_multicast.c"
int32 rtl8651_multicastSetPara(rtl8651_tblDrvMCastPara_t *para)
{
        if (!para)
                return -1;

        rtlglue_drvMutexLock();

        if (para->MCastMember_ExpireTime)
                rtl8651_drvMCastMember_ExpireTime = para->MCastMember_ExpireTime;
        if (para->MCastUpstream_Timeout)
                rtl8651_drvMCastUpstream_Timeout = para->MCastUpstream_Timeout;
        if (para->igmp_qi)
                rtl8651_igmp_qi = para->igmp_qi;
        if (para->igmp_qri)
                rtl8651_igmp_qri = para->igmp_qri;
        if (para->igmp_gmi)
                rtl8651_igmp_gmi = para->igmp_gmi;
        if (para->igmp_group_query_interval)
                rtl8651_igmp_group_query_interval = para->igmp_group_query_interval;

        rtl8651_igmp_oqpi = para->igmp_oqpi;
        rtl8651_igmp_sqc = para->igmp_sqc;
        rtl8651_igmp_sqi = para->igmp_sqi;
        rtl8651_igmp_lmqc = para->igmp_lmqc;
        rtl8651_igmp_lmqi = para->igmp_lmqi;
        rtl8651_igmp_lmqt = (rtl8651_igmp_lmqc * rtl8651_igmp_lmqi);

        rtl8651_igmp_response_tolerance_delay = para->igmp_response_tolerance_delay;

        if (rtl8651_GlobalVariable.remainingQuery)
                rtl8651_GlobalVariable.remainingQuery = rtl8651_igmp_sqc;

        rtlglue_drvMutexUnlock();
        return 0;
}
# 334 "rtl8651_multicast.c"
int32 _rtl8651_multicastSetInitPara(rtl8651_fwdEngineInitPara_t *para)
{
        uint32 c1, c2;

        if (!para)
                return -1;

        rtl8651_multicastProcessOptions = para->MCastProcessOption;
        rtl8651_drvMaxMCastCnt = para->MaxMCastCnt;
        rtl8651_drvMaxMCastMemberCnt = para->MaxMCastMemberCnt;
        rtl8651_drvMaxTotalMemberCnt = para->MaxMCastTotalMemberCnt;
        rtl8651_drvMaxTotalSourceCnt = para->MaxMCastTotalSourceCnt;
        rtl8651_SystemMCastSourceCnt = rtl8651_drvMaxTotalSourceCnt + (4 * rtl8651_drvMaxTotalSourceCnt);

        if ((para->MCastDefaultVersion > 3) ||
                        (para->MCastDefaultVersion == 0))
        {
                rtl8651_drvMCastVersion = 3;
        }else
        {
                rtl8651_drvMCastVersion = para->MCastDefaultVersion;
        }


        if (para->MCastMember_ExpireTime)
                rtl8651_drvMCastMember_ExpireTime = para->MCastMember_ExpireTime;
        if (para->MCastUpstream_Timeout)
                rtl8651_drvMCastUpstream_Timeout = para->MCastUpstream_Timeout;
        if (para->igmp_qi)
                rtl8651_igmp_qi = para->igmp_qi;
        if (para->igmp_qri)
                rtl8651_igmp_qri = para->igmp_qri;
        if (para->igmp_gmi)
                rtl8651_igmp_gmi = para->igmp_gmi;
        if (para->igmp_group_query_interval)
                rtl8651_igmp_group_query_interval = para->igmp_group_query_interval;

        rtl8651_igmp_oqpi = para->igmp_oqpi;
        rtl8651_igmp_sqc = para->igmp_sqc;
        rtl8651_igmp_sqi = para->igmp_sqi;
        rtl8651_igmp_lmqc = para->igmp_lmqc;
        rtl8651_igmp_lmqi = para->igmp_lmqi;
        rtl8651_igmp_lmqt = (rtl8651_igmp_lmqc * rtl8651_igmp_lmqi);

        rtl8651_igmp_response_tolerance_delay = para->igmp_response_tolerance_delay;

        {

                c1 = rtl8651_drvMaxTotalMemberCnt;
                c2 = (rtl8651_drvMaxMCastCnt * rtl8651_drvMaxMCastMemberCnt);

                if (c1 == 0)
                        rtl8651_SystemMCastMemberCnt = c2;
                else if (c2 == 0)
                        rtl8651_SystemMCastMemberCnt = c1;
                else
                        rtl8651_SystemMCastMemberCnt = ((c1>c2)?c2:c1);
        }

        return 0;
}






void rtl8651_multicastReinit(void)
{
        if (system_enable == 0)
                return;

        rtlglue_drvMutexLock();

        while (rtl8651_MCastTable)
                MCast_RemoveMCastEntry(rtl8651_MCastTable);


        _rtl8651_delMulticast(0, 0, 0);

        do {} while (0);
        do {} while (0);


        system_id = 1;

        MCastPool_reinit();


        rtl8651_multicastProcessOptions = 0;


        rtl8651_GlobalVariable.remainingQuery = rtl8651_igmp_sqc;

        if (rtl8651_igmp_sqc)
        {
                rtl8651_GlobalVariable.query_timer.data = (uint32)0;
                rtl8651_GlobalVariable.query_timer.function = (void*)MCast_BroadCastQuery;
                _rtl8651_mod_timer(&(rtl8651_GlobalVariable.query_timer), _sysUpSeconds + 10);
        }

        rtlglue_drvMutexUnlock();
}
# 447 "rtl8651_multicast.c"
int32 _rtl8651_multicastInit(rtl8651_fwdEngineInitPara_t * para)
{
        int32 retval = 0;

        system_enable = 0;


        rtl8651_MCastTable = ((void *)0);
        bzero(&rtl8651_GlobalVariable, sizeof(rtl8651_tblDrvMCastGlobal_t));
        rtl8651_GlobalVariable.MCastUpStream.isSet = 0;
        _rtl8651_init_timer(&(rtl8651_GlobalVariable.query_timer));


        if (para)
                retval = _rtl8651_multicastSetInitPara(para);


        if (
                (!rtl8651_drvMaxMCastCnt) ||
                (!rtl8651_SystemMCastMemberCnt) ||
                (!rtl8651_SystemMCastSourceCnt)
        )
                goto out;


        if ((retval = MCastPool_init()) != 0)
        {
                goto out;
        }


        system_enable = 1;


        rtl8651_multicastReinit();
out:
        return retval;
}







int32 rtl8651_multicastSetUpStream(int8* netifName, uint32 para)
{
        rtl8651_tblDrvMCastUpStreamInfo_t fake_UpStream;
        rtl8651_tblDrv_networkIntfTable_t *netif;

        printk("\nSet IGMP Default Upstream interface ");

        rtlglue_drvMutexLock();

        memset(&fake_UpStream, 0, sizeof(rtl8651_tblDrvMCastUpStreamInfo_t));
        if ((!netifName) ||
                ((netif = GET_NETWORK_INTERFACE(netifName, ((void *)0))) == ((void *)0)))
        {
                goto err;
        }
        printk("(%s) ... ", netifName);

        fake_UpStream.netif = netif;
        fake_UpStream.vlan = &DrvTbl.vlan[netif->vid & (8 - 1)];
        fake_UpStream.portMask = fake_UpStream.vlan->memberPortMask;

        switch (netif->linkLayerType)
        {
                case 0x01:
                        {
                                rtl8651_tblDrv_ipIntfEntry_t * ipIntfPtr;
                                rtl8651_tblDrv_ipIntfIpAddrEntry_t * ipAddrPtr;

                                if (para)
                                {
                                        for((ipIntfPtr) = (&(netif->IpHead))->slh_first; (ipIntfPtr); (ipIntfPtr) = (ipIntfPtr)->nextIp.sle_next)
                                        {
                                                if (!ipIntfPtr)
                                                {
                                                        goto err;
                                                }
                                                for((ipAddrPtr) = (&ipIntfPtr->ipAddr)->slh_first; (ipAddrPtr); (ipAddrPtr) = (ipAddrPtr)->nextIpAddr.sle_next)
                                                {
                                                        if (!ipAddrPtr)
                                                        {
                                                                goto err;
                                                        }
                                                        if (ipAddrPtr->ipAddr == para)
                                                        {
                                                                fake_UpStream.MUpStreamInfo_un.intfIp= para;
                                                                goto set_para;
                                                        }
                                                }
                                        }
                                        goto err;
                                }else
                                {
# 560 "rtl8651_multicast.c"
                                        fake_UpStream.MUpStreamInfo_un.intfIp = 0;

                                }
                        }
                        break;
                case 0x02:
                        {
                                rtl8651_tblDrvSession_t *sessionPtr;

                                if (para)
                                {
                                        for (sessionPtr = ((&(netif->sessionHead))->tqh_first); sessionPtr; sessionPtr = ((sessionPtr)->nextSession.tqe_next))
                                        {
                                                do {} while (0);
                                                if (sessionPtr->session_t->sessionId == para)
                                                {
                                                        fake_UpStream.MUpStreamInfo_un.pppoesessionPtr = sessionPtr;
                                                        goto set_para;
                                                }
                                        }
                                        goto err;
                                }else
                                {
                                        fake_UpStream.MUpStreamInfo_un.pppoesessionPtr = ((&netif->sessionHead)->tqh_first);
                                }
                        }
                        break;

                case 0x05:
                case 0x06:
                        {
                                rtl8651_tblDrvSession_t *sessionPtr;
                                if (para)
                                {
                                        for (sessionPtr = ((&(netif->sessionHead))->tqh_first); sessionPtr; sessionPtr = ((sessionPtr)->nextSession.tqe_next))
                                        {
                                                do {} while (0);
                                                if (sessionPtr->session_t->sessionId == para)
                                                {
                                                        fake_UpStream.MUpStreamInfo_un.sessionPtr = sessionPtr;
                                                        goto set_para;
                                                }
                                        }
                                        goto err;
                                }else
                                {
                                        fake_UpStream.MUpStreamInfo_un.sessionPtr = ((&netif->sessionHead)->tqh_first);
                                }
                        }
                        break;

                default:
                        goto err;
        }
set_para:
        rtl8651_GlobalVariable.MCastUpStream = fake_UpStream;
        rtl8651_GlobalVariable.MCastUpStream.isSet = 1;

        rtlglue_drvMutexUnlock();

        printk("SUCCESS!!\n");
        return 0;
err:
        rtlglue_drvMutexUnlock();
        printk("FAILED!!\n");
        return -1;
}
# 635 "rtl8651_multicast.c"
int32 rtl8651_multicastPeriodicQuery(int8 enable)
{
        if (enable)
        {



                if (rtl8651_igmp_general_query == 0)
                {
                        if (rtl8651_GlobalVariable.remainingQuery == 0)
                        {
                                _rtl8651_mod_timer(&(rtl8651_GlobalVariable.query_timer), _sysUpSeconds + rtl8651_igmp_qi);
                        }
                        rtl8651_igmp_general_query = 1;



                        MCast_BroadCastQuery();
                }
        }else
        {
                rtl8651_igmp_general_query = 0;
                if (rtl8651_GlobalVariable.remainingQuery == 0)
                        _rtl8651_del_timer(&(rtl8651_GlobalVariable.query_timer));
        }
        return 0;
}



void *MCast_malloc(uint32 size)
{
        void *ret = ((void *)0);

        switch (size)
        {
                case (sizeof (rtl8651_tblDrvMCast_t)):
                        if (MCastEntryPoolPtr)
                        {
                                ret = MCastEntryPoolPtr;
                                MCastEntryPoolPtr = MCastEntryPoolPtr->next;
                                bzero(ret, sizeof(rtl8651_tblDrvMCast_t));
                                ((rtl8651_tblDrvMCast_t *)ret)->_type = 0xff;
                        }
                        break;
                case (sizeof (rtl8651_tblDrvMCastMember_t)):
                        if (MCastMemberPoolPtr)
                        {
                                ret = MCastMemberPoolPtr;
                                MCastMemberPoolPtr = MCastMemberPoolPtr->next;
                                bzero(ret, sizeof(rtl8651_tblDrvMCastMember_t));
                                ((rtl8651_tblDrvMCastMember_t *)ret)->_type = 0xfe;
                        }
                        break;
                case (sizeof (rtl8651_tblDrvMCastSource_t)):
                        if (MCastSourcePoolPtr)
                        {
                                ret = MCastSourcePoolPtr;
                                MCastSourcePoolPtr = MCastSourcePoolPtr->next;
                                bzero(ret, sizeof(rtl8651_tblDrvMCastSource_t));
                                ((rtl8651_tblDrvMCastSource_t *)ret)->_type = 0xfd;
                        }
                        break;
                default:
                        do {} while (0);
        }

        return ret;
}
void MCast_free(void *ptr)
{
        if (!ptr)
                return;

        switch (((rtl8651_tblDrvMCast_t *)ptr)->_type)
        {
                case 0xff:
                        ((rtl8651_tblDrvMCast_t *)ptr)->next = MCastEntryPoolPtr;
                        MCastEntryPoolPtr = (rtl8651_tblDrvMCast_t *)ptr;
                        break;
                case 0xfe:
                        ((rtl8651_tblDrvMCastMember_t *)ptr)->next = MCastMemberPoolPtr;
                        MCastMemberPoolPtr = (rtl8651_tblDrvMCastMember_t *)ptr;
                        break;
                case 0xfd:
                        ((rtl8651_tblDrvMCastSource_t *)ptr)->next = MCastSourcePoolPtr;
                        MCastSourcePoolPtr = (rtl8651_tblDrvMCastSource_t *)ptr;
                        break;
                default:
                        do {} while (0);
        }
}




uint16 MCast_igmpChecksum(struct ip * pip)
{
        uint16 *ptr;
        int32 nhdr, nbytes;
        int32 sum, i;


        nhdr = ((pip->ip_vhl &0xf) << 2);
        nbytes = (pip->ip_len) - nhdr;
        ptr = (uint16 *) ((char *) pip + nhdr);
        sum = 0;


        *(((uint8 *)pip) + nhdr + nbytes) = (uint8)0;
        for (i=0; i<nbytes ; i=i+2){
                sum += (unsigned long) *ptr++;
        }


        sum = (sum >> 16) + (sum & 0xffff);
        sum += (sum >> 16);


        return ((uint16) ~ sum);
}






void MCast_BroadCastQuery(void)
{

        if ((system_enable == 0) || (rtl8651_drvMulticastProcessEnable == 0))
                return;

        if ((rtl8651_igmp_general_query == 1) ||
                (rtl8651_GlobalVariable.remainingQuery > 0))
        {

                rtl8651_tblDrvMCastRouteInfo_t info;
                uint8 idx;
                rtl8651_tblDrv_vlanTable_t * vlanp;
# 783 "rtl8651_multicast.c"
                info.m_addr = (0xE0000001L);

                vlanp = DrvTbl.vlan;
                for (idx = 0 ; idx < 8 ; idx ++)
                {
                        if ((vlanp->valid) && (vlanp->internal))
                        {
                                info.netif = ((void *)0);
                                info.ifInfo = 0;
                                info.vlan = vlanp;
                                info.port = vlanp->memberPortMask;
                                info.isPortMask= 1;
                                if ((rtl8651_GlobalVariable.MCastUpStream.isSet == 1) &&
                                        (rtl8651_GlobalVariable.MCastUpStream.vlan == vlanp))
                                {
                                        info.port &= ~(rtl8651_GlobalVariable.MCastUpStream.portMask);
                                        if (info.port == 0)
                                                goto next_vlan;
                                }
                                MCast_QueryPack(((void *)0), &info, rtl8651_drvMCastVersion, ((void *)0), 0, ((void *)0));
                        }

                next_vlan:
                        vlanp ++;
                }


                if (rtl8651_GlobalVariable.remainingQuery != 0)
                {
                        _rtl8651_mod_timer(&(rtl8651_GlobalVariable.query_timer), _sysUpSeconds + rtl8651_igmp_sqi);

                        rtl8651_GlobalVariable.remainingQuery --;
                }
        }

        if (rtl8651_GlobalVariable.remainingQuery == 0)
        {
                if (rtl8651_igmp_general_query == 1)
                        _rtl8651_mod_timer(&(rtl8651_GlobalVariable.query_timer), _sysUpSeconds + rtl8651_igmp_qi);
                else
                        _rtl8651_del_timer(&(rtl8651_GlobalVariable.query_timer));
        }
        return;
}





void MCast_DumpMCast(void)
{
        rtl8651_tblDrvMCast_t *m_entry;
        rtl8651_tblDrvMCastMember_t *member;
        rtl8651_tblDrvMCastSource_t *source;

        printk("\nIGMP System report:\n");

        printk("System support latest IGMP version:\t\t[ IGMPv%d ]\n", 3);
        printk("System default IGMP version:\t\t\t[ IGMPv%d ]\n", rtl8651_drvMCastVersion);

        if (system_enable == 0)
        {
                printk("\nIP-multicast system Enable:\t\t[ NO ]\n\n");
                return;
        }


        printk("Timer:\n");
        printk("\tSystem specific:\n");
        if (rtl8651_drvMCastUpstream_Timeout == 0xffffffff)
                printk("\t\tUp-stream No-response timeout:\t\t[INFINITE]\n");
        else
                printk("\t\tUp-stream No-response timeout:\t\t%d sec.\n", rtl8651_drvMCastUpstream_Timeout);

        printk("\t\tDown-stream No-report timeout:\t\t%d sec.\n", rtl8651_drvMCastMember_ExpireTime);

        printk("\tIGMP msg related:\n");
        printk("\t\tQuery Interval:\t\t\t\t%d sec.\n", rtl8651_igmp_group_query_interval);
        printk("\t\tQuery Response Interval:\t\t%d sec.\n", rtl8651_igmp_qri);
        printk("\t\tOther Querier Present Interval:\t\t%d sec.\n", rtl8651_igmp_oqpi);
        printk("\t\tIGMP msg tolerance delay:\t\t%d sec\n", rtl8651_igmp_response_tolerance_delay);
        printk("\t\tSystem-up Query Count:\t\t\t%d\n", rtl8651_igmp_sqc);
        printk("\t\tSystem-up Query Interval:\t\t%d sec.\n", rtl8651_igmp_sqi);
        printk("\t\tLast Member Query Count:\t\t%d\n", rtl8651_igmp_lmqc);
        printk("\t\tLast Member Query Interval:\t\t%d sec.\n", rtl8651_igmp_lmqi);

        printk("\n\t\tPeriodic General Query:\t");
        if (rtl8651_igmp_general_query == 1)
                printk("[ on ]\n\t\t\tQuery Interval:\t\t\t%d sec.\n\n", rtl8651_igmp_qi);
        else
                printk("[ off ]\n\n");


        printk("System status:\n");
        printk("\t\tRemaining Start-up Query Count:\t\t%d\n", rtl8651_GlobalVariable.remainingQuery);
        if (rtl8651_igmp_general_query == 1)
                printk("\t\tNext general query remaining time:\t%d sec.\n", (rtl8651_GlobalVariable.query_timer.expires - _sysUpSeconds));
        printk("\n");


        printk("Resource Utilization:\n");
        printk("\t\t\t\tTotal\tUsage\tFree\n");
        printk("\tMulticast Entry\t\t%d\t%d\t%d\n", rtl8651_drvMaxMCastCnt, rtl8651_MCastEntryCnt, (rtl8651_drvMaxMCastCnt-rtl8651_MCastEntryCnt));
        printk("\tMulticast Member\t%d\t%d\t%d\n", rtl8651_SystemMCastMemberCnt, rtl8651_MemberCnt, (rtl8651_SystemMCastMemberCnt-rtl8651_MemberCnt));
        printk("\tSource List\t\t%d\t%d\t%d\n", rtl8651_SystemMCastSourceCnt, rtl8651_SourceListCnt, (rtl8651_SystemMCastSourceCnt-rtl8651_SourceListCnt));

        printk("Multicast Entries:\n");
        printk("===============================================================\n");

        rtlglue_drvMutexLock();

        m_entry = rtl8651_MCastTable;
        while (m_entry)
        {
                printk("(%3u.%3u.%3u.%3u) [IGMPv%d] <Up ", ((unsigned char *)&m_entry->mcast_addr)[0], ((unsigned char *)&m_entry->mcast_addr)[1], ((unsigned char *)&m_entry->mcast_addr)[2], ((unsigned char *)&m_entry->mcast_addr)[3], m_entry->MulticastRouterVersion);
                if (m_entry->up_vlan)
                        printk("Vid[0x%02X] pMsk[0x%02X] ", m_entry->up_vlan->vid, m_entry->up_portMask);
                else
                        printk("NOT Set ");

                if ((rtl8651_drvMCastUpstream_Timeout == 0xffffffff) || !(m_entry->up_vlan))
                        printk("(NO Exp) >");
                else
                        printk("(Exp: %d) >", (m_entry->timer_upstream.expires - _sysUpSeconds));

                if (rtl8651_drvMaxMCastMemberCnt)
                        printk(" MEMBER[%d:%d]\n", m_entry->memberCnt, rtl8651_drvMaxMCastMemberCnt);
                else
                        printk(" MEMBER[%d]\n", m_entry->memberCnt);


                member = m_entry->member;
                while (member)
                {
                        if (member->isForwarder == 1)
                                printk("\t=> [O] ");
                        else
                                printk("\t=> [X] ");
                        printk("VID[0x%02X] MBR[0x%02X] [v%d] %s(%d) ",
                                member->vlan->vid, member->portMask, member->MulticastRouterVersion,
                                ((member->FilterMode == 2)?"Inc":"Exc"),
                                ((member->FilterMode == 2)?0:(member->timer_filterMode.expires - _sysUpSeconds)));

                        if (member->state == 1)
                        {
                                printk("(NORMAL) NextQ(%d) ", (member->timer_query.expires - _sysUpSeconds));
                                if (member->timer_query_expire.list.next)
                                        printk("Exp:(%d)\n", (member->timer_query_expire.expires - _sysUpSeconds));
                                else
                                        printk("Exp:(%d)\n", (member->timer_state.expires - _sysUpSeconds));
                        }else
                                printk("(EXPIRE) Rem Q(%d) Exp(%d)\n", member->remainingQuery, (member->timer_state.expires - _sysUpSeconds));
                        if (member->FilterMode == 2)
                        {
                                source = member->slist;
                                while (source)
                                {
                                        printk("\t\t+ %u.%u.%u.%u (Exp %d)\n", ((unsigned char *)&source->source)[0], ((unsigned char *)&source->source)[1], ((unsigned char *)&source->source)[2], ((unsigned char *)&source->source)[3], (source->timer.expires - _sysUpSeconds));
                                        source = source->next;
                                }
                        }else if (member->FilterMode == 1)
                        {
                                source = member->slist;
                                while (source)
                                {
                                        if (source->timer.expires <= _sysUpSeconds)
                                                printk("\t\t- %u.%u.%u.%u\n", ((unsigned char *)&source->source)[0], ((unsigned char *)&source->source)[1], ((unsigned char *)&source->source)[2], ((unsigned char *)&source->source)[3]);
                                        source = source->next;
                                }
                                source = member->slist;
                                while (source)
                                {
                                        if (source->timer.expires > _sysUpSeconds)
                                                printk("\t\t+ %u.%u.%u.%u (Exp %d)\n", ((unsigned char *)&source->source)[0], ((unsigned char *)&source->source)[1], ((unsigned char *)&source->source)[2], ((unsigned char *)&source->source)[3], (source->timer.expires - _sysUpSeconds));
                                        source = source->next;
                                }
                        }


                        member = member->next;
                }


                m_entry = m_entry->next;
        }

        rtlglue_drvMutexUnlock();

        printk("===============================================================\n\n");
        return;
}

rtl8651_tblDrvMCast_t *MCast_FindMCastEntry(ipaddr_t mcast_addr, uint8 create, uint8 refresh)
{
        rtl8651_tblDrvMCast_t *m_entry = rtl8651_MCastTable;

        if (!((((ipaddr_t)(mcast_addr)) & 0xf0000000) == 0xe0000000))
                return ((void *)0);

        while (m_entry)
        {
                if (m_entry->mcast_addr == mcast_addr)
                {
                        if (refresh == 1)
                        {
                                if (rtl8651_drvMCastUpstream_Timeout == 0xffffffff)
                                        _rtl8651_del_timer(&m_entry->timer_upstream);
                                else if (m_entry->up_vlan)
                                        _rtl8651_mod_timer(&m_entry->timer_upstream, _sysUpSeconds + rtl8651_drvMCastUpstream_Timeout);
                        }
                        return m_entry;
                }
                m_entry = m_entry->next;
        }

        if (create == 1)
                return MCast_CreateMCastEntry(mcast_addr);
        else
                return ((void *)0);
}

rtl8651_tblDrvMCast_t *MCast_CreateMCastEntry(ipaddr_t mcast_addr)
{
        rtl8651_tblDrvMCast_t *new_entry;





        rtlglue_drvMutexLock();


        if (rtl8651_MCastEntryCnt >= rtl8651_drvMaxMCastCnt)
                goto errout;


        new_entry = (rtl8651_tblDrvMCast_t *)MCast_malloc(sizeof(rtl8651_tblDrvMCast_t));
        if (!new_entry)
                goto errout;


        new_entry->mcast_addr = mcast_addr;
        new_entry->MulticastRouterVersion = rtl8651_drvMCastVersion;
        new_entry->memberCnt = 0;
        new_entry->member = ((void *)0);
        new_entry->up_vlan = ((void *)0);
        new_entry->up_portMask = 0;


        new_entry->FilterMode = 0;
        new_entry->slist = ((void *)0);

        new_entry->next = ((void *)0);
        new_entry->prev = ((void *)0);


        _rtl8651_init_timer(&new_entry->timer_upstream);
        new_entry->timer_upstream.data = (uint32)new_entry;
        new_entry->timer_upstream.function =(void*)MCast_ClrMCastEntryUpStream;


        MCast_Entrylink(new_entry);


        rtl8651_MCastEntryCnt ++;





        rtlglue_drvMutexUnlock();
        return new_entry;
errout:
        rtlglue_drvMutexUnlock();
        return ((void *)0);
}

uint8 MCast_MCastEntryMinVersion(rtl8651_tblDrvMCast_t *m_entry)
{
        rtl8651_tblDrvMCastMember_t *mptr;
        uint8 v = 3;

        if (!m_entry)
                goto out;
        mptr = m_entry->member;
        while (mptr)
        {
                if (mptr->MulticastRouterVersion < v)
                        v = mptr->MulticastRouterVersion;
                mptr = mptr->next;
        }
out:
        return v;
}

void MCast_SetMCastEntryUpStream(rtl8651_tblDrvMCast_t *m_entry, rtl8651_tblDrv_vlanTable_t *vlan, uint16 up_port, uint8 RouterVersion)
{
        m_entry->up_vlan = vlan;
        m_entry->up_portMask = (1<<up_port);
        m_entry->MulticastRouterVersion = RouterVersion;
        if (rtl8651_drvMCastUpstream_Timeout != 0xffffffff)
                _rtl8651_mod_timer(&m_entry->timer_upstream, _sysUpSeconds + rtl8651_drvMCastUpstream_Timeout);
        m_entry->timer_upstream.data = (uint32)m_entry;
        m_entry->timer_upstream.function = (void*)MCast_ClrMCastEntryUpStream;
}

void MCast_ClrMCastEntryUpStream(uint32 expire)
{
        rtl8651_tblDrvMCast_t *m_entry = (rtl8651_tblDrvMCast_t *)expire;
        m_entry->up_vlan = ((void *)0);
        m_entry->up_portMask = 0;
        m_entry->MulticastRouterVersion = rtl8651_drvMCastVersion;
}

void MCast_RemoveMCastEntry(rtl8651_tblDrvMCast_t *m_entry)
{
# 1107 "rtl8651_multicast.c"
        rtlglue_drvMutexLock();

        _rtl8651_delMulticast(m_entry->mcast_addr, 0, 0);

        if (m_entry->MulticastRouterVersion == 2)
                MCast_LeavePack(m_entry, ((void *)0));
        if (m_entry->MulticastRouterVersion == 3)
                MCast_ReportPack(m_entry, m_entry->MulticastRouterVersion, 1, ((void *)0), 2, ((void *)0), ((void *)0));

        while (m_entry->member)
                MCast_RemoveMember(m_entry, m_entry->member);

        MCast_SourceList_freeAll(m_entry->slist);

        _rtl8651_del_timer(&m_entry->timer_upstream);
        MCast_EntryUnlink(m_entry);
        MCast_free(m_entry);

        rtl8651_MCastEntryCnt --;
        rtlglue_drvMutexUnlock();




}


void MCast_Entrylink(rtl8651_tblDrvMCast_t *entry)
{
        rtlglue_drvMutexLock();
        entry->next = rtl8651_MCastTable;
        if (rtl8651_MCastTable)
                rtl8651_MCastTable->prev = entry;
        rtl8651_MCastTable = entry;
        rtlglue_drvMutexUnlock();
}

void MCast_EntryUnlink(rtl8651_tblDrvMCast_t *entry)
{
        rtlglue_drvMutexLock();
        if (rtl8651_MCastTable == entry)
                rtl8651_MCastTable = entry->next;
        if (entry->next)
                entry->next->prev = entry->prev;
        if (entry->prev)
                entry->prev->next = entry->next;
        entry->prev = ((void *)0);
        entry->next = ((void *)0);
        rtlglue_drvMutexUnlock();
}


rtl8651_tblDrvMCastMember_t *MCast_FindMember(rtl8651_tblDrvMCast_t *m_entry, rtl8651_tblDrv_vlanTable_t *vlan, uint16 port, uint8 create, uint8 refresh, uint8 ModifyDataFlow)
{
        rtl8651_tblDrvMCastMember_t *member = m_entry->member;
        uint16 portMask = (1<<port);

        while (member)
        {
                if ((member->vlan == vlan) &&
                        (member->portMask == portMask))
                {
                        if (refresh == 1)
                        {
                                uint8 oldState = member->state;
                                member->state = 1;


                                _rtl8651_mod_timer(&(member->timer_state), _sysUpSeconds + rtl8651_drvMCastMember_ExpireTime);
                                member->timer_state.data = (uint32)member;
                                member->timer_state.function =(void*)MCast_MemberExpire;


                                _rtl8651_mod_timer(&(member->timer_query), _sysUpSeconds + rtl8651_igmp_group_query_interval);
                                member->timer_query.data = (uint32)member;
                                member->timer_query.function = (void*)MCast_MemberSendQuery;


                                _rtl8651_del_timer(&(member->timer_query_expire));


                                if ((oldState != 1) && (rtl8651_multicastProcessOptions & 0x00000001))
                                {




                                        _rtl8651_addMulticastMember(m_entry->mcast_addr, (1<<((member->vlan->vid)&(8 -1))), member->portMask, 0);
                                }

                        }
                        return member;
                }
                member = member->next;
        }
        if (create == 1)

                return MCast_CreateMember(m_entry, vlan, portMask, ModifyDataFlow);
        else
                return ((void *)0);
}

rtl8651_tblDrvMCastMember_t *MCast_CreateMember(rtl8651_tblDrvMCast_t *m_entry, rtl8651_tblDrv_vlanTable_t *vlan, uint16 portMask, uint8 ModifyDataFlow)
{
        rtl8651_tblDrvMCastMember_t *member;





        rtlglue_drvMutexLock();

        if ((!m_entry) ||
                ((rtl8651_drvMaxMCastMemberCnt)&&(m_entry->memberCnt >= rtl8651_drvMaxMCastMemberCnt)) ||
                ((rtl8651_drvMaxTotalMemberCnt)&&(rtl8651_MemberCnt >= rtl8651_drvMaxTotalMemberCnt)))
                goto errout;

        if ((member = (rtl8651_tblDrvMCastMember_t *)MCast_malloc(sizeof(rtl8651_tblDrvMCastMember_t))) == ((void *)0))
                goto errout;


        member->MulticastRouterVersion = rtl8651_drvMCastVersion;
        member->vlan = vlan;
        member->state = 1;
        member->isForwarder = 1;

        member->next = ((void *)0);
        member->prev = ((void *)0);

        member->portMask = portMask;

        member->FilterMode = 0;
        member->slist = ((void *)0);


        MCast_MemberLink(m_entry, member);


        _rtl8651_init_timer(&member->timer_state);
        member->timer_state.data = (uint32) member;
        member->timer_state.function = (void*)MCast_MemberExpire;
        _rtl8651_mod_timer(&member->timer_state, _sysUpSeconds + rtl8651_drvMCastMember_ExpireTime);

        _rtl8651_init_timer(&member->timer_query);
        member->timer_query.data = (uint32) member;
        member->timer_query.function = (void*)MCast_MemberSendQuery;
        _rtl8651_mod_timer(&member->timer_query, _sysUpSeconds + rtl8651_igmp_group_query_interval);

        _rtl8651_init_timer(&member->timer_filterMode);
        member->timer_filterMode.data = (uint32)member;
        member->timer_filterMode.function = (void*)MCast_MemberExcludeExpire;
        _rtl8651_mod_timer(&member->timer_filterMode, _sysUpSeconds + rtl8651_igmp_gmi);


        _rtl8651_init_timer(&(member->timer_query_expire));
        member->timer_query_expire.data = (uint32) member;
        member->timer_query_expire.function = (void*)MCast_MemberExpire;



        m_entry->memberCnt ++;






        rtl8651_MemberCnt ++;

        if (ModifyDataFlow == 1)
        {




        _rtl8651_addMulticastMember(m_entry->mcast_addr, (1<<((member->vlan->vid)&(8 -1))), member->portMask, 0);
        }

        rtlglue_drvMutexUnlock();
        return member;
errout:
        rtlglue_drvMutexUnlock();
        return ((void *)0);
}

void MCast_RemoveMember(rtl8651_tblDrvMCast_t *m_entry, rtl8651_tblDrvMCastMember_t *member)
{
# 1303 "rtl8651_multicast.c"
        rtlglue_drvMutexLock();

        _rtl8651_delMulticast(m_entry->mcast_addr, (1<<((member->vlan->vid)&(8 -1))), member->portMask);


        _rtl8651_del_timer(&member->timer_filterMode);
        _rtl8651_del_timer(&member->timer_state);
        _rtl8651_del_timer(&member->timer_query);
        _rtl8651_del_timer(&member->timer_query_expire);

        MCast_MemberUnLink(member);


        MCast_SourceList_freeAll(member->slist);

        MCast_free(member);


        m_entry->memberCnt --;
        rtl8651_MemberCnt --;

        rtlglue_drvMutexUnlock();




}

void MCast_DestroyMember(rtl8651_tblDrvMCastMember_t *member)
{
        rtl8651_tblDrvMCast_t *m_entry;

        rtlglue_drvMutexLock();

        m_entry = member->m_entry;





        MCast_RemoveMember(m_entry, member);
        if (m_entry->memberCnt == 0)
                MCast_RemoveMCastEntry(m_entry);

        rtlglue_drvMutexUnlock();
}

void MCast_MemberLink(rtl8651_tblDrvMCast_t *m_entry, rtl8651_tblDrvMCastMember_t *member)
{
        rtlglue_drvMutexLock();
        member->m_entry = m_entry;
        if (m_entry->member)
        {
                member->next = m_entry->member;
                m_entry->member->prev = member;
        }
        m_entry->member = member;
        rtlglue_drvMutexUnlock();
}

int32 MCast_MemberUnLink(rtl8651_tblDrvMCastMember_t *member)
{
        rtl8651_tblDrvMCast_t *m_entry;

        rtlglue_drvMutexLock();
        m_entry = member->m_entry;
        if (!m_entry)
                goto errout;

        if (m_entry->member == member)
                m_entry->member = member->next;
        if (member->next)
                member->next->prev = member->prev;
        if (member->prev)
                member->prev->next = member->next;

        member->m_entry = ((void *)0);
        member->prev = ((void *)0);
        member->next = ((void *)0);

        rtlglue_drvMutexUnlock();
        return 0;
errout:
        rtlglue_drvMutexUnlock();
        return -1;
}







void MCast_MemberExcludeExpire(uint32 expire)
{
        rtl8651_tblDrvMCastMember_t *member = (rtl8651_tblDrvMCastMember_t *)expire;





        if (member->FilterMode == 1)
        {
                rtl8651_tblDrvMCastSource_t *ptr;
                member->FilterMode = 2;
                ptr = member->slist;
                while (ptr)
                {
                        if (ptr->timer.expires <= _sysUpSeconds)
                                ptr = MCast_SourceList_freeCurrent(ptr);
                        else
                                ptr = ptr->next;
                }
                if (member->MulticastRouterVersion == 3)
                {
                        _rtl8651_delMulticast(member->m_entry->mcast_addr, 0, 0);
                        if (!member->slist)
                                MCast_MemberExpire((uint32)member);
                }
        }





}






void MCast_MemberExpire(uint32 expire)
{
        rtl8651_tblDrvMCastMember_t *member = (rtl8651_tblDrvMCastMember_t *)expire;





        member->state = 2;
        member->remainingQuery = rtl8651_igmp_lmqc;


        _rtl8651_del_timer(&(member->timer_query_expire));

        if (!member->remainingQuery)
        {
                MCast_DestroyMember(member);
                return;
        }


        if (rtl8651_multicastProcessOptions & 0x00000001)
        {




                _rtl8651_delMulticast(member->m_entry->mcast_addr, (1<<((member->vlan->vid)&(8 -1))), member->portMask);
        }



        member->timer_state.data = (uint32) member;
        member->timer_state.function = (void*)MCast_DestroyMember;
        _rtl8651_mod_timer(&member->timer_state, _sysUpSeconds + (((rtl8651_igmp_lmqc - 1) * rtl8651_igmp_lmqi) + rtl8651_igmp_qri + rtl8651_igmp_response_tolerance_delay));

        if (member->isForwarder == 1)
                MCast_MemberSendQuery(member);
}

void MCast_MemberSendQuery(rtl8651_tblDrvMCastMember_t *member)
{
        uint32 expire_time;






        member->isForwarder = 1;

        if (member->state == 1)
        {
                expire_time = rtl8651_igmp_group_query_interval;

                _rtl8651_mod_timer(&(member->timer_query_expire), _sysUpSeconds + rtl8651_igmp_qri + rtl8651_igmp_response_tolerance_delay);
                member->timer_query_expire.data = (uint32)member;
                member->timer_query_expire.function = (void*)MCast_MemberExpire;
        }else
        {
                if (!member->remainingQuery)
                        return;
                expire_time = rtl8651_igmp_lmqi;
                member->remainingQuery --;
        }


        member->timer_query.data = (uint32)member;
        member->timer_query.function = (void*)MCast_MemberSendQuery;
        _rtl8651_mod_timer(&member->timer_query, _sysUpSeconds + expire_time);


        if ((_sysUpSeconds + rtl8651_igmp_qri + rtl8651_igmp_response_tolerance_delay) > (member->timer_state.expires))
                _rtl8651_mod_timer(&member->timer_state, _sysUpSeconds + rtl8651_igmp_qri + rtl8651_igmp_response_tolerance_delay);


        if (member->MulticastRouterVersion == 1)
        {
                rtl8651_tblDrvMCastRouteInfo_t info;

                info.netif = ((void *)0);
                info.ifInfo = 0;
                info.m_addr = (0xE0000001L);
                info.netif = ((void *)0);
                info.ifInfo = 0;
                info.vlan = member->vlan;
                info.port = member->portMask;
                info.isPortMask= 1;

                MCast_QueryPack(((void *)0), &info, 1, ((void *)0), 0, ((void *)0));
        }else

                MCast_QueryPack(member, ((void *)0), member->MulticastRouterVersion, ((void *)0), 0, ((void *)0));
}





rtl8651_tblDrvMCastSource_t *MCast_SourceList_Create()
{
        rtl8651_tblDrvMCastSource_t *ret = ((void *)0);
        if ((ret = MCast_malloc(sizeof(rtl8651_tblDrvMCastSource_t))) == ((void *)0))
                return ((void *)0);
        _rtl8651_init_timer(&ret->timer);
        ret->timer.data = (uint32)ret;
        ret->timer.function = (void*)MCast_SourceList_Expire;
        rtl8651_SourceListCnt ++;

        return ret;
}

void MCast_SourceList_Link(rtl8651_tblDrvMCast_t *m_entry, rtl8651_tblDrvMCastMember_t *member, rtl8651_tblDrvMCastSource_t *src)
{
        rtl8651_tblDrvMCastSource_t **listpp;
        if ((!src) || (m_entry && member) || (!m_entry && !member))
                return;

        if (m_entry)
                listpp = &m_entry->slist;
        else
        {
                listpp = &member->slist;
                src->mbr = member;
        }

        src->prev = ((void *)0);
        src->next = (*listpp);
        if (*listpp)
                (*listpp)->prev = src;
        *listpp = src;
}


void MCast_SourceList_UnLink(rtl8651_tblDrvMCastSource_t *src)
{
        if (src->next)
                src->next->prev = src->prev;
        if (src->prev)
                src->prev->next = src->next;
        if (src->mbr && (src->mbr->slist == src))
                src->mbr->slist = src->next;

        src->prev = ((void *)0);
        src->next = ((void *)0);
}

rtl8651_tblDrvMCastSource_t* MCast_SourceList_inList(ipaddr_t addr, rtl8651_tblDrvMCastSource_t *slist)
{
        rtl8651_tblDrvMCastSource_t *ptr = slist;

        if (!ptr)
                return ptr;

        while (ptr)
        {
                if (ptr->source == addr)
                        return ptr;
                ptr = ptr->next;
        }

        return ((void *)0);
}


uint32 MCast_SourceList_EntryCnt(rtl8651_tblDrvMCastSource_t *slist)
{
        rtl8651_tblDrvMCastSource_t *ptr = slist;
        uint32 cnt = 0;

        while (ptr)
        {
                cnt ++;
                ptr = ptr->next;
        }

        return cnt;
}



rtl8651_tblDrvMCastSource_t *MCast_SourceList_freeCurrent(rtl8651_tblDrvMCastSource_t *s_entry)
{
        rtl8651_tblDrvMCastSource_t *ret;
        if (!s_entry)
                return ((void *)0);


        ret = s_entry->next;

        MCast_SourceList_UnLink(s_entry);
        _rtl8651_del_timer(&s_entry->timer);
        MCast_free(s_entry);
        rtl8651_SourceListCnt --;

        return ret;
}


void MCast_SourceList_freeAll(rtl8651_tblDrvMCastSource_t *slist)
{
        rtl8651_tblDrvMCastSource_t *ptr = slist;
        if (!ptr)
                return;

        while(ptr->prev)
                ptr = ptr->prev;

        if (ptr->mbr)
        {
                do {} while (0);
                ptr->mbr->slist = ((void *)0);
        }

        while (ptr)
                ptr = MCast_SourceList_freeCurrent(ptr);

        return;
}


uint32 MCast_SourceList_removal(
        rtl8651_tblDrvMCastSource_t *s1,
        uint8 s1constraint,
        uint8 s1action,
        rtl8651_tblDrvMCastSource_t *s2,
        uint8 s2constraint,
        uint8 newSrcAction,
        rtl8651_tblDrvMCastSource_t **removalResult)
{
        rtl8651_tblDrvMCastSource_t *tmp;
        rtl8651_tblDrvMCastSource_t *ptr = s1;
        rtl8651_tblDrvMCastSource_t *ret = ((void *)0);
        rtl8651_tblDrvMCastSource_t* newp = ((void *)0);
        uint32 count = 0;

        if (!ptr)
                goto out;

        while(ptr)
        {
                if (
                        ((s1constraint == 1) && (ptr->timer.expires <= _sysUpSeconds)) ||
                        ((s1constraint == 2) && (ptr->timer.expires > _sysUpSeconds))
                )
                        goto next_s1;
                if ((tmp = MCast_SourceList_inList(ptr->source, s2)) == ((void *)0))
                {
match:
                        if ((newp = MCast_SourceList_Create()) == ((void *)0))
                                goto out;

                        newp->next = ret;
                        if (ret)
                                ret->prev = newp;
                        ret = newp;

                        newp->source = ptr->source;
                        newp->mbr = ((void *)0);
                        _rtl8651_init_timer(&newp->timer);


                        if (s1action == 1)
                                _rtl8651_mod_timer(&ptr->timer, _sysUpSeconds + rtl8651_igmp_lmqt);

                        if (newSrcAction== 1)
                                _rtl8651_mod_timer(&newp->timer, _sysUpSeconds + rtl8651_igmp_lmqt);

                        count ++;
                }else
                {
                        if (
                                ((s2constraint == 1) && (tmp->timer.expires <= _sysUpSeconds)) ||
                                ((s2constraint == 2) && (tmp->timer.expires > _sysUpSeconds))
                                )
                                goto match;
                }
next_s1:
                ptr = ptr->next;
        }
out:
        *removalResult = ret;
        return count;
}




void MCast_SourceList_addList(rtl8651_tblDrvMCastMember_t *member, rtl8651_tblDrvMCastSource_t *add, uint8 refreshAdded, uint8 refreshExist)
{
        rtl8651_tblDrvMCastSource_t *tmp, *ptr = add;

        while(ptr)
        {
                if ((tmp = MCast_SourceList_inList(ptr->source, member->slist)) != ((void *)0))
                {
                        ptr = MCast_SourceList_freeCurrent(ptr);
                        if (refreshExist == 1)
                                _rtl8651_mod_timer(&tmp->timer, (_sysUpSeconds + rtl8651_igmp_gmi));
                }else
                {

                        tmp = ptr;
                        ptr = ptr->next;
                        MCast_SourceList_UnLink(tmp);
                        MCast_SourceList_Link(((void *)0), member, tmp);
                        if (refreshAdded == 1)
                                _rtl8651_mod_timer(&tmp->timer, (_sysUpSeconds + rtl8651_igmp_gmi));
                }
        }
}




int32 MCast_SourceList_dup(rtl8651_tblDrvMCastMember_t *member, rtl8651_tblDrvMCastSource_t *org, rtl8651_tblDrvMCastSource_t **dup)
{
        rtl8651_tblDrvMCastSource_t *ptr, *newp;

        if ((!org) || (!dup && !member) || (dup && member))
                return -1;

        if (dup)
                *dup = ((void *)0);

        ptr = org;

        while (ptr)
        {
                newp = MCast_SourceList_Create();
                if (!newp)
                        return -1;
                newp->source = ptr->source;
                if (member)
                        MCast_SourceList_addList(member, newp, 1, 1);
                else
                {
                        newp->next = *dup;
                        if (*dup)
                                (*dup)->prev = newp;
                        *dup = newp;
                }
                ptr = ptr->next;
        }
        return 0;
}




void MCast_SourceList_Expire(rtl8651_tblDrvMCastSource_t *s_entry)
{
        rtl8651_tblDrvMCastMember_t *mbr;
        if ((!s_entry) || (!s_entry->mbr))
                return;

        mbr = s_entry->mbr;

        if (mbr->FilterMode == 1)
        {
                if (mbr->MulticastRouterVersion == 3)
                        _rtl8651_delMulticast(mbr->m_entry->mcast_addr, 0, 0);
        }else if (mbr->FilterMode == 2)
        {

                MCast_SourceList_freeCurrent(s_entry);
                if (mbr->MulticastRouterVersion == 3)
                {

                        _rtl8651_delMulticast(mbr->m_entry->mcast_addr, 0, 0);

                        if (!mbr->slist)
                                MCast_MemberExpire((uint32)mbr);
                }
        }else
        {
                do {} while (0);
        }
}







uint32 MCast_SourceList_getCache(rtl8651_tblDrvMCast_t *m_entry, rtl8651_tblDrvMCastSource_t **newCache)
{
        rtl8651_tblDrvMCastMember_t *mptr, *firstmptr, *firstExcludeMember;
        uint8 mFilterMode = 0;
        uint8 allMemberNone;
        rtl8651_tblDrvMCastSource_t *ret = ((void *)0), *tmp, *tmp_2, *newp;

        if (!m_entry)
                goto list_add_done;

        do {} while (0);
        firstmptr = m_entry->member;

        firstExcludeMember = ((void *)0);
        allMemberNone = 1;
        mptr = firstmptr;
        while (mptr)
        {


                if ((mptr->FilterMode == 2) && (mptr->slist == ((void *)0)))
                        mptr->FilterMode = 1;

                if (mptr->FilterMode == 1)
                {
                        mFilterMode = 1;
                        if (!firstExcludeMember)
                                firstExcludeMember = mptr;
                }
                if (mptr->FilterMode != 0)
                        allMemberNone = 0;
                mptr = mptr->next;
        }
        if (allMemberNone == 1)
        {
                mFilterMode = 0;
                ret = ((void *)0);
                goto list_add_done;
        }

        if (mFilterMode == 0)
                mFilterMode = 2;


        ret = ((void *)0);
        if (mFilterMode == 2)
        {


                mptr = firstmptr;
                while (mptr)
                {
                        do {} while (0);
                        tmp = mptr->slist;
                        while (tmp)
                        {
                                if (!MCast_SourceList_inList(tmp->source, ret))
                                {
                                        if ((newp = MCast_SourceList_Create()) == ((void *)0))
                                                goto list_add_done;

                                        newp->source = tmp->source;
                                        newp->next = ret;
                                        if (ret)
                                                ret->prev = newp;
                                        ret = newp;
                                }
                                tmp = tmp->next;
                        }
                        mptr = mptr->next;
                }
        }else
        {
# 1903 "rtl8651_multicast.c"
                do {} while (0);
                tmp = firstExcludeMember->slist;
                while (tmp)
                {
                        if ((newp = MCast_SourceList_Create()) == ((void *)0))
                                goto list_init_done;

                        newp->source = tmp->source;
                        newp->next = ret;
                        if (ret)
                                ret->prev = newp;
                        ret = newp;

                        tmp = tmp->next;
                }
        list_init_done:

                mptr = m_entry->member;
                while (mptr)
                {
                        if (mptr->MulticastRouterVersion < 3)
                                goto ex_next_member;
                        if (!ret)
                                goto list_add_done;
                        if (mptr != firstExcludeMember)
                        {
                                if (mptr->FilterMode == 2)
                                {
                                        tmp = mptr->slist;
                                        while (tmp)
                                        {
                                                if ((tmp_2 = MCast_SourceList_inList(tmp->source, ret)) != ((void *)0))
                                                {
                                                        if (tmp_2 == ret)
                                                                ret = MCast_SourceList_freeCurrent(tmp_2);
                                                        else
                                                                MCast_SourceList_freeCurrent(tmp_2);
                                                }
                                                if (!ret)
                                                        goto list_add_done;

                                                tmp = tmp->next;
                                        }
                                }else
                                {
                                        tmp = ret;
                                        while (tmp)
                                        {
                                                if (!MCast_SourceList_inList(tmp->source, mptr->slist))
                                                {
                                                        if (tmp == ret)
                                                        {
                                                                ret = MCast_SourceList_freeCurrent(tmp);
                                                                tmp = ret;
                                                        } else
                                                                tmp = MCast_SourceList_freeCurrent(tmp);
                                                } else
                                                        tmp = tmp->next;
                                                if (!ret)
                                                        goto list_add_done;
                                        }
                                }
                        }
        ex_next_member:
                        mptr = mptr->next;
                }
        }
list_add_done:
        if (newCache)
                *newCache = ret;
        return mFilterMode;
}





ipaddr_t MCast_GetIpByVlan(rtl8651_tblDrv_vlanTable_t *vlanp, uint32 vid)
{
        rtl8651_tblDrv_networkIntfTable_t *netif;
        rtl8651_tblDrv_ipIntfEntry_t *ipIf;
        rtl8651_tblDrv_ipIntfIpAddrEntry_t *ipEntry;

        if (!vlanp && !vid)
        {
                return 0;
        }

        if (vid)
                netif = _rtl8651_getNetworkIntfEntryByVid(vid);
        else
                netif = _rtl8651_getNetworkIntfEntryByVid(vlanp->vid);

        if (netif)
        {
                for((ipIf) = (&netif->IpHead)->slh_first; (ipIf); (ipIf) = (ipIf)->nextIp.sle_next)
                {
                        for((ipEntry) = (&ipIf->ipAddr)->slh_first; (ipEntry); (ipEntry) = (ipEntry)->nextIpAddr.sle_next)
                        {
                                if (ipEntry->ipAddr)
                                        return (ipEntry->ipAddr);
                        }
                }
        }
        return 0;
}

void inline MCast_asicSetActualVlanPort(uint16 *pPortMask, uint32 *pVlanMask, rtl8651_tblDrv_networkIntfTable_t *netif, rtl8651_tblDrv_vlanTable_t* vlan, uint16 orgPortMask, uint32 intfInfo)
{
        do {} while (0);
        do {} while (0);

        switch (netif->linkLayerType) {

                case 0x05:
                case 0x06:
                {
                        rtl8651_tblDrv_pppTable_t *ptb;
                        do {} while (0);

                        ptb = ((rtl8651_tblDrvSession_t *)intfInfo)->session_t;

                        *pVlanMask = (ptb->initiated)?(1<<(tunnel.loopBackVid & (8 - 1))):0;
                        *pPortMask = (ptb->initiated)?(1<<0x7):0;
                }
                        break;

                default:
                        *pPortMask = orgPortMask;
                        *pVlanMask = 1<<(vlan->vid & (8 - 1));
        }
}


int32 MCast_SetRouteInfoAndGetIntfIp(ipaddr_t *gip, rtl8651_tblDrvMCastRouteInfo_t *info)
{
        ipaddr_t ip;

        do {} while (0);

        if ((!(info->netif)) &&
                ((info->netif = _rtl8651_getNetworkIntfEntryByVid(info->vlan->vid)) == ((void *)0)))
        {
                return -1;
        }
        switch (info->netif->linkLayerType)
        {
                case 0x01:
                                if (info->ifInfo)
                                {
                                        ip = info->ifInfo;
                                }else
                                {
                                        if (((&(info->netif->IpHead))->slh_first) == ((void *)0))
                                                return -1;
                                        if (((&(((&(info->netif->IpHead))->slh_first))->ipAddr)->slh_first) == ((void *)0))
                                                return -1;
                                        if ((((&(((&(info->netif->IpHead))->slh_first))->ipAddr)->slh_first))->ipAddr == 0)
                                                return -1;
                                        ip = info->ifInfo = ((&(((&(info->netif->IpHead))->slh_first)->ipAddr))->slh_first)->ipAddr;
                                }
                        break;
                case 0x02:

                case 0x05:
                case 0x06:

                                if (!info->ifInfo)
                                {
                                        if ((info->ifInfo = (uint32)(((&(info->netif->sessionHead))->tqh_first))) == 0)
                                        {
                                                return -1;
                                        }
                                }
                                if ((!((rtl8651_tblDrvSession_t*)(info->ifInfo))->ip_t) ||
                                        (!((rtl8651_tblDrvSession_t*)(info->ifInfo))->ip_t->ipAddr))
                                {
                                        return -1;
                                }
                                ip = ((rtl8651_tblDrvSession_t*)(info->ifInfo))->ip_t->ipAddr;
                        break;
                default:
                        return -1;
        }

        if (gip)
                *gip = ip;
        return 0;
}




void MCast_Proc_ISIN(
        rtl8651_tblDrvMCastMember_t *member,
        rtl8651_tblDrvMCastSource_t *slist,
        uint16 srcCnt,
        uint8 sendQ
)
{


        MCast_SourceList_addList(member, slist, 1, 1);
}

static inline void MCast_Proc_ISEX(
        rtl8651_tblDrvMCastMember_t *member,
        rtl8651_tblDrvMCastSource_t *slist,
        uint16 srcCnt,
        uint8 sendQ
)
{
        rtl8651_tblDrvMCastSource_t *ptr, *tmp;


        if (member->FilterMode == 2)
        {

                ptr = member->slist;
                while(ptr)
                {
                        if (!MCast_SourceList_inList(ptr->source, slist))
                                ptr = MCast_SourceList_freeCurrent(ptr);
                        else
                                ptr = ptr->next;
                }

                ptr = slist;
                while(ptr)
                {
                        if (!MCast_SourceList_inList(ptr->source, member->slist))
                        {
                                tmp = ptr->next;
                                MCast_SourceList_UnLink(ptr);
                                MCast_SourceList_Link(((void *)0), member, ptr);
                                _rtl8651_del_timer(&ptr->timer);
                                ptr->timer.expires = _sysUpSeconds;
                                ptr = tmp;
                        }else
                        {
                                ptr = MCast_SourceList_freeCurrent(ptr);
                        }
                }
        }else
        {

                ptr = member->slist;
                while(ptr)
                {
                        if (!MCast_SourceList_inList(ptr->source, slist))
                                ptr = MCast_SourceList_freeCurrent(ptr);
                        else
                                ptr = ptr->next;
                }

                MCast_SourceList_addList(member, slist, 1, 0);
        }
        member->FilterMode = 1;
        _rtl8651_mod_timer(&member->timer_filterMode, (_sysUpSeconds + rtl8651_igmp_gmi));
}

static inline void MCast_Proc_TOIN(
        rtl8651_tblDrvMCastMember_t *member,
        rtl8651_tblDrvMCastSource_t *slist,
        uint16 srcCnt,
        uint8 sendQ
)
{
        rtl8651_tblDrvMCastSource_t *sendQsrc = ((void *)0);
        uint32 sendQsrcCnt = 0;




        if (member->FilterMode == 2)
                sendQsrcCnt = MCast_SourceList_removal(member->slist, 0, 1, slist, 0, 0, &sendQsrc);
        else
                sendQsrcCnt = MCast_SourceList_removal(member->slist, 1, 1, slist, 0, 0, &sendQsrc);

        MCast_SourceList_addList(member, slist, 1, 1);
        if (sendQ == 1)
        {
                if (member->FilterMode == 2)
                {
                        if (sendQsrcCnt)
                                MCast_QueryPack(member, ((void *)0), member->MulticastRouterVersion, sendQsrc, sendQsrcCnt, ((void *)0));
                }else
                {
                        if (sendQsrcCnt > 0)
                                MCast_QueryPack(member, ((void *)0), member->MulticastRouterVersion, sendQsrc, sendQsrcCnt, ((void *)0));

                        MCast_MemberExpire((uint32)member);
                }
        }

        MCast_SourceList_freeAll(sendQsrc);
}

static inline void MCast_Proc_TOEX(
        rtl8651_tblDrvMCastMember_t *member,
        rtl8651_tblDrvMCastSource_t *slist,
        uint16 srcCnt,
        uint8 sendQ
)
{
        rtl8651_tblDrvMCastSource_t *ptr;
        rtl8651_tblDrvMCastSource_t *sendQsrc = ((void *)0);
        uint32 sendQsrcCnt = 0;



        if (member->FilterMode == 2)
        {

                ptr = member->slist;
                while(ptr)
                {
                        if (!MCast_SourceList_inList(ptr->source, slist))
                                ptr = MCast_SourceList_freeCurrent(ptr);
                        else
                                ptr = ptr->next;
                }

                sendQsrcCnt = 0;
                ptr = member->slist;
                while (ptr)
                {
                        _rtl8651_mod_timer(&ptr->timer, (_sysUpSeconds + rtl8651_igmp_lmqt));
                        sendQsrcCnt ++;
                        ptr = ptr->next;
                }
                if ((sendQ == 1) && (sendQsrcCnt > 0))
                        MCast_QueryPack(member, ((void *)0), member->MulticastRouterVersion, member->slist, sendQsrcCnt, ((void *)0));

                MCast_SourceList_addList(member, slist, 0, 0);

                member->FilterMode = 1;
                _rtl8651_mod_timer(&member->timer_filterMode, (_sysUpSeconds + rtl8651_igmp_gmi));
        }else
        {

                ptr = member->slist;
                while(ptr)
                {
                        if (!MCast_SourceList_inList(ptr->source, slist))
                                ptr = MCast_SourceList_freeCurrent(ptr);
                        else
                                ptr = ptr->next;
                }


                sendQsrcCnt = MCast_SourceList_removal(slist, 0, 0, member->slist, 2, 0, &sendQsrc);
                if ((sendQ == 1) && (sendQsrcCnt > 0))
                {
                        MCast_QueryPack(member, ((void *)0), member->MulticastRouterVersion, sendQsrc, sendQsrcCnt, ((void *)0));
                        MCast_SourceList_freeAll(sendQsrc);
                }

                ptr = member->slist;
                while (ptr)
                {
                        if (ptr->timer.expires <= _sysUpSeconds)
                                goto next_ptr;
                        if (MCast_SourceList_inList(ptr->source, slist))
                                _rtl8651_mod_timer(&ptr->timer, (_sysUpSeconds * rtl8651_igmp_lmqt));
                        next_ptr:
                                ptr = ptr->next;
                }

                ptr = slist;
                while(ptr)
                {
                        if (MCast_SourceList_inList(ptr->source, member->slist))
                        {
                                ptr = MCast_SourceList_freeCurrent(ptr);
                        }else
                        {
                                rtl8651_tblDrvMCastSource_t *tmp;
                                tmp = ptr->next;
                                MCast_SourceList_UnLink(ptr);
                                MCast_SourceList_Link(((void *)0), member, ptr);
                                if (member->timer_filterMode.expires > _sysUpSeconds)
                                        _rtl8651_mod_timer(&ptr->timer, (member->timer_filterMode.expires));
                                else
                                        _rtl8651_mod_timer(&ptr->timer, (_sysUpSeconds + 1));
                                ptr = tmp;
                        }
                }

                _rtl8651_mod_timer(&member->timer_filterMode, (_sysUpSeconds + rtl8651_igmp_gmi));
        }
}

static inline void MCast_Proc_ALLOW(
        rtl8651_tblDrvMCastMember_t *member,
        rtl8651_tblDrvMCastSource_t *slist,
        uint16 srcCnt,
        uint8 sendQ
)
{


        MCast_SourceList_addList(member, slist, 1, 1);
}

static inline void MCast_Proc_BLOCK(
        rtl8651_tblDrvMCastMember_t *member,
        rtl8651_tblDrvMCastSource_t *slist,
        uint16 srcCnt,
        uint8 sendQ
)
{
        rtl8651_tblDrvMCastSource_t *slistP = slist;
        rtl8651_tblDrvMCastSource_t *ptr, *tmp;
        rtl8651_tblDrvMCastSource_t *sendQsrc = ((void *)0);
        uint32 sendQsrcCnt = 0;



        if (member->FilterMode == 2)
        {
                ptr = member->slist;
                sendQsrcCnt = 0;
                sendQsrc = ((void *)0);
                while (ptr)
                {
                        if ((tmp = MCast_SourceList_inList(ptr->source, slistP)) != ((void *)0))
                        {
                                if (slistP == tmp)
                                        slistP = tmp->next;
                                MCast_SourceList_UnLink(tmp);
                                tmp->next = sendQsrc;
                                if (sendQsrc)
                                        sendQsrc->prev = tmp;
                                sendQsrc = tmp;
                                sendQsrcCnt ++;

                                _rtl8651_mod_timer(&ptr->timer, (_sysUpSeconds + rtl8651_igmp_lmqt));
                        }
                        ptr = ptr->next;
                }
                if ((sendQ == 1) && (sendQsrcCnt > 0))
                        MCast_QueryPack(member, ((void *)0), member->MulticastRouterVersion, sendQsrc, sendQsrcCnt, ((void *)0));

                MCast_SourceList_freeAll(slistP);
                if (sendQsrcCnt > 0)
                        MCast_SourceList_freeAll(sendQsrc);
        }else
        {


                sendQsrcCnt = MCast_SourceList_removal(slist, 0, 0, member->slist, 2, 0, &sendQsrc);
                if ((sendQ == 1) && (sendQsrcCnt>0))
                        MCast_QueryPack(member, ((void *)0), member->MulticastRouterVersion, sendQsrc, sendQsrcCnt, ((void *)0));

                if (sendQsrcCnt > 0)
                MCast_SourceList_freeAll(sendQsrc);

                ptr = slist;
                while (ptr)
                {
                        if (MCast_SourceList_inList(ptr->source, member->slist))
                                ptr = MCast_SourceList_freeCurrent(ptr);
                        else
                        {
                                tmp = ptr->next;
                                MCast_SourceList_UnLink(ptr);
                                MCast_SourceList_Link(((void *)0), member, ptr);
                                if (member->timer_filterMode.expires > _sysUpSeconds)
                                        _rtl8651_mod_timer(&ptr->timer, (member->timer_filterMode.expires));
                                else
                                        _rtl8651_mod_timer(&ptr->timer, (_sysUpSeconds + 1));
                                ptr = tmp;
                        }
                }
        }
}







uint32 MCast_ProcessGroupRecord(
        rtl8651_tblDrvMCast_t *m_entry,
        rtl8651_tblDrvMCastMember_t *member,
        uint8 RecordType,
        rtl8651_tblDrvMCastSource_t *slist,
        uint16 srcCnt,
        uint8 sendQ,
        rtl8651_tblDrvMCastSource_t **newCache)
{
        uint8 mFilterMode = 1;

        if (newCache)
                *newCache = ((void *)0);

        if ((!m_entry) || (!member))
                goto out;

        if (member->FilterMode == 0)
        {
                MCast_SourceList_freeAll(member->slist);
                MCast_SourceList_dup(member, slist, ((void *)0));
                switch (RecordType)
                {
                        case 1:
                        case 3:
                        case 5:
                                member->FilterMode = 2;
                                break;
                        case 2:
                        case 4:
                        case 6:
                                member->FilterMode = 1;
                                break;
                }
        }

        switch (RecordType)
        {
                case 1:
                        MCast_Proc_ISIN(member, slist, srcCnt, sendQ);
                        break;
                case 2:
                        MCast_Proc_ISEX(member, slist, srcCnt, sendQ);
                        break;
                case 3:
                        MCast_Proc_TOIN(member, slist, srcCnt, sendQ);
                        break;
                case 4:
                        MCast_Proc_TOEX(member, slist, srcCnt, sendQ);
                        break;
                case 5:
                        MCast_Proc_ALLOW(member, slist, srcCnt, sendQ);
                        break;
                case 6:
                        MCast_Proc_BLOCK(member, slist, srcCnt, sendQ);
                        break;
                default:
                        goto out;
        }


        mFilterMode = MCast_SourceList_getCache(m_entry, newCache);
out:
        return mFilterMode;
}


int32 MCast_query(struct rtl_pktHdr *pkthdr, struct ip *ip, struct igmp *ig)
{
        uint16 igmp_length = 0;
        uint8 version = 0;
        ipaddr_t dip = 0;
        ipaddr_t mcast_addr = 0;
        rtl8651_tblDrvMCast_t * m_entry;
        rtl8651_tblDrvMCastMember_t * member;
        rtl8651_tblDrv_vlanTable_t * vlanp = &DrvTbl.vlan[pkthdr->ph_vlanIdx & (8 - 1)];
        uint8 keep_pkt = 0;
# 2472 "rtl8651_multicast.c"
        igmp_length = (ip->ip_len) - ((ip->ip_vhl&0xf)<<2);

        if (igmp_length == 8)
        {
                if (ig->igmp_code)
                        version = 2;
                else
                        version = 1;
        }else if (igmp_length >= 12)
                version = 3;
        else
                goto errout;


        mcast_addr = ((uint32) (*((uint8*)(&ig->grp.group))<<24)|(*(((uint8*)(&ig->grp.group))+1)<<16)|(*(((uint8*)(&ig->grp.group))+2)<<8) | *(((uint8*)(&ig->grp.group))+3));


        {
                rtl8651_tblDrvMCastFilter_t *filter;
                filter = _rtl8651_multicast_FindFilter(mcast_addr);
                if (filter)
                {
                        switch (filter->action)
                        {
                                case ((1<<0)|(1<<1)):

                                        goto errout;
                                        break;
                                case ((1<<0)):

                                        keep_pkt = 1;
                                        break;
                                case ((1<<1)):

                                        goto freeout;
                                        break;
                        }
                }
        }

        if (!((((ipaddr_t)(mcast_addr)) & 0xf0000000) == 0xe0000000))
        {



                dip = ((uint32) (*((uint8*)(&ip->ip_dst))<<24)|(*(((uint8*)(&ip->ip_dst))+1)<<16)|(*(((uint8*)(&ip->ip_dst))+2)<<8) | *(((uint8*)(&ip->ip_dst))+3));
                if (dip == (0xE0000001L))
                {



                        goto GeneralQuery;
                }else
                {
                        goto errout;
                }
        }

        if (((((ipaddr_t)(mcast_addr)) & (0xFFFFFF00L)) == 0xe0000000))
                goto errout;
# 2541 "rtl8651_multicast.c"
        if ((m_entry = MCast_FindMCastEntry(mcast_addr, 0, 1)) == ((void *)0))
                goto freeout;

        if ((m_entry->up_vlan) &&
                ((m_entry->up_vlan != vlanp) || (m_entry->up_portMask != (1<<pkthdr->ph_portlist))))
        {
                member = MCast_FindMember(m_entry, vlanp, pkthdr->ph_portlist, 0, 0, 0);
                if (member)
                {
                        ipaddr_t sip;

                        sip = ((uint32) (*((uint8*)(&ip->ip_src))<<24)|(*(((uint8*)(&ip->ip_src))+1)<<16)|(*(((uint8*)(&ip->ip_src))+2)<<8) | *(((uint8*)(&ip->ip_src))+3));

                        if (sip && (MCast_GetIpByVlan(member->vlan, 0) > sip) && rtl8651_igmp_oqpi)
                        {
                                member->isForwarder = 0;

                                member->timer_query.data = (uint32)member;
                                member->timer_query.function = (void*)MCast_MemberSendQuery;
                                _rtl8651_mod_timer(&member->timer_query, _sysUpSeconds + rtl8651_igmp_oqpi);
                        }

                        member->MulticastRouterVersion = version;
                }
                goto freeout;
        }else
        {
                uint8 ver;

                member = MCast_FindMember(m_entry, vlanp, pkthdr->ph_portlist, 0, 0, 0);
                if (member)
                {
                        MCast_RemoveMember(m_entry, member);
                        if (m_entry->memberCnt == 0)
                        {
                                MCast_RemoveMCastEntry(m_entry);
                                goto freeout;
                        }
                }

                MCast_SetMCastEntryUpStream(m_entry, vlanp, pkthdr->ph_portlist, version);
                if (version >= 3)
                {
                        MCast_SourceList_freeAll(m_entry->slist);
                        m_entry->FilterMode = MCast_SourceList_getCache(m_entry, &(m_entry->slist));
                }

                ver = MCast_MCastEntryMinVersion(m_entry);
                if (ver < 3)
                        MCast_ReportPack(m_entry, version, 0, ((void *)0), 1, ((void *)0), ((keep_pkt == 1)?((void *)0):pkthdr));
                else
                        MCast_ReportPack(m_entry, version, 0, ((void *)0), m_entry->FilterMode, m_entry->slist, ((keep_pkt == 1)?((void *)0):pkthdr));
        }
        goto out;




GeneralQuery:
        {
                struct rtl_pktHdr *pkt = pkthdr;
                uint8 proc_entry = 1;
                uint16 portlist = pkthdr->ph_portlist;
                uint8 memberVersion = rtl8651_drvMCastVersion;




                if ((rtl8651_GlobalVariable.MCastUpStream.isSet == 1) &&
                        ((rtl8651_GlobalVariable.MCastUpStream.vlan != vlanp) ||
                        (!(rtl8651_GlobalVariable.MCastUpStream.portMask & (1<<pkt->ph_portlist)))))
                        goto freeout;

                m_entry = rtl8651_MCastTable;
                while (m_entry)
                {



                        proc_entry = 1;
                        if ((!m_entry->up_vlan) ||
                                ((m_entry->up_vlan) && (m_entry->up_vlan == vlanp) && (m_entry->up_portMask == (1<<portlist))))
                        {
                                if (!m_entry->up_vlan)
                                {
                                        member = MCast_FindMember(m_entry, vlanp, portlist, 0, 0, 0);
                                        if (member)
                                        {
                                                MCast_RemoveMember(m_entry, member);
                                                if (m_entry->memberCnt == 0)
                                                {
                                                        rtl8651_tblDrvMCast_t *next = m_entry->next;
                                                        MCast_RemoveMCastEntry(m_entry);
                                                        m_entry = next;
                                                        proc_entry = 0;
                                                }
                                        }
                                }
                                if (proc_entry == 1)
                                {




                                        MCast_SetMCastEntryUpStream(m_entry, vlanp, portlist, version);

                                        memberVersion = MCast_MCastEntryMinVersion(m_entry);
                                        if ((memberVersion >= 3) && (version >= 3))
                                        {
                                                MCast_SourceList_freeAll(m_entry->slist);
                                                m_entry->FilterMode = MCast_SourceList_getCache(m_entry, &(m_entry->slist));
                                        }

                                        if (pkt && (keep_pkt == 0))
                                        {
                                                if (memberVersion < 3)
                                                        MCast_ReportPack(m_entry, version, 0, ((void *)0), 1, ((void *)0), pkt);
                                                else
                                                        MCast_ReportPack(m_entry, version, 0, ((void *)0), m_entry->FilterMode, m_entry->slist, pkt);
                                                pkt = ((void *)0);
                                        }else
                                        {
                                                if (memberVersion < 3)
                                                        MCast_ReportPack(m_entry, version, 0, ((void *)0), 1, ((void *)0), ((void *)0));
                                                else
                                                        MCast_ReportPack(m_entry, version, 0, ((void *)0), m_entry->FilterMode, m_entry->slist, ((void *)0));
                                        }
                                }
                        }
                        if (proc_entry == 1)
                        {

                                if ((rtl8651_drvMCastUpstream_Timeout != 0xffffffff) && (m_entry->up_vlan))
                                        _rtl8651_mod_timer(&m_entry->timer_upstream, _sysUpSeconds + rtl8651_drvMCastUpstream_Timeout);

                                m_entry = m_entry->next;
                        }
                }

                if (pkt && (keep_pkt == 0))
                        mBuf_freeMbufChain(pkt->PKTHDRNXT.mbuf_first);
        }
out:
        if (keep_pkt == 1)
                return 32;
        return 0;
freeout:
        if (keep_pkt == 1)
                return 32;

        mBuf_freeMbufChain(pkthdr->PKTHDRNXT.mbuf_first);
        return 0;
errout:


        return 32;
}






int32 MCast_report(struct rtl_pktHdr *pkthdr, struct ip *ip, struct igmp *ig)
{
        ipaddr_t mcast_addr;
        uint8 version;
        rtl8651_tblDrvMCast_t * m_entry;
        rtl8651_tblDrvMCastMember_t * member;
        rtl8651_tblDrv_vlanTable_t * vlanp = &DrvTbl.vlan[pkthdr->ph_vlanIdx & (8 - 1)];
        uint16 portlist = pkthdr->ph_portlist;
        uint8 keep_pkt = 0;

        uint32 l4Len = 0;
        uint32 l4ClaimLen = (ip->ip_len) - ((*(uint8*)ip&0xf) << 2);
        struct igmp_gr * gr = ((void *)0);
        int32 LoopCnt = 0;
        uint8 mirrorThis = 0;

        rtl8651_tblDrvMCastSource_t * slist;
        uint16 srcCnt;
        uint8 RecordType;
        uint8 newFilterMode = 1;
        rtl8651_tblDrvMCastSource_t * newSlist = ((void *)0);



        if (!vlanp->internal)
                goto freeout;

        switch (ig->igmp_type)
        {
                case 0x12:
                        version = 1;
                        break;
                case 0x16:
                        version = 2;
                        break;
                case 0x22:
                        version = 3;
                        break;
                default:

                        goto errout;
        }





        if (version >= 3)
        {
                LoopCnt = (ig->grp.v3_report.nofg);
                gr = &(ig->un_v3.report.gr_list);
        }else
                LoopCnt = 1;

        l4Len = 0;
        keep_pkt = 0;

        while (LoopCnt > 0)
        {
                if (version < 3)
                        mcast_addr = ((uint32) (*((uint8*)(&ig->grp.group))<<24)|(*(((uint8*)(&ig->grp.group))+1)<<16)|(*(((uint8*)(&ig->grp.group))+2)<<8) | *(((uint8*)(&ig->grp.group))+3));
                else
                        mcast_addr = ((uint32) (*((uint8*)(&gr->igmp_gr_group))<<24)|(*(((uint8*)(&gr->igmp_gr_group))+1)<<16)|(*(((uint8*)(&gr->igmp_gr_group))+2)<<8) | *(((uint8*)(&gr->igmp_gr_group))+3));


                mirrorThis = 0;
                {
                        rtl8651_tblDrvMCastFilter_t *filter;
                        filter = _rtl8651_multicast_FindFilter(mcast_addr);
                        if (filter)
                        {
                                switch (filter->action)
                                {
                                        case ((1<<0)|(1<<1)):

                                                keep_pkt = 1;
                                                mirrorThis = 1;
                                                goto next_loop;
                                                break;
                                        case ((1<<0)):

                                                keep_pkt = 1;
                                                mirrorThis = 1;
                                                break;
                                        case ((1<<1)):

                                                goto next_loop;
                                                break;
                                }
                        }
                }


                if ((!((((ipaddr_t)(mcast_addr)) & 0xf0000000) == 0xe0000000)) || ((((ipaddr_t)(mcast_addr)) & (0xFFFFFF00L)) == 0xe0000000))
                {
                        keep_pkt = 1;
                        goto next_loop;
                }

                if ((m_entry = MCast_FindMCastEntry(mcast_addr, 1, 0)) == ((void *)0))
                        goto next_loop;

                if ((m_entry->up_vlan == vlanp) &&
                        (m_entry->up_portMask == (1<<portlist)))
                        goto next_loop;

                if ((member = MCast_FindMember(m_entry, vlanp, portlist, 1, 1, 1)) == ((void *)0))
                        goto next_loop;

                if (mirrorThis == 1)
                        _rtl8651_setMGroupAttribute(mcast_addr, 1);


                member->MulticastRouterVersion = version;


                if (version < 3)
                {
                        slist = ((void *)0);
                        srcCnt = 0;
                        RecordType = 2;
                }else
                {
                        rtl8651_tblDrvMCastSource_t *s;
                        ipaddr_t* addrPtr = &(gr->src_list);
                        uint16 i = 0;

                        RecordType = gr->igmp_gr_rt;
                        srcCnt = (gr->igmp_gr_nofs);
                        slist = ((void *)0);

                        for (i = 0 ; i < srcCnt ; i ++)
                        {

                                if ((s = MCast_SourceList_Create()) == ((void *)0))
                                        break;

                                s->source = ((uint32) (*((uint8*)(addrPtr))<<24)|(*(((uint8*)(addrPtr))+1)<<16)|(*(((uint8*)(addrPtr))+2)<<8) | *(((uint8*)(addrPtr))+3));
                                s->next = slist;
                                if (slist)
                                        slist->prev = s;
                                slist = s;

                                addrPtr ++;
                        }
                }

                MCast_SourceList_freeAll(m_entry->slist);
                m_entry->FilterMode = MCast_SourceList_getCache(m_entry, &m_entry->slist);

                newFilterMode = MCast_ProcessGroupRecord(m_entry, member, RecordType, slist, srcCnt, ((version == 3)?1:0), &newSlist);


                if ((!m_entry->up_vlan) &&
                        (rtl8651_GlobalVariable.MCastUpStream.isSet == 1) &&
                        ((rtl8651_GlobalVariable.MCastUpStream.vlan != vlanp) ||((rtl8651_GlobalVariable.MCastUpStream.portMask& ~(1<<portlist)) != 0)))

                {

                        uint8 ver = MCast_MCastEntryMinVersion(m_entry);

                        if (ver < 3)
                                MCast_ReportPack(m_entry, m_entry->MulticastRouterVersion, m_entry->FilterMode, m_entry->slist, 1, ((void *)0), ((void *)0));
                        else
                                MCast_ReportPack(m_entry, m_entry->MulticastRouterVersion, m_entry->FilterMode, m_entry->slist, newFilterMode, newSlist, ((void *)0));
                }


                MCast_SourceList_freeAll(m_entry->slist);
                m_entry->slist = newSlist;
                m_entry->FilterMode = newFilterMode;



                if (version >= 3)
                        _rtl8651_delMulticast(mcast_addr, 0, 0);

next_loop:

                if (version < 3)
                {
                        l4Len += 8;
                }else
                {
                        l4Len += (8 + (uint32)(gr->igmp_gr_auxlen) + ((gr->igmp_gr_nofs) * sizeof(ipaddr_t)));

                        if (LoopCnt > 1)
                                gr = (struct igmp_gr*)(8 + (uint32)(gr->igmp_gr_auxlen) + (uint32)((gr->igmp_gr_nofs) * sizeof(ipaddr_t)) + (uint32)gr);
                }

                if (l4Len > l4ClaimLen)
                {
                        do {} while (0);
                        keep_pkt = 0;
                        goto freeout;
                }

                LoopCnt --;
        }


freeout:
        if (keep_pkt == 1)
                return 32;

        mBuf_freeMbufChain(pkthdr->PKTHDRNXT.mbuf_first);
        return 0;
errout:


        return 32;
}


int32 MCast_leave(struct rtl_pktHdr *pkthdr, struct ip *ip, struct igmp *ig)
{
        rtl8651_tblDrvMCast_t * m_entry;
        rtl8651_tblDrvMCastMember_t * member;
        rtl8651_tblDrv_vlanTable_t * vlanp = &DrvTbl.vlan[pkthdr->ph_vlanIdx & (8 - 1)];
        uint16 portlist = pkthdr->ph_portlist;
        ipaddr_t mcast_addr;
        uint8 keep_pkt = 0;


        if (!vlanp->internal)
                goto freeout;

        mcast_addr = ((uint32) (*((uint8*)(&(ig->grp.group)))<<24)|(*(((uint8*)(&(ig->grp.group)))+1)<<16)|(*(((uint8*)(&(ig->grp.group)))+2)<<8) | *(((uint8*)(&(ig->grp.group)))+3));


        {
                rtl8651_tblDrvMCastFilter_t *filter;
                filter = _rtl8651_multicast_FindFilter(mcast_addr);
                if (filter)
                {
                        switch (filter->action)
                        {
                                case ((1<<0)|(1<<1)):

                                        goto errout;
                                        break;
                                case ((1<<0)):

                                        keep_pkt = 1;
                                        break;
                                case ((1<<1)):

                                        goto freeout;
                                        break;
                        }
                }
        }

        if ((!((((ipaddr_t)(mcast_addr)) & 0xf0000000) == 0xe0000000)) || ((((ipaddr_t)(mcast_addr)) & (0xFFFFFF00L)) == 0xe0000000))
                goto errout;

        if ((m_entry = MCast_FindMCastEntry(mcast_addr, 1, 0)) == ((void *)0))
                goto freeout;
        else if ((m_entry->up_vlan == vlanp) &&
                        (m_entry->up_portMask== (1<<portlist)))
                goto freeout;

        if ((member = MCast_FindMember(m_entry, vlanp, portlist, 1, 0, (rtl8651_multicastProcessOptions & 0x00000001)?0:1)) == ((void *)0))

                goto freeout;

        if (keep_pkt == 1)
                _rtl8651_setMGroupAttribute(mcast_addr, 1);

        member->MulticastRouterVersion = 2;


        {
                uint8 newFilterMode;
                rtl8651_tblDrvMCastSource_t *newSlist;
                newFilterMode = MCast_ProcessGroupRecord(m_entry, member, 3, ((void *)0), 0, 0, &newSlist);
        }


        MCast_MemberExpire((uint32) member);
# 2997 "rtl8651_multicast.c"
freeout:
        if (keep_pkt == 1)
                return 32;

        mBuf_freeMbufChain(pkthdr->PKTHDRNXT.mbuf_first);
        return 0;
errout:


        return 32;
}
# 3033 "rtl8651_multicast.c"
static inline struct rtl_pktHdr *MCast_procPkt(struct rtl_pktHdr *pkt)
{
        if (pkt)
        {

                mBuf_adjTail(pkt->PKTHDRNXT.mbuf_first, mBuf_getPktlen(pkt->PKTHDRNXT.mbuf_first));
                return pkt;
        }else
        {
                struct rtl_mBuf *mbuf = ((void *)0);
                if((mbuf = mBuf_get(0x02, 0x01, 1)) == ((void *)0))
                        return ((void *)0);
                if((mBuf_getPkthdr(mbuf, 0x02) == (struct rtl_mBuf *) ((void *)0))||
                (mBuf_reserve(mbuf,rtl8651_fwdEnginePara.mbufHeadroom)))
                {
                        mBuf_freeMbufChain(mbuf);
                        return ((void *)0);
                }
                return mbuf->m_pkthdr;
        }
}
# 3064 "rtl8651_multicast.c"
int32 MCast_QueryPack(
        rtl8651_tblDrvMCastMember_t *member,
        rtl8651_tblDrvMCastRouteInfo_t *info,
        uint8 version,
        rtl8651_tblDrvMCastSource_t *sourceList,
        uint16 NumOfSrc,
        struct rtl_pktHdr *pkthdr)
{
        rtl8651_tblDrvMCastRouteInfo_t McastRouteInfo, *route_info = &McastRouteInfo;
        struct rtl_pktHdr *pkt = pkthdr;
        struct rtl_mBuf *mbuf;
        ipaddr_t sip;
        struct ip *pip;
        struct igmp *ig;
        uint8 *trailer;
        uint8 isGeneral = 0;
        uint32 pktLen = 0;
        rtl8651_tblDrvMCastSource_t *sptr = sourceList;
        uint32 remNumOfSrc = NumOfSrc;


        if (
                (!member && !info) ||
                ((version == 3) && sourceList && !member) ||
                ((version == 3) && NumOfSrc && !member))
                goto errout;






        if (member)
        {
                isGeneral = 0;

                route_info->netif = ((void *)0);
                route_info->ifInfo = 0;
                route_info->m_addr = member->m_entry->mcast_addr;
                route_info->vlan = member->vlan;
                route_info->port = member->portMask;
                route_info->isPortMask = 1;
        }else
        {
                isGeneral = 1;

                *route_info = *info;
                route_info->m_addr = (0xE0000001L);
        }

        if (MCast_SetRouteInfoAndGetIntfIp(&sip, route_info) != 0)
                goto errout;

sendNext:


        pkt = MCast_procPkt(pkt);
        if (pkt)
                mbuf = pkt->PKTHDRNXT.mbuf_first;
        else
                goto errout;
# 3137 "rtl8651_multicast.c"
        pktLen = 0;

        trailer = (uint8 *)(mbuf->m_data + 46);




        *(uint16 *)(mbuf->m_data + 12) = (0x0800);
        pktLen += 14;


        pip = (struct ip *)(mbuf->m_data + pktLen);
        if (version == 1)
                pip->ip_vhl = 0x45;
        else
                pip->ip_vhl = 0x46;
        pip->ip_tos = 0;
        pip->ip_id = ((system_id ++));
        pip->ip_off = (0);
        pip->ip_ttl = 1;
        pip->ip_p = 2;
        pip->ip_sum = 0;

        do{ *((uint8*)(&pip->ip_src)) = (uint8)((sip)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((sip)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((sip)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((sip)); }while(0);
        if (isGeneral == 1)
                do{ *((uint8*)(&pip->ip_dst)) = (uint8)(((0xE0000001L))>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)(((0xE0000001L))>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)(((0xE0000001L))>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)(((0xE0000001L))); }while(0);
        else
                do{ *((uint8*)(&pip->ip_dst)) = (uint8)((route_info->m_addr)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((route_info->m_addr)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((route_info->m_addr)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((route_info->m_addr)); }while(0);

        if (version == 1)
                pktLen += 20;
        else
        {
                *(uint16*)((uint8*)pip+20) = (0x9404);
                *(uint16*)((uint8*)pip+22) = (0x0000);
                pktLen += 24;
        }


        ig = (struct igmp *)(mbuf->m_data + pktLen);
        ig->igmp_type = 0x11;
        ig->igmp_cksum = 0;
        if (isGeneral)
                do{ *((uint8*)(&ig->grp.group)) = (uint8)((0)>>24); *(((uint8*)(&ig->grp.group))+1) = (uint8)((0)>>16); *(((uint8*)(&ig->grp.group))+2) = (uint8)((0)>>8); *(((uint8*)(&ig->grp.group))+3) = (uint8)((0)); }while(0);
        else
                do{ *((uint8*)(&ig->grp.group)) = (uint8)((route_info->m_addr)>>24); *(((uint8*)(&ig->grp.group))+1) = (uint8)((route_info->m_addr)>>16); *(((uint8*)(&ig->grp.group))+2) = (uint8)((route_info->m_addr)>>8); *(((uint8*)(&ig->grp.group))+3) = (uint8)((route_info->m_addr)); }while(0);

        switch (version)
        {
                case 1:
                        ig->igmp_code = 0;
                        pktLen += 8;
                        break;
                case 2:
                        {
                                if (rtl8651_igmp_qri)
                                        ig->igmp_code = ((rtl8651_igmp_qri * 10) & 0xff);
                                else
                                        ig->igmp_code = 10;
                                pktLen += 8;
                        }
                        break;
                case 3:
                        {
                                uint32 NumOfSrcThisPkt;
                                ipaddr_t *pkt_srcPtr;

                                if (rtl8651_igmp_qri)
                                        ig->igmp_code = ((rtl8651_igmp_qri * 10) & 0xff);
                                else
                                        ig->igmp_code = 10;

                                ig->un_v3.query.rsq = 0x01;
                                if (member)
                                        ig->un_v3.query.qqic = (uint8)(((rtl8651_igmp_group_query_interval) < (0x80) ? (rtl8651_igmp_group_query_interval) : ((((4)>=32 ? (rtl8651_igmp_group_query_interval) : ((1<<(4))-1) & (rtl8651_igmp_group_query_interval)) | (1<<(4 +3))) << (((3)>=32 ? ((rtl8651_igmp_group_query_interval) >> (4)) : ((1<<(3))-1) & ((rtl8651_igmp_group_query_interval) >> (4))) + (3)))));
                                else
                                        ig->un_v3.query.qqic = (uint8)(((rtl8651_igmp_qi) < (0x80) ? (rtl8651_igmp_qi) : ((((4)>=32 ? (rtl8651_igmp_qi) : ((1<<(4))-1) & (rtl8651_igmp_qi)) | (1<<(4 +3))) << (((3)>=32 ? ((rtl8651_igmp_qi) >> (4)) : ((1<<(3))-1) & ((rtl8651_igmp_qi) >> (4))) + (3)))));


                                if (route_info->netif->mtu < (pktLen + 12 + (remNumOfSrc * sizeof(ipaddr_t)) - 14))
                                {
                                        NumOfSrcThisPkt = ((route_info->netif->mtu - (pktLen + 12)) % sizeof(ipaddr_t));
                                        remNumOfSrc -= NumOfSrcThisPkt;
                                }else
                                {
                                        NumOfSrcThisPkt = remNumOfSrc;
                                        remNumOfSrc = 0;
                                }

                                ig->un_v3.query.nofs = (NumOfSrcThisPkt);
                                pktLen += (12 + (NumOfSrcThisPkt * sizeof(ipaddr_t)));


                                pkt_srcPtr = (ipaddr_t *)(&(ig->un_v3.query.src_list));
                                while (NumOfSrcThisPkt)
                                {
                                        do {} while (0);
                                        if (!sptr)
                                                goto errout;

                                        do{ *((uint8*)(pkt_srcPtr)) = (uint8)((sptr->source)>>24); *(((uint8*)(pkt_srcPtr))+1) = (uint8)((sptr->source)>>16); *(((uint8*)(pkt_srcPtr))+2) = (uint8)((sptr->source)>>8); *(((uint8*)(pkt_srcPtr))+3) = (uint8)((sptr->source)); }while(0);
                                        sptr = sptr->next;
                                        pkt_srcPtr ++;
                                        NumOfSrcThisPkt --;
                                }
                        }
                        break;
                default:
                        goto errout;
        }


        pip->ip_len = ((pktLen - 14));


        if (pktLen < 60)
        {
                trailer = (uint8*)(mbuf->m_data + pktLen);
                memset(trailer, 0, (60 - pktLen));
                pktLen = 60;
        }


        ig->igmp_cksum = MCast_igmpChecksum(pip);
        pip->ip_sum = _rtl8651_ipChecksum(pip);
        pkt->ph_flags &= ~(0x0002|0x0001);


        pkt->ph_len = pktLen;
        pkt->PKTHDRNXT.mbuf_first->m_len = pktLen;
        pkt->ph_portlist = 0;
        pkt->ph_pppeTagged = 0;
        pkt->ph_iphdrOffset = 14;
        pkt->ph_proto = 4;





        if (MCast_l3ActRouting(pkt, route_info) != 0)
                goto errout;

        if ((version == 3) && (remNumOfSrc > 0))
        {
                pkt = ((void *)0);
                goto sendNext;
        }
        return 0;
errout:
        if (pkt)
                mBuf_freeMbufChain(pkt->PKTHDRNXT.mbuf_first);
        return -1;
}







int32 MCast_ReportPack(
        rtl8651_tblDrvMCast_t *m_entry,
        uint8 version,
        uint8 oldFilterMode,
        rtl8651_tblDrvMCastSource_t *oldSourceList,
        uint8 newFilterMode,
        rtl8651_tblDrvMCastSource_t *newSourceList,
        struct rtl_pktHdr *pkthdr)
{
        rtl8651_tblDrvMCastRouteInfo_t McastRouteInfo, *route_info = &McastRouteInfo;
        struct rtl_pktHdr *pkt = pkthdr;
        struct rtl_mBuf *mbuf;
        ipaddr_t sip = 0;
        struct ip *pip;
        struct igmp *ig;
        uint8 *trailer;
        uint32 pktLen;

        rtl8651_tblDrvMCastSource_t* tempList[2] = {((void *)0), ((void *)0)};

        rtl8651_tblDrvMCastSource_t* SourceList[3] = {((void *)0), ((void *)0), ((void *)0)};
        uint8 RecordType[3] = {0, 0, 0};
        uint32 SourceListCnt[3] = {0, 0, 0};

        rtl8651_tblDrvMCastSource_t **CurrentSourceListp = ((void *)0);
        uint32 *CurrentSourceListCntp = ((void *)0);
        uint8 *CurrentRecordTypep = ((void *)0);

        if ((!m_entry) ||
                (
                        (version == 3) &&
                        (newFilterMode != 1) &&
                        (newFilterMode != 2))
                )
                goto release_out;
# 3345 "rtl8651_multicast.c"
        if (version == 3)
        {
                if (oldFilterMode == 0)
                {
                        RecordType[0] = ((newFilterMode == 1)?2:1);
                        SourceList[0] = newSourceList;
                        SourceListCnt[0] = MCast_SourceList_EntryCnt(newSourceList);
                        RecordType[1] = 0;
                        SourceList[1] = ((void *)0);
                        SourceListCnt[1] = 0;
                }else if (oldFilterMode != newFilterMode)
                {
                        RecordType[0] = ((newFilterMode == 1)?4:3);
                        SourceList[0] = newSourceList;
                        SourceListCnt[0] = MCast_SourceList_EntryCnt(newSourceList);
                        RecordType[1] = 0;
                        SourceList[1] = ((void *)0);
                        SourceListCnt[1] = 0;
                }else
                {
                        RecordType[0] = 5;
                        RecordType[1] = 6;
                        if (oldFilterMode == 2)
                        {
                                SourceListCnt[0] = MCast_SourceList_removal(newSourceList, 0, 0, oldSourceList, 0, 0, &tempList[0]);
                                SourceListCnt[1] = MCast_SourceList_removal(oldSourceList, 0, 0, newSourceList, 0, 0, &tempList[1]);
                        }else
                        {
                                SourceListCnt[0] = MCast_SourceList_removal(oldSourceList, 0, 0, newSourceList, 0, 0, &tempList[0]);
                                SourceListCnt[1] = MCast_SourceList_removal(newSourceList, 0, 0, oldSourceList, 0, 0, &tempList[1]);
                        }
                        SourceList[0] = tempList[0];
                        SourceList[1] = tempList[1];
                }


                CurrentSourceListp = &SourceList[0];
                CurrentSourceListCntp = &SourceListCnt[0];
                CurrentRecordTypep = &RecordType[0];
        }





        if (version < 3)
                route_info->m_addr = m_entry->mcast_addr;
        else
                route_info->m_addr = (0xE0000016L);


        if (m_entry->up_vlan)
        {
                route_info->netif = ((void *)0);
                route_info->ifInfo = 0;
                route_info->vlan = m_entry->up_vlan;
                route_info->port = m_entry->up_portMask;
                route_info->isPortMask = 1;
        }else if (rtl8651_GlobalVariable.MCastUpStream.isSet == 1)
        {
                rtl8651_tblDrvMCastMember_t *member;

                route_info->netif = rtl8651_GlobalVariable.MCastUpStream.netif;
                route_info->vlan = rtl8651_GlobalVariable.MCastUpStream.vlan;
                route_info->port = (rtl8651_GlobalVariable.MCastUpStream.portMask & phyPortLinkStatus);
                if (!route_info->port)
                        goto release_out;
                {
                        uint16 tmp = ~(route_info->port);
                        route_info->port = route_info->port & (tmp + 1);
                }
                route_info->ifInfo = (uint32)(rtl8651_GlobalVariable.MCastUpStream.MUpStreamInfo_un.intfIp);


                member = m_entry->member;
                while (member)
                {
                        if (member->vlan == route_info->vlan)
                        {
                                route_info->port &= ~(member->portMask);
                                if (!(route_info->port))
                                        goto release_out;
                        }
                        member = member->next;
                }
                route_info->isPortMask = 1;
        }else
                goto release_out;

        if (MCast_SetRouteInfoAndGetIntfIp(&sip, route_info) != 0)
                goto errout;

sendNext:



        pkt = MCast_procPkt(pkt);
        if (pkt)
                mbuf = pkt->PKTHDRNXT.mbuf_first;
        else
                goto errout;
# 3458 "rtl8651_multicast.c"
        pktLen = 0;



        *(uint16 *)(mbuf->m_data + 12) = (0x0800);
        pktLen += 14;
        pip = (struct ip *)(mbuf->m_data + pktLen);


        if (version == 1)
                pip->ip_vhl = 0x45;
        else
                pip->ip_vhl = 0x46;
        pip->ip_tos = 0;
        pip->ip_id = ((system_id ++));
        pip->ip_off = (0);
        pip->ip_ttl = 1;
        pip->ip_p = 2;
        pip->ip_sum = 0;

        do{ *((uint8*)(&pip->ip_src)) = (uint8)((sip)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((sip)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((sip)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((sip)); }while(0);
        do{ *((uint8*)(&pip->ip_dst)) = (uint8)((route_info->m_addr)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((route_info->m_addr)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((route_info->m_addr)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((route_info->m_addr)); }while(0);

        if (version == 1)
        {
                pktLen += 20;
        }else
        {

                *(uint16*)((uint8*)pip+20) = (0x9404);
                *(uint16*)((uint8*)pip+22) = (0x0000);
                pktLen += 24;
        }

        ig = (struct igmp *)(mbuf->m_data + pktLen);

        ig->igmp_cksum = 0;
        ig->igmp_code = 0;

        switch (version)
        {
                case 1:
                        do{ *((uint8*)(&ig->grp.group)) = (uint8)((route_info->m_addr)>>24); *(((uint8*)(&ig->grp.group))+1) = (uint8)((route_info->m_addr)>>16); *(((uint8*)(&ig->grp.group))+2) = (uint8)((route_info->m_addr)>>8); *(((uint8*)(&ig->grp.group))+3) = (uint8)((route_info->m_addr)); }while(0);
                        ig->igmp_type = 0x12;
                        pktLen += 8;
                        break;
                case 2:
                        do{ *((uint8*)(&ig->grp.group)) = (uint8)((route_info->m_addr)>>24); *(((uint8*)(&ig->grp.group))+1) = (uint8)((route_info->m_addr)>>16); *(((uint8*)(&ig->grp.group))+2) = (uint8)((route_info->m_addr)>>8); *(((uint8*)(&ig->grp.group))+3) = (uint8)((route_info->m_addr)); }while(0);
                        ig->igmp_type = 0x16;
                        pktLen += 8;
                        break;
                case 3:
                        {
                                struct igmp_gr * currGr, *gr;
                                ipaddr_t * addrPtr;
                                uint32 mtu;
                                uint32 nofg;
                                uint32 nofs;
                                uint32 genNextGroup;

                                ig->igmp_type = 0x22;
                                ig->grp.v3_report.resv = 0;
                                pktLen += 8;

                                mtu = route_info->netif->mtu;
                                currGr = &(ig->un_v3.report.gr_list);
                                nofg = 0;
                                genNextGroup = 1;

                                while ((*CurrentRecordTypep != 0) && (genNextGroup == 1))
                                {
                                        if (((*CurrentRecordTypep == 5) || (*CurrentRecordTypep == 6)) &&
                                                (*CurrentSourceListCntp == 0))
                                        {

                                                CurrentSourceListp ++;
                                                CurrentSourceListCntp ++;
                                                CurrentRecordTypep ++;
                                                continue;
                                        }

                                        gr = currGr;
                                        addrPtr = &(gr->src_list);
                                        nofs = 0;
                                        nofg ++;

                                        gr->igmp_gr_rt = *CurrentRecordTypep;

                                        gr->igmp_gr_auxlen = 0;
                                        do{ *((uint8*)(&(gr->igmp_gr_group))) = (uint8)((m_entry->mcast_addr)>>24); *(((uint8*)(&(gr->igmp_gr_group)))+1) = (uint8)((m_entry->mcast_addr)>>16); *(((uint8*)(&(gr->igmp_gr_group)))+2) = (uint8)((m_entry->mcast_addr)>>8); *(((uint8*)(&(gr->igmp_gr_group)))+3) = (uint8)((m_entry->mcast_addr)); }while(0);
                                        pktLen += 8;
                                        while(*CurrentSourceListCntp > 0)
                                        {
                                                do {} while (0);
                                                if (((pktLen + sizeof(ipaddr_t)-14) > mtu) || (nofs == 0xff))
                                                {
                                                        genNextGroup = 0;
                                                        goto SlistAdd_End;
                                                }
                                                do{ *((uint8*)(addrPtr)) = (uint8)(((*CurrentSourceListp)->source)>>24); *(((uint8*)(addrPtr))+1) = (uint8)(((*CurrentSourceListp)->source)>>16); *(((uint8*)(addrPtr))+2) = (uint8)(((*CurrentSourceListp)->source)>>8); *(((uint8*)(addrPtr))+3) = (uint8)(((*CurrentSourceListp)->source)); }while(0);
                                                addrPtr ++;
                                                nofs ++;
                                                (*CurrentSourceListCntp) --;
                                                (*CurrentSourceListp) = (*CurrentSourceListp)->next;
                                        }

                                        CurrentSourceListp ++;
                                        CurrentSourceListCntp ++;
                                        CurrentRecordTypep ++;
                                        currGr = (struct igmp_gr *)addrPtr;
        SlistAdd_End:
                                        gr->igmp_gr_nofs = (nofs);
                                        pktLen += (nofs * sizeof(ipaddr_t));
                                }
                                ig->grp.v3_report.nofg = (nofg);
                                if (nofg == 0)
                                        goto release_out;
                        }
                        break;
                default:
                        do {} while (0);
                        goto errout;
        }

        pip->ip_len = (pktLen - 14);


        if (pktLen < 60)
        {
                trailer = (uint8*)(mbuf->m_data + pktLen);
                memset(trailer, 0, (60 - pktLen));
                pktLen = 60;
        }


        ig->igmp_cksum = MCast_igmpChecksum(pip);
        pip->ip_sum = _rtl8651_ipChecksum(pip);
        pkt->ph_flags &= ~(0x0002|0x0001);


        pkt->ph_len = pktLen;
        pkt->PKTHDRNXT.mbuf_first->m_len = pktLen;
        pkt->ph_portlist = 0;
        pkt->ph_pppeTagged = 0;
        pkt->ph_iphdrOffset = 14;
        pkt->ph_proto = 4;





        if (MCast_l3ActRouting(pkt, route_info) != 0)
                goto errout;

        if (
                (version == 3) &&
                (*CurrentSourceListCntp > 0) &&
                (*CurrentRecordTypep != 2) &&
                (*CurrentRecordTypep != 4))
        {
                pkt = ((void *)0);
                goto sendNext;
        }

        goto out;

release_out:
        if (pkt)
                mBuf_freeMbufChain(pkt->PKTHDRNXT.mbuf_first);
out:
        if (tempList[0])
                        MCast_SourceList_freeAll(tempList[0]);
        if (tempList[1])
                        MCast_SourceList_freeAll(tempList[1]);
        return 0;
errout:
        if (pkt)
                mBuf_freeMbufChain(pkt->PKTHDRNXT.mbuf_first);
        if (tempList[0])
                        MCast_SourceList_freeAll(tempList[0]);
        if (tempList[1])
                        MCast_SourceList_freeAll(tempList[1]);
        return -1;
}


int32 MCast_LeavePack(rtl8651_tblDrvMCast_t *m_entry, struct rtl_pktHdr *pkthdr)
{
        struct rtl_pktHdr *pkt = pkthdr;
        struct rtl_mBuf *mbuf;
        ipaddr_t sip;
        struct ip *pip;
        struct igmp *ig;
        uint8 *trailer;
        rtl8651_tblDrvMCastRouteInfo_t McastRouteInfo, *route_info = &McastRouteInfo;

        if (!m_entry)
                goto errout;






        route_info->m_addr = m_entry->mcast_addr;
        if (m_entry->up_vlan)
        {
                route_info->netif = ((void *)0);
                route_info->ifInfo = 0;
                route_info->vlan = m_entry->up_vlan;
                route_info->port = m_entry->up_portMask;
                route_info->isPortMask = 1;
        }else
        {
                if (rtl8651_GlobalVariable.MCastUpStream.isSet == 1)
                {
                        rtl8651_tblDrvMCastMember_t *member;

                        route_info->netif = rtl8651_GlobalVariable.MCastUpStream.netif;
                        route_info->vlan = rtl8651_GlobalVariable.MCastUpStream.vlan;
                        route_info->port = rtl8651_GlobalVariable.MCastUpStream.portMask;
                        if (!route_info->port)
                                goto release_out;
                        {
                                uint16 tmp = ~(route_info->port);
                                route_info->port = route_info->port & (tmp + 1);
                        }
                        route_info->ifInfo = (uint32)(rtl8651_GlobalVariable.MCastUpStream.MUpStreamInfo_un.intfIp);


                        member = m_entry->member;
                        while (member)
                        {
                                if (member->vlan == route_info->vlan)
                                {
                                        route_info->port = route_info->port & ~(member->portMask);
                                        if (!(route_info->port))
                                        {
                                                goto release_out;
                                        }
                                }
                                member = member->next;
                        }
                        route_info->isPortMask = 1;
                }else
                {
                        goto errout;
                }
        }

        if (MCast_SetRouteInfoAndGetIntfIp(&sip, route_info) != 0)
        {
                goto errout;
        }




        pkt = MCast_procPkt(pkthdr);
        if (pkt)
                mbuf = pkt->PKTHDRNXT.mbuf_first;
        else
                goto errout;






        pkt->ph_len = 60;
        mbuf->m_len = 60;
        pip = (struct ip *)(mbuf->m_data + 14);
        ig = (struct igmp *)(mbuf->m_data + 38);
        trailer = (uint8 *)(mbuf->m_data + 46);




        *(uint16 *)(mbuf->m_data + 12) = (0x0800);


        pip->ip_vhl = 0x46;
        pip->ip_tos = 0;
        pip->ip_len = ((24+8));
        pip->ip_id = ((system_id ++));
        pip->ip_off = (0);
        pip->ip_ttl = 1;
        pip->ip_p = 2;
        pip->ip_sum = 0;

        do{ *((uint8*)(&pip->ip_src)) = (uint8)((sip)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((sip)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((sip)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((sip)); }while(0);
        do{ *((uint8*)(&pip->ip_dst)) = (uint8)(((0xE0000002L))>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)(((0xE0000002L))>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)(((0xE0000002L))>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)(((0xE0000002L))); }while(0);

        *(uint16*)((uint8*)pip+20) = (0x9404);
        *(uint16*)((uint8*)pip+22) = (0x0000);


        ig->igmp_type = 0x17;
        ig->igmp_code = 0;
        ig->igmp_cksum = 0;
        do{ *((uint8*)(&ig->grp.group)) = (uint8)((route_info->m_addr)>>24); *(((uint8*)(&ig->grp.group))+1) = (uint8)((route_info->m_addr)>>16); *(((uint8*)(&ig->grp.group))+2) = (uint8)((route_info->m_addr)>>8); *(((uint8*)(&ig->grp.group))+3) = (uint8)((route_info->m_addr)); }while(0);



        memset(trailer, 0, 14);


        ig->igmp_cksum = MCast_igmpChecksum(pip);
        pip->ip_sum = _rtl8651_ipChecksum(pip);
        pkt->ph_flags &= ~(0x0002|0x0001);


        pkt->ph_portlist = 0;
        pkt->ph_pppeTagged = 0;
        pkt->ph_iphdrOffset = 14;
        pkt->ph_proto = 4;





        if (MCast_l3ActRouting(pkt, route_info) != 0)
        {
                goto errout;
        }

        return 0;
release_out:
        if (pkt)
                mBuf_freeMbufChain(pkt->PKTHDRNXT.mbuf_first);
        return 0;
errout:
        if (pkt)
                mBuf_freeMbufChain(pkt->PKTHDRNXT.mbuf_first);
        return -1;
}

int32 MCast_l3ActRouting(struct rtl_pktHdr* pkthdr, rtl8651_tblDrvMCastRouteInfo_t *info)
{
        int8 *ptr;
        rtl8651_tblDrv_networkIntfTable_t *netif;
        uint16 srcPortList;

        if ((!(info->vlan)) ||
                (!(info->port)) ||
                (!(info->m_addr)))
        {
                return -1;
        }


        if (info->netif)
        {
                netif = info->netif;
        }else if ((netif = _rtl8651_getNetworkIntfEntryByVid(info->vlan->vid)) == ((void *)0))
        {
                return -1;
        }

        if(pkthdr->ph_pppeTagged)
        {
                uint16 etherType = (0x0800);

                mBuf_adjHead(pkthdr->PKTHDRNXT.mbuf_first, 8);

                ptr = (int8*)(pkthdr->PKTHDRNXT.mbuf_first->m_data);

                rtl8651_memcpy(ptr+12, &etherType, 2);

                pkthdr->ph_pppeTagged = 0;
                pkthdr->ph_iphdrOffset = 14;
        }
        do {} while (0);


        ptr = (int8*)(pkthdr->PKTHDRNXT.mbuf_first->m_data);

        switch (netif->linkLayerType)
        {
                case 0x01:

                        {
                                ether_addr_t ether;

                                ether.octet[0] = 0x01;
                                ether.octet[1] = 0x00;
                                ether.octet[2] = 0x5e;
                                ether.octet[3] = (uint8)((info->m_addr >> 16) & 0xff);
                                ether.octet[4] = (uint8)((info->m_addr >> 8) & 0xff);
                                ether.octet[5] = (uint8)(info->m_addr & 0xff);
                                ether.octet[3] &= 0x7f;
                                rtl8651_memcpy(ptr, &ether, 6);
                        }

                        break;
                case 0x02:

                        {
                                rtl8651_tblDrv_pppTable_t *poe_tb;

                                if (info->ifInfo)
                                {
                                        poe_tb = ((rtl8651_tblDrvSession_t*)(info->ifInfo))->session_t;
                                }else
                                {
                                        poe_tb = ((&netif->sessionHead)->tqh_first)->session_t;
                                }


                                pkthdr->ph_pppoeIdx = (poe_tb - DrvTbl.pppoe);
                                pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid=poe_tb->dsid;

                                pkthdr->ph_flags |= (0x0008);

                                rtl8651_memcpy(ptr, &(poe_tb->macInfo->macAddr), 6);
                        }
                        break;

                case 0x05:
                case 0x06:
                        {
                                rtl8651_tblDrv_pppTable_t *ptb;
                                if (info->ifInfo)
                                {
                                        ptb = ((rtl8651_tblDrvSession_t *)(info->ifInfo))->session_t;
                                }else
                                {
                                        ptb = ((rtl8651_tblDrvSession_t *)((&(netif->sessionHead))->tqh_first))->session_t;
                                }

                                rtl8651_memcpy(ptr, &(ptb->macInfo->macAddr), 6);


                                info->vlan = &DrvTbl.vlan[netif->vid & (8 - 1)];
                                info->port = info->vlan->memberPortMask;
                                info->isPortMask = 1;
                        }
                        break;

                default:
                        return -1;
        }

        if (info->vlan->macAddrNumber == 0)
        {
                return -1;
        }
        rtl8651_memcpy(ptr+6, &(info->vlan->macAddr), 6);


        srcPortList = pkthdr->ph_portlist;
        if (info->isPortMask == 1)
        {
                pkthdr->ph_portlist = (info->port);
        }else
        {
                pkthdr->ph_portlist = (1<<(info->port));
        }
        if (pkthdr->ph_portlist == 0)
        {
                return -1;
        }
        pkthdr->ph_flags &= ~(0x0002|0x0001);
        MCast_setPkthdrProperty(pkthdr, 0x01);

        {
                uint32 mtu, tol_len;
                mtu = netif->mtu;
                tol_len = mBuf_getPktlen(pkthdr->PKTHDRNXT.mbuf_first);
                if (tol_len > (mtu+14))
                {
                        int32 retval;
                        int8 old_IcmpRoutingMsgEnable;


                        old_IcmpRoutingMsgEnable = rtl8651_drvIcmpRoutingMsgEnable;

                        rtl8651_drvIcmpRoutingMsgEnable = 0;

                        retval = _rtl8651_mtuFragment(((uint32)(1)<<1), pkthdr, mtu, (info->vlan->vid), 0, srcPortList);

                        rtl8651_drvIcmpRoutingMsgEnable = old_IcmpRoutingMsgEnable;
                        return retval;
                }
        }
        return _rtl8651_fwdEngineSend(((uint32)(1)<<1), (void*)pkthdr, (info->vlan->vid),-1);
}



int32 MCast_setPkthdrProperty(struct rtl_pktHdr *ph, int32 property)
{
        uint32 swNicRxIndex = 0;

        if (!ph)
                return -1;




        rtlglue_getRingSize(&swNicRxIndex, ((void *)0));


        if (!swNicRxIndex)
                return -1;

        switch (property)
        {
                case 0x01:
                        if ((ph->ph_rxdesc>=0)&&(ph->ph_rxdesc<swNicRxIndex))
                                return -1;
                        ph->ph_rxdesc = swNicRxIndex;
                        break;
                default:
                        return -1;
        }
        return 0;
}




int32 _rtl8651_igmp_process(struct rtl_pktHdr *pkthdr, struct ip *ip, struct igmp *ig)
{
        if ((system_enable == 0) || (rtl8651_drvMulticastProcessEnable == 0))
        {
                return 32;
        }

        switch (ig->igmp_type)
        {
                case 0x12:
                case 0x16:
                case 0x22:



                        return MCast_report(pkthdr, ip, ig);
                case 0x17:



                        return MCast_leave(pkthdr, ip, ig);
                case 0x11:



                        return MCast_query(pkthdr, ip, ig);
        }
        return 32;
}


int32 _rtl8651_multicast_process(struct rtl_pktHdr *pkthdr, struct ip *ip)
{
        ipaddr_t sip_org, sip;
        uint16 portSrc = pkthdr->ph_portlist;
        uint16 portMask = (1<<pkthdr->ph_portlist);
        uint16 MemberPortMask;
        ipaddr_t mcast_addr;
        ipaddr_t extIp;
        rtl8651_tblDrvMCast_t * m_entry;
        rtl8651_tblDrvMCastMember_t * member;
        rtl8651_tblDrv_vlanTable_t * vlanp = &DrvTbl.vlan[pkthdr->ph_vlanIdx & (8 - 1)];
        rtl8651_tblDrvMCastRouteInfo_t info;
        rtl8651_tblDrv_vlanTable_t * FwdVlan[8];
        uint16 FwdPortMask[8];
        uint32 CacheVlanMask = 0;
        uint32 CachePortMask = 0;
        uint8 idx;
        uint8 fwdPktCnt;

        uint8 totalUpCnt = 0;

        rtl8651_tblDrvMCastUpStreamInfo_t upstreamInfo, *up = &upstreamInfo;
        struct rtl_pktHdr *fwdHdr = pkthdr;
        struct rtl_mBuf *fwdMbuf = pkthdr->PKTHDRNXT.mbuf_first;
        struct ip *fwdIp = ip;
        uint8 l4proto;

        uint8 keep_pkt = 0;

        uint8 ignoreCacheUpStream;
        uint16 upPortMask = 0;

        if ((system_enable == 0) || (rtl8651_drvMulticastProcessEnable == 0))
                return 46;


        CacheVlanMask= 0;
        CachePortMask = 0;
        extIp = 0;
        ignoreCacheUpStream = 0;

        up->isSet = 0;

        l4proto = ip->ip_p;


        switch(l4proto)
        {
                case 6:
                        rtl8651_fwdEngineCounter.tcpReceive ++;
                        break;
                case 17:
                        rtl8651_fwdEngineCounter.udpReceive ++;
                        break;
        }

        mcast_addr = ((uint32) (*((uint8*)(&ip->ip_dst))<<24)|(*(((uint8*)(&ip->ip_dst))+1)<<16)|(*(((uint8*)(&ip->ip_dst))+2)<<8) | *(((uint8*)(&ip->ip_dst))+3));
        sip_org = ((uint32) (*((uint8*)(&ip->ip_src))<<24)|(*(((uint8*)(&ip->ip_src))+1)<<16)|(*(((uint8*)(&ip->ip_src))+2)<<8) | *(((uint8*)(&ip->ip_src))+3));
        do {} while (0);






        {
                rtl8651_tblDrvMCastFilter_t *filter;
                filter = _rtl8651_multicast_FindFilter(mcast_addr);
                if (filter)
                {
                        switch (filter->action)
                        {
                                case ((1<<0)|(1<<1)):

                                        return 46;
                                case ((1<<0)):

                                        {
                                                struct rtl_mBuf *nbuf = ((void *)0);
                                                nbuf = mBuf_dupPacket(pkthdr->PKTHDRNXT.mbuf_first, 0x02);
                                                if (nbuf)
                                                {
                                                        fwdMbuf = nbuf;
                                                        fwdHdr= nbuf->m_pkthdr;
                                                        fwdIp = (struct ip *)((uint32)nbuf->m_data + ((uint32)ip - (uint32)(pkthdr->PKTHDRNXT.mbuf_first->m_data)));
                                                        keep_pkt = 1;
                                                }
                                        }
                                        break;
                                case ((1<<1)):

                                        goto release_out;
                        }
                }
        }




        if (((((ipaddr_t)(mcast_addr)) & (0xFFFFFF00L)) == 0xe0000000))
                goto release_out;
# 4123 "rtl8651_multicast.c"
        if ((m_entry = MCast_FindMCastEntry(mcast_addr, 0, 1)) == ((void *)0))
        {
                if ((rtl8651_GlobalVariable.MCastUpStream.isSet == 1) && ((rtl8651_GlobalVariable.MCastUpStream.vlan != vlanp) || !(rtl8651_GlobalVariable.MCastUpStream.portMask & portMask)))
                {
                                up = &(rtl8651_GlobalVariable.MCastUpStream);
                }
        }else
        {



                if ((m_entry->up_vlan) && ((m_entry->up_vlan != vlanp) || (m_entry->up_portMask != portMask)))
                {
                        up->isSet = 1;
                        up->vlan = m_entry->up_vlan;
                        up->portMask = m_entry->up_portMask;
                        up->netif = _rtl8651_getNetworkIntfEntryByVid(m_entry->up_vlan->vid);
                        up->MUpStreamInfo_un.intfIp = 0;
                }else if ((rtl8651_GlobalVariable.MCastUpStream.isSet == 1) && ((rtl8651_GlobalVariable.MCastUpStream.vlan != vlanp) || !(rtl8651_GlobalVariable.MCastUpStream.portMask & portMask)))
                {
                        up = &(rtl8651_GlobalVariable.MCastUpStream);
                }



        member = m_entry->member;
        memset(FwdPortMask, 0, (sizeof(uint16)*8));
        memset(FwdVlan, 0, (sizeof(uint32)*8));
        fwdPktCnt = 0;
        while (member)
        {

                if (member->isForwarder == 0)
                        goto next_member;


                        if ((rtl8651_multicastProcessOptions & 0x00000001) &&
                                (member->state != 1))
                                goto next_member;


                if (member->MulticastRouterVersion == 3)
                {
                        rtl8651_tblDrvMCastSource_t *tmp;
                        if ((member->FilterMode == 2) && (!MCast_SourceList_inList(sip_org, member->slist)))
                                goto next_member;
                        if (member->FilterMode == 1)
                        {
                                tmp = MCast_SourceList_inList(sip_org, member->slist);
                                if (tmp && (tmp->timer.expires <= _sysUpSeconds))
                                        goto next_member;
                        }
                }


                MemberPortMask = member->portMask;
                if (member->vlan == vlanp)
                        MemberPortMask &= ~(portMask);
                if (MemberPortMask == 0)
                        goto next_member;


                if (FwdVlan[((member->vlan->vid) & (8 - 1))] == ((void *)0))
                {
                                fwdPktCnt ++;
                        FwdVlan[((member->vlan->vid) & (8 - 1))] = member->vlan;
                }
                        FwdPortMask[((member->vlan->vid) & (8 - 1))] |= MemberPortMask;






        next_member:
                member = member->next;
        }


                totalUpCnt = fwdPktCnt;



        if (fwdPktCnt == 0)
                goto fwd_to_upstream;


        idx = 0;
        info.m_addr = mcast_addr;
        info.isPortMask = 1;
        info.netif = ((void *)0);
        info.ifInfo = 0;


        fwdHdr->ph_flags &= ~(0x0002|0x0001);


        while (fwdPktCnt > 0)
        {
                        uint8 needDup = 0;
                        uint8 needDecrTTL = 0;
                        uint8 needIgnoreThisFwd = 0;

                while (FwdVlan[idx] == ((void *)0))
                {
                        idx ++;
                        do {} while (0);
                }
# 4240 "rtl8651_multicast.c"
                        CacheVlanMask |= (1<<idx);
                        CachePortMask|= FwdPortMask[idx];


                info.vlan = FwdVlan[idx];
                info.port = FwdPortMask[idx];
                        do {} while (0);
                        do {} while (0);



                        if ((fwdPktCnt > 1)



                        )
                {
                                needDup = 1;
                }
# 4280 "rtl8651_multicast.c"
                        if (FwdVlan[idx] != vlanp)
                        {
                                if (fwdIp->ip_ttl > 1)
                                {
                                        needDecrTTL = 1;
                                }else
                                {



                                        needIgnoreThisFwd = 1;
                                }
                        }






                        if (needIgnoreThisFwd == 1)
                        {
                                if (needDup == 0)
                                {
                                        do {} while (0);
                                        mBuf_freeMbufChain(fwdMbuf);
                                }
                        } else
                        {
                                if (needDup == 1)
                {
                        struct rtl_mBuf *newMbuf;

                                        if ((newMbuf = mBuf_dupPacket(fwdMbuf, 0x02)) != ((void *)0))
                                        {

                                                if (needDecrTTL == 1)
                                                {
                                                        struct ip *newIp = (struct ip*)(((uint32)fwdIp - (uint32)(fwdMbuf->m_data)) + (uint32)(newMbuf->m_data));

                                                        do { int32 ttl_mod = 0x0100; (newIp->ip_ttl) --; do { ttl_mod += ((newIp->ip_sum)); if (ttl_mod < 0) { ttl_mod = -ttl_mod; ttl_mod = (ttl_mod >> 16) + (ttl_mod & 0xffff); ttl_mod += ttl_mod >> 16; (newIp->ip_sum) = ((uint16) ~ttl_mod); } else { ttl_mod = (ttl_mod >> 16) + (ttl_mod & 0xffff); ttl_mod += ttl_mod >> 16; (newIp->ip_sum) = ((uint16) ttl_mod); } } while (0); } while(0);




                                                }





                        if (MCast_l3ActRouting(newMbuf->m_pkthdr, &info) != 0)
                        {
                                mBuf_freeMbufChain(newMbuf);



                                                }




                        }
                }else
                {

                                        if (needDecrTTL == 1)
                                        {
                                                do { int32 ttl_mod = 0x0100; (fwdIp->ip_ttl) --; do { ttl_mod += ((fwdIp->ip_sum)); if (ttl_mod < 0) { ttl_mod = -ttl_mod; ttl_mod = (ttl_mod >> 16) + (ttl_mod & 0xffff); ttl_mod += ttl_mod >> 16; (fwdIp->ip_sum) = ((uint16) ~ttl_mod); } else { ttl_mod = (ttl_mod >> 16) + (ttl_mod & 0xffff); ttl_mod += ttl_mod >> 16; (fwdIp->ip_sum) = ((uint16) ttl_mod); } } while (0); } while(0);



                                        }






                                        if (MCast_l3ActRouting(fwdHdr, &info) != 0)
                                        {
                                                mBuf_freeMbufChain(fwdMbuf);



                                        }




                                }
                        }

                        fwdPktCnt --;
                        idx ++;
                }
        }






fwd_to_upstream:

        if (totalUpCnt == 0)
        {

                if (up->isSet == 1)
                {







                        info.port = ((up->portMask & ~(portMask)) & phyPortLinkStatus);
                        if (info.port == 0)
                        {



                                ignoreCacheUpStream = 1;
                                goto upstream_fwd_fail;
                        } else
                        {
                                uint16 tmp = ~(info.port);
                                info.port = info.port & (tmp + 1);
                                upPortMask = info.port;
                        }
                        info.m_addr = mcast_addr;
                        info.vlan = up->vlan;
                        info.netif = up->netif;
                        info.ifInfo = (uint32)(up->MUpStreamInfo_un.intfIp);
                        info.isPortMask = 1;


                        if (MCast_SetRouteInfoAndGetIntfIp(&sip, &info) != 0)
                        {
                                ignoreCacheUpStream = 1;
                                goto upstream_fwd_fail;
                        }

                        if ((!(portMask&rtl8651_externalMulticastPortMask)) &&
                                        ((info.port)&rtl8651_externalMulticastPortMask))
                        {


                                extIp = sip;


                                do{ *((uint8*)(&fwdIp->ip_src)) = (uint8)((sip)>>24); *(((uint8*)(&fwdIp->ip_src))+1) = (uint8)((sip)>>16); *(((uint8*)(&fwdIp->ip_src))+2) = (uint8)((sip)>>8); *(((uint8*)(&fwdIp->ip_src))+3) = (uint8)((sip)); }while(0);

                                do { do { int32 accumulate = 0; if ((((sip)) != 0) && (((sip_org)) != 0)){ accumulate = (((sip_org)) & 0xffff); accumulate += (( ((sip_org)) >> 16 ) & 0xffff); accumulate -= (((sip)) & 0xffff); accumulate -= (( ((sip)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((fwdIp->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((fwdIp->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((fwdIp->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                                if (!((fwdIp->ip_off) & 0x1fff))
                                {
                                        uint8 *l4hdr = (uint8 *) ((int8 *) fwdIp + ((*(uint8*)fwdIp&0xf) << 2));
                                        uint16 *cksum = ((void *)0);

                                        switch(fwdHdr->ph_proto)
                                        {
                                                case 5:
                                                        cksum = &(((struct tcphdr*)l4hdr)->th_sum);
                                                        break;
                                                case 6:
                                                        cksum = &(((struct udphdr*)l4hdr)->uh_sum);
                                                        break;
                                                default:
                                                        goto skip_l4_checksum;
                                        }

                                        do { do { int32 accumulate = 0; if ((((sip)) != 0) && (((sip_org)) != 0)){ accumulate = (((sip_org)) & 0xffff); accumulate += (( ((sip_org)) >> 16 ) & 0xffff); accumulate -= (((sip)) & 0xffff); accumulate -= (( ((sip)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((*cksum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((*cksum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((*cksum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                                skip_l4_checksum:
                                        ;
                                }
                        }


                        if (up->vlan != vlanp)
                        {
                                if (fwdIp->ip_ttl > 1)
                                {
                                        do { int32 ttl_mod = 0x0100; (fwdIp->ip_ttl) --; do { ttl_mod += ((fwdIp->ip_sum)); if (ttl_mod < 0) { ttl_mod = -ttl_mod; ttl_mod = (ttl_mod >> 16) + (ttl_mod & 0xffff); ttl_mod += ttl_mod >> 16; (fwdIp->ip_sum) = ((uint16) ~ttl_mod); } else { ttl_mod = (ttl_mod >> 16) + (ttl_mod & 0xffff); ttl_mod += ttl_mod >> 16; (fwdIp->ip_sum) = ((uint16) ttl_mod); } } while (0); } while(0);



                                }else
                                {



                                        goto upstream_fwd_fail;
                                }
                        }

                        if (MCast_l3ActRouting(fwdHdr, &info) != 0)
                        {
        upstream_fwd_fail:
                                mBuf_freeMbufChain(fwdMbuf);
                        }
                }else
                {
                        goto release_out;
                }
        }
# 4511 "rtl8651_multicast.c"
        if ((totalUpCnt == 0) && (up->isSet == 1) && (ignoreCacheUpStream == 0))
        {
                uint16 recUpPortMask;
                uint32 recUpVlanMask;

                do {} while (0);

                MCast_asicSetActualVlanPort(&recUpPortMask, &recUpVlanMask, up->netif, up->vlan, upPortMask, (uint32)(up->MUpStreamInfo_un.intfIp));

                if ((recUpPortMask = (recUpPortMask & ~(portMask))) != 0)
                {
                        CacheVlanMask |= recUpVlanMask;
                        CachePortMask |= recUpPortMask;
                }
        }

        if (CacheVlanMask && CachePortMask)
        {
# 4549 "rtl8651_multicast.c"
                _rtl8651_addMulticast(mcast_addr, sip_org, vlanp->vid, portSrc, CacheVlanMask, CachePortMask, extIp, ((keep_pkt == 1)?1:0), (totalUpCnt == 0)?0x04:0);


        }
ret:

        {
                switch(l4proto)
                {
                        case 6:
                                rtl8651_fwdEngineCounter.tcpSend ++;
                                break;
                        case 17:
                                rtl8651_fwdEngineCounter.udpSend ++;
                                break;
                }
        }
        if (keep_pkt == 1)
                return 46;
        else
                return 0;

release_out:
        mBuf_freeMbufChain(fwdMbuf);
        goto ret;
}


int32 _rtl8651_multicast_Fastfwd(struct rtl_pktHdr *pkthdr, struct ip *ip, rtl8651_tblDrv_vlanTable_t *vlanp)
{
        rtl8651_tblDrvMCastRouteInfo_t info;
        rtl8651_tblDrv_mCast_t *m_data;
        ipaddr_t mcast_addr;
        ipaddr_t sip;
        uint32 vlanMask;
        uint16 idx;
        uint8 l4proto;
        uint8 keep_pkt = 0;

        if ((system_enable == 0) || (rtl8651_drvMulticastProcessEnable == 0))
                return -1;

        if (((((ipaddr_t)(pkthdr->ph_dip)) & (0xFFFFFF00L)) == 0xe0000000))
                return -1;

        mcast_addr = pkthdr->ph_dip;
        sip = pkthdr->ph_sip;
        l4proto = ip->ip_p;


        {
                rtl8651_tblDrvMCastFilter_t *filter;
                filter = _rtl8651_multicast_FindFilter(mcast_addr);
                if (filter)
                {
                        switch (filter->action)
                        {
                                case ((1<<0)|(1<<1)):

                                        return 46;
                                case ((1<<0)):

                                        keep_pkt = 1;
                                        break;
                                case ((1<<1)):

                                        goto errout;
                        }
                }
        }





        m_data = (rtl8651_tblDrv_mCast_t *)_rtl8651_findMCast(mcast_addr, sip, vlanp->vid, pkthdr->ph_portlist);

        if(m_data == ((void *)0) )
        {



                return -1;
        }





        if (m_data->flag & 0x02)
        {



                return -1;
        }





        if (((1<<(pkthdr->ph_vlanIdx & (8 - 1))) & m_data->vlanMask)
                && (m_data->vlanMask & ~(1<<(pkthdr->ph_vlanIdx & (8 - 1)))))
        {



                return -1;
        }else
        {
                if (m_data->vlanMask & ~(1<<(pkthdr->ph_vlanIdx & (8 - 1))))
                {
                        if (ip->ip_ttl > 1)
                        {
                                do { int32 ttl_mod = 0x0100; (ip->ip_ttl) --; do { ttl_mod += ((ip->ip_sum)); if (ttl_mod < 0) { ttl_mod = -ttl_mod; ttl_mod = (ttl_mod >> 16) + (ttl_mod & 0xffff); ttl_mod += ttl_mod >> 16; (ip->ip_sum) = ((uint16) ~ttl_mod); } else { ttl_mod = (ttl_mod >> 16) + (ttl_mod & 0xffff); ttl_mod += ttl_mod >> 16; (ip->ip_sum) = ((uint16) ttl_mod); } } while (0); } while(0);
                        }else
                        {
                                goto freeout;
                        }
                }
        }


        info.m_addr = mcast_addr;
        info.port = m_data->mbr;
        info.isPortMask = 1;
        info.netif = ((void *)0);
        info.ifInfo = 0;

        vlanMask = m_data->vlanMask;
        idx = 0;

        if ((!vlanMask) || (!(m_data->mbr)))
                return -1;


        pkthdr->ph_flags &= ~(0x0002|0x0001);

        while (vlanMask)
        {
                if (vlanMask & 1)
                {
                        info.vlan = &DrvTbl.vlan[idx];


                        if ((keep_pkt == 0) && (vlanMask == 1))
                        {
                                if (MCast_l3ActRouting(pkthdr, &info) != 0)
                                        goto errout;
                        }else
                        {
                                struct rtl_mBuf *newMbuf;
                                newMbuf = mBuf_dupPacket(pkthdr->PKTHDRNXT.mbuf_first, 0x02);

                                if (MCast_l3ActRouting(newMbuf->m_pkthdr, &info) != 0)
                                        mBuf_freeMbufChain(newMbuf);

                        }
                }

                vlanMask = vlanMask >> 1;
                idx ++;
        }


        {
                switch(l4proto)
                {
                        case 6:
                                rtl8651_fwdEngineCounter.tcpSend ++;
                                break;
                        case 17:
                                rtl8651_fwdEngineCounter.udpSend ++;
                                break;
                }
        }

        if (keep_pkt == 1)
                return 46;
        else
                return 0;
errout:

freeout:
        mBuf_freeMbufChain(pkthdr->PKTHDRNXT.mbuf_first);
        return 0;
}
# 4747 "rtl8651_multicast.c"
int32 _rtl8651_multicast_FilterInit(rtl8651_fwdEngineInitPara_t *para)
{
        uint32 idx;
        rtl8651_tblDrvMCastFilter_t *ptr;

        rtlglue_drvMutexLock();


        for (idx = 0 ; idx < 32 ; idx ++)
                MCastFilter[idx] = ((void *)0);


        MCastFilter_FreeHdr = ((void *)0);

        if (!para->MCastFilterEntryCnt)
                goto out;


        MCastFilter_FreeHdr = (rtl8651_tblDrvMCastFilter_t *)rtlglue_malloc(para->MCastFilterEntryCnt * sizeof(rtl8651_tblDrvMCastFilter_t));

        if (!MCastFilter_FreeHdr)
                goto out;


        bzero(MCastFilter_FreeHdr, (para->MCastFilterEntryCnt * sizeof(rtl8651_tblDrvMCastFilter_t)));

        ptr = MCastFilter_FreeHdr;
        for (idx = 0 ; idx < para->MCastFilterEntryCnt ; idx ++, ptr++)
        {
                if (idx < (para->MCastFilterEntryCnt - 1))
                        ptr->next = ptr + 1;
                else
                        ptr->next = ((void *)0);
        }

out:
        rtlglue_drvMutexUnlock();
        return 0;
}
void rtl8651_multicast_FilterReinit(void)
{
        uint32 idx;

        for (idx = 0 ; idx < 32 ; idx ++)
        {
                while (MCastFilter[idx])
                        rtl8651_multicast_RemoveFilter(MCastFilter[idx]->gip, 0xffffffff);
                do {} while (0);
        }
}

uint32 _rtl8651_multicast_Filter_Hash(ipaddr_t gip)
{
        return (gip % 32);
}

rtl8651_tblDrvMCastFilter_t *_rtl8651_multicast_FindFilter(ipaddr_t gip)
{
        rtl8651_tblDrvMCastFilter_t *ptr;

        ptr = MCastFilter[_rtl8651_multicast_Filter_Hash(gip)];

        while(ptr && (ptr->gip != gip))
                ptr = ptr->next;

        return ptr;
}

int32 rtl8651_multicast_AddFilter(ipaddr_t gip, uint32 action)
{
        rtl8651_tblDrvMCastFilter_t *ptr;
        uint32 idx;
        uint32 orgAction = 0;


        do { if (((action) & (((1<<1)|(1<<2)))) == (((1<<1)|(1<<2)))) { return -1; } } while (0);;

        rtlglue_drvMutexLock();

        ptr = _rtl8651_multicast_FindFilter(gip);
        if (ptr)
        {
                orgAction = ptr->action;
                ptr->action |= action;
        }else
        {
                if (!action)
                        goto out;
                if (!MCastFilter_FreeHdr)
                        goto errout;


                ptr = MCastFilter_FreeHdr;
                MCastFilter_FreeHdr = MCastFilter_FreeHdr->next;


                ptr->gip = gip;
                ptr->action = action;


                idx = _rtl8651_multicast_Filter_Hash(gip);
                ptr->next = MCastFilter[idx];
                MCastFilter[idx] = ptr;
        }


        _rtl8651_setMGroupAttribute(gip, ((ptr->action & (1<<0))?1:0));
        if (ptr->action & ((1<<1)|(1<<2)))
        {
                rtl8651_tblDrvMCast_t *m_entry = MCast_FindMCastEntry(gip, 0, 0);
                if (m_entry)
                {
                        MCast_RemoveMCastEntry(m_entry);
                        _rtl8651_delMulticast(gip, 0, 0);
                }
        }

out:
        rtlglue_drvMutexUnlock();
        return 0;
errout:
        rtlglue_drvMutexUnlock();
        return -1;
}
int32 rtl8651_multicast_RemoveFilter(ipaddr_t gip, uint32 action)
{
        rtl8651_tblDrvMCastFilter_t *ptr, *prev;
        uint32 idx;
        uint8 TurnMirrorOff = 0;

        rtlglue_drvMutexLock();


        idx = _rtl8651_multicast_Filter_Hash(gip);
        prev = ((void *)0);
        ptr = MCastFilter[idx];
        while (ptr && (ptr->gip != gip))
        {
                ptr = ptr->next;
                prev = ptr;
        }



        if (ptr)
        {
                uint32 orgAction = ptr->action;

                ptr->action &= ~action;

                if ((orgAction & (1<<0)) && (!(ptr->action & (1<<0))))
                        TurnMirrorOff = 1;

                if (ptr->action)
                        goto out;



                if (prev)
                        prev->next = ptr->next;

                if (MCastFilter[idx] == ptr)
                        MCastFilter[idx] = ptr->next;


                ptr->next = MCastFilter_FreeHdr;
                MCastFilter_FreeHdr = ptr;
        }

out:


        if (TurnMirrorOff == 1)
                _rtl8651_setMGroupAttribute(gip, 0);

        rtlglue_drvMutexUnlock();
        return 0;
}
