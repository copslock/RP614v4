# 1 "rtl8651_layer2fwd.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "rtl8651_layer2fwd.c"
# 410 "rtl8651_layer2fwd.c"
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
# 411 "rtl8651_layer2fwd.c" 2
# 1 "assert.h" 1
# 412 "rtl8651_layer2fwd.c" 2
# 1 "rtl8651_tblAsicDrv.h" 1





# 1 "types.h" 1
# 7 "rtl8651_tblAsicDrv.h" 2
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
# 8 "rtl8651_tblAsicDrv.h" 2
# 1 "rtl8651_tblDrv.h" 1
# 18 "rtl8651_tblDrv.h"
# 1 "rtl_errno.h" 1
# 19 "rtl8651_tblDrv.h" 2

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
# 21 "rtl8651_tblDrv.h" 2
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
# 22 "rtl8651_tblDrv.h" 2

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
# 9 "rtl8651_tblAsicDrv.h" 2


extern int8 RtkHomeGatewayChipName[16];
extern int32 RtkHomeGatewayChipRevisionID;
# 58 "rtl8651_tblAsicDrv.h"
enum {
    TYPE_L2_SWITCH_TABLE = 0,
    TYPE_ARP_TABLE,
    TYPE_L3_ROUTING_TABLE,
    TYPE_MULTICAST_TABLE,
    TYPE_PROTOCOL_TRAP_TABLE,
    TYPE_VLAN_TABLE,
    TYPE_EXT_INT_IP_TABLE,
    TYPE_ALG_TABLE,
    TYPE_SERVER_PORT_TABLE,
    TYPE_L4_TCP_UDP_TABLE,
    TYPE_L4_ICMP_TABLE,
    TYPE_PPPOE_TABLE,
    TYPE_ACL_RULE_TABLE,
    TYPE_NEXT_HOP_TABLE,
    TYPE_RATE_LIMIT_TABLE,
};






typedef struct {


    uint16 mac31_16;
    uint16 mac15_0;

    uint16 vhid : 9;
    uint16 memberPort : 6;
    uint16 valid : 1;
    uint16 mac47_32;

    uint8 reserv5 : 1;
    uint8 outACLEnd : 7;
    uint8 reserv4 : 1;
    uint8 outACLStart : 7;
    uint8 reserv3 : 1;
    uint8 inACLEnd : 7;
    uint8 reserv2 : 1;
    uint8 inACLStart : 7;

    uint32 mtuL : 8;
    uint32 macMask : 2;
    uint32 egressUntag : 6;
    uint32 promiscuous : 1;
    uint32 bcastToCPU : 1;
    uint32 STPStatus : 12;
    uint32 enHWRoute : 1;
    uint32 isInternal : 1;

    uint32 reserv7 : 15;
    uint32 macNotExist : 1;
    uint32 isDMZ : 1;
    uint32 extSTPStatus : 6;
    uint32 extEgressUntag : 3;
    uint32 extMemberPort : 3;
    uint32 mtuH : 3;
# 154 "rtl8651_tblAsicDrv.h"
    uint32 reservw5;

    uint32 reservw6;

    uint32 reservw7;
} rtl8651_tblAsic_vlanTable_t;

typedef struct {


    uint16 reserv5 : 12;
    uint16 valid : 1;
    uint16 trapProtocol: 3;
    uint16 trapContent;
# 176 "rtl8651_tblAsicDrv.h"
    uint32 reservw1;

    uint32 reservw2;

    uint32 reservw3;

    uint32 reservw4;

    uint32 reservw5;

    uint32 reservw6;

    uint32 reservw7;
} rtl8651_tblAsic_protoTrapTable_t;

typedef struct {


    ipaddr_t internalIP;

    ipaddr_t externalIP;




    uint32 reserv0 : 24;
    uint32 nextHop : 5;

    uint32 isLocalPublic : 1;
    uint32 isOne2One : 1;
    uint32 valid : 1;
# 224 "rtl8651_tblAsicDrv.h"
    uint32 reservw3;

    uint32 reservw4;

    uint32 reservw5;

    uint32 reservw6;

    uint32 reservw7;
} rtl8651_tblAsic_extIpTable_t;

typedef struct {


    ipaddr_t internalIP;

    ipaddr_t externalIP;

    uint16 externalPort;
    uint16 internalPort;




    uint32 reserv0 : 25;
    uint32 isPortRange : 1;
    uint32 nextHop : 5;

    uint32 valid : 1;
# 272 "rtl8651_tblAsicDrv.h"
    uint32 reservw4;

    uint32 reservw5;

    uint32 reservw6;

    uint32 reservw7;
} rtl8651_tblAsic_srvPortTable_t;

typedef struct {


    uint16 reserv : 15;
    uint16 valid : 1;
    uint16 L4Port;







    uint32 reservw1;

    uint32 reservw2;

    uint32 reservw3;

    uint32 reservw4;

    uint32 reservw5;

    uint32 reservw6;

    uint32 reservw7;
} rtl8651_tblAsic_algTable_t;

typedef struct {


    ipaddr_t IPAddr;

    union {
        struct {
            uint32 reserv0 : 5;
            uint32 ARPIpIdx : 2;
            uint32 ARPEnd : 6;
            uint32 ARPStart : 6;
            uint32 IPMask : 5;
            uint32 vid : 3;
            uint32 hPriority : 1;
            uint32 process : 3;
            uint32 valid : 1;
        } ARPEntry;
        struct {
            uint32 reserv0 : 9;
            uint32 nextHop : 10;
            uint32 IPMask : 5;
            uint32 vid : 3;
            uint32 hPriority : 1;
            uint32 process : 3;
            uint32 valid : 1;
        } L2Entry;
        struct {
            uint32 reserv0 : 6;
            uint32 PPPoEIndex : 3;
            uint32 nextHop : 10;
            uint32 IPMask : 5;
            uint32 vid : 3;
            uint32 hPriority : 1;
            uint32 process : 3;
            uint32 valid : 1;
        } PPPoEEntry;

        struct {
            uint32 reserv0 : 5;
            uint32 IPDomain : 3;
            uint32 nhAlgo : 2;
            uint32 nhNxt : 5;
            uint32 nhStart : 4;
            uint32 IPMask : 5;
            uint32 nhNum : 3;
            uint32 hPriority : 1;
            uint32 process : 3;
            uint32 valid : 1;
        } NxtHopEntry;

    } linkTo;
# 412 "rtl8651_tblAsicDrv.h"
    uint32 reservw2;

    uint32 reservw3;

    uint32 reservw4;

    uint32 reservw5;

    uint32 reservw6;

    uint32 reservw7;
} rtl8651_tblAsic_l3RouteTable_t;

typedef struct {





    uint16 reserv0 : 13;
    uint16 ageTime : 3;

    uint16 sessionID;
# 446 "rtl8651_tblAsicDrv.h"
    uint32 reservw1;

    uint32 reservw2;

    uint32 reservw3;

    uint32 reservw4;

    uint32 reservw5;

    uint32 reservw6;

    uint32 reservw7;
} rtl8651_tblAsic_pppoeTable_t;

typedef struct {


    uint16 mac39_24;
    uint16 mac23_8;




    uint16 reserv0 : 8;
    uint16 extMemberPort : 3;

    uint16 nxtHostFlag : 1;
    uint16 srcBlock : 1;
    uint16 agingTime : 2;
    uint16 isStatic : 1;
    uint16 toCPU : 1;
    uint16 hPriority : 1;
    uint16 memberPort : 6;
    uint16 mac47_40 : 8;
# 502 "rtl8651_tblAsicDrv.h"
    uint32 reservw2;

    uint32 reservw3;

    uint32 reservw4;

    uint32 reservw5;

    uint32 reservw6;

    uint32 reservw7;
} rtl8651_tblAsic_l2Table_t;

typedef struct {


    uint32 reserv0 : 21;
    uint32 nextHop : 10;
    uint32 valid : 1;







    uint32 reservw1;

    uint32 reservw2;

    uint32 reservw3;

    uint32 reservw4;

    uint32 reservw5;

    uint32 reservw6;

    uint32 reservw7;
} rtl8651_tblAsic_arpTable_t;

typedef struct {


    ipaddr_t intIPAddr;
# 558 "rtl8651_tblAsicDrv.h"
    uint32 reserv0 : 1;
    uint32 selEIdx : 10;
    uint32 selIPIdx : 4;
    uint32 isStatic : 1;
    uint32 dedicate : 1;
    uint32 collision2 : 1;
    uint32 offset : 6;
    uint32 agingTime : 6;
    uint32 collision : 1;
    uint32 valid : 1;


    uint32 reserv2 : 12;
    uint32 isTCP : 1;
    uint32 TCPFlag : 3;
    uint32 intPort : 16;
# 606 "rtl8651_tblAsicDrv.h"
    uint32 reservw3;

    uint32 reservw4;

    uint32 reservw5;

    uint32 reservw6;

    uint32 reservw7;
} rtl8651_tblAsic_naptTcpUdpTable_t;

typedef struct {


    ipaddr_t intIPAddr;

    uint32 ICMPIDL : 15;
    uint32 isStatic : 1;



    uint32 type : 2;

    uint32 offset : 6;
    uint32 agingTime : 6;
    uint32 collision : 1;
    uint32 valid : 1;

    uint32 reserv2 : 15;
    uint32 count : 16;
    uint32 ICMPIDH : 1;
# 658 "rtl8651_tblAsicDrv.h"
    uint32 reservw3;

    uint32 reservw4;

    uint32 reservw5;

    uint32 reservw6;

    uint32 reservw7;
} rtl8651_tblAsic_naptIcmpTable_t;

typedef struct {

    union {
        struct {

            uint16 dMacP31_16;
            uint16 dMacP15_0;

            uint16 dMacM15_0;
            uint16 dMacP47_32;

            uint16 dMacM47_32;
            uint16 dMacM31_16;

            uint16 sMacP31_16;
            uint16 sMacP15_0;

            uint16 sMacM15_0;
            uint16 sMacP47_32;

            uint16 sMacM47_32;
            uint16 sMacM31_16;

            uint16 ethTypeM;
            uint16 ethTypeP;
        } ETHERNET;
        struct {

            uint32 reserv1 : 24;
            uint32 gidxSel : 8;

            uint32 reserv2[6];
        } IFSEL;
        struct {

            ipaddr_t sIPP;

            ipaddr_t sIPM;

            ipaddr_t dIPP;

            ipaddr_t dIPM;
            union {
                struct {

                    uint8 IPProtoM;
                    uint8 IPProtoP;
                    uint8 IPTOSM;
                    uint8 IPTOSP;




                    uint32 reserv0 : 20;
                    uint32 identSDIPM : 1;
                    uint32 identSDIPP : 1;
                    uint32 HTTPM : 1;
                    uint32 HTTPP : 1;
                    uint32 FOM : 1;
                    uint32 FOP : 1;

                    uint32 IPFlagM : 3;
                    uint32 IPFlagP : 3;

                    uint32 reserv1;
                } IP;
                struct {

                    uint8 ICMPTypeM;
                    uint8 ICMPTypeP;
                    uint8 IPTOSM;
                    uint8 IPTOSP;

                    uint16 reserv0;
                    uint8 ICMPCodeM;
                    uint8 ICMPCodeP;

                    uint32 reserv1;
                } ICMP;
                struct {

                    uint8 IGMPTypeM;
                    uint8 IGMPTypeP;
                    uint8 IPTOSM;
                    uint8 IPTOSP;

                    uint32 reserv0[2];
                } IGMP;
                struct {

                    uint8 TCPFlagM;
                    uint8 TCPFlagP;
                    uint8 IPTOSM;
                    uint8 IPTOSP;

                    uint16 TCPSPLB;
                    uint16 TCPSPUB;

                    uint16 TCPDPLB;
                    uint16 TCPDPUB;
                } TCP;
                struct {

                    uint16 reserv0;
                    uint8 IPTOSM;
                    uint8 IPTOSP;

                    uint16 UDPSPLB;
                    uint16 UDPSPUB;

                    uint16 UDPDPLB;
                    uint16 UDPDPUB;
                } UDP;
            } is;
        } L3L4;

        struct {

            uint16 sMacP31_16;
            uint16 sMacP15_0;

            uint16 sMacM15_0;
            uint16 sMacP47_32;

            uint16 sMacM47_32;
            uint16 sMacM31_16;

            uint32 reserv2 : 6;
            uint32 protoType : 2;
            uint32 sVidxM : 3;
            uint32 sVidxP : 3;
            uint32 spaM : 9;
            uint32 spaP : 9;

            ipaddr_t sIPP;

            ipaddr_t sIPM;

            uint16 SPORTLB;
            uint16 SPORTUB;
        } SRC_FILTER;
        struct {

            uint16 dMacP31_16;
            uint16 dMacP15_0;

            uint16 dMacM15_0;
            uint16 dMacP47_32;

            uint16 dMacM47_32;
            uint16 dMacM31_16;

            uint32 reserv2 : 24;
            uint32 protoType : 2;
            uint32 vidxM : 3;
            uint32 vidxP : 3;

            ipaddr_t dIPP;

            ipaddr_t dIPM;

            uint16 DPORTLB;
            uint16 DPORTUB;
        } DST_FILTER;

    } is;




    uint32 pktOpApp : 3;
    uint32 reserv0 : 4;

    uint32 PPPoEIndex : 3;
    uint32 vid : 3;
    uint32 hPriority : 1;
    uint32 nextHop : 10;
    uint32 actionType : 4;
    uint32 ruleType : 4;
# 1027 "rtl8651_tblAsicDrv.h"
} rtl8651_tblAsic_aclTable_t;

typedef struct {


    ipaddr_t srcIPAddr;

    uint32 srcPortL : 1;
    uint32 srcVid : 3;
    uint32 destIPAddrLsbs : 28;




    uint32 reserv0 : 11;
    uint32 extIPIndexH : 1;
    uint32 ageTime : 3;
    uint32 extPortList : 3;
    uint32 srcPortExt : 1;

    uint32 toCPU : 1;
    uint32 valid : 1;
    uint32 extIPIndex : 3;
    uint32 portList : 6;
    uint32 srcPortH : 2;
# 1076 "rtl8651_tblAsicDrv.h"
    uint32 reservw3;

    uint32 reservw4;

    uint32 reservw5;

    uint32 reservw6;

    uint32 reservw7;
} rtl8651_tblAsic_ipMulticastTable_t;


typedef struct {


    uint32 reserv0 : 11;
    uint32 nextHop : 10;
    uint32 PPPoEIndex : 3;
    uint32 dstVid : 3;
    uint32 IPIndex : 4;
    uint32 type : 1;
# 1107 "rtl8651_tblAsicDrv.h"
    uint32 reservw1;

    uint32 reservw2;

    uint32 reservw3;

    uint32 reservw4;

    uint32 reservw5;

    uint32 reservw6;

    uint32 reservw7;
} rtl8651_tblAsic_nextHopTable_t;

typedef struct {


    uint32 reserv0 : 2;
    uint32 refillRemainTime : 6;
    uint32 token : 24;

    uint32 reserv1 : 2;
    uint32 refillTime : 6;
    uint32 maxToken : 24;

    uint32 reserv2 : 8;
    uint32 refill : 24;
# 1149 "rtl8651_tblAsicDrv.h"
    uint32 reservw3;

    uint32 reservw4;

    uint32 reservw5;

    uint32 reservw6;

    uint32 reservw7;
} rtl8651_tblAsic_rateLimitTable_t;







int32 _rtl8651_addAsicEntry(uint32 tableType, uint32 eidx, void *entryContent_P);
int32 _rtl8651_forceAddAsicEntry(uint32 tableType, uint32 eidx, void *entryContent_P);
int32 _rtl8651_readAsicEntry(uint32 tableType, uint32 eidx, void *entryContent_P);
int32 _rtl8651_delAsicEntry(uint32 tableType, uint32 startEidx, uint32 endEidx);

uint32 _rtl8651_NaptAgingToSec(uint32 value);
uint32 _rtl8651_NaptAgingToUnit(uint32 sec);
uint32 rtl8651_filterDbIndex(ether_addr_t * macAddr);

