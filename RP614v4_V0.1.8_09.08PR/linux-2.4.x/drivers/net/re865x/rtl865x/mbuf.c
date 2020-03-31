# 1 "mbuf.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "mbuf.c"
# 12 "mbuf.c"
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
# 13 "mbuf.c" 2
# 1 "assert.h" 1
# 14 "mbuf.c" 2
# 1 "types.h" 1
# 15 "mbuf.c" 2
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
# 16 "mbuf.c" 2
# 1 "rtl_utils.h" 1






void __strlowerncpy(char *dst, const char *src, int32 len);
int8 *_strncpy(int8 *dst0, const int8 *src0, int32 count);
int _strncasecmp(const char *s1, const char *s2, unsigned int n);
int32 _strncmp(const int8 *s1, const int8 *s2, int32 n);
void rtl8651_memcpy(void *dst,void*src,int32 len);
int32 isPowerOf2(uint32 number, uint32 *exponent);
int32 IpStrToAscii(const int8 *cp, uint32 *addr);
void IntToAscii(int32 n, int8 s[]);
int AsciiToInt( char **s);
int32 ether_ntoa_r(ether_addr_t *n, uint8 *a);
int8 *inet_ntoa_r(ipaddr_t ipaddr, int8 *p);
void memDump (void *start, uint32 size, int8 * strHeader);
# 17 "mbuf.c" 2
# 1 "rtl_glue.h" 1
# 130 "rtl_glue.h"
extern int32 rtlglue_init(void);
# 139 "rtl_glue.h"
extern int32 rtlglue_registerTimerMs(uint32 *eventId,uint32 *eventSerialNumber,
                                                int32 (* callback_func)(uint32 eventSerialNumber,void *), void *callback_func_arg, uint32 msec);
# 161 "rtl_glue.h"
extern int32 rtlglue_cancelTimer(uint32 eventId,uint32 eventSerialNumber);
# 172 "rtl_glue.h"
extern int32 rtlglue_mbufMutexLock(void);
# 183 "rtl_glue.h"
extern int32 rtlglue_mbufMutexUnlock(void);
# 193 "rtl_glue.h"
extern int32 rtlglue_mbufTsleep(uint32 wait_channel);
# 204 "rtl_glue.h"
extern int32 rtlglue_mbufTwakeup(uint32 wait_channel);
# 214 "rtl_glue.h"
extern int32 rtlglue_mbufAllocCluster(void **buffer, uint32 size, uint32 *id);
# 228 "rtl_glue.h"
extern int32 rtlglue_mbufFreeCluster(void *buffer, uint32 size, uint32 id);
# 242 "rtl_glue.h"
extern int32 rtlglue_mbufClusterRefcnt(void *buffer, uint32 id, uint32 *count, int8 operation);
# 263 "rtl_glue.h"
extern void * rtlglue_mbufClusterToData(void *buffer);
# 272 "rtl_glue.h"
extern int32 rtlglue_drvMutexLock(void);
# 282 "rtl_glue.h"
extern int32 rtlglue_drvMutexUnlock(void);
# 292 "rtl_glue.h"
extern void rtlglue_getMacAddress(ether_addr_t * macAddress, uint32 * number);
# 305 "rtl_glue.h"
extern void rtlglue_drvSend(void * pkthdr);
# 317 "rtl_glue.h"
void rtlglue_extDeviceSend(uint16 vid, int32 linkId, struct rtl_pktHdr *pktHdr);
# 329 "rtl_glue.h"
int32 rtlglue_reclaimRxBD(uint32 rxDescIdx,struct rtl_pktHdr *pThisPkthdr, struct rtl_mBuf *pThisMbuf);



void rtlglue_getRingSize(uint32 *rx, uint32 *tx);

uint32 rtlglue_getsectime(void) ;
uint32 rtlglue_getmstime( uint32* );
void *rtlglue_malloc(uint32);
void rtlglue_free(void *APTR);







uint32 rtl865x_getHZ(void);
# 413 "rtl_glue.h"
void rtlglue_srandom( uint32 seed );






uint32 rtlglue_random( void );






uint32 rtlglue_time( uint32* t );
# 18 "mbuf.c" 2
# 33 "mbuf.c"
int32 m_clusterSize=(-1);




# 1 "mbuf_local.h" 1







struct mcluster_tag
{






        union
        {
                struct mcluster_tag *mclustertag_next;
                struct rtl_mBuf *mbuf_back;
        }
        MCLNXT;



        uint8 cltag_flags;
# 34 "mbuf_local.h"
        uint8 cltag_refcnt;
        uint8 cltag_reserved[2];

};


struct poolstat
{
        uint32 iTotalSize;
        void *pvAddr;
        void *pvFreelist;
        uint32 iFreebufs;
        uint32 iUsedbufs;
        uint32 iWaiting;
};
# 63 "mbuf_local.h"
 memaddr _mbufMsgLogId;
 uint32 _iTotalMbufs;
 uint32 _iTotalClusters;
 uint32 _iTotalPkthdrs;
 struct rtl_mBufStatus _Statistics;
 struct poolstat _MbufStatus,
                                                _ClStatus,
                                                _PHStatus;



 struct rtl_mBuf *_MbufPool;
 uint8 *_ClusterDataPool;
 struct rtl_pktHdr *_PkthdrPool;
 struct mcluster_tag *_ClusterTag;
 uint32 m_clusterShift;
# 39 "mbuf.c" 2

static int32 _mbInited=0;
struct extCluster {
        void *buf;
        uint32 id;
};
static struct extCluster *_clusters;

