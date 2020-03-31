# 1 "rtl8651_timer.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "rtl8651_timer.c"
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
# 2 "rtl8651_timer.c" 2
# 1 "rtl8651_timer.h" 1



# 1 "types.h" 1
# 5 "rtl8651_timer.h" 2

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
# 3 "rtl8651_timer.c" 2







static struct list_head _rtl8651_tv1_vec = { &(_rtl8651_tv1_vec), &(_rtl8651_tv1_vec) };

void _rtl8651_init_timer(struct rtl8651_timer_list * timer)
{

timer->list.next=timer->list.prev=0;
}

static inline int timer_pending (const struct rtl8651_timer_list * timer)
{
        return timer->list.next != 0;
}

static inline int _rtl8651_detach_timer (struct rtl8651_timer_list *timer)
{
        if (!timer_pending(timer))
                return 0;
        list_del(&timer->list);
        return 1;
}

int _rtl8651_del_timer(struct rtl8651_timer_list * timer)
{
        int ret;
        ret = _rtl8651_detach_timer(timer);
        timer->list.next = timer->list.prev = 0;
        return ret;
}





static inline void _rtl8651_internal_add_timer(struct rtl8651_timer_list *timer)
{
        list_add_tail(&timer->list,&_rtl8651_tv1_vec);
}

int _rtl8651_mod_timer(struct rtl8651_timer_list *timer, uint32 expires)
{
        int ret;
        timer->expires = expires;
        ret = _rtl8651_detach_timer(timer);
        _rtl8651_internal_add_timer(timer);
        return ret;
}



void _rtl8651_run_timer_list(void)
{
        struct list_head *head, *curr;

        if (list_empty(&_rtl8651_tv1_vec))
        {
                return;
        }
        head = &_rtl8651_tv1_vec;
        curr=head->next;
        while(curr!=head)
        {
                struct rtl8651_timer_list *timer;
                void (*fn)(uint32);
                unsigned long data;

                timer = ((struct rtl8651_timer_list *)((char *)(curr)-(unsigned long)(&((struct rtl8651_timer_list *)0)->list)));
                if (timer && (timer->expires <=_sysUpSeconds))
                {

                        fn = timer->function;
                        data= timer->data;
                        _rtl8651_detach_timer(timer);
                        timer->list.next = timer->list.prev = 0;
                        if (fn)
                        {
                                fn(data);
                                curr = head->next;
                        }else
                                curr = curr->next;
                }else
                {
                        curr = curr->next;
                }
        }

}