uint32 rtl8651_naptTcpUdpTableIndex(int8 isTCP, ipaddr_t srcAddr, uint16 srcPort, ipaddr_t destAddr, uint16 destPort);
uint32 rtl8651_naptIcmpTableIndex(ipaddr_t srcAddr, uint16 icmpId, ipaddr_t destAddr, uint32 * tblIdx);
uint32 rtl8651_ipMulticastTableIndex(ipaddr_t srcAddr, ipaddr_t dstAddr);

int32 rtl8651_clearAsicAllTable(void);

int32 _rtl8651_mapToVirtualRegSpace( void );
int32 _rtl8651_mapToRealRegSpace( void );
int32 rtl8651_initAsic(void);

int32 rtl8651_setAsicOperationLayer(uint32 layer);
int32 rtl8651_getAsicOperationLayer(void);
int32 rtl8651_setAsicSpanningEnable(int8 spanningTreeEnabled);
int32 rtl8651_getAsicSpanningEnable(int8 *spanningTreeEnabled);
void rtl8651_setEthernetPortLinkStatus(uint32 port, int8 linkUp);
int32 rtl8651_updateLinkStatus(void);
int32 rtl8651_setAsicEthernetLinkStatus(uint32 port, int8 linkUp);
int32 rtl8651_getAsicEthernetLinkStatus(uint32 port, int8 *linkUp);
int32 rtl8651_setAsicEthernetPHY(uint32 port, int8 autoNegotiation, uint32 advCapability, uint32 speed, int8 fullDuplex);
int32 rtl8651_getAsicEthernetPHY(uint32 port, int8 *autoNegotiation, uint32 *advCapability, uint32 *speed, int8 *fullDuplex);
int32 rtl8651_setAsicEthernetBandwidthControl(uint32 port, int8 input, uint32 rate);
int32 rtl8651_getAsicEthernetBandwidthControl(uint32 port, int8 input, uint32 *rate);
int32 rtl8651_setAsicEthernetBandwidthControlX4(int8 enable);
int32 rtl8651_getAsicEthernetBandwidthControlX4(int8 *enable);
int32 rtl8651_setAsicEthernetBandwidthControlX8(int8 enable);
int32 rtl8651_getAsicEthernetBandwidthControlX8(int8 *enable);
int32 rtl8651_setAsicEthernetMII(uint32 phyAddress, int32 mode, int32 enabled);
int32 rtl8651_setAsicEthernetPHYLoopback(uint32 port, int32 enabled);
int32 rtl8651_getAsicEthernetPHYLoopback(uint32 port, int32 *flag);
int32 rtl8651_setAsicMulticastSpanningTreePortState(uint32 port, uint32 portState);
int32 rtl8651_getAsicMulticastSpanningTreePortState(uint32 port, uint32 *portState);
int32 rtl8651_setAsicMulticastPortInternal(uint32 port, int8 isInternal);
int32 rtl8651_getAsicMulticastPortInternal(uint32 port, int8 *isInternal);

typedef struct rtl865x_tblAsicDrv_l2Param_s {
        ether_addr_t macAddr;
        uint32 memberPortMask;
        uint32 ageSec;
        uint32 cpu:1,
                                srcBlk:1,
                                isStatic:1,
                                nhFlag:1;
} rtl865x_tblAsicDrv_l2Param_t;
int32 rtl8651_setAsicL2Table(uint32 row, uint32 column, rtl865x_tblAsicDrv_l2Param_t *l2p);
int32 rtl8651_delAsicL2Table(uint32 row, uint32 column);

int32 rtl8651_getAsicL2Table(uint32 row, uint32 column, rtl865x_tblAsicDrv_l2Param_t *l2p);
int32 rtl8651_updateAsicLinkAggregatorLMPR(int32 portmask);
int32 rtl8651_setAsicLinkAggregator(uint32 portMask);
int32 rtl8651_getAsicLinkAggregator(uint32 * portMask, uint32 *mapping);
int32 rtl8651_turnOnHardwiredProtoTrap(uint8 protoType, uint16 protoContent);
int32 rtl8651_turnOffHardwiredProtoTrap(uint8 protoType, uint16 protoContent);
int32 rtl8651_getHardwiredProtoTrap(uint8 protoType, uint16 protoContent, int8 *isEnable);
typedef struct rtl865x_tblAsicDrv_protoTrapParam_s {
        uint8 type;
        uint16 content;
} rtl865x_tblAsicDrv_protoTrapParam_t;
int32 rtl8651_setAsicProtoTrap(uint32 index, rtl865x_tblAsicDrv_protoTrapParam_t *protoTrapp);
int32 rtl8651_delAsicProtoTrap(uint32 index);
int32 rtl8651_getAsicProtoTrap(uint32 index, rtl865x_tblAsicDrv_protoTrapParam_t *protoTrapp);
int32 rtl8651_setAsicPvid(uint32 port, uint32 pvidx);
int32 rtl8651_getAsicPvid(uint32 port, uint32 *pvidx);


typedef struct rtl865x_tblAsicDrv_vlanParam_s {
        ether_addr_t macAddr;
        uint32 memberPortMask;
        uint32 untagPortMask;
        uint16 macAddrNumber;
        uint16 vid;
        uint32 inAclStart, inAclEnd, outAclStart, outAclEnd;
        int8 portState[9];
        uint32 mtu;
        uint16 internal:1,
                        enableRoute:1,
                        broadcastToCpu:1,
                        promiscuous:1,
                        DMZFlag:1,
                        valid:1;
} rtl865x_tblAsicDrv_vlanParam_t;
int32 rtl8651_setAsicVlan(rtl865x_tblAsicDrv_vlanParam_t *vlanp);
int32 rtl8651_delAsicVlan(uint16 vid);
int32 rtl8651_getAsicVlan(uint16 vid, rtl865x_tblAsicDrv_vlanParam_t *vlanp);
typedef struct rtl865x_tblAsicDrv_pppoeParam_s {
        uint16 sessionId;

        uint16 age;

} rtl865x_tblAsicDrv_pppoeParam_t;
int32 rtl8651_setAsicPppoe(uint32 index, rtl865x_tblAsicDrv_pppoeParam_t *pppoep);
int32 rtl8651_getAsicPppoe(uint32 index, rtl865x_tblAsicDrv_pppoeParam_t *pppoep);
typedef struct rtl865x_tblAsicDrv_routingParam_s {
            ipaddr_t ipAddr;
            ipaddr_t ipMask;
            uint32 process;
            uint32 vidx;
            uint32 arpStart;
            uint32 arpEnd;
            uint32 arpIpIdx;
            uint32 nextHopRow;
            uint32 nextHopColumn;
            uint32 pppoeIdx;

            uint32 nhStart;
            uint32 nhNum;
            uint32 nhNxt;
            uint32 nhAlgo;
            uint32 ipDomain;

} rtl865x_tblAsicDrv_routingParam_t;
int32 rtl8651_setAsicRouting(uint32 index, rtl865x_tblAsicDrv_routingParam_t *routingp);
int32 rtl8651_delAsicRouting(uint32 index);
int32 rtl8651_getAsicRouting(uint32 index, rtl865x_tblAsicDrv_routingParam_t *routingp);
typedef struct rtl865x_tblAsicDrv_arpParam_s {
        uint32 nextHopRow;
        uint32 nextHopColumn;
} rtl865x_tblAsicDrv_arpParam_t;
int32 rtl8651_setAsicArp(uint32 index, rtl865x_tblAsicDrv_arpParam_t *arpp);
int32 rtl8651_delAsicArp(uint32 index);
int32 rtl8651_getAsicArp(uint32 index, rtl865x_tblAsicDrv_arpParam_t *arpp);
int32 rtl8651_setAsicGidxRegister(uint32 regValue);
int32 rtl8651_getAsicGidxRegister(uint32 * reg);
typedef struct rtl865x_tblAsicDrv_extIntIpParam_s {
            ipaddr_t extIpAddr;
            ipaddr_t intIpAddr;

            uint32 nhIndex;

            uint32 localPublic:1,
                                nat:1;
} rtl865x_tblAsicDrv_extIntIpParam_t;
int32 rtl8651_setAsicExtIntIpTable(uint32 index, rtl865x_tblAsicDrv_extIntIpParam_t *extIntIpp);

int32 rtl8651_setInvalidAsicExtIntIpTable(uint32 index, rtl865x_tblAsicDrv_extIntIpParam_t *extIntIpp);

int32 rtl8651_delAsicExtIntIpTable(uint32 index);
int32 rtl8651_getAsicExtIntIpTable(uint32 index, rtl865x_tblAsicDrv_extIntIpParam_t *extIntIpp);
typedef struct rtl865x_tblAsicDrv_serverPortParam_s {
        ipaddr_t extIpAddr;
        ipaddr_t intIpAddr;
        uint16 extPort;
        uint16 intPort;

        uint32 nhIndex;
        uint32 portRange:1;

        uint32 valid:1;
} rtl865x_tblAsicDrv_serverPortParam_t;
int32 rtl8651_setAsicServerPortTable(uint32 index, rtl865x_tblAsicDrv_serverPortParam_t *serverPortp);
int32 rtl8651_delAsicServerPortTable(uint32 index);
int32 rtl8651_getAsicServerPortTable(uint32 index, rtl865x_tblAsicDrv_serverPortParam_t *serverPortp);
int32 rtl8651_setAsicAgingFunction(int8 l2Enable, int8 l4Enable);
int32 rtl8651_getAsicAgingFunction(int8 * l2Enable, int8 * l4Enable);
int32 rtl8651_setAsicNaptAutoAddDelete(int8 autoAdd, int8 autoDelete);
int32 rtl8651_getAsicNaptAutoAddDelete(int8 *autoAdd, int8 *autoDelete);
int32 rtl8651_setAsicNaptIcmpTimeout(uint32 timeout);
int32 rtl8651_getAsicNaptIcmpTimeout(uint32 *timeout);
int32 rtl8651_setAsicNaptUdpTimeout(uint32 timeout);
int32 rtl8651_getAsicNaptUdpTimeout(uint32 *timeout);
int32 rtl8651_setAsicNaptTcpLongTimeout(uint32 timeout);
int32 rtl8651_getAsicNaptTcpLongTimeout(uint32 *timeout);
int32 rtl8651_setAsicNaptTcpMediumTimeout(uint32 timeout);
int32 rtl8651_getAsicNaptTcpMediumTimeout(uint32 *timeout);
int32 rtl8651_setAsicNaptTcpFastTimeout(uint32 timeout);
int32 rtl8651_getAsicNaptTcpFastTimeout(uint32 *timeout);

int32 rtl8651_setAsicPortMirror(uint32 mTxMask, uint32 mRxMask, uint32 mPortMask);
int32 rtl8651_getAsicPortMirror(uint32 *mRxMask, uint32 *mTxMask, uint32 *mPortMask);

typedef struct rtl865x_tblAsicDrv_nextHopParam_s {
        uint32 nextHopRow;
        uint32 nextHopColumn;
        uint32 pppoeIdx;
        uint32 dvid;
        uint32 extIntIpIdx;
        uint32 isPppoe:1;
} rtl865x_tblAsicDrv_nextHopParam_t;
int32 rtl8651_setAsicNextHopTable(uint32 index, rtl865x_tblAsicDrv_nextHopParam_t *nextHopp);
int32 rtl8651_getAsicNextHopTable(uint32 index, rtl865x_tblAsicDrv_nextHopParam_t *nextHopp);
# 1378 "rtl8651_tblAsicDrv.h"
typedef struct rtl865x_tblAsicDrv_naptTcpUdpParam_s {
        ipaddr_t insideLocalIpAddr;
        uint16 insideLocalPort;
        uint32 ageSec;
        uint8 tcpFlag;
        uint8 offset;

        uint8 selExtIPIdx;
        uint16 selEIdx;

        uint32 isTcp:1,
                        isCollision:1,
                        isStatic:1,

                        isCollision2:1,
                        isDedicated:1,

                        isValid:1;
} rtl865x_tblAsicDrv_naptTcpUdpParam_t;
int32 rtl8651_setAsicNaptTcpUdpTable(int8 forced, uint32 index, rtl865x_tblAsicDrv_naptTcpUdpParam_t *naptTcpUdpp);
int32 rtl8651_getAsicNaptTcpUdpTable(uint32 index, rtl865x_tblAsicDrv_naptTcpUdpParam_t *naptTcpUdpp);
int32 rtl8651_delAsicNaptTcpUdpTable(uint32 start, uint32 end);
int32 _rtl8651_findAsicExtIpTableIdx(ipaddr_t extIp);
int32 rtl8651_setAsicRawNaptTable(uint32 index, void * entry, int8 forced);
int32 rtl8651_getAsicRawNaptTable(uint32 index, void *entry);

int32 rtl8651_setAsicLiberalNaptTcpUdpTable(int8 forced, uint16 index, ipaddr_t insideLocalIpAddr, uint16 insideLocalPort, int8 selExtIPIdx, uint16 insideGlobalPort, uint32 ageSec, int8 entryType, int8 isTcp, int8 isCollision, int8 isCollision2, int8 isValid);


typedef struct rtl865x_tblAsicDrv_naptIcmpParam_s {
        ipaddr_t insideLocalIpAddr;
        uint16 insideLocalId;
        uint16 ageSec;
        uint8 offset;
        uint32 isStatic:1,
                        isCollision:1,

                        isSpi:1,
                        isPptp:1,

                        isValid:1;
        uint16 count;
} rtl865x_tblAsicDrv_naptIcmpParam_t;
int32 rtl8651_setAsicNaptIcmpTable(int8 forced, uint32 index, rtl865x_tblAsicDrv_naptIcmpParam_t *naptIcmpp);
int32 rtl8651_getAsicNaptIcmpTable(uint32 index, rtl865x_tblAsicDrv_naptIcmpParam_t *naptIcmpp);
int32 rtl8651_setAsicL4Offset(uint16 start, uint16 end);
int32 rtl8651_getAsicL4Offset(uint16 *start, uint16 *end);

typedef struct rtl865x_tblAsicDrv_algParam_s {
        uint16 port;
} rtl865x_tblAsicDrv_algParam_t;
int32 rtl8651_setAsicAlg(uint32 index, rtl865x_tblAsicDrv_algParam_t *algp);
int32 rtl8651_delAsicAlg(uint32 index);
int32 rtl8651_getAsicAlg(uint32 index, rtl865x_tblAsicDrv_algParam_t *algp);
int32 rtl8651_getAsicNaptTcpUdpOffset(uint16 index, uint16 * offset, int8 * isValid);
int32 rtl8651_getAsicNaptIcmpOffset(uint16 index, uint16 * offset, int8 * isValid);

typedef struct rtl865x_tblAsicDrv_multiCastParam_s {
        ipaddr_t sip;
        ipaddr_t dip;
        uint16 svid;
        uint16 port;
        uint32 mbr;
        uint16 age;
        uint16 cpu;
        uint16 extIdx;
} rtl865x_tblAsicDrv_multiCastParam_t;

int32 rtl8651_setAsicIpMulticastTable(rtl865x_tblAsicDrv_multiCastParam_t *mCast_t);
int32 rtl8651_delAsicIpMulticastTable(uint32 index);
int32 rtl8651_getAsicIpMulticastTable(uint32 index, rtl865x_tblAsicDrv_multiCastParam_t *mCast_t);


typedef struct rtl865x_tblAsicDrv_basicCounterParam_s {
        uint32 mbr;
        uint32 txPackets;
        uint32 txBytes;
        uint32 rxPackets;
        uint32 rxBytes;
        uint32 rxErrors;
        uint32 drops;
        uint32 cpus;
} rtl865x_tblAsicDrv_basicCounterParam_t;

int32 rtl8651_returnAsicCounter(uint32 offset);
int32 rtl8651_clearAsicCounter(void);

int32 rtl8651_clearAsicSpecifiedCounter(uint32 counterIdx);
int32 rtl8651_resetAsicCounterMemberPort(uint32 counterIdx);
int32 rtl8651_addAsicCounterMemberPort(uint32 counterIdx, uint32 port);
int32 rtl8651_delAsicCounterMemberPort(uint32 counterIdx, uint32 port);
int32 rtl8651_getAsicCounter(uint32 counterIdx, rtl865x_tblAsicDrv_basicCounterParam_t * basicCounter);