static int16 _maxRxDescidx= (32767);
# 58 "mbuf.c"
static int32 _iTryGet(uint32 * piAvailableBuffers, uint32 iRequestedBuffers, uint32 * piWaitID, int32 iHow, uint32 * piHaveWaited);
static uint32 _iFreeMbufChain(struct rtl_mBuf *pFirstMbuf, int8 flags);
static void _vWakeup(uint32 * piWaitID);
static void _vInitBufferPools(void *pBufPool, int32 iSize, int32 iNum);
static __inline__ void _vFreePkthdr(struct rtl_pktHdr *ph);
static __inline__ uint8 _iGetClusterDataByte(struct rtl_mBuf *m, uint32 offset, uint32 *offsetTbl, uint32 *lenTbl, uint32 mbufs);
static __inline__ void _vReturnFreeBuffer(void *pvFreeBuffer, struct poolstat *pBufPoolStat);
static __inline__ void *_pvGetFreeBuffer(struct poolstat *pBufPoolStat);
static struct rtl_mBuf *_pCopyPacket(struct rtl_mBuf *pMbuf, uint32 iHow);
# 76 "mbuf.c"
int32 mBuf_init(uint32 nmbufs, uint32 nmbclusters, uint32 nmpkthdrs, uint32 clusterSize, memaddr logId)
{
        uint32 exponent;

        if ( _mbInited!=0)
                return -1;


        rtlglue_mbufMutexLock();

        _iTotalMbufs = nmbufs;

        _iTotalPkthdrs = nmpkthdrs;
        _mbufMsgLogId = logId;

        _MbufPool= (void *) (0x20000000 | (uint32) rtlglue_malloc(_iTotalMbufs *sizeof(struct rtl_mBuf)));

        if(nmbclusters){

                if((isPowerOf2(clusterSize, &exponent)==0)||(clusterSize < sizeof(struct mcluster_tag)))
                        return -1;

                m_clusterSize = clusterSize;
                m_clusterShift = exponent;

                _ClusterDataPool= (void *) (0x20000000 | (uint32) rtlglue_malloc(nmbclusters * clusterSize));
                _ClusterTag= (struct mcluster_tag *)rtlglue_malloc(nmbclusters * sizeof(struct mcluster_tag));
                _iTotalClusters = nmbclusters;
        }else{



                m_clusterSize = clusterSize;
                m_clusterShift =0;
                 _clusters= (struct extCluster *)rtlglue_malloc(sizeof(struct extCluster)*nmbufs);
                 if(!_clusters)
                        return -1;

                memset(_clusters, 0, sizeof(struct extCluster)*nmbufs);
                _iTotalClusters = 0;
                _ClusterDataPool =((void *)0);
                _ClusterTag=((void *)0);
        }

        _PkthdrPool= (void *) (0x20000000 | (uint32) rtlglue_malloc(_iTotalPkthdrs * sizeof(struct rtl_pktHdr)));
        if(!_MbufPool || (nmbclusters&&(!_ClusterDataPool || !_ClusterDataPool)) || !_PkthdrPool)
                return -1;

        if(nmbclusters){
                _vInitBufferPools(_ClusterTag, sizeof(struct mcluster_tag), _iTotalClusters);
                memset((void *) &_ClStatus, (uint8) 0, sizeof(struct poolstat));



                memset((void *) _ClusterDataPool, (uint8) 0,
                           _iTotalClusters * m_clusterSize);
                _ClStatus.pvAddr = _ClStatus.pvFreelist = _ClusterTag;
                _ClStatus.iTotalSize = _ClStatus.iFreebufs = _iTotalClusters;

        }






        _vInitBufferPools(_MbufPool, sizeof(struct rtl_mBuf), _iTotalMbufs);
        _vInitBufferPools(_PkthdrPool, sizeof(struct rtl_pktHdr), _iTotalPkthdrs);




        memset((void *) &_MbufStatus, (uint8) 0, sizeof(struct poolstat));
        memset((void *) &_PHStatus, (uint8) 0, sizeof(struct poolstat));

        _MbufStatus.pvAddr = _MbufStatus.pvFreelist = _MbufPool;
        _MbufStatus.iTotalSize = _MbufStatus.iFreebufs = _iTotalMbufs;


        _PHStatus.pvAddr = _PHStatus.pvFreelist = _PkthdrPool;
        _PHStatus.iTotalSize = _PHStatus.iFreebufs = _iTotalPkthdrs;


        memset((void *) &_Statistics, (uint8) 0, sizeof(struct rtl_mBufStatus));
        _Statistics.m_msize = sizeof(struct rtl_mBuf);
        _Statistics.m_pkthdrsize = sizeof(struct rtl_pktHdr);
        _Statistics.m_mclbytes=m_clusterSize;
        _mbInited = 1;
        rtlglue_mbufMutexUnlock();
        return 0;
}
# 229 "mbuf.c"
int32 mBuf_getBufStat(struct rtl_mBufStatus *mbs){
        if (!mbs || _mbInited!=1)
                return -1;
        mbs->m_totalmbufs=_iTotalMbufs;
        mbs->m_totalclusters=_iTotalClusters;
        mbs->m_totalpkthdrs=_iTotalPkthdrs;
        mbs->m_freembufs= _MbufStatus.iFreebufs;
        mbs->m_freeclusters=_ClStatus.iFreebufs;
        mbs->m_freepkthdrs=_PHStatus.iFreebufs;
        mbs->m_msize = _Statistics.m_msize;
        mbs->m_mclbytes=_Statistics.m_mclbytes;
        mbs->m_pkthdrsize= _Statistics.m_pkthdrsize;
        mbs->m_wait= _Statistics.m_wait;
        return 0;
}





int32 mBuf_leadingSpace(struct rtl_mBuf * m)
{
        int32 retval;

        do {} while (0);
        retval = (int32)(m->m_data - m->m_extbuf);

        return retval;
}

int32 mBuf_reserve(struct rtl_mBuf * m, uint16 headroom){
        do {} while (0);
        do {} while (0);
        if(m->m_len){
                return -1;
        }
        if(m->m_extsize<headroom){
                return -1;
        }
        m->m_data=m->m_extbuf;
        do { do {} while (0); (m)->m_data += ( ((headroom) > (m)->m_extsize)? (m)->m_extsize : headroom); } while (0);
        return 0;
}






int32 mBuf_trailingSpace(struct rtl_mBuf * m)
{
        int32 retval;

        do {} while (0);
        retval = (( (memaddr)m->m_extbuf + m->m_extsize) - ((memaddr)m->m_data + m->m_len));

        return retval;

}




int32 mBuf_clusterIsWritable(struct rtl_mBuf * m)
{
        int32 retval;




        if(!_iTotalClusters)
                return 1;
        if ((&_ClusterTag[( (uint32)m->m_extbuf - (uint32)_ClusterDataPool)>> m_clusterShift ])->MCLNXT.mbuf_back == m)
                retval = ((&_ClusterTag[( (uint32)m->m_extbuf - (uint32)_ClusterDataPool)>> m_clusterShift ])->cltag_refcnt == 1);
        else
                retval = 0;

        return retval;

}


static uint32 _m_getPktlen(struct rtl_mBuf *mp){
        struct rtl_mBuf *m=mp;
        uint32 pktlen=0;
        do {} while (0);
        do {} while (0);


        if(m->m_pkthdr)
                pktlen = m->m_pkthdr->ph_len;
        else{
                pktlen = 0;
                for (;m;)
                {
                        pktlen += m->m_len;
                        if (m->m_next == (struct rtl_mBuf *) 0){
                                m=mp;
                                break;
                        }
                        m = m->m_next;
                }
        }
        return pktlen;
}

uint32 mBuf_getPktlen(struct rtl_mBuf *mp){
        uint32 ret;
        rtlglue_mbufMutexLock();

        ret = _m_getPktlen(mp);
        rtlglue_mbufMutexUnlock();
        return ret;
}
# 356 "mbuf.c"
static struct rtl_mBuf *_m_get(int32 how, uint32 Nbuf)
{
        register int32 iIndex=0, iHow, extClusterAllocated=0;
        register struct rtl_mBuf *pThisMbuf, *pFirstMbuf, *pPrevMbuf;
        register struct mcluster_tag *pThisClusterTag;
        uint32 iMbufWaited;
        uint32 iClusterWaited;
        do {} while (0);
        do {} while (0);

        pThisMbuf = pFirstMbuf = pPrevMbuf = ((void *)0);
        pThisClusterTag = ((void *)0);
        iMbufWaited = iClusterWaited = 0;

        iHow = how;



        if (Nbuf>_MbufStatus.iFreebufs){
                goto out;
        }
        if(Nbuf*m_clusterSize>65536){
                goto out;
        }
        if(_iTryGet(&_MbufStatus.iFreebufs, Nbuf, &_MbufStatus.iWaiting, iHow,&iMbufWaited) == 0)
                goto out;


        if ((((iHow) & (0x04))==0)) {
                if(_iTotalClusters==0){


                        if((((iHow) & (0x01))!=0))
                                goto out;
                        for(extClusterAllocated=0; extClusterAllocated < Nbuf; extClusterAllocated++){
                                if(rtlglue_mbufAllocCluster(&_clusters[extClusterAllocated].buf,m_clusterSize,&_clusters[extClusterAllocated].id)==-1){
                                        int32 release;

                                        for(release=0; release < extClusterAllocated; release++)
                                                rtlglue_mbufFreeCluster(_clusters[release].buf,m_clusterSize,_clusters[release].id);
                                        goto out;
                                }
                                do {} while (0);
                        }
                }else{

                        if ((Nbuf>_iTotalClusters)||
                                (_iTryGet(&_ClStatus.iFreebufs, Nbuf, &_ClStatus.iWaiting, iHow,&iClusterWaited) == 0))
                                        goto out;
                }
        }
        ((iHow) &= ~(0x01));



        if ((((iHow) & (0x04))!=0)){
                for (iIndex = 0; iIndex < Nbuf; iIndex++){
                        do {} while (0);
                        pThisMbuf = (struct rtl_mBuf *) _pvGetFreeBuffer(&_MbufStatus);
                        do {} while (0);
                        memset((void *) pThisMbuf, (uint8) 0, sizeof(struct rtl_mBuf));
                        ((pThisMbuf->m_flags) &= ~(0x10));
                        ((pThisMbuf->m_flags) |= (0x80));
                        pThisMbuf->m_next = ((void *)0);
                        _MbufStatus.iUsedbufs++;

                        if (iIndex == 0)
                                pFirstMbuf = pThisMbuf;
                        else
                                pPrevMbuf->m_next = pThisMbuf;
                        pPrevMbuf = pThisMbuf;
                }
        }else{

                for (iIndex = 0; iIndex < Nbuf; iIndex++)
                {
                        do {} while (0);
                        pThisMbuf = (struct rtl_mBuf *) _pvGetFreeBuffer(&_MbufStatus);

                        do {} while (0);


                        memset((void *) pThisMbuf, (uint8) 0, sizeof(struct rtl_mBuf));
                        ((pThisMbuf->m_flags) |= (0x10 | 0x80));
                        pThisMbuf->m_next = ((void *)0);
                        _MbufStatus.iUsedbufs++;

                        if(_iTotalClusters){
                                do {} while (0);
                                pThisClusterTag = (struct mcluster_tag *) _pvGetFreeBuffer(&_ClStatus);
                                do {} while (0);
                                pThisMbuf->m_extbuf = pThisMbuf->m_data =
                                        (uint8 *) (&_ClusterDataPool[ ((uint32)pThisClusterTag - (uint32)_ClusterTag)<< (m_clusterShift - 3) ]);

                                pThisClusterTag->cltag_refcnt = 1;
                                ((pThisClusterTag->cltag_flags) |= (0x80));
                                pThisClusterTag->MCLNXT.mbuf_back = pThisMbuf;
                        }else{
                                pThisMbuf->m_extbuf = pThisMbuf->m_data = (uint8 *)_clusters[iIndex].buf;
                                pThisMbuf->m_extClusterId = _clusters[iIndex].id;
                        }
                        pThisMbuf->m_len = 0;
                        pThisMbuf->m_extsize = m_clusterSize;

                        if (iIndex == 0)
                                pFirstMbuf = pThisMbuf;
                        else
                                pPrevMbuf->m_next = pThisMbuf;
                        pPrevMbuf = pThisMbuf;

                }
        }

        if(_iTotalClusters){




                if (iClusterWaited == 1 && _ClStatus.pvFreelist) {
                        _Statistics.m_wait++;
                        _vWakeup(&_ClStatus.iWaiting);
                }
                else if (iMbufWaited == 1 && _MbufStatus.pvFreelist){
                        _Statistics.m_wait++;
                        _vWakeup(&_MbufStatus.iWaiting);
                }
        }
out:

        if (iIndex == Nbuf)
                return (pFirstMbuf);

        return ((void *)0);
}


 struct rtl_mBuf *mBuf_get(int32 how, int32 type, uint32 Nbuf){

        struct rtl_mBuf *m;
        rtlglue_mbufMutexLock();
        m=_m_get( how, Nbuf);
        rtlglue_mbufMutexUnlock();
        return m;
}



struct rtl_mBuf *mBuf_attachHeader(void *buffer, uint32 id, uint32 bufsize,uint32 datalen, uint16 align){
        struct rtl_mBuf *m=((void *)0);
        struct rtl_pktHdr *ph=((void *)0);
        rtlglue_mbufMutexLock();


        if (!_MbufStatus.iFreebufs||!_PHStatus.iFreebufs||(align &&align>=bufsize))
                goto out;
        m = (struct rtl_mBuf *) _pvGetFreeBuffer(&_MbufStatus);
        _MbufStatus.iUsedbufs++;

        ph = (struct rtl_pktHdr *) _pvGetFreeBuffer(&_PHStatus);
        _PHStatus.iUsedbufs++;

        ph->PKTHDRNXT.mbuf_first = m;
        ph->ph_len = datalen;
        ph->ph_flags= (0x80 << 8);
        *((uint16 *)((uint8 *)ph)+8)=0;

        ph->ph_iphdrOffset=0;
        ph->ph_pppeTagged = 0;
        ph->ph_LLCTagged = 0;
        ph->ph_vlanTagged = 0;


        ph->ph_rxdesc=_maxRxDescidx;
        m->m_next = ((void *)0);
        m->m_pkthdr = ph;
        m->m_len=datalen;
        m->m_flags=0x80|0x10|0x08;
        m->m_data = ((uint8 *)buffer)+align;
        m->m_extbuf=buffer;
        m->m_extClusterId = id;
        m->m_extsize= bufsize;
out:
        rtlglue_mbufMutexUnlock();
        return m;
 }


int mBuf_attachHeaderLSO(uint32 skb_len,uint32 skb_data_len,uint8 *skb_data,uint32 skb,uint8 protocol, struct rtl_mBuf *m[32]){

        struct rtl_pktHdr *ph[32],*phi;
        struct rtl_mBuf *mi;
        int loop=0,size=skb_data_len;
        uint32 header_len=(skb_len-skb_data_len);
        uint32 mss=1514-header_len;
        rtlglue_mbufMutexLock();


        if(protocol==0x06)
        {
                while(1)
                {
                        size-=mss;
                        loop++;
                        if(size<=0) break;
                }




                if((loop>1) && ((loop&1)==1))
                {
                        mss=(skb_data_len/(loop+1))+1;



                        if(mss&1) mss++;
                }
                loop=0;
                size=skb_data_len;
        }

        while(1)
        {
                if (!_MbufStatus.iFreebufs||!_PHStatus.iFreebufs)
                        goto out;

                m[loop] = (struct rtl_mBuf *) _pvGetFreeBuffer(&_MbufStatus);
                _MbufStatus.iUsedbufs++;

                ph[loop] = (struct rtl_pktHdr *) _pvGetFreeBuffer(&_PHStatus);
                _PHStatus.iUsedbufs++;

                mi=m[loop];
                phi=ph[loop];

                phi->PKTHDRNXT.mbuf_first = mi;
                phi->ph_flags= (0x80 << 8);
                phi->ph_iphdrOffset=0;
                phi->ph_pppeTagged = 0;
                phi->ph_LLCTagged = 0;
                phi->ph_vlanTagged = 0;


                phi->ph_un_sw.PS_USG.FROM_PS._ph_pkt_property = 0;
                phi->ph_un_sw.PS_USG.FROM_PS._ph_pkt_property |= (1<<1);
                phi->ph_un_sw.PS_USG.FROM_PS._ph_pkt_property |= (1<<2);

                *((uint16 *)((uint8 *)ph)+8)=0;
                phi->ph_rxdesc=_maxRxDescidx;
                mi->m_next = ((void *)0);
                mi->m_pkthdr = phi;
                mi->m_flags=0x80|0x10|0x08;

                mi->m_len = phi->ph_len = header_len+((size>mss)?mss:size);
                size-=mss;
                mi->m_extbuf = mi->m_data = (uint8*)((uint32)skb_data|0x20000000)+mss*loop;

                if(size<=0)
                {
                        mi->m_extClusterId = (uint32)skb;
                        break;
                }
                mi->m_extClusterId = 0;
                mi->m_extsize= mi->m_len;
                loop++;
        }

        rtlglue_mbufMutexUnlock();
        return 0;

out:
        rtlglue_mbufMutexUnlock();
        return -1;

 }
# 913 "mbuf.c"
static struct rtl_mBuf *_m_gethdr(struct rtl_mBuf *pMbuf, int32 how){
        int32 iLen = 0;
        struct rtl_mBuf *pThisMbuf = ((void *)0);
        struct rtl_pktHdr *pPkthdr = ((void *)0);
        uint32 PkthdrWaited;

        do {} while (0);
        do {} while (0);

        iLen = pMbuf->m_len;

        for (pThisMbuf = pMbuf->m_next; pThisMbuf; pThisMbuf = pThisMbuf->m_next)
        {

                if ((((pThisMbuf->m_flags) & (0x08))!=0)){
                        do {} while (0);
                        do {} while (0);
                        pPkthdr = pThisMbuf->m_pkthdr;
                        pMbuf->m_pkthdr = pPkthdr;
                        pPkthdr->PKTHDRNXT.mbuf_first = pMbuf;
                        pPkthdr->ph_len += iLen;
                        ((pMbuf->m_flags) |= (0x08));
                        for (; pThisMbuf && (pThisMbuf->m_next != ((void *)0)); pThisMbuf = pThisMbuf->m_next)
                                ((pThisMbuf->m_flags) &= ~(0x08));
                        return pMbuf;
                }
                iLen += pThisMbuf->m_len;
        }







        if ((!_PHStatus.pvFreelist) &&
                (_iTryGet(&_PHStatus.iFreebufs, 1, &_PHStatus.iWaiting, how, &PkthdrWaited) == 0))
                        goto out;




        do {} while (0);
        pPkthdr = (struct rtl_pktHdr *) _pvGetFreeBuffer(&_PHStatus);
        do {} while (0);
        memset((void *) pPkthdr, (uint8) 0, sizeof(struct rtl_pktHdr));
        ((pPkthdr->ph_flags) |= ((0x80 << 8)));
        pPkthdr->PKTHDRNXT.mbuf_first = pMbuf;
        pPkthdr->ph_len += iLen;
        pMbuf->m_pkthdr = pPkthdr;
        ((pMbuf->m_flags) |= (0x08));