typedef struct rtl865x_tblAsicDrv_rateLimitParam_s {
        uint32 token;
        uint32 maxToken;
        uint32 t_remainUnit;
        uint32 t_intervalUnit;
        uint32 refill_number;
} rtl865x_tblAsicDrv_rateLimitParam_t;

int32 rtl8651_setAsicRateLimitTable(uint32 index, rtl865x_tblAsicDrv_rateLimitParam_t *rateLimit_t);
int32 rtl8651_delAsicRateLimitTable(uint32 index);
int32 rtl8651_getAsicRateLimitTable(uint32 index, rtl865x_tblAsicDrv_rateLimitParam_t *rateLimit_t);



int32 rtl8651_setBroadCastStormReg(int8 enable);
int32 rtl8651_getBroadCastSTormReg(int8 *enable);
int32 rtl8651_testAsicDrv(void);

typedef struct {
    uint32 spa;
    uint32 bc;
    uint32 vid;
    uint32 vlan;
    uint32 pppoe;
    uint8 sip[4];
    uint32 sprt;

    uint8 dip[4];
    uint32 dprt;

    uint32 ipptl;
    uint32 ipflg;
    uint32 iptos;
    uint32 tcpflg;
    uint32 type;
    uint32 prtnmat;
        uint32 ethrtype;
    uint8 da[6];
    uint8 pad1[2];
    uint8 sa[6];
    uint8 pad2[2];
    uint32 hp;
    uint32 llc;
    uint32 udp_nocs;
    uint32 ttlst;
    uint32 pktend;
    uint32 dirtx;
    uint32 l4crcok;
    uint32 l3crcok;
    uint32 ipfragif;
    uint32 dp ;
    uint32 hp2;

        uint16 ipLen;
        uint8 L2only;


} rtl8651_tblAsic_hsb_param_watch_t;

typedef struct {

        uint8 mac[6];
        uint8 pad1[2];
        uint8 ip[4];
        uint32 prt;
        uint32 l3cs;
        uint32 l4cs;
        uint32 egress;
        uint32 l2act;
        uint32 l34act;
        uint32 dirtx;
        uint32 type;
        uint32 llc;
        uint32 vlan;
        uint32 dvid;
        uint32 pppoe;
        uint32 pppid;
        uint32 ttl_1;
        uint32 dpc;
        uint32 bc;
        uint32 pktend;
        uint32 mulcst;
        uint32 svid;
        uint32 cpursn;
        uint32 spa;
        uint32 lastfrag;
        uint32 frag;
        uint32 l4csok;
        uint32 l3csok;
        uint32 bc10_5;

        uint32 extSrcPortNum;
        uint32 extDstPortMask;
        uint32 cpuacl;
        uint32 extTTL_1;

} rtl8651_tblAsic_hsa_param_watch_t;
# 1580 "rtl8651_tblAsicDrv.h"
void rtl8651_updateLinkChangePendingCount(void);

int32 rtl8651_getAsicHsB(rtl8651_tblAsic_hsb_param_watch_t * hsbWatch);
int32 rtl8651_getAsicHsA(rtl8651_tblAsic_hsa_param_watch_t * hsaWatch);

extern int8 rtl8651_tblAsicDrv_Id[];

int32 rtl8651_setAsicPortPatternMatch(uint32 port, uint32 pattern, uint32 patternMask, int32 operation);
int32 rtl8651_getAsicFlowControlRegister(uint32 *fcren);
int32 rtl8651_setAsicFlowControlRegister(uint32 port, int8 enable);
int32 rtl8651_setAsicHLQueueWeight(uint32 weight);
int32 rtl8651_setAsicPortPriority(uint32 port, int8 highPriority);
int32 rtl8651_getAsicQoSControlRegister(uint32 *qoscr);
int32 rtl8651_setAsicDiffServReg(uint32 dscp, int8 highPriority);
int32 rtl8651_getAsicDiffServReg(uint32 *dscr0, uint32 *dscr1);

int32 rtl8651_asicEthernetCableMeter(uint32 port, int32 *rxStatus, int32 *txStatus);
int32 rtl8651_getAsicEthernetMII(uint32 *phyAddress);
int32 rtl8651_queryProtocolBasedVLAN( uint32 ruleNo, uint8* ProtocolType, uint16* ProtocolValue );
# 1612 "rtl8651_tblAsicDrv.h"
int32 rtl8651_defineProtocolBasedVLAN( uint32 ruleNo, uint8 ProtocolType, uint16 ProtocolValue );
int32 rtl8651_setProtocolBasedVLAN( uint32 ruleNo, uint32 port, uint8 valid, uint8 vlanIdx );
int32 rtl8651_getProtocolBasedVLAN( uint32 ruleNo, uint32 port, uint8* valid, uint8* vlanIdx );

int32 rtl8651_autoMdiMdix(uint32 port, uint32 isEnable);
int32 rtl8651_getAutoMdiMdix(uint32 port, uint32 *isEnable);
int32 rtl8651_selectMdiMdix(uint32 port, uint32 isMdi);
int32 rtl8651_getSelectMdiMdix(uint32 port, uint32 *isMdi);




uint32 _Is4WayHashEnabled( void );
# 413 "rtl8651_layer2fwd.c" 2
# 1 "rtl8651_tblDrvFwdLocal.h" 1
# 169 "rtl8651_tblDrvFwdLocal.h"
# 1 "assert.h" 1
# 170 "rtl8651_tblDrvFwdLocal.h" 2






# 1 "rtl_queue.h" 1
# 177 "rtl8651_tblDrvFwdLocal.h" 2



# 1 "rtl8651_tblDrvFwd_utility.h" 1
# 181 "rtl8651_tblDrvFwdLocal.h" 2

# 1 "rtl8651_tblDrvLocal.h" 1
# 31 "rtl8651_tblDrvLocal.h"
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
# 183 "rtl8651_tblDrvFwdLocal.h" 2
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
# 14 "rtl8651_multicast_local.h"
# 1 "assert.h" 1
# 15 "rtl8651_multicast_local.h" 2
# 24 "rtl8651_multicast_local.h"
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
# 414 "rtl8651_layer2fwd.c" 2


# 1 "rtl8651_tblDrvPatch.h" 1
# 66 "rtl8651_tblDrvPatch.h"
inline int32 RTL8651_SETASICVLAN( rtl8651_tblDrv_vlanTable_t *vt );
inline int32 convert_getAsicVlan( uint16 vid, ether_addr_t * mac, uint32 * mbr,
                                      uint32 * inAclStart, uint32 * inAclEnd, uint32 * outAclStart,
                                      uint32 * outAclEnd, int8 * internalIntf, int8 * enableRoute,
                                      int8 *portState, int8 * broadcastToCpu, int8 * promiscuous,
                                      uint32 * untagPortMask, uint32 * macNumber, uint32 * mtu );

inline int32 convert_setAsicPppoe( uint32 index, uint16 sid );
inline int32 convert_getAsicPppoe( uint32 index, uint16 *sid );

inline int32 convert_setAsicExtIntIpTable( uint32 ipIdx, ipaddr_t ExtIp, ipaddr_t IntIp,
                                   uint32 localPublic, uint32 nat);
inline int32 convert_getAsicExtIntIpTable( uint32 index, ipaddr_t *ExtIp, ipaddr_t *IntIp,
                                               int8 *localPublic, int8 *nat );

inline int32 convert_setAsicArp( uint32 ArpPos, uint32 ArpIdx, uint32 asicPos );
inline int32 convert_getAsicArp( uint32 index, uint32 *nextHopRow, uint32 *nextHopColumn );

inline int32 convert_setAsicRouting( uint32 idx, ipaddr_t ipAddr, ipaddr_t ipMask,
                                         uint32 process, uint32 vidx, uint32 arpStart, uint32 arpEnd,
                                         uint32 nextHopRow, uint32 nextHopColumn, uint32 pppoeIdx );
inline int32 convert_getAsicRouting( uint32 index, ipaddr_t * ipAddr, ipaddr_t * ipMask, uint32 * process,
                                         uint32 * vidx, uint32 * arpStart, uint32 * arpEnd,
                                         uint32 * nextHopRow, uint32 * nextHopColumn, uint32 * pppoeIdx) ;

inline int32 convert_setAsicServerPortTable( uint32 index, ipaddr_t ExtIp, uint16 ExtPort,
                                                 ipaddr_t IntIp, uint16 IntPort );
inline int32 convert_getAsicServerPortTable( uint32 index, ipaddr_t *ExtIp, uint16 *ExtPort,
                                                 ipaddr_t *IntIp, uint16 *IntPort );

inline int32 convert_setAsicNaptTcpUdpTable( int8 forced,
                                                 ipaddr_t IntIp, uint16 IntPort, uint16 ExtPort,
                                                 uint32 ageSec, int8 entryType, int8 isTcp, int8 tcpFlag,
                                                 int8 isCollision, int8 isCollision2, int8 isValid );
inline int32 convert_getAsicNaptTcpUdpTable( uint8 *extIpIdx, uint16 index,
                                                 ipaddr_t *intIPAddr, uint16 *intPort, uint16 *extPort,
                                                 uint32 *ageSec, int8 * entryType, int8 *isTcp, int8 *flags,
                                                 int8 *isCollision, int8 *isValid,int8 *isCollision2,
                                                 int8 *isDedicated, uint16 *selEIdx, uint8 *selExtIpIdx );

inline int32 convert_setAsicNaptIcmpTable(int8 forced,
                ipaddr_t IntIp, uint16 IntId, uint16 ExtId,
                uint32 ageSec, int8 entryType, int16 count, int8 isCollision, int8 isValid );
inline int32 convert_getAsicNaptIcmpTable( int8 precisePort, uint16 tarId,
                                               ipaddr_t *IntIp, uint16 *IntId,
                                               uint16 *ExtId, uint32 *ageSec, int8 *entryType,
                                               uint16 *count, int8 *isCollision, int8 *isValid );

inline int32 convert_setAsicAlg( uint32 index, uint16 port );
inline int32 convert_getAsicAlg( uint32 index, uint16 *port );

inline int32 convertt_setAsicProtoTrap( uint32 index, uint8 type, uint16 content );
inline int32 convert_getAsicProtoTrap( uint32 index, uint8 *type, uint16 *content);

inline int32 convert_setAsicL2Table(uint32 row, uint32 column, ether_addr_t * mac, int8 cpu,
                int8 srcBlk, uint32 mbr, uint32 ageSec, int8 isStatic, int8 nhFlag);



int32 rtl8651_setAsicL2Table_Patch(uint32 row, uint32 column, ether_addr_t * mac, int8 cpu,
                int8 srcBlk, uint32 mbr, uint32 ageSec, int8 isStatic, int8 nhFlag);


int32 rtl8651_getAsicL2Table_Patch(uint32 row, uint32 column, rtl865x_tblAsicDrv_l2Param_t *asic_l2_t);
# 417 "rtl8651_layer2fwd.c" 2
# 1 "rtl8651_tblDrvStatistic.h" 1
# 14 "rtl8651_tblDrvStatistic.h"
typedef struct rtl8651_tblDrvNaptCounter_s {
        uint32 protoAddCount,
                   protoDelCount,
                   drvAddCount,
                   drvAgeoutCount,
                   addAttempts, addSucceeded,
                   threadWriteBackCount,
                   naptUnitAddCnt,
                   maxNaptUnitAddCnt,
                   dosCountedTcpCnt, dosCountedUdpCnt,
                   dosCountedFromInternalTcpCnt, dosCountedFromInternalUdpCnt;
} rtl8651_tblDrvNaptCounter_t;


typedef struct rtl8651_tblDrvIcmpCounter_s {
        uint32 protoAddCount,
                   protoDelCount,
                   drvAddCount,
                   learntFromAsic,
                   drvDelCount,
                   diffHashCount,
                   threadWriteBackCount,
                   syncFailure,
                   addFailure;

        uint16 curActiveCount,
                   curInactiveCount,
                   curInDriverCount,
                   curInAsicCount,
                   curDiffHashCount,
                   curFromAsicCount;

} rtl8651_tblDrvIcmpCounter_t;

extern rtl8651_tblDrvNaptCounter_t rtl8651_tblDrvNaptCounter;
extern rtl8651_tblDrvIcmpCounter_t rtl8651_tblDrvIcmpCounter;


int32 _rtl8651_dumpAsicNaptTableEntry(uint32 index, uint32 findport);
int32 _rtl8651_dumpNaptTableEntry(uint32 index, uint32 findport);
int32 _rtl8651_dumpAlgCtrlConnections(uint32 index);
int32 _rtl8651_dumpNaptIcmpTable(void);
int32 rtl8651_getTblDrvNaptIcmpCounter(rtl8651_tblDrvIcmpCounter_t *counter);
int32 _rtl8651_tblDrvStatisticReset(void);
void rtl8651_getTblDrvNaptInfo( int32 TopN, int32 listN );
# 418 "rtl8651_layer2fwd.c" 2
# 1 "asicRegs.h" 1
# 39 "asicRegs.h"
# 1 "rtl865xb_asicregs.h" 1
# 40 "asicRegs.h" 2
# 419 "rtl8651_layer2fwd.c" 2
# 1 "asicTabs.h" 1
# 420 "rtl8651_layer2fwd.c" 2
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
# 421 "rtl8651_layer2fwd.c" 2

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
# 423 "rtl8651_layer2fwd.c" 2
# 439 "rtl8651_layer2fwd.c"
static int32 _rtl8651_fwdEnginePciSend(void * data, int16 dvid, int32 iphdrOffset);
static int32 (*_arpAgent)(struct rtl_pktHdr *pkthdrPtr,struct rtl_mBuf *mbufPtr,uint16 vid)=((void *)0);
static void _rtl8651_ExtPortChecksumProcess(struct rtl_mBuf *mbuf);

void rtl8651_installArpAgent(int32 (*arpAgent)(struct rtl_pktHdr *pkthdrPtr,struct rtl_mBuf *mbufPtr,uint16 vid)){
        _arpAgent=arpAgent;
}
# 487 "rtl8651_layer2fwd.c"
static uint8 extPortMaskToPortNum[7 +1]={
        0, 1, 2, 0, 3, 0, 0, 0
};
# 544 "rtl8651_layer2fwd.c"
void _rtl8651_rxPktPreprocess_stripVlan(struct rtl_pktHdr * pPkthdr){
                struct rtl_mBuf *thisMbuf=pPkthdr->PKTHDRNXT.mbuf_first;
                uint8 *data=thisMbuf->m_data;
                uint8 dasa[12];

                memcpy(dasa,data,12);
                memcpy(data+4,dasa,12);
                pPkthdr->ph_len-=4;
                thisMbuf->m_len-=4;
                thisMbuf->m_data+=4;
}

__attribute__ ((section(".iram-l2-fwd"))) int32 rtl8651_rxPktPreprocess(struct rtl_pktHdr * pPkthdr)
{
        uint32 destExtPortList , srcPortNum;


        destExtPortList = pPkthdr->ph_extPortList;
        srcPortNum=pPkthdr->ph_portlist;
        pPkthdr->ph_extPortList&=0xf;
        if(srcPortNum>=7) {



                pPkthdr->ph_extPortList &= ~(1<<(pPkthdr->ph_srcExtPortNum-1));
                if(pPkthdr->ph_extPortList==0){


                        return -1;
                }else if (pPkthdr->ph_extPortList<8){



                        srcPortNum=extPortMaskToPortNum[pPkthdr->ph_extPortList]+6 -1;
                        pPkthdr->ph_portlist=srcPortNum;
# 599 "rtl8651_layer2fwd.c"
                        if (RtkHomeGatewayChipRevisionID < 0x02)




                        {
                                pPkthdr->ph_vlanIdx=DrvTbl.aggregator[srcPortNum].pvid&(8 -1);
                        }
                }else{

                        pPkthdr->ph_portlist=pPkthdr->ph_srcExtPortNum+6 -1;
                }

        }else{

                pPkthdr->ph_srcExtPortNum=0;
                if((pPkthdr->ph_extPortList&0xf)<8){



                        if(pPkthdr->ph_extPortList){

                                srcPortNum=extPortMaskToPortNum[pPkthdr->ph_extPortList]+6 -1;
                                pPkthdr->ph_portlist=srcPortNum;
                        }
# 635 "rtl8651_layer2fwd.c"
                        if (RtkHomeGatewayChipRevisionID < 0x02)




                        {
                                pPkthdr->ph_vlanIdx=DrvTbl.aggregator[srcPortNum].pvid&(8 -1);
                        }
                }
        }


        if(pPkthdr->ph_vlanTagged) {


                pPkthdr->ph_un_sw.ROMEDRV_USG._ph_priority = ((*((uint16 *)(pPkthdr->PKTHDRNXT.mbuf_first->m_data + 14))) & 0xe000) >> 13;







                if (RtkHomeGatewayChipRevisionID < 0x02) {

                        _rtl8651_rxPktPreprocess_stripVlan(pPkthdr);
                        pPkthdr->ph_vlanTagged=0;
                }
        }
        else
                pPkthdr->ph_un_sw.ROMEDRV_USG._ph_priority = 0;






        return 0;
}