        for (pThisMbuf = pMbuf->m_next; pThisMbuf;pThisMbuf = pThisMbuf->m_next)
                pThisMbuf->m_pkthdr = pPkthdr;

        if (PkthdrWaited == 1 && _PHStatus.pvFreelist){
                _Statistics.m_wait++;
                _vWakeup(&_PHStatus.iWaiting);
        }

out:
        if (pPkthdr)
                return pMbuf;
        else
                return ((void *)0);
}


 struct rtl_mBuf *mBuf_getPkthdr(struct rtl_mBuf *pMbuf, int32 how){
        struct rtl_mBuf *m;
        rtlglue_mbufMutexLock();
        m = _m_gethdr( pMbuf, how);

        m->m_pkthdr->ph_rxdesc=_maxRxDescidx;
        m->m_pkthdr->ph_un_sw.ROMEDRV_USG._ph_priority = 0;
        rtlglue_mbufMutexUnlock();
        return m;

 }




void mBuf_freePkthdr(struct rtl_pktHdr *ph){
        rtlglue_mbufMutexLock();
        _vFreePkthdr(ph);
        rtlglue_mbufMutexUnlock();
}







struct rtl_mBuf *mBuf_getm(struct rtl_mBuf *m, uint32 len, int32 how, int32 type){
        register struct rtl_mBuf *pMbuf = m, *mtail = ((void *)0), *p=((void *)0);
        register int32 trailing_len = 0, Nbuf = 0;

        do {} while (0);
        do {} while (0);


        if(len> 65535)
                return pMbuf;

        rtlglue_mbufMutexLock();

        if (m != ((void *)0)){
                do {} while (0);
                for (mtail = m; mtail->m_next != ((void *)0); mtail = mtail->m_next) ;
                trailing_len = mBuf_trailingSpace(mtail);

                if (trailing_len >= len)
                        goto out;
                len -= trailing_len;
        }


        Nbuf = ((len - 1) / m_clusterSize) + 1;
        do {} while (0);

        ((how) &= ~(0x04));


        pMbuf = _m_get(how, Nbuf);

        if (!pMbuf)
                goto out;

        if (m != ((void *)0)) {
                if(m->m_pkthdr){
                        for (p = pMbuf; p; p = p->m_next)
                                p->m_pkthdr = m->m_pkthdr;
                }
                mtail->m_next = pMbuf;
                pMbuf = m;
        }else{


                if ((((how) & (0x08))!=0) && (pMbuf != _m_gethdr(pMbuf, how))){
                        _iFreeMbufChain(m, 1);
                        pMbuf = ((void *)0);
                        goto out;
                }
                pMbuf->m_pkthdr->ph_rxdesc=_maxRxDescidx;

                for (p = pMbuf; p; p = p->m_next)
                        p->m_pkthdr = pMbuf->m_pkthdr;
        }
out:
        rtlglue_mbufMutexUnlock();
        return pMbuf;

}





struct rtl_mBuf *mBuf_prepend(struct rtl_mBuf *m, uint32 plen, int32 how){
        struct rtl_mBuf *pMbuf=m, *mm;
        int32 leading_len, Nbuf, start;
        int32 count=0;


        do {} while (0);
        do {} while (0);

        rtlglue_mbufMutexLock();


        if ((((how) & (0x10))!=0))
                leading_len = 0;
        else
                leading_len = mBuf_leadingSpace(m);


        if (leading_len >= plen){
                m->m_data -= plen;
                m->m_len += plen;
                if(m->m_pkthdr)
                        m->m_pkthdr->ph_len +=plen;
                do {} while (0);
                goto out;
        }
        if(leading_len){


                m->m_data -= leading_len;
                m->m_len += leading_len;
                if(m->m_pkthdr)
                        m->m_pkthdr->ph_len += leading_len;
                plen -= leading_len;
        }
        count = leading_len;



        Nbuf = ((plen - 1) / m_clusterSize) + 1;
        start = (Nbuf*m_clusterSize)-plen;

        ((how) &= ~(0x04));


        pMbuf = _m_get(how, Nbuf);
        if (!pMbuf)
                goto out;

        do {} while (0);


        for (mm = pMbuf; mm; mm = mm->m_next){

                do {} while (0);
                if(mm==pMbuf){
                        pMbuf->m_data += start;
                        pMbuf->m_len = m->m_extsize - start;
                        count+= pMbuf->m_len;
                }else{
                        mm->m_len = mm->m_extsize;
                        count+=mm->m_extsize;
                }
                if(m->m_pkthdr){
                        mm->m_pkthdr = m->m_pkthdr;
                        m->m_pkthdr->ph_len+=mm->m_len;
                }
                if(mm->m_next==((void *)0)){
                        mm->m_next = m;
                        if(m->m_pkthdr){
                                ((pMbuf->m_flags) |= (0x08));
                                m->m_pkthdr->PKTHDRNXT.mbuf_first = pMbuf;
                                ((m->m_flags) &= ~(0x08));
                                do {} while (0);

                        }
                        break;
                }
        }
out:
        rtlglue_mbufMutexUnlock();
        return pMbuf;
}






struct rtl_mBuf *mBuf_padding(struct rtl_mBuf *m, uint32 plen, int32 how){
        struct rtl_mBuf *pLastMbuf=((void *)0), *pLastMbufNext, *pNewMbuf, *mm;
        int32 trailing_len, Nbuf, end;
        int32 count=0;


        do {} while (0);
        do {} while (0);

        rtlglue_mbufMutexLock();

        for(pLastMbuf=m, pLastMbufNext=m->m_next; pLastMbufNext; pLastMbuf=pLastMbuf->m_next, pLastMbufNext=pLastMbufNext->m_next);

        trailing_len = mBuf_trailingSpace(pLastMbuf);


        if (trailing_len >= plen){

                pLastMbuf->m_len += plen;
                if(m->m_pkthdr)
                        m->m_pkthdr->ph_len +=plen;
                goto out;
        }



        pLastMbuf->m_len += trailing_len;
        if(m->m_pkthdr)
                m->m_pkthdr->ph_len += plen;
        count = trailing_len;

        plen -= trailing_len;


        Nbuf = ((plen - 1) / m_clusterSize) + 1;
        end = (Nbuf*m_clusterSize)-plen;

        ((how) &= ~(0x04));
        pNewMbuf = _m_get(how, Nbuf);
        if (!pNewMbuf){
                rtlglue_mbufMutexUnlock();
                return ((void *)0);
        }

        do {} while (0);

        pLastMbuf->m_next = pNewMbuf;


        for (mm = pNewMbuf; mm; mm = mm->m_next)
        {

                do {} while (0);

                if(m->m_pkthdr){
                        mm->m_pkthdr = m->m_pkthdr;
                }
                if(mm->m_next != ((void *)0)) {
                        mm->m_len = mm->m_extsize;
                        memset((void *)mm->m_data, 0, mm->m_len);
                        count+=mm->m_len;
                } else {
                        mm->m_len = mm->m_extsize-end;
                        memset((void *)mm->m_data, 0, mm->m_len);
                        count+=mm->m_len;
                        do {} while (0);
                        pLastMbuf = mm;
                        break;
                }
        }
out:
        rtlglue_mbufMutexUnlock();
        return pLastMbuf;
}


int32 mBuf_freeOneMbufPkthdr(struct rtl_mBuf *m, void **buffer, uint32 *id, uint16 *size){
        uint32 ret;
        do {} while (0);
        rtlglue_mbufMutexLock();
        if(buffer)
                *buffer =(void *)m->m_extbuf;
        if(id)
                *id =m->m_extClusterId;
        if(size)
                *size = m->m_extsize;
        ret=_iFreeMbufChain(m, 4 | 2);
        rtlglue_mbufMutexUnlock();
        return ret;
}


int32 mBuf_attachCluster(struct rtl_mBuf *m, void *buffer, uint32 id, uint32 size, uint16 datalen, uint16 align){
        int32 retval = -1;
        struct rtl_pktHdr *ph;
        ph=m->m_pkthdr;
        rtlglue_mbufMutexLock();

        if((((m->m_flags) & (0x80|0x08))==0))
                goto out;
        ((m->m_flags) |= (0x10));

        m->m_extbuf=buffer;
        m->m_extClusterId = id;
        m->m_extsize= size;

        if(datalen){
                if(datalen+align>size)
                        goto out;
                m->m_len=datalen;
                m->m_data = ((uint8 *)buffer)+align;
        }else{
                m->m_len=0;
                m->m_data = ((uint8 *)buffer);
        }

        retval = 0;
out:
        rtlglue_mbufMutexUnlock();
        return retval;
}




struct rtl_mBuf *mBuf_freeOne(struct rtl_mBuf *m)
{

        struct rtl_mBuf *n = ((void *)0);
        rtlglue_mbufMutexLock();
        do {} while (0);
        do {} while (0);
        if (m->m_next)
                n = m->m_next;
         _iFreeMbufChain(m, 2);
        rtlglue_mbufMutexUnlock();
        return n;
}



uint32 mBuf_freeMbufChain(register struct rtl_mBuf * m){
        int32 i = 0;

        do {} while (0);
        do {} while (0);

        rtlglue_mbufMutexLock();
        i = _iFreeMbufChain(m, 1);
        rtlglue_mbufMutexUnlock();
        if (i > 0)
                return i;
        else
                return 0;

}
# 1332 "mbuf.c"
int32 mBuf_copyToMbuf(struct rtl_mBuf * m0, uint32 offset, register uint32 len, int8 * cp)
{
         int32 mlen;
         struct rtl_mBuf *m = m0, *n;
         uint32 off = offset;
        int32 totlen = 0;


        do {} while (0);
        rtlglue_mbufMutexLock();
        if(mBuf_clusterIsWritable(m)==0){
                rtlglue_mbufMutexUnlock();
                return -1;
        }

        do {} while (0);
        mlen = m->m_len;
        while (off > mlen){
                off -= mlen;
                totlen += mlen;
                if (m->m_next == 0){
                        if(totlen < offset)
                        {
                                rtlglue_mbufMutexUnlock();
                                return -1;
                        }
                }
                m = m->m_next;
        }
        while (len > 0){
                int32 maxLen;
                do {} while (0);
                if (m->m_len)
                        mlen= ({ const typeof(mBuf_trailingSpace(m)+m->m_len - off) _x = (mBuf_trailingSpace(m)+m->m_len - off); const typeof(len) _y = (len); (void) (&_x == &_y); _x < _y ? _x : _y; });
                else
                        mlen = ({ const typeof((uint32)m->m_extsize) _x = ((uint32)m->m_extsize); const typeof((uint32) len) _y = ((uint32) len); (void) (&_x == &_y); _x < _y ? _x : _y; });


                maxLen = totlen + m->m_len + mlen;
                if(maxLen > 65535)
                        mlen= 65535-totlen-m->m_len;

                rtl8651_memcpy( (void *) (off + ((int8 *)((m)->m_data))),(void *) cp,(uint32) mlen);
                cp += mlen;
                len -= mlen;
                mlen += off;
                off = 0;
                totlen += mlen;
                if(m->m_len < mlen+off)
                        m->m_len = mlen+off;

                if (len == 0 || maxLen>65535)
                        break;
                if (m->m_next == 0){
                        n = _m_get(0x02, 1);
                        if (n == 0)
                                break;
                        n->m_len = ({ const typeof(m_clusterSize) _x = (m_clusterSize); const typeof((int32)len) _y = ((int32)len); (void) (&_x == &_y); _x < _y ? _x : _y; });
                        m->m_next = n;
                }
                m = m->m_next;
        }

        if (((m = m0)->m_flags & 0x08)&& (m->m_pkthdr->ph_len < totlen))
                m->m_pkthdr->ph_len = totlen;
        rtlglue_mbufMutexUnlock();
        return totlen;
}



void mBuf_getBMjmpTable(uint8 *pat, uint16 *jump_tbl,uint16 patLen, uint8 caseSensitive) {
        uint32 i;
        rtlglue_mbufMutexLock();
        for(i=0; i<256; i++)
                jump_tbl[i]= patLen;

        if (caseSensitive == 0)
        {
                for(i = 0; i < patLen - 1; i++)
                {
                        jump_tbl[(uint16) __tolower(pat[i])] = patLen -i -1;
                        jump_tbl[(uint16) __toupper(pat[i])] = patLen -i -1;
                }
        }
        else
        {
        for(i=0; i< patLen-1; i++)
                jump_tbl[(uint16) pat[i]]= patLen -i -1;
        }
        rtlglue_mbufMutexUnlock();
}
# 1434 "mbuf.c"
int32 mBuf_BMpatternMatch(struct rtl_mBuf *m, uint32 len, uint8 *delimiter, uint32 delimitLen, uint16 *jmp_tbl, uint8 caseSensitive) {
        int32 retval= -1;


        do {} while (0);
        rtlglue_mbufMutexLock();
        if(m->m_data + len <= m->m_extbuf + m->m_extsize){

                int32 i,j,k;
                uint8 *mem= (uint8 *)m->m_data;

                if (caseSensitive == 0)
                {
                        for(i = delimitLen -1; i < len; ){
                                for(j = delimitLen - 1, k = i; j >= 0 && (__tolower(mem[k]) == delimiter[j]); k--, j--);
                                if (j < 0) {
                                        retval = k+1;
                                        goto out;
                                }else
                                        i+=jmp_tbl[(uint16)mem[i]];
                        }
                }
                else
                {
                for(i=delimitLen -1; i < len; ){
                        for(j=delimitLen-1, k=i; j>=0 && (mem[k]==delimiter[j]); k--, j--);
                        if (j<0){
                                retval = k+1;
                                goto out;
                        }else
                                i+=jmp_tbl[(uint16)mem[i]];
                }
                }
        }else{


                struct rtl_mBuf *p;
                int32 i,j,k;
                uint32 offsetTbl[16], lenTbl[16],mbufs, num=0;


                for(mbufs=0, p=m; p; p=p->m_next, mbufs++){
                        offsetTbl[mbufs]=num+p->m_len;
                        lenTbl[mbufs]=p->m_len;
                        num +=p->m_len;
                }

                if (caseSensitive == 0)
                {
                        for(i=delimitLen -1; i < len; ){
                                for(j=delimitLen-1, k=i; j>=0 && __tolower(_iGetClusterDataByte(m, k,offsetTbl,lenTbl,mbufs)) ==delimiter[j]; k--, j--);
                                if (j<0){
                                        retval = k+1;
                                        goto out;
                                }else
                                        i+=jmp_tbl[(uint16)_iGetClusterDataByte(m, i, offsetTbl,lenTbl,mbufs)];
                        }
                }
                else
                {
                for(i=delimitLen -1; i < len; ){
                        for(j=delimitLen-1, k=i; j>=0 && _iGetClusterDataByte(m, k,offsetTbl,lenTbl,mbufs) ==delimiter[j]; k--, j--);
                        if (j<0){
                                retval = k+1;
                                goto out;
                        }else
                                i+=jmp_tbl[(uint16)_iGetClusterDataByte(m, i, offsetTbl,lenTbl,mbufs)];
                }
        }
        }
out:
        rtlglue_mbufMutexUnlock();
        return retval;
}






int32 mBuf_copyToUserBuffer(struct rtl_mBuf * m, uint32 off, uint32 len, int8 * cp)
{
        register uint32 count;
        register uint32 copied = 0;


        rtlglue_mbufMutexLock();
        while (off > 0)
        {
                do {} while (0);
                do {} while (0);
                if (off < m->m_len)
                        break;
                off -= m->m_len;
                m = m->m_next;
        }
        while (len > 0)
        {
                do {} while (0);
                do {} while (0);
                count = ({ const typeof(m->m_len - off) _x = (m->m_len - off); const typeof(len) _y = (len); (void) (&_x == &_y); _x < _y ? _x : _y; });
                rtl8651_memcpy( cp,((int8 *)((m)->m_data)) + off, count);
                len -= count;
                copied += count;
                cp += count;
                off = 0;
                m = m->m_next;
        }
        rtlglue_mbufMutexUnlock();
        return copied;
}
# 1600 "mbuf.c"
struct rtl_mBuf *mBuf_dupPacket(struct rtl_mBuf *pMbuf, int32 iHow){
        struct rtl_mBuf *m;
        rtlglue_mbufMutexLock();
        m = _pCopyPacket(pMbuf, iHow);
        rtlglue_mbufMutexUnlock();
        return m;
}
# 1667 "mbuf.c"
struct rtl_mBuf *mBuf_adjHead(struct rtl_mBuf *mp, uint32 req_len){
         uint32 len = req_len;
         struct rtl_mBuf *m=mp;
         uint32 adjusted=0, toomuch=0;