__attribute__ ((section(".iram-l2-fwd"))) int32 rtl8651_txPktPostProcessing(struct rtl_pktHdr * pPkt)
{
        uint32 destPortMask=pPkt->ph_portlist;

        destPortMask&= ~0x40;

        if(destPortMask){

                if(destPortMask & 0x20 && miiPhyAddress<0)
                        destPortMask&=~0x20;

                pPkt->ph_srcExtPortNum=pPkt->ph_extPortList=0;
                pPkt->ph_flags &= ~(0x0040|0x0020);
                destPortMask&=~rtl8651_allExtPortMask;
        }

        else if(pPkt->ph_srcExtPortNum){
                pPkt->ph_flags |=0x0020;
                destPortMask=7;

        }else

                pPkt->ph_flags &= ~(0x0040|0x0020);
        pPkt->ph_portlist=destPortMask;

        return 0;

}



int32 rtl8651_bridgeEnable;
int32 rtl8651_fwdEngineEnableWDS(int32 flag){
        rtl8651_bridgeEnable=flag;
        return 0;
}




int32 rtl8651_fwdEngineRemoveHostsOnExtLinkID(uint32 linkID){
        int32 retval=-1;
        if(linkID==0)
                return retval;
        rtlglue_drvMutexLock();
        _rtl8651_removeArpAndNaptFlowWhenLinkDown(-1,&linkID);
        rtlglue_drvMutexUnlock();
        return retval;
}

 int32 rtl8651_fwdEngineAddWlanSTA(uint8 *smac,uint16 myvid, uint32 myportmask, uint32 linkId){
        rtl8651_tblDrv_vlanTable_t *thisVlan;
        rtl8651_tblDrv_filterDbTableEntry_t * thisFDBentry;
        int32 retval=-1;

        if (linkId==0)
                return retval;

        rtlglue_drvMutexLock();


        thisVlan= &DrvTbl.vlan[ myvid&(8 -1)];
        do {} while (0);
         thisFDBentry=_rtl8651_getVlanFilterDatabaseEntry(myvid, (ether_addr_t*)smac);



        if(!thisFDBentry){
                int32 retval;
                int32 l2type;

                if(thisVlan->macAddrNumber){

                        if(memcmp(smac, &thisVlan->macAddr,6)==0)
                                goto out;
                }
                if(smac[0]&1){
                        goto out;
                }




                do {} while (0);
                l2type=0x0002;
                retval=_rtl8651_addVlanRefFilterDatabaseEntry(l2type, 0, myvid, (ether_addr_t *)smac, 0x00,myportmask);

                if(!retval)
                        _rtl8651_modifyVlanRefFilterDatabaseEntry(0, (ether_addr_t *)smac,((void *)0),((void *)0), &linkId, 0x00);
# 774 "rtl8651_layer2fwd.c"
                retval=0;
        } else if(thisFDBentry->memberPortMask!=myportmask ||(thisFDBentry->linkId!=linkId)){
# 789 "rtl8651_layer2fwd.c"
                _rtl8651_modifyVlanRefFilterDatabaseEntry(0, (ether_addr_t *)smac,&myportmask, ((void *)0),&linkId, 0x00);
                retval=0;
        }
out:
        rtlglue_drvMutexUnlock();
        return retval;
 }


 int32 rtl8651_fwdEngineDelWlanSTA(uint8 *mac,uint16 myvid){
        rtl8651_tblDrv_vlanTable_t *thisVlan;
        rtl8651_tblDrv_filterDbTableEntry_t * thisFDBentry;
        int32 retval=-1;
        rtlglue_drvMutexLock();

        thisVlan= &DrvTbl.vlan[ myvid&(8 -1)];
        do {} while (0);
         thisFDBentry=_rtl8651_getVlanFilterDatabaseEntry(myvid, (ether_addr_t*)mac);
        if(thisFDBentry){
                retval=_rtl8651_delVlanRefFilterDatabaseEntry(0x0002,0,(ether_addr_t *)mac);
        }
        rtlglue_drvMutexUnlock();
        return retval;
 }


__attribute__ ((section(".iram-extdev"))) int32 rtl8651_fwdEngineExtPortUcastFastRecv(struct rtl_pktHdr *pkt,uint16 myvid, uint32 myportmask)
{
        rtlglue_drvMutexLock();
        pkt->ph_flags &= ~(0x0002| 0x0001|0x0040);
        pkt->ph_portlist = myportmask;
        pkt->ph_vlanIdx= myvid & (8 -1);
        pkt->ph_srcExtPortNum= extPortMaskToPortNum[ (myportmask>>6)&7];
        pkt->ph_portlist=0;
        pkt->ph_portlist |= rtl8651_tblDrvCpuMirrorPortMask;


        _rtl8651_ExtPortChecksumProcess(pkt->PKTHDRNXT.mbuf_first);


        rtlglue_drvSend((void*)pkt);
        rtlglue_drvMutexUnlock();
        return 0;
 }

static void _rtl8651_extPortRecvL2Lookup(uint8 *data, uint16 myvid, uint32 myportmask, uint32 linkID){
        uint8 *smac=data+6;
        rtl8651_tblDrv_filterDbTableEntry_t * thisFDBentry;
        rtl8651_tblDrv_vlanTable_t *thisVlan;

        thisVlan= &DrvTbl.vlan[ myvid&(8 -1)];
        do {} while (0);
         thisFDBentry=_rtl8651_getVlanFilterDatabaseEntry(myvid, (ether_addr_t*)smac);



        if(!thisFDBentry){
                int32 retval;
                int32 l2type;

                if(thisVlan->macAddrNumber){

                        if(memcmp(smac, &thisVlan->macAddr,6)==0)
                                return;
                }
                if(smac[0]&1)
                        return;




                if(myportmask>((1<<6)-1))
                        l2type=0x0002;
                else
                        l2type=0x0004;
                retval=_rtl8651_addVlanRefFilterDatabaseEntry(l2type, 0, myvid, (ether_addr_t *)smac, 0x00,myportmask);

                if(!retval)
                        _rtl8651_modifyVlanRefFilterDatabaseEntry(0, (ether_addr_t *)smac,((void *)0),((void *)0), &linkID, 0x00);
# 878 "rtl8651_layer2fwd.c"
        } else if(thisFDBentry->memberPortMask!=myportmask ||(thisFDBentry->linkId!=linkID)){
# 893 "rtl8651_layer2fwd.c"
                _rtl8651_modifyVlanRefFilterDatabaseEntry(0, (ether_addr_t *)smac,&myportmask, ((void *)0),&linkID, 0x00);
        }
}

__attribute__ ((section(".iram-extdev"))) static void _rtl8651_ExtPortChecksumProcess(struct rtl_mBuf *mbuf)
{

        uint8 *pkt = mbuf->m_data;
        uint16 byte2;
        uint32 etherPos = 12;
        struct ip *pip = ((void *)0);

nextRound:
        byte2 = *(uint16*)(&pkt[etherPos]);
        switch (byte2)
        {
                case 0x0800:
                        pip = (struct ip *)(&pkt[(etherPos+2)]);
                        break;
                case 0x8864:
                        byte2 = (*((uint16 *)(&pkt[etherPos + 8])));
                        if (byte2 == 0x2100)
                        {
                                pip = (struct ip *)(&pkt[(etherPos + 10)]);
                                break;
                        } else
                        {
                                goto check_done;
                        }
                case 0x8100:
                        if ( pkt[etherPos + 2] & 0x10 )
                        {
                                goto check_done;
                        }
                        etherPos += 4;
                        goto nextRound;
                default:
                        goto check_done;
        }

        do {} while (0);

        if ((pip->ip_vhl & 0xf0) != 0x40)
        {
                goto check_done;
        }

        if ( (!(((uint16)(pip->ip_off)) & (0x1fff|0x2000))) &&
                (pip->ip_p == 17))
        {
                struct udphdr *ud = (struct udphdr*)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));

                if (ud->uh_sum == 0)
                {
                        ud->uh_sum = 0;
                        pip->ip_sum = 0;
                        ud->uh_sum = _rtl8651_tcpChecksum(pip);
                        pip->ip_sum = _rtl8651_ipChecksum(pip);
                }
        }

check_done:
        return;
}

int32 _WdsLinkFwd(uint8 *data,struct rtl_pktHdr* pktHdr, uint32 linkID, uint16 myvid, uint8 *vlanMac ){
        if(data[0]&1){
                struct rtl_mBuf *newMbuf= mBuf_dupPacket(pktHdr->PKTHDRNXT.mbuf_first, 0x02);
                if(newMbuf){





                        rtlglue_extDeviceSend(myvid, -((int32)(linkID)),newMbuf->m_pkthdr);
                }





        }else if(memcmp(data, vlanMac,6)!=0){
                rtl8651_tblDrv_filterDbTableEntry_t *dal2Entry;


                dal2Entry=_rtl8651_getVlanFilterDatabaseEntry(myvid, (ether_addr_t *)data);
                if(dal2Entry&&dal2Entry->linkId>0){
                        int32 UnicastToWdsLinkID= dal2Entry->linkId;




                        rtlglue_extDeviceSend(myvid, UnicastToWdsLinkID, pktHdr);
                        return 1;
                }
        }
        return 0;
}



__attribute__ ((section(".iram-extdev"))) int32 rtl8651_fwdEngineExtPortRecv(void *id, uint8 *data, uint32 len, uint16 myvid, uint32 myportmask, uint32 linkID)
{


        struct rtl_pktHdr *pktHdr=((void *)0);
        struct rtl_mBuf *m=((void *)0);
        int32 retval=-1;
        rtl8651_tblDrv_vlanTable_t *thisVlan;
        thisVlan= &DrvTbl.vlan[ myvid&(8 -1)];



        (*((volatile uint32 *)((0x03C + (0xBD010000 +0x2000)))))|=(1 << 23);


        if (linkID==0) {
                printk("packet from illegal-device-LinkID (%d)\n", linkID);
                goto out;
        }

        do {} while (0);

        rtlglue_drvMutexLock();

        if(data[0]&1 || *((uint16 *)(data+12))!=0x0800){

                _rtl8651_extPortRecvL2Lookup(data, myvid, myportmask, linkID);
        }


        m=mBuf_attachHeader((void*)((uint32)data|0xa0000000),(uint32)(id),m_clusterSize, len,0);
        if(!m){



                goto out;
        }
        ((m->m_flags) |= (0x10));
        pktHdr=m->m_pkthdr;
        pktHdr->ph_portlist = myportmask;


        pktHdr->ph_flags &= ~(0x0002| 0x0001|0x0040);


        if(rtl8651_bridgeEnable){
                if(_WdsLinkFwd(data,pktHdr,linkID,myvid,(uint8 *)&thisVlan->macAddr)){
                        retval=0;
                        goto out;
                }
        }


        _rtl8651_ExtPortChecksumProcess(m);


        _rtl8651_fwdEnginePciSend((void*)pktHdr, myvid,-1);





        retval = 0;
out:
        rtlglue_drvMutexUnlock();
        return retval;
}

int rtl8651_pptp_ppp_compress=0;
# 1071 "rtl8651_layer2fwd.c"
void rtl8651_pptpPppCompress(int enable)
{
        rtl8651_pptp_ppp_compress=enable;
}







static int32 _rtl8651_pptpL2tpInput(int32 inbound, struct rtl_pktHdr *pkthdrPtr,rtl8651_tblDrv_vlanTable_t *local_vlanp, uint8 *m_data, uint16 ethtype, rtl8651_tblDrv_pppTable_t **ppp);




static inline void _rtl8651_forgeL2tpBuffer(uint8 **l2tpBuff, uint8 *pL2tpLength, uint8 *pL2tpLengthBit, ipaddr_t gatewayIp, ipaddr_t serverIp, uint16 tunnelID, uint16 sessionID)
{
        void *buff;
        struct ip *pip;
        struct udphdr *udp;
        struct wan_l2tp_header *l2tp;
        uint8 *ppp;


        if (*l2tpBuff == ((void *)0))
        {
                *l2tpBuff = rtlglue_malloc(60);

                do {} while (0);
        }
        buff = *l2tpBuff;

        *pL2tpLength = 0;


        pip = (struct ip *)buff;

        pip->ip_vhl = 0x45;
        pip->ip_tos = 0;
        pip->ip_len = 0;
        pip->ip_id = 1;
        pip->ip_off = 0;
        pip->ip_ttl = 0xff;
        pip->ip_p = 17;
        pip->ip_sum = 0;
        do{ *((uint8*)(&pip->ip_src)) = (uint8)((gatewayIp)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((gatewayIp)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((gatewayIp)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((gatewayIp)); }while(0);
        do{ *((uint8*)(&pip->ip_dst)) = (uint8)((serverIp)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((serverIp)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((serverIp)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((serverIp)); }while(0);

        *pL2tpLength += sizeof(struct ip);


        udp = (struct udphdr *)((uint32)buff + sizeof(struct ip));

        udp->uh_sport = (1701);
        udp->uh_dport = (1701);
        udp->uh_ulen = 0;
        udp->uh_sum = 0;

        *pL2tpLength += sizeof(struct udphdr);


        l2tp = (struct wan_l2tp_header*)((uint32)udp + sizeof(struct udphdr));

        l2tp->flags_type = 0;
        l2tp->flags_length = 1;
        l2tp->flags_rsv1 = 0;
        l2tp->flags_sequence = 0;
        l2tp->flags_rsv2 = 0;
        l2tp->flags_offset = 0;
        l2tp->flags_priority = 0;
        l2tp->flags_rsv3 = 0;
        l2tp->flags_version = 2;

        l2tp->length = 0;
        l2tp->tunnel_id = (tunnelID);
        l2tp->session_id = (sessionID);

        *pL2tpLengthBit = 1;
        *pL2tpLength += sizeof(struct wan_l2tp_header);


        ppp = (uint8 *)((uint32)l2tp + sizeof(struct wan_l2tp_header));

        ppp[0] = 0xff;
        ppp[1] = 0x03;
        ppp[2] = 0x00;
        ppp[3] = 0x21;

        *pL2tpLength += 4;

}


int32 _rtl8651_fwdEngineSend_PptpL2tp( struct rtl_pktHdr * pkthdrPtr,
                                       rtl8651_tblDrv_vlanTable_t *local_vlanp,
                                       struct rtl_mBuf *mbuf,
                                       struct ip *ip,
                                       rtl8651_tblDrv_routeTable_t *rt_t,
                                       uint32* pDestPortMask )
{
        rtl8651_tblDrv_pppTable_t *pppEntry_t;
        uint32 destPortMask = *pDestPortMask;
        int32 retval;


        pppEntry_t=rt_t->un.nxthop.un1.session.session_t;



        do {} while (0);


        if((pppEntry_t->initiated)&&(local_vlanp->vid==tunnel.loopBackVid))
        {

                if(memcmp(mbuf->m_data+6,pppEntry_t->macInfo->macAddr.octet,6)==0)
                {

                        if(tunnel.loopbackPort>=6)
                        {
                                pkthdrPtr->ph_vlanIdx= tunnel.loopBackVid & (8 -1);
                                pkthdrPtr->ph_srcExtPortNum=extPortMaskToPortNum[0x7 -(6 -1)];
                                pkthdrPtr->ph_portlist= pkthdrPtr->ph_extPortList=0;


                                _rtl8651_ExtPortChecksumProcess(mbuf);
                        }

                        destPortMask = pkthdrPtr->ph_portlist;

                        retval = 30001;
                        goto out;
                }


                else
                {


                        {
                                ip->ip_sum=0;
                                ip->ip_sum=_rtl8651_ipChecksum(ip);
                                if (!(((uint16)(ip->ip_off)) & (0x1fff|0x2000)))
                                {
                                        switch(ip->ip_p)
                                        {
                                                struct tcphdr *tc;
                                                struct udphdr *ud;
                                                struct icmp *ic;
                                                struct igmp *ig;
                                                case 6:
                                                        tc = (struct tcphdr *)((uint8 *)ip + (((*(uint8*)ip)&0xf) << 2));
                                                        tc->th_sum = 0;
                                                        tc->th_sum = _rtl8651_tcpChecksum(ip);
                                                        break;
                                                case 17:
                                                        ud = (struct udphdr *)((uint8 *)ip + (((*(uint8*)ip)&0xf) << 2));
                                                        if (ud->uh_sum)
                                                        {
                                                                ud->uh_sum = 0;
                                                                ud->uh_sum = _rtl8651_tcpChecksum(ip);
                                                        }
                                                        break;
                                                case 1:
                                                        ic = (struct icmp *)((uint8 *)ip + (((*(uint8*)ip)&0xf) << 2));
                                                        ic->icmp_cksum = 0;
                                                        ic->icmp_cksum = _rtl8651_icmpChecksum(ip);
                                                        break;
                                                case 2:
                                                        ig = (struct igmp *)((uint8 *)ip + (((*(uint8*)ip)&0xf) << 2));
                                                        ig->igmp_cksum = 0;
                                                        ig->igmp_cksum = _rtl8651_icmpChecksum(ip);
                                                        break;
                                        }
                                }
                        }
                        pkthdrPtr->ph_vlanIdx= tunnel.loopBackVid & (8 -1);
                        pkthdrPtr->ph_srcExtPortNum=pkthdrPtr->ph_extPortList=0;
                        pkthdrPtr->ph_portlist= 0x7;
                        if (_rtl8651_pptpL2tpInput(0 , pkthdrPtr, &DrvTbl.vlan[pkthdrPtr->ph_vlanIdx], pkthdrPtr->PKTHDRNXT.mbuf_first->m_data, 0x0800, &pppEntry_t) != 0)

                        {
                                mBuf_freeMbufChain(pkthdrPtr->PKTHDRNXT.mbuf_first);
                        }
                        retval = 0;
                        goto out;
                }

        }
        else if(local_vlanp->vid==tunnel.wanVid)
        {
                uint16 iplen=(ip->ip_len);


                if (rt_t->netif_t->linkLayerType == 0x05)
                {
                        if (memcmp(local_vlanp->macAddr.octet, mbuf->m_data + 6 , 6))
                        {

                                pkthdrPtr->ph_portlist = 0;
                                pkthdrPtr->ph_srcExtPortNum = 0;
                        }else
                        {
                                if(pppEntry_t->un.pptp.greBuf1__==((void *)0))
                                {

                                        pppEntry_t->un.pptp.greBuf1__=(uint8*)rtlglue_malloc(40);
                                        do {} while (0);






                                }


                                if((pppEntry_t->initiated)&&(pkthdrPtr->ph_rxdesc>=0)&&
                                        (iplen>=20)&&(iplen<=local_vlanp->mtu))
                                {
                                        struct ip* iphdr;
                                        uint32 newSeq;
                                        static int ip_id = 1;

                                        int offset=40;

                                        if(rtl8651_pptp_ppp_compress==1)
                                        {
                                                offset-=3;
                                        }


                                        pppEntry_t->un.pptp.delta__++;

                                        newSeq=pppEntry_t->un.pptp.lastSeq__+pppEntry_t->un.pptp.delta__;
                                        pppEntry_t->un.pptp.greBuf1__[21]|=0x80;

                                        if(rtl8651_pptp_ppp_compress==1)
                                        {
                                                pppEntry_t->un.pptp.greBuf1__[24]=((iplen+1)>>8)&0xff;
                                                pppEntry_t->un.pptp.greBuf1__[25]=(iplen+1)&0xff;
                                        }
                                        else
                                        {
                                                pppEntry_t->un.pptp.greBuf1__[24]=((iplen+4)>>8)&0xff;
                                                pppEntry_t->un.pptp.greBuf1__[25]=(iplen+4)&0xff;
                                        }

                                        pppEntry_t->un.pptp.greBuf1__[28]=((newSeq)>>24)&0xff;
                                        pppEntry_t->un.pptp.greBuf1__[29]=((newSeq)>>16)&0xff;
                                        pppEntry_t->un.pptp.greBuf1__[30]=((newSeq)>>8)&0xff;
                                        pppEntry_t->un.pptp.greBuf1__[31]=(newSeq)&0xff;
                                        pppEntry_t->un.pptp.greBuf1__[32]=(pppEntry_t->un.pptp.lastReceiveSeq__>>24)&0xff;
                                        pppEntry_t->un.pptp.greBuf1__[33]=(pppEntry_t->un.pptp.lastReceiveSeq__>>16)&0xff;
                                        pppEntry_t->un.pptp.greBuf1__[34]=(pppEntry_t->un.pptp.lastReceiveSeq__>>8)&0xff;
                                        pppEntry_t->un.pptp.greBuf1__[35]=pppEntry_t->un.pptp.lastReceiveSeq__&0xff;

                                        if(rtl8651_pptp_ppp_compress==1)
                                        {
                                                pppEntry_t->un.pptp.greBuf1__[36]=0x21;
                                        }
                                        else
                                        {
                                                pppEntry_t->un.pptp.greBuf1__[36]=0xff;
                                                pppEntry_t->un.pptp.greBuf1__[37]=0x03;
                                                pppEntry_t->un.pptp.greBuf1__[38]=0x00;
                                                pppEntry_t->un.pptp.greBuf1__[39]=0x21;
                                        }

                                        iphdr=(struct ip *)pppEntry_t->un.pptp.greBuf1__;

                                        pkthdrPtr->ph_proto = 2;
                                        pkthdrPtr->ph_flags |= 0x0002;
                                        pkthdrPtr->ph_flags &= ~0x0001;

                                        iphdr->ip_id = (ip_id ++);
                                        iphdr->ip_len = (iplen+offset);

                                        rtl8651_memcpy(mbuf->m_data-offset,mbuf->m_data,14);
                                        rtl8651_memcpy(mbuf->m_data-offset+14,pppEntry_t->un.pptp.greBuf1__,offset);
                                        if(offset<=128) mbuf->m_data-=offset;


                                        if (mbuf->m_data[0]==0x01 && mbuf->m_data[1]==0x00 && mbuf->m_data[2]==0x5e)
                                        {
                                                rtl8651_memcpy(mbuf->m_data, &(pppEntry_t->macInfo->macAddr), 6);
                                        }


                                        pkthdrPtr->ph_len += offset;
                                        mbuf->m_len += offset;

                                        pkthdrPtr->ph_portlist=1<<(tunnel.wanPort);
                                        destPortMask = pkthdrPtr->ph_portlist;


                                        retval = 30001;
                                        goto out;
                                }



                                else if((ip->ip_p==47)&&(pkthdrPtr->ph_rxdesc<0)
                                        &&(iplen>=28))
                                {
                                        struct wan_gre_header *gre;
                                        uint16 iphlen = (((*(uint8*)ip)&0xf) << 2);
                                        gre = (struct wan_gre_header *) ((int8 *) ip + iphlen);

                                        if(gre->flags&16)
                                        {
                                                if(gre->ver&128)
                                                {
                                                        pppEntry_t->un.pptp.lastSeq__=((uint32) (*((uint8*)(&gre->seq))<<24)|(*(((uint8*)(&gre->seq))+1)<<16)|(*(((uint8*)(&gre->seq))+2)<<8) | *(((uint8*)(&gre->seq))+3));
                                                        pppEntry_t->un.pptp.lastAck__=((uint32) (*((uint8*)(&gre->ack))<<24)|(*(((uint8*)(&gre->ack))+1)<<16)|(*(((uint8*)(&gre->ack))+2)<<8) | *(((uint8*)(&gre->ack))+3));

                                                        do{ *((uint8*)(&gre->seq)) = (uint8)((pppEntry_t->un.pptp.lastSeq__+pppEntry_t->un.pptp.delta__)>>24); *(((uint8*)(&gre->seq))+1) = (uint8)((pppEntry_t->un.pptp.lastSeq__+pppEntry_t->un.pptp.delta__)>>16); *(((uint8*)(&gre->seq))+2) = (uint8)((pppEntry_t->un.pptp.lastSeq__+pppEntry_t->un.pptp.delta__)>>8); *(((uint8*)(&gre->seq))+3) = (uint8)((pppEntry_t->un.pptp.lastSeq__+pppEntry_t->un.pptp.delta__)); }while(0);
                                                        do{ *((uint8*)(&gre->ack)) = (uint8)((pppEntry_t->un.pptp.lastAck__+pppEntry_t->un.pptp.delta__)>>24); *(((uint8*)(&gre->ack))+1) = (uint8)((pppEntry_t->un.pptp.lastAck__+pppEntry_t->un.pptp.delta__)>>16); *(((uint8*)(&gre->ack))+2) = (uint8)((pppEntry_t->un.pptp.lastAck__+pppEntry_t->un.pptp.delta__)>>8); *(((uint8*)(&gre->ack))+3) = (uint8)((pppEntry_t->un.pptp.lastAck__+pppEntry_t->un.pptp.delta__)); }while(0);
                                                }
                                                else
                                                {
                                                        pppEntry_t->un.pptp.lastSeq__=((uint32) (*((uint8*)(&gre->seq))<<24)|(*(((uint8*)(&gre->seq))+1)<<16)|(*(((uint8*)(&gre->seq))+2)<<8) | *(((uint8*)(&gre->seq))+3));

                                                        do{ *((uint8*)(&gre->seq)) = (uint8)((pppEntry_t->un.pptp.lastSeq__+pppEntry_t->un.pptp.delta__)>>24); *(((uint8*)(&gre->seq))+1) = (uint8)((pppEntry_t->un.pptp.lastSeq__+pppEntry_t->un.pptp.delta__)>>16); *(((uint8*)(&gre->seq))+2) = (uint8)((pppEntry_t->un.pptp.lastSeq__+pppEntry_t->un.pptp.delta__)>>8); *(((uint8*)(&gre->seq))+3) = (uint8)((pppEntry_t->un.pptp.lastSeq__+pppEntry_t->un.pptp.delta__)); }while(0);
                                                }

                                                if((pppEntry_t->un.pptp.greBuf1__[26]!=(((gre->call_id)>>8)&0xff))||
                                                        (pppEntry_t->un.pptp.greBuf1__[27]!=(((gre->call_id)&0xff)))||(pppEntry_t->un.pptp.peerCallId__==0))
                                                {
                                                        pppEntry_t->un.pptp.peerCallId__=(gre->call_id);
                                                        rtl8651_memcpy(pppEntry_t->un.pptp.greBuf1__,ip,28);
                                                        pppEntry_t->un.pptp.greBuf1__[22]=0x88;
                                                        pppEntry_t->un.pptp.greBuf1__[23]=0x0b;
                                                        pppEntry_t->un.pptp.greBuf1__[26]=(pppEntry_t->un.pptp.peerCallId__>>8)&0xff;
                                                        pppEntry_t->un.pptp.greBuf1__[27]=pppEntry_t->un.pptp.peerCallId__&0xff;

                                                }

                                        }
                                        else if(gre->ver&128)
                                        {
                                                pppEntry_t->un.pptp.lastAck__=((uint32) (*((uint8*)(&gre->seq))<<24)|(*(((uint8*)(&gre->seq))+1)<<16)|(*(((uint8*)(&gre->seq))+2)<<8) | *(((uint8*)(&gre->seq))+3));
                                                do{ *((uint8*)(&gre->seq)) = (uint8)((pppEntry_t->un.pptp.lastAck__+pppEntry_t->un.pptp.delta__)>>24); *(((uint8*)(&gre->seq))+1) = (uint8)((pppEntry_t->un.pptp.lastAck__+pppEntry_t->un.pptp.delta__)>>16); *(((uint8*)(&gre->seq))+2) = (uint8)((pppEntry_t->un.pptp.lastAck__+pppEntry_t->un.pptp.delta__)>>8); *(((uint8*)(&gre->seq))+3) = (uint8)((pppEntry_t->un.pptp.lastAck__+pppEntry_t->un.pptp.delta__)); }while(0);
                                        }

                                        retval = 30001;
                                        goto out;
                                }
                        }
                }
                else if (rt_t->netif_t->linkLayerType == 0x06)
                {
                        if (memcmp(local_vlanp->macAddr.octet, mbuf->m_data + 6 , 6))
                        {

                                pkthdrPtr->ph_portlist = 0;
                                pkthdrPtr->ph_srcExtPortNum = 0;
                        }else
                        {
                                if(pppEntry_t->un.l2tp.l2tpBuf1__==((void *)0))
                                {
                                        pppEntry_t->un.l2tp.l2tpBuf1__=(uint8*)rtlglue_malloc(60);
                                        do {} while (0);
                                }



                                if((pppEntry_t->initiated)&&(pkthdrPtr->ph_rxdesc>=0)&&
                                        (iplen>=20)&&(iplen<=1452))
                                {

                                        struct ip *iphdr=(struct ip *)pppEntry_t->un.l2tp.l2tpBuf1__;
                                        struct udphdr *udph = (struct udphdr *) ((int8 *) iphdr + ((iphdr->ip_vhl &0xf) << 2));
                                        static uint16 ip_id = 1;


                                        pkthdrPtr->ph_proto=6;
                                        pkthdrPtr->ph_flags|=0x0002;
                                        pkthdrPtr->ph_flags|=0x0001;
                                        iphdr->ip_len=(iplen+pppEntry_t->un.l2tp.l2tpOffset__);
                                        iphdr->ip_id = (ip_id ++);
                                        udph->uh_ulen=(iplen+18);

                                        if(pppEntry_t->un.l2tp.l2tpLengthBit__==1)
                                        {
                                                udph->uh_ulen=((udph->uh_ulen)+2);
                                                if((pppEntry_t->un.l2tp.l2tpBuf1__[pppEntry_t->un.l2tp.l2tpOffset__-2]==0)&&(pppEntry_t->un.l2tp.l2tpBuf1__[pppEntry_t->un.l2tp.l2tpOffset__-3]==0x03))
                                                {
                                                        pppEntry_t->un.l2tp.l2tpBuf1__[pppEntry_t->un.l2tp.l2tpOffset__-10]=((iplen+12)>>8)&0xff;
                                                        pppEntry_t->un.l2tp.l2tpBuf1__[pppEntry_t->un.l2tp.l2tpOffset__-9]=(iplen+12)&0xff;
                                                }
                                                else
                                                {
                                                        pppEntry_t->un.l2tp.l2tpBuf1__[pppEntry_t->un.l2tp.l2tpOffset__-7]=((iplen+9)>>8)&0xff;
                                                        pppEntry_t->un.l2tp.l2tpBuf1__[pppEntry_t->un.l2tp.l2tpOffset__-6]=(iplen+9)&0xff;
                                                }
                                        }

                                        rtl8651_memcpy(mbuf->m_data-pppEntry_t->un.l2tp.l2tpOffset__,mbuf->m_data,14);
                                        rtl8651_memcpy(mbuf->m_data-pppEntry_t->un.l2tp.l2tpOffset__+14,pppEntry_t->un.l2tp.l2tpBuf1__,pppEntry_t->un.l2tp.l2tpOffset__);
                                        if(pppEntry_t->un.l2tp.l2tpOffset__<=128) mbuf->m_data-=pppEntry_t->un.l2tp.l2tpOffset__;


                                        if (mbuf->m_data[0]==0x01 && mbuf->m_data[1]==0x00 && mbuf->m_data[2]==0x5e)
                                        {
                                                rtl8651_memcpy(mbuf->m_data, &(pppEntry_t->macInfo->macAddr), 6);
                                        }


                                        pkthdrPtr->ph_len += pppEntry_t->un.l2tp.l2tpOffset__;
                                        mbuf->m_len += pppEntry_t->un.l2tp.l2tpOffset__;
                                        pkthdrPtr->ph_portlist=1<<(tunnel.wanPort);
                                        destPortMask = pkthdrPtr->ph_portlist;

                                        retval = 30001;
                                        goto out;
                                }


                                else if((ip->ip_p==17)&&(iplen>=34))
                                {
                                        struct udphdr *udp;
                                        udp = (struct udphdr *)((uint8 *)ip + (((*(uint8*)ip)&0xf) << 2));
                                        if((udp->uh_dport)==1701)
                                        {
                                                struct wan_l2tp_header *l2tp=(struct wan_l2tp_header*)(udp+1);

                                                if(((l2tp->tunnel_id)==0)&&((l2tp->session_id)==0))
                                                {
                                                        pppEntry_t->un.l2tp.l2tpBuf1State__=0;
                                                        pppEntry_t->un.l2tp.l2tpOffset__=0;
                                                        pppEntry_t->un.l2tp.tunnelId__=0;
                                                        pppEntry_t->un.l2tp.l2tpSessionId__=0;
                                                        pppEntry_t->un.l2tp.serverIp__=0;
                                                        pppEntry_t->un.l2tp.l2tpLengthBit__=0;
                                                }






                                                if ( (pppEntry_t->un.l2tp.l2tpBuf1State__ == 0) &&
                                                       (l2tp->flags_type == 0) &&
                                                        (l2tp->flags_offset == 0) &&
                                                        (l2tp->flags_sequence == 0) )
                                                {
                                                        if (pppEntry_t->un.l2tp.l2tpBuf1__ == ((void *)0))
                                                        {
                                                                pppEntry_t->un.l2tp.l2tpBuf1__ = rtlglue_malloc(60);
                                                                do {} while (0);
                                                        }

                                                        if (iplen < 60)
                                                        {
                                                                rtl8651_memcpy(pppEntry_t->un.l2tp.l2tpBuf1__, ip, iplen);
                                                                pppEntry_t->un.l2tp.l2tpOffset__ = (uint32)l2tp - (uint32)ip + 10 ;

                                                                if(l2tp->flags_length)
                                                                {
                                                                        pppEntry_t->un.l2tp.l2tpOffset__ += 2;
                                                                        pppEntry_t->un.l2tp.l2tpLengthBit__= 1;
                                                                }else
                                                                {
                                                                        pppEntry_t->un.l2tp.l2tpLengthBit__ = 0;
                                                                }
                                                                pppEntry_t->un.l2tp.l2tpBuf1__[pppEntry_t->un.l2tp.l2tpOffset__ - 4] = 0xff;
                                                                pppEntry_t->un.l2tp.l2tpBuf1__[pppEntry_t->un.l2tp.l2tpOffset__ - 3] = 0x03;
                                                                pppEntry_t->un.l2tp.l2tpBuf1__[pppEntry_t->un.l2tp.l2tpOffset__ - 2] = 0x00;
                                                                pppEntry_t->un.l2tp.l2tpBuf1__[pppEntry_t->un.l2tp.l2tpOffset__ - 1] = 0x21;


                                                                pppEntry_t->un.l2tp.l2tpBuf1State__ = 1;
                                                        }
                                                } else if (l2tp->flags_type == 1)
                                                {
                                                        int32 pureL2tpHdrLen = 8;

                                                        do {} while (0);

                                                        if (l2tp->flags_sequence)
                                                        {
                                                                pureL2tpHdrLen += 4;
                                                        }

                                                        if ((l2tp->length) <= pureL2tpHdrLen)
                                                        {
                                                        }else
                                                        {
                                                                int32 totalAVPLengthBudget;
                                                                uint8 *AVP;

                                                                AVP = (uint8 *)((uint32)l2tp + pureL2tpHdrLen);

                                                                totalAVPLengthBudget = (l2tp->length) - pureL2tpHdrLen;
                                                                do {} while (0);


                                                                while (totalAVPLengthBudget > 0)
                                                                {
                                                                        int32 currentAVPLength;
                                                                        uint16 attributeType;

                                                                        currentAVPLength = (*(uint16 *)AVP) & 0x3ff;
                                                                        do {} while (0);

                                                                        attributeType = (*(uint16 *)((uint32)AVP + 4));


                                                                        switch (attributeType)
                                                                        {
                                                                                case 0:
                                                                                {
# 1593 "rtl8651_layer2fwd.c"
                                                                                        if (currentAVPLength == 8)
                                                                                        {
                                                                                                uint16 msgType;

                                                                                                msgType = (*(uint16 *)((uint32)AVP + 6));

                                                                                                switch (msgType)
                                                                                                {
                                                                                                        case 12:
                                                                                                        {




                                                                                                                if ((pppEntry_t->un.l2tp.l2tpBuf1__) && (pppEntry_t->un.l2tp.l2tpOffset__ >= 8))
                                                                                                                {
                                                                                                                        *(uint16*)&(pppEntry_t->un.l2tp.l2tpBuf1__[pppEntry_t->un.l2tp.l2tpOffset__ - 8]) = l2tp->tunnel_id;
                                                                                                                        *(uint16*)&(pppEntry_t->un.l2tp.l2tpBuf1__[pppEntry_t->un.l2tp.l2tpOffset__ - 6]) = l2tp->session_id;
                                                                                                                }else
                                                                                                                {
                                                                                                                        uint16 tunnelID = (l2tp->tunnel_id);
                                                                                                                        uint16 sessionID = (l2tp->session_id);
                                                                                                                        ipaddr_t gatewayIp = ((uint32) (*((uint8*)(&ip->ip_src))<<24)|(*(((uint8*)(&ip->ip_src))+1)<<16)|(*(((uint8*)(&ip->ip_src))+2)<<8) | *(((uint8*)(&ip->ip_src))+3));
                                                                                                                        ipaddr_t serverIp = ((uint32) (*((uint8*)(&ip->ip_dst))<<24)|(*(((uint8*)(&ip->ip_dst))+1)<<16)|(*(((uint8*)(&ip->ip_dst))+2)<<8) | *(((uint8*)(&ip->ip_dst))+3));

                                                                                                                        _rtl8651_forgeL2tpBuffer(&pppEntry_t->un.l2tp.l2tpBuf1__,
                                                                                                                                                                         &pppEntry_t->un.l2tp.l2tpOffset__,
                                                                                                                                                                         &pppEntry_t->un.l2tp.l2tpLengthBit__,
                                                                                                                                                                         gatewayIp,
                                                                                                                                                                         serverIp,
                                                                                                                                                                         tunnelID,
                                                                                                                                                                         sessionID);
                                                                                                                }
                                                                                                        }
                                                                                                        break;
                                                                                                }
                                                                                        }

                                                                                }
                                                                                break;
                                                                        }

                                                                        AVP = (uint8 *)((uint32)AVP + currentAVPLength);

                                                                        do {} while (0);
                                                                        totalAVPLengthBudget -= currentAVPLength;
                                                                }
                                                        }
                                                }
# 1677 "rtl8651_layer2fwd.c"
                                                retval = 30001;
                                                goto out;
                                        }
                                }
                        }
                }
        }



        retval = 30000;
out:
        *pDestPortMask = destPortMask;
        return retval;
}







int32 _rtl8651_fwdEngineSend_FromPS( int16 dvid,
                                     struct rtl_pktHdr * pkthdrPtr,
                                     rtl8651_tblDrv_vlanTable_t *local_vlanp,
                                     struct rtl_mBuf *mbuf,
                                     uint32* pDestPortMask )
{
        rtl8651_tblDrv_filterDbTableEntry_t *dal2Entry;
        int32 retval;
        uint32 destPortMask = *pDestPortMask;




        struct rtl_mBuf *newMbuf;
# 1728 "rtl8651_layer2fwd.c"
        if((mbuf->m_data[0]&1)==0){

                dal2Entry=_rtl8651_getVlanFilterDatabaseEntry(dvid, (ether_addr_t *)&mbuf->m_data[0]);
                if(dal2Entry && (dal2Entry->memberPortMask&local_vlanp->memberPortMask)){



                        if(dal2Entry->memberPortMask&peripheralExtPortMask)
                        {





                                rtlglue_extDeviceSend(local_vlanp->vid, (int32)(dal2Entry->linkId), pkthdrPtr);
                                retval = 0;
                                goto out;
                        }






                        destPortMask =dal2Entry->memberPortMask;

                        retval = 30002;
                        goto out;

                }






        }



        if(destPortMask & local_vlanp->memberPortMask & peripheralExtPortMask)
        {
                newMbuf= mBuf_dupPacket(mbuf, 0x02);
                if(newMbuf){





                        rtlglue_extDeviceSend(local_vlanp->vid, 0, newMbuf->m_pkthdr);
                }
        }

        destPortMask&=local_vlanp->memberPortMask&((1<<6)-1);

        destPortMask &= ~peripheralExtPortMask;





        pkthdrPtr->ph_srcExtPortNum=0;
        retval = 30001;


out:
        *pDestPortMask = destPortMask;
        return retval;
}






int32 _rtl8651_fwdEngineSend_ExtDevSend( int16 dvid,
                                         struct rtl_pktHdr * pkthdrPtr,
                                         rtl8651_tblDrv_vlanTable_t *local_vlanp,
                                         struct rtl_mBuf *mbuf,
                                         struct ip *ip,
                                         uint32* pDestPortMask )
{
        rtl8651_tblDrv_filterDbTableEntry_t *dal2Entry;
        int32 retval;
        uint32 destPortMask = *pDestPortMask;
        uint32 vlanMbrPortMask;
        struct rtl_mBuf *newMbuf;
        uint32 linkId=0;
# 1830 "rtl8651_layer2fwd.c"
        vlanMbrPortMask = local_vlanp->memberPortMask;


        dal2Entry=_rtl8651_getVlanFilterDatabaseEntry(dvid, (ether_addr_t *)&mbuf->m_data[0]);

        if(dal2Entry && (dal2Entry->memberPortMask & vlanMbrPortMask))
                linkId=dal2Entry->linkId;

        if(ip){
                ip->ip_sum=0;
                ip->ip_sum=_rtl8651_ipChecksum(ip);
                if (!(((uint16)(ip->ip_off)) & (0x1fff|0x2000)))
                {
                        switch(ip->ip_p)
                        {
                                struct tcphdr *tc;
                                struct udphdr *ud;
                                struct icmp *ic;
                                struct igmp *ig;
                                case 6:
                                        tc = (struct tcphdr *)((uint8 *)ip + (((*(uint8*)ip)&0xf) << 2));
                                        tc->th_sum = 0;
                                        tc->th_sum = _rtl8651_tcpChecksum(ip);
                                        break;
                                case 17:
                                        ud = (struct udphdr *)((uint8 *)ip + (((*(uint8*)ip)&0xf) << 2));
                                        if (ud->uh_sum)
                                        {
                                                ud->uh_sum = 0;
                                                ud->uh_sum = _rtl8651_tcpChecksum(ip);
                                        }
                                        break;
                                case 1:
                                        ic = (struct icmp *)((uint8 *)ip + (((*(uint8*)ip)&0xf) << 2));
                                        ic->icmp_cksum = 0;
                                        ic->icmp_cksum = _rtl8651_icmpChecksum(ip);
                                        break;
                                case 2:
                                        ig = (struct igmp *)((uint8 *)ip + (((*(uint8*)ip)&0xf) << 2));
                                        ig->igmp_cksum = 0;
                                        ig->igmp_cksum = _rtl8651_icmpChecksum(ip);
                                        break;
                        }
                }
        }
        if((destPortMask&((1<<6)-1))==0){
# 1887 "rtl8651_layer2fwd.c"
                rtlglue_extDeviceSend(local_vlanp->vid, (int32)linkId, pkthdrPtr);

                retval = 0;
                goto out;
        }

        newMbuf= mBuf_dupPacket(mbuf, 0x02);
        if(newMbuf){
# 1906 "rtl8651_layer2fwd.c"
                rtlglue_extDeviceSend(local_vlanp->vid, (int32)linkId, newMbuf->m_pkthdr);


        }



        destPortMask &= ~(destPortMask & peripheralExtPortMask & vlanMbrPortMask);
        destPortMask &= ~(1<<(pkthdrPtr->ph_srcExtPortNum-1+6));






        retval = 30000;
out:
        *pDestPortMask = destPortMask;
        return retval;
}
# 1941 "rtl8651_layer2fwd.c"
__attribute__ ((section(".iram-l2-fwd"))) int32 _rtl8651_fwdEngineSend(uint32 property, void * data, int16 dvid, int32 iphdrOffset)
{
        struct rtl_pktHdr * pkthdrPtr=(struct rtl_pktHdr *)data;
        struct ip *ip=((void *)0);
        uint32 destPortMask=pkthdrPtr->ph_portlist;
        uint32 vlanMbrPortMask;
        struct rtl_mBuf *mbuf;
        rtl8651_tblDrv_vlanTable_t *local_vlanp;
        int32 retval=0;
# 1961 "rtl8651_layer2fwd.c"
        do {} while (0);
        do {} while (0);
        do {} while (0);
        mbuf=pkthdrPtr->PKTHDRNXT.mbuf_first;
# 1984 "rtl8651_layer2fwd.c"
        pkthdrPtr->ph_vlanIdx= dvid & (8 -1);
        local_vlanp = &DrvTbl.vlan[pkthdrPtr->ph_vlanIdx];
        vlanMbrPortMask = local_vlanp->memberPortMask;




        if(pkthdrPtr->ph_iphdrOffset)
                ip=(struct ip *)&mbuf->m_data[pkthdrPtr->ph_iphdrOffset];
        else if(iphdrOffset>=0){
                ip=(struct ip *)&mbuf->m_data[iphdrOffset];
        }


        if(rtl8651_drvPacketFastSend == 0) {
                retval=_rtl8651_egressAcl(pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid,local_vlanp,dvid,(uint8 *)mbuf->m_data,(uint8 *)ip);
                if(retval&0x1000){

                        return retval;
                }
        }




        {
                rtl8651_tblDrv_routeTable_t *rt_t;

                rt_t = DrvTbl.route+(rtl8651_tblDrvPara.routingTableSize-1);
                if (rt_t->valid != 0 && rt_t->ifrt_flag==0)
                {

                        if (((rt_t->netif_t->linkLayerType == 0x05) || (rt_t->netif_t->linkLayerType == 0x06)) &&
                            (ip) )
                        {
                                retval = _rtl8651_fwdEngineSend_PptpL2tp( pkthdrPtr, local_vlanp, mbuf, ip, rt_t, &destPortMask );
                                switch ( retval )
                                {
                                        case 30001:
                                                goto send;
                                        case 30000:
                                                break;
                                        case 0:
                                                return 0;
                                        default:
                                                do {} while (0);
                                                return retval;
                                }
                        }
                }
        }







        if(property == ((uint32)(1)<<2))
        {
                retval = _rtl8651_fwdEngineSend_FromPS( dvid, pkthdrPtr, local_vlanp, mbuf, &destPortMask );
                switch ( retval )
                {
                        case 30001:
                                goto send;
                        case 30002:
                                goto to_swcore;
                        case 0:
                                return 0;
                        default:
                                do {} while (0);
                                return retval;
                }
        }





to_swcore:





        destPortMask &= vlanMbrPortMask;


        if(destPortMask & peripheralExtPortMask & vlanMbrPortMask){
                retval = _rtl8651_fwdEngineSend_ExtDevSend( dvid, pkthdrPtr, local_vlanp, mbuf, ip, &destPortMask );
                switch ( retval )
                {
                        case 30000:
                                break;
                        case 0:
                                return 0;
                        default:
                                do {} while (0);
                                return retval;
                }
        }
        pkthdrPtr->ph_srcExtPortNum=0;
send:






        do {} while (0);
        destPortMask |= rtl8651_tblDrvCpuMirrorPortMask;



        destPortMask &= phyPortLinkStatus;





        if ( rtl8651_tblDrvSpanningTreeEnable &&

                (property & (((uint32)(1)<<1)|((uint32)(1)<<3)) || ((pkthdrPtr->ph_un_sw.PS_USG.FROM_PS._ph_pkt_property & (1<<0)) == 0)))
        {
                destPortMask &= rtl8651_tblDrvSpanningTreePortFwdStatus;
        }


        if(destPortMask==0&&pkthdrPtr->ph_srcExtPortNum==0){

                mBuf_freeMbufChain(mbuf);
                return 0;
        }
# 2155 "rtl8651_layer2fwd.c"
        do {} while (0);
        {
                uint32 swNicRxIndex;
# 2166 "rtl8651_layer2fwd.c"
                rtlglue_getRingSize(&swNicRxIndex, ((void *)0));



                if( (pkthdrPtr->ph_rxdesc >= 0) &&
                        (pkthdrPtr->ph_rxdesc < swNicRxIndex) &&
                        (local_vlanp->internal == 0) &&
                        (pkthdrPtr->ph_srcExtPortNum == 0))
                {
                        _rtl8651_recordTraffic(pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid, 1 );
                }
        }
# 2186 "rtl8651_layer2fwd.c"
        pkthdrPtr->ph_portlist=destPortMask;


        if ((pkthdrPtr->ph_rxdesc >= 0) && ip)
                _rtl8651_fragmentShortestPathCacheSet_secondHalf(pkthdrPtr, pkthdrPtr->PKTHDRNXT.mbuf_first->m_data, ip);





        rtlglue_drvSend((void*)data);





        return 0;
}


static int32 _rtl8651_layer2Passthrough(struct rtl_pktHdr *pkthdrPtr,rtl8651_tblDrv_vlanTable_t *local_vlanp, uint8 *m_data, uint16 ethtype){




        if ( ( rtl8651_l2protoPassThrough & (1<<0) && ( ethtype == 0x8863 || ethtype == 0x8864 ) ) ||
             ( rtl8651_l2protoPassThrough & (1<<1) && ethtype == 0x86DD ) ||
             ( rtl8651_l2protoPassThrough & (1<<2) && ethtype == 0xE0E0 ) ||
             ( rtl8651_l2protoPassThrough & (1<<3) && ethtype == 0xF0F0 ) )
        {
                ether_addr_t vlanGMAC;




                rtl8651_getVlanMacAddress( local_vlanp->vid, &vlanGMAC, ((void *)0) );


                if ( memcmp( pkthdrPtr->PKTHDRNXT.mbuf_first->m_data, &vlanGMAC, sizeof(ether_addr_t) ) != 0 )
                {
                        int32 retval;
                        rtl8651_tblDrv_filterDbTableEntry_t *macinfo;
                        struct ether_header *ethHdr;
                        uint16 srcport;
# 2240 "rtl8651_layer2fwd.c"
                        srcport = pkthdrPtr->ph_portlist;
                        ethHdr = (struct ether_header*)m_data;




                        if ( rtl8651_drvDropUnknownPppoePADT &&
                             ethtype == 0x8863 )
                        {
                                pppoeHdr_t *pppoeHdr;

                                pppoeHdr = (pppoeHdr_t *)(((char*)ethHdr)+sizeof(struct ether_header));



                                if ( local_vlanp->internal==0 &&
                                     pppoeHdr->code==0xa7 )
                                {
# 2267 "rtl8651_layer2fwd.c"
                                        if ( memcmp( ethHdr->ether_dhost, rtl8651_knownPppoePassthruEthHdr.ether_shost, 6 ) )
                                        {

                                                return 13;
                                        }
                                        else
                                        {

                                        }
                                }


                                if ( local_vlanp->internal==1 )
                                {
                                        rtl8651_knownPppoePassthruEthHdr = *ethHdr;







                                }

                        }
# 2314 "rtl8651_layer2fwd.c"
                        if (( (1<<srcport) & peripheralExtPortMask ) &&
                                (pkthdrPtr->ph_extPortList < 8) )
                        {




                                return -1;
                        }
                        else
                        {

                                macinfo = _rtl8651_getVlanFilterDatabaseEntry( 0 , (struct ether_addr_s*) ethHdr->ether_dhost );
                                if ( macinfo == ((void *)0) )
                                {


                                        switch ( ethtype )
                                        {
                                                case 0x86DD:

                                                        pkthdrPtr->ph_portlist = ( DrvTbl.vlan[(rtl8651_gIPv6PassthruVlanID& (8 -1))].memberPortMask | peripheralExtPortMask ) & (~(1<<srcport));
                                                        break;

                                                case 0xE0E0:

                                                        pkthdrPtr->ph_portlist = ( DrvTbl.vlan[(rtl8651_gIPXPassthruVlanID& (8 -1))].memberPortMask | peripheralExtPortMask ) & (~(1<<srcport));
                                                        break;

                                                case 0xF0F0:

                                                        pkthdrPtr->ph_portlist = ( DrvTbl.vlan[(rtl8651_gNetbiosPassthruVlanID& (8 -1))].memberPortMask | peripheralExtPortMask ) & (~(1<<srcport));
                                                        break;

                                                default:

                                                        pkthdrPtr->ph_portlist = ( DrvTbl.vlan[(rtl8651_gPPPoEPassthruVlanID& (8 -1))].memberPortMask | peripheralExtPortMask ) & (~(1<<srcport));
                                                        break;
                                        }
                                }
                                else
                                {


                                        pkthdrPtr->ph_portlist = macinfo->memberPortMask & (~(1<<srcport));
                                }
                        }

                        if ( ethtype == 0x8864 )
                        {
                                pkthdrPtr->ph_pppeTagged = 0;
                                pkthdrPtr->ph_flags &= ~(0x0008|0x0002|0x0001);
                        }







                        retval = _rtl8651_fwdEngineSend( ((uint32)(1)<<1),
                                                             (void*)pkthdrPtr,
                                                         ethtype==0x86DD?rtl8651_gIPv6PassthruVlanID:
                                                         ethtype==0xE0E0?rtl8651_gIPXPassthruVlanID:
                                                         ethtype==0xF0F0?rtl8651_gNetbiosPassthruVlanID:
                                                         rtl8651_gPPPoEPassthruVlanID,
                                                         -1 );

                        if ( retval != 0 )
                        {
                                mBuf_freeMbufChain( pkthdrPtr->PKTHDRNXT.mbuf_first );
                        }
# 2509 "rtl8651_layer2fwd.c"
                        return 0;
                }
                else
                {


                }
        }
        return -1;
}


static int32 _rtl8651_pptpL2tpInput(int32 inbound, struct rtl_pktHdr *pkthdrPtr,rtl8651_tblDrv_vlanTable_t *local_vlanp, uint8 *m_data, uint16 ethtype, rtl8651_tblDrv_pppTable_t **ppp){
        rtl8651_tblDrv_routeTable_t *rt_t=((void *)0);
        rtl8651_tblDrv_pppTable_t *pppEntry_t=((void *)0);

        rt_t = DrvTbl.route+(rtl8651_tblDrvPara.routingTableSize-1);
        if (rt_t->valid != 0 && rt_t->ifrt_flag==0)
        {
                if ((rt_t->netif_t->linkLayerType == 0x05) || (rt_t->netif_t->linkLayerType == 0x06))
                {

                        pppEntry_t=rt_t->un.nxthop.un1.session.session_t;



                }
        }

        *ppp=pppEntry_t;



        if(inbound==1)
        {
                struct rtl_mBuf *mbufPtr=pkthdrPtr->PKTHDRNXT.mbuf_first;

                if((pppEntry_t)&&(ethtype==0x0800))
                {
                        struct ip *ip=((void *)0),*ip2=((void *)0);

                        if(pkthdrPtr->ph_iphdrOffset)
                                ip=(struct ip *)&m_data[pkthdrPtr->ph_iphdrOffset];

                        if(ip)
                        {
                                if(rt_t->netif_t->linkLayerType == 0x05)
                                {

                                        if((ip->ip_p==47)&&((ip->ip_len)>=28))
                                        {

                                                struct wan_gre_header *gre;

                                                uint16 iphlen = (((*(uint8*)ip)&0xf) << 2);
                                                uint16 offset=iphlen+8,ip2len=0;
                                                uint8 *ptr;
                                                uint32 gre_seq, gre_ack;
                                                uint8 gre_type;

                                                gre = (struct wan_gre_header *) ((int8 *) ip + iphlen);
                                                gre_seq = 0;
                                                gre_ack = 0;
                                                gre_type = 0;

                                                if(gre->flags&16)
                                                {
                                                        offset+=4;
                                                        pppEntry_t->un.pptp.lastReceiveSeq__= ((uint32) (*((uint8*)(&gre->seq))<<24)|(*(((uint8*)(&gre->seq))+1)<<16)|(*(((uint8*)(&gre->seq))+2)<<8) | *(((uint8*)(&gre->seq))+3));
                                                        gre_seq = pppEntry_t->un.pptp.lastReceiveSeq__;
                                                        gre_type |= 0x01;


                                                        if(gre->ver&128)
                                                        {
                                                                offset+=4;
                                                                gre_ack = ((uint32) (*((uint8*)(&gre->ack))<<24)|(*(((uint8*)(&gre->ack))+1)<<16)|(*(((uint8*)(&gre->ack))+2)<<8) | *(((uint8*)(&gre->ack))+3));
                                                                gre_type |= 0x02;

                                                                do{ *((uint8*)(&gre->ack)) = (uint8)((gre_ack - pppEntry_t->un.pptp.delta__)>>24); *(((uint8*)(&gre->ack))+1) = (uint8)((gre_ack - pppEntry_t->un.pptp.delta__)>>16); *(((uint8*)(&gre->ack))+2) = (uint8)((gre_ack - pppEntry_t->un.pptp.delta__)>>8); *(((uint8*)(&gre->ack))+3) = (uint8)((gre_ack - pppEntry_t->un.pptp.delta__)); }while(0);
                                                        }

                                                }
                                                else if(gre->ver&128)
                                                {
                                                        offset+=4;
                                                        gre_ack = ((uint32) (*((uint8*)(&gre->seq))<<24)|(*(((uint8*)(&gre->seq))+1)<<16)|(*(((uint8*)(&gre->seq))+2)<<8) | *(((uint8*)(&gre->seq))+3));
                                                        gre_type |= 0x02;
                                                        do{ *((uint8*)(&gre->seq)) = (uint8)((gre_ack - pppEntry_t->un.pptp.delta__)>>24); *(((uint8*)(&gre->seq))+1) = (uint8)((gre_ack - pppEntry_t->un.pptp.delta__)>>16); *(((uint8*)(&gre->seq))+2) = (uint8)((gre_ack - pppEntry_t->un.pptp.delta__)>>8); *(((uint8*)(&gre->seq))+3) = (uint8)((gre_ack - pppEntry_t->un.pptp.delta__)); }while(0);

                                                }

                                                ptr=(uint8 *)ip;

                                                if((pppEntry_t->initiated)&&(gre->payload_len))
                                                {
# 2651 "rtl8651_layer2fwd.c"
                                                        uint32 grePayloadLen = 0;

                                                        if ((ptr[offset] == 0xff) && (ptr[offset + 1] == 0x03))
                                                        {
                                                                offset += 2;
                                                                grePayloadLen += 2;
                                                        }

                                                        if ( ((ptr[offset] == 0x00) && (ptr[offset + 1] == 0x21) ) ||
                                                                (ptr[offset] == 0x21 ))
                                                        {

                                                                if (ptr[offset] == 0x21)
                                                                {
                                                                        offset += 1;
                                                                        grePayloadLen += 1;
                                                                } else
                                                                {
                                                                        offset += 2;
                                                                        grePayloadLen += 2;
                                                                }

                                                                ip2=(struct ip *)(ptr+offset);




                                                                if ( ( (grePayloadLen + (((*(uint8*)ip2)&0xf) << 2)) > (gre->payload_len) ) ||

                                                                        ( (grePayloadLen + (ip2->ip_len)) != (gre->payload_len) ))
                                                                {

                                                                } else
                                                                {
                                                                ip2len = (ip2->ip_len);

                                                                if(ip2len<=local_vlanp->mtu)
                                                                {
                                                                        {

                                                                                uint16 id = (ip2->ip_id);
                                                                                uint16 offset = (ip2->ip_off);
                                                                                _rtl8651_pptpHdrCache_Add(id, offset, gre_seq, gre_ack, gre_type);


                                                                                if (pppEntry_t->un.pptp.greOffset2__ == 0)
                                                                                {

                                                                                        if (pppEntry_t->un.pptp.greBuf2__ == ((void *)0))
                                                                                        {
                                                                                                do {} while (0);
                                                                                                pppEntry_t->un.pptp.greBuf2__ = rtlglue_malloc(60);
                                                                                        }

                                                                                        if (pppEntry_t->un.pptp.greBuf2__)
                                                                                        {
                                                                                                pppEntry_t->un.pptp.greOffset2__ = ((uint32)ip2 - (uint32)ip);
                                                                                                rtl8651_memcpy(pppEntry_t->un.pptp.greBuf2__, (void *)ip, pppEntry_t->un.pptp.greOffset2__);
                                                                                        }
                                                                                }else if (pppEntry_t->un.pptp.greBuf2__)
                                                                                {
                                                                                        struct ip *ipBuf;
                                                                                        struct wan_gre_header *greBuf;
                                                                                        ipBuf = (struct ip *)(pppEntry_t->un.pptp.greBuf2__);
                                                                                        greBuf = (struct wan_gre_header *)((uint8 *)ipBuf + (((*(uint8*)ipBuf)&0xf) << 2));
                                                                                        greBuf->call_id = gre->call_id;
                                                                                }
                                                                        }

                                                                        rtl8651_memcpy((uint8 *)(ip2)-14,m_data,14);
                                                                        m_data=(uint8 *)(ip2)-14;

                                                                        {
                                                                                ipaddr_t dest_ip = ((uint32) (*((uint8*)(&ip2->ip_dst))<<24)|(*(((uint8*)(&ip2->ip_dst))+1)<<16)|(*(((uint8*)(&ip2->ip_dst))+2)<<8) | *(((uint8*)(&ip2->ip_dst))+3));
                                                                                if (((((ipaddr_t)(dest_ip)) & 0xf0000000) == 0xe0000000))
                                                                                {
                                                                                        do { ((uint8*)(m_data))[0] = 0x01; ((uint8*)(m_data))[1] = 0x00; ((uint8*)(m_data))[2] = 0x5e; ((uint8*)(m_data))[3] = (uint8)((((uint32)(dest_ip)) >> 16) & 0xff); ((uint8*)(m_data))[4] = (uint8)((((uint32)(dest_ip)) >> 8) & 0xff); ((uint8*)(m_data))[5] = (uint8)(((uint32)(dest_ip)) & 0xff); ((uint8*)(m_data))[3] &= 0x7f; }while(0);;
                                                                                }

                                                                                if (dest_ip == 0xffffffff)
                                                                                {
                                                                                        do { memset(m_data, 0xff, 6); } while (0);;
                                                                                }
                                                                        }

                                                                        pkthdrPtr->ph_flags&=~0x0001;
                                                                        pkthdrPtr->ph_flags&=~0x0002;

                                                                        pkthdrPtr->ph_len -= offset;
                                                                        mbufPtr->m_len -= offset;
                                                                        mbufPtr->m_data = m_data;

                                                                        if (_rtl8651_fwdEngineSend(((uint32)(1)<<1), (void*)pkthdrPtr,tunnel.loopBackVid,-1) != 0)
                                                                        {
                                                                                mBuf_freeMbufChain(pkthdrPtr->PKTHDRNXT.mbuf_first);
                                                                        }
                                                                        return 0;
                                                                }
                                                        }
                                                }
                                        }
                                }
                                }
                                else if(rt_t->netif_t->linkLayerType == 0x06)
                                {
                                        rtl8651_tblDrv_vlanTable_t *extVlan = &DrvTbl.vlan[(tunnel.loopBackVid & (8 -1))];
                                        do {} while (0);

                                        if((ip->ip_p==17)&&((ip->ip_len)>=35)&&((ip->ip_len)<=extVlan->mtu))
                                        {
                                                struct udphdr *udp;
                                                udp = (struct udphdr *)((uint8 *)ip + (((*(uint8*)ip)&0xf) << 2));
                                                if((udp->uh_dport)==1701)
                                                {
                                                        struct wan_l2tp_header *l2tp=(struct wan_l2tp_header*)(udp+1);

                                                        if (l2tp->flags_type==0)
                                                        {
                                                                uint8 *u8p_l2tp = (uint8*)l2tp;
                                                                struct ip *ip2 = ((void *)0);
                                                                uint32 l2tpPppChkLen = 6 ;

                                                                if (l2tp->flags_length)
                                                                {
                                                                        l2tpPppChkLen += 2;
                                                                }
                                                                if (l2tp->flags_offset)
                                                                {
                                                                        l2tpPppChkLen += 2;
                                                                }


                                                                if ((u8p_l2tp[l2tpPppChkLen] == 0xff) && (u8p_l2tp[l2tpPppChkLen + 1] == 0x03))
                                                                {
                                                                        l2tpPppChkLen += 2;
                                                                }
                                                                if (u8p_l2tp[l2tpPppChkLen] == 0x21)
                                                                {
                                                                        l2tpPppChkLen += 1;
                                                                        ip2 = (struct ip *)((uint32)u8p_l2tp + l2tpPppChkLen);
                                                                } else if ((u8p_l2tp[l2tpPppChkLen] == 0x00) && (u8p_l2tp[l2tpPppChkLen + 1] == 0x21))
                                                                {
                                                                        l2tpPppChkLen += 2;
                                                                        ip2 = (struct ip *)((uint32)u8p_l2tp + l2tpPppChkLen);
                                                                }






                                                                if ( ip2 )
                                                                {
                                                                        if ( ( (l2tpPppChkLen + (((*(uint8*)ip2)&0xf) << 2) + sizeof(struct udphdr)) > (udp->uh_ulen) ) ||

                                                                                ( (l2tpPppChkLen + (ip2->ip_len) + sizeof(struct udphdr)) != (udp->uh_ulen)))
                                                                        {

                                                                                ip2 = ((void *)0);
                                                                        }
                                                                }

                                                                if ( ip2 )
                                                                {
                                                                        uint16 ip2len = (ip2->ip_len);

                                                                        if(ip2len<=extVlan->mtu)
                                                                        {

                                                                                if (pppEntry_t->un.l2tp.l2tpOffset2__ == 0)
                                                                                {

                                                                                        if (pppEntry_t->un.l2tp.l2tpBuf2__ == ((void *)0))
                                                                                        {
                                                                                                do {} while (0);
                                                                                                pppEntry_t->un.l2tp.l2tpBuf2__ = rtlglue_malloc(60);
                                                                                        }

                                                                                        if (pppEntry_t->un.l2tp.l2tpBuf2__)
                                                                                        {
                                                                                                pppEntry_t->un.l2tp.l2tpOffset2__ = ((uint32)ip2 - (uint32)ip);
                                                                                                rtl8651_memcpy(pppEntry_t->un.l2tp.l2tpBuf2__, (void *)ip, pppEntry_t->un.l2tp.l2tpOffset2__);
                                                                                        }
                                                                                }

                                                                                switch(ip2->ip_p)
                                                                                {
                                                                                        case 1:
                                                                                                pkthdrPtr->ph_proto = 3;
                                                                                                break;
                                                                                        case 2:
                                                                                                pkthdrPtr->ph_proto = 4;
                                                                                                break;
                                                                                        case 6:
                                                                                                pkthdrPtr->ph_proto = 5;
                                                                                                break;
                                                                                        case 17:
                                                                                                pkthdrPtr->ph_proto = 6;
                                                                                                break;
                                                                                }

                                                                                pkthdrPtr->ph_flags&=~0x0001;
                                                                                pkthdrPtr->ph_flags&=~0x0002;


                                                                                rtl8651_memcpy((uint8 *)(ip2)-14,m_data,14);
                                                                                m_data=(uint8 *)(ip2)-14;

                                                                                {
                                                                                        ipaddr_t dest_ip = ((uint32) (*((uint8*)(&ip2->ip_dst))<<24)|(*(((uint8*)(&ip2->ip_dst))+1)<<16)|(*(((uint8*)(&ip2->ip_dst))+2)<<8) | *(((uint8*)(&ip2->ip_dst))+3));
                                                                                        if (((((ipaddr_t)(dest_ip)) & 0xf0000000) == 0xe0000000))
                                                                                        {
                                                                                                do { ((uint8*)(m_data))[0] = 0x01; ((uint8*)(m_data))[1] = 0x00; ((uint8*)(m_data))[2] = 0x5e; ((uint8*)(m_data))[3] = (uint8)((((uint32)(dest_ip)) >> 16) & 0xff); ((uint8*)(m_data))[4] = (uint8)((((uint32)(dest_ip)) >> 8) & 0xff); ((uint8*)(m_data))[5] = (uint8)(((uint32)(dest_ip)) & 0xff); ((uint8*)(m_data))[3] &= 0x7f; }while(0);;
                                                                                        }

                                                                                        if (dest_ip == 0xffffffff)
                                                                                        {
                                                                                                do { memset(m_data, 0xff, 6); } while (0);;
                                                                                        }
                                                                                }

                                                                                pkthdrPtr->ph_len -= ((uint32)ip2-(uint32)ip);
                                                                                mbufPtr->m_len -= ((uint32)ip2-(uint32)ip);
                                                                                mbufPtr->m_data = m_data;

                                                                                if (_rtl8651_fwdEngineSend(((uint32)(1)<<1), (void*)pkthdrPtr,tunnel.loopBackVid,-1) != 0)
                                                                                {
                                                                                        mBuf_freeMbufChain(pkthdrPtr->PKTHDRNXT.mbuf_first);
                                                                                }
                                                                                return 0;
                                                                        }
                                                                }
                                                        }
# 2910 "rtl8651_layer2fwd.c"
                                                }
                                        }
                                }
                        }
                }
        }
        else if((pppEntry_t) && (pppEntry_t->initiated))
        {




                if((memcmp(pppEntry_t->macInfo->macAddr.octet,m_data,6)==0) ||
                        (m_data[0]==0x01 && m_data[1]==0x00 && m_data[2]==0x5e && memcmp(pppEntry_t->macInfo->macAddr.octet, &m_data[6], 6)!=0)){


                        return _rtl8651_fwdEngineSend(((uint32)(1)<<1), (void*)pkthdrPtr,tunnel.wanVid,-1);
                }else{


                }
        }
        return -1;
}


static int32 _rtl8651_l2switch(struct rtl_pktHdr *pkthdrPtr,rtl8651_tblDrv_vlanTable_t *local_vlanp, uint8 *m_data, uint16 ethtype);


__attribute__ ((section(".iram-l2-fwd"))) int32 rtl8651_fwdEngineL2Input(struct rtl_pktHdr *pkthdrPtr,rtl8651_tblDrv_vlanTable_t *local_vlanp, uint8 *m_data, uint16 ethtype)
{
        int32 compare;
# 2950 "rtl8651_layer2fwd.c"
        if (rtl8651_l2protoPassThrough)
        {
                int32 ret=_rtl8651_layer2Passthrough(pkthdrPtr,local_vlanp, m_data, ethtype);

                if (ret!=-1)
                {
                        return ret;
                }
        }


        {
                rtl8651_tblDrv_pppTable_t *pppEntry_t=((void *)0);
                if (local_vlanp->vid==tunnel.loopBackVid)
                {
                        int32 ret = _rtl8651_pptpL2tpInput(0 , pkthdrPtr,local_vlanp, m_data, ethtype, &pppEntry_t);

                        if (ret!=-1)
                        {
                                return ret;
                        }
                }else if (local_vlanp->vid==tunnel.wanVid)
                {
                        int32 ret = _rtl8651_pptpL2tpInput(1 , pkthdrPtr,local_vlanp, m_data, ethtype, &pppEntry_t);

                        if (ret!=-1)
                        {
                                return ret;
                        }
                }
        }
# 2999 "rtl8651_layer2fwd.c"
        if ( ((1<<pkthdrPtr->ph_portlist) & peripheralExtPortMask) &&
                (pkthdrPtr->ph_extPortList < 8) )
        {



                uint32 linkId=0;

                rtl8651_tblDrv_filterDbTableEntry_t * dal2Entry;






                for((dal2Entry) = (&(DrvTbl.filterDB[0].database[rtl8651_filterDbIndex((ether_addr_t *)m_data)]))->slh_first; (dal2Entry); (dal2Entry) = (dal2Entry)->nextFDB.sle_next)
                {
                        if (memcmp(&dal2Entry->macAddr, m_data, sizeof(ether_addr_t)) == 0)
                        {
                                break;
                        }
                }
                if (dal2Entry)
                {
                        linkId=dal2Entry->linkId;
                }
                rtlglue_extDeviceSend(local_vlanp->vid, (int32)linkId, pkthdrPtr);

                return 0;
        }


        compare = memcmp(&m_data[0], &local_vlanp->macAddr, sizeof(ether_addr_t));
        if (compare == 0)
        {







                return -1;
        } else
        {

                return _rtl8651_l2switch(pkthdrPtr,local_vlanp,m_data, ethtype);
        }
}

static int32 _rtl8651_l2PhysicalPortRelay(struct rtl_mBuf *inMbufPtr)
{
        struct rtl_pktHdr *phdr;

        phdr = inMbufPtr->m_pkthdr;


        if (DrvTbl.vlan[phdr->ph_vlanIdx].vid == tunnel.loopBackVid)
        {




        } else

        {

                struct rtl_mBuf *mbufPtr;

                mbufPtr = mBuf_dupPacket(inMbufPtr, 0x02);

                if(mbufPtr == ((void *)0))
                {



                        return -1;
                }


                mbufPtr->m_pkthdr->ph_flags &= (~(0x0002 | 0x0001));

                mbufPtr->m_pkthdr->ph_portlist = DrvTbl.vlan[phdr->ph_vlanIdx].memberPortUpStatus & ~(1<<phdr->ph_portlist);
                mbufPtr->m_pkthdr->ph_portlist &=~rtl8651_allExtPortMask;
                if (_rtl8651_fwdEngineSend(((uint32)(1)<<1), (void*)mbufPtr->m_pkthdr, DrvTbl.vlan[phdr->ph_vlanIdx].vid, -1) != 0)
                {
                        mBuf_driverFreeMbufChain(mbufPtr);
                }
        }

        return 0;
}


 int32 _rtl8651_l2switch(struct rtl_pktHdr *pkthdrPtr,rtl8651_tblDrv_vlanTable_t *local_vlanp, uint8 *m_data, uint16 ethtype){
        uint16 vid;

        uint32 vlanMbrPortMask;
        struct rtl_mBuf *mbufPtr;
        rtl8651_tblDrv_filterDbTableEntry_t *dal2Entry=((void *)0);
        struct rtl_mBuf *newMbuf;
# 3125 "rtl8651_layer2fwd.c"
        vid = local_vlanp->vid;
        vlanMbrPortMask = local_vlanp->memberPortMask;



        mbufPtr=pkthdrPtr->PKTHDRNXT.mbuf_first;
# 3141 "rtl8651_layer2fwd.c"
        if( (m_data[0]&1)==0){







                dal2Entry=_rtl8651_getVlanFilterDatabaseEntry(vid, (ether_addr_t *)&m_data[0]);

                if(dal2Entry){

                        if(dal2Entry->memberPortMask & vlanMbrPortMask) {

                                if((dal2Entry->memberPortMask&peripheralExtPortMask)==0)
                                {
# 3179 "rtl8651_layer2fwd.c"
                                        mbufPtr->m_pkthdr->ph_portlist = dal2Entry->memberPortMask & ~(1<<mbufPtr->m_pkthdr->ph_portlist);
                                        pkthdrPtr->ph_iphdrOffset=0;


                                        pkthdrPtr->ph_flags &= ~(0x0002| 0x0001);
# 3202 "rtl8651_layer2fwd.c"
                                        return _rtl8651_fwdEngineSend(((uint32)(1)<<1), (void*)pkthdrPtr,DrvTbl.vlan[pkthdrPtr->ph_vlanIdx].vid,-1 );

                                }
                                if(peripheralExtPortMask){

                                        if((1<<pkthdrPtr->ph_portlist)&peripheralExtPortMask)
                                                goto drop;
# 3230 "rtl8651_layer2fwd.c"
                                        rtlglue_extDeviceSend(vid, (int32)(dal2Entry->linkId), pkthdrPtr);

                                        return 0;
                                }
                                do {} while (0);
                        }
                }
        }
        else if (m_data[0] & 1)
        {
# 3252 "rtl8651_layer2fwd.c"
                if ( rtl8651_drvMulticastProcessEnable &&
                        (m_data[0] == 0x01 && m_data[1] == 0x00 && m_data[2] == 0x5e))
                {
                        return 46;
                }
# 3270 "rtl8651_layer2fwd.c"
                if ( rtl8651_tblDrvSpanningTreeEnable &&
                        m_data[0] == 0x01 &&
                        m_data[1] == 0x80 &&
                        m_data[2] == 0xc2 &&
                        m_data[3] == 0x00 &&
                        m_data[4] == 0x00 &&
                        ((m_data[5] <= 0x10) || ((m_data[5] & 0xf0) == 0x20)) )
                {
                        return 21;
                }
        }
# 3295 "rtl8651_layer2fwd.c"
        if (vlanMbrPortMask & peripheralExtPortMask)
        {

                if(pkthdrPtr->ph_srcExtPortNum)
                {

                        uint32 filtered = vlanMbrPortMask & ~(1 << (pkthdrPtr->ph_srcExtPortNum - 1 + 6));
                        if((filtered&rtl8651_allExtPortMask)==0)
                        {
                                goto physical_port_proc;
                        }
                }


                newMbuf= mBuf_dupPacket(mbufPtr, 0x02);
                if(newMbuf)
                {
# 3352 "rtl8651_layer2fwd.c"
                        rtlglue_extDeviceSend(vid, 0, newMbuf->m_pkthdr);

                }





        }

physical_port_proc:

        if( m_data[0]&1 )
        {
# 3378 "rtl8651_layer2fwd.c"
                if ( m_data[0] == 0x01 && m_data[1] == 0x00 && m_data[2] == 0x5e )
                {



                        _rtl8651_l2PhysicalPortRelay(mbufPtr);
                        return 46;
                }





                if ( rtl8651_drvSoftwareBroadcastEnable[vid & (8 - 1)]==1 )
                {
                        _rtl8651_l2PhysicalPortRelay(mbufPtr);
                }


                switch (ethtype)
                {

                        case 0x8863:
                        {
                                if (m_data[15] == 0x7)
                                {







                                        _rtl8651_addVlanRefFilterDatabaseEntry(0x0001, local_vlanp->fid,
                                                local_vlanp->vid, (ether_addr_t *)m_data+6, 0x00, 1<<pkthdrPtr->ph_portlist);
                                }
                                return 13;
                        }
                                break;
                        case 0x0806:
                        {
                                if (_arpAgent)
                                {
                                        return _arpAgent (pkthdrPtr, mbufPtr, vid);
                                }
                        }
                                break;
                }


                return 10;

        }
# 3468 "rtl8651_layer2fwd.c"
drop:
        mBuf_driverFreeMbufChain(pkthdrPtr->PKTHDRNXT.mbuf_first);

        return 0;
}


__attribute__ ((section(".iram-extdev"))) static int32 _rtl8651_fwdEnginePciSend(void * data, int16 dvid, int32 iphdrOffset)
{
        struct rtl_pktHdr * pkthdrPtr=(struct rtl_pktHdr *)data;

        struct rtl_mBuf *mbuf;
        rtl8651_tblDrv_vlanTable_t *local_vlanp;

        mbuf=pkthdrPtr->PKTHDRNXT.mbuf_first;
        pkthdrPtr->ph_vlanIdx= dvid & (8 -1);
        local_vlanp = &DrvTbl.vlan[pkthdrPtr->ph_vlanIdx ];

        if(peripheralExtPortMask>((1<<6)-1)){


                pkthdrPtr->ph_srcExtPortNum=
                        extPortMaskToPortNum[ (pkthdrPtr->ph_portlist>>6)&7];




                pkthdrPtr->ph_portlist=0;
        }else
                pkthdrPtr->ph_srcExtPortNum=0;
        pkthdrPtr->ph_portlist |= rtl8651_tblDrvCpuMirrorPortMask;

        rtlglue_drvSend((void*)data);

        return 0;
}