        do {} while (0);
        do {} while (0);

        if((((m->m_flags) & (0x10))==0))
                return ((void *)0);

        rtlglue_mbufMutexLock();

        while (m != ((void *)0) && len > 0) {
                do {} while (0);
                if (m->m_len <= len){
                        len -= m->m_len;
                        adjusted+= m->m_len;
                        m->m_len = 0;
                        m->m_data = m->m_extbuf;
                        m = m->m_next;
                }else{
                        m->m_len -= len;
                        adjusted+= len;

                        if(m->m_len==0)
                        {
                                m->m_data = m->m_extbuf;
                        }
                        else
                                m->m_data += len;
                        len = 0;
                        do {} while (0);
                        break;
                }
        }
        if(len>0)
                toomuch=1;
        if (mp->m_pkthdr)
                mp->m_pkthdr->ph_len -= adjusted;
        rtlglue_mbufMutexUnlock();
        if(toomuch)
                return mp;
        else
                return m;
}

struct rtl_mBuf *mBuf_adjTail(struct rtl_mBuf *mp, uint32 req_len){
         uint32 len = req_len;
         struct rtl_mBuf *m=mp, *n=((void *)0);
         uint32 pktlen, drop;
         uint32 adjusted=0;


        do {} while (0);
        do {} while (0);
        do {} while (0);

        if((((m->m_flags) & (0x10))==0)){
                return ((void *)0);
        }

        rtlglue_mbufMutexLock();

        pktlen = _m_getPktlen(mp);

        if(len>pktlen)
                len = pktlen;
        drop = pktlen - len;
# 1749 "mbuf.c"
        m = mp;
        n = ((void *)0);
        adjusted=0;
        for (; m; n=m, m = m->m_next)
        {
                do {} while (0);
                if (m->m_len >= drop)
                {
                        adjusted+= (m->m_len - drop);
                        if (drop==0){
                                do {} while (0);
                                m->m_data = m->m_extbuf;
                        }
                        m->m_len = drop;
                        break;
                }
                drop -= m->m_len;
        }




        n = m->m_next;
        if(!n && (m->m_len==0)){
                m = mp;
                goto done;
        }

        while (n){
                adjusted+= n->m_len;
                n->m_len = 0;
                n->m_data = n->m_extbuf;
                n = n->m_next;
        }

done:
        if (mp->m_pkthdr)
                mp->m_pkthdr->ph_len -= adjusted;

        rtlglue_mbufMutexUnlock();
        return m;
}
# 2068 "mbuf.c"
uint32 mBuf_driverGetPkthdr(uint32 Npkthdr, struct rtl_pktHdr **ppFirstPkthdr, struct rtl_pktHdr **ppTailPkthdr){

         int32 iIndex;
         struct rtl_pktHdr *pThisPkthdr=((void *)0),*pPrevPkthdr=((void *)0);
        rtlglue_mbufMutexLock();

        Npkthdr = ({ const typeof(Npkthdr) _x = (Npkthdr); const typeof(_PHStatus.iFreebufs) _y = (_PHStatus.iFreebufs); (void) (&_x == &_y); _x < _y ? _x : _y; });
        if (Npkthdr==0){
                rtlglue_mbufMutexUnlock();
                return 0;
        }


        for (iIndex = 0; iIndex < Npkthdr; iIndex++){
                do {} while (0);
                pThisPkthdr = _PHStatus.pvFreelist;
                _PHStatus.iFreebufs--;



                _PHStatus.pvFreelist = (uint32 *) (*((uint32 *) pThisPkthdr));



                pThisPkthdr->ph_flags= (0x80 << 8)|(0x40<<8);
                pThisPkthdr->ph_nextHdr=((void *)0);
                pThisPkthdr->ph_len=0;
                pThisPkthdr->ph_rxdesc=_maxRxDescidx;

                if (iIndex != 0)
                        pPrevPkthdr->ph_nextHdr = pThisPkthdr;
                else
                        *ppFirstPkthdr = pThisPkthdr;
                pPrevPkthdr = pThisPkthdr;
        }
        do {} while (0);
        rtlglue_mbufMutexUnlock();
        *ppTailPkthdr = pThisPkthdr;
        return (iIndex);
}







uint32 mBuf_driverFreePkthdr(struct rtl_pktHdr *ph, uint32 Npkthdr, struct rtl_pktHdr **ppHeadPkthdr)
{
        register struct rtl_pktHdr *pThisPkthdr = ph, *pNextPkthdr = ((void *)0);
        register uint32 iFreed = 0;
        rtlglue_mbufMutexLock();
        while (iFreed<Npkthdr && pThisPkthdr && (((pThisPkthdr->ph_flags) & ((0x80 << 8)))!=0))
        {

                ((ph->ph_flags) &= ~((0x80 << 8)));

                *((uint32 *) pThisPkthdr) = (uint32) _PHStatus.pvFreelist;
                _PHStatus.pvFreelist = pThisPkthdr;
                _PHStatus.iFreebufs++;
                pNextPkthdr = pThisPkthdr->ph_nextHdr;
                iFreed++;
                pThisPkthdr = pNextPkthdr;
        }
        if(ppHeadPkthdr)
                *ppHeadPkthdr = pNextPkthdr;
        rtlglue_mbufMutexUnlock();
        return iFreed;
}





uint32 mBuf_driverGet(uint32 Nmbuf,struct rtl_mBuf **ppFirstMbuf, struct rtl_mBuf **ppTailMbuf)
{

        register uint32 iIndex, extClusterAllocated=0;
        register struct rtl_mBuf *pThisMbuf=((void *)0),*pPrevMbuf=((void *)0);
        register struct mcluster_tag *pThisClusterTag=((void *)0);
        rtlglue_mbufMutexLock();

        Nmbuf = ({ const typeof(Nmbuf) _x = (Nmbuf); const typeof(_MbufStatus.iFreebufs) _y = (_MbufStatus.iFreebufs); (void) (&_x == &_y); _x < _y ? _x : _y; });
        if(_iTotalClusters){
                Nmbuf = ({ const typeof(Nmbuf) _x = (Nmbuf); const typeof(_ClStatus.iFreebufs) _y = (_ClStatus.iFreebufs); (void) (&_x == &_y); _x < _y ? _x : _y; });
                if (Nmbuf==0){
                        rtlglue_mbufMutexUnlock();
                        return 0;
                }
        }else{
                for(extClusterAllocated=0; extClusterAllocated < Nmbuf; extClusterAllocated++){
                        if(rtlglue_mbufAllocCluster(&_clusters[extClusterAllocated].buf,m_clusterSize,&_clusters[extClusterAllocated].id)==-1){
                                int32 release;

                                for(release=0; release < extClusterAllocated; release++)
                                        rtlglue_mbufFreeCluster(_clusters[extClusterAllocated].buf,m_clusterSize,_clusters[release].id);
                                rtlglue_mbufMutexUnlock();
                                return 0;
                        }
                }
        }


        for (iIndex = 0; iIndex < Nmbuf; iIndex++){



                do {} while (0);
                pThisMbuf = _MbufStatus.pvFreelist;
                _MbufStatus.iFreebufs--;
                _MbufStatus.pvFreelist = (uint32 *) (*((uint32 *) pThisMbuf));

                if(_iTotalClusters){

                        do {} while (0);
                        pThisClusterTag = _ClStatus.pvFreelist;
                        _ClStatus.iFreebufs--;
                        _ClStatus.pvFreelist = (uint32 *) (*((uint32 *) pThisClusterTag));
                }
                pThisMbuf->m_next = ((void *)0);
                pThisMbuf->m_pkthdr= 0;
                pThisMbuf->m_len = 0;
                pThisMbuf->m_flags = 0x10 | 0x80;
                _MbufStatus.iUsedbufs++;

                if(_iTotalClusters){
                        pThisMbuf->m_extbuf = pThisMbuf->m_data =
                                (uint8 *) (&_ClusterDataPool[ ((uint32)pThisClusterTag - (uint32)_ClusterTag)<< (m_clusterShift - 3) ]);
                        pThisClusterTag->MCLNXT.mbuf_back = pThisMbuf;
                        pThisClusterTag->cltag_flags = 0x80;
                        pThisClusterTag->cltag_refcnt = 1;
                }else{
                        pThisMbuf->m_extbuf = pThisMbuf->m_data = (uint8 *)_clusters[iIndex].buf;
                        pThisMbuf->m_extClusterId = _clusters[iIndex].id;
                }
                pThisMbuf->m_extsize = _Statistics.m_mclbytes;

                if (iIndex != 0)
                        pPrevMbuf->m_next = pThisMbuf;
                else
                        *ppFirstMbuf = pThisMbuf;
                pPrevMbuf = pThisMbuf;
        }
        do {} while (0);
        rtlglue_mbufMutexUnlock();
        *ppTailMbuf = pThisMbuf;
        return (iIndex);
}






uint32 mBuf_driverFreeMbufChain(struct rtl_mBuf *pFirstMbuf)
{
        register struct rtl_mBuf *pThisMbuf = pFirstMbuf, *pNextMbuf = ((void *)0);
        register struct mcluster_tag *pThisClusterTag = ((void *)0);
        struct rtl_pktHdr * pThisPkthdr=((void *)0);
        register uint32 iFreed = 0;

        rtlglue_mbufMutexLock();
        if(pThisMbuf->m_flags & 0x08){
                int32 rxDescIdx;
                pThisPkthdr=pThisMbuf->m_pkthdr;
                rxDescIdx=pThisPkthdr->ph_rxdesc;
                if(rxDescIdx>=0&&rxDescIdx<_maxRxDescidx){
                        if(rtlglue_reclaimRxBD(rxDescIdx, pThisPkthdr, pThisMbuf))
                                goto free;
                        iFreed=1;
                        goto out;
                }
        }

free:

        while (pThisMbuf && (((pThisMbuf->m_flags) & (0x80))!=0))
        {

                if (pThisMbuf->m_flags & 0x10)
                {
                        if(_iTotalClusters){
                                pThisClusterTag = (&_ClusterTag[( (uint32)pThisMbuf->m_data - (uint32)_ClusterDataPool)>> m_clusterShift ]);

                                pThisClusterTag->cltag_refcnt--;
                                if (pThisClusterTag->cltag_refcnt == 0)
                                {
                                        ((pThisClusterTag->cltag_flags) &= ~(0x80));


                                        *((uint32 *) pThisClusterTag) = (uint32) _ClStatus.pvFreelist;
                                        _ClStatus.pvFreelist = pThisClusterTag;
                                        _ClStatus.iFreebufs++;
                                }
                                else if (pThisClusterTag->MCLNXT.mbuf_back == pThisMbuf)
                                {



                                        pThisClusterTag->MCLNXT.mbuf_back = ((void *)0);
                                }

                        }else{
                                uint32 count;
                                if(pThisMbuf->m_extClusterId){
                                        rtlglue_mbufClusterRefcnt(pThisMbuf->m_extbuf, pThisMbuf->m_extClusterId, &count, 0);
                                        if(count==1){

                                                rtlglue_mbufFreeCluster(pThisMbuf->m_extbuf, m_clusterSize, pThisMbuf->m_extClusterId);
                                        }else
                                                rtlglue_mbufClusterRefcnt(pThisMbuf->m_extbuf, pThisMbuf->m_extClusterId, &count, 2);
                                }

                        }
                }

                if (pThisMbuf->m_pkthdr)
                {
                        if (pThisMbuf->m_flags & 0x08)
                        {
                                ((pThisMbuf->m_pkthdr->ph_flags) &= ~((0x80 << 8)));
                                *((uint32 *) pThisMbuf->m_pkthdr) = (uint32) _PHStatus.pvFreelist;
                                _PHStatus.pvFreelist = pThisMbuf->m_pkthdr;
                                _PHStatus.iFreebufs++;

                                pThisMbuf->m_pkthdr = ((void *)0);
                                ((pThisMbuf->m_flags) &= ~(0x08));
                        }
                        else
                                pThisMbuf->m_pkthdr = ((void *)0);
                }




                _MbufStatus.iUsedbufs--;
                pThisMbuf->m_flags = 0x00;
                pNextMbuf = pThisMbuf->m_next;
                *((uint32 *) pThisMbuf) = (uint32) _MbufStatus.pvFreelist;
                _MbufStatus.pvFreelist = pThisMbuf;
                _MbufStatus.iFreebufs++;
                iFreed++;
                pThisMbuf = pNextMbuf;
        }
out:
        rtlglue_mbufMutexUnlock();
        return iFreed;
}

int32 mBuf_setNICRxRingSize(uint32 size){
        if ( _mbInited==0)
                return -1;
        if (size>_iTotalPkthdrs)
                return -1;
        _maxRxDescidx=size;
        return 0;
}
# 2343 "mbuf.c"
static void _vWakeup(uint32 * piWaitID)
{

        do {} while (0);

        if (piWaitID){
                (*piWaitID)--;
                rtlglue_mbufTwakeup((uint32)piWaitID);
        }
        return;
}

static __inline__ void _vFreePkthdr(struct rtl_pktHdr *ph){
                do {} while (0);
                ((ph->ph_flags) &= ~((0x80 << 8)));
                _vReturnFreeBuffer(ph, &_PHStatus);
}





static __inline__ uint8 _iGetClusterDataByte(struct rtl_mBuf *m, uint32 offset, uint32 *offsetTbl, uint32 *lenTbl, uint32 mbufs){
        uint32 i, len=offset;
        struct rtl_mBuf *p;
        for(i=0, p=m; i<mbufs && offset>offsetTbl[i]; len-=lenTbl[i], p=p->m_next, i++);
        return (uint8)p->m_data[len];
}
# 2384 "mbuf.c"
static int32 _iTryGet(register uint32 * piAvailableBuffers, register uint32 iRequestedBuffers,
                                        register uint32 * piWaitID, register int32 iHow, register uint32 * piHaveWaited)
{

        int32 iWaited = 0;

        do {} while (0);


        while (*piAvailableBuffers < iRequestedBuffers) {


                if ((((iHow) & (0x02))!=0)){
                        *piHaveWaited = iWaited;
                        return 0;
                }


                (*piWaitID)++;
                rtlglue_mbufMutexUnlock();

                rtlglue_mbufTsleep((uint32)piWaitID);
                (*piWaitID)--;
                iWaited = 1;
                rtlglue_mbufMutexLock();
        }

        *piHaveWaited = iWaited;
        return 1;
}
# 2428 "mbuf.c"
static void _vInitBufferPools(void *pBufPool, int32 iSize, int32 iNum)
{

        int32 i;
        int8 *pBuf;

        do {} while (0);
        do {} while (0);
        pBuf = (int8 *) pBufPool;

        memset((void *) pBuf, (uint8) 0, iSize * iNum);


        for (i = 0; i < (iNum - 1); i++, pBuf += iSize)
                *((uint32 *) pBuf) = (uint32) (pBuf + iSize);
}
# 2456 "mbuf.c"
static __inline__ void *_pvGetFreeBuffer(struct poolstat *pBufPoolStat)
{

        void *pvFreeBuffer;


        pvFreeBuffer = pBufPoolStat->pvFreelist;
        pBufPoolStat->iFreebufs--;


        pBufPoolStat->pvFreelist = (uint32 *) (*((uint32 *) pvFreeBuffer));
        return pvFreeBuffer;
};
# 2479 "mbuf.c"
static __inline__ void _vReturnFreeBuffer(register void *pvFreeBuffer,
                                                                                  register struct poolstat *pBufPoolStat)
{



        *((uint32 *) pvFreeBuffer) = (uint32) pBufPoolStat->pvFreelist;
        pBufPoolStat->pvFreelist = pvFreeBuffer;
        pBufPoolStat->iFreebufs++;
}



uint32 _iFreeMbufChain(struct rtl_mBuf *pFirstMbuf, int8 flags)
{
        register struct rtl_mBuf *pThisMbuf = pFirstMbuf, *pNextMbuf = ((void *)0);
        register struct mcluster_tag *pThisClusterTag = ((void *)0);
        register uint32 iFreed = 0;
        register uint32 iFreedPkthdr = 0, iFreedCLusters = 0;

        do {} while (0);
        if(pThisMbuf->m_flags & 0x08){
                struct rtl_pktHdr *pThisPkthdr;
                int32 rxDescIdx;
                pThisPkthdr=pThisMbuf->m_pkthdr;
                rxDescIdx=pThisPkthdr->ph_rxdesc;
                if(rxDescIdx>=0&&rxDescIdx<_maxRxDescidx){
                        if(rtlglue_reclaimRxBD(rxDescIdx, pThisPkthdr, pThisMbuf))
                                goto free;
                        iFreed=1;
                        goto out;
                }
        }
free:

        while (pThisMbuf && (((pThisMbuf->m_flags) & (0x80))!=0))
        {

                if (pThisMbuf->m_flags & 0x10&& (((flags) & (4))==0)){
                        if(_iTotalClusters){

                                pThisClusterTag = (&_ClusterTag[( (uint32)pThisMbuf->m_data - (uint32)_ClusterDataPool)>> m_clusterShift ]);
                                do {} while (0);
                                do {} while (0);
                                pThisClusterTag->cltag_refcnt--;
                                if (pThisClusterTag->cltag_refcnt == 0){
                                        ((pThisClusterTag->cltag_flags) &= ~(0x80));
                                        _vReturnFreeBuffer(pThisClusterTag, &_ClStatus);
                                        iFreedCLusters++;
                                }else if (pThisClusterTag->MCLNXT.mbuf_back == pThisMbuf){



                                        pThisClusterTag->MCLNXT.mbuf_back = ((void *)0);
                                }

                        }else{
                                uint32 count;
                                if(pThisMbuf->m_extClusterId){
                                        rtlglue_mbufClusterRefcnt(pThisMbuf->m_extbuf, pThisMbuf->m_extClusterId, &count, 0);
                                        if(count==1){

                                                rtlglue_mbufFreeCluster(pThisMbuf->m_extbuf, m_clusterSize, pThisMbuf->m_extClusterId);
                                        }else
                                                rtlglue_mbufClusterRefcnt(pThisMbuf->m_extbuf, pThisMbuf->m_extClusterId, &count, 2);
                                }
                        }
                }



                if (pThisMbuf->m_pkthdr){
                        if (pThisMbuf->m_flags & 0x08){
                                do {} while (0);





                                if ((pThisMbuf->m_next) && (flags&2)) {
                                        pThisMbuf->m_pkthdr->PKTHDRNXT.mbuf_first = pThisMbuf->m_next;
                                        do {} while (0);
                                        pThisMbuf->m_pkthdr->ph_len -= pThisMbuf->m_len;
                                        ((pThisMbuf->m_next->m_flags) |= (0x08));
                                }else{

                                        ((pThisMbuf->m_pkthdr->ph_flags) &= ~((0x80 << 8)));
                                        _vReturnFreeBuffer(pThisMbuf->m_pkthdr, &_PHStatus);
                                        iFreedPkthdr++;
                                }
                                pThisMbuf->m_pkthdr = ((void *)0);
                                ((pThisMbuf->m_flags) &= ~(0x08));
                        }else if ((((flags) & (2))!=0))
                                pThisMbuf->m_pkthdr->ph_len -= pThisMbuf->m_len;
                        else
                                pThisMbuf->m_pkthdr = ((void *)0);
                }




                _MbufStatus.iUsedbufs--;
                pThisMbuf->m_flags = 0x00;
                pNextMbuf = pThisMbuf->m_next;
                ((pThisMbuf->m_flags) &= ~(0x80));
                _vReturnFreeBuffer(pThisMbuf, &_MbufStatus);

                iFreed++;

                if ((((flags) & (1))!=0))
                        pThisMbuf = pNextMbuf;
                else
                        break;
        }

        if (_iTotalClusters&&iFreedCLusters&&_ClStatus.iWaiting)
                _vWakeup(&_ClStatus.iWaiting);
        if (iFreedPkthdr&&_PHStatus.iWaiting)
                _vWakeup(&_PHStatus.iWaiting);
        if(_MbufStatus.iWaiting)
                _vWakeup(&_MbufStatus.iWaiting);

        pFirstMbuf = pNextMbuf;
out:
        return iFreed;
}





static struct rtl_mBuf *_pCopyPacket(struct rtl_mBuf *pMbuf, uint32 iHow)
{
        struct rtl_mBuf *pFirstMbuf = ((void *)0), *pThisMbuf = ((void *)0), *pNewMbuf =
                ((void *)0), *pPrevNewMbuf = ((void *)0);
        struct rtl_pktHdr *pNewPkthdr = ((void *)0);
        uint32 iCopied = 0;

        do {} while (0);
        do {} while (0);
        pThisMbuf = pMbuf;

        while (pThisMbuf)
        {
                do {} while (0);
                pNewMbuf = _m_get(iHow, 1);


                if (!pNewMbuf)
                        goto nospace;

                if (pPrevNewMbuf)
                        pPrevNewMbuf->m_next = pNewMbuf;

                pPrevNewMbuf = pNewMbuf;

                if (!pFirstMbuf && (((pThisMbuf->m_flags) & (0x08))!=0))
                {
                        pFirstMbuf = pNewMbuf;
                        if (!_m_gethdr(pFirstMbuf, iHow))
                                goto nospace;
                        do {} while (0);
                        pNewPkthdr = pFirstMbuf->m_pkthdr;
                        do {} while (0);


                        rtl8651_memcpy
                                ((void *) (((int32 *) pNewPkthdr) + 1),
                                  (void *) (((int32 *) pThisMbuf->m_pkthdr) + 1),
                                 sizeof(struct rtl_pktHdr) - 4);

                        pNewPkthdr->ph_rxdesc=_maxRxDescidx;
                        do {} while (0);
                        pNewPkthdr = pFirstMbuf->m_pkthdr;
                        do {} while (0);
                        do {} while (0);
                }




                if (((iHow) & (0x04))!=0)

                {
                        rtl8651_memcpy
                                ((void *) (((int32 *) pNewMbuf) + 1),
                                  (void *) (((int32 *) pThisMbuf) + 1),
                                  sizeof(struct rtl_mBuf) - 4);
                }
                else
                {

                        pNewMbuf->m_len = pThisMbuf->m_len;
                        pNewMbuf->m_flags = pThisMbuf->m_flags;
                }


                if (pNewPkthdr)
                        pNewMbuf->m_pkthdr = pNewPkthdr;

                do {} while (0);
                do {} while (0);

                if (((iHow) & (0x04))!=0)

                {



                        if (_iTotalClusters)
                        {

                                (&_ClusterTag[( (uint32)pThisMbuf->m_extbuf - (uint32)_ClusterDataPool)>> m_clusterShift ])->cltag_refcnt++;
                        }else{
                                pNewMbuf->m_extClusterId= pThisMbuf->m_extClusterId;
                                rtlglue_mbufClusterRefcnt(pThisMbuf->m_extbuf, pThisMbuf->m_extClusterId, ((void *)0), 1);
                        }

                }
                else
                {
                        int32 align=((uint32)pThisMbuf->m_data|0x20000000)-((uint32)pThisMbuf->m_extbuf|0x20000000);
                        if(align){
                                do {} while (0);
                                pNewMbuf->m_data+=align;
                        }
                        rtl8651_memcpy
                                ( (void *) ((uint32)pNewMbuf->m_data & ~0x20000000),(void *) pThisMbuf->m_data,
                                 pThisMbuf->m_len);
                        pNewMbuf->m_data=(uint8 *)((uint32)pNewMbuf->m_data & ~0x20000000);
                        pNewMbuf->m_extbuf=(uint8 *)((uint32)pNewMbuf->m_extbuf & ~0x20000000);
                        do {} while (0);
                }

                iCopied++;
                pThisMbuf = pThisMbuf->m_next;
        }
        do {} while (0);

        return pFirstMbuf;

  nospace:
        if(pFirstMbuf)
                _iFreeMbufChain(pFirstMbuf, 1);

        return ((void *)0);
}
