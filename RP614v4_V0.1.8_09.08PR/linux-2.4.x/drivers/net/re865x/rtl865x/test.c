# 1 "rtl8651_tblDrvFwd.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "rtl8651_tblDrvFwd.c"
# 31 "rtl8651_tblDrvFwd.c"
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
# 32 "rtl8651_tblDrvFwd.c" 2
# 1 "rtl8651_tblDrvFwdLocal.h" 1
# 169 "rtl8651_tblDrvFwdLocal.h"
# 1 "assert.h" 1
# 170 "rtl8651_tblDrvFwdLocal.h" 2
# 1 "types.h" 1
# 171 "rtl8651_tblDrvFwdLocal.h" 2





# 1 "rtl_queue.h" 1
# 177 "rtl8651_tblDrvFwdLocal.h" 2
# 1 "rtl_errno.h" 1
# 178 "rtl8651_tblDrvFwdLocal.h" 2
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
# 179 "rtl8651_tblDrvFwdLocal.h" 2

# 1 "rtl8651_tblDrvFwd_utility.h" 1
# 181 "rtl8651_tblDrvFwdLocal.h" 2
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
# 182 "rtl8651_tblDrvFwdLocal.h" 2
# 1 "rtl8651_tblDrvLocal.h" 1
# 26 "rtl8651_tblDrvLocal.h"
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
# 33 "rtl8651_tblDrvFwd.c" 2


# 1 "rtl8651_layer2local.h" 1
# 36 "rtl8651_tblDrvFwd.c" 2
# 1 "rtl8651_dos_local.h" 1
# 76 "rtl8651_dos_local.h"
extern uint32 _rtl8651_dos_enable;
extern uint32 _rtl8651_dos_sw[2];



void _rtl8651_dos_init(rtl8651_fwdEngineInitPara_t *);
void _rtl8651_dos_Reinit(void);







int32 _rtl8651_procDoSPkt_init(rtl8651_fwdEngineInitPara_t *);
void _rtl8651_procDosPkt_reinit(void);
void _rtl8651_procDoSPkt(uint32 item, uint32 dsid, uint16 vid, struct ip*ip, uint8 direction, struct rtl_pktHdr *);
void _rtl8651_procDoSIP(uint32 item, uint32 dsid, uint16 vid, ipaddr_t ip);



int32 _rtl8651_dosProc_blockSip_check(uint16 vid, ipaddr_t sip);

void _rtl8651_dosScanTracking(struct rtl_pktHdr*pkt, struct ip *ip, uint8 l4Type, void*l4hdr);
int32 _rtl8651_dosScanCheckComplain(uint16 dsid, struct ip *ip);
int32 _rtl8651_dosScanCheckTcpOutboundFailUnusual(uint16 dsid, struct ip *ip, struct tcphdr *tc);

inline uint8 _rtl8651_dosIgnoreTypeCheck(uint8 direction);




uint32 _rtl8651_addAclRuleForSipBlock(uint16 vid, uint32 aclStart, uint32 aclEnd, int8 *enoughFlag);

void _rtl8651_dosProc_blockSip_discharge(uint32);


int32 _rtl8651_dosNaptConnCheck(uint8 isTcp, ipaddr_t ip, uint8 direction);
inline void _rtl8651_dosSrcConnCtrlUpdateConnection(uint8 isDecrease, uint8 isTcp, ipaddr_t ip);

int32 _rtl8651_connSrcTrackingRemoveByFlowtypeIp(uint8, ipaddr_t);
int32 _rtl8651_connSrcTrackingRemoveByIp(ipaddr_t);
# 37 "rtl8651_tblDrvFwd.c" 2
# 1 "rtl8651_dos.h" 1
# 170 "rtl8651_dos.h"
void rtl8651a_setDosStatus(uint32 dsid,uint32 enableItem);


void rtl8651a_setDosThreshold(uint32 dsid,uint32 type,uint32 threshold);

void rtl8651a_setPerSrcDosThreshold(uint32 dsid, uint32 type, uint32 threshold);


int32 rtl8651_dosOneSecondTimer(void);

int32 rtl8651a_dosTearDropLogging(uint32 dsid, uint16 vid, struct ip* ip, uint8 direction, struct rtl_pktHdr* pktHdr);
int32 rtl8651a_dosFragUdpBombCheck(uint32 dsid, uint16 vid, struct ip* ip, struct udphdr*ud, uint8 direction, uint32 IpTotalLen, struct rtl_pktHdr* pktHdr);
int32 rtl8651a_dosTcpCheck(uint32 dsid,uint16 vid, struct ip* ip, int32 *ret,uint8 direction,uint32 wanStatus,struct rtl_pktHdr* pktHdr, uint8 checkType);

int32 rtl8651a_dosUdpCheck(uint32 dsid,uint16 vid, struct ip* ip, int32 *ret,uint8 direction, uint32 wanStatus, struct rtl_pktHdr* pktHdr, uint8 checkType);

int32 rtl8651a_dosIcmpCheck(uint32 dsid,uint16 vid, struct ip* ip, int32 *ret,uint8 direction, uint32 wanStatus, struct rtl_pktHdr* pktHdr);

int32 rtl8651a_dosIpCheck(uint32 dsid,uint16 vid, struct ip* ip, int32 *ret,uint8 direction, uint32 wanStatus, struct rtl_pktHdr* pktHdr);




void rtl8651_dumpConnCtrl(void);



int32 rtl8651_dosScanTrackingSetPara(uint32 dsid, uint32 windowSize, uint32 threshold);



uint32 rtl8651_dosSIPBlockSw(uint32 item, uint32 dsid, uint32 *flag);
void rtl8651_dosProc_blockSip_freeAll(void);
int32 rtl8651_dosProc_blockSip_setPrisonTime(uint32 prisonTime);
void rtl8651_dosProc_blockSip_enable(uint32 dsid, uint32 enable);
# 38 "rtl8651_tblDrvFwd.c" 2
# 1 "asicRegs.h" 1
# 39 "asicRegs.h"
# 1 "rtl865xb_asicregs.h" 1
# 40 "asicRegs.h" 2
# 39 "rtl8651_tblDrvFwd.c" 2
# 1 "rtl8651_tblAsicDrv.h" 1
# 11 "rtl8651_tblAsicDrv.h"
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
# 40 "rtl8651_tblDrvFwd.c" 2






# 1 "rtl8651_dns_local.h" 1
# 17 "rtl8651_dns_local.h"
# 1 "rtl8651_dns.h" 1
# 28 "rtl8651_dns.h"
void rtl8651_dns_dnsProc_dump(void);
void rtl8651_dns_dataBase_dump(void);

int32 rtl8651_dns_setDnsTtlSuppression(uint8 enable, uint32 suppressedTtl);

int32 rtl8651_dns_registerProcess( uint8 * process,
                                                                                uint32 property,
                                                                                int32 (*init)(void *para),
                                                                                void (*reinit)(void),
                                                                                int32 (*proc)(char *orig_domain, char *domain, ipaddr_t ip, void *data),
                                                                                void (*timeUpdate)(uint32 secpassed),
                                                                                int32 (*destructor)(void *data));
int32 rtl8651_dns_addProcessEntry(uint8 process, char *domain, void *procData, void **entryPtr);
int32 rtl8651_dns_delProcessEntry(uint8 process, uint8 byDbPtr, void *db_p, char *domain, void *procData);
int32 rtl8651_dns_findProcessEntry(uint8 process, char *domain, void *procData, char **returnedDomain, void **returnedProcData, void **start);
char *rtl8651_dns_getProcessEntryDomainInfo(void *db_p);
# 18 "rtl8651_dns_local.h" 2
# 1 "rtl8651_dns_proto.h" 1
# 37 "rtl8651_dns_proto.h"
typedef struct _rtl8651_dns_dnsHeader_s {
        uint16 id;
        uint16 qr:1;
        uint16 opcode:4;
        uint16 aa:1;
        uint16 tc:1;
        uint16 rd:1;
        uint16 ra:1;
        uint16 z:3;
        uint16 rcode:4;
        uint16 qdcount;
        uint16 ancount;
        uint16 nscount;
        uint16 arcount;
} _rtl8651_dns_dnsHeader_t;
# 94 "rtl8651_dns_proto.h"
typedef struct _rtl8651_dns_dnsRR_fixedField_s {
        uint16 type;
        uint16 class;
        uint32 ttl;
        uint16 rdlength;
} _rtl8651_dns_dnsRR_fixedField_t;
# 19 "rtl8651_dns_local.h" 2
# 37 "rtl8651_dns_local.h"
typedef struct _rtl8651_dnsDB_s {
        char domain[128];
        void *procData;


        struct _rtl8651_dnsDB_s **hdr;
        struct _rtl8651_dnsDB_s *prev;
        struct _rtl8651_dnsDB_s *next;
} _rtl8651_dnsDB_t;

typedef struct _rtl8651_dnsFuncCtrl_s {
        uint32 property;
        void (*reinit)(void);
        int32 (*proc)(char *orig_domain, char *domain, ipaddr_t ip, void *data);
        void (*timeUpdate)(uint32 secpassed);
        int32 (*destructor)(void *data);
} _rtl8651_dnsFuncCtrl_t;

typedef struct _rtl8651_dnsDB_ctrl_s {
        uint8 dnsDB_unusedProcCnt;
        _rtl8651_dnsDB_t **rtl8651_inusedDB;
        _rtl8651_dnsDB_t *freeDnsDB;
        _rtl8651_dnsFuncCtrl_t *callBack;
        rtl8651_fwdEngineInitPara_t initPara;
} _rtl8651_dnsDB_ctrl_t;

typedef enum _rtl8651_dns_dnsDomain_e {
        _RTL8651_DNS_GET_TYPE_INET_IPV4 = 1,
        _RTL8651_DNS_GET_TYPE_DOMAIN
} _rtl8651_dns_dnsDomain_t;



typedef struct _rtl8651_dns_cnameMapping_s {
        char addr[128];

        uint32 updateTime;

        struct _rtl8651_dns_cnameMapping_s *hdr_prev;
        struct _rtl8651_dns_cnameMapping_s *hdr_next;
        struct _rtl8651_dns_cnameMapping_s *lru_prev;
        struct _rtl8651_dns_cnameMapping_s *lru_next;
        struct _rtl8651_dns_cnameMapping_s *prev;
        struct _rtl8651_dns_cnameMapping_s *next;
} _rtl8651_dns_cnameMapping_t;






int32 _rtl8651_dns_init(rtl8651_fwdEngineInitPara_t *para);
void _rtl8651_dns_reinit(void);
int32 _rtl8651_dns_procDnsPkt(int32 ruleNo, struct rtl_pktHdr *pktHdr, struct ip *pip, void *usrDefined);


void _rtl8651_dns_timeUpdate(uint32 secPassed);
uint32 _rtl8651_tryToAddAclRuleForDns(uint32 aclStart, uint32 aclEnd, int8 *enoughFlag);


int32 _rtl8651_dns_registerProcess( uint8 * process,
                                                                                uint32 property,
                                                                                int32 (*init)(void *para),
                                                                                void (*reinit)(void),
                                                                                int32 (*proc)(char *orig_domain, char *domain, ipaddr_t ip, void *data),
                                                                                void (*timeUpdate)(uint32 secpassed),
                                                                                int32 (*destructor)(void *data));

int32 _rtl8651_dns_addProcessEntry(uint8 process, char *domain, void *procData, void **entryPtr);
int32 _rtl8651_dns_delProcessEntry(uint8 process, uint8 byDbPtr, void *db_p, char *domain, void *procData);
int32 _rtl8651_dns_findProcessEntry(uint8 process, char *domain, void *procData, char **returnedDomain, void **returnedProcData, void **start);
char *_rtl8651_dns_getProcessEntryDomainInfo(void *db_p);
# 47 "rtl8651_tblDrvFwd.c" 2
# 1 "rtl8651_dns_domainBlock_local.h" 1
# 18 "rtl8651_dns_domainBlock_local.h"
# 1 "rtl8651_dns_domainBlock.h" 1
# 19 "rtl8651_dns_domainBlock.h"
typedef struct rtl8651_domainBlockingInfo_s {
        ipaddr_t sip;
        ipaddr_t sipMask;
} rtl8651_domainBlockingInfo_t;





void rtl8651_domainBlocking_dump(void);
int32 rtl8651_domainBlocking_addDomainBlockingEntry(char *domain_name, rtl8651_domainBlockingInfo_t *usrInfo);
int32 rtl8651_domainBlocking_delDomainBlockingEntry(char *domain_name, rtl8651_domainBlockingInfo_t *usrInfo);
int32 rtl8651_domainBlocking_flushDomainBlockingEntry(void);
# 19 "rtl8651_dns_domainBlock_local.h" 2
# 28 "rtl8651_dns_domainBlock_local.h"
typedef struct _rtl8651_domainBlockingInfo_s {
        rtl8651_domainBlockingInfo_t info;

        void *ctrlEntry;
        struct _rtl8651_domainBlockingInfo_s *prev;
        struct _rtl8651_domainBlockingInfo_s *next;
} _rtl8651_domainBlockingInfo_t;


typedef struct _rtl8651_domainBlockingBlockList_s {
        _rtl8651_domainBlockingInfo_t *info;
        uint32 updateTime;
        ipaddr_t dip;

        struct _rtl8651_domainBlockingBlockList_s *prev;
        struct _rtl8651_domainBlockingBlockList_s *next;
} _rtl8651_domainBlockingBlockList_t;







int32 _rtl8651_registerDomainBlock(void);


int32 _rtl8651_domainBlocking_init(void *para);
void _rtl8651_domainBlocking_flushBlockList(void);
int32 _rtl8651_domainBlocking_procMapping(char *orig_domain, char *mapped_domain, ipaddr_t mapped_ip, void *info);
void _rtl8651_domainBlocking_timeUpdate(uint32 secPassed);
int32 _rtl8651_domainBlocking_blockInfoDestructor(void *info);


uint32 _rtl8651_tryToAddAclRuleForDnsDomainBlocking(rtl8651_tblDrv_vlanTable_t *vlanPtr, uint32 aclStart, uint32 aclEnd, int8 *enoughFlag);


int32 _rtl8651_domainBlocking_addDomainBlockingEntry(char *domain_name, rtl8651_domainBlockingInfo_t *usrInfo);
int32 _rtl8651_domainBlocking_delDomainBlockingEntry(char *domain_name, rtl8651_domainBlockingInfo_t *usrInfo);
int32 _rtl8651_domainBlocking_flushDomainBlockingEntry(void);
# 48 "rtl8651_tblDrvFwd.c" 2
# 67 "rtl8651_tblDrvFwd.c"
int8 rtl8651_tblDrvFwd_Id[] = "$Id: rtl8651_tblDrvFwd.c,v 1.364 2005/12/12 03:19:44 tony Exp $";
rtl8651_tblDrvFwdEngineCounts_t rtl8651_fwdEngineCounter;
rtl8651_fwdEngineInitPara_t rtl8651_fwdEnginePara;
int8 rtl8651_drvPacketFastSend = 0;
static int8 _dropCases[140];
static int32 (*rtl8651_pppoeInput)(struct rtl_mBuf *);
extern int32 *rtl8651_wanStatus;



static int8 rtl8651_drvIcmpReplyEnable = 0;
static int8 rtl8651_PPPoEEnable = 0;
static int8 rtl8651_drvRoutingEnable = 1;
int8 rtl8651_drvIcmpRoutingMsgEnable = 1;
static int8 rtl8651_drvIcmpAlwaysReplyErrForFrag = 0;
static int8 rtl8651_DMZHostIcmpPassthroughEnable = 0;
static int8 rtl8651_drvArpProcessEnable = 0;
static int8 rtl8651_drvArpProxyProcessEnable = 0;
static int8 rtl8651_drvProcessUpnpPortBouncing = 0;
static int8 rtl8651_drvFwdOtherL4ToDMZEnable = 0;
static int8 rtl8651_drvFwdUnicastIGMPEnable = 0;
int8 rtl8651_drvSoftwareBroadcastEnable[8] = {0};
static int8 rtl8651_drvEnPortBouncingPSaction = 1;
static int8 rtl8651_drvPktDemandRouteTrigger = 1;
static int8 rtl8651_drvProtocolStackDontTimeout = 0;
static int8 rtl8651_drvProtocolStackErrMsgDontTimeout = 1;

static int8 rtl8651_drvDynamicRPPolicyRoute = 0;



static int8 rtl8651_drvInexactUdpNaptEnable = 0;
static int8 rtl8651_drvStaticUdpNaptPortTranslation = 0;
static int8 rtl8651_drvStaticTcpNaptPortTranslation = 0;


static int8 rtl8651_drvWeakTcpNaptEnable = 0;



int8 rtl8651_drvMulticastProcessEnable = 1;
static uint8 IP_MULTICAST_SYSTEM_ENABLE = 1;


static int8 rtl8651_drvFragmentProcessEnable = 1;
static uint8 IP_QUEUE_SYSTEM_ENABLE = 1;







static uint32 _rtl8651_max_fragCache_count = 32;
static uint32 _rtl8651_max_fragCache_age = 5;
static struct _rtl8651_frag * _rtl8651_fragCache[8];

static uint32 _rtl8651_fragCacheInit(void);
static void _rtl8651_fragCacheReinit(void);
static inline uint32 _rtl8651_getFragCache(int32 FlowType, ipaddr_t org_sip, ipaddr_t org_dip, uint16 ip_id, ipaddr_t *newIp, int8 *routeIdx, rtl8651_tblDrv_naptTcpUdpFlowEntry_t **naptEntryp, uint8* dsid);
static inline _rtl8651_frag_t *_rtl8651_getFragCacheEntry(int32 FlowType, ipaddr_t org_sip, ipaddr_t org_dip, uint16 ip_id);
static inline void _rtl8651_updateFragCache(int32 FlowType, ipaddr_t org_sip, ipaddr_t org_dip, uint16 ip_id, ipaddr_t ip_addr, int8 routeIdx, rtl8651_tblDrv_naptTcpUdpFlowEntry_t *naptEntry, uint8 dsid);
void _rtl8651_fragCache_timeUpdate(uint32 secPassed);




uint8 _rtl8651_fragQueueProcess = 0;
uint8 _rtl8651_fragQueueDropChain = 0;



ipaddr_t _rtl8651_fragQueueNaptRedirect_MatchedIP = 0;

uint8 _rtl8651_fragQueueProcessOk = 0;
uint16 *_rtl8651_udpSizeThreshValue;
uint8 _rtl8651_udpBlockingEnable = 0;





_rtl8651_FragmentShortestPathFwdCache_t fragmentShortestPathCache[32];

static inline void _rtl8651_fragmentShortestPathCacheSet_firstHalf(struct rtl_pktHdr *pkthdr, uint8 *l4hdr, struct ip *pip, ipaddr_t sip, ipaddr_t dip, uint32 mode, ipaddr_t aliasIp);
static inline void _rtl8651_fragmentShortestPathCache_clear(struct rtl_pktHdr *pkthdr, struct ip*pip);
static void _rtl8651_fragmentShortestPathCache_timeUpdate(uint32 passed);
static inline int32 _rtl8651_fragmentShortestPathFwd(struct rtl_pktHdr*pkthdr, struct ip *pip);
# 164 "rtl8651_tblDrvFwd.c"
__attribute__ ((section(".dram-l34-fwd"))) static uint32 *_ageTimer[8 +1];
static uint32 *__ageTimer[8 +1] ={



        ((void *)0),
        ((void *)0),
        &rtl8651GlobalControl.tcpFastTimeout,
        &rtl8651GlobalControl.tcpFastTimeout,
        ((void *)0),
         &rtl8651GlobalControl.tcpLongTimeout,
         &rtl8651GlobalControl.tcpMediumTimeout,
         &rtl8651GlobalControl.tcpMediumTimeout,
         &rtl8651GlobalControl.tcpFinTimeout
};


__attribute__ ((section(".dram-l34-fwd"))) static int8 _inNextState[2][8];
static int8 __inNextState[2][8]={




        { 3, 5, 0, -1, 0,0,0,3 },

        { 0, 7,7,-1,7,8,0,0}
};


__attribute__ ((section(".dram-l34-fwd"))) static int8 _outNextState[2][8];
static int8 __outNextState[2][8]={




        { 2, 0, 5, -1, 0,0,0,2 },

        { 6, 6,6,-1,6,0, 8,0}
};





static struct _RTL8651_UPNP_ENTRY *upnp_tb;

static void _rtl8651_initUpnpDb(void);
static void _rtl8651_ReinitUpnpDb(void);
static inline int32 _rtl8651_findInboundUpnpMapping( uint32 isTcp,
                                                                                                                ipaddr_t remote_ip, uint16 remote_port,
                                                                                                                ipaddr_t alias_ip, uint16 alias_port,
                                                                                                                ipaddr_t *local_ip, uint16 *local_port,
                                                                                                                uint32 *flags, uint32 *algIdx);
static inline int32 _rtl8651_findOutboundUpnpMapping( uint32 isTcp,
                                                                                                                ipaddr_t IntIp, uint16 IntPort,
                                                                                                                ipaddr_t *ExtIp, uint16 *ExtPort,
                                                                                                                ipaddr_t RemoteIp, uint16 RemotePort,
                                                                                                                uint32 *flags, uint32 *algIdx);

static inline int32 _rtl8651_checkUsableUpnpEntry( uint32 isTcp,
                                                                                                        ipaddr_t IntIp, uint32 IntPort,
                                                                                                        ipaddr_t ExtIp, uint32 ExtPort,
                                                                                                        ipaddr_t RemoteIp, uint32 RemotePort);
# 238 "rtl8651_tblDrvFwd.c"
static uint32 triggerPort_entry_cnt = 0;
static _rtl8651_triggerPort_entry_t *triggerPort_entry_tbl = ((void *)0);
static _rtl8651_triggerPort_entry_t *triggerPort_entry_freeList = ((void *)0);
static _rtl8651_triggerPort_entry_t *triggerPort_entry_Hdr[2] = {((void *)0)};

static uint32 triggerPort_cache_cnt = 0;
static _rtl8651_triggerPort_cache_t *triggerPort_cache_tbl = ((void *)0);
static _rtl8651_triggerPort_cache_t *triggerPort_cache_freeList = ((void *)0);
static _rtl8651_triggerPort_cache_t *triggerPort_cache_lruHdr = ((void *)0);
static _rtl8651_triggerPort_cache_t *triggerPort_cache_lruTail = ((void *)0);

__attribute__ ((section(".dram-l34-fwd"))) static _rtl8651_triggerPort_cache_t *triggerPort_cache_hashTbl[8];



static _rtl8651_triggerPort_cache_t *triggerPort_cache_staticEntry = ((void *)0);

static int32 _rtl8651_TriggerPortInit(rtl8651_fwdEngineInitPara_t *para);
static void _rtl8651_TriggerPortReinit(void);

static void _rtl8651_flushNetTriggerPortRules(uint32 netIntfId);
static int32 _rtl8651_addTriggerPortRule(uint32 netIntfId, uint8 inType, uint16 inPortStart, uint16 inPortEnd, _rtl8651_triggerPort_param_t *mappingInfo);

static inline void _rtl8651_TriggerPort_FreeCache(uint8 isStatic, _rtl8651_triggerPort_cache_t *cache);
static inline void _rtl8651_TriggerPort_FreeEntry(_rtl8651_triggerPort_entry_t *entry);

static inline _rtl8651_triggerPort_cache_t * _rtl8651_TriggerPort_getCache(void);

static inline _rtl8651_triggerPort_cache_t *_rtl8651_getTriggerPortCache(uint8 refreshAge, uint8 isTcp, uint32 netIntfId, ipaddr_t extIp, uint16 extPort);
static inline void _rtl8651_addTriggerPortCache(_rtl8651_triggerPort_entry_t *entry, ipaddr_t extIp, ipaddr_t localIpAddr);

static inline int32 _rtl8651_tryActiveTriggerPort(uint8 isTcp, uint32 netIntfId, uint16 outPort, ipaddr_t extIp, ipaddr_t localIpAddr);
static inline int32 _rtl8651_getTriggeredIpAddr(uint8 isTcp, uint32 netIntfId, ipaddr_t extIp, uint16 inPort, ipaddr_t *localIpAddrp);

static inline int32 _rtl8651_checkUsableTriggeredPortEntry(uint32 isTcp, uint32 netIntfId, ipaddr_t intIp, uint32 extPort);

static void _rtl8651_TriggerPortTimeUpdate(uint32 secPassed);






static struct _RTL8651_PORT_BOUNCING_ENTRY *portBouncingTable;
void _rtl8651_flushPortBouncingEntry(void);
static struct _RTL8651_PORT_BOUNCING_ENTRY * _rtl8651_addPortBouncingEntry(uint8 flowType,ipaddr_t cip,uint16 cport,ipaddr_t gip,uint16 gport,ipaddr_t sip,uint16 sport, uint16 id, uint32 tcpFlag, uint16 age);
void _rtl8651_portBouncingTimeUpdate(uint32 secPassed);
static int32 _rtl8651_l34PortBouncingIcmpErrMsg(struct rtl_pktHdr *, struct ip *, struct icmp *);
static inline int32 _rtl8651_l4NaptPortBouncing(struct rtl_pktHdr*, struct ip*);
static inline int32 _rtl8651_l4NatPortBouncing(struct rtl_pktHdr*, struct ip*);
static inline uint32 _rtl8651_portBouncingTcpMonitor(struct tcphdr *, uint32 *, int8);




int32 rtl8651_mss=1460;
uint16 pppoe_mss[8]={1452,1452,1452,1452,1452,1452,1452,1452};




rtl8651_PS_Action_Entry_t *rtl8651_ProtoStackActions;

static int32 _rtl8651_doProtoStackAction(struct rtl_pktHdr *pktHdr, struct ip *iph);
static void _rtl8651_aliasProtoStackSentPkt(uint32 outbound, uint32 dsid, struct ip *ip);
static void _rtl8651_aliasProtoStackSentIcmpErr(struct ip *ip);
static int32 _rtl8651_aliasProtoStackRecvPkt(struct rtl_pktHdr *pktHdr, uint32 fromOutbound, struct ip *ip);
static inline int32 _rtl8651_protoStackAction_filter(struct rtl_pktHdr* pktHdr, rtl8651_tblDrv_vlanTable_t *svlan, struct ip *pip);
static inline rtl8651_PS_Action_Entry_t *_rtl8651_checkProtoStackRegistedPort(uint16 port, uint8 l4proto);





__attribute__ ((section(".dram-l34-fwd"))) static uint8 _RTL8651_PROC[_RTL8651_HOST_MAX][_RTL8651_HOST_MAX];
static uint8 __RTL8651_PROC[_RTL8651_HOST_MAX][_RTL8651_HOST_MAX] = {




                        { _RTL8651_DEC_RT_NPNP, _RTL8651_DEC_RT_NPN, _RTL8651_DEC_RT_NPL, _RTL8651_DEC_NPT, _RTL8651_DEC_NPTBC_NP, _RTL8651_DEC_NTBC_NP},
                        { _RTL8651_DEC_RT_NNP, _RTL8651_DEC_RT_NN, _RTL8651_DEC_RT_NL, _RTL8651_DEC_NT, _RTL8651_DEC_NPTBC_N, _RTL8651_DEC_NTBC_N},
                        { _RTL8651_DEC_RT_LNP, _RTL8651_DEC_RT_LN, _RTL8651_DEC_RT_LL, _RTL8651_DEC_RT_LR, _RTL8651_DEC_NPTBC_L, _RTL8651_DEC_NTBC_L},
                        {_RTL8651_DEC_DP, _RTL8651_DEC_DP, _RTL8651_DEC_RT_RL, _RTL8651_DEC_RT_RR, _RTL8651_DEC_NPTR, _RTL8651_DEC_NTR},
                        {_RTL8651_DEC_DP, _RTL8651_DEC_DP, _RTL8651_DEC_DP, _RTL8651_DEC_DP, _RTL8651_DEC_DP, _RTL8651_DEC_DP},
                        {_RTL8651_DEC_DP, _RTL8651_DEC_DP, _RTL8651_DEC_DP, _RTL8651_DEC_DP, _RTL8651_DEC_DP, _RTL8651_DEC_DP}
};





__attribute__ ((section(".dram-l34-fwd"))) static uint8 _RTL8651_ADDITIONAL_PROC[_RTL8651_DEC_MAX];
static uint8 __RTL8651_ADDITIONAL_PROC[_RTL8651_DEC_MAX] = {0};




static void _rtl8651_l34AdditionalExec_init(void);
static inline int32 _rtl8651_l34AddtionalExec(int32 decision, ipaddr_t dip, void *pkt);




_rtl8651_trapping_dispatch_entry_t *rtl8651_trappingDispatchSystem_inUsed;
_rtl8651_trapping_dispatch_entry_t *rtl8651_trappingDispatchSystem_freeHdr;

_rtl8651_trapping_dispatch_cache_t rtl8651_trappingDispatchSystem_cache;

static int32 _rtl8651_trappingDispatchInit(rtl8651_fwdEngineInitPara_t *para);
static void _rtl8651_trappingDispatchReinit(void);
static _rtl8651_trapping_dispatch_entry_t *_rtl8651_findTrappingDispatchEntry(uint8 l4Proto, ipaddr_t srcIp, ipaddr_t dstIp, int32 srcPort, int32 dstPort, uint8 isExactlyMatch);
static int32 _rtl8651_registerTrappingDispatchEntry(uint8 l4Proto, ipaddr_t srcIp, ipaddr_t dstIp, int32 srcPort, int32 dstPort, uint16 category);
static void _rtl8651_removeTrappingDispatchEntry(_rtl8651_trapping_dispatch_entry_t *delEntry);
static int32 _rtl8651_unregisterTrappingDispatchEntry(uint8 l4Proto, ipaddr_t srcIp, ipaddr_t dstIp, int32 srcPort, int32 dstPort);
static uint16 _rtl8651_getTrappingDispatchCategory(struct ip * pip);







uint8 rtl8651_returnValue[(140 + 3)];
void _rtl8651_fwdEngineRetValueStatisticInit(void);
void _rtl8651_fwdEngineRetValueStatisticReset(void);
void _rtl8651_fwdEngineRetValueStatisticUpdate(int32);
int32 _rtl8651_fwdEngineRetValueStaticDump(void);



static _rtl8651_pppoeActiveSession_entry_t * pppoeActiveSessionHead, * pppoeFreeActiveSession;
int8 rtl8651_drvPppoeNotExistedSessionTerminationEnable = 0;
void _rtl8651_freeAllPppoeActiveSession(void);
void _rtl8651_updatePppoeActiveSession(uint16 pppoeSessionId);
void _rtl8651_terminatePppoeActiveSession(uint16 pppoeSessionId);
int32 inline _rtl8651_pppoeSessionActive(uint16 pppoeSessionId);
uint16 * _rtl8651_getNextPppoeActiveSession(uint16 *curPppoeSessionId, uint16 * nextPppoeSessionId);



static inline int32 _rtl8651_l4SeqDiff(uint32 x, uint32 y);
static int32 _rtl8651_l4GetDeltaAckIn(struct ip * pip, struct tcphdr *tc, rtl8651_tblDrv_naptTcpUdpFlowEntry_t* tb);



static int32 _rtl8651_pktAccessGateway (ipaddr_t srcIpAddr, ipaddr_t dstIpAddr, uint16 vid);
static int32 _rtl8651_l2Relay(struct rtl_mBuf *arpMbufPtr);
static int32 _rtl8651_drvArpAgent(struct rtl_pktHdr *pkthdrPtr, struct rtl_mBuf *mbufPtr, uint16 vid);
static int32 _rtl8651_l3ActRouting(struct rtl_pktHdr * pkthdrPtr, ipaddr_t dst_ip, struct ip *ip);

static inline void _rtl8651_l34Decision(struct rtl_pktHdr *pkthdr, rtl8651_tblDrv_vlanTable_t *vlanp, uint32 *decision_p, uint32 *srcType_p, uint32 *dstType_p, uint32 *optLayer_p);
static inline int32 _rtl8651_l34PacketProcess(struct rtl_pktHdr *pkthdr, struct ip *pip, uint32 decision);
static inline int32 _rtl8651_l34ActExec(struct rtl_pktHdr *, struct ip* ,uint8, int32);
static inline int32 _rtl8651_l4napt_process(struct rtl_pktHdr *,struct ip *ip, uint8, int32);
static inline int32 _rtl8651_l4nat_in_process(struct rtl_pktHdr *, struct ip*);
static inline int32 _rtl8651_l4nat_out_process(struct rtl_pktHdr *, struct ip*);


static inline int32 _rtl8651_l4TcpFastAliasOut(struct rtl_pktHdr *, struct ip *pip);
static inline int32 _rtl8651_l4TcpFastAliasIn(struct rtl_pktHdr *, struct ip *pip);
static inline int32 _rtl8651_l4UdpFastAliasIn(struct rtl_pktHdr *, struct ip *pip);
static inline int32 _rtl8651_l4UdpFastAliasOut(struct rtl_pktHdr *, struct ip *pip);


static int8 _rtl8651_l4CheckOccupiedConnection(uint32 isTcp, uint32 dsid, ipaddr_t IntIp, uint16 IntPort, ipaddr_t ExtIp, uint16 ExtPort, ipaddr_t RemoteIp, uint16 RemotePort);
static int32 _rtl8651_inboundL4DMZForward(struct rtl_pktHdr *phdr, struct ip *ip, ipaddr_t dip);
static int32 _rtl8651_outboundL4DMZForward(struct rtl_pktHdr * phdr, struct ip * ip, ipaddr_t sip);
static inline int32 _rtl8651_l4TcpMonitorIn(struct tcphdr *, rtl8651_tblDrv_naptTcpUdpFlowEntry_t *);
static inline int32 _rtl8651_l4TcpMonitorOut(struct tcphdr *, rtl8651_tblDrv_naptTcpUdpFlowEntry_t *);
static inline int32 _rtl8651_l4IcmpNaptAliasIn1(struct rtl_pktHdr *, struct ip *,struct icmp *ic);
static inline int32 _rtl8651_l4IcmpNaptAliasIn2(struct rtl_pktHdr *, struct ip *,struct icmp *ic);
static inline int32 _rtl8651_l4IcmpNaptAliasIn3(struct rtl_pktHdr *, struct ip *,struct icmp *ic);
static inline int32 _rtl8651_L4IcmpNaptAliasIn(struct rtl_pktHdr *, struct ip *);
static inline int32 _rtl8651_l4IcmpNaptAliasOut1(struct rtl_pktHdr *, struct ip *,struct icmp *);
static inline int32 _rtl8651_l4IcmpNaptAliasOut2(struct rtl_pktHdr *, struct ip *,struct icmp *);
static inline int32 _rtl8651_l4IcmpNaptAliasOut3(struct rtl_pktHdr *, struct ip *,struct icmp *);
static inline int32 _rtl8651_l4IcmpNaptAliasOut(struct rtl_pktHdr *, struct ip *);
static inline int32 _rtl8651_l4UdpNaptAliasOut(struct rtl_pktHdr *, struct ip *);
static inline int32 _rtl8651_l4UdpNaptAliasIn(struct rtl_pktHdr *, struct ip *);
static inline int32 _rtl8651_l4TcpNaptAliasOut(struct rtl_pktHdr *, struct ip *);
static inline int32 _rtl8651_l4TcpNaptAliasIn(struct rtl_pktHdr *, struct ip *);
static inline int32 _rtl8651_drvIcmpAgent(struct rtl_pktHdr *,struct ip*, uint16);
static inline int32 _rtl8651_drvIcmp(struct rtl_pktHdr *, struct ip*, struct icmp *, uint16);
static inline int32 _rtl8651_l4NaptFlowGetDSID (uint8 fromInternal, struct rtl_pktHdr *pkthdr, struct ip *pip);

static inline int32 _rtl8651_drvPktDemandRouteTrigger(struct ip *pip);

static inline int32 _rtl8651_l4UdpNatAlgAliasOut(struct rtl_pktHdr *, struct ip *, rtl8651_tblDrv_natEntry_t *);
static inline int32 _rtl8651_l4UdpNatAlgAliasIn(struct rtl_pktHdr *, struct ip *, rtl8651_tblDrv_natEntry_t *);
static inline int32 _rtl8651_l4TcpNatAlgAliasOut(struct rtl_pktHdr *, struct ip *, rtl8651_tblDrv_natEntry_t *);
static inline int32 _rtl8651_l4TcpNatAlgAliasIn(struct rtl_pktHdr *, struct ip *, rtl8651_tblDrv_natEntry_t *);
static int32 _rtl8651_uPnPOneSecondTimer(void);
static int32 _rtl8651_queuePacketSecondTimer(void);
extern int _rtl8651_getPolicyRoutingDSID(struct rtl_pktHdr *pktHdr,uint32 ip_d,uint32 ip_s,uint8 proto,int ip_dp);


static int32 _rtl8651_fwdEngineProtocolStackSend(void * pkthdr, int16 dvid, int32 iphdrOffset, int32 highPriority);
static void _rtl8651_fwdEnginePsFlowCacheCreate(struct ip *iphdr);




struct _RTL8651_QUEUE_PACKET_ENTRY *queue_packet_tb;

static int32 _rtl8651_protoStackActionInit(rtl8651_fwdEngineInitPara_t *para);
static int32 _rtl8651_queueInit(void);
static int32 _rtl8651_queueReinit(void);
static int32 _rtl8651_enQueuePacket(struct rtl_pktHdr * , struct ip*, ipaddr_t, uint8 );
static int32 _rtl8651_queuePacketSecondTimer(void);
static struct rtl_pktHdr * _rtl8651_queryQuenePacket(struct ip*, uint8, uint32 *, struct ip** );




extern rtl8651_loggingFuncPtr_t _pUserLoggingFunc;
extern uint32 *_loggingModule;

extern uint8 *_rtl8651_acl_drop_nolog;





int32 (*rtl8651_l4GreNaptAliasIn)(struct rtl_pktHdr *, struct ip *);
int32 (*rtl8651_l4GreNaptAliasOut)(struct rtl_pktHdr *, struct ip *);

int32 (*rtl8651_l4EspNaptAliasIn)(struct rtl_pktHdr *, struct ip *);
int32 (*rtl8651_l4EspNaptAliasOut)(struct rtl_pktHdr *, struct ip *);

int32 (*rtl8651_l4RsvpNaptAliasIn)(struct rtl_pktHdr *, struct ip *);
int32 (*rtl8651_l4RsvpNaptAliasOut)(struct rtl_pktHdr *, struct ip *);
# 479 "rtl8651_tblDrvFwd.c"
static _rtl8651_naptRedirectEntry_t *_rtl8651_naptRedirectEntry_inuse = ((void *)0);
static _rtl8651_naptRedirectEntry_t *_rtl8651_naptRedirectEntry_freelist = ((void *)0);

static _rtl8651_naptRedirectFlow_t *_rtl8651_naptRedirectFlowCache_lru_head = ((void *)0);
static _rtl8651_naptRedirectFlow_t *_rtl8651_naptRedirectFlowCache_lru_tail = ((void *)0);
static _rtl8651_naptRedirectFlow_t *_rtl8651_naptRedirectFlowCache_freelist = ((void *)0);

static int32 _rtl8651_naptRedirectInit(rtl8651_fwdEngineInitPara_t *para);
static void _rtl8651_naptRedirectReinit(void);
static inline int32 _rtl8651_findNaptRedirectEntry(uint8 isTcp, ipaddr_t sip, uint16 sport, ipaddr_t dip, uint16 dport, ipaddr_t *pNewDip, uint16 *pNewDport, uint8 createCache, uint16 vlanIdx);
static _rtl8651_naptRedirectEntry_t *_rtl8651_findExistNaptRedirectEntry(uint8 isExceptionList, uint8 isTcp, ipaddr_t sip, uint16 sport, ipaddr_t originalDip, uint16 originalDport);
static inline _rtl8651_naptRedirectFlow_t *_rtl8651_findNaptRedirectFlow(uint8 isTcp, ipaddr_t sip, uint16 sport, ipaddr_t originalDip, uint16 originalDport, ipaddr_t newDip, uint16 newDport, uint8 isExternalQuery, uint8 refresh);
static inline int32 _rtl8651_addNaptRedirectFlow(uint8 isTcp, ipaddr_t sip, uint16 sport, ipaddr_t originalDip, uint16 originalDport, ipaddr_t newDip, uint16 newDport);
static void _rtl8651_naptRedirectFlowTimeUpdate(uint32 secPassed);
static int32 _rtl8651_resolveProxyInboundFlow(rtl8651_tblDrv_vlanTable_t * dvlan, struct ip * pip);
static inline int32 _rtl8651_queryRedirectOutboundNaptFlow(uint8 isTcp, ipaddr_t sip, uint16 sport, ipaddr_t *pOriginalDip, uint16 *pOriginalDport, ipaddr_t newDip, uint16 newDport);
# 505 "rtl8651_tblDrvFwd.c"
_rtl8651_pptpHdrCacheEntry_t *_rtl8651_pptpHdrCache_hashTbl[64] = {((void *)0)};
_rtl8651_pptpHdrCacheEntry_t *_rtl8651_pptpHdrCache_lru_head = ((void *)0);
_rtl8651_pptpHdrCacheEntry_t *_rtl8651_pptpHdrCache_lru_tail = ((void *)0);
_rtl8651_pptpHdrCacheEntry_t *_rtl8651_pptpHdrCache_unused = ((void *)0);

static int32 _rtl8651_pptpHdrCacheInit(rtl8651_fwdEngineInitPara_t *para);
static void _rtl8651_pptpHdrCacheReinit(void);
static void _rtl8651_pptpHdrCache_Del(_rtl8651_pptpHdrCacheEntry_t* ptr);
static inline int32 _rtl8651_pptpHdrCache_Find(uint16 ip_id, uint16 ip_off, uint32 *pSeq, uint32 *pAck, uint8 *pType);
static inline int32 _rtl8651_refillHeader(int32 result, struct rtl_pktHdr *pkthdr, struct ip*pip, rtl8651_tblDrv_vlanTable_t *svlan, uint16 srcPortList);







static int32 _rtl8651_initFwdEngineParam(rtl8651_fwdEngineInitPara_t *configPara)
{

        memset(&rtl8651_fwdEnginePara, 0, sizeof(rtl8651_fwdEngineInitPara_t));

        {

                rtl8651_fwdEnginePara.MaxFragPktCnt =
                        (configPara && configPara->MaxFragPktCnt != 0xffffffff)?
                        configPara->MaxFragPktCnt:10;
                rtl8651_fwdEnginePara.MaxFragSubPktCnt =
                        (configPara && configPara->MaxFragSubPktCnt != 0xffffffff)?
                        configPara->MaxFragSubPktCnt:12;
                rtl8651_fwdEnginePara.MaxNegativeListEntryCnt =
                        (configPara && configPara->MaxNegativeListEntryCnt != 0xffffffff)?
                        configPara->MaxNegativeListEntryCnt:20;
                rtl8651_fwdEnginePara.MaxPositiveListEntryCnt =
                        (configPara && configPara->MaxPositiveListEntryCnt != 0xffffffff)?
                        configPara->MaxPositiveListEntryCnt:60;
                rtl8651_fwdEnginePara.MaxFragPoolCnt =
                        (configPara && configPara->MaxFragPoolCnt != 0xffffffff)?
                        configPara->MaxFragPoolCnt:60;
                rtl8651_fwdEnginePara.MaxFragTimeOut =
                        (configPara && configPara->MaxFragTimeOut != 0xffffffff)?
                        configPara->MaxFragTimeOut:3;
                rtl8651_fwdEnginePara.MaxNegativeListTimeOut =
                        (configPara && configPara->MaxNegativeListTimeOut != 0xffffffff)?
                        configPara->MaxNegativeListTimeOut:1;


                rtl8651_fwdEnginePara.MCastDefaultVersion =
                        (configPara && configPara->MCastDefaultVersion != 0xffffffff)?
                        configPara->MCastDefaultVersion: 3;
                rtl8651_fwdEnginePara.MCastProcessOption =
                        (configPara && configPara->MCastProcessOption != 0xffffffff)?
                        configPara->MCastProcessOption:0;
                rtl8651_fwdEnginePara.MaxMCastCnt =
                        (configPara && configPara->MaxMCastCnt != 0xffffffff)?
                        configPara->MaxMCastCnt:20;
                rtl8651_fwdEnginePara.MaxMCastMemberCnt =
                        (configPara && configPara->MaxMCastMemberCnt != 0xffffffff)?
                        configPara->MaxMCastMemberCnt:6;
                rtl8651_fwdEnginePara.MaxMCastTotalMemberCnt =
                        (configPara && configPara->MaxMCastTotalMemberCnt != 0xffffffff)?
                        configPara->MaxMCastTotalMemberCnt:120;
                rtl8651_fwdEnginePara.MaxMCastTotalSourceCnt =
                        (configPara && configPara->MaxMCastTotalSourceCnt != 0xffffffff)?
                        configPara->MaxMCastTotalSourceCnt:200;
                rtl8651_fwdEnginePara.MCastMember_ExpireTime =
                        (configPara && configPara->MCastMember_ExpireTime != 0xffffffff)?
                        configPara->MCastMember_ExpireTime:180;
                rtl8651_fwdEnginePara.MCastUpstream_Timeout =
                        (configPara && configPara->MCastUpstream_Timeout != 0xffffffff)?
                        configPara->MCastUpstream_Timeout:125;
                rtl8651_fwdEnginePara.MCastFilterEntryCnt =
                        (configPara && configPara->MCastFilterEntryCnt != 0xffffffff)?
                        configPara->MCastFilterEntryCnt:32;
                rtl8651_fwdEnginePara.igmp_qi =
                        (configPara && configPara->igmp_qi != 0xffffffff)?
                        configPara->igmp_qi:125;
                rtl8651_fwdEnginePara.igmp_qri =
                        (configPara && configPara->igmp_qri != 0xffffffff)?
                        configPara->igmp_qri: 10;
                rtl8651_fwdEnginePara.igmp_oqpi =
                        (configPara && configPara->igmp_oqpi != 0xffffffff)?
                        configPara->igmp_oqpi:255;
                rtl8651_fwdEnginePara.igmp_sqc =
                        (configPara && configPara->igmp_sqc != 0xffffffff)?
                        configPara->igmp_sqc:3;
                rtl8651_fwdEnginePara.igmp_sqi =
                        (configPara && configPara->igmp_sqi != 0xffffffff)?
                        configPara->igmp_sqi:25;
                rtl8651_fwdEnginePara.igmp_lmqc =
                        (configPara && configPara->igmp_lmqc != 0xffffffff)?
                        configPara->igmp_lmqc:2;
                rtl8651_fwdEnginePara.igmp_lmqi =
                        (configPara && configPara->igmp_lmqi != 0xffffffff)?
                        configPara->igmp_lmqi: 5;
                rtl8651_fwdEnginePara.igmp_gmi =
                        (configPara && configPara->igmp_gmi != 0xffffffff)?
                        configPara->igmp_gmi:135;
                rtl8651_fwdEnginePara.igmp_group_query_interval =
                        (configPara && configPara->igmp_group_query_interval != 0xffffffff)?
                        configPara->igmp_group_query_interval:125;
                rtl8651_fwdEnginePara.igmp_response_tolerance_delay =
                        (configPara && configPara->igmp_response_tolerance_delay != 0xffffffff)?
                        configPara->igmp_response_tolerance_delay: 5;


                rtl8651_fwdEnginePara.dos_SynFlood_trackCnt =
                        (configPara && configPara->dos_SynFlood_trackCnt != 0xffffffff)?
                        configPara->dos_SynFlood_trackCnt:30;
                rtl8651_fwdEnginePara.dos_StealthFin_trackCnt =
                        (configPara && configPara->dos_StealthFin_trackCnt != 0xffffffff)?
                        configPara->dos_StealthFin_trackCnt:30;
                rtl8651_fwdEnginePara.dos_UdpFlood_trackCnt =
                        (configPara && configPara->dos_UdpFlood_trackCnt != 0xffffffff)?
                        configPara->dos_UdpFlood_trackCnt:40;
                rtl8651_fwdEnginePara.dos_IcmpFlood_trackCnt =
                        (configPara && configPara->dos_IcmpFlood_trackCnt != 0xffffffff)?
                        configPara->dos_IcmpFlood_trackCnt:20;
                rtl8651_fwdEnginePara.dos_total_trackCnt =
                        (configPara && configPara->dos_total_trackCnt != 0xffffffff)?
                        configPara->dos_total_trackCnt:120;
                rtl8651_fwdEnginePara.dos_total_portScan_trackCnt =
                        (configPara && configPara->dos_total_portScan_trackCnt != 0xffffffff)?
                        configPara->dos_total_portScan_trackCnt:32;
                rtl8651_fwdEnginePara.dos_TcpConn_trackCnt =
                        (configPara && configPara->dos_TcpConn_trackCnt != 0xffffffff)?
                        configPara->dos_TcpConn_trackCnt:60;
                rtl8651_fwdEnginePara.dos_UdpConn_trackCnt =
                        (configPara && configPara->dos_UdpConn_trackCnt != 0xffffffff)?
                        configPara->dos_UdpConn_trackCnt:60;
                rtl8651_fwdEnginePara.dos_totalConn_trackCnt =
                        (configPara && configPara->dos_totalConn_trackCnt != 0xffffffff)?
                        configPara->dos_totalConn_trackCnt:120;



                rtl8651_fwdEnginePara.dosProc_sipblock_count =
                        (configPara && configPara->dosProc_sipblock_count != 0xffffffff)?
                        configPara->dosProc_sipblock_count:30;


                rtl8651_fwdEnginePara.pppoeActiveSessionTrackingNumber =
                        (configPara && configPara->pppoeActiveSessionTrackingNumber != 0xffffffff)?
                        configPara->pppoeActiveSessionTrackingNumber:4;


                rtl8651_fwdEnginePara.mbufHeadroom =
                        (configPara && configPara->mbufHeadroom != 0xffffffff)?
                        configPara->mbufHeadroom:(0x80);


                rtl8651_fwdEnginePara.protoStackMaxActions =
                        (configPara && configPara->protoStackMaxActions != 0xffffffff)?
                        configPara->protoStackMaxActions:16;



                rtl8651_fwdEnginePara.redirectTblSize =
                        (configPara && configPara->redirectTblSize != 0xffffffff)?
                        configPara->redirectTblSize:16;
                rtl8651_fwdEnginePara.redirectFlowCacheSize =
                        (configPara && configPara->redirectFlowCacheSize != 0xffffffff)?
                        configPara->redirectFlowCacheSize:32;




                rtl8651_fwdEnginePara.pptpHdrCacheSize =
                (configPara && configPara->pptpHdrCacheSize != 0xffffffff)?
                configPara->pptpHdrCacheSize:192;



                rtl8651_fwdEnginePara.trappingPktDispatchTblSize =
                (configPara && configPara->trappingPktDispatchTblSize != 0xffffffff)?
                configPara->trappingPktDispatchTblSize:128;


                rtl8651_fwdEnginePara.dns_dnsDB_processCnt =
                (configPara && configPara->dns_dnsDB_processCnt != 0xffffffff)?
                configPara->dns_dnsDB_processCnt:1;
                rtl8651_fwdEnginePara.dns_dnsDB_tblSize =
                (configPara && configPara->dns_dnsDB_tblSize != 0xffffffff)?
                configPara->dns_dnsDB_tblSize:24;
                rtl8651_fwdEnginePara.dns_dnsDB_cnameMapTblSize =
                (configPara && configPara->dns_dnsDB_cnameMapTblSize != 0xffffffff)?
                configPara->dns_dnsDB_cnameMapTblSize:16;
                rtl8651_fwdEnginePara.dns_dnsDB_cnameMapTimeout =
                (configPara && configPara->dns_dnsDB_cnameMapTimeout != 0xffffffff)?
                configPara->dns_dnsDB_cnameMapTimeout:6400;

                rtl8651_fwdEnginePara.domainBlock_tblSize =
                (configPara && configPara->domainBlock_tblSize != 0xffffffff)?
                configPara->domainBlock_tblSize:24;
                rtl8651_fwdEnginePara.domainBlock_maxBlockEntryCnt =
                (configPara && configPara->domainBlock_maxBlockEntryCnt != 0xffffffff)?
                configPara->domainBlock_maxBlockEntryCnt:12;
                rtl8651_fwdEnginePara.domainBlock_blockEntryTimeout =
                (configPara && configPara->domainBlock_blockEntryTimeout != 0xffffffff)?
                configPara->domainBlock_blockEntryTimeout:3600;


                rtl8651_fwdEnginePara.triggerPortEntryCnt =
                (configPara && configPara->triggerPortEntryCnt != 0xffffffff)?
                configPara->triggerPortEntryCnt:64;
                rtl8651_fwdEnginePara.triggerPortCacheSize =
                (configPara && configPara->triggerPortCacheSize != 0xffffffff)?
                configPara->triggerPortCacheSize:128;


        }




        if ((!rtl8651_fwdEnginePara.MaxFragPktCnt) ||
                ((!rtl8651_fwdEnginePara.MaxFragSubPktCnt) && (!rtl8651_fwdEnginePara.MaxFragPoolCnt)))
        {
                IP_QUEUE_SYSTEM_ENABLE = 0;
                rtl8651_drvFragmentProcessEnable = 0;

        }else
        {
                IP_QUEUE_SYSTEM_ENABLE = 1;
                rtl8651_drvFragmentProcessEnable = 1;
        }





        if ((!rtl8651_fwdEnginePara.MaxMCastCnt) ||
                ((!rtl8651_fwdEnginePara.MaxMCastMemberCnt) && (!rtl8651_fwdEnginePara.MaxMCastTotalMemberCnt)) ||
                (!rtl8651_fwdEnginePara.MaxMCastTotalSourceCnt))
        {
                IP_MULTICAST_SYSTEM_ENABLE = 0;
                rtl8651_drvMulticastProcessEnable = 0;
        }else
        {
                IP_MULTICAST_SYSTEM_ENABLE = 1;
                rtl8651_drvMulticastProcessEnable = 0;
        }

        return 0;
}


static void _rtl8651_fwdEngineDropPktCaseReset(void)
{
        int32 trueFlag = 1;

        do {} while (0);


        memset(&_dropCases[0],0, sizeof(_dropCases));


        rtl8651_fwdEngineDropPktCase(11,&trueFlag);
        rtl8651_fwdEngineDropPktCase(12,&trueFlag);
        rtl8651_fwdEngineDropPktCase(19,&trueFlag);
        rtl8651_fwdEngineDropPktCase(3,&trueFlag);
        rtl8651_fwdEngineDropPktCase(5,&trueFlag);
        rtl8651_fwdEngineDropPktCase(42,&trueFlag);
        rtl8651_fwdEngineDropPktCase(43,&trueFlag);
        rtl8651_fwdEngineDropPktCase(16,&trueFlag);
        rtl8651_fwdEngineDropPktCase(30,&trueFlag);
        rtl8651_fwdEngineDropPktCase(66,&trueFlag);
        rtl8651_fwdEngineDropPktCase(70,&trueFlag);
        rtl8651_fwdEngineDropPktCase(77,&trueFlag);
        rtl8651_fwdEngineDropPktCase(82,&trueFlag);
        rtl8651_fwdEngineDropPktCase(86,&trueFlag);
        rtl8651_fwdEngineDropPktCase(87,&trueFlag);
        rtl8651_fwdEngineDropPktCase(100,&trueFlag);
        rtl8651_fwdEngineDropPktCase(108,&trueFlag);
        rtl8651_fwdEngineDropPktCase(110,&trueFlag);
        rtl8651_fwdEngineDropPktCase(118,&trueFlag);
        rtl8651_fwdEngineDropPktCase(116,&trueFlag);

        rtl8651_fwdEngineDropPktCase(60, &trueFlag);
        rtl8651_fwdEngineDropPktCase(63, &trueFlag);
        rtl8651_fwdEngineDropPktCase(107,&trueFlag);
        rtl8651_fwdEngineDropPktCase(74,&trueFlag);
        rtl8651_fwdEngineDropPktCase(113,&trueFlag);
        rtl8651_fwdEngineDropPktCase(80,&trueFlag);

        rtl8651_fwdEngineDropPktCase(75, &trueFlag);
        rtl8651_fwdEngineDropPktCase(76, &trueFlag);
        rtl8651_fwdEngineDropPktCase(79, &trueFlag);
        rtl8651_fwdEngineDropPktCase(90,&trueFlag);
        rtl8651_fwdEngineDropPktCase(89,&trueFlag);
        rtl8651_fwdEngineDropPktCase(84,&trueFlag);
        rtl8651_fwdEngineDropPktCase(83,&trueFlag);

        rtl8651_fwdEngineDropPktCase(103,&trueFlag);
        rtl8651_fwdEngineDropPktCase(102,&trueFlag);
        rtl8651_fwdEngineDropPktCase(111,&trueFlag);
        rtl8651_fwdEngineDropPktCase(109,&trueFlag);
        rtl8651_fwdEngineDropPktCase(119,&trueFlag);
        rtl8651_fwdEngineDropPktCase(115,&trueFlag);
        rtl8651_fwdEngineDropPktCase(136,&trueFlag);
        rtl8651_fwdEngineDropPktCase(131,&trueFlag);
        rtl8651_fwdEngineDropPktCase(101,&trueFlag);


}


static void _rtl8651_dramInit(void)
{
        memcpy(_ageTimer, __ageTimer, sizeof(_ageTimer));
        memcpy(_inNextState, __inNextState, sizeof(_inNextState));
        memcpy(_outNextState, __outNextState, sizeof(_outNextState));
        memset(triggerPort_cache_hashTbl, 0, sizeof(triggerPort_cache_hashTbl));
        memcpy(_RTL8651_PROC, __RTL8651_PROC, sizeof(_RTL8651_PROC));
        memcpy(_RTL8651_ADDITIONAL_PROC, __RTL8651_ADDITIONAL_PROC, sizeof(_RTL8651_ADDITIONAL_PROC));
}
# 831 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineInit(rtl8651_fwdEngineInitPara_t * configPara)
{

        rtlglue_drvMutexLock();

        do { if((_rtl8651_initFwdEngineParam(configPara))!=0){ printk("Error >>> initialize failed at line %d!!!\n", 836); rtlglue_drvMutexUnlock(); return -1; }}while(0);


        _rtl8651_dramInit();


        rtl8651_resetFwdEngineCounter();




        rtl8651_installArpAgent(_rtl8651_drvArpAgent);


        _rtl8651_fragCacheInit();



        rtl8651_setNaptTcpUdpPortRange(32768,65535);
        _rtl8651_setl4NaptFindEmptyAsicRetry( 8 );
        rtl8651_enable4WayHash( 1 );


        _rtl8651_initUpnpDb();



        do { if((_rtl8651_TriggerPortInit(&rtl8651_fwdEnginePara))!=0){ printk("Error >>> initialize failed at line %d!!!\n", 863); rtlglue_drvMutexUnlock(); return -1; }}while(0);



        portBouncingTable = (struct _RTL8651_PORT_BOUNCING_ENTRY *)
                                rtlglue_malloc(64 * sizeof (struct _RTL8651_PORT_BOUNCING_ENTRY));
        _rtl8651_flushPortBouncingEntry();



        _rtl8651_pptpHdrCacheInit(&rtl8651_fwdEnginePara);



        _rtl8651_queueInit();



        _rtl8651_protoStackActionInit(&rtl8651_fwdEnginePara);



        _rtl8651_dos_init(&rtl8651_fwdEnginePara);




        _rtl8651_IpFragQueueInit(&rtl8651_fwdEnginePara);




        _rtl8651_multicastInit(&rtl8651_fwdEnginePara);
        _rtl8651_multicast_FilterInit(&rtl8651_fwdEnginePara);

        rtl8651_fwdEngineEnableWanRouting(1);


        memset(fragmentShortestPathCache, 0, (sizeof(_rtl8651_FragmentShortestPathFwdCache_t)*32));



        _rtl8651_naptRedirectInit(&rtl8651_fwdEnginePara);



        _rtl8651_trappingDispatchInit(&rtl8651_fwdEnginePara);


        _rtl8651_dns_init(&rtl8651_fwdEnginePara);
        _rtl8651_registerDomainBlock();


        rtl8651_bridgeEnable=0;


        {
                _rtl8651_pppoeActiveSession_entry_t * tempPtr;
                uint32 cntr = rtl8651_fwdEnginePara.pppoeActiveSessionTrackingNumber;

                pppoeActiveSessionHead = pppoeFreeActiveSession = ((void *)0);
                while(cntr--) {
                        tempPtr = (_rtl8651_pppoeActiveSession_entry_t *) rtlglue_malloc(sizeof (_rtl8651_pppoeActiveSession_entry_t));
                        tempPtr->next = pppoeFreeActiveSession;
                        pppoeFreeActiveSession = tempPtr;
                }
                rtl8651_drvPppoeNotExistedSessionTerminationEnable = 0;
        }



        rtl8651_drvWeakTcpNaptEnable = 0;



        _rtl8651_udpBlockingEnable = 0;


        rtl8651_drvIcmpAlwaysReplyErrForFrag = 0;


        rtl8651_drvFwdOtherL4ToDMZEnable = 0;


        rtl8651_drvFwdUnicastIGMPEnable = 0;


        rtl8651_drvProcessUpnpPortBouncing = 0;


        rtl8651_drvEnPortBouncingPSaction = 1;


        rtl8651_drvPktDemandRouteTrigger = 1;


        rtl8651_drvProtocolStackDontTimeout = 0;


        rtl8651_drvProtocolStackErrMsgDontTimeout = 1;


        rtl8651_drvDynamicRPPolicyRoute = 0;



        memset(&rtl8651_drvSoftwareBroadcastEnable, 0, (sizeof(int8) * 8));


        _rtl8651_fwdEngineRetValueStatisticInit();



        _rtl8651_fwdEngineDropPktCaseReset();


        _rtl8651_l34AdditionalExec_init();

        rtlglue_drvMutexUnlock();

        return 0;

}
# 994 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineReinit(void)
{

        rtlglue_drvMutexLock();


        _rtl8651_dramInit();


        rtl8651_resetFwdEngineCounter();


        _rtl8651_fragCacheReinit();



        rtl8651_setNaptTcpUdpPortRange(32768,65535);
        _rtl8651_setl4NaptFindEmptyAsicRetry( 8 );
        rtl8651_enable4WayHash( 1 );


        _rtl8651_ReinitUpnpDb();



        _rtl8651_TriggerPortReinit();



        do {} while (0);
        _rtl8651_flushPortBouncingEntry();



        _rtl8651_pptpHdrCacheReinit();



        _rtl8651_queueReinit();




        _rtl8651_dos_Reinit();



        rtl8651_IpFragQueueReinit();



        rtl8651_multicastReinit();
        rtl8651_multicast_FilterReinit();



        rtl8651_flushProtoStackActions();



        memset(fragmentShortestPathCache, 0, (sizeof(_rtl8651_FragmentShortestPathFwdCache_t)*32));



        _rtl8651_naptRedirectReinit();




        rtl8651_drvWeakTcpNaptEnable = 0;



        _rtl8651_trappingDispatchReinit();


        _rtl8651_dns_reinit();


        rtl8651_algReInit();


        {
                _rtl8651_freeAllPppoeActiveSession();
                rtl8651_drvPppoeNotExistedSessionTerminationEnable = 0;
        }

        {
                uint32 index;
                rtl8651_mss=1460;
                for(index=0; index<8; index++)
                        pppoe_mss[index] = 1452;
        }


        rtl8651_drvIcmpAlwaysReplyErrForFrag = 0;


        _rtl8651_udpBlockingEnable = 0;


        rtl8651_drvFwdOtherL4ToDMZEnable = 0;


        rtl8651_drvFwdUnicastIGMPEnable = 0;


        rtl8651_drvProcessUpnpPortBouncing = 0;


        rtl8651_drvEnPortBouncingPSaction = 1;


        rtl8651_drvPktDemandRouteTrigger = 1;


        rtl8651_drvProtocolStackDontTimeout = 0;


        rtl8651_drvProtocolStackErrMsgDontTimeout = 1;


        rtl8651_drvDynamicRPPolicyRoute = 0;


        memset(&rtl8651_drvSoftwareBroadcastEnable, 0, (sizeof(int8) * 8));


        _rtl8651_fwdEngineRetValueStatisticReset();



        _rtl8651_fwdEngineDropPktCaseReset();


        _rtl8651_l34AdditionalExec_init();

        rtlglue_drvMutexUnlock();

        return 0;
}
# 1145 "rtl8651_tblDrvFwd.c"
int32 rtl8651_getFwdEngineCounter(rtl8651_tblDrvFwdEngineCounts_t * counter)
{

        rtlglue_drvMutexLock();

        if (counter == ((void *)0))
        {
                rtlglue_drvMutexUnlock();
                return -1;
        }
        *counter = rtl8651_fwdEngineCounter;

        rtlglue_drvMutexUnlock();
        return 0;
}







int32 rtl8651_resetFwdEngineCounter(void)
{
        rtlglue_drvMutexLock();
        memset(&rtl8651_fwdEngineCounter, 0, sizeof(rtl8651_tblDrvFwdEngineCounts_t));
        rtlglue_drvMutexUnlock();
        return 0;
}
# 1188 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineDropPktCase(uint32 fwdengDropCase, int32 *flag)
{

        rtlglue_drvMutexLock();

        if (fwdengDropCase>=140)
        {
                rtlglue_drvMutexUnlock();
                return -1;
        }
        if (!flag)
        {
                rtlglue_drvMutexUnlock();
                return _dropCases[fwdengDropCase];
        }


        _dropCases[fwdengDropCase]= (*flag)? 1: 0;

        rtlglue_drvMutexUnlock();
        return 0;
}
# 1220 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineArp(int8 enable)
{
        rtlglue_drvMutexLock();
        rtl8651_drvArpProcessEnable = enable;
        rtlglue_drvMutexUnlock();
        return 0;
}
# 1236 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineIcmp(int8 enable)
{
        rtlglue_drvMutexLock();
        rtl8651_drvIcmpReplyEnable = enable;
        rtlglue_drvMutexUnlock();
        return 0;
}
# 1252 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineIcmpRoutingMsg(int8 enable)
{
        rtlglue_drvMutexLock();
        rtl8651_drvIcmpRoutingMsgEnable= enable;
        rtlglue_drvMutexUnlock();
        return 0;
}
# 1270 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineAlwaysReplyICMPErrForFragment(int8 enable)
{
        rtlglue_drvMutexLock();
        rtl8651_drvIcmpAlwaysReplyErrForFrag = enable;
        rtlglue_drvMutexUnlock();
        return 0;
}
# 1286 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineDMZHostIcmpPassThrough(int8 enable)
{
        rtlglue_drvMutexLock();
        rtl8651_DMZHostIcmpPassthroughEnable = enable;
        rtlglue_drvMutexUnlock();
        return 0;
}
# 1302 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineArpProxy(int8 enable)
{
        rtlglue_drvMutexLock();
        rtl8651_drvArpProxyProcessEnable = enable;
        rtlglue_drvMutexUnlock();
        return 0;
}
# 1318 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineProcessL34(int8 routingEnable)
{
        rtlglue_drvMutexLock();
        rtl8651_drvRoutingEnable = routingEnable;
        rtlglue_drvMutexUnlock();
        return 0;
}
# 1335 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineProcessIPFragment(int8 enable)
{
        rtlglue_drvMutexLock();
        if (IP_QUEUE_SYSTEM_ENABLE == 0)
        {
                rtl8651_drvFragmentProcessEnable = 0;
                rtlglue_drvMutexUnlock();
                return 0;
        }

        if (rtl8651_drvFragmentProcessEnable != enable)
        {
                rtl8651_IpFragQueueReinit();
                rtl8651_drvFragmentProcessEnable = enable;
        }

        rtlglue_drvMutexUnlock();
        return 0;
}
# 1365 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineProcessIPMulticast(int8 enable)
{
        rtlglue_drvMutexLock();

        if (IP_MULTICAST_SYSTEM_ENABLE == 0)
        {
                rtl8651_drvMulticastProcessEnable = 0;

                rtlglue_drvMutexUnlock();

                return 0;
        }

        if (rtl8651_drvMulticastProcessEnable != enable)
        {



                rtl8651_multicastReinit();



                rtl8651_drvMulticastProcessEnable = enable;



                rtl8651_multicastPeriodicQuery(enable);
        }

        rtlglue_drvMutexUnlock();

        return 0;
}


int32 rtl8651_fwdEnginePPPoE(int8 enable, int32 (*pppoeInput)(struct rtl_mBuf *)) {

        rtlglue_drvMutexLock();

        if (enable&&!pppoeInput)
        {
                rtlglue_drvMutexUnlock();
                return -1;
        }
        rtl8651_PPPoEEnable = enable;
        rtl8651_pppoeInput = pppoeInput;

        rtlglue_drvMutexUnlock();
        return 0;
}
# 1424 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEnginePppoeNotExistedSessionTermination(int8 enable)
{
        rtlglue_drvMutexLock();


        if (rtl8651_drvPppoeNotExistedSessionTerminationEnable == 1 && enable== 0) {
                _rtl8651_freeAllPppoeActiveSession();
                rtl8651_drvPppoeNotExistedSessionTerminationEnable = 0;
        } else
                rtl8651_drvPppoeNotExistedSessionTerminationEnable = enable;

        rtlglue_drvMutexUnlock();
        return 0;
}
# 1448 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineEnableWanRouting(int8 enable)
{
        _rtl8651_l34AdditionalExec_t param;
        uint8 newProperty;

        rtlglue_drvMutexLock();
        _rtl8651_l34AdditionalExec_getParam(_RTL8651_HOST_RP, _RTL8651_HOST_RP, &param);
        if (enable)
        {
                newProperty = (param.property &~ 0x01);
        } else
        {
                newProperty = (param.property | 0x01);
        }

        if (newProperty != param.property)
        {
                param.property = newProperty;
                _rtl8651_l34AdditionalExec_setParam(_RTL8651_HOST_RP, _RTL8651_HOST_RP, &param);
        }
        rtlglue_drvMutexUnlock();

        return 0;
}
# 1481 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineProcessPortBouncing(int8 enable)
{
        _rtl8651_l34AdditionalExec_t param;
        uint8 newProperty;
        int32 srcIdx, dstIdx;
        uint32 src[] = {_RTL8651_HOST_NPI, _RTL8651_HOST_NI, _RTL8651_HOST_LP};
        uint32 dst[] = {_RTL8651_HOST_NPE, _RTL8651_HOST_NE};

        rtlglue_drvMutexLock();

        if (enable == 0)
        {
                _rtl8651_flushPortBouncingEntry();
        }

        for (srcIdx = 0 ; srcIdx < (sizeof(src) / sizeof(uint32)) ; srcIdx ++)
        for (dstIdx = 0 ; dstIdx < (sizeof(dst) / sizeof(uint32)) ; dstIdx ++)
        {
                _rtl8651_l34AdditionalExec_getParam(src[srcIdx], dst[dstIdx], &param);
                if (enable)
                {
                        newProperty = (param.property &~ 0x01);
                } else
                {
                        newProperty = (param.property | 0x01);
                }

                if (newProperty != param.property)
                {
                        param.property = newProperty;
                        _rtl8651_l34AdditionalExec_setParam(src[srcIdx], dst[dstIdx], &param);
                }
        }

        rtlglue_drvMutexUnlock();

        return 0;
}
# 1528 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineProcessUpnpPortBouncing(int8 enable)
{
        rtlglue_drvMutexLock();
        rtl8651_drvProcessUpnpPortBouncing = enable;
        rtlglue_drvMutexUnlock();

        return 0;
}
# 1547 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineFwdGeneralL4ToDMZ(int8 enable)
{
        rtlglue_drvMutexLock();
        rtl8651_drvFwdOtherL4ToDMZEnable = enable;
        rtlglue_drvMutexUnlock();
        return 0;
}
# 1565 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineFwdUnicastIGMPPkt(int8 enable)
{
        rtlglue_drvMutexLock();
        rtl8651_drvFwdUnicastIGMPEnable = enable;
        rtlglue_drvMutexUnlock();

        return 0;
}
# 1582 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEnginePortBouncingDoProtocolStackAction(int8 enable)
{
        rtlglue_drvMutexLock();
        rtl8651_drvEnPortBouncingPSaction = enable;
        rtlglue_drvMutexUnlock();

        return 0;
}
# 1601 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineTrapPktDemandRouteTrigger(int8 enable)
{
        rtlglue_drvMutexLock();
        rtl8651_drvPktDemandRouteTrigger = enable;
        rtlglue_drvMutexUnlock();

        return 0;
}
# 1623 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineInexactUdpFlow(int8 enable)
{
        rtlglue_drvMutexLock();
        rtl8651_drvInexactUdpNaptEnable = enable;
        rtlglue_drvMutexUnlock();

        return 0;
}
# 1664 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineUdpStaticNaptPortTranslation(int8 enable)
{
        rtlglue_drvMutexLock();
        rtl8651_drvStaticUdpNaptPortTranslation = enable;
        rtlglue_drvMutexUnlock();

        return 0;
}
# 1683 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineTcpStaticNaptPortTranslation(int8 enable)
{
        rtlglue_drvMutexLock();
        rtl8651_drvStaticTcpNaptPortTranslation = enable;
        rtlglue_drvMutexUnlock();

        return 0;
}
# 1705 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineWeakTcpNaptProcess(int8 enable)
{
        rtlglue_drvMutexLock();
        rtl8651_drvWeakTcpNaptEnable = enable;
        rtlglue_drvMutexUnlock();

        return 0;
}
# 1724 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEnginePsDontTimeout(int enable)
{
        rtlglue_drvMutexLock();
        rtl8651_drvProtocolStackDontTimeout = enable;
        rtlglue_drvMutexUnlock();

        return 0;
}
# 1749 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEnginePsToWanErrMsgDontTimeout(int enable)
{
        rtlglue_drvMutexLock();
        rtl8651_drvProtocolStackErrMsgDontTimeout = enable;
        rtlglue_drvMutexUnlock();

        return 0;
}
# 1769 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineDynamicRemoteHostPolicyRT(int enable)
{
        rtlglue_drvMutexLock();
        rtl8651_drvDynamicRPPolicyRoute = enable;
        rtlglue_drvMutexUnlock();

        return 0;
}
# 1796 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineSend(void * pkthdr, int16 dvid, int32 iphdrOffset)
{
        int32 retval = -1;

        rtlglue_drvMutexLock();


        retval = _rtl8651_fwdEngineProtocolStackSend(pkthdr,
                                                                                                dvid,
                                                                                                iphdrOffset,
                                                                                                0 );

        rtlglue_drvMutexUnlock();

        return retval;
}
# 1838 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineQosSend(void *pkthdr, int16 dvid, int32 iphdrOffset, int32 qualityId)
{
        int32 retval = -1;

        rtlglue_drvMutexLock();

        retval = _rtl8651_fwdEngineProtocolStackSend(pkthdr,
                                                                                                dvid,
                                                                                                iphdrOffset,
                                                                                                qualityId?1:0);

        rtlglue_drvMutexUnlock();

        return retval;
}

void _calc_L34Checksum(struct rtl_pktHdr *pkthdrPtr, int32 IphdrOffset)
{
        struct rtl_mBuf *mbuf = pkthdrPtr->PKTHDRNXT.mbuf_first;
        struct ip *iphdr = (struct ip *)&(mbuf->m_data[IphdrOffset]);
        uint16 org_l3cksum = 0, org_l4cksum = 0;

        if (pkthdrPtr->ph_un_sw.PS_USG.FROM_PS._ph_pkt_property & (1<<1)) {
                org_l3cksum = iphdr->ip_sum;
                iphdr->ip_sum = 0;
                iphdr->ip_sum = _rtl8651_ipChecksum(iphdr);
        }
        if (pkthdrPtr->ph_un_sw.PS_USG.FROM_PS._ph_pkt_property & (1<<2)) {
                uint16 ipcsm_tmp = iphdr->ip_sum;

                if ((((uint16)(iphdr->ip_off)) & 0x1fff))
                {
                        goto l4cksum_done;
                }
                switch (iphdr->ip_p)
                {
                        case 6:
                                {
                                        struct tcphdr *tcp;
                                        tcp = (struct tcphdr *)((uint8 *)iphdr + (((*(uint8*)iphdr)&0xf) << 2));

                                        org_l4cksum = tcp->th_sum;

                                        iphdr->ip_sum = 0;
                                        tcp->th_sum = 0;
                                        tcp->th_sum = _rtl8651_tcpChecksum(iphdr);
                                        iphdr->ip_sum = ipcsm_tmp;
                                }
                                break;
                        case 17:
                                {
                                        struct udphdr *udp;
                                        udp = (struct udphdr *)((uint8 *)iphdr + (((*(uint8*)iphdr)&0xf) << 2));

                                        org_l4cksum = udp->uh_sum;

                                        iphdr->ip_sum = 0;
                                        udp->uh_sum = 0;
                                        udp->uh_sum = _rtl8651_tcpChecksum(iphdr);
                                        iphdr->ip_sum = ipcsm_tmp;
                                }
                                break;
                        case 1:
                                {
                                        struct icmp *ic;
                                        ic = (struct icmp *)((uint8 *)iphdr + (((*(uint8*)iphdr)&0xf) << 2));

                                        org_l4cksum = ic->icmp_cksum;

                                        ic->icmp_cksum = 0;
                                        ic->icmp_cksum = _rtl8651_icmpChecksum(iphdr);
                                }
                                break;
                        case 2:
                                {
                                        struct igmp *ig;
                                        ig = (struct igmp *)((uint8 *)iphdr + (((*(uint8*)iphdr)&0xf) << 2));

                                        org_l4cksum = ig->igmp_cksum;

                                        ig->igmp_cksum = 0;
                                        ig->igmp_cksum = _rtl8651_icmpChecksum(iphdr);
                                }
                                break;
                }
        }

l4cksum_done:

        return;
}
# 1968 "rtl8651_tblDrvFwd.c"
static int32 _rtl8651_fwdEngineProtocolStackSend(void * pkthdr, int16 dvid, int32 iphdrOffset, int32 highPriority)
{
        int32 retval=-1;
        rtl8651_tblDrv_vlanTable_t *local_vlanp;
        uint32 dsid=0, portmask=0,l2portmask=0;

        uint32 sip=0;
        struct ip *iphdr=((void *)0);

        struct rtl_mBuf *mbuf;
        struct rtl_pktHdr * pkthdrPtr=(struct rtl_pktHdr *)pkthdr;
        uint32 assignedPortMask = pkthdrPtr->ph_portlist;
        int32 realIphdrOffset;

        uint8 isToWanPptpL2tpOther = 0;



        mbuf=pkthdrPtr->PKTHDRNXT.mbuf_first;
        pkthdrPtr->ph_vlanIdx= dvid & (8 -1);
        local_vlanp = &DrvTbl.vlan[pkthdrPtr->ph_vlanIdx];
        pkthdrPtr->ph_rxdesc = -1;
        realIphdrOffset = iphdrOffset;



        {
                rtl8651_tblDrv_routeTable_t *rt_t;


                rt_t = DrvTbl.route + (rtl8651_tblDrvPara.routingTableSize - 1);

                if (((rt_t->valid) && (rt_t->ifrt_flag == 0)) &&
                        ((rt_t->netif_t->linkLayerType == 0x05) || (rt_t->netif_t->linkLayerType == 0x06)))
                {
                        rtl8651_tblDrv_pppTable_t *pppEntry_t;
                        pppEntry_t = rt_t->un.nxthop.un1.session.session_t;

                        if (pppEntry_t && pppEntry_t->initiated && tunnel.valid && (local_vlanp->vid == tunnel.wanVid))
                        {
                                struct ip *outerIp;


                                if (realIphdrOffset <= 0)
                                {
                                        goto TO_WAN_PPTPL2TP_OTHER;
                                }

                                outerIp = (struct ip *)((uint32)(mbuf->m_data) + realIphdrOffset);

                                if ( (((uint16)(outerIp->ip_off)) & 0x1fff) )
                                {
                                        goto TO_WAN_PPTPL2TP_OTHER;
                                }

                                if (rt_t->netif_t->linkLayerType == 0x05)
                                {
                                        if (outerIp->ip_p == 47)
                                        {
                                                struct wan_gre_header *gre = (struct wan_gre_header*)((uint8 *)outerIp + (((*(uint8*)outerIp)&0xf) << 2));
                                                uint32 l4Len = 8;
                                                uint32 grePayloadLen = 0;
                                                uint8 *ptr = (uint8 *)gre;

                                                do {} while (0);

                                                if (gre->flags & 0x10)
                                                        l4Len += 4;
                                                if (gre->ver & 0x80)
                                                        l4Len += 4;

                                                if ((ptr[l4Len] == 0xff) && (ptr[l4Len + 1] == 0x03))
                                                {
                                                        l4Len += 2;
                                                        grePayloadLen += 2;
                                                }

                                                if ( ((ptr[l4Len] == 0x00) && (ptr[l4Len + 1] == 0x21) ) ||
                                                        (ptr[l4Len] == 0x21 ))
                                                {
                                                        struct ip *innerIp = ((void *)0);

                                                        if (ptr[l4Len] == 0x21)
                                                        {
                                                                l4Len += 1;
                                                                grePayloadLen += 1;
                                                        } else
                                                        {
                                                                l4Len += 2;
                                                                grePayloadLen += 2;
                                                        }

                                                        innerIp = (struct ip*)((uint32)gre + l4Len);




                                                        if ( ( (grePayloadLen + (((*(uint8*)innerIp)&0xf) << 2)) > (gre->payload_len) ) ||

                                                                ( (grePayloadLen + (innerIp->ip_len)) != (gre->payload_len) ))
                                                        {
                                                                goto TO_WAN_PPTPL2TP_OTHER;
                                                        }

                                                        if ((uint32)(outerIp->ip_len) != ((innerIp->ip_len) + ((uint32)innerIp - (uint32)outerIp)))
                                                        {
                                                                goto TO_WAN_PPTPL2TP_OTHER;
                                                        }


                                                        realIphdrOffset = l4Len + ((uint32)gre - (uint32)(mbuf->m_data));


                                                        _calc_L34Checksum(pkthdrPtr, realIphdrOffset);
                                                        goto IPHDROFFSET_MODIFY_DONE;
                                                }
                                        }
                                } else if (rt_t->netif_t->linkLayerType == 0x06)
                                {
                                        if (outerIp->ip_p == 17)
                                        {
                                                struct udphdr *udp = (struct udphdr *)((uint8 *)outerIp + (((*(uint8*)outerIp)&0xf) << 2));

                                                if (udp->uh_sport == (1701))
                                                {
                                                        struct wan_l2tp_header *l2tp = (struct wan_l2tp_header*)(udp + 1);

                                                        if (l2tp->flags_type == 0)
                                                        {
                                                                uint8 *u8p_l2tp = (uint8 *)l2tp;
                                                                struct ip *innerIp = ((void *)0);
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
                                                                } else if ((u8p_l2tp[l2tpPppChkLen] == 0x00) && (u8p_l2tp[l2tpPppChkLen + 1] == 0x21))
                                                                {
                                                                        l2tpPppChkLen += 2;
                                                                }
                                                                else
                                                                        goto TO_WAN_PPTPL2TP_OTHER;

                                                                innerIp = (struct ip*)((uint32)u8p_l2tp + l2tpPppChkLen);






                                                                if ( ( (l2tpPppChkLen + (((*(uint8*)innerIp)&0xf) << 2) + sizeof(struct udphdr)) > (udp->uh_ulen) ) ||

                                                                        ( (l2tpPppChkLen + (innerIp->ip_len) + sizeof(struct udphdr)) != (udp->uh_ulen)))
                                                                {
                                                                        goto TO_WAN_PPTPL2TP_OTHER;
                                                                }

                                                                if ((uint32)(outerIp->ip_len) != ((innerIp->ip_len) + ((uint32)innerIp-(uint32)outerIp)))
                                                                {
                                                                        goto TO_WAN_PPTPL2TP_OTHER;
                                                                }


                                                                realIphdrOffset = ((uint32)innerIp - (uint32)mbuf->m_data);

                                                                iphdr = (struct ip *)&(mbuf->m_data[realIphdrOffset]);




                                                                if (pkthdrPtr->ph_un_sw.PS_USG.FROM_PS._ph_pkt_property & (1<<1)) {
                                                                        uint16 org_l3cksum = iphdr->ip_sum;
                                                                        iphdr->ip_sum = 0;
                                                                        iphdr->ip_sum = _rtl8651_ipChecksum(iphdr);
                                                                        do { int32 accumulate; accumulate = ((org_l3cksum) - (iphdr->ip_sum)); do { accumulate += ((udp->uh_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (udp->uh_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (udp->uh_sum) = ((uint16) accumulate); } } while (0); } while(0);
                                                                }
                                                                if (pkthdrPtr->ph_un_sw.PS_USG.FROM_PS._ph_pkt_property & (1<<2)) {
                                                                        uint16 org_l4cksum;




                                                                        uint16 ipcsm_tmp = iphdr->ip_sum;

                                                                        if ((((uint16)(iphdr->ip_off)) & 0x1fff))
                                                                                goto IPHDROFFSET_MODIFY_DONE;

                                                                        switch (iphdr->ip_p)
                                                                        {
                                                                                case 6:
                                                                                        {
                                                                                                struct tcphdr *inner_tcp;
                                                                                                inner_tcp = (struct tcphdr *)((uint8 *)iphdr + (((*(uint8*)iphdr)&0xf) << 2));
                                                                                                org_l4cksum = inner_tcp->th_sum;
                                                                                                iphdr->ip_sum = 0;
                                                                                                inner_tcp->th_sum = 0;
                                                                                                inner_tcp->th_sum = _rtl8651_tcpChecksum(iphdr);
                                                                                                iphdr->ip_sum = ipcsm_tmp;

                                                                                                do { int32 accumulate; accumulate = ((org_l4cksum) - (inner_tcp->th_sum)); do { accumulate += ((udp->uh_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (udp->uh_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (udp->uh_sum) = ((uint16) accumulate); } } while (0); } while(0);
                                                                                        }
                                                                                        break;
                                                                                case 17:
                                                                                        {
                                                                                                struct udphdr *inner_udp;
                                                                                                inner_udp = (struct udphdr *)((uint8 *)iphdr + (((*(uint8*)iphdr)&0xf) << 2));
                                                                                                org_l4cksum = inner_udp->uh_sum;
                                                                                                iphdr->ip_sum = 0;
                                                                                                inner_udp->uh_sum = 0;
                                                                                                inner_udp->uh_sum = _rtl8651_tcpChecksum(iphdr);
                                                                                                iphdr->ip_sum = ipcsm_tmp;

                                                                                                do { int32 accumulate; accumulate = ((org_l4cksum) - (inner_udp->uh_sum)); do { accumulate += ((udp->uh_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (udp->uh_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (udp->uh_sum) = ((uint16) accumulate); } } while (0); } while(0);
                                                                                        }
                                                                                        break;
                                                                                case 1:
                                                                                        {
                                                                                                struct icmp *inner_ic;
                                                                                                inner_ic = (struct icmp *)((uint8 *)iphdr + (((*(uint8*)iphdr)&0xf) << 2));
                                                                                                org_l4cksum = inner_ic->icmp_cksum;
                                                                                                inner_ic->icmp_cksum = 0;
                                                                                                inner_ic->icmp_cksum = _rtl8651_icmpChecksum(iphdr);

                                                                                                do { int32 accumulate; accumulate = ((org_l4cksum) - (inner_ic->icmp_cksum)); do { accumulate += ((udp->uh_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (udp->uh_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (udp->uh_sum) = ((uint16) accumulate); } } while (0); } while(0);
                                                                                        }
                                                                                        break;
                                                                                case 2:
                                                                                        {
                                                                                                struct igmp *inner_ig;
                                                                                                inner_ig = (struct igmp *)((uint8 *)iphdr + (((*(uint8*)iphdr)&0xf) << 2));
                                                                                                org_l4cksum = inner_ig->igmp_cksum;
                                                                                                inner_ig->igmp_cksum = 0;
                                                                                                inner_ig->igmp_cksum = _rtl8651_icmpChecksum(iphdr);

                                                                                                do { int32 accumulate; accumulate = ((org_l4cksum) - (inner_ig->igmp_cksum)); do { accumulate += ((udp->uh_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (udp->uh_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (udp->uh_sum) = ((uint16) accumulate); } } while (0); } while(0);
                                                                                        }
                                                                                        break;
                                                                        }
                                                                }

                                                                goto IPHDROFFSET_MODIFY_DONE;
                                                        }
                                                }
                                        }
                                }
TO_WAN_PPTPL2TP_OTHER:
# 2239 "rtl8651_tblDrvFwd.c"
                                isToWanPptpL2tpOther = 1;
                        }
                }
        }
IPHDROFFSET_MODIFY_DONE:




        if (mbuf->m_data[12] == 0x88 && (mbuf->m_data[13] == 0x63 || mbuf->m_data[13] == 0x64)) {
                rtl8651_tblDrv_pppTable_t * pppoePtr;
                uint16 sessionId = (mbuf->m_data[16] << 8) + mbuf->m_data[17];

                pppoePtr = _rtl8651_getPppoeSessionByPppoeSessionId(sessionId);
                pkthdrPtr->ph_pppoeIdx = (pppoePtr - DrvTbl.pppoe);
        }


        if(realIphdrOffset>=0){


                iphdr=(struct ip *)&mbuf->m_data[realIphdrOffset];

                sip = ((uint32) (*((uint8*)(&iphdr->ip_src.s_addr))<<24)|(*(((uint8*)(&iphdr->ip_src.s_addr))+1)<<16)|(*(((uint8*)(&iphdr->ip_src.s_addr))+2)<<8) | *(((uint8*)(&iphdr->ip_src.s_addr))+3));
                dsid= _rtl8651_getpppDSID(sip);
# 2299 "rtl8651_tblDrvFwd.c"
                if (isToWanPptpL2tpOther == 0)

                {
# 2366 "rtl8651_tblDrvFwd.c"
                        if((mbuf->m_data[12]!=0x88)||(mbuf->m_data[13]!=0x64)||((mbuf->m_data[20]==0x00) && (mbuf->m_data[21]==0x21)))
                        {
                                _rtl8651_aliasProtoStackSentPkt( !local_vlanp->internal,dsid, iphdr );
                        }
# 2378 "rtl8651_tblDrvFwd.c"
                        _rtl8651_dosScanCheckComplain(dsid, iphdr);
# 2388 "rtl8651_tblDrvFwd.c"
                        _rtl8651_resolveProxyInboundFlow(local_vlanp, iphdr);

                }
# 2401 "rtl8651_tblDrvFwd.c"
                if ((!local_vlanp->internal) && (!(((uint16)(iphdr->ip_off)) & 0x1fff)))
                {
                        _rtl8651_fwdEnginePsFlowCacheCreate(iphdr);
                }

        }
        if (assignedPortMask==0)
        {
                l2portmask=rtl8651_asicL2DAlookup(mbuf->m_data);
                if (l2portmask == 0)
                {
                        l2portmask = local_vlanp->memberPortMask;
                }

                else if (l2portmask == (1<<0x7))
                {
                        l2portmask = (1<<tunnel.wanPort);
                }

        } else
        {
                l2portmask = assignedPortMask;
        }
        portmask = local_vlanp->memberPortMask & l2portmask;

        if (!portmask)
        {
                retval = 135;
                mBuf_driverFreeMbufChain(mbuf);
                goto out;
        }

        pkthdrPtr->ph_portlist = portmask;
        pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid = dsid;
        pkthdrPtr->ph_flags |= (0x8800 | ((highPriority == 1)?0x0010:0));


        retval= _rtl8651_fwdEngineSend(((uint32)(1)<<2), pkthdr, dvid, iphdrOffset);


        if (retval != 0)

        {
                mBuf_driverFreeMbufChain(mbuf);
        }
out:
        return retval;
}


static void _rtl8651_fwdEnginePsFlowCacheCreate(struct ip *iphdr)
{
# 2470 "rtl8651_tblDrvFwd.c"
        uint8 protocol;

        protocol = iphdr->ip_p;

        if ((protocol == 6) || (protocol == 17))
        {
                struct tcphdr *tc;
                struct udphdr *ud;
                ipaddr_t sip;
                ipaddr_t dip;
                uint16 sport;
                uint16 dport;
                struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s entry;
                struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s *tbl;

                tbl = &entry;

                sip = ((uint32) (*((uint8*)(&iphdr->ip_src))<<24)|(*(((uint8*)(&iphdr->ip_src))+1)<<16)|(*(((uint8*)(&iphdr->ip_src))+2)<<8) | *(((uint8*)(&iphdr->ip_src))+3));
                dip = ((uint32) (*((uint8*)(&iphdr->ip_dst))<<24)|(*(((uint8*)(&iphdr->ip_dst))+1)<<16)|(*(((uint8*)(&iphdr->ip_dst))+2)<<8) | *(((uint8*)(&iphdr->ip_dst))+3));

                if (protocol == 6)
                {
                        tc = (struct tcphdr *)((uint8 *)iphdr + (((*(uint8*)iphdr)&0xf) << 2));

                        sport = (tc->th_sport);
                        dport = (tc->th_dport);

                        if (_rtl8651_getOutboundNaptFlow(1, sip, sport, dip, dport, &tbl) != 0)
                        {
                                int8 flowType;
                                int32 retval;
                                int16 retryCnt = 10;
                                uint16 newSport = sport;

                                if (tc->th_flags == 0x02)
                                {
                                        flowType = 2;
                                }else
                                {





                                        flowType = 5;
                                }

                                tbl = ((void *)0);


                                while ( _rtl8651_getInboundNaptFlow(1, sip, newSport, dip, dport, &tbl) == 0 )
                                {
                                        retryCnt --;
                                        newSport += 4096;
                                        tbl = ((void *)0);
                                        if (retryCnt == 0) break;
                                }


                                if ( (retryCnt > 0) &&
                                        ((retval = _rtl8651_addNaptConnection(1, (1|0x0002|0x0004|0x0008), flowType, sip, sport, &sip, &newSport, dip, dport)) == 0) )
                                {
                                        tbl = &entry;
                                        if ((retval = _rtl8651_getInboundNaptFlow(1, sip, newSport, dip, dport, &tbl)) != 0)
                                        {




                                                tbl = ((void *)0);
                                        }
                                }

                        }
                        if (tbl)
                        {
                                if ( tbl->insideLocalPort != tbl->insideGlobalPort)
                                {
                                        do {} while (0);
                                        tc->th_sport = (tbl->insideGlobalPort);
                                        do { int32 accumulate = 0; if (((0) != 0) && ((0) != 0)){ accumulate = ((0) & 0xffff); accumulate += (( (0) >> 16 ) & 0xffff); accumulate -= ((0) & 0xffff); accumulate -= (( (0) >> 16 ) & 0xffff); } if (((tbl->insideGlobalPort) != 0) && ((sport) != 0)){ accumulate += (sport); accumulate -= (tbl->insideGlobalPort); } do { accumulate += ((tc->th_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) accumulate); } } while (0); }while(0);
                                        sport = tbl->insideGlobalPort;
                                }
                                do {} while (0);
                                _rtl8651_l4TcpMonitorOut(tc, tbl);
                        }
                }else
                {
                        ud = (struct udphdr *)((uint8 *)iphdr + (((*(uint8*)iphdr)&0xf) << 2));

                        sport = (ud->uh_sport);
                        dport = (ud->uh_dport);

                        if (_rtl8651_getOutboundNaptFlow(0, sip, sport, dip, dport, &tbl) != 0)
                        {
                                int32 retval;
                                int16 retryCnt = 10;
                                uint16 newSport = sport;

                                tbl = ((void *)0);


                                while ( _rtl8651_getInboundNaptFlow(0, sip, newSport, dip, dport, &tbl) == 0 )
                                {
                                        retryCnt --;
                                        newSport += 4096;
                                        tbl = ((void *)0);
                                        if (retryCnt == 0) break;
                                }


                                if ( (retryCnt > 0) && ((retval = _rtl8651_addNaptConnection(1, (1|0x0002|0x0004|0x0008), 0,
                                        sip, sport, &sip, &newSport, dip, dport)) == 0) )
                                {
                                        tbl = &entry;
                                        if ((retval = _rtl8651_getInboundNaptFlow(0, sip, newSport, dip, dport, &tbl)) != 0)
                                        {




                                                tbl = ((void *)0);
                                        }
                                }


                        }
                        if (tbl)
                        {
                                if ( tbl->insideLocalPort != tbl->insideGlobalPort)
                                {
                                        do {} while (0);
                                        ud->uh_sport = (tbl->insideGlobalPort);
                                        if (ud->uh_sum);
                                                do { int32 accumulate = 0; if (((0) != 0) && ((0) != 0)){ accumulate = ((0) & 0xffff); accumulate += (( (0) >> 16 ) & 0xffff); accumulate -= ((0) & 0xffff); accumulate -= (( (0) >> 16 ) & 0xffff); } if (((tbl->insideGlobalPort) != 0) && ((sport) != 0)){ accumulate += (sport); accumulate -= (tbl->insideGlobalPort); } do { accumulate += ((ud->uh_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) accumulate); } } while (0); }while(0);
                                        sport = tbl->insideGlobalPort;
                                }
                                do {} while (0);
                                _rtl8651_updateNaptConnection(tbl, 0, rtl8651GlobalControl.udpTimeout);
                        }
                }
        }

        return;
}

int32 rtl8651_offloadEngineL3Send(void * pPkt, uint32 L3PktLength, uint32 l34CkumOffload, int32 highPriority)
{
# 2638 "rtl8651_tblDrvFwd.c"
        struct rtl_pktHdr *pkthdr = (struct rtl_pktHdr*)pPkt;
        struct rtl_mBuf *mBuf = ((void *)0);
        struct ip *iphdr = ((void *)0);
        int32 retval = -1;





        if (pkthdr==((void *)0)||pkthdr->PKTHDRNXT.mbuf_first==((void *)0))
        {
                return 31000;
        }

        mBuf = pkthdr->PKTHDRNXT.mbuf_first;

        if (((uint32)(mBuf->m_data) - (uint32)(mBuf->m_extbuf)) < (14 + rtl8651_fwdEnginePara.mbufHeadroom))
        {
                return 31001;
        }

        iphdr = (struct ip*)(mBuf->m_data);




        mBuf->m_data -= 14;
        memset(mBuf->m_data, 0, 2 * sizeof(ether_addr_t));
        *(uint16*)&(mBuf->m_data[12]) = (0x0800);
# 2676 "rtl8651_tblDrvFwd.c"
        if (l34CkumOffload)
        {
                if (!(((*(uint8*)iphdr)&0xf) == 5))
                {
                        if (l34CkumOffload & 0x0002)
                        {
                                if (!(((uint16)(iphdr->ip_off)) & (0x1fff|0x2000)))
                                {
                                        switch (iphdr->ip_p)
                                        {
                                                case 6:
                                                {
                                                        struct tcphdr *tc = (struct tcphdr*)((uint8 *)iphdr + (((*(uint8*)iphdr)&0xf) << 2));
                                                        tc->th_sum = 0;
                                                        tc->th_sum = _rtl8651_tcpChecksum(iphdr);
                                                }
                                                        break;
                                                case 17:
                                                {
                                                        struct udphdr *ud = (struct udphdr*)((uint8 *)iphdr + (((*(uint8*)iphdr)&0xf) << 2));
                                                        ud->uh_sum = 0;
                                                        ud->uh_sum = _rtl8651_tcpChecksum(iphdr);
                                                }
                                                        break;
                                                case 1:
                                                {
                                                        struct icmp *ic = (struct icmp*)((uint8 *)iphdr + (((*(uint8*)iphdr)&0xf) << 2));
                                                        ic->icmp_cksum = 0;
                                                        ic->icmp_cksum = _rtl8651_icmpChecksum(iphdr);
                                                }
                                                        break;
                                                case 2:
                                                {
                                                        struct igmp *ig = (struct igmp*)((uint8 *)iphdr + (((*(uint8*)iphdr)&0xf) << 2));
                                                        ig->igmp_cksum = 0;
                                                        ig->igmp_cksum = _rtl8651_icmpChecksum(iphdr);
                                                }
                                                        break;
                                        }
                                }
                        }
                        if (l34CkumOffload & 0x0001)
                        {
                                iphdr->ip_sum = 0;
                                iphdr->ip_sum = _rtl8651_ipChecksum(iphdr);
                        }
                }
        }




        pkthdr->ph_sip = ((uint32) (*((uint8*)(&iphdr->ip_src))<<24)|(*(((uint8*)(&iphdr->ip_src))+1)<<16)|(*(((uint8*)(&iphdr->ip_src))+2)<<8) | *(((uint8*)(&iphdr->ip_src))+3));
        pkthdr->ph_dip = ((uint32) (*((uint8*)(&iphdr->ip_dst))<<24)|(*(((uint8*)(&iphdr->ip_dst))+1)<<16)|(*(((uint8*)(&iphdr->ip_dst))+2)<<8) | *(((uint8*)(&iphdr->ip_dst))+3));
        switch (iphdr->ip_p)
        {
                case 6: pkthdr->ph_proto = 5; break;
                case 17: pkthdr->ph_proto = 6; break;
                case 1: pkthdr->ph_proto = 3; break;
                case 2: pkthdr->ph_proto = 4; break;
                case 47: pkthdr->ph_proto = 1; break;
                default: pkthdr->ph_proto = 2; break;
        }

        pkthdr->ph_un_sw.ROMEDRV_USG._ph_dataLen = 0;
        pkthdr->ph_un_sw.ROMEDRV_USG._ph_fragOffset = 0;
        pkthdr->ph_reason = 2;
        pkthdr->ph_un_sw.ROMEDRV_USG._ph_sport = 0;

        pkthdr->ph_flags &= ~(0x0100|0x0080|0x0040|0x0020|0x0010|0x0008|0x0004|0x0002|0x0001);
        pkthdr->ph_flags |= ((highPriority == 1)?0x0010:0);
        pkthdr->ph_portlist = (6 +rtl8651_totalExtPortNum+1);
        pkthdr->ph_extPortList = 0;
        pkthdr->ph_srcExtPortNum = 0;
        pkthdr->ph_vlanIdx = 0;
        pkthdr->ph_pppoeIdx = 0;
        pkthdr->ph_un_sw.ROMEDRV_USG._ph_unnumber = 0;
        pkthdr->ph_vlanTagged = 0;
        pkthdr->ph_LLCTagged = 0;

        pkthdr->ph_routeIdx = 0;
        pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid = _rtl8651_getpppDSID(pkthdr->ph_sip);
        pkthdr->ph_iphdrOffset = 14;
        pkthdr->ph_len = mBuf->m_len = 14 + L3PktLength;




        if (pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid != _rtl8651_DefaultDialSessionId)
        {
                rtl8651_tblDrv_routeTable_t *rt_t = ((void *)0);
                rtl8651_tblDrv_vlanTable_t *vlan_t;
# 2776 "rtl8651_tblDrvFwd.c"
                rt_t = _rtl8651_getRoutingEntry(pkthdr->ph_dip);

                if (rt_t && rt_t->valid)
                {
                        vlan_t = &DrvTbl.vlan[(rt_t->dvid& (8 -1))];
                        if (vlan_t->internal == 0)
                        {
                                rtl8651_tblDrv_pppTable_t *ppp_tb = ((void *)0);

                                ppp_tb = _rtl8651_getPppoeSessionByDsid((uint32)(pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid));
                                if (ppp_tb)
                                {
                                        uint32 rtIdx;

                                        rt_t = DrvTbl.route;
                                        for(rtIdx = 0; rtIdx < rtl8651_tblDrvPara.routingTableSize; rtIdx++,rt_t++)
                                        {
                                                if ( (rt_t->netif_t->linkLayerType == 0x02) &&
                                                        (rt_t->un.nxthop.un1.session.session_t == ppp_tb))
                                                {

                                                        vlan_t = &DrvTbl.vlan[(rt_t->dvid& (8 -1))];
                                                        if (vlan_t->internal == 0)
                                                        {
                                                                pkthdr->ph_routeIdx = (rt_t - &DrvTbl.route[0]) + 1;
                                                                goto policyRoute_done;
                                                        }
                                                }
                                        }
                                }

                        }
                }
        }
policyRoute_done:




        rtlglue_drvMutexLock();
        retval = _rtl8651_l3FastActRouting(((uint32)(1)<<3), pkthdr, pkthdr->ph_dip, iphdr, ((void *)0));
        rtlglue_drvMutexUnlock();

        if (retval != 0)
        {

                mBuf_freeMbufChain(mBuf);
        }

        return retval;

}

static void _rtl8651_fwdEnginePSOffload_L3ExtraProcess(struct rtl_pktHdr *pPkt, struct ip *iphdr, rtl8651_tblDrv_vlanTable_t *vlan_t)
{
        uint8 dsid = pPkt->ph_un_sw.ROMEDRV_USG._ph_dsid;
# 2851 "rtl8651_tblDrvFwd.c"
        _rtl8651_aliasProtoStackSentPkt(!vlan_t->internal, dsid, iphdr);
# 2860 "rtl8651_tblDrvFwd.c"
        _rtl8651_dosScanCheckComplain(dsid, iphdr);
# 2870 "rtl8651_tblDrvFwd.c"
        _rtl8651_resolveProxyInboundFlow(vlan_t, iphdr);
# 2881 "rtl8651_tblDrvFwd.c"
        if ((!vlan_t->internal) && (!(((uint16)(iphdr->ip_off)) & 0x1fff)))
        {
                _rtl8651_fwdEnginePsFlowCacheCreate(iphdr);
        }


}


static int32 _getEthTypeIpOffset(struct rtl_pktHdr *ph, uint8 *m_data, uint32 *ethtypeOffset, uint32 *iphdrOffset, uint32 *ncp){
        uint32 ip_offset = *iphdrOffset;
        uint32 ethTypePos= *ethtypeOffset;
        if( ph->ph_vlanTagged){
                ip_offset+=4;
                ethTypePos+=4;

                if(m_data[ethTypePos-2] & 0x10 )
                        return 12;
        }
        if(ph->ph_LLCTagged){
                ip_offset+=6;
                ethTypePos+=8;
        }
        if(ph->ph_pppeTagged){
                *ncp= (*((uint16 *)(m_data+ip_offset+6)));
                ip_offset+=8;
        }
        *ethtypeOffset=ethTypePos;
        *iphdrOffset=ip_offset;
        return 0;
}
# 2998 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineInput(void * pkthdr)
{
        struct rtl_pktHdr * pkthdrPtr = (struct rtl_pktHdr *)pkthdr;
        struct rtl_mBuf *mbufPtr;
        ipaddr_t sip,dip;
        uint16 vid, ethType = 0;
        uint32 ethTypePos;
        uint8 *m_data;
        int32 local_val;
        uint8 ip_protocol;
        struct ip *ip=((void *)0);
        int32 ip_offset;
        uint32 ncp = 0;
        uint16 srcPortlist = 0;
        rtl8651_tblDrv_vlanTable_t *local_vlanp;
        int32 inAcl_done = 0;
        uint32 inAcl_index = 0;
        uint8 *l4hdr;
        uint8 direction;
        struct tcphdr *tc;
        struct udphdr *ud;
        uint8 isMulticast;


        uint32 srcType = _RTL8651_HOST_NONE;
        uint32 dstType = _RTL8651_HOST_NONE;
        uint32 decision = _RTL8651_DEC_NONE;
        uint32 optLayer = 0;
# 3034 "rtl8651_tblDrvFwd.c"
        rtlglue_drvMutexLock();

        local_vlanp = &DrvTbl.vlan[pkthdrPtr->ph_vlanIdx];


        mbufPtr = pkthdrPtr->PKTHDRNXT.mbuf_first;
        m_data = mbufPtr->m_data;
        pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_procFlag = 0;
        srcPortlist = pkthdrPtr->ph_portlist;

        do {} while (0);
        ip_offset = 14;
        ethTypePos = 12;
        ncp = 0;


        if (( *((uint16 *)(((uint8 *)pkthdrPtr)+8))&0x1c00)==0)
        {
                pkthdrPtr->ph_iphdrOffset = 14;
        } else
        {

                local_val = _getEthTypeIpOffset(pkthdrPtr,m_data, &ethTypePos, &ip_offset, &ncp);
                if (local_val != 0)
                {
                        goto out;
                }
                pkthdrPtr->ph_iphdrOffset = ip_offset;
        }
        ethType = (*((uint16*)(m_data+ethTypePos)));
        ip = (struct ip *)(pkthdrPtr->PKTHDRNXT.mbuf_first->m_data + ip_offset);




        if ( ( pkthdrPtr->ph_reason & 0x1c ) == 0x04 )
        {
                uint8 l4proto;
                l4proto = ip->ip_p;

                inAcl_done = 0;
                inAcl_index = ((pkthdrPtr->ph_reason >> 5) & 0x7f);






                if ( _rtl8651_jumptoACLDB(inAcl_index, pkthdrPtr, ip) == 0 )
                {
                        switch (l4proto)
                        {
                                case 6:
                                        rtl8651_fwdEngineCounter.tcpReceive ++;
                                        rtl8651_fwdEngineCounter.tcpSend ++;
                                        break;
                                case 17:
                                        rtl8651_fwdEngineCounter.udpReceive ++;
                                        rtl8651_fwdEngineCounter.udpSend ++;
                                        break;
                                case 1:
                                        rtl8651_fwdEngineCounter.icmpReceive ++;
                                        rtl8651_fwdEngineCounter.icmpSend ++;
                                        break;
                        }
                        local_val = 0;

                        goto out;
                }

        }else if ( pkthdrPtr->ph_reason & 0x18 )
        {
                rtl8651_fwdEngineCounter.inAclPermit ++;
                inAcl_done = 1;
                inAcl_index = 0;
        } else
        {
                inAcl_done = 0;
                inAcl_index = 0;
# 3132 "rtl8651_tblDrvFwd.c"
        }






        if (local_vlanp != ((void *)0) && pkthdrPtr->ph_vlanTagged)
        {
                _rtl8651_rxPktPreprocess_stripVlan(pkthdrPtr);
        }
# 3154 "rtl8651_tblDrvFwd.c"
        local_val = rtl8651_fwdEngineL2Input(pkthdrPtr,local_vlanp, m_data,ethType);

        if (local_val == 0)
        {
                goto out;
        }
        if (local_val != -1)
        {






                if (local_val == 46)
                {
                        isMulticast = 1;
                }else
                {


                        if (local_val == 13)
                                rtl8651_fwdEngineCounter.pppoeDiscoveryReceive++;
                        goto out;
                }
        }

        vid = local_vlanp->vid;
        pkthdrPtr->ph_routeIdx = 0;





        pkthdrPtr->ph_sip=((*((uint16*)&ip->ip_src))<<16)+(*(((uint16*)&ip->ip_src)+1));
        pkthdrPtr->ph_dip=((*((uint16*)&ip->ip_dst))<<16)+(*(((uint16*)&ip->ip_dst)+1));



        _rtl8651_fragQueueProcessOk = 0;




        if ((rtl8651_drvRoutingEnable == 1) && (ip->ip_ttl > 1))
        {
                if (((ethType == 0x0800) || (ncp == 0x0021)))
                {
                        uint8 l4proto;
                        l4proto = ip->ip_p;

                        if (l4proto == 17)
                        {
                                if (_rtl8651_fragmentShortestPathFwd(pkthdrPtr, ip) == 0)
                                {
                                        rtl8651_fwdEngineCounter.udpReceive ++;
                                        rtl8651_fwdEngineCounter.udpSend ++;
                                        local_val = 0;
                                        goto out;
                                }
                        }else if (l4proto == 6)
                        {
                                if (_rtl8651_fragmentShortestPathFwd(pkthdrPtr, ip) == 0)
                                {
                                        rtl8651_fwdEngineCounter.tcpReceive ++;
                                        rtl8651_fwdEngineCounter.tcpSend ++;
                                        local_val = 0;
                                        goto out;
                                }
                        }

                        if (_rtl8651_dos_enable == 1)
                        {







                                if (_rtl8651_dosProc_blockSip_check(vid, pkthdrPtr->ph_sip) == 0)
                                {
                                        local_val = 0x1000;
                                        goto out;
                                }
                        }
                }


                if ((_rtl8651_dos_enable == 0) && (_rtl8651_udpBlockingEnable == 0))
                {





                        rtl8651_drvPacketFastSend = 1;
                        if (local_vlanp->internal) {
                                if (ip->ip_p == 17)
                                {
                                        local_val = _rtl8651_l4UdpFastAliasOut(pkthdrPtr, ip);
                                        do {} while (0);
                                        if (local_val == 0)
                                        {
                                                rtl8651_fwdEngineCounter.udpReceive ++;
                                                rtl8651_fwdEngineCounter.udpSend++;




                                                goto out;
                                        }else if ((local_val > 0) && (local_val & 0x1000))
                                        {
                                                rtl8651_fwdEngineCounter.udpReceive ++;
                                                goto out;
                                        }
                                } else if (ip->ip_p == 6)
                                {
                                        local_val = _rtl8651_l4TcpFastAliasOut(pkthdrPtr,ip);
                                        do {} while (0);
                                        if (local_val == 0)
                                        {
                                                rtl8651_fwdEngineCounter.tcpReceive ++;
                                                rtl8651_fwdEngineCounter.tcpSend++;




                                                goto out;
                                        }else if ((local_val > 0) && (local_val & 0x1000))
                                        {
                                                rtl8651_fwdEngineCounter.tcpReceive ++;
                                                goto out;
                                        }
                                }
                        }
                        else {
                                if (ip->ip_p == 17)
                                {
                                        local_val=_rtl8651_l4UdpFastAliasIn(pkthdrPtr, ip);
                                        do {} while (0);
                                        if (local_val == 0)
                                        {
                                                rtl8651_fwdEngineCounter.udpReceive ++;
                                                rtl8651_fwdEngineCounter.udpSend++;




                                                goto out;
                                        }else if ((local_val > 0) && (local_val&0x1000))
                                        {
                                                rtl8651_fwdEngineCounter.udpReceive ++;
                                                goto out;
                                        }
                                } else if (ip->ip_p == 6)
                                {
                                        local_val = _rtl8651_l4TcpFastAliasIn(pkthdrPtr,ip);
                                        do {} while (0);
                                        if (local_val == 0)
                                        {
                                                rtl8651_fwdEngineCounter.tcpReceive ++;
                                                rtl8651_fwdEngineCounter.tcpSend++;




                                                goto out;
                                        }else if ((local_val > 0) && (local_val&0x1000))
                                        {
                                                rtl8651_fwdEngineCounter.tcpReceive ++;
                                                goto out;
                                        }
                                }
                        }
                        rtl8651_drvPacketFastSend = 0;
                }

        }






        tc = ((void *)0);
        ud = ((void *)0);
        ip_protocol = 0;
        local_val = -1;
        l4hdr = ((void *)0);
        direction = 0;
        isMulticast = 0;
# 3358 "rtl8651_tblDrvFwd.c"
        if (pkthdrPtr->ph_proto == 0)
        {

                if (!inAcl_done)
                {
                        local_val = _rtl8651_ingressAcl( pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid,
                                                                                        inAcl_index,
                                                                                        local_vlanp,
                                                                                        vid,
                                                                                        m_data,
                                                                                        ((void *)0),
                                                                                        0x00,
                                                                                        0);

                        if (((local_val > 0) && (local_val&0x1000))||(local_val==2))
                        {
                                goto out;
                        }
                        inAcl_done = 1;
                }


                if(ethType == 0x0806) {

                        local_val = _rtl8651_drvArpAgent(pkthdrPtr, mbufPtr, vid);
                        goto out;
                }else if(ethType == 0x8863) {

                        if(rtl8651_drvPppoeNotExistedSessionTerminationEnable == 1) {
                                pppoeHdr_t * pppoeHdrPtr;
                                pppoeHdrPtr = (pppoeHdr_t *)&(mbufPtr->m_data[ethTypePos+2]);
                                if(pppoeHdrPtr->code == 0x65) {
                                        printk("Active Session Detection receive PADS to update session ID %x\n", (pppoeHdrPtr->sessionId));
                                        _rtl8651_updatePppoeActiveSession((pppoeHdrPtr->sessionId));
                                } else if(pppoeHdrPtr->code == 0xa7) {
                                        printk("Active Session Detection receive PADT to terminate session ID %x\n", (pppoeHdrPtr->sessionId));
                                        _rtl8651_terminatePppoeActiveSession((pppoeHdrPtr->sessionId));
                                }
                        }
                        rtl8651_fwdEngineCounter.pppoeDiscoveryReceive++;

                        if (rtl8651_PPPoEEnable){

                                do {} while (0);
                                if(rtl8651_pppoeInput(mbufPtr)) {
                                        local_val = -1;
                                }else{
                                        rtl8651_fwdEngineCounter.pppoeDiscoveryProcessed++;
                                        local_val = 0;
                                }
                        }else
                                local_val=13;




                        goto out;
                }
        }

        if(pkthdrPtr->ph_pppeTagged){

                pppoeHdr_t * pppoeHdrPtr;
                rtl8651_tblDrv_pppTable_t * pppoePtr;

                pppoeHdrPtr = (pppoeHdr_t *)&(mbufPtr->m_data[ethTypePos+2]);
                pppoePtr = _rtl8651_getPppoeSessionByPppoeSessionId((pppoeHdrPtr->sessionId));
                if(pppoePtr == ((void *)0)) {
                        if(rtl8651_drvPppoeNotExistedSessionTerminationEnable == 1 &&
                                _rtl8651_pppoeSessionActive((pppoeHdrPtr->sessionId)) == 0) {
                                uint16 i;
                                uint8 charValue;


                                printk("SID %x should be invalid send PADT\n", (pppoeHdrPtr->sessionId));

                                for(i=0; i<6; i++) {
                                        charValue = mbufPtr->m_data[i];
                                        mbufPtr->m_data[i] = mbufPtr->m_data[i+6];
                                        mbufPtr->m_data[i+6] = charValue;
                                }
                                mbufPtr->m_data[ethTypePos] = 0x88;
                                mbufPtr->m_data[ethTypePos+1] = 0x63;
                                pppoeHdrPtr->code = 0xa7;
                                pppoeHdrPtr->length = 0;
                                pkthdrPtr->ph_flags &= ~(0x0100 | 0x0080 | 0x0040 | 0x0020 | 0x0010 |
                                                                                0x0008 | 0x0004 | 0x0002 | 0x0001 | 0x0002 | 0x0001);
                                pkthdrPtr->ph_pppeTagged = 0;
                                pkthdrPtr->ph_proto = 0;
                                pkthdrPtr->ph_srcExtPortNum = 0;
                                pkthdrPtr->ph_extPortList = 0;
                                pkthdrPtr->ph_portlist = 1<<pkthdrPtr->ph_portlist;
                                pkthdrPtr->ph_len = mbufPtr->m_len = 60;
                                if(_rtl8651_fwdEngineSend(((uint32)(1)<<1), (void*)pkthdrPtr, vid,-1)!=0) {
                                        mBuf_driverFreeMbufChain(pkthdrPtr->PKTHDRNXT.mbuf_first);
                                }
                                local_val = 0;
                                goto out;
                        }
                }
                else {
                        pppoePtr->rxBytes += pkthdrPtr->ph_len;
                        pppoePtr->rxPackets ++;
                }
                do {} while (0);

                        rtl8651_fwdEngineCounter.pppoeSessionReceive++;
                if(ncp!=0x0021){
                        if (rtl8651_PPPoEEnable){

                                do {} while (0);
                                if(rtl8651_pppoeInput(mbufPtr)){
                                        local_val=-1;
                                }else{
                                        rtl8651_fwdEngineCounter.pppoeSessionProcessed++;
                                        local_val=0;
                                }
                        }else
                                local_val=14;
                        goto out;
                }
                else {
                }
                rtl8651_fwdEngineCounter.pppoeSessionProcessed++;
        }else if(ethType!=0x0800){
                local_val=18;
                goto out;
        }





        if(rtl8651_drvRoutingEnable == 0){
                local_val=31;
                goto out;
        }
# 3503 "rtl8651_tblDrvFwd.c"
        if((((pkthdrPtr->ph_flags) & (0x0002))==0)) {
                rtl8651_fwdEngineCounter.ipErrorReceive++;
                local_val = 43;
                goto out;
        }

        ip_protocol = ip->ip_p;
        l4hdr = (uint8 *) ((uint8 *)ip + (((*(uint8*)ip)&0xf) << 2));

        sip = pkthdrPtr->ph_sip;
        dip = pkthdrPtr->ph_dip;


        if (!(((*(uint8*)ip)&0xf) == 5))
        {
                switch(ip->ip_p)
                {
                        case 6:
                                pkthdrPtr->ph_proto = 5;
                                break;
                        case 17:
                                pkthdrPtr->ph_proto = 6;
                                break;
                        case 1:
                                pkthdrPtr->ph_proto = 3;
                                break;
                        case 2:
                                pkthdrPtr->ph_proto = 4;
                                break;

                }
        }





        if(!dip||((dip&0xff000000)==0x7f000000)){
                local_val=45;
                goto out;
        }
        if(sip&&(sip==0xffffffff|| (sip&0xff000000)==0x7f000000||(sip & 0xf0000000) == 0xe0000000)){
                local_val=45;
                goto out;
        }

        if (((((ipaddr_t)(dip)) & 0xf0000000) == 0xe0000000))
                isMulticast = 1;


        if (pkthdrPtr->ph_proto == 4)
        {
                struct igmp *ig = (struct igmp*)l4hdr;
                rtl8651_fwdEngineCounter.igmpReceive++;


                if (!(rtl8651_drvFwdUnicastIGMPEnable && (((((ipaddr_t)(dip)) & 0xf0000000) < 0xe0000000))))
                {
                        local_val = 32;

                        if (rtl8651_drvMulticastProcessEnable && (!(((uint16)(ip->ip_off)) & (0x1fff|0x2000))))
                        {
                                local_val = _rtl8651_igmp_process(pkthdr, ip, ig);
                        }

                        goto out;
                }
        }


        if((ip->ip_ttl < 2) && (!isMulticast))
        {
                local_val=44;
                if (rtl8651_drvIcmpRoutingMsgEnable)
                {
                        uint32 netIdx;
                        if ((_rtl8651_extIpAddr(dip, &netIdx) == 0)
                                && (_rtl8651_intIpAddr(dip) == 0))
                        {

                                _rtl8651_IcmpPktField_t icmp_info;
                                icmp_info.ic_type = 11;
                                icmp_info.ic_code = 0;
                                icmp_info.ic_hun.next_mtu = 0;
                                local_val = _rtl8651_drvIcmpErrorGeneration(pkthdrPtr, ip, &icmp_info, vid);
                        }
                }
                goto out;
        }


        {
                if(!local_vlanp->internal)
                        direction=1;
        }



        {
                int32 flowBasedDsid = 0;

                pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_unnumber = 0;


                pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid = 0xff;





                if (_rtl8651_l4NaptFlowGetDSID( !direction,
                                                                                pkthdrPtr,
                                                                                ip) == 0)
                {
                        flowBasedDsid = 1;
                }

                if (!direction)
                {
                        if ( flowBasedDsid == 0 )
                        {
                                switch(pkthdrPtr->ph_proto)
                                {
                                        case 5:
                                                tc=(struct tcphdr *)l4hdr;
                                                pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid=_rtl8651_getPolicyRoutingDSID(pkthdrPtr,dip,sip,6,(tc->th_dport));
                                                break;
                                        case 6:
                                                ud=(struct udphdr *)l4hdr;
                                                pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid=_rtl8651_getPolicyRoutingDSID(pkthdrPtr,dip,sip,17,(ud->uh_dport));
                                                break;
                                        default:
                                                pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid=_rtl8651_getPolicyRoutingDSID(pkthdrPtr,dip,sip,pkthdrPtr->ph_proto,0);
                                                break;
                                }
                        }
                } else
                {
                        _rtl8651_getPolicyRoutingDSID(pkthdrPtr,0,dip,pkthdrPtr->ph_proto,0);

                        if ( flowBasedDsid == 0 )
                        {
                                pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid= _rtl8651_getpppDSID(dip);
                        }
                }
                pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_unnumber|=direction<<1;


                if (pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid == 0xff)
                {
                        do {printk(" [= !! BUG !! =] at %s line %d\n\t=> Cause: %s\n\t=>-- system Halt\n", __FUNCTION__, 3653, "dsid is not set !\n"); while(1);} while (0);;
                }
        }
# 3689 "rtl8651_tblDrvFwd.c"
        if ((((uint16)(ip->ip_off)) & (0x1fff|0x2000)))
        {
                if (rtl8651_drvFragmentProcessEnable)
                {
                        if (!_rtl8651_fragQueueProcess)
                        {
                                pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dataLen = pkthdrPtr->ph_len - ip_offset;

                                local_val = _rtl8651_ip_defrag(pkthdrPtr, ip);
                                if (local_val != -1)
                                {




                                        goto frag_out;
                                }
                        }
                }else
                {
                        local_val = 40;
                        goto out;
                }

                _rtl8651_fragQueueProcessOk = 1;

        }



        if (isMulticast == 1)
        {

                if (rtl8651_drvMulticastProcessEnable)
                {
                        local_val = _rtl8651_multicast_Fastfwd(pkthdrPtr, ip, local_vlanp);
                        if ((local_val == 0) || (local_val == 46))
                        {
                                goto out;
                        }
                }else

                {


                        local_val = 46;
                        goto out;
                }
        }


        if (pkthdrPtr->ph_proto == 5)
        {
                rtl8651_fwdEngineCounter.tcpReceive++;
                tc=(struct tcphdr *)l4hdr;
                pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_sport = (tc->th_sport);




                if((((pkthdrPtr->ph_flags) & ((0x0001)))==0))
                {
                        rtl8651_fwdEngineCounter.tcpErrorReceive++;
                        local_val=100;
                        goto out;
                }


                if(!sip || dip==0xffffffff)
                {
                        local_val = 45;
                        goto out;
                }




                if (rtl8651a_dosTcpCheck(pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid,vid,ip,&local_val,direction,
                        rtl8651_wanStatus[pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid], pkthdrPtr, 1) == 0)
                {
                        goto dos_out;
                }





                rtl8651_drvPacketFastSend = 1;
                {
                        if(local_vlanp->internal)
                                local_val = _rtl8651_l4TcpFastAliasOut(pkthdrPtr,ip);
                        else {
                                local_val = _rtl8651_l4TcpFastAliasIn(pkthdrPtr,ip);
                        }
                }
                rtl8651_drvPacketFastSend = 0;

                if (local_val == 0)
                {
                        rtl8651_fwdEngineCounter.tcpSend++;
                        goto out;
                }

                if (local_val == 132)
                {
                        goto out;
                }

                if (((local_val > 0) && (local_val & 0x1000)) || (local_val == 101))
                {
                        rtl8651_fwdEngineCounter.natdrop++;
                        local_val |= 0x1000;
                        goto out;
                }






                if (rtl8651a_dosTcpCheck(pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid,vid,ip,&local_val,direction,
                        rtl8651_wanStatus[pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid], pkthdrPtr, 0) == 0)
                {
                        goto dos_out;
                }

                _rtl8651_dosScanTracking(pkthdrPtr, ip, 6, (void*)tc);



                _rtl8651_l34Decision( pkthdrPtr,
                                                                local_vlanp,
                                                                &decision,
                                                                &srcType,
                                                                &dstType,
                                                                &optLayer);



                if (inAcl_done == 0)
                {
                        local_val = _rtl8651_ingressAcl( pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid,
                                                                                        inAcl_index,
                                                                                        local_vlanp,
                                                                                        vid,
                                                                                        m_data,
                                                                                        (uint8 *)ip,
                                                                                        0x00,
                                                                                        optLayer);

                        if (local_val & 0x1000)
                        {
                                goto out;
                        }
                        if (local_val == 2)
                        {
                                goto out;
                        }

                        inAcl_done = 1;
                }





                {
                        _rtl8651_tblDrvAclRule_t *rule_matched;

                        rule_matched = (_rtl8651_tblDrvAclRule_t *) _rtl8651_matchDiffservACL(pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid, ip);
                        if (rule_matched)
                        {
                                _rtl8651_markDiffservPkt(rule_matched, ip);
                        }
                }


                goto normal_process;
        }else if (pkthdrPtr->ph_proto == 6)
        {
                rtl8651_fwdEngineCounter.udpReceive++;
                ud=(struct udphdr *)l4hdr;
                pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_sport = (ud->uh_sport);





                if((((pkthdrPtr->ph_flags) & ((0x0001)))==0))
                {
                        rtl8651_fwdEngineCounter.udpErrorReceive++;
                        local_val = 70;
                        goto out;
                }


                if (sip == 0)
                {






                        if ((((uint16)(ip->ip_off)) & 0x1fff) ||
                                (((ud->uh_sport) != 68) && ((ud->uh_sport) != 67 )))
                        {
                                local_val = 45;
                                goto out;
                        }
                }



                if (rtl8651a_dosUdpCheck(pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid,vid,ip,&local_val,direction,
                        rtl8651_wanStatus[pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid], pkthdrPtr, 1) == 0)
                {
                        goto dos_out;
                }




                rtl8651_drvPacketFastSend = 1;
                {
                        if (local_vlanp->internal)
                                local_val = _rtl8651_l4UdpFastAliasOut(pkthdrPtr, ip);
                        else
                                local_val = _rtl8651_l4UdpFastAliasIn(pkthdrPtr, ip);
                }
                rtl8651_drvPacketFastSend = 0;

                if (local_val == 0)
                {
                        rtl8651_fwdEngineCounter.udpSend++;
                        goto out;
                }

                if (local_val == 132)
                {
                        goto out;
                }

                if ((local_val > 0) && (local_val & 0x1000))
                {
                        rtl8651_fwdEngineCounter.natdrop++;
                        goto out;
                }





                if (rtl8651a_dosUdpCheck(pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid,vid,ip,&local_val,direction,
                        rtl8651_wanStatus[pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid], pkthdrPtr, 0) == 0)
                {
                        goto dos_out;
                }

                _rtl8651_dosScanTracking(pkthdrPtr, ip, 17, (void*)ud);



                _rtl8651_l34Decision( pkthdrPtr,
                                                                local_vlanp,
                                                                &decision,
                                                                &srcType,
                                                                &dstType,
                                                                &optLayer);



                if (inAcl_done == 0)
                {
                        local_val = _rtl8651_ingressAcl( pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid,
                                                                                        inAcl_index,
                                                                                        local_vlanp,
                                                                                        vid,
                                                                                        m_data,
                                                                                        (uint8 *)ip,
                                                                                        0x00,
                                                                                        optLayer);

                        if ( ((local_val > 0) && (local_val&0x1000)) ||
                                (local_val == 2)
                        )
                        {
                                goto out;
                        }
                        inAcl_done=1;
                }

                goto normal_process;
        }else if (pkthdrPtr->ph_proto==3)
        {
                struct icmp *ic;
                do {} while (0);
                ic = (struct icmp *) l4hdr;
                pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_sport = (ic->icmp_hun.ih_idseq.icd_id);
                rtl8651_fwdEngineCounter.icmpReceive++;




                if((((pkthdrPtr->ph_flags) & ((0x0001)))==0))
                {
                        rtl8651_fwdEngineCounter.icmpErrorReceive++;
                        local_val=66;
                        goto out;
                }


                if (sip == 0)
                {
                        local_val = 45;
                        goto out;
                }



                if (rtl8651a_dosIcmpCheck(pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid,vid,ip,&local_val,direction,
                        rtl8651_wanStatus[pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid], pkthdrPtr) == 0)
                {
                        goto dos_out;
                }



                _rtl8651_l34Decision( pkthdrPtr,
                                                                local_vlanp,
                                                                &decision,
                                                                &srcType,
                                                                &dstType,
                                                                &optLayer);



                if (inAcl_done == 0)
                {
                        local_val=_rtl8651_ingressAcl( pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid,
                                                                                inAcl_index,
                                                                                local_vlanp,
                                                                                vid,
                                                                                m_data,
                                                                                (uint8 *)ip,
                                                                                0x00,
                                                                                optLayer);

                        if (((local_val > 0) && (local_val&0x1000))||(local_val==2))
                        {
                                goto out;
                        }
                        inAcl_done = 1;
                }

                if (_rtl8651_isLocalBcastAddr(vid, pkthdrPtr->ph_dip))
                {
                        _rtl8651_l2Relay(mbufPtr);
                }

                goto normal_process;
        }else if (pkthdrPtr->ph_proto == 2||pkthdrPtr->ph_proto == 1)
        {
                rtl8651_fwdEngineCounter.ipReceive++;






                if (rtl8651a_dosIpCheck(pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid,vid,ip,&local_val,direction,rtl8651_wanStatus[pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid], pkthdrPtr)
                        == 0)
                {
                        goto dos_out;
                }



                _rtl8651_l34Decision( pkthdrPtr,
                                                                local_vlanp,
                                                                &decision,
                                                                &srcType,
                                                                &dstType,
                                                                &optLayer);


                if (inAcl_done == 0)
                {
                        local_val = _rtl8651_ingressAcl( pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid,
                                                                                        inAcl_index,
                                                                                        local_vlanp,
                                                                                        vid,
                                                                                        m_data,
                                                                                        (uint8*)ip,
                                                                                        0x00,
                                                                                        optLayer);

                        if (((local_val > 0) && (local_val&0x1000))||(local_val==2))
                        {
                                goto out;
                        }
                        inAcl_done = 1;
                }


                if (_rtl8651_isLocalBcastAddr(vid, pkthdrPtr->ph_dip))
                {
                        _rtl8651_l2Relay(mbufPtr);
                }
# 4107 "rtl8651_tblDrvFwd.c"
                if (rtl8651_drvProtocolBasedNatEnable)
                {

                        if ( local_vlanp->internal )
                        {

                                ipaddr_t newExtIp;
                                if ( 0 == _rtl8651_getOutboundProtocolBasedNAT(ip_protocol, &newExtIp, sip))
                                {

                                        do{ *((uint8*)(&ip->ip_src)) = (uint8)((newExtIp)>>24); *(((uint8*)(&ip->ip_src))+1) = (uint8)((newExtIp)>>16); *(((uint8*)(&ip->ip_src))+2) = (uint8)((newExtIp)>>8); *(((uint8*)(&ip->ip_src))+3) = (uint8)((newExtIp)); }while(0);
                                        if (!(((*(uint8*)ip)&0xf) == 5))
                                        {
                                                do { do { int32 accumulate = 0; if ((((newExtIp)) != 0) && (((pkthdrPtr->ph_sip)) != 0)){ accumulate = (((pkthdrPtr->ph_sip)) & 0xffff); accumulate += (( ((pkthdrPtr->ph_sip)) >> 16 ) & 0xffff); accumulate -= (((newExtIp)) & 0xffff); accumulate -= (( ((newExtIp)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((ip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                                        }
                                        pkthdrPtr->ph_proto = 2;
                                        local_val = _rtl8651_l3ActRouting( pkthdr, pkthdrPtr->ph_dip, ip );
                                        goto out;
                                }
                        }else
                        {

                                ipaddr_t newIntIp;
                                if ( 0 == _rtl8651_getInboundProtocolBasedNAT(ip_protocol, dip, &newIntIp))
                                {

                                        do{ *((uint8*)(&ip->ip_dst)) = (uint8)((newIntIp)>>24); *(((uint8*)(&ip->ip_dst))+1) = (uint8)((newIntIp)>>16); *(((uint8*)(&ip->ip_dst))+2) = (uint8)((newIntIp)>>8); *(((uint8*)(&ip->ip_dst))+3) = (uint8)((newIntIp)); }while(0);
                                        if (!(((*(uint8*)ip)&0xf) == 5))
                                        {
                                                do { do { int32 accumulate = 0; if ((((newIntIp)) != 0) && (((pkthdrPtr->ph_dip)) != 0)){ accumulate = (((pkthdrPtr->ph_dip)) & 0xffff); accumulate += (( ((pkthdrPtr->ph_dip)) >> 16 ) & 0xffff); accumulate -= (((newIntIp)) & 0xffff); accumulate -= (( ((newIntIp)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((ip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                                        }
                                        pkthdrPtr->ph_proto = 2;
                                        local_val = _rtl8651_l3ActRouting(pkthdr, newIntIp, ip );
                                        goto out;
                                }
                        }
                }

                goto normal_process;
        }else if (pkthdrPtr->ph_proto == 4)
        {

                do {} while (0);



                if (rtl8651a_dosIpCheck(pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid,vid,ip,&local_val,direction,rtl8651_wanStatus[pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid], pkthdrPtr)
                        == 0)
                {
                        goto dos_out;
                }



                _rtl8651_l34Decision( pkthdrPtr,
                                                                local_vlanp,
                                                                &decision,
                                                                &srcType,
                                                                &dstType,
                                                                &optLayer);


                if (inAcl_done == 0)
                {
                        local_val = _rtl8651_ingressAcl( pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid,
                                                                                        inAcl_index,
                                                                                        local_vlanp,
                                                                                        vid,
                                                                                        m_data,
                                                                                        (uint8*)ip,
                                                                                        0x00,
                                                                                        optLayer);

                        if (((local_val > 0) && (local_val&0x1000))||(local_val==2))
                        {
                                goto out;
                        }
                        inAcl_done = 1;
                }

                goto normal_process;
        }


        if (inAcl_done == 0)
        {

                local_val=_rtl8651_ingressAcl( pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid,
                                                                        inAcl_index,
                                                                        local_vlanp,
                                                                        vid,
                                                                        m_data,
                                                                        (uint8*)ip,
                                                                        0x00,
                                                                        0);

                if (((local_val > 0) && (local_val&0x1000))||(local_val==2))
                {
                        goto out;
                }
                inAcl_done = 1;
        }

        local_val = 36;
        goto out;

normal_process:

        do {} while (0);



        if ( (isMulticast == 1) &&
                (rtl8651_drvMulticastProcessEnable))
        {
                local_val = _rtl8651_multicast_process(pkthdrPtr, ip);
                goto out;
        }
# 4240 "rtl8651_tblDrvFwd.c"
        if (decision == _RTL8651_DEC_NONE)
        {
                _rtl8651_l34Decision( pkthdrPtr,
                                                                local_vlanp,
                                                                &decision,
                                                                &srcType,
                                                                &dstType,
                                                                &optLayer);
        }



        local_val = 0;
        local_val = _rtl8651_l34PacketProcess(pkthdrPtr, ip, decision);
        if(local_val != 0)
        {
                rtl8651_fwdEngineCounter.l34actionLookupFailed++;
                goto out;
        }


        local_val = _rtl8651_l34ActExec(pkthdrPtr, ip, ip_protocol, decision);






        if(local_val != 0)
        {
                if ( local_val > 0 )
                {
                        if ((local_val & ~0x1000) == 130)
                        {
                                goto dos_out;
                        }
                        if ( local_val & 0x1000 )
                        {
                                rtl8651_fwdEngineCounter.l34actionFailed++;
                                goto out;
                        }
                }


                _rtl8651_drvPktDemandRouteTrigger(ip);


                if (rtl8651_drvIcmpReplyEnable && ip_protocol == 1)
                {
                        if (_rtl8651_drvIcmpAgent(pkthdrPtr,ip,vid) == 0)
                        {
                                local_val = 0;
                        }else
                        {
                                rtl8651_fwdEngineCounter.l34actionFailed++;
                        }
                        goto out;
                }




                rtl8651_fwdEngineCounter.l34actionFailed++;
                goto out;
        }

        switch (ip_protocol)
        {
                case 6:
                        rtl8651_fwdEngineCounter.tcpSend++;
                        break;
                case 17:
                        rtl8651_fwdEngineCounter.udpSend++;
                        break;
                case 1:
                        rtl8651_fwdEngineCounter.icmpSend++;
                        break;
        }
        goto out;

dos_out:
        rtl8651_fwdEngineCounter.dosDrop++;

out:


                {







                        if ( (local_val != 0) &&
                                ((local_val & 0x1000) == 0) &&
                                (_dropCases[local_val&(0x1000 -1)] == 0) &&
                                (ip)
                        )
                        {
                                int32 ps_result;
                                if ((ps_result = _rtl8651_protoStackAction_filter(pkthdrPtr, local_vlanp, ip)) != 0)
                                {
                                        local_val = ps_result;
                                }
                        }
                }


frag_out:






        rtl8651_drvPacketFastSend = 0;


        if (local_val != 0)
        {
                _rtl8651_fwdEngineRetValueStatisticUpdate(local_val);
        }



        if (local_val > 0)
        {
                if ( ((local_val & 0x1000) == 0) &&
                        (_dropCases[local_val&(0x1000 -1)]))
                {
                        local_val |= 0x1000;
                }

                if ( ((local_val & ~0x1000) == 1) &&
                        (pkthdrPtr->ph_proto!=0))
                {
                        int32 DropBit = (local_val & 0x1000);
                        _rtl8651_IcmpPktField_t icmpInfo;
                        icmpInfo.ic_type = 3;
                        icmpInfo.ic_code = 1;
                        icmpInfo.ic_hun.next_mtu = 0;
                        pkthdrPtr->ph_portlist = srcPortlist;
                        local_val = _rtl8651_drvIcmpErrorGeneration(pkthdrPtr, ip, &icmpInfo, local_vlanp->vid);
                        if (local_val != 0)
                        {
                                local_val |= DropBit;
                        }
                }

                if (local_val & 0x1000)
                {
                        mBuf_driverFreeMbufChain(pkthdrPtr->PKTHDRNXT.mbuf_first);

                        _rtl8651_fragQueueDropChain = 1;

                        local_val = 0;
                }
                if (local_val == 133)
                {
                        local_val = 0;
                }



        }
# 4419 "rtl8651_tblDrvFwd.c"
        if (local_val != 0)
        {

                {

                        uint16 category = 0;

                        if ( (ethType == 0x0800 || ((ethType == 0x8864) && (ncp = 0x0021))) &&
                                (pkthdrPtr->ph_iphdrOffset) &&
                                (!_rtl8651_fragQueueProcess))
                        {




                                category = _rtl8651_getTrappingDispatchCategory((struct ip *)(pkthdrPtr->PKTHDRNXT.mbuf_first->m_data + pkthdrPtr->ph_iphdrOffset));
                        }


                        {
                                struct rtl_pktHdr *pHdr = pkthdrPtr;

                                while (pHdr)
                                {
                                        pHdr->ph_un_sw.PS_USG.TO_PS._ph_category = category;
                                        pHdr = pHdr->ph_nextHdr;
                                }
                        }
                }



                if ( (ethType == 0x0800) &&
                      (pkthdrPtr->ph_iphdrOffset) &&
                      (!_rtl8651_fragQueueProcess))
                {






                        _rtl8651_refillHeader( local_val,
                                                                  pkthdrPtr,
                                                                  (struct ip *)(pkthdrPtr->PKTHDRNXT.mbuf_first->m_data + pkthdrPtr->ph_iphdrOffset),
                                                                  local_vlanp,
                                                                  srcPortlist);
                }







                {
                        struct rtl_pktHdr *pHdr = pkthdrPtr;
                        while (pHdr)
                        {
                                if (pHdr->ph_vlanIdx == (tunnel.loopBackVid& (8 -1)))
                                {
                                        pHdr->ph_vlanIdx = (tunnel.wanVid& (8 -1));
                                        pHdr->ph_portlist = tunnel.wanPort;
                                }

                                pHdr = pHdr->ph_nextHdr;
                        }
                }







                {
                        struct rtl_pktHdr *pHdr = pkthdrPtr;
                        rtl8651_tblDrv_vlanTable_t *srcVlan = ((void *)0);

                        while (pHdr)
                        {
                                srcVlan = &DrvTbl.vlan[pkthdrPtr->ph_vlanIdx];

                                do {} while (0);

                                if (srcVlan->fvlan_t)
                                {
                                        pHdr->ph_vlanIdx = (srcVlan->fvlan_t->vid& (8 -1));
                                }

                                pHdr = pHdr->ph_nextHdr;
                        }
                }


        }

        rtlglue_drvMutexUnlock();
        return local_val;
}
# 4531 "rtl8651_tblDrvFwd.c"
 int32 rtl8651_fwdEngineRegisterAlgModule(uint16 alg_port, uint16 isTcp,
        int32 (*alg_init)(void *),
        alg_funcptr alg_outboundClientcb,
        alg_funcptr alg_inboundClientcb,
        alg_funcptr alg_outboundServercb,
        alg_funcptr alg_inboundServercb)
{

        rtl8651_tblDrv_algEntry_t *tb;
        int8 isServer, isClient;
        int32 retval = -1;

        rtlglue_drvMutexLock();

        tb = _rtl8651_getAlgEntry(isTcp, &isServer, &isClient, alg_port, alg_port);

        if (tb)
        {
                if ( tb->fwEngAdd)
                {
                        retval = 0;
                        goto out;
                }else
                {
                        retval = -1;
                        goto out;
                }
        }
        if (alg_init && (0 != alg_init(((void *)0))))
        {
                retval = -1;
                goto out;
        }

        isClient = 1;
        isServer = 1;
        retval = rtl8651_addALGRule(alg_port, alg_port, isTcp, isServer, isClient);

        if (retval != 0)
        {
                goto out;
        }

        tb = _rtl8651_getAlgEntry(isTcp, &isServer, &isClient, alg_port, alg_port);

        do {} while (0);

        tb->fwEngAdd = 1;
        tb->alg_outboundClientcb = (alg_funcptr_t)alg_outboundClientcb;
        tb->alg_inboundClientcb = (alg_funcptr_t)alg_inboundClientcb;
        tb->alg_outboundServercb = (alg_funcptr_t)alg_outboundServercb;
        tb->alg_inboundServercb = (alg_funcptr_t)alg_inboundServercb;

        retval = 0;

out:
        rtlglue_drvMutexUnlock();

        return retval;

}
# 4600 "rtl8651_tblDrvFwd.c"
int32 rtl8651_fwdEngineRemoveAlgModule(uint16 alg_port, uint16 isTcp)
{

        rtl8651_tblDrv_algEntry_t *tb;
        int8 isServer, isClient;
        int32 retval = -1;

        rtlglue_drvMutexLock();

        tb = _rtl8651_getAlgEntry(isTcp, &isServer, &isClient, alg_port, alg_port);

        if(tb)
        {
                if( tb->fwEngAdd == 0)
                {
                        retval = -1;
                        goto out;
                }
        } else
        {
                retval = -1;
                goto out;
        }

        retval = rtl8651_delALGRule(alg_port, alg_port, isTcp, isServer, isClient);

out:
        rtlglue_drvMutexUnlock();
        return retval;
}


void _rtl8651_fwdEngineTimeUpdate(uint32 secPassed)
{


        _rtl8651_queuePacketSecondTimer();



        _rtl8651_uPnPOneSecondTimer();



        rtl8651_dosOneSecondTimer();



        _rtl8651_portBouncingTimeUpdate(secPassed);



        rtl8651_algOneSecondTimer();



        _rtl8651_fragmentShortestPathCache_timeUpdate(secPassed);



        _rtl8651_naptRedirectFlowTimeUpdate(secPassed);



        _rtl8651_fragCache_timeUpdate(secPassed);



        _rtl8651_TriggerPortTimeUpdate(secPassed);


}
# 4684 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4SeqDiff(uint32 x, uint32 y)
{





        return ((y) - (x));
}
# 4703 "rtl8651_tblDrvFwd.c"
int32 _rtl8651_l4GetDeltaSeqOut(struct ip * pip, struct tcphdr *tc, rtl8651_tblDrv_naptTcpUdpFlowEntry_t *tb)
{

        int32 i;
        int32 delta, seq_diff_min;
        uint32 seq;

        seq = ((uint32) (*((uint8*)(&tc->th_seq))<<24)|(*(((uint8*)(&tc->th_seq))+1)<<16)|(*(((uint8*)(&tc->th_seq))+2)<<8) | *(((uint8*)(&tc->th_seq))+3));

        delta = 0;
        seq_diff_min = -1;
        for (i = 0; i < 2; i++)
        {
                struct l4ack_data_record x;

                rtl8651_memcpy(&x,&tb->ack[i], sizeof(struct l4ack_data_record));

                if (x.active == 1)
                {
                        int32 seq_diff;

                        seq_diff = _rtl8651_l4SeqDiff(x.ack_old, seq);
                        if (seq_diff >= 0)
                        {
                                if (seq_diff_min >= 0)
                                {
                                        if (seq_diff < seq_diff_min)
                                        {
                                                delta = x.delta;
                                                seq_diff_min = seq_diff;
                                        }
                                }
                                else
                                {
                                        delta = x.delta;
                                        seq_diff_min = seq_diff;
                                }
                        }
                }
        }

        return (delta);
}
# 4756 "rtl8651_tblDrvFwd.c"
int32 _rtl8651_isdigit(int32 c)
{
        return (((uint32) ((c) - ('0'))) <= ((uint32) (('9')-('0'))));
}

int32 _rtl8651_isspace(int32 c )
{
        return (c==0x20) | (((uint32) ((c) - ('\t'))) <= ((uint32) (('\r')-('\t'))));
}






static uint32 _rtl8651_fragCacheInit(void)
{
        int i;


        for ( i = 0 ; i < 8 ; i ++)
        {
                _rtl8651_fragCache[i] = ((void *)0);
        }


        if (_rtl8651_max_fragCache_count)
        {
                for ( i = 0 ; i < 8 ; i ++)
                {
                        _rtl8651_fragCache[i] = (_rtl8651_frag_t *)rtlglue_malloc(sizeof(_rtl8651_frag_t) * (_rtl8651_max_fragCache_count));
                        if (_rtl8651_fragCache[i] == ((void *)0))
                                return -1;

                        memset(_rtl8651_fragCache[i], 0, (sizeof(_rtl8651_frag_t) * (_rtl8651_max_fragCache_count)));
                }
        }

        return 0;
}


static void _rtl8651_fragCacheReinit(void)
{

        int i;

        for ( i = 0 ; i < 8 ; i ++)
        {
                if (_rtl8651_fragCache[i])
                {
                        memset(_rtl8651_fragCache[i], 0, (sizeof(_rtl8651_frag_t) * (_rtl8651_max_fragCache_count)));
                }
        }
}
# 4833 "rtl8651_tblDrvFwd.c"
static inline uint32 _rtl8651_getFragCache(int32 FlowType, ipaddr_t org_sip, ipaddr_t org_dip, uint16 ip_id, ipaddr_t *newIp, int8 *routeIdx, rtl8651_tblDrv_naptTcpUdpFlowEntry_t **naptEntryp, uint8 *dsid)
{
        int i;
        _rtl8651_frag_t *cachePtr;

        do {} while (0);





        cachePtr = _rtl8651_fragCache[FlowType];

        for (i = 0 ; i < _rtl8651_max_fragCache_count ; i ++)
        {
# 4858 "rtl8651_tblDrvFwd.c"
                if ( (cachePtr[i].age > 0) &&
                        (org_sip == cachePtr[i].org_sip) &&
                        (org_dip == cachePtr[i].org_dip) &&
                        (ip_id == cachePtr[i].ip_id) )
                {






                        if (newIp)
                                *newIp = cachePtr[i].new_ip;
                        if (routeIdx)
                                *routeIdx = cachePtr[i].routeIdx;
                        if (naptEntryp)
                        {
                                if (cachePtr[i].napt_entry_t && ((rtl8651_tblDrv_naptTcpUdpFlowEntry_t*)(cachePtr[i].napt_entry_t))->alive)
                                        *naptEntryp = cachePtr[i].napt_entry_t;
                                else
                                        *naptEntryp = ((void *)0);
                        }
                        if (dsid)
                                *dsid = cachePtr[i].dsid;

                        return 0;
                }
        }





        return -1;
}
# 4906 "rtl8651_tblDrvFwd.c"
static inline _rtl8651_frag_t *_rtl8651_getFragCacheEntry(int32 FlowType, ipaddr_t org_sip, ipaddr_t org_dip, uint16 ip_id)
{
        int i;
        _rtl8651_frag_t *cachePtr;

        do {} while (0);

        cachePtr = _rtl8651_fragCache[FlowType];

        for (i = 0 ; i < _rtl8651_max_fragCache_count ; i ++)
        {
                if ( (cachePtr[i].age > 0) &&
                        (org_sip == cachePtr[i].org_sip) &&
                        (org_dip == cachePtr[i].org_dip) &&
                        (ip_id == cachePtr[i].ip_id) )
                {
                        return &cachePtr[i];
                }
        }
        return ((void *)0);
}
# 4942 "rtl8651_tblDrvFwd.c"
static inline void _rtl8651_updateFragCache(int32 FlowType, ipaddr_t org_sip, ipaddr_t org_dip, uint16 ip_id, ipaddr_t ip_addr, int8 routeIdx, rtl8651_tblDrv_naptTcpUdpFlowEntry_t *naptEntry, uint8 dsid)
{
        int i;
        _rtl8651_frag_t *cachePtr;
        _rtl8651_frag_t *entryToAdd;
        uint32 minAge = _rtl8651_max_fragCache_age + 1;

        do {} while (0);
        do {} while (0);







        cachePtr = _rtl8651_getFragCacheEntry(FlowType, org_sip, org_dip, ip_id);
        if (cachePtr)
        {
# 4970 "rtl8651_tblDrvFwd.c"
                cachePtr->age = _rtl8651_max_fragCache_age;

                cachePtr->new_ip = ip_addr;
                cachePtr->routeIdx = routeIdx;
                cachePtr->napt_entry_t = naptEntry;
                cachePtr->dsid = dsid;

                return;
        }


        cachePtr = _rtl8651_fragCache[FlowType];
        entryToAdd = ((void *)0);





        for ( i = 0 ; i < _rtl8651_max_fragCache_count ; i ++ )
        {
                if (cachePtr[i].age == 0)
                {
                        entryToAdd = &cachePtr[i];





                        goto found;
                }
                if (cachePtr[i].age < minAge)
                {
                        entryToAdd = &cachePtr[i];
                        minAge = cachePtr[i].age;





                }
        }




found:
        do {} while (0);

        entryToAdd->age = _rtl8651_max_fragCache_age;

        entryToAdd->org_sip = org_sip;
        entryToAdd->org_dip = org_dip;
        entryToAdd->ip_id = ip_id;

        entryToAdd->new_ip = ip_addr;
        entryToAdd->routeIdx = routeIdx;
        entryToAdd->napt_entry_t = naptEntry;
        entryToAdd->dsid = dsid;

        return;
}


void _rtl8651_fragCache_timeUpdate(uint32 secPassed)
{
        int i;
        _rtl8651_frag_t *cachePtr;

        for ( i = 0 ; i < 8 ; i ++)
        {
                cachePtr = _rtl8651_fragCache[i];
                if (cachePtr)
                {
                        int j;
                        for ( j = 0 ; j < _rtl8651_max_fragCache_count ; j ++ )
                        {
                                if (cachePtr[j].age > secPassed)
                                        cachePtr[j].age -= secPassed;
                                else
                                {





                                        cachePtr[j].age = 0;
                                }
                        }
                }
        }
}
# 5072 "rtl8651_tblDrvFwd.c"
static int32 _rtl8651_pktAccessGateway (ipaddr_t srcIpAddr, ipaddr_t dstIpAddr, uint16 vid)
{
        uint32 natIdx;

        if (_rtl8651_extIpAddr(dstIpAddr, &natIdx) == 1)
        {
                goto true;
        }else if (_rtl8651_intIpAddr(dstIpAddr) == 1)
        {
                rtl8651_tblDrv_vlanTable_t *vlanp;

                vlanp = &DrvTbl.vlan[vid & (8 - 1)];

                if ((vlanp->internal) && (_rtl8651_intNetIpAddr(srcIpAddr) == 1))
                {
                        goto true;
                }
        }

        return 0;
true:
        return 1;
}




static int32 _rtl8651_l2Relay(struct rtl_mBuf *inMbufPtr)
{
        struct rtl_pktHdr *phdr;

        phdr = inMbufPtr->m_pkthdr;


        if (DrvTbl.vlan[phdr->ph_vlanIdx].vid == tunnel.loopBackVid)
        {




        } else
        {

                struct rtl_mBuf *mbufPtr;
                int32 retval;

                mbufPtr = mBuf_dupPacket(inMbufPtr, 0x02);

                if(mbufPtr == ((void *)0))
                {



                        return -1;
                }


                mbufPtr->m_pkthdr->ph_flags &= (~(0x0002 | 0x0001));

                mbufPtr->m_pkthdr->ph_portlist = DrvTbl.vlan[phdr->ph_vlanIdx].memberPortUpStatus & ~(1<<phdr->ph_portlist);
                retval = _rtl8651_fwdEngineSend(((uint32)(1)<<1), (void*)mbufPtr->m_pkthdr, DrvTbl.vlan[phdr->ph_vlanIdx].vid, -1);

                if (retval != 0)
                {
                        mBuf_driverFreeMbufChain(mbufPtr);
                }


        }


        return 0;
}


static int32 _rtl8651_drvArpGeneration(ipaddr_t ipAddr)
{
        uint32 natIdx;
        int32 retval;
        int8 *bufptr;
        ether_addr_t macAddr;
        rtl8651_tblDrv_networkIntfTable_t * netIntfPtr;
        rtl8651_tblDrv_ipIntfEntry_t * ipIntfPtr;
        struct rtl_mBuf *mbufPtr;

        if(_rtl8651_intNetIpAddr(ipAddr) == 0 && _rtl8651_extNetIpAddr(ipAddr, &natIdx) == 0)
                return -1;
        if(_rtl8651_getArpEntry(((void *)0), ipAddr, 1) != ((void *)0))
                return -1;
        if((netIntfPtr = _rtl8651_getNetworkIntfEntryByAddr(ipAddr)) == ((void *)0))
                return -1;
        if((ipIntfPtr = _rtl8651_getIpIntfEntryByAddr(ipAddr)) == ((void *)0))
                return -1;
        if((mbufPtr = mBuf_get(0x02, 0x01, 1)) == ((void *)0))
                return -1;
        if(mBuf_getPkthdr(mbufPtr, 0x02) == (struct rtl_mBuf *) ((void *)0))
        {
                mBuf_freeMbufChain(mbufPtr);
                return -1;
        }

        mbufPtr->m_data = (void *)rtlglue_mbufClusterToData(mbufPtr->m_data);

        if (mBuf_reserve(mbufPtr,rtl8651_fwdEnginePara.mbufHeadroom))
        {
                mBuf_freeMbufChain(mbufPtr);
                return -1;
        }
        bufptr=(int8 *)mbufPtr->m_data;

        memset(bufptr,0xff, 6);
        rtl8651_getVlanMacAddress(netIntfPtr->vid, &macAddr, ((void *)0));

        rtl8651_memcpy(bufptr + 6,(int8 *)&macAddr.octet[0],6);

        *(uint32 *)(bufptr + 12) = (0x08060001);
        *(uint32 *)(bufptr + 16) = (0x08000604);
        *(uint16 *)(bufptr + 20) = (0x0001);
        rtl8651_memcpy(bufptr + 22,(int8 *)&macAddr.octet[0],6);
        *(uint32 *)(bufptr + 28) = (ipIntfPtr->ipAddr.slh_first->ipAddr);
        *(uint32 *)(bufptr + 32) = (0x0);
        *(uint16 *)(bufptr + 36) = (0x0);
        do{ *((uint8*)(bufptr+38)) = (uint8)((ipAddr)>>24); *(((uint8*)(bufptr+38))+1) = (uint8)((ipAddr)>>16); *(((uint8*)(bufptr+38))+2) = (uint8)((ipAddr)>>8); *(((uint8*)(bufptr+38))+3) = (uint8)((ipAddr)); }while(0);

        mbufPtr->m_len = 60;
        mbufPtr->m_pkthdr->ph_len = 60;
        mbufPtr->m_pkthdr->ph_portlist = (DrvTbl.vlan[netIntfPtr->vid&(8 -1)].memberPortMask);
        retval = _rtl8651_fwdEngineSend(((uint32)(1)<<1), (void*)mbufPtr->m_pkthdr,netIntfPtr->vid,-1 );
        if(retval == 0)
        {
                rtl8651_fwdEngineCounter.arpGenerate++;
        }else
        {
                mBuf_driverFreeMbufChain(mbufPtr);
        }
        return 0;
}


static int32 _rtl8651_drvArpAgent(struct rtl_pktHdr *pkthdrPtr, struct rtl_mBuf *mbufPtr, uint16 vid)
{
        ipaddr_t srcIpAddr, dstIpAddr;
        int8 *bufptr;
        int32 retval;
        ether_addr_t macAddr;
        rtl8651_tblDrv_networkIntfTable_t * netIntfPtr;
        uint32 dummy = 14;
        uint32 etherTypePosition = 12;

        rtl8651_fwdEngineCounter.arpReceive++;
        mbufPtr = pkthdrPtr->PKTHDRNXT.mbuf_first;

        if ((netIntfPtr = _rtl8651_getNetworkIntfEntryByVid(vid)) == ((void *)0))
        {
                return 30;
        }

        bufptr = (int8 *)mbufPtr->m_data;

        if (_getEthTypeIpOffset(pkthdrPtr, bufptr, &etherTypePosition, &dummy, &dummy) != 0)
        {
                do {} while (0);
                return 0x1000;
        }


        memcpy(&macAddr, (bufptr+etherTypePosition+10),6);
        srcIpAddr = ((uint32) (*((uint8*)(bufptr+(etherTypePosition+16)))<<24)|(*(((uint8*)(bufptr+(etherTypePosition+16)))+1)<<16)|(*(((uint8*)(bufptr+(etherTypePosition+16)))+2)<<8) | *(((uint8*)(bufptr+(etherTypePosition+16)))+3));

        if (srcIpAddr == 0)
        {
                return 0x1000;
        }

        if (_rtl8651_addLocalArp(1, srcIpAddr, &macAddr, netIntfPtr, pkthdrPtr->ph_portlist) == 0)
        {
                rtl8651_fwdEngineCounter.arpAddSuccess++;


                {
                        struct rtl_pktHdr * q_pkt;
                        struct ip *local_ip_p;
                        uint32 local_dst_ip;
                        int32 local_cnt = 0;
                        struct ip fake_ip;
                        fake_ip.ip_dst.s_addr = srcIpAddr;

                        while (1)
                        {
                                local_cnt++;
                                if (local_cnt > 32)
                                {
                                        _rtl8651_queuePacketSecondTimer();
                                        break;
                                }
                                q_pkt = _rtl8651_queryQuenePacket(&fake_ip, 1, &local_dst_ip, &local_ip_p);
                                if (q_pkt == ((void *)0))
                                {
                                        break;
                                }

                                if (_rtl8651_l3ActRouting(q_pkt, local_dst_ip, local_ip_p) != 0)
                                {
                                        mBuf_freeMbufChain(q_pkt->PKTHDRNXT.mbuf_first);
                                }
                        }
                }


        }else
        {
                rtl8651_fwdEngineCounter.arpAddFail ++;
        }

        if (*(uint16 *)(bufptr + (etherTypePosition+8)) == (0x1))
        {


                srcIpAddr = ((uint32) (*((uint8*)(bufptr + (etherTypePosition + 16)))<<24)|(*(((uint8*)(bufptr + (etherTypePosition + 16)))+1)<<16)|(*(((uint8*)(bufptr + (etherTypePosition + 16)))+2)<<8) | *(((uint8*)(bufptr + (etherTypePosition + 16)))+3));
                dstIpAddr = ((uint32) (*((uint8*)(bufptr + (etherTypePosition + 26)))<<24)|(*(((uint8*)(bufptr + (etherTypePosition + 26)))+1)<<16)|(*(((uint8*)(bufptr + (etherTypePosition + 26)))+2)<<8) | *(((uint8*)(bufptr + (etherTypePosition + 26)))+3));






                if (_rtl8651_pktAccessGateway(srcIpAddr, dstIpAddr, vid) == 0)
                {

                        if (rtl8651_drvArpProxyProcessEnable)
                        {
                                rtl8651_tblDrv_vlanTable_t *vlanp;
                                vlanp = &DrvTbl.vlan[vid & (8 - 1)];
                                if (vlanp->internal)
                                {
                                        rtl8651_tblDrv_routeTable_t *rt;
                                        rt = _rtl8651_getRoutingEntry(dstIpAddr);
                                        if ((rt == ((void *)0)) || (rt->dvid != vid))
                                        {
                                                goto send_reply;
                                        }
                                }
                        }
                        return 16;
                }

                if (!rtl8651_drvArpProcessEnable)
                {
                        return 17;
                }

send_reply:

                {
                        struct rtl_mBuf *mbuf_arpReply = ((void *)0);
                        struct rtl_pktHdr *pkthdr_arpReply = ((void *)0);
                        uint8 *bufptr_reply;
# 5338 "rtl8651_tblDrvFwd.c"
                        if ((mbuf_arpReply = mBuf_dupPacket(pkthdrPtr->PKTHDRNXT.mbuf_first, 0x02)) == ((void *)0) )
                        {
                                retval = -1;
                                goto reply_out;
                        }

                        pkthdr_arpReply = mbuf_arpReply->m_pkthdr;
                        bufptr_reply = mbuf_arpReply->m_data;

                        rtl8651_memcpy((bufptr_reply + (etherTypePosition+20)), (bufptr_reply + (etherTypePosition+10)), 10);
                        *(uint16 *)(bufptr_reply + (etherTypePosition+8)) = (0x2);
                        rtl8651_memcpy(bufptr_reply, (bufptr_reply + 6), 6);
                        rtl8651_getVlanMacAddress(vid, &macAddr, ((void *)0));
                        rtl8651_memcpy((bufptr_reply+6), ((int8 *)&macAddr.octet[0]), 6);
                        rtl8651_memcpy((bufptr_reply+(etherTypePosition+10)), ((int8 *)&macAddr.octet[0]), 6);
                        do{ *((uint8*)((bufptr_reply+(etherTypePosition+16)))) = (uint8)((dstIpAddr)>>24); *(((uint8*)((bufptr_reply+(etherTypePosition+16))))+1) = (uint8)((dstIpAddr)>>16); *(((uint8*)((bufptr_reply+(etherTypePosition+16))))+2) = (uint8)((dstIpAddr)>>8); *(((uint8*)((bufptr_reply+(etherTypePosition+16))))+3) = (uint8)((dstIpAddr)); }while(0);


                        pkthdr_arpReply->ph_portlist = (1 << pkthdr_arpReply->ph_portlist);

                        retval = _rtl8651_fwdEngineSend(((uint32)(1)<<1), (void*)pkthdr_arpReply, vid, -1);

reply_out:

                        if ( retval == 0 )
                        {
                                rtl8651_fwdEngineCounter.arpReply ++;
                        } else
                        {
                                if ( mbuf_arpReply )
                                {
                                        mBuf_driverFreeMbufChain( mbuf_arpReply );
                                }
                        }


                        mBuf_driverFreeMbufChain( pkthdrPtr->PKTHDRNXT.mbuf_first );


                        return 0;
                }
        }
        return 15;
}


int32 _rtl8651_drvIcmpErrorGeneration(struct rtl_pktHdr *pkthdrPtr, struct ip* ip, _rtl8651_IcmpPktField_t *icmp_info, uint16 vid) {
        rtl8651_tblDrv_networkIntfTable_t * netIntf;
        rtl8651_tblDrv_ipIntfEntry_t *ipIntf;
        int8 org_pkt[((ip->ip_vhl&0xf)<<2) + 8];
        uint16 org_pkt_len;
        struct icmp *ic;
        ipaddr_t sip;
        void *macHdr;
        ether_addr_t macAddr;
        int32 retval;
        uint16 trailer_len;
        uint16 icmp_ip_len;
        uint16 icmp_total_len;

        switch (icmp_info->ic_type)
        {
                case 11:
                case 3:
                        break;
                default:
                        return -1;
        }



        netIntf = _rtl8651_getNetworkIntfEntryByVid(vid);
        if ((netIntf == ((void *)0)) ||(netIntf->valid == 0) || (((&netIntf->IpHead)->slh_first) == ((void *)0)))
        {
                return -1;
        }
        ipIntf = ((&netIntf->IpHead)->slh_first);
        sip =ipIntf->ipAddr.slh_first->ipAddr;




        {
                uint16 org_iphdr_len = (ip->ip_vhl&0xf)<<2;
                uint16 org_ip_len = (ip->ip_len);

                if ((org_ip_len - org_iphdr_len) > 8)
                {
                        org_pkt_len = org_iphdr_len + 8;
                        trailer_len = 0;
                }else
                {
                        org_pkt_len = org_ip_len;
                        trailer_len = 8 - (org_ip_len - org_iphdr_len);
                }
        }
        icmp_ip_len = 20 + 8 + org_pkt_len + trailer_len;
        memset(org_pkt, 0, org_pkt_len);
        rtl8651_memcpy(org_pkt, ip, org_pkt_len);


        icmp_total_len = pkthdrPtr->ph_iphdrOffset + icmp_ip_len;
        {
                uint16 org_total_len = pkthdrPtr->ph_len;
                if (org_total_len > icmp_total_len)
                {
                        mBuf_adjTail(pkthdrPtr->PKTHDRNXT.mbuf_first, (uint32)(org_total_len - icmp_total_len));
                }else
                {
                        pkthdrPtr->ph_len = icmp_total_len;
                        pkthdrPtr->PKTHDRNXT.mbuf_first->m_len = icmp_total_len;
                }
        }




        ic = (struct icmp *)((uint32)ip + 20);
        ic->icmp_type = icmp_info->ic_type;
        ic->icmp_code = icmp_info->ic_code;
        if (icmp_info->ic_hun.next_mtu)
        {
                ic->icmp_hun.ih_pmtu.ipm_void = 0;
                ic->icmp_hun.ih_pmtu.ipm_nextmtu = (icmp_info->ic_hun.next_mtu);
        }else
        {
                do{ *((uint8*)(&ic->icmp_hun.ih_void)) = (uint8)(((uint32)0)>>24); *(((uint8*)(&ic->icmp_hun.ih_void))+1) = (uint8)(((uint32)0)>>16); *(((uint8*)(&ic->icmp_hun.ih_void))+2) = (uint8)(((uint32)0)>>8); *(((uint8*)(&ic->icmp_hun.ih_void))+3) = (uint8)(((uint32)0)); }while(0);
        }
        rtl8651_memcpy(&ic->icmp_dun.id_ip.idi_ip, org_pkt, org_pkt_len);

        if (trailer_len)
        {
                memset((void*)((uint32)ip + (uint32)icmp_ip_len - (uint32)trailer_len), 0, trailer_len);
        }



        ip->ip_vhl = 0x45;
        ip->ip_tos = 0;
        ip->ip_len = (icmp_ip_len);
        ip->ip_off = 0;
        ip->ip_ttl = 0x80;
        ip->ip_p = 1;

        rtl8651_memcpy(&ip->ip_dst, &ip->ip_src, 4);
        do{ *((uint8*)(&ip->ip_src)) = (uint8)((sip)>>24); *(((uint8*)(&ip->ip_src))+1) = (uint8)((sip)>>16); *(((uint8*)(&ip->ip_src))+2) = (uint8)((sip)>>8); *(((uint8*)(&ip->ip_src))+3) = (uint8)((sip)); }while(0);




        pkthdrPtr->ph_proto = 3;
        pkthdrPtr->ph_flags |= 0x0001;
        pkthdrPtr->ph_flags |= 0x0002;




        if( pkthdrPtr->ph_pppeTagged)
        {
                int8 tmpEther[14];

                rtl8651_memcpy(tmpEther, pkthdrPtr->PKTHDRNXT.mbuf_first->m_data, 14);

                mBuf_adjHead(pkthdrPtr->PKTHDRNXT.mbuf_first, 8);

                rtl8651_memcpy(pkthdrPtr->PKTHDRNXT.mbuf_first->m_data, tmpEther, 14);

                do{ *((uint8*)((pkthdrPtr->PKTHDRNXT.mbuf_first->m_data + 12))) = (uint8)(((uint16)0x0800)>>8); *(((uint8*)((pkthdrPtr->PKTHDRNXT.mbuf_first->m_data + 12)))+1) = (uint8)(0x0800); }while(0);

                pkthdrPtr->ph_pppeTagged = 0;
        }

        if (netIntf->linkLayerType == 0x02)
        {

                pkthdrPtr->ph_flags &= 0x0008;
        }


        macHdr = pkthdrPtr->PKTHDRNXT.mbuf_first->m_data;
        rtl8651_memcpy(&macAddr, macHdr,6);
        rtl8651_memcpy(macHdr,macHdr+6,6);
        rtl8651_memcpy(macHdr+6,&macAddr,6);

        pkthdrPtr->ph_portlist = (1<<pkthdrPtr->ph_portlist);
        retval=_rtl8651_fwdEngineSend(((uint32)(1)<<1), (void*)pkthdrPtr, vid,-1);

        if(retval==0)
        {
                rtl8651_fwdEngineCounter.icmpReply++;
        }else
        {
                mBuf_driverFreeMbufChain(pkthdrPtr->PKTHDRNXT.mbuf_first);
                rtl8651_fwdEngineCounter.icmpReplyFailed++;
        }
        return 0;
}

static inline int32 _rtl8651_drvIcmp(struct rtl_pktHdr *pkthdrPtr, struct ip* ip, struct icmp *icmp, uint16 vid) {
        rtl8651_tblDrv_networkIntfTable_t *netintf;
        ether_addr_t macAddr;
        ipaddr_t ipAddr;
        uint8 *cp = pkthdrPtr->PKTHDRNXT.mbuf_first->m_data;
        int32 retval, tol_len;
        uint32 mtu;
        uint8 ttl;
        uint16 srcPortList;
        ipaddr_t sip = ((uint32) (*((uint8*)(&ip->ip_src))<<24)|(*(((uint8*)(&ip->ip_src))+1)<<16)|(*(((uint8*)(&ip->ip_src))+2)<<8) | *(((uint8*)(&ip->ip_src))+3));
        ipaddr_t dip = ((uint32) (*((uint8*)(&ip->ip_dst))<<24)|(*(((uint8*)(&ip->ip_dst))+1)<<16)|(*(((uint8*)(&ip->ip_dst))+2)<<8) | *(((uint8*)(&ip->ip_dst))+3));

        if ((ip->ip_off) & (0x1fff))
        {
                if (_rtl8651_getFragCache(3, sip, dip, (ip->ip_id), ((void *)0), ((void *)0), ((void *)0), &(pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid)) == 0)
                {
                        goto proc_icmp;
                }else
                {
                        return -1;
                }
        }

        switch (icmp->icmp_type)
        {
                case 8:
                        break;
                default:
                        return -1;
        }

proc_icmp:



        if (tunnel.valid && vid == tunnel.loopBackVid && pkthdrPtr->ph_portlist == tunnel.loopbackPort) {
                netintf = _rtl8651_getNetworkIntfEntryByVid(tunnel.wanVid);
        }else

        {
                netintf = _rtl8651_getNetworkIntfEntryByVid(vid);
        }
        if ((netintf == ((void *)0)) || (netintf->valid == 0) )
        {
                return -1;
        }
# 5590 "rtl8651_tblDrvFwd.c"
        mtu = netintf->mtu;
        tol_len=mBuf_getPktlen(pkthdrPtr->PKTHDRNXT.mbuf_first);


        rtl8651_memcpy(&macAddr, cp,6);
        rtl8651_memcpy(cp,cp+6,6);
        rtl8651_memcpy(cp+6,&macAddr,6);


        rtl8651_memcpy(&ipAddr, &ip->ip_src, 4);
        rtl8651_memcpy(&ip->ip_src, &ip->ip_dst, 4);
        rtl8651_memcpy(&ip->ip_dst, &ipAddr, 4);

        ttl = ip->ip_ttl;
        ip->ip_ttl = 0x80;

        if (!((ip->ip_off) & 0x1fff))
        {
                icmp->icmp_type = 0;
        }

        pkthdrPtr->ph_flags |= (0x0002|0x0001);
        if (((ip->ip_off) & (0x2000|0x1fff)) || ((ip->ip_vhl & 0x0f) != 5))
        {
                if ((ip->ip_vhl & 0x0f) != 5)
                {
                        pkthdrPtr->ph_flags &= ~0x0002;
                        do { int32 accumulate; accumulate = (((ttl << 8)) - ((ip->ip_ttl << 8))); do { accumulate += ((ip->ip_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ip->ip_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ip->ip_sum) = ((uint16) accumulate); } } while (0); } while(0);
                }
                if (!((ip->ip_off) & 0x1fff))
                {
                        do { int32 accumulate; accumulate = (((8<<8)) - ((0<<8))); do { accumulate += ((icmp->icmp_cksum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (icmp->icmp_cksum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (icmp->icmp_cksum) = ((uint16) accumulate); } } while (0); } while(0);
                        if ((ip->ip_off) & 0x2000)
                        {
                                _rtl8651_updateFragCache(3, sip, dip, (ip->ip_id), (ipaddr_t)(ipAddr), 0, ((void *)0), pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid);
                        }
                }
                pkthdrPtr->ph_flags &= ~0x0001;
                pkthdrPtr->ph_proto = 2;
        }

        pkthdrPtr->ph_flags |= 0x0002;

        srcPortList = pkthdrPtr->ph_portlist;
        pkthdrPtr->ph_portlist = (1<<pkthdrPtr->ph_portlist);

        if (tol_len > (mtu+14))
        {
                int8 old_IcmpRoutingMsgEnable = rtl8651_drvIcmpRoutingMsgEnable;
                rtl8651_drvIcmpRoutingMsgEnable = 0;
                retval = _rtl8651_mtuFragment(((uint32)(1)<<1), pkthdrPtr, mtu, vid, 0, srcPortList);
                rtl8651_drvIcmpRoutingMsgEnable = old_IcmpRoutingMsgEnable;
        }else
                retval=_rtl8651_fwdEngineSend(((uint32)(1)<<1), (void*)pkthdrPtr, vid,-1);

        if(retval==0)
        {
                rtl8651_fwdEngineCounter.icmpReply++;
                return 0;
        }
        else
        {
                rtl8651_fwdEngineCounter.icmpReplyFailed++;
                rtl8651_fwdEngineCounter.icmpDrop++;
                return 0x1000;
        }
}






static inline int32 _rtl8651_drvPktDemandRouteTrigger(struct ip *pip)
{
        if (rtl8651_drvPktDemandRouteTrigger != 1)
        {
                return 0;
        }

        {





                if (!(((uint16)(pip->ip_off)) & 0x1fff))
                {
                        switch (pip->ip_p)
                        {
                                case 6:
                                {
                                        struct tcphdr *tc;
                                        ipaddr_t dip = ((uint32) (*((uint8*)(&pip->ip_dst))<<24)|(*(((uint8*)(&pip->ip_dst))+1)<<16)|(*(((uint8*)(&pip->ip_dst))+2)<<8) | *(((uint8*)(&pip->ip_dst))+3));

                                        tc = (struct tcphdr *)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));

                                        if ((tc->th_dport) == 53)
                                        {
                                                _rtl8651_getDemandRoutingEntry(0, dip, 6, (tc->th_dport));
                                        }
                                }
                                        break;
                                case 17:
                                {
                                        struct udphdr *ud;
                                        ipaddr_t dip = ((uint32) (*((uint8*)(&pip->ip_dst))<<24)|(*(((uint8*)(&pip->ip_dst))+1)<<16)|(*(((uint8*)(&pip->ip_dst))+2)<<8) | *(((uint8*)(&pip->ip_dst))+3));

                                        ud = (struct udphdr *)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));

                                        if ((ud->uh_dport) == 53)
                                        {
                                                _rtl8651_getDemandRoutingEntry(0, dip, 17, (ud->uh_dport));
                                        }
                                }
                        }
                }
        }

        return 0;
}

static int32 _rtl8651_drvIcmpAgent(struct rtl_pktHdr * pkthdrPtr, struct ip* ip, uint16 vid)
{

        if (_rtl8651_pktAccessGateway(pkthdrPtr->ph_sip, pkthdrPtr->ph_dip, vid) != 1)
        {
                return -1;
        }







        return _rtl8651_drvIcmp(pkthdrPtr, ip, (struct icmp *)((uint8 *)ip + (((*(uint8*)ip)&0xf) << 2)), vid);
}

int32 _rtl8651_ingressAcl(uint32 dsid, uint32 startIdx, rtl8651_tblDrv_vlanTable_t *pVlan, int32 vid, uint8 *m_data, uint8 *ip, uint32 matchType, uint32 optLayer){
        _rtl8651_tblDrvAclRule_t *acl_tb;
        rtl8651_tblDrv_networkIntfTable_t *netif_tb;
        int8 defPermit = 1;
        struct ip *pip=(struct ip*)ip;

        netif_tb = _rtl8651_getNetworkIntfEntryByVid(vid);
        if(netif_tb){
                acl_tb = _rtl8651_aclLookUp(dsid, netif_tb, 1, startIdx, (int8 *)m_data, (int8*)ip,&defPermit, matchType, optLayer);
                if(acl_tb){
                        switch(acl_tb->actionType_){
                                case 0x01:
                                        rtl8651_fwdEngineCounter.inAclPermit++;
                                        return 0;
                                case 0x02:
                                        rtl8651_fwdEngineCounter.inAclDrop++;
                                        return 3|0x1000;
                                case 0x04:
                                        rtl8651_fwdEngineCounter.inAclDrop++;
                                        if ( (_loggingModule[dsid]&0x00000002)
                                                && _pUserLoggingFunc
                                                && ip

                                                && (_rtl8651_acl_drop_nolog[dsid]==0)

                                        ){

                                                rtl8651_logInfo_t info;
                                                struct tcphdr *tc = ((void *)0);
                                                struct udphdr *ud = ((void *)0);
                                                struct icmp *ic = ((void *)0);
                                                uint16 sport = 0xffff;
                                                uint16 dport = 0xffff;
                                                uint8 type = 0xff;
                                                uint16 id = 0xffff;

                                                if (!(((uint16)(pip->ip_off)) & 0x1fff))
                                                {
                                                        switch(pip->ip_p)
                                                        {
                                                                case 6:
                                                                        tc = (struct tcphdr *) ((int8 *) ip + ((*(uint8*)ip&0xf) << 2));
                                                                        sport = (tc->th_sport);
                                                                        dport = (tc->th_dport);
                                                                        break;
                                                                case 17:
                                                                        ud = (struct udphdr *) ((int8 *) ip + ((*(uint8*)ip&0xf) << 2));
                                                                        sport = (ud->uh_sport);
                                                                        dport = (ud->uh_dport);
                                                                        break;
                                                                case 1:
                                                                        ic = (struct icmp *) ((int8 *) ip + ((*(uint8*)ip&0xf) << 2));
                                                                        type = ic->icmp_type;
                                                                        id = (ic->icmp_hun.ih_idseq.icd_id);
                                                                        break;
                                                        }
                                                }

                                                info.infoType = 1;
                                                info.un.pkt.dsid = dsid;
                                                info.un.pkt.sip = ((uint32) (*((uint8*)(&pip->ip_src))<<24)|(*(((uint8*)(&pip->ip_src))+1)<<16)|(*(((uint8*)(&pip->ip_src))+2)<<8) | *(((uint8*)(&pip->ip_src))+3));
                                                info.un.pkt.dip = ((uint32) (*((uint8*)(&pip->ip_dst))<<24)|(*(((uint8*)(&pip->ip_dst))+1)<<16)|(*(((uint8*)(&pip->ip_dst))+2)<<8) | *(((uint8*)(&pip->ip_dst))+3));
                                                info.un.pkt.protocol = pip->ip_p;
                                                info.un.pkt.direction = (pVlan->internal?0:1);
                                                info.un.pkt.sport = sport;
                                                info.un.pkt.dport = dport;
                                                info.un.pkt.icmpType = type;
                                                info.un.pkt.icmpId = id;
                                                info.action = 1;
                                                (* _pUserLoggingFunc)(0x00000002, 6, &info);
# 5819 "rtl8651_tblDrvFwd.c"
                                        }
                                        return (3|0x1000);
                                case 0x03:
                                        rtl8651_fwdEngineCounter.inAclCpu++;
                                        return 2;
                                case 0x05:
                                        rtl8651_fwdEngineCounter.inAclDrop++;
                                        return (1|0x1000);
                                case 0x06:
                                case 0x07:

                                        rtl8651_fwdEngineCounter.inAclDrop++;
                                        return 3|0x1000;
                                default:
                                        if(defPermit != 1){
                                                rtl8651_fwdEngineCounter.inAclDrop++;
                                                return 3|0x1000;
                                        }else{
                                                rtl8651_fwdEngineCounter.inAclPermit++;
                                                return 0;
                                        }
                        }
                }

                else {

                        int8 defAction;
                        int32 ret;
                        ret=_rtl8651_getDefaultAcl(netif_tb->ifName,&defAction);
                        do {} while (0);
                        switch(defAction){
                                case 0x06:
                                case 0x02:

                                        rtl8651_fwdEngineCounter.inAclDrop++;
                                        return 3|0x1000;
                                case 0x04:

                                        rtl8651_fwdEngineCounter.inAclDrop++;
                                        if (
                                                (_loggingModule[dsid]&0x00000002)
                                                &&_pUserLoggingFunc
                                                && ip
                                        )
                                        {

                                                rtl8651_logInfo_t info;
                                                struct tcphdr *tc = ((void *)0);
                                                struct udphdr *ud = ((void *)0);
                                                struct icmp *ic = ((void *)0);
                                                uint16 sport = 0xffff;
                                                uint16 dport = 0xffff;
                                                uint8 type = 0xff;
                                                uint16 id = 0xffff;

                                                if (!(((uint16)(pip->ip_off)) & 0x1fff))
                                                {
                                                        switch(pip->ip_p)
                                                        {
                                                                case 6:
                                                                        tc = (struct tcphdr *) ((int8 *) ip + ((*(uint8*)ip&0xf) << 2));
                                                                        sport = (tc->th_sport);
                                                                        dport = (tc->th_dport);
                                                                        break;
                                                                case 17:
                                                                        ud = (struct udphdr *) ((int8 *) ip + ((*(uint8*)ip&0xf) << 2));
                                                                        sport = (ud->uh_sport);
                                                                        dport = (ud->uh_dport);
                                                                        break;
                                                                case 1:
                                                                        ic = (struct icmp *) ((int8 *) ip + ((*(uint8*)ip&0xf) << 2));
                                                                        type = ic->icmp_type;
                                                                        id = (ic->icmp_hun.ih_idseq.icd_id);
                                                                        break;
                                                        }
                                                }

                                                info.infoType = 1;
                                                info.un.pkt.dsid = dsid;
                                                info.un.pkt.sip = ((uint32) (*((uint8*)(&pip->ip_src))<<24)|(*(((uint8*)(&pip->ip_src))+1)<<16)|(*(((uint8*)(&pip->ip_src))+2)<<8) | *(((uint8*)(&pip->ip_src))+3));
                                                info.un.pkt.dip = ((uint32) (*((uint8*)(&pip->ip_dst))<<24)|(*(((uint8*)(&pip->ip_dst))+1)<<16)|(*(((uint8*)(&pip->ip_dst))+2)<<8) | *(((uint8*)(&pip->ip_dst))+3));
                                                info.un.pkt.protocol = pip->ip_p;
                                                info.un.pkt.direction = (pVlan->internal?0:1);
                                                info.un.pkt.sport = sport;
                                                info.un.pkt.dport = dport;
                                                info.un.pkt.icmpType = type;
                                                info.un.pkt.icmpId = id;
                                                info.action = 1;
                                                (* _pUserLoggingFunc)(0x00000002, 6, &info);
# 5926 "rtl8651_tblDrvFwd.c"
                                        }
                                        return 3|0x1000;
                                case 0x01:

                                        rtl8651_fwdEngineCounter.inAclPermit++;
                                        return 0;
                                case 0x03:

                                        rtl8651_fwdEngineCounter.inAclPermit++;
                                        return 0;
                                default:
                                        do {} while (0);
                                        break;
                        }
                }

        }
        return 0;
}

int32 _rtl8651_egressAcl(uint32 dsid,rtl8651_tblDrv_vlanTable_t *pVlan,int32 vid, uint8 *ethHdr, uint8 *ip){
        _rtl8651_tblDrvAclRule_t *acl_tb;
        rtl8651_tblDrv_networkIntfTable_t *netif_tb;
        int8 defPermit = 1;
        struct ip *pip=(struct ip*)ip;
        netif_tb = _rtl8651_getNetworkIntfEntryByVid(vid);

        if(netif_tb){
                acl_tb = _rtl8651_aclLookUp(dsid,netif_tb,0,0,(int8 *)ethHdr,(int8*)ip,&defPermit, 0, 0);





                if(acl_tb) {
                        switch(acl_tb->actionType_){
                        case 0x01:
                                rtl8651_fwdEngineCounter.outAclPermit++;
                                return 0;
                        case 0x02:
                                rtl8651_fwdEngineCounter.outAclDrop++;
                                return 5|0x1000;
                        case 0x04:
                                rtl8651_fwdEngineCounter.outAclDrop++;

                                if ( (_loggingModule[dsid]&0x00000002)
                                        && _pUserLoggingFunc
                                        && ip

                                        && (_rtl8651_acl_drop_nolog[dsid]==0)

                                ){

                                        rtl8651_logInfo_t info;
                                        struct tcphdr *tc = ((void *)0);
                                        struct udphdr *ud = ((void *)0);
                                        struct icmp *ic = ((void *)0);
                                        uint16 sport = 0xffff;
                                        uint16 dport = 0xffff;
                                        uint8 type = 0xff;
                                        uint16 id = 0xffff;

                                        if (!(((uint16)(pip->ip_off)) & 0x1fff))
                                        {
                                                switch(pip->ip_p)
                                                {
                                                        case 6:
                                                                tc = (struct tcphdr *) ((int8 *) ip + ((*(uint8*)ip&0xf) << 2));
                                                                sport = (tc->th_sport);
                                                                dport = (tc->th_dport);
                                                                break;
                                                        case 17:
                                                                ud = (struct udphdr *) ((int8 *) ip + ((*(uint8*)ip&0xf) << 2));
                                                                sport = (ud->uh_sport);
                                                                dport = (ud->uh_dport);
                                                                break;
                                                        case 1:
                                                                ic = (struct icmp *) ((int8 *) ip + ((*(uint8*)ip&0xf) << 2));
                                                                type = ic->icmp_type;
                                                                id = (ic->icmp_hun.ih_idseq.icd_id);
                                                                break;
                                                }
                                        }

                                        info.infoType = 1;
                                        info.un.pkt.dsid = dsid;
                                        info.un.pkt.sip = ((uint32) (*((uint8*)(&pip->ip_src))<<24)|(*(((uint8*)(&pip->ip_src))+1)<<16)|(*(((uint8*)(&pip->ip_src))+2)<<8) | *(((uint8*)(&pip->ip_src))+3));
                                        info.un.pkt.dip = ((uint32) (*((uint8*)(&pip->ip_dst))<<24)|(*(((uint8*)(&pip->ip_dst))+1)<<16)|(*(((uint8*)(&pip->ip_dst))+2)<<8) | *(((uint8*)(&pip->ip_dst))+3));
                                        info.un.pkt.protocol = pip->ip_p;
                                        info.un.pkt.direction = (pVlan->internal?0:1);
                                        info.un.pkt.sport = sport;
                                        info.un.pkt.dport = dport;
                                        info.un.pkt.icmpType = type;
                                        info.un.pkt.icmpId = id;
                                        info.action = 1;
                                        (* _pUserLoggingFunc)(0x00000002, 5, &info);
# 6039 "rtl8651_tblDrvFwd.c"
                                }
                                return (5|0x1000);







                        default:
                                if(defPermit != 1){
                                        rtl8651_fwdEngineCounter.outAclDrop++;
                                        return 5|0x1000;
                                }else{
                                        rtl8651_fwdEngineCounter.outAclPermit++;
                                        return 0;
                                }
                        }
                }
                else {

                        int8 defAction;
                        int32 ret;
                        ret=_rtl8651_getDefaultAcl(netif_tb->ifName,&defAction);
                        do {} while (0);
                        switch(defAction){
                                case 0x06:
                                case 0x02:
                                        rtl8651_fwdEngineCounter.outAclDrop++;
                                        return 5|0x1000;
                                case 0x04:
                                        rtl8651_fwdEngineCounter.outAclDrop++;
                                        if ( (_loggingModule[dsid]&0x00000002)
                                                && ip
                                                &&_pUserLoggingFunc
                                        )
                                        {

                                                rtl8651_logInfo_t info;
                                                struct tcphdr *tc = ((void *)0);
                                                struct udphdr *ud = ((void *)0);
                                                struct icmp *ic = ((void *)0);
                                                uint16 sport = 0xffff;
                                                uint16 dport = 0xffff;
                                                uint8 type = 0xff;
                                                uint16 id = 0xffff;

                                                if (!(((uint16)(pip->ip_off)) & 0x1fff))
                                                {
                                                        switch(pip->ip_p)
                                                        {
                                                                case 6:
                                                                        tc = (struct tcphdr *) ((int8 *) ip + ((*(uint8*)ip&0xf) << 2));
                                                                        sport = (tc->th_sport);
                                                                        dport = (tc->th_dport);
                                                                        break;
                                                                case 17:
                                                                        ud = (struct udphdr *) ((int8 *) ip + ((*(uint8*)ip&0xf) << 2));
                                                                        sport = (ud->uh_sport);
                                                                        dport = (ud->uh_dport);
                                                                        break;
                                                                case 1:
                                                                        ic = (struct icmp *) ((int8 *) ip + ((*(uint8*)ip&0xf) << 2));
                                                                        type = ic->icmp_type;
                                                                        id = (ic->icmp_hun.ih_idseq.icd_id);
                                                                        break;
                                                        }
                                                }

                                                info.infoType = 1;
                                                info.un.pkt.dsid = dsid;
                                                info.un.pkt.sip = ((uint32) (*((uint8*)(&pip->ip_src))<<24)|(*(((uint8*)(&pip->ip_src))+1)<<16)|(*(((uint8*)(&pip->ip_src))+2)<<8) | *(((uint8*)(&pip->ip_src))+3));
                                                info.un.pkt.dip = ((uint32) (*((uint8*)(&pip->ip_dst))<<24)|(*(((uint8*)(&pip->ip_dst))+1)<<16)|(*(((uint8*)(&pip->ip_dst))+2)<<8) | *(((uint8*)(&pip->ip_dst))+3));
                                                info.un.pkt.protocol = pip->ip_p;
                                                info.un.pkt.direction = (pVlan->internal?0:1);
                                                info.un.pkt.sport = sport;
                                                info.un.pkt.dport = dport;
                                                info.un.pkt.icmpType = type;
                                                info.un.pkt.icmpId = id;
                                                info.action = 1;
                                                (* _pUserLoggingFunc)(0x00000002, 5, &info);
# 6138 "rtl8651_tblDrvFwd.c"
                                        }
                                        return 5|0x1000;
                                case 0x01:
                                case 0x03:
                                        rtl8651_fwdEngineCounter.outAclPermit++;
                                        return 0;
                                default:
                                        do {} while (0);
                                        break;
                        }
                }
        }
        return 0;
}
# 6163 "rtl8651_tblDrvFwd.c"
static inline void _rtl8651_l34Decision( struct rtl_pktHdr *pkthdr,
                                                                                rtl8651_tblDrv_vlanTable_t *vlanp,
                                                                                uint32 *decision_p,
                                                                                uint32 *srcType_p,
                                                                                uint32 *dstType_p,
                                                                                uint32 *optLayer_p)
{
        ipaddr_t sip = pkthdr->ph_sip;
        ipaddr_t dip = pkthdr->ph_dip;

        do {} while (0);


        if (_rtl8651_localServerIpAddr(sip) == 1)
        {
                *srcType_p = _RTL8651_HOST_LP;
        } else
        {
                if ( vlanp->internal )
                {
                        if (_rtl8651_getNatInternalMappingEntry(sip, pkthdr))
                        {
                                *srcType_p = _RTL8651_HOST_NI;
                        } else
                        {
                                *srcType_p = _RTL8651_HOST_NPI;
                        }
                } else
                {
                        *srcType_p = _RTL8651_HOST_RP;
                }
        }

        if (_rtl8651_getNatExternalMappingEntry(dip, pkthdr))
        {
                *dstType_p = _RTL8651_HOST_NE;
        }else if (_rtl8651_localServerIpAddr(dip) == 1)
        {
                *dstType_p = _RTL8651_HOST_LP;
        }else if (_rtl8651_extIpAddr(dip, ((void *)0)) == 1)
        {
                *dstType_p = _RTL8651_HOST_NPE;
        }else
        {
                rtl8651_tblDrv_routeTable_t *rt = ((void *)0);

                rt = _rtl8651_getRoutingEntry(dip);

                if ( (rt == ((void *)0))
                        || (rt && (rt->ipAddr == 0))

                        || (rt->netif_t->linkLayerType == 0x05)
                        || (rt->netif_t->linkLayerType == 0x06)

                )
                {

                        *dstType_p = _RTL8651_HOST_RP;
# 6230 "rtl8651_tblDrvFwd.c"
                } else
                {
                        rtl8651_tblDrv_vlanTable_t *dst_vlanp;

                        dst_vlanp = &DrvTbl.vlan[rt->dvid & (8 -1)];

                        if (dst_vlanp->internal)
                        {
                                if (_rtl8651_getNatInternalMappingEntry(dip, pkthdr) != ((void *)0))
                                {
                                        *dstType_p = _RTL8651_HOST_NI;
                                }else
                                {
                                        *dstType_p = _RTL8651_HOST_NPI;
                                }
                        }else
                        {
                                *dstType_p = _RTL8651_HOST_RP;
                        }


                        pkthdr->ph_routeIdx = (rt - &DrvTbl.route[0]) + 1;
                }
        }


        do {} while (0);

        *decision_p = _RTL8651_PROC[*srcType_p][*dstType_p];
        *optLayer_p = (((*decision_p) >= _RTL8651_DEC_RT_LR) && ((*decision_p) <= _RTL8651_DEC_RT_RR))? (3): ((((*decision_p) >= _RTL8651_DEC_NT) && ((*decision_p) <= _RTL8651_DEC_NPTBC_L))? (4): (0));

        return;
}
# 6271 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l34PacketProcess( struct rtl_pktHdr *pkthdr,
                                                                                                struct ip *pip,
                                                                                                uint32 decision)
{
        ipaddr_t sip = pkthdr->ph_sip;
        ipaddr_t dip = pkthdr->ph_dip;

        if (pkthdr->ph_routeIdx == 0 )
        {
                rtl8651_tblDrv_routeTable_t *policy_rt = ((void *)0);
                rtl8651_tblDrv_routeTable_t *rt = ((void *)0);


                if (decision == _RTL8651_DEC_NPT)
                {
                        if ( !(((uint16)(pip->ip_off)) & 0x1fff) )
                        {





                                switch (pip->ip_p)
                                {
                                        case 6:
                                        {
                                                struct tcphdr *tc;

                                                tc = (struct tcphdr *)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));

                                                if ((policy_rt = _rtl8651_getSoftRoutingEntry(sip, dip, 6, (tc->th_dport))) == ((void *)0))
                                                {
                                                        if (_rtl8651_getDemandRoutingEntry(sip, dip, 6, (tc->th_dport)))
                                                        {
                                                                return 138;
                                                        }
                                                }
                                        }
                                                break;

                                        case 17:
                                        {
                                                struct udphdr *ud;

                                                ud = (struct udphdr *)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));

                                                if ((policy_rt = _rtl8651_getSoftRoutingEntry(sip, dip, 17, (ud->uh_dport))) == ((void *)0))
                                                {
                                                        if (_rtl8651_getDemandRoutingEntry(sip, dip, 17, (ud->uh_dport)))
                                                        {
                                                                return 138;
                                                        }
                                                }
                                        }
                                                break;
                                        default:

                                                if ((policy_rt = _rtl8651_getSoftRoutingEntry(sip, dip, pip->ip_p, 0)) == ((void *)0))
                                                {
                                                        if (_rtl8651_getDemandRoutingEntry(sip, dip, pip->ip_p, 0))
                                                        {
                                                                return 138;
                                                        }
                                                }
                                                break;
                                }
                        }
                }
# 6350 "rtl8651_tblDrvFwd.c"
                if ( (policy_rt == ((void *)0)) &&
                        (decision != _RTL8651_DEC_NTR) &&
                        (decision != _RTL8651_DEC_NPTR) &&
                        (decision != _RTL8651_DEC_NTBC_NP) &&
                        (decision != _RTL8651_DEC_NTBC_N) &&
                        (decision != _RTL8651_DEC_NTBC_L) &&
                        (decision != _RTL8651_DEC_NPTBC_NP) &&
                        (decision != _RTL8651_DEC_NPTBC_N) &&
                        (decision != _RTL8651_DEC_NPTBC_L) &&
                        (decision != _RTL8651_DEC_DP) )
                {
                        rt = _rtl8651_getRoutingEntry(dip);

                        if (rt == ((void *)0))
                        {
                                return 139;
                        }
                }

                if ( policy_rt )
                {
                        pkthdr->ph_routeIdx = (policy_rt - &DrvTbl.route[0]) + 1;
                }else if ( rt )
                {
                        pkthdr->ph_routeIdx = (rt - &DrvTbl.route[0]) + 1;
                }

        }
        return 0;
}


static inline int32 _rtl8651_l34ActExec ( struct rtl_pktHdr * pkthdrPtr,
                                                                                struct ip* ip,
                                                                                uint8 proto,
                                                                                int32 decision )
{
        int32 val;

        if ((val = _rtl8651_l34AddtionalExec(decision, pkthdrPtr->ph_dip, pkthdrPtr->PKTHDRNXT.mbuf_first->m_data)) != 0)
        {
                return val;
        }

        switch ( decision )
        {



                case _RTL8651_DEC_NPT:
                {
                        val = _rtl8651_l4napt_process(pkthdrPtr, ip, proto, 2);

                        switch (val)
                        {
                                 case 0:
                                 {
                                        if ((val = _rtl8651_l3ActRouting(pkthdrPtr,pkthdrPtr->ph_dip, ip)) == 0)
                                        {
                                                return 0;
                                        }

                                 }
                                case 2:
                                {
                                        rtl8651_fwdEngineCounter.natdrop++;
                                        return 0x1000;
                                }
                                case 1:
                                {
                                        return -1;
                                }
                        }


                        return val;
                }

                case _RTL8651_DEC_NPTR:
                {
                        val = _rtl8651_l4napt_process(pkthdrPtr, ip, proto, 1);

                        switch (val)
                        {
                                 case 0:
                                 {

                                        ipaddr_t dip;
                                        uint32 dsid = pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid;
                                        ipaddr_t org_sip = pkthdrPtr->ph_sip;
                                        ipaddr_t org_dip = pkthdrPtr->ph_dip;

                                        dip = ((uint32) (*((uint8*)(&ip->ip_dst))<<24)|(*(((uint8*)(&ip->ip_dst))+1)<<16)|(*(((uint8*)(&ip->ip_dst))+2)<<8) | *(((uint8*)(&ip->ip_dst))+3));
                                        pkthdrPtr->ph_routeIdx = 0;

                                        if ((val = _rtl8651_l3ActRouting(pkthdrPtr, dip, ip)) == 0)
                                        {





                                                if ( ( rtl8651_drvDynamicRPPolicyRoute == 1 ) &&
                                                        ( dsid != 0 ) )
                                                {
                                                        rtl8651_tblDrvPolicyRoute_t policyRt;
                                                        memset(&policyRt, 0, sizeof(rtl8651_tblDrvPolicyRoute_t));
                                                        policyRt.type = (0x02|0x60);
                                                        policyRt.ip_alias = org_dip;
                                                        policyRt.trigger.sipDipPair.dip = (uint32)org_sip;
                                                        policyRt.trigger.sipDipPair.sip = (uint32)dip;
                                                        _rtl8651_addPolicyRoute( &policyRt, 3 );
                                                }

                                                return 0;
                                        }

                                 }
                                case 2:
                                {
                                        rtl8651_fwdEngineCounter.natdrop++;
                                        return 0x1000;
                                }
                                case 1:
                                {
                                        return -1;
                                }
                        }


                        return val;
                }




                case _RTL8651_DEC_NT:
                        return _rtl8651_l4nat_out_process(pkthdrPtr, ip);
                case _RTL8651_DEC_NTR:
                        return _rtl8651_l4nat_in_process(pkthdrPtr, ip);




                case _RTL8651_DEC_RT_LR:
                case _RTL8651_DEC_RT_RL:
                case _RTL8651_DEC_RT_LNP:
                case _RTL8651_DEC_RT_NPL:
                case _RTL8651_DEC_RT_LN:
                case _RTL8651_DEC_RT_NL:
                case _RTL8651_DEC_RT_LL:
                case _RTL8651_DEC_RT_NN:
                case _RTL8651_DEC_RT_NPNP:
                case _RTL8651_DEC_RT_NPN:
                case _RTL8651_DEC_RT_NNP:
                case _RTL8651_DEC_RT_RR:

                        return _rtl8651_l3ActRouting(pkthdrPtr, pkthdrPtr->ph_dip, ip);





                case _RTL8651_DEC_NPTBC_NP:
                case _RTL8651_DEC_NPTBC_N:
                case _RTL8651_DEC_NPTBC_L:
                        return _rtl8651_l4NaptPortBouncing(pkthdrPtr, ip);
                case _RTL8651_DEC_NTBC_NP:
                case _RTL8651_DEC_NTBC_N:
                case _RTL8651_DEC_NTBC_L:
                        return _rtl8651_l4NatPortBouncing(pkthdrPtr, ip);





                case _RTL8651_DEC_DP:
                        return 136;

                default:
                        do {} while (0);

        }

        return -1;
}

int32 _rtl8651_mtuFragment(uint32 property, struct rtl_pktHdr *pkthdrPtr, uint32 mtu, uint16 dvid, int8 isNapt, uint16 srcPortList)
{
        struct ip *ip = (struct ip *)(pkthdrPtr->PKTHDRNXT.mbuf_first->m_data + pkthdrPtr->ph_iphdrOffset);
        struct rtl_pktHdr *orgPkthdr=((void *)0);
        uint32 local_ph_reason;
        int32 retval;





        local_ph_reason = 0x0064;

        switch (local_ph_reason & 0x007f) {
                struct rtl_mBuf *new_m;
                struct ip *new_ip;
                int32 offset;
                int32 ip_hlen;
                uint8 *cp1;
                uint32 payloadLen, hdrLen;
                uint32 segLen;
                uint32 seg_seq;
        case 0x0064:

                ip_hlen = (ip->ip_vhl &0xf) << 2;


                if ((((uint16)(ip->ip_off)) & (0x1fff|0x2000)))
                        pkthdrPtr->ph_proto = 2;

                switch(pkthdrPtr->ph_proto){

                        struct tcphdr *tcp_p;
                        struct udphdr*udp_p;
                        struct icmp *icmp_p;
                        int32 totalLen ;
                case 5:
                        totalLen = (ip->ip_len);
                        tcp_p = (struct tcphdr *) ((int8 *) ip + ip_hlen);
                        tcp_p->th_sum = 0;
                        ip->ip_sum = 0;
                        tcp_p->th_sum = (_rtl8651_tcpChecksum(ip));
                        ip->ip_sum = (_rtl8651_ipChecksum((struct ip*)ip));
                        break;
                case 6:
                        udp_p = (struct udphdr *) ((int8 *) ip + ip_hlen);
                        totalLen = (ip->ip_len);
                        ip->ip_sum = 0;
                        if (udp_p->uh_sum)
                        {
                                udp_p->uh_sum = 0;
                                udp_p->uh_sum = (_rtl8651_tcpChecksum(ip));
                        }
                        ip->ip_sum = (_rtl8651_ipChecksum(ip));
                        break;
                case 3:
                        totalLen = (ip->ip_len);
                        icmp_p = (struct icmp *) ((int8 *) ip + ip_hlen);
                        icmp_p->icmp_cksum = 0;
                        ip->ip_sum = 0;
                        icmp_p->icmp_cksum = (_rtl8651_icmpChecksum(ip));
                        ip->ip_sum = (_rtl8651_ipChecksum((struct ip*)ip));
                        break;
# 6610 "rtl8651_tblDrvFwd.c"
                default:
                        break;
                }



                if ((rtl8651_drvIcmpRoutingMsgEnable == 1) &&
                        (property == ((uint32)(1)<<1)) &&
                        (rtl8651_drvIcmpAlwaysReplyErrForFrag == 1 || (((uint16)(ip->ip_off)) & (0x4000)))) {
                        struct ip *iphdr;
                        rtl8651_tblDrv_vlanTable_t *vlan_t;
                        rtl8651_tblDrv_arpEntry_t *arp_t;

                        uint32 ip_hlen, totalLen, ipAddr;


                        if ((new_m=mBuf_dupPacket(pkthdrPtr->PKTHDRNXT.mbuf_first, 0x02)) == ((void *)0))
                                return -1;
                        orgPkthdr = new_m->m_pkthdr;




                        orgPkthdr->ph_flags &= ~(0x0008|0x0004|0x0002|0x0001);

                        iphdr = (struct ip *)(new_m->m_data + orgPkthdr->ph_iphdrOffset);
                        iphdr->ip_ttl ++;
                        if (isNapt == 1) {
                                do{ *((uint8*)(&iphdr->ip_src)) = (uint8)((orgPkthdr->ph_sip)>>24); *(((uint8*)(&iphdr->ip_src))+1) = (uint8)((orgPkthdr->ph_sip)>>16); *(((uint8*)(&iphdr->ip_src))+2) = (uint8)((orgPkthdr->ph_sip)>>8); *(((uint8*)(&iphdr->ip_src))+3) = (uint8)((orgPkthdr->ph_sip)); }while(0);
                        }
                        else {
                                rtl8651_memcpy(&ipAddr, &iphdr->ip_src, 4);
                                rtl8651_memcpy(&iphdr->ip_src, &iphdr->ip_dst, 4);
                                rtl8651_memcpy(&iphdr->ip_dst, &ipAddr, 4);
                        }
                        ip_hlen = (iphdr->ip_vhl &0xf) << 2;
                        totalLen = (iphdr->ip_len);


                        if ((arp_t=_rtl8651_getArpEntry(((void *)0), orgPkthdr->ph_sip, 0))) {
                                vlan_t = &DrvTbl.vlan[(orgPkthdr->ph_vlanIdx& (8 -1))];
                                rtl8651_memcpy((new_m->m_data+6), &arp_t->macInfo->macAddr, 6);
                                rtl8651_memcpy(new_m->m_data, &vlan_t->macAddr, 6);
                        }

                        switch(orgPkthdr->ph_proto){
                                struct tcphdr *tcp_p;
                                struct udphdr*udp_p;
                                struct icmp *icmp_p;
                        case 5:
                                tcp_p = (struct tcphdr *) ((int8 *) iphdr + ip_hlen);
                                tcp_p->th_sport = (orgPkthdr->ph_un_sw.ROMEDRV_USG._ph_sport);
                                tcp_p->th_sum = 0;
                                iphdr->ip_sum = 0;
                                tcp_p->th_sum = (_rtl8651_tcpChecksum((struct ip*)iphdr));
                                iphdr->ip_sum = (_rtl8651_ipChecksum((struct ip*)iphdr));
                                break;

                        case 6:
                                udp_p = (struct udphdr *) ((int8 *) iphdr + ip_hlen);
                                udp_p->uh_sport = (orgPkthdr->ph_un_sw.ROMEDRV_USG._ph_sport);
                                iphdr->ip_sum = 0;
                                if (udp_p->uh_sum)
                                {
                                        udp_p->uh_sum = 0;
                                        udp_p->uh_sum= (_rtl8651_tcpChecksum((struct ip*)iphdr));
                                }
                                iphdr->ip_sum = (_rtl8651_ipChecksum((struct ip*)iphdr));
                                break;

                        case 3:
                                icmp_p = (struct icmp *) ((int8 *) iphdr + ip_hlen);
                                icmp_p->icmp_hun.ih_idseq.icd_id = (orgPkthdr->ph_un_sw.ROMEDRV_USG._ph_sport);
                                icmp_p->icmp_cksum = 0;
                                iphdr->ip_sum = 0;
                                icmp_p->icmp_cksum = (_rtl8651_icmpChecksum((struct ip*)iphdr));
                                iphdr->ip_sum = (_rtl8651_ipChecksum((struct ip*)iphdr));
                                break;

                        case 2:
                                if (!(((*(uint8*)iphdr)&0xf) == 5))
                                {
                                        iphdr->ip_sum = 0;
                                        iphdr->ip_sum = (_rtl8651_ipChecksum((struct ip*)iphdr));
                                }
                        default: break;

                        }

                        if (p_mtuHandler)
                        {
                                p_mtuHandler(orgPkthdr);
                        }else
                        {
                                _rtl8651_IcmpPktField_t icmpInfo;
                                icmpInfo.ic_type = 3;
                                icmpInfo.ic_code = 4;
                                icmpInfo.ic_hun.next_mtu = mtu;
                                vlan_t = &DrvTbl.vlan[(orgPkthdr->ph_vlanIdx& (8 -1))];
                                orgPkthdr->ph_portlist = srcPortList;
                                if (_rtl8651_drvIcmpErrorGeneration(orgPkthdr, iphdr, &icmpInfo, vlan_t->vid) != 0)
                                {
                                        mBuf_freeMbufChain(orgPkthdr->PKTHDRNXT.mbuf_first);
                                }
                        }
                }

                if ((((uint16)(ip->ip_off)) & (0x4000)))
                        return -1;


                offset = (uint8 *)ip - (uint8 *)pkthdrPtr->PKTHDRNXT.mbuf_first->m_data;
                if(offset <= 0 ){




                        return -1;
                }

                hdrLen = offset + ip_hlen;
                payloadLen = (ip->ip_len) - ip_hlen;
                segLen = ((mtu - ip_hlen)>>3)<<3;

                for(seg_seq=0 ; payloadLen > segLen; payloadLen-=segLen, seg_seq++) {
                        if ((new_m=mBuf_dupPacket(pkthdrPtr->PKTHDRNXT.mbuf_first, 0x02)) == ((void *)0)) {





                                return -1;
                        }
                        new_m->m_pkthdr->ph_flags &= ~(0x0001);
                        if (ip_hlen == 20)
                                new_m->m_pkthdr->ph_flags |= (0x0002);
                        else
                                new_m->m_pkthdr->ph_flags &= ~(0x0002);
                        if (seg_seq > 0) {
                                cp1 = (uint8 *)new_m->m_data + (seg_seq*segLen);
                                rtl8651_memcpy(cp1, (uint8 *)new_m->m_data, hdrLen);
                                mBuf_adjHead(new_m, segLen*seg_seq);
                        }
                        mBuf_adjTail(new_m, payloadLen-segLen);

                        new_ip = (struct ip *)(new_m->m_data + offset);
                        {
                                uint16 ip_len = (new_ip->ip_len);
                                uint16 ip_off =(ip->ip_off);

                                ip_len = ip_hlen + segLen;
                                new_ip->ip_len = (ip_len);

                                ip_off = seg_seq*(segLen>>3);
                                new_ip->ip_off += (ip_off) ;
                                new_ip->ip_off |= (0x2000);
                        }
                        do {} while (0);
                        new_m->m_pkthdr->ph_proto = 2;

                        if ((retval=_rtl8651_fwdEngineSend(property, (void*)(new_m->m_pkthdr),dvid,-1)) != 0) {
                                mBuf_freeMbufChain(new_m);




                                return retval;
                        }
                }


                cp1 = (uint8 *)pkthdrPtr->PKTHDRNXT.mbuf_first->m_data + (seg_seq*segLen);
                rtl8651_memcpy(cp1, (uint8 *)pkthdrPtr->PKTHDRNXT.mbuf_first->m_data, hdrLen);
                mBuf_adjHead(pkthdrPtr->PKTHDRNXT.mbuf_first, segLen*seg_seq);

                ip = (struct ip *)(pkthdrPtr->PKTHDRNXT.mbuf_first->m_data + offset);
                {
                        uint16 ip_len = (ip->ip_len);
                        uint16 ip_off =(ip->ip_off);

                        ip_len = ip_hlen + payloadLen;
                        ip->ip_len = (ip_len);

                        ip_off = seg_seq*(segLen>>3);
                        ip->ip_off += (ip_off);
                }
                pkthdrPtr->ph_flags &= ~(0x0001);
                if (ip_hlen == 20)
                        pkthdrPtr->ph_flags |= (0x0002);
                else
                        pkthdrPtr->ph_flags &= ~(0x0002);
# 6811 "rtl8651_tblDrvFwd.c"
                pkthdrPtr->ph_proto = 2;
                return _rtl8651_fwdEngineSend(property, (void*)pkthdrPtr,dvid,-1);

        case 0x0066:
                return -1;
        }


        return -1;
}





static int32 _rtl8651_l3ActRouting(struct rtl_pktHdr * pkthdrPtr, ipaddr_t dst_ip, struct ip *ip)
{
        {


                _rtl8651_dosScanCheckComplain(pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid, ip);

        }


        return _rtl8651_l3FastActRouting(((uint32)(1)<<1), pkthdrPtr, dst_ip, ip, ((void *)0));
}


__attribute__ ((section(".iram-l34-fwd"))) int32 _rtl8651_l3FastActRouting(uint32 property, struct rtl_pktHdr * pkthdrPtr, ipaddr_t dst_ip, struct ip *ip, void **arp_t)
{

        rtl8651_tblDrv_arpEntry_t *arp_tb;
        rtl8651_tblDrv_vlanTable_t *vlan_t;
        rtl8651_tblDrv_pppTable_t *nhSession_t;
        int8 *cp;
        ipaddr_t next_ip;
        rtl8651_tblDrv_routeTable_t *tb;
        int32 pktPPPoE = 0;
        uint32 mtu, tol_len;
        uint16 dvid;
        uint16 srcPortList;





        if (pkthdrPtr->ph_routeIdx >= 1)
        {
                tb = DrvTbl.route + (pkthdrPtr->ph_routeIdx - 1);
        }else
        {
                tb = _rtl8651_getRoutingEntry(dst_ip);
                if(tb == ((void *)0) || ip == ((void *)0))
                {
                        return 139;
                }
        }


        mtu = tb->netif_t->mtu;


        vlan_t = &DrvTbl.vlan[(tb->dvid& (8 -1))];
        if (vlan_t->macAddrNumber == 0)
                return -1;

        switch (tb->nextHopType)
        {
                case 0x00:
                case 0x01:

                case 0x05:
                case 0x06:

                        if( pkthdrPtr->ph_pppeTagged)
                        {

                                mBuf_adjHead( pkthdrPtr->PKTHDRNXT.mbuf_first, 8);
                                cp = (int8*)(pkthdrPtr->PKTHDRNXT.mbuf_first->m_data);


                                do{ *((uint8*)((cp+12))) = (uint8)(((uint16)0x0800)>>8); *(((uint8*)((cp+12)))+1) = (uint8)(0x0800); }while(0);

                                pkthdrPtr->ph_pppeTagged = 0;
                                pkthdrPtr->ph_iphdrOffset -= 8;
                        } else
                                cp = (int8*)(pkthdrPtr->PKTHDRNXT.mbuf_first->m_data);

                        nhSession_t = ((void *)0);
                        break;
                case 0x02:
                        pktPPPoE = 1;
                        cp = (int8*)(pkthdrPtr->PKTHDRNXT.mbuf_first->m_data);
                        if( pkthdrPtr->ph_pppeTagged == 0 )
                        {
                                if( tb->un.nxthop.un1.session.session_t == ((void *)0) || tb->un.nxthop.un1.session.session_t->valid == 0)




                                {
                                        return -1;
                                }
# 6924 "rtl8651_tblDrvFwd.c"
                                rtl8651_memcpy(cp+6, &(vlan_t->macAddr), sizeof(ether_addr_t));
                        }else
                        {






                                 return -1;
                        }
                        break;
                default:
                        return -1;
        }







        srcPortList = pkthdrPtr->ph_portlist;



        if(tb->nextHopType==0x05||tb->nextHopType==0x06)
        {

                _rtl8651_fragmentShortestPathCache_clear(pkthdrPtr, ip);

                if((tb-DrvTbl.route) != (rtl8651_tblDrvPara.routingTableSize-1))
                {
                         tb = &DrvTbl.route[rtl8651_tblDrvPara.routingTableSize-1];


                }

                if (tb->un.nxthop.un1.session.session_t->valid == 0 || tb->un.nxthop.un1.session.session_t->initiated == 0)
                        return -1;
                rtl8651_memcpy(cp, &(tb->un.nxthop.un1.session.session_t->macInfo->macAddr), sizeof(ether_addr_t));






                rtl8651_memcpy(cp+6, &(vlan_t->macAddr), sizeof(ether_addr_t));
                pkthdrPtr->ph_portlist = DrvTbl.vlan[tb->dvid & (8 - 1)].memberPortMask;
                pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid = 0;
                goto pptpL2tpSend;
        }







        if (pktPPPoE == 0)
        {

                if (tb->ifrt_flag == 0)
                {




                        next_ip = tb->nextHop;

                        arp_tb = tb->un.nxthop.un1.direct.arp_t;



                } else
                {
                        next_ip = dst_ip;

                        if (arp_t && *arp_t)
                        {
                                arp_tb = (rtl8651_tblDrv_arpEntry_t *)(*arp_t);
                                if ( (arp_tb->age > 0) &&
                                        (arp_tb->vid ==tb->dvid) &&
                                        (arp_tb->ipAddr == next_ip) )
                                {

                                } else
                                {
                                        goto arp_lookup;
                                }
                        } else
                        {
                        arp_lookup:
                                arp_tb = _rtl8651_getArpEntry(tb->netif_t, dst_ip, 1);
                        }
                }


                if (arp_t)
                {
                        *arp_t = (void *)arp_tb;
                }
# 7053 "rtl8651_tblDrvFwd.c"
                if (tb->ipClass == 1 && arp_tb && tb->ipintf_t && !tb->ipintf_t->ipUnnumber)
                        _rtl8651_ipClassMonitoring(next_ip, arp_tb);

                if (arp_tb == ((void *)0) || arp_tb->macInfo == ((void *)0))
                {
                        rtl8651_tblDrv_ipIntfEntry_t *iftb;
                        iftb = _rtl8651_getIpIntfEntryByAddr(next_ip);

                        if(iftb && iftb->ipAddr.slh_first )
                        {
                                if (iftb->ipAddr.slh_first->ipAddr == next_ip)
                                {
                                        return -1;
                                }
                        }
                        _rtl8651_drvArpGeneration(next_ip);

                        if(_rtl8651_enQueuePacket(pkthdrPtr,ip, next_ip,1) == 0)
                        {
                                return 0;
                        }


                        return -1;
                }

                {
                        uint32 mbrMask = arp_tb->macInfo->memberPortMask;
                        rtl8651_memcpy(cp, &(arp_tb->macInfo->macAddr), sizeof(ether_addr_t));
                        rtl8651_memcpy(cp+6, &vlan_t->macAddr, sizeof(ether_addr_t));
                        if (mbrMask == 0xffffffff)
                                pkthdrPtr->ph_portlist = DrvTbl.vlan[(tb->dvid& (8 -1))].memberPortMask;
                        else
                                pkthdrPtr->ph_portlist = mbrMask;
                }
        }else
        {
                rtl8651_tblDrv_pppTable_t *poe_tb;
                rtl8651_tblDrv_filterDbTableEntry_t *fb;





                        poe_tb = (rtl8651_tblDrv_pppTable_t *)_rtl8651_getPppoeSessionByDsid(pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid);
                        if(poe_tb == ((void *)0))
                        {
                                return -1;
                        }



                fb = poe_tb->macInfo;
                if(fb == ((void *)0))
                {
                        return -1;
                }
                poe_tb->txPackets++;
                poe_tb->txBytes += pkthdrPtr->ph_len;
                pkthdrPtr->ph_pppoeIdx=(poe_tb - DrvTbl.pppoe);
                pkthdrPtr->ph_portlist = fb->memberPortMask;
                rtl8651_memcpy(cp, &(fb->macAddr), sizeof(ether_addr_t));

                pkthdrPtr->ph_flags |= (0x0008);
                pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid=poe_tb->dsid;

                mtu = (poe_tb->mss + 40);
        }







pptpL2tpSend:


        if (property == ((uint32)(1)<<1))
        {
                ip->ip_ttl--;
        }


        if ((((*(uint8*)ip)&0xf) == 5))
        {

                pkthdrPtr->ph_flags |= 0x0002;
                if ((pkthdrPtr->ph_proto == 2) ||
                        (property == ((uint32)(1)<<1) && pkthdrPtr->ph_proto == 1) ||
                        ((((uint16)(ip->ip_off)) & (0x1fff|0x2000))))
                {



                        pkthdrPtr->ph_flags &= (~0x0001);
                        pkthdrPtr->ph_proto = 2;
                }else
                {
                        pkthdrPtr->ph_flags |= 0x0001;
                        if (property == ((uint32)(1)<<1) && ip->ip_p == 17)
                        {
                                struct udphdr *ud;
                                ud = (struct udphdr*)((uint8 *)ip + (((*(uint8*)ip)&0xf) << 2));
                                if (!ud->uh_sum)
                                        pkthdrPtr->ph_flags &= (~0x0001);
                        }
                }
        }else
        {

                if (property == ((uint32)(1)<<1))
                {
                        int32 accumulate = 0x0100;
                        do { accumulate += (ip->ip_sum); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ip->ip_sum = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ip->ip_sum = ((uint16) accumulate); } } while (0);
                }



                pkthdrPtr->ph_flags &= ~(0x0002|0x0001);
                pkthdrPtr->ph_proto = 2;
        }







        dvid = tb->dvid;





        if (property == ((uint32)(1)<<3))
        {
                _rtl8651_fwdEnginePSOffload_L3ExtraProcess(pkthdrPtr, ip, vlan_t);
        }


        tol_len = mBuf_getPktlen(pkthdrPtr->PKTHDRNXT.mbuf_first);
        if (tol_len > (mtu+14))
        {

                _rtl8651_fragmentShortestPathCache_clear(pkthdrPtr, ip);

                return _rtl8651_mtuFragment(property, pkthdrPtr, mtu, tb->dvid, 1, srcPortList);
        }





        return _rtl8651_fwdEngineSend(property, (void*)pkthdrPtr, dvid, -1);
}
# 7221 "rtl8651_tblDrvFwd.c"
inline void _rtl8651_l4TcpAdjustMss(struct ip *ip, struct tcphdr *tc, ipaddr_t intfIp, int32 delta)
{
        if (tc->th_flags & 0x02)
        {


                uint8 *ptr;
                uint32 cnt;
                int32 optLen;
                int32 opt;

                ptr = (uint8 *)((uint8 *)tc + sizeof(struct tcphdr));
                cnt = ((tc->th_off_x >> 2) & 0x3c) - sizeof(struct tcphdr);

                for (; cnt > 0 ; cnt -= optLen, ptr += optLen)
                {
                        opt = (uint32)ptr[0];

                        if (opt == 0)
                                return;


                        if (opt == 2)
                        {
                                uint16 mss, new_mss;
                                rtl8651_tblDrv_pppTable_t * pppoeEntry;

                                mss = (*(uint16*)(&ptr[2]));
                                new_mss = mss;
                                pppoeEntry=_rtl8651_getPppoeSessionByIpAddr(intfIp);
                                if (pppoeEntry)
                                {
                                        if (mss > pppoe_mss[pppoeEntry->dsid]+delta)
                                        {
                                                new_mss = pppoe_mss[pppoeEntry->dsid]+delta;
                                                *(uint16*)(&ptr[2]) = (new_mss);
                                        }
                                }else if (mss > rtl8651_mss+delta)
                                {
                                        new_mss = rtl8651_mss+delta;
                                        *(uint16*)(&ptr[2]) = (new_mss);
                                }


                                if ( 1 )
                                {
                                        do { int32 accumulate; accumulate = ((mss) - (new_mss)); do { accumulate += ((tc->th_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) accumulate); } } while (0); } while(0);
                                }
                        }

                        if (opt == 1)
                        {
                                optLen = 1;
                        }else
                        {
                                optLen= ptr[1];
                                if (optLen <= 0)
                                        return;
                        }
                }
        }
}
# 7296 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4TcpMonitorIn(struct tcphdr *tc, rtl8651_tblDrv_naptTcpUdpFlowEntry_t* tb)
{
        uint32 pktFlags, currentState;
        int32 retval;


        pktFlags = tc->th_flags & (0x04|0x02|0x01);
        currentState = tb->tcpFlag;

        do {} while (0);
        if(pktFlags==0){
resetage:

                if (_ageTimer[currentState+1])
                        retval=_rtl8651_updateNaptConnection( tb, 0, *_ageTimer[currentState+1]);
                else
                        retval = 0;
                return retval;
        }

        retval = -1;
        if (pktFlags>=0x04){
                retval=_rtl8651_updateNaptConnection( tb, 8, rtl8651GlobalControl.tcpFastTimeout);
        } else if(pktFlags==0x02){

                int32 state=_inNextState[0][currentState];
                if(state>0){
                        if (_ageTimer[state])
                                retval=_rtl8651_updateNaptConnection( tb, state, *_ageTimer[state]);
                        else
                                retval = 0;
                }else if(state==0)
                        goto resetage;
        }else{

                int32 state=_inNextState[1][currentState];
                if(state>0){
                        if (_ageTimer[state])
                                retval=_rtl8651_updateNaptConnection( tb, state, *_ageTimer[state]);
                        else
                                retval = 0;
                }else if(state==0)
                        goto resetage;
        }
        return retval;

}
# 7356 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4TcpMonitorOut(struct tcphdr *tc, rtl8651_tblDrv_naptTcpUdpFlowEntry_t* tb)
{
        uint32 pktFlags, currentState;
        int32 retval;


        pktFlags = tc->th_flags & (0x04|0x02|0x01);
        currentState = tb->tcpFlag;

        do {} while (0);
        if(pktFlags==0){
resetage:

                if (_ageTimer[currentState+1])
                        retval=_rtl8651_updateNaptConnection( tb, 0, *_ageTimer[currentState+1]);
                else
                        retval = 0;
                return retval;
        }

        retval = -1;
        if (pktFlags >= 0x04) {
                retval=_rtl8651_updateNaptConnection( tb, 8, rtl8651GlobalControl.tcpFastTimeout);
        }else if(pktFlags==0x02){


                int32 state=_outNextState[0][currentState];
                if(state>0){
                        if ( _ageTimer[state] )
                                retval=_rtl8651_updateNaptConnection( tb, state, *_ageTimer[state]);
                        else
                                retval = 0;
                }else if(state==0)
                        goto resetage;
        }else{

                int32 state=_outNextState[1][currentState];
                if(state>0){
                        if ( _ageTimer[state] )
                                retval=_rtl8651_updateNaptConnection( tb, state, *_ageTimer[state]);
                        else
                                retval = 0;
                }
                else if(state==0)
                        goto resetage;
        }
        return retval;
}
# 7416 "rtl8651_tblDrvFwd.c"
static int8 _rtl8651_l4CheckOccupiedConnection(uint32 isTcp, uint32 dsid, ipaddr_t IntIp, uint16 IntPort, ipaddr_t ExtIp, uint16 ExtPort, ipaddr_t RemoteIp, uint16 RemotePort)
{
        rtl8651_tblDrv_naptServerPortEntry_t *sp_t = ((void *)0);
# 7431 "rtl8651_tblDrvFwd.c"
        if ((sp_t = _rtl8651_getOutsideNaptServerPortMapping(isTcp, ExtIp, ExtPort)) != ((void *)0))
        {
                if (((IntPort + sp_t->endLocalPort - sp_t->localPort) != ExtPort) || (sp_t->localIp != IntIp))
                {
                        return 1;
                }
        }


        if (_rtl8651_checkProtoStackRegistedPort(ExtPort, (isTcp?6:17)))
        {
                return 1;
        }


        if (_rtl8651_checkUsableUpnpEntry(isTcp, IntIp, IntPort, ExtIp, ExtPort, RemoteIp, RemotePort) == 0)
        {
                return 1;
        }


        if (_rtl8651_checkUsableTriggeredPortEntry(isTcp, dsid, IntIp, ExtPort) == 0)
        {
                return 1;
        }

        return 0;
}





static int32 _rtl8651_inboundL4DMZForward(struct rtl_pktHdr *phdr, struct ip *ip, ipaddr_t dip)
{
        ipaddr_t dmzIp = 0;

        if (!rtl8651_drvFwdOtherL4ToDMZEnable)
                goto errout;

        if (_rtl8651_getDmzHost(phdr->ph_un_sw.ROMEDRV_USG._ph_dsid, dip, &dmzIp) != 0)
                goto errout;


        do{ *((uint8*)(&ip->ip_dst)) = (uint8)((dmzIp)>>24); *(((uint8*)(&ip->ip_dst))+1) = (uint8)((dmzIp)>>16); *(((uint8*)(&ip->ip_dst))+2) = (uint8)((dmzIp)>>8); *(((uint8*)(&ip->ip_dst))+3) = (uint8)((dmzIp)); }while(0);


        if (!(((*(uint8*)ip)&0xf) == 5))
        {

                do { do { int32 accumulate = 0; if ((((dmzIp)) != 0) && (((dip)) != 0)){ accumulate = (((dip)) & 0xffff); accumulate += (( ((dip)) >> 16 ) & 0xffff); accumulate -= (((dmzIp)) & 0xffff); accumulate -= (( ((dmzIp)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((ip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);

        }
        if (((((uint16)(ip->ip_off)) & (0x1fff|0x2000)) == 0x2000))
        {
                _rtl8651_updateFragCache(0, phdr->ph_sip, phdr->ph_dip, (ip->ip_id), dmzIp, 0, ((void *)0), phdr->ph_un_sw.ROMEDRV_USG._ph_dsid);
        }

        return 0;

errout:
        return -1;
}




static int32 _rtl8651_outboundL4DMZForward(struct rtl_pktHdr *phdr, struct ip *ip, ipaddr_t sip)
{
        ipaddr_t naptIp = 0;

        if (!rtl8651_drvFwdOtherL4ToDMZEnable)
                goto errout;

        if (_rtl8651_fromDmzHost(phdr->ph_un_sw.ROMEDRV_USG._ph_dsid, sip, &naptIp) != 0)
                goto errout;


        do{ *((uint8*)(&ip->ip_src)) = (uint8)((naptIp)>>24); *(((uint8*)(&ip->ip_src))+1) = (uint8)((naptIp)>>16); *(((uint8*)(&ip->ip_src))+2) = (uint8)((naptIp)>>8); *(((uint8*)(&ip->ip_src))+3) = (uint8)((naptIp)); }while(0);


        if (!(((*(uint8*)ip)&0xf) == 5))
        {

                do { do { int32 accumulate = 0; if ((((naptIp)) != 0) && (((sip)) != 0)){ accumulate = (((sip)) & 0xffff); accumulate += (( ((sip)) >> 16 ) & 0xffff); accumulate -= (((naptIp)) & 0xffff); accumulate -= (( ((naptIp)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((ip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);

        }
        if (((((uint16)(ip->ip_off)) & (0x1fff|0x2000)) == 0x2000))
        {
                _rtl8651_updateFragCache(1, phdr->ph_sip, phdr->ph_dip, (ip->ip_id), naptIp, 0, ((void *)0), phdr->ph_un_sw.ROMEDRV_USG._ph_dsid);
        }

        return 0;

errout:
        return -1;
}
# 7539 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4IcmpNaptAliasIn1(struct rtl_pktHdr *phdr, struct ip *pip,struct icmp *ic)
{

        rtl8651_tblDrv_naptIcmpFlowEntry_t * tb;

        ipaddr_t ip_org = 0;
        uint16 id, id_org = 0;

        id = (ic->icmp_hun.ih_idseq.icd_id);

        tb = _rtl8651_getOutsideNaptIcmpEntry(phdr->ph_dip, id, phdr->ph_sip, 1, 1);

        if (tb != ((void *)0))
        {
                id_org = tb->insideLocalId;
                ip_org= tb->insideLocalIpAddr;

                if (((pip->ip_vhl & 0x0f) != 5) || ((pip->ip_off) & 0x2000))
                {
                        if ((pip->ip_vhl & 0x0f) != 5)
                        {

                                do { do { int32 accumulate = 0; if ((((ip_org)) != 0) && (((phdr->ph_sip)) != 0)){ accumulate = (((phdr->ph_sip)) & 0xffff); accumulate += (( ((phdr->ph_sip)) >> 16 ) & 0xffff); accumulate -= (((ip_org)) & 0xffff); accumulate -= (( ((ip_org)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                        }

                        do { int32 accumulate = 0; if (((0) != 0) && ((0) != 0)){ accumulate = ((0) & 0xffff); accumulate += (( (0) >> 16 ) & 0xffff); accumulate -= ((0) & 0xffff); accumulate -= (( (0) >> 16 ) & 0xffff); } if (((id_org) != 0) && ((id) != 0)){ accumulate += (id); accumulate -= (id_org); } do { accumulate += ((ic->icmp_cksum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) accumulate); } } while (0); }while(0);
                }
# 7574 "rtl8651_tblDrvFwd.c"
                do{ *((uint8*)(&pip->ip_dst)) = (uint8)((ip_org)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((ip_org)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((ip_org)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((ip_org)); }while(0);



                ic->icmp_hun.ih_idseq.icd_id = (id_org);
                return (0);
        }

        return (64);
}
# 7597 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4IcmpNaptAliasIn2(struct rtl_pktHdr *phdr, struct ip *pip,struct icmp *ic)
{





        struct ip *ip;
        struct icmp *ic2=((void *)0);
        struct udphdr *ud=((void *)0);
        struct tcphdr *tc=((void *)0);
        struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s entry;

        rtl8651_tblDrv_naptIcmpFlowEntry_t * tb_icmp = ((void *)0);
        rtl8651_tblDrv_naptTcpUdpFlowEntry_t * tb_tcpudp = &entry;

        ipaddr_t ip_s, ip_d;

        ip = &ic->icmp_dun.id_ip.idi_ip;

        ip_s = ((uint32) (*((uint8*)(&ip->ip_dst))<<24)|(*(((uint8*)(&ip->ip_dst))+1)<<16)|(*(((uint8*)(&ip->ip_dst))+2)<<8) | *(((uint8*)(&ip->ip_dst))+3));
        ip_d =((uint32) (*((uint8*)(&ip->ip_src))<<24)|(*(((uint8*)(&ip->ip_src))+1)<<16)|(*(((uint8*)(&ip->ip_src))+2)<<8) | *(((uint8*)(&ip->ip_src))+3));

        if ((((uint16)(ip->ip_off)) & 0x1fff))
        {
                ;

                tb_tcpudp = ((void *)0);
                tb_icmp = ((void *)0);
        } else
        {
                if (ip->ip_p == 17)
                {
                        ud = (struct udphdr *) ((int8 *)ip + ((ip->ip_vhl & 0x0f) << 2));
                        if(_rtl8651_getInboundNaptFlow(0, ip_d, (ud->uh_sport),
                                                ip_s, (ud->uh_dport), &tb_tcpudp )!=0)
                        {
                                tb_tcpudp = ((void *)0);
                        }
                } else if (ip->ip_p == 6){
                        tc = (struct tcphdr *) ((int8 *) ip + ((ip->ip_vhl & 0x0f) << 2));
                        if(_rtl8651_getInboundNaptFlow(1, ip_d, (tc->th_sport),
                                                ip_s, (tc->th_dport), &tb_tcpudp )!=0)
                        {
                                tb_tcpudp = ((void *)0);
                        }
                } else if (ip->ip_p == 1)
                {
                        ic2 = (struct icmp *) ((int8 *) ip + ( (ip->ip_vhl & 0x0f) << 2));
                        tb_icmp = _rtl8651_getOutsideNaptIcmpEntry(ip_d, (ic2->icmp_hun.ih_idseq.icd_id), ip_s, 0, 0);
                        tb_tcpudp = ((void *)0);
                } else
                {
                        ;

                        tb_icmp = ((void *)0);
                        tb_tcpudp = ((void *)0);
                }
        }

        if (tb_tcpudp){
                ipaddr_t original_address;
                uint16 original_port;




                if (tb_tcpudp->toProtocolStack == 1)
                {




                        if (!(((uint16)(ip->ip_off)) & 0x1fff))
                        {
                                int32 retval;
                                uint16 orgSPort, orgDPort;
                                uint16 *pnewSPort;
                                uint16 *pnewDPort;
                                if (ip->ip_p == 6)
                                {
                                        orgSPort = (tc->th_sport);
                                        orgDPort = (tc->th_dport);
                                        pnewSPort = &(tc->th_sport);
                                        pnewDPort = &(tc->th_dport);

                                        if ( tb_tcpudp->insideLocalPort != orgSPort )
                                        {
                                                tc->th_sport = (tb_tcpudp->insideLocalPort);
                                                do { int32 accumulate = 0; if (((0) != 0) && ((0) != 0)){ accumulate = ((0) & 0xffff); accumulate += (( (0) >> 16 ) & 0xffff); accumulate -= ((0) & 0xffff); accumulate -= (( (0) >> 16 ) & 0xffff); } if (((tb_tcpudp->insideLocalPort) != 0) && ((orgSPort) != 0)){ accumulate += (orgSPort); accumulate -= (tb_tcpudp->insideLocalPort); } do { accumulate += ((ic->icmp_cksum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) accumulate); } } while (0); }while(0);
                                                orgSPort = tb_tcpudp->insideLocalPort;
                                        }
                                }else
                                {
                                        orgSPort = (ud->uh_sport);
                                        orgDPort = (ud->uh_dport);
                                        pnewSPort = &(ud->uh_sport);
                                        pnewDPort = &(ud->uh_dport);

                                        if ( tb_tcpudp->insideLocalPort != orgSPort )
                                        {
                                                ud->uh_sport = (tb_tcpudp->insideLocalPort);
                                                do { int32 accumulate = 0; if (((0) != 0) && ((0) != 0)){ accumulate = ((0) & 0xffff); accumulate += (( (0) >> 16 ) & 0xffff); accumulate -= ((0) & 0xffff); accumulate -= (( (0) >> 16 ) & 0xffff); } if (((tb_tcpudp->insideLocalPort) != 0) && ((orgSPort) != 0)){ accumulate += (orgSPort); accumulate -= (tb_tcpudp->insideLocalPort); } do { accumulate += ((ic->icmp_cksum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) accumulate); } } while (0); }while(0);
                                                orgSPort = tb_tcpudp->insideLocalPort;
                                        }
                                }

                                retval = _rtl8651_aliasProtoStackRecvPkt(phdr, 1, ip);
                                switch ( retval )
                                {
                                        case 2:
                                        {







                                                do { int32 accumulate = 0; if (((0) != 0) && ((0) != 0)){ accumulate = ((0) & 0xffff); accumulate += (( (0) >> 16 ) & 0xffff); accumulate -= ((0) & 0xffff); accumulate -= (( (0) >> 16 ) & 0xffff); } if ((((*pnewSPort)) != 0) && ((orgSPort) != 0)){ accumulate += (orgSPort); accumulate -= ((*pnewSPort)); } do { accumulate += ((ic->icmp_cksum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) accumulate); } } while (0); }while(0);
                                                do { int32 accumulate = 0; if (((0) != 0) && ((0) != 0)){ accumulate = ((0) & 0xffff); accumulate += (( (0) >> 16 ) & 0xffff); accumulate -= ((0) & 0xffff); accumulate -= (( (0) >> 16 ) & 0xffff); } if ((((*pnewDPort)) != 0) && ((orgDPort) != 0)){ accumulate += (orgDPort); accumulate -= ((*pnewDPort)); } do { accumulate += ((ic->icmp_cksum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) accumulate); } } while (0); }while(0);
                                                break;
                                        }
                                        case 1:
                                        {




                                                return 131;
                                        }
                                }
                        }
                        return 132;
                }

                original_address = tb_tcpudp->insideLocalIpAddr;
                original_port = tb_tcpudp->insideLocalPort;



                 do { do { int32 accumulate = 0; if ((((original_address)) != 0) && (((ip_d)) != 0)){ accumulate = (((ip_d)) & 0xffff); accumulate += (( ((ip_d)) >> 16 ) & 0xffff); accumulate -= (((original_address)) & 0xffff); accumulate -= (( ((original_address)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((ip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);


                if (((pip->ip_vhl & 0x0f) != 5) || ((pip->ip_off) & 0x2000))
                {
                        if ((pip->ip_vhl & 0x0f) != 5)
                        {

                                do { do { int32 accumulate = 0; if ((((original_address)) != 0) && (((ip_d)) != 0)){ accumulate = (((ip_d)) & 0xffff); accumulate += (( ((ip_d)) >> 16 ) & 0xffff); accumulate -= (((original_address)) & 0xffff); accumulate -= (( ((original_address)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                        }

                        if (ip->ip_p == 6)
                        {
                                do { int32 accumulate = 0; if (((original_address) != 0) && ((ip_d) != 0)){ accumulate = ((ip_d) & 0xffff); accumulate += (( (ip_d) >> 16 ) & 0xffff); accumulate -= ((original_address) & 0xffff); accumulate -= (( (original_address) >> 16 ) & 0xffff); } if (((original_port) != 0) && (((tc->th_sport)) != 0)){ accumulate += ((tc->th_sport)); accumulate -= (original_port); } do { accumulate += ((ic->icmp_cksum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) accumulate); } } while (0); }while(0);
                        }else
                        {
                                do { int32 accumulate = 0; if (((original_address) != 0) && ((ip_d) != 0)){ accumulate = ((ip_d) & 0xffff); accumulate += (( (ip_d) >> 16 ) & 0xffff); accumulate -= ((original_address) & 0xffff); accumulate -= (( (original_address) >> 16 ) & 0xffff); } if (((original_port) != 0) && (((ud->uh_sport)) != 0)){ accumulate += ((ud->uh_sport)); accumulate -= (original_port); } do { accumulate += ((ic->icmp_cksum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) accumulate); } } while (0); }while(0);
                        }
                }
# 7772 "rtl8651_tblDrvFwd.c"
                do{ *((uint8*)(&pip->ip_dst)) = (uint8)((original_address)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((original_address)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((original_address)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((original_address)); }while(0);



                do{ *((uint8*)(&ip->ip_src)) = (uint8)((original_address)>>24); *(((uint8*)(&ip->ip_src))+1) = (uint8)((original_address)>>16); *(((uint8*)(&ip->ip_src))+2) = (uint8)((original_address)>>8); *(((uint8*)(&ip->ip_src))+3) = (uint8)((original_address)); }while(0);
                if (ip->ip_p == 17)
                {
                        ud->uh_sport = (original_port);
                }
                else if (ip->ip_p == 6)
                {
                        tc->th_sport = (original_port);
                }
                return (0);

        }else if (tb_icmp)
        {
                ipaddr_t original_address;
                uint16 original_id;

                original_address = tb_icmp->insideLocalIpAddr;
                original_id = tb_icmp->insideLocalId;



                do { do { int32 accumulate = 0; if ((((original_address)) != 0) && (((ip_d)) != 0)){ accumulate = (((ip_d)) & 0xffff); accumulate += (( ((ip_d)) >> 16 ) & 0xffff); accumulate -= (((original_address)) & 0xffff); accumulate -= (( ((original_address)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((ip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);


                if (((pip->ip_vhl & 0x0f) != 5) || ((pip->ip_off) & 0x2000))
                {
                        if ((pip->ip_vhl & 0x0f) != 5)
                        {

                                do { do { int32 accumulate = 0; if ((((original_address)) != 0) && (((ip_d)) != 0)){ accumulate = (((ip_d)) & 0xffff); accumulate += (( ((ip_d)) >> 16 ) & 0xffff); accumulate -= (((original_address)) & 0xffff); accumulate -= (( ((original_address)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                        }

                        do { int32 accumulate = 0; if (((original_address) != 0) && ((ip_d) != 0)){ accumulate = ((ip_d) & 0xffff); accumulate += (( (ip_d) >> 16 ) & 0xffff); accumulate -= ((original_address) & 0xffff); accumulate -= (( (original_address) >> 16 ) & 0xffff); } if (((original_id) != 0) && (((ic2->icmp_hun.ih_idseq.icd_id)) != 0)){ accumulate += ((ic2->icmp_hun.ih_idseq.icd_id)); accumulate -= (original_id); } do { accumulate += ((ic->icmp_cksum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) accumulate); } } while (0); }while(0);
                }
# 7820 "rtl8651_tblDrvFwd.c"
                do{ *((uint8*)(&pip->ip_dst)) = (uint8)((original_address)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((original_address)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((original_address)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((original_address)); }while(0);



                do{ *((uint8*)(&ip->ip_src)) = (uint8)((original_address)>>24); *(((uint8*)(&ip->ip_src))+1) = (uint8)((original_address)>>16); *(((uint8*)(&ip->ip_src))+2) = (uint8)((original_address)>>8); *(((uint8*)(&ip->ip_src))+3) = (uint8)((original_address)); }while(0);
                ic2->icmp_hun.ih_idseq.icd_id = (original_id);
                return (0);
        }else
        {
                return (65);
        }
}
# 7842 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4IcmpNaptAliasIn3(struct rtl_pktHdr *phdr, struct ip *pip,struct icmp *ic)
{
        ipaddr_t ip_s, ip_d;
        ipaddr_t dmzhost;
        int r;

        ip_s = phdr->ph_sip;
        ip_d = phdr->ph_dip;


                r = _rtl8651_doProtoStackAction(phdr, pip);
                if(r==1) return 131;

        if (!rtl8651_DMZHostIcmpPassthroughEnable)
        {
                return 64;
        }

        if (_rtl8651_getDmzHost(phdr->ph_un_sw.ROMEDRV_USG._ph_dsid, ip_d, &dmzhost) == 0)
        {
                uint16 id;
                rtl8651_tblDrv_naptIcmpFlowEntry_t* icmp_tb;

                id = (ic->icmp_hun.ih_idseq.icd_id);
                icmp_tb = _rtl8651_getOutsideNaptIcmpEntry(ip_d, id, ip_s, 1, 0);

                if (!icmp_tb)
                {
                        {




                                int32 local_val;
                                rtl8651_tblDrv_vlanTable_t *local_vlanp = &DrvTbl.vlan[phdr->ph_vlanIdx];
                                local_val = _rtl8651_ingressAcl(phdr->ph_un_sw.ROMEDRV_USG._ph_dsid, 0, local_vlanp, local_vlanp->vid, phdr->PKTHDRNXT.mbuf_first->m_data, (uint8 *) pip, 0x01, 0);
                                if (((local_val > 0) && (local_val & 0x1000)) ||(local_val == 2))
                                        return local_val;
                        }

                        if( _rtl8651_addNaptIcmpNonCandidateFlow(1, dmzhost, id, ip_d, id, ip_s)!= 0)
                        {
                                return 63;
                        }


                        icmp_tb = _rtl8651_getOutsideNaptIcmpEntry(ip_d, id, ip_s, 1, 0);
                }


                do {} while (0);
                icmp_tb->dsid = phdr->ph_un_sw.ROMEDRV_USG._ph_dsid;




                if ((pip->ip_vhl & 0x0f) != 5)
                        do { do { int32 accumulate = 0; if ((((dmzhost)) != 0) && (((ip_d)) != 0)){ accumulate = (((ip_d)) & 0xffff); accumulate += (( ((ip_d)) >> 16 ) & 0xffff); accumulate -= (((dmzhost)) & 0xffff); accumulate -= (( ((dmzhost)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);


                do{ *((uint8*)(&pip->ip_dst)) = (uint8)((dmzhost)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((dmzhost)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((dmzhost)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((dmzhost)); }while(0);
                return 0;
        } else
        {
                return 64;
        }
}
# 7921 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_L4IcmpNaptAliasIn(struct rtl_pktHdr *phdr, struct ip *pip)
{
        int32 iresult;
        struct icmp *ic;


        ic = (struct icmp *) ((int8 *) pip + ((*(uint8*)pip&0xf) << 2));
        switch (ic->icmp_type)
        {
                case 0:
                case 14:
                        iresult = _rtl8651_l4IcmpNaptAliasIn1(phdr, pip, ic);
                        break;
                case 3:
                case 4:
                case 11:
                case 12:
                        iresult = _rtl8651_l4IcmpNaptAliasIn2(phdr, pip, ic);
                        break;
                case 8:
                case 13:
                        iresult = _rtl8651_l4IcmpNaptAliasIn3(phdr, pip, ic);
                        break;
                default:
                        return (64);
        }

        if (iresult == 0)
        {

                if((pip->ip_off) & (0x2000|0x1fff)){
                        int32 ta;
                        phdr->ph_proto = 2;
                        ta = ((uint32) (*((uint8*)(&pip->ip_dst))<<24)|(*(((uint8*)(&pip->ip_dst))+1)<<16)|(*(((uint8*)(&pip->ip_dst))+2)<<8) | *(((uint8*)(&pip->ip_dst))+3));
                        _rtl8651_updateFragCache(0, phdr->ph_sip, phdr->ph_dip, (pip->ip_id), ta, 0, ((void *)0), phdr->ph_un_sw.ROMEDRV_USG._ph_dsid);
                }

        }
        return (iresult);
}
# 7972 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4IcmpNaptAliasOut1(struct rtl_pktHdr *phdr, struct ip *pip,struct icmp *ic)
{
        rtl8651_tblDrv_naptIcmpFlowEntry_t * tb;

        ipaddr_t ip_s, ip_d, ip_alias = 0;
        uint16 id, id_alias = 0;

        ip_s = phdr->ph_sip;
        ip_d = phdr->ph_dip;
        id = (ic->icmp_hun.ih_idseq.icd_id);

        tb = _rtl8651_getInsideNaptIcmpEntry(ip_s, id, ip_d, 1, 0);

        if(tb)
        {
                ip_alias = tb->insideGlobalIpAddr;
                id_alias = tb->insideGlobalId;
        }
        else
        {

                {




                        int32 local_val;
                        rtl8651_tblDrv_vlanTable_t *local_vlanp = &DrvTbl.vlan[phdr->ph_vlanIdx];
                        local_val = _rtl8651_ingressAcl(phdr->ph_un_sw.ROMEDRV_USG._ph_dsid, 0, local_vlanp, local_vlanp->vid, phdr->PKTHDRNXT.mbuf_first->m_data, (uint8 *) pip, 0x01, 0);
                        if (((local_val > 0) && (local_val & 0x1000)) ||(local_val == 2))
                                return local_val;
                }

                if (_rtl8651_softIcmpPolicyRoute(ip_s, id, ip_d, &ip_alias, &id_alias) == 0)
                {
                        int32 retval;
                        while ((retval = _rtl8651_addNaptIcmpNonCandidateFlow(1, ip_s, id, ip_alias, id_alias, ip_d))
                                        != 0)
                        {
                                if (retval == -3004)
                                {

                                        id_alias ++;
                                }
                                else
                                {
                                        return 60;
                                }
                        }
                }
                else
                {
                        if (_rtl8651_getIcmpUsableExtIpAndID(ip_s, id, ip_d,
                                &ip_alias, &id_alias) != 0)
                        {
                                return 61;
                        }
                        if( _rtl8651_addNaptIcmpNonCandidateFlow(
                                1, ip_s, id, ip_alias, id_alias, ip_d)!= 0 ){
                                return 60;
                        }
                }


                tb = _rtl8651_getInsideNaptIcmpEntry(ip_s, id, ip_d, 1, 0);
        }


        do {} while (0);
        tb->dsid = phdr->ph_un_sw.ROMEDRV_USG._ph_dsid;

        if (((pip->ip_vhl & 0x0f) != 5) || ((pip->ip_off) & 0x2000))
        {
                if ((pip->ip_vhl & 0x0f) != 5)
                {

                        do { do { int32 accumulate = 0; if ((((ip_alias)) != 0) && (((ip_s)) != 0)){ accumulate = (((ip_s)) & 0xffff); accumulate += (( ((ip_s)) >> 16 ) & 0xffff); accumulate -= (((ip_alias)) & 0xffff); accumulate -= (( ((ip_alias)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                }

                do { int32 accumulate = 0; if (((0) != 0) && ((0) != 0)){ accumulate = ((0) & 0xffff); accumulate += (( (0) >> 16 ) & 0xffff); accumulate -= ((0) & 0xffff); accumulate -= (( (0) >> 16 ) & 0xffff); } if (((id_alias) != 0) && ((id) != 0)){ accumulate += (id); accumulate -= (id_alias); } do { accumulate += ((ic->icmp_cksum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) accumulate); } } while (0); }while(0);
        }
# 8062 "rtl8651_tblDrvFwd.c"
        ic->icmp_hun.ih_idseq.icd_id = (id_alias);


        do{ *((uint8*)(&pip->ip_src)) = (uint8)((ip_alias)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((ip_alias)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((ip_alias)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((ip_alias)); }while(0);
        return (0);
}
# 8080 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4IcmpNaptAliasOut2(struct rtl_pktHdr *phdr, struct ip *pip,struct icmp *ic)
{




        struct ip *ip;
        struct icmp *ic2=((void *)0);
        struct udphdr *ud=((void *)0);
        struct tcphdr *tc=((void *)0);
        struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s entry, *tb_tcpudp = &entry;
        rtl8651_tblDrv_naptIcmpFlowEntry_t * tb_icmp = ((void *)0);

        ipaddr_t ip_s, ip_d;

        ip = &ic->icmp_dun.id_ip.idi_ip;

        ip_s = ((uint32) (*((uint8*)(&ip->ip_dst))<<24)|(*(((uint8*)(&ip->ip_dst))+1)<<16)|(*(((uint8*)(&ip->ip_dst))+2)<<8) | *(((uint8*)(&ip->ip_dst))+3));
        ip_d =((uint32) (*((uint8*)(&ip->ip_src))<<24)|(*(((uint8*)(&ip->ip_src))+1)<<16)|(*(((uint8*)(&ip->ip_src))+2)<<8) | *(((uint8*)(&ip->ip_src))+3));

        if ((((uint16)(ip->ip_off)) & 0x1fff))
        {
                ;

                tb_tcpudp = ((void *)0);
                tb_icmp = ((void *)0);
        } else
        {
                if (ip->ip_p == 17)
                {
                        ud = (struct udphdr *) ((int8 *) ip + ( (ip->ip_vhl & 0x0f) << 2));
                        if(_rtl8651_getOutboundNaptFlow(0,ip_s, (ud->uh_dport),
                                                ip_d,(ud->uh_sport),&tb_tcpudp )!=0)
                        {
                                tb_tcpudp = ((void *)0);
                        }
                }else if (ip->ip_p == 6)
                {
                        tc = (struct tcphdr *) ((int8 *) ip + ( (ip->ip_vhl & 0x0f) << 2));
                        if(_rtl8651_getOutboundNaptFlow(1,ip_s, (tc->th_dport),
                                                ip_d,(tc->th_sport),&tb_tcpudp )!=0)
                        {
                                tb_tcpudp = ((void *)0);
                        }
                }else if (ip->ip_p == 1)
                {
                        ic2 = (struct icmp *) ((int8 *) ip + ( (ip->ip_vhl & 0x0f) << 2));
                        tb_icmp = _rtl8651_getInsideNaptIcmpEntry(ip_s, (ic2->icmp_hun.ih_idseq.icd_id), ip_d, 0, 0);
                        tb_tcpudp = ((void *)0);
                }else
                {
                        ;

                        tb_icmp = ((void *)0);
                        tb_tcpudp = ((void *)0);
                }
        }

        if (tb_tcpudp){
                ipaddr_t alias_address;
                uint16 alias_port;


                alias_address = tb_tcpudp->insideGlobalIpAddr;
                alias_port = tb_tcpudp->insideGlobalPort;

                if (tb_tcpudp->out_rt_t)
                {
                        phdr->ph_routeIdx = ((rtl8651_tblDrv_routeTable_t *)tb_tcpudp->out_rt_t-DrvTbl.route) + 1;
                }



                 do { do { int32 accumulate = 0; if ((((alias_address)) != 0) && (((ip_s)) != 0)){ accumulate = (((ip_s)) & 0xffff); accumulate += (( ((ip_s)) >> 16 ) & 0xffff); accumulate -= (((alias_address)) & 0xffff); accumulate -= (( ((alias_address)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((ip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);


                if (((pip->ip_vhl & 0x0f) != 5) || ((pip->ip_off) & 0x2000))
                {
                        if ((pip->ip_vhl & 0x0f) != 5)
                        {

                                do { do { int32 accumulate = 0; if ((((alias_address)) != 0) && (((ip_s)) != 0)){ accumulate = (((ip_s)) & 0xffff); accumulate += (( ((ip_s)) >> 16 ) & 0xffff); accumulate -= (((alias_address)) & 0xffff); accumulate -= (( ((alias_address)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                        }

                        if (ip->ip_p == 6)
                        {
                                do { int32 accumulate = 0; if (((alias_address) != 0) && ((ip_s) != 0)){ accumulate = ((ip_s) & 0xffff); accumulate += (( (ip_s) >> 16 ) & 0xffff); accumulate -= ((alias_address) & 0xffff); accumulate -= (( (alias_address) >> 16 ) & 0xffff); } if (((alias_port) != 0) && (((tc->th_dport)) != 0)){ accumulate += ((tc->th_dport)); accumulate -= (alias_port); } do { accumulate += ((ic->icmp_cksum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) accumulate); } } while (0); }while(0);
                        }else
                        {
                                do { int32 accumulate = 0; if (((alias_address) != 0) && ((ip_s) != 0)){ accumulate = ((ip_s) & 0xffff); accumulate += (( (ip_s) >> 16 ) & 0xffff); accumulate -= ((alias_address) & 0xffff); accumulate -= (( (alias_address) >> 16 ) & 0xffff); } if (((alias_port) != 0) && (((ud->uh_dport)) != 0)){ accumulate += ((ud->uh_dport)); accumulate -= (alias_port); } do { accumulate += ((ic->icmp_cksum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) accumulate); } } while (0); }while(0);
                        }
                }
# 8187 "rtl8651_tblDrvFwd.c"
                do{ *((uint8*)(&pip->ip_src)) = (uint8)((alias_address)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((alias_address)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((alias_address)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((alias_address)); }while(0);



                do{ *((uint8*)(&ip->ip_dst)) = (uint8)((alias_address)>>24); *(((uint8*)(&ip->ip_dst))+1) = (uint8)((alias_address)>>16); *(((uint8*)(&ip->ip_dst))+2) = (uint8)((alias_address)>>8); *(((uint8*)(&ip->ip_dst))+3) = (uint8)((alias_address)); }while(0);
                if (ip->ip_p == 17)
                {
                        ud->uh_dport = (alias_port);
                }
                else if (ip->ip_p == 6)
                {
                        tc->th_dport = (alias_port);
                }


                phdr->ph_un_sw.ROMEDRV_USG._ph_dsid = tb_tcpudp->dsid;

                return (0);

        }
        else if (tb_icmp){
                ipaddr_t alias_address;
                uint16 alias_id;


                alias_address = tb_icmp->insideGlobalIpAddr;
                alias_id = tb_icmp->insideGlobalId;



                 do { do { int32 accumulate = 0; if ((((alias_address)) != 0) && (((ip_s)) != 0)){ accumulate = (((ip_s)) & 0xffff); accumulate += (( ((ip_s)) >> 16 ) & 0xffff); accumulate -= (((alias_address)) & 0xffff); accumulate -= (( ((alias_address)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((ip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);


                if (((pip->ip_vhl & 0x0f) != 5) || ((pip->ip_off) & 0x2000))
                {
                        if ((pip->ip_vhl & 0x0f) != 5)
                        {

                                do { do { int32 accumulate = 0; if ((((alias_address)) != 0) && (((ip_s)) != 0)){ accumulate = (((ip_s)) & 0xffff); accumulate += (( ((ip_s)) >> 16 ) & 0xffff); accumulate -= (((alias_address)) & 0xffff); accumulate -= (( ((alias_address)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                        }

                        do { int32 accumulate = 0; if (((alias_address) != 0) && ((ip_s) != 0)){ accumulate = ((ip_s) & 0xffff); accumulate += (( (ip_s) >> 16 ) & 0xffff); accumulate -= ((alias_address) & 0xffff); accumulate -= (( (alias_address) >> 16 ) & 0xffff); } if (((alias_id) != 0) && (((ic2->icmp_hun.ih_idseq.icd_id)) != 0)){ accumulate += ((ic2->icmp_hun.ih_idseq.icd_id)); accumulate -= (alias_id); } do { accumulate += ((ic->icmp_cksum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) accumulate); } } while (0); }while(0);
                }
# 8239 "rtl8651_tblDrvFwd.c"
                do{ *((uint8*)(&pip->ip_src)) = (uint8)((alias_address)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((alias_address)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((alias_address)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((alias_address)); }while(0);



                do{ *((uint8*)(&ip->ip_dst)) = (uint8)((alias_address)>>24); *(((uint8*)(&ip->ip_dst))+1) = (uint8)((alias_address)>>16); *(((uint8*)(&ip->ip_dst))+2) = (uint8)((alias_address)>>8); *(((uint8*)(&ip->ip_dst))+3) = (uint8)((alias_address)); }while(0);
                ic2->icmp_hun.ih_idseq.icd_id = (alias_id);


                phdr->ph_un_sw.ROMEDRV_USG._ph_dsid = tb_icmp->dsid;

                return (0);
        }
        else{
                return (62);
        }
}
# 8265 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4IcmpNaptAliasOut3(struct rtl_pktHdr *phdr, struct ip *pip,struct icmp *ic)
{
        rtl8651_tblDrv_naptIcmpFlowEntry_t * icmp_tb;
        ipaddr_t ip_s, ip_d;
        uint16 id;

        ip_s = phdr->ph_sip;
        ip_d = phdr->ph_dip;
        id = (ic->icmp_hun.ih_idseq.icd_id);

        icmp_tb = _rtl8651_getInsideNaptIcmpEntry(ip_s, id, ip_d, 1, 1);

        if(icmp_tb){
                ipaddr_t ip_alias;
                uint16 id_alias;

                ip_alias = icmp_tb->insideGlobalIpAddr;
                id_alias = icmp_tb->insideGlobalId;


                if (((pip->ip_vhl & 0x0f) != 5) || ((pip->ip_off) & 0x2000))
                {
                        if (((pip->ip_vhl) & 0x0f) != 5)
                        {

                                do { do { int32 accumulate = 0; if ((((ip_alias)) != 0) && (((ip_s)) != 0)){ accumulate = (((ip_s)) & 0xffff); accumulate += (( ((ip_s)) >> 16 ) & 0xffff); accumulate -= (((ip_alias)) & 0xffff); accumulate -= (( ((ip_alias)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                        }

                        do { int32 accumulate = 0; if (((0) != 0) && ((0) != 0)){ accumulate = ((0) & 0xffff); accumulate += (( (0) >> 16 ) & 0xffff); accumulate -= ((0) & 0xffff); accumulate -= (( (0) >> 16 ) & 0xffff); } if (((id_alias) != 0) && ((id) != 0)){ accumulate += (id); accumulate -= (id_alias); } do { accumulate += ((ic->icmp_cksum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) accumulate); } } while (0); }while(0);
                }
# 8303 "rtl8651_tblDrvFwd.c"
                ic->icmp_hun.ih_idseq.icd_id = (id_alias);


                do{ *((uint8*)(&pip->ip_src)) = (uint8)((ip_alias)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((ip_alias)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((ip_alias)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((ip_alias)); }while(0);


                phdr->ph_un_sw.ROMEDRV_USG._ph_dsid = icmp_tb->dsid;

                return (0);
        }
        return (61);
}
# 8327 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4IcmpNaptAliasOut(struct rtl_pktHdr *phdr, struct ip *pip)
{
        int32 iresult;
        struct icmp *ic;

        ic = (struct icmp *) ((int8 *) pip + ((*(uint8*)pip&0xf) << 2));

        switch (ic->icmp_type)
        {
                case 8:
                case 13:
                        iresult = _rtl8651_l4IcmpNaptAliasOut1(phdr, pip, ic);
                        break;
                case 3:
                case 4:
                case 11:
                case 12:
                        iresult = _rtl8651_l4IcmpNaptAliasOut2(phdr, pip, ic);
                        break;
                case 0:
                case 14:
                        iresult = _rtl8651_l4IcmpNaptAliasOut3(phdr, pip, ic);
                        break;
                default:
                        return (61);
        }

        if (iresult == 0)
        {

                if((((uint16)(pip->ip_off)) & (0x1fff|0x2000)))
                {
                        int32 ta;
                        phdr->ph_proto = 2;
                        ta = ((uint32) (*((uint8*)(&pip->ip_src))<<24)|(*(((uint8*)(&pip->ip_src))+1)<<16)|(*(((uint8*)(&pip->ip_src))+2)<<8) | *(((uint8*)(&pip->ip_src))+3));
                        _rtl8651_updateFragCache(1, phdr->ph_sip, phdr->ph_dip, (pip->ip_id), ta, phdr->ph_routeIdx, ((void *)0), phdr->ph_un_sw.ROMEDRV_USG._ph_dsid);
                }

        }
        return (iresult);
}
# 8380 "rtl8651_tblDrvFwd.c"
static int32 _rtl8651_l4GetDeltaAckIn(struct ip * pip, struct tcphdr *tc, rtl8651_tblDrv_naptTcpUdpFlowEntry_t* tb)
{

        int32 i;
        int32 delta, ack_diff_min;
        uint32 ack;

        ack = ((uint32) (*((uint8*)(&tc->th_ack))<<24)|(*(((uint8*)(&tc->th_ack))+1)<<16)|(*(((uint8*)(&tc->th_ack))+2)<<8) | *(((uint8*)(&tc->th_ack))+3));

        delta = 0;
        ack_diff_min = -1;
        for (i = 0; i < 2; i++)
        {
                struct l4ack_data_record x;

                rtl8651_memcpy(&x,&tb->ack[i],sizeof(struct l4ack_data_record));

                if (x.active == 1)
                {
                        int32 ack_diff;

                        ack_diff = _rtl8651_l4SeqDiff(x.ack_new, ack);
                        if (ack_diff >= 0)
                        {
                                if (ack_diff_min >= 0)
                                {
                                        if (ack_diff < ack_diff_min)
                                        {
                                                delta = x.delta;
                                                ack_diff_min = ack_diff;
                                        }
                                }
                                else
                                {
                                        delta = x.delta;
                                        ack_diff_min = ack_diff;
                                }
                        }
                }
        }
        return (delta);
}
# 8433 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4UdpNaptAliasIn(struct rtl_pktHdr *phdr, struct ip *pip)
{
        struct udphdr *ud;
        ipaddr_t ip_s, ip_d, dmzhost;
        ipaddr_t ip_org = 0;
        uint16 ip_sp, ip_dp, ip_orgp = 0;
        struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s entry, *tb = &entry;
        rtl8651_tblDrv_algEntry_t *client_alg_link = ((void *)0);
        rtl8651_tblDrv_algEntry_t *server_alg_link = ((void *)0);
        rtl8651_tblDrv_naptServerPortEntry_t *tb2;
        uint32 actionFlag = 0,i,inTrigger=0;
        rtl8651_tblDrv_arpEntry_t *arp_t;
        int32 retval = -1;

        ud = (struct udphdr *) ((int8 *) pip + ((*(uint8*)pip&0xf) << 2));

        ip_s = phdr->ph_sip;
        ip_d = phdr->ph_dip;
        ip_sp = (ud->uh_sport);
        ip_dp = (ud->uh_dport);




        if(_rtl8651_getInboundNaptFlow(0,ip_d,ip_dp,ip_s,ip_sp, &tb)!=0){
                tb=((void *)0);
        }else
        {
                if (tb->toProtocolStack == 1)
                {
                        if (ip_dp != tb->insideLocalPort)
                        {
                                ud->uh_dport = (tb->insideLocalPort);
                                if (ud->uh_sum)
                                        do { int32 accumulate = 0; if (((0) != 0) && ((0) != 0)){ accumulate = ((0) & 0xffff); accumulate += (( (0) >> 16 ) & 0xffff); accumulate -= ((0) & 0xffff); accumulate -= (( (0) >> 16 ) & 0xffff); } if (((tb->insideLocalPort) != 0) && ((ip_dp) != 0)){ accumulate += (ip_dp); accumulate -= (tb->insideLocalPort); } do { accumulate += ((ud->uh_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) accumulate); } } while (0); }while(0);
                        }
                        _rtl8651_doProtoStackAction(phdr, pip);
                        _rtl8651_updateNaptConnection(tb, 0, rtl8651GlobalControl.udpTimeout);
                        return 132;
                }
        }

        tb2 = _rtl8651_getOutsideNaptServerPortMapping(0,ip_d,ip_dp);

        if (tb2 && (arp_t=_rtl8651_getArpEntry(((void *)0), tb2->localIp, 0))) {
                if (_rtl8651_isMacAccessControlPermit(&arp_t->macInfo->macAddr) == 0)
                        return 19;
        }


        client_alg_link = _rtl8651_l4FindLinkAlg(ip_sp, 0);
        if(ip_sp!=ip_dp){
                server_alg_link = _rtl8651_l4FindLinkAlg(ip_dp, 0);
        }

        if(tb2 && server_alg_link && tb == ((void *)0)){
                tb=&entry;
                if(_rtl8651_getOutboundAlgConnection(0,tb2->localIp,ip_dp-tb2->globalPort+tb2->localPort,ip_s,ip_sp, &tb)!=0){
                        tb=((void *)0);
                }
        }


        if (tb == ((void *)0)) {




                int32 local_val;
                rtl8651_tblDrv_vlanTable_t *local_vlanp = &DrvTbl.vlan[phdr->ph_vlanIdx];
                local_val = _rtl8651_ingressAcl(phdr->ph_un_sw.ROMEDRV_USG._ph_dsid, 0, local_vlanp, local_vlanp->vid, phdr->PKTHDRNXT.mbuf_first->m_data, (uint8 *) pip, 0x01, 0);
                if (((local_val > 0) && (local_val & 0x1000)) ||(local_val == 2))
                        return local_val;
        }







        if(tb)
                actionFlag |= 0x01;

        if(tb2)
                actionFlag |= 0x02;


        if(actionFlag==0)
        {
                if (_rtl8651_getTriggeredIpAddr( 0,
                                                                                phdr->ph_un_sw.ROMEDRV_USG._ph_dsid,
                                                                                0,
                                                                                ip_dp,
                                                                                &ip_org) == 0)
                {
                        if ((retval = _rtl8651_addNaptConnection( 1,
                                                                                                        (1|0x0020),
                                                                                                        0,
                                                                                                        ip_org, ip_dp, & ip_d, &ip_dp, ip_s, ip_sp)) != 0)
                        {
                                return 113;
                        }
                        tb = &entry;
                        if (_rtl8651_getInboundNaptFlow(0, ip_d, ip_dp, ip_s, ip_sp, &tb) != 0)
                        {
                                do {} while (0);
                                return 78;
                        }
                        inTrigger = 1;
                }
        }




        {
                if(client_alg_link)
                        actionFlag |= 0x04;

                if(server_alg_link)
                        actionFlag |= 0x08;
        }
# 8565 "rtl8651_tblDrvFwd.c"
        switch(actionFlag){
                case 0:
                case 4:
                case 8:
                case 12:
                        if(inTrigger==1) break;



                        {

                        ipaddr_t local_ip = 0;
                        uint16 local_port = 0;
                        uint32 flags=0;
                        uint32 algIdx=0;

                        if (_rtl8651_findInboundUpnpMapping(0, ip_s, ip_sp,ip_d, ip_dp, &local_ip, &local_port,&flags,&algIdx) != 0)
                                goto newDmzHostConn;

                        flags&=(0x0080);

                        if(actionFlag==0)
                        {
                                if((retval = _rtl8651_addAlgQosNaptConnection(1,
                                                (1|0x0020|flags),
                                                0,local_ip, local_port,&ip_d, &ip_dp, ip_s, ip_sp,algIdx))
                                                != 0)
                                {
                                        return 80;
                                }

                                tb=&entry;
                                if(_rtl8651_getInboundNaptFlow(0,ip_d,ip_dp,ip_s,ip_sp, &tb)!=0)
                                {

                                        i=_rtl8651_doProtoStackAction(phdr, pip);
                                        if(i==1) return 131;

                                        return 78;
                                }
                        }
                        else
                        {
                                tb = _rtl8651_addNaptAlgConnection(
                                                (1|0x0020|flags),
                                                0,local_ip,local_port,&ip_d, &ip_dp, ip_s, ip_sp);
                                if(!tb)
                                {
                                        return 79;
                                }
                                if(tb)
                                {
                                        tb-> tcpAckModified = 0;
                                        tb-> tcpFtpLastLineCRLFTermed = 0;
                                        tb->tcpStateINdex = 0;
                                        memset(&tb->ack[0],0,sizeof(struct l4ack_data_record)*2);
                                }


                                if( (actionFlag & 4) && (client_alg_link->fwEngAdd) && (client_alg_link->alg_inboundClientcb)){
                                        client_alg_link->alg_inboundClientcb(phdr, pip, tb);
                                        tb->alg_client_in = client_alg_link->alg_inboundClientcb;
                                }

                                if( (actionFlag & 8) && (server_alg_link->fwEngAdd) && (server_alg_link->alg_inboundServercb)){
                                        int32 r;
                                        tb->alg_server_in = server_alg_link->alg_inboundServercb;
                                        r = server_alg_link->alg_inboundServercb(phdr, pip, tb);
                                        if(r==131) {
                                                return 131;
                                        }
                                }
                        }
                        break;

                }

newDmzHostConn:



                        i=_rtl8651_doProtoStackAction(phdr, pip);
                        if(i==1) return 131;
                        if(i==2) return 112;


                if (_rtl8651_getDmzHost(phdr->ph_un_sw.ROMEDRV_USG._ph_dsid,ip_d, &dmzhost) == 0)
                {
# 8671 "rtl8651_tblDrvFwd.c"
                        if(_rtl8651_addNaptConnection(1,
                                        (1|0x0020), 0,
                                        dmzhost,ip_dp, &ip_d, &ip_dp, ip_s, ip_sp)
                                        != 0)
                        {
                                return 80;
                        }

                        tb=&entry;
                        if(_rtl8651_getInboundNaptFlow(0,ip_d,ip_dp,ip_s,ip_sp, &tb)!=0)
                                return 78;
                        break;
                }else
                        return 78;

                case 3:
                case 1:

                        if(tb->alg_client_in){
                                int r;
                                r=tb->alg_client_in(phdr, pip, tb);
                                if(r==131) {
                                        return 131;
                                }
                        }
                        if(tb->alg_server_in){
                                int r;
                                r=tb->alg_server_in(phdr, pip, tb);
                                if(r==131) {
                                        return 131;
                                }
                        }
                        break;
# 8712 "rtl8651_tblDrvFwd.c"
                case 2:

                        if(_rtl8651_addNaptConnection(1,
                                        (1|0x0020),
                                        0,tb2->localIp,ip_dp-tb2->globalPort+tb2->localPort, &ip_d, &ip_dp, ip_s, ip_sp)
                                        != 0)
                        {
                                return 80;
                        }

                        tb=&entry;

                        if(_rtl8651_getInboundNaptFlow(0,ip_d,ip_dp,ip_s,ip_sp, &tb)!=0)
                                return 78;
                        break;

                case 6:
                case 10:
                        tb = _rtl8651_addNaptAlgConnection((1|0x0020),
                                0,tb2->localIp,ip_dp-tb2->globalPort+tb2->localPort,&ip_d, &ip_dp, ip_s, ip_sp);
                        if(!tb)
                        {
                                return 79;
                        }
                        if(tb)
                        {
                                tb-> tcpAckModified = 0;
                                tb-> tcpFtpLastLineCRLFTermed = 0;
                                tb->tcpStateINdex = 0;
                                memset(&tb->ack[0],0,sizeof(struct l4ack_data_record)*2);
                        }
                        break;

                case 7:
                case 5:

                        if(client_alg_link->fwEngAdd && client_alg_link->alg_inboundClientcb){
                                client_alg_link->alg_inboundClientcb(phdr, pip, tb);
                        }
                        break;
                case 11:
                case 9:

                         if(server_alg_link->fwEngAdd && server_alg_link->alg_inboundServercb){
                                server_alg_link->alg_inboundServercb(phdr, pip, tb);
                        }
                        break;
                case 15:
                case 13:
                        if( (actionFlag & 4) && (client_alg_link->fwEngAdd) && (client_alg_link->alg_inboundClientcb)){
                                client_alg_link->alg_inboundClientcb(phdr, pip, tb);
                        }

                        if( (actionFlag & 8) && (server_alg_link->fwEngAdd) && (server_alg_link->alg_inboundServercb)){
                                server_alg_link->alg_inboundServercb(phdr, pip, tb);
                        }
                        break;

                default:
                        printk("%s: action=%d\n",__FUNCTION__,actionFlag );
                        return 82;

        }
        do {} while (0);


        tb->dsid = phdr->ph_un_sw.ROMEDRV_USG._ph_dsid;


        _rtl8651_updateNaptConnection(tb, 0, rtl8651GlobalControl.udpTimeout);

        ip_s = phdr->ph_sip;
        ip_d = phdr->ph_dip;
        ip_sp = (ud->uh_sport);
        ip_dp = (ud->uh_dport);

        ip_org = tb->insideLocalIpAddr;
        ip_orgp = tb->insideLocalPort;


        if ((!(actionFlag&0x01)) && tb)
        {
                do {} while (0);


                if ((_loggingModule[phdr->ph_un_sw.ROMEDRV_USG._ph_dsid]&0x00000010)&&_pUserLoggingFunc)
                {

                        rtl8651_logInfo_t info;
                        info.infoType = 1;
                        info.un.pkt.dsid = phdr->ph_un_sw.ROMEDRV_USG._ph_dsid;
                        info.un.pkt.sip = ip_s;
                        info.un.pkt.dip = ip_org;
                        info.un.pkt.protocol = 17;
                        info.un.pkt.direction = 1;
                        info.un.pkt.sport = ip_sp;
                        info.un.pkt.dport = ip_orgp;
                        info.action = 3;
                        (* _pUserLoggingFunc)(0x00000010, 4, &info);
# 8825 "rtl8651_tblDrvFwd.c"
                }
        }



        if (((pip->ip_vhl & 0x0f) != 5) || (((pip->ip_off) & (0x2000|0x1fff)) == 0x2000))
        {
                if ((pip->ip_vhl & 0x0f) != 5)
                {
                        do { do { int32 accumulate = 0; if ((((ip_org)) != 0) && (((ip_d)) != 0)){ accumulate = (((ip_d)) & 0xffff); accumulate += (( ((ip_d)) >> 16 ) & 0xffff); accumulate -= (((ip_org)) & 0xffff); accumulate -= (( ((ip_org)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                }

                if (ud->uh_sum)
                {
                        do { int32 accumulate = 0; if (((ip_org) != 0) && ((ip_d) != 0)){ accumulate = ((ip_d) & 0xffff); accumulate += (( (ip_d) >> 16 ) & 0xffff); accumulate -= ((ip_org) & 0xffff); accumulate -= (( (ip_org) >> 16 ) & 0xffff); } if (((ip_orgp) != 0) && ((ip_dp) != 0)){ accumulate += (ip_dp); accumulate -= (ip_orgp); } do { accumulate += ((ud->uh_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) accumulate); } } while (0); }while(0);
                }

                if ((((uint16)(pip->ip_off)) & (0x1fff|0x2000)))
                {
                        phdr->ph_proto = 2;
                        _rtl8651_updateFragCache(0, phdr->ph_sip, phdr->ph_dip, (pip->ip_id), ip_org, 0, ((void *)0), phdr->ph_un_sw.ROMEDRV_USG._ph_dsid);

                        _rtl8651_fragmentShortestPathCacheSet_firstHalf(phdr, (uint8*)ud, pip, ip_s, ip_d, 1, ip_org);

                }
        }



        ud->uh_dport = (ip_orgp);

        do{ *((uint8*)(&pip->ip_dst)) = (uint8)((ip_org)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((ip_org)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((ip_org)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((ip_org)); }while(0);

        return (0);
}
# 8871 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4UdpNatAlgAliasIn(struct rtl_pktHdr *phdr, struct ip *pip, rtl8651_tblDrv_natEntry_t *natEntry)
{
        struct udphdr *ud;
        ipaddr_t ip_s, ip_d, ip_org = 0;
        uint16 ip_sp, ip_dp, ip_orgp = 0;
        struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s entry, *tb = &entry;
        rtl8651_tblDrv_algEntry_t *client_alg_link = ((void *)0);
        rtl8651_tblDrv_algEntry_t *server_alg_link = ((void *)0);
        uint32 actionFlag = 0;

        ip_s = phdr->ph_sip;
        ip_d = phdr->ph_dip;

        if (ip_d == natEntry->localIp)
        {
                return 85;
        }

        ud = (struct udphdr *) ((int8 *) pip + ((*(uint8*)pip&0xf) << 2));

        ip_sp = (ud->uh_sport);
        ip_dp = (ud->uh_dport);

        client_alg_link = _rtl8651_l4FindLinkAlg(ip_sp, 0);
        if(ip_sp != ip_dp){
                server_alg_link = _rtl8651_l4FindLinkAlg(ip_dp, 0);
        }

        if(client_alg_link == ((void *)0) && server_alg_link == ((void *)0)){
                return 85;
        }


        if(_rtl8651_getInboundNaptFlow(0,ip_d,ip_dp,ip_s,ip_sp, &tb)!=0){
                tb=((void *)0);
        }







        if(tb)
                actionFlag |= 0x01;

        if(client_alg_link)
                actionFlag |= 0x04;

        if(server_alg_link)
                actionFlag |= 0x08;





        switch(actionFlag){
                case 1:

                        if(tb->alg_client_in){
                                int r;
                                r=tb->alg_client_in(phdr, pip, tb);
                                if(r==131) {
                                        return 131;
                                }
                        }
                        if(tb->alg_server_in){
                                int r;
                                r=tb->alg_server_in(phdr, pip, tb);
                                if(r==131) {
                                        return 131;
                                }
                        }
                        break;
                case 4:

                        tb = _rtl8651_addNaptAlgConnection(
                                        (1|0x0020),
                                        0,natEntry->localIp, ip_dp, &ip_d, &ip_dp, ip_s, ip_sp);
                        if(!tb)
                                return 83;
                        if(client_alg_link->fwEngAdd && client_alg_link->alg_inboundClientcb){
                                tb->natlink = 1;
                                client_alg_link->alg_inboundClientcb(phdr, pip, tb);
                        }
                        break;
                case 8:

                        tb = _rtl8651_addNaptAlgConnection(
                                        (1|0x0020),
                                        0,natEntry->localIp, ip_dp, &ip_d, &ip_dp, ip_s, ip_sp);
                        if(!tb)
                                return 84;
                         if( server_alg_link->fwEngAdd && server_alg_link->alg_outboundServercb){
                                int r;
                                tb->natlink = 1;
                                r=server_alg_link->alg_outboundServercb(phdr, pip, tb);
                                if(r==131) return 131;
                         }
                        break;
                case 5:

                        if(client_alg_link->fwEngAdd && client_alg_link->alg_inboundClientcb){
                                client_alg_link->alg_inboundClientcb(phdr, pip, tb);
                        }
                        break;
                case 9:

                         if(server_alg_link->fwEngAdd && server_alg_link->alg_inboundServercb){
                                server_alg_link->alg_inboundServercb(phdr, pip, tb);
                         }
                        break;

                default:
                        printk("%s: action=%d\n",__FUNCTION__,actionFlag);
                        return 86;
        }

        do {} while (0);


        _rtl8651_updateNaptConnection(tb, 0, rtl8651GlobalControl.udpTimeout);

        ip_s = phdr->ph_sip;
        ip_d = phdr->ph_dip;
        ip_sp = (ud->uh_sport);
        ip_dp = (ud->uh_dport);

        ip_org = tb->insideLocalIpAddr;
        ip_orgp = tb->insideLocalPort;



        if (((pip->ip_vhl & 0x0f) != 5) || (((pip->ip_off) & (0x2000|0x1fff)) == 0x2000))
        {
                if ((pip->ip_vhl & 0x0f) != 5)
                {
                        do { do { int32 accumulate = 0; if ((((ip_org)) != 0) && (((ip_d)) != 0)){ accumulate = (((ip_d)) & 0xffff); accumulate += (( ((ip_d)) >> 16 ) & 0xffff); accumulate -= (((ip_org)) & 0xffff); accumulate -= (( ((ip_org)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                }
                if(ud->uh_sum)
                {
                        do { int32 accumulate = 0; if (((ip_org) != 0) && ((ip_d) != 0)){ accumulate = ((ip_d) & 0xffff); accumulate += (( (ip_d) >> 16 ) & 0xffff); accumulate -= ((ip_org) & 0xffff); accumulate -= (( (ip_org) >> 16 ) & 0xffff); } if (((ip_orgp) != 0) && ((ip_dp) != 0)){ accumulate += (ip_dp); accumulate -= (ip_orgp); } do { accumulate += ((ud->uh_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) accumulate); } } while (0); }while(0);
                }
        }



        ud->uh_dport = (ip_orgp);

        do{ *((uint8*)(&pip->ip_dst)) = (uint8)((ip_org)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((ip_org)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((ip_org)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((ip_org)); }while(0);

        return (0);
}
# 9036 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4UdpNaptAliasOut(struct rtl_pktHdr *phdr, struct ip *pip)
{
        struct udphdr *ud;
        ipaddr_t ip_s, ip_d, ip_alias = 0;
        uint16 ip_sp, ip_dp, ip_aliasp = 0;
        struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s entry, *tb=&entry;
        rtl8651_tblDrv_algEntry_t *client_alg_link = ((void *)0);
        rtl8651_tblDrv_algEntry_t *server_alg_link = ((void *)0);

        rtl8651_tblDrv_naptServerPortEntry_t *tb2;
# 9063 "rtl8651_tblDrvFwd.c"
        int32 isUpnpMapping = 0;
        ipaddr_t upnpExtIp;
        uint16 upnpExtPort;
        uint32 upnpFlags;
        uint32 upnpAlgIdx;

        uint32 actionFlag = 0;
        int inTrigger = 0;

        ud = (struct udphdr *) ((int8 *) pip + ((*(uint8*)pip&0xf) << 2));

        ip_s = phdr->ph_sip;
        ip_d = phdr->ph_dip;
        ip_sp = (ud->uh_sport);
        ip_dp = (ud->uh_dport);




        if( _rtl8651_getOutboundNaptFlow(0,ip_s,ip_sp,ip_d,ip_dp, &tb) != 0 )
        {
                tb = &entry;
                if( _rtl8651_getOutboundAlgConnection(0,ip_s,ip_sp,ip_d,ip_dp, &tb) != 0 )
                {
                        tb = ((void *)0);
                }
        }




        tb2 = _rtl8651_getInsideNaptServerPortMapping(0,ip_s,ip_sp);




        client_alg_link = _rtl8651_l4FindLinkAlg(ip_dp, 0);

        if(ip_dp != ip_sp)
        {
                if( tb )
                {
                        server_alg_link = _rtl8651_l4FindLinkAlg(tb->insideGlobalPort, 0);
                }else
                {
                        server_alg_link = _rtl8651_l4FindLinkAlg(ip_sp, 0);
                }
        }
# 9121 "rtl8651_tblDrvFwd.c"
        if ((tb == ((void *)0)) && (tb2 == ((void *)0)))
        {
                if (_rtl8651_findOutboundUpnpMapping(
                        0,
                        ip_s,
                        ip_sp,
                        &upnpExtIp,
                        &upnpExtPort,
                        ip_d,
                        ip_dp,
                        &upnpFlags,
                        &upnpAlgIdx) == 0)
                {
                        isUpnpMapping = 1;
                }
        }
# 9147 "rtl8651_tblDrvFwd.c"
                if ((tb == ((void *)0)) && (tb2 == ((void *)0)) && (isUpnpMapping == 0))
                {
                        ipaddr_t redirectIp;
                        uint16 redirectPort;
                        if (_rtl8651_findNaptRedirectEntry(0, ip_s, ip_sp, ip_d, ip_dp, &redirectIp, &redirectPort, 1, phdr->ph_vlanIdx) == 0)
                        {

                                do{ *((uint8*)(&pip->ip_dst)) = (uint8)((redirectIp)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((redirectIp)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((redirectIp)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((redirectIp)); }while(0);
                                ud->uh_dport = (redirectPort);

                                if (ud->uh_sum)
                                        do { int32 accumulate = 0; if (((redirectIp) != 0) && ((ip_d) != 0)){ accumulate = ((ip_d) & 0xffff); accumulate += (( (ip_d) >> 16 ) & 0xffff); accumulate -= ((redirectIp) & 0xffff); accumulate -= (( (redirectIp) >> 16 ) & 0xffff); } if (((redirectPort) != 0) && ((ip_dp) != 0)){ accumulate += (ip_dp); accumulate -= (redirectPort); } do { accumulate += ((ud->uh_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) accumulate); } } while (0); }while(0);
                                do { do { int32 accumulate = 0; if ((((redirectIp)) != 0) && (((ip_d)) != 0)){ accumulate = (((ip_d)) & 0xffff); accumulate += (( ((ip_d)) >> 16 ) & 0xffff); accumulate -= (((redirectIp)) & 0xffff); accumulate -= (( ((redirectIp)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);

                                if (((((uint16)(pip->ip_off)) & (0x1fff|0x2000)) == 0x2000))
                                {
                                        _rtl8651_updateFragCache(5, ip_s, ip_d, (pip->ip_id), redirectIp, 0, ((void *)0), phdr->ph_un_sw.ROMEDRV_USG._ph_dsid);
                                }

                                if (_rtl8651_fragQueueProcess == 1)
                                {
                                        _rtl8651_fragQueueNaptRedirect_MatchedIP = redirectIp;
                                }

                                return 132;
                        }
                }


        if (tb == ((void *)0)) {




                int32 local_val;
                rtl8651_tblDrv_vlanTable_t *local_vlanp = &DrvTbl.vlan[phdr->ph_vlanIdx];
                local_val = _rtl8651_ingressAcl(phdr->ph_un_sw.ROMEDRV_USG._ph_dsid, 0, local_vlanp, local_vlanp->vid, phdr->PKTHDRNXT.mbuf_first->m_data, (uint8 *) pip, 0x01, 0);
                if (((local_val > 0) && (local_val & 0x1000)) ||(local_val == 2))
                        return local_val;
        }







        if(tb)
        {
                actionFlag |= 0x01;
        }

        if(tb2)
        {
                actionFlag |= 0x02;
        }

        if (isUpnpMapping == 1)
        {
                actionFlag |= 0x10;
        }



        if ( actionFlag==0 )
        {
                if (_rtl8651_tryActiveTriggerPort( 0,
                                                                                phdr->ph_un_sw.ROMEDRV_USG._ph_dsid,
                                                                                ip_dp,
                                                                                0,
                                                                                ip_s) > 0)
                {
                        inTrigger = 1;
                }
        }





        {
                if(client_alg_link)
                {
                        actionFlag |= 0x04;
                }

                if(server_alg_link)
                {
                        actionFlag |= 0x08;
                }
        }
# 9253 "rtl8651_tblDrvFwd.c"
        switch ( actionFlag )
        {

                case 0:


                        _rtl8651_softNaptPolicyRoute(0x40,ip_s,ip_d,ip_dp,&ip_alias,&ip_aliasp);
                        if (ip_alias)
                        {



                                if ((rtl8651_drvStaticUdpNaptPortTranslation == 1) &&
                                        (_rtl8651_l4CheckOccupiedConnection(0, phdr->ph_un_sw.ROMEDRV_USG._ph_dsid, ip_s, ip_sp, ip_alias, ip_sp, ip_d, ip_dp) == 0))
                                {

                                        if (_rtl8651_addNaptConnection(1,
                                                        (1|0x0002|0x0020|0x0040|0x0100),
                                                        0, ip_s, ip_sp, &ip_alias, &ip_sp,
                                                        (rtl8651_drvInexactUdpNaptEnable?0:ip_d),(rtl8651_drvInexactUdpNaptEnable?0:ip_dp))
                                                        == 0)
                                                ip_aliasp = ip_sp;
                                        else
                                                goto UdpPolicyDynamicPortAssign;
                                }else
                                {
UdpPolicyDynamicPortAssign:
                                        if(_rtl8651_addNaptConnection(1,
                                                        (1|0x0002|0x0020|0x0040),
                                                        0,ip_s,ip_sp, &ip_alias,&ip_aliasp,
                                                        (rtl8651_drvInexactUdpNaptEnable?0:ip_d),(rtl8651_drvInexactUdpNaptEnable?0:ip_dp))
                                                        != 0)
                                                return 74;
                                }






                        }else
                        {


                                if (rtl8651_drvStaticUdpNaptPortTranslation == 1)
                                {
                                        ip_alias = _rtl8651_getNaptInsideGlobalIpAddr(0, ip_s, ip_sp, ip_d, ip_dp);

                                        if ((!ip_alias) || (_rtl8651_l4CheckOccupiedConnection(0, phdr->ph_un_sw.ROMEDRV_USG._ph_dsid, ip_s, ip_sp, ip_alias, ip_sp, ip_d, ip_dp) == 1))
                                                goto UdpNormalDynamicPortAssign;

                                        if (_rtl8651_addNaptConnection(1,
                                                        (1|0x0020|0x0040|0x0100),
                                                        0, ip_s, ip_sp, &ip_alias, &ip_sp,
                                                        (rtl8651_drvInexactUdpNaptEnable?0:ip_d), (rtl8651_drvInexactUdpNaptEnable?0:ip_dp))
                                                        == 0)
                                                ip_aliasp = ip_sp;
                                        else
                                                goto UdpNormalDynamicPortAssign;
                                }else
                                {
UdpNormalDynamicPortAssign:
                                        if(_rtl8651_addNaptConnection(1,
                                                        (0|0x0020|0x0040),
                                                        0, ip_s, ip_sp, &ip_alias, &ip_aliasp,
                                                        (rtl8651_drvInexactUdpNaptEnable?0:ip_d), (rtl8651_drvInexactUdpNaptEnable?0:ip_dp))
                                                        != 0 )
                                                return 74;
                                }
# 9331 "rtl8651_tblDrvFwd.c"
                        }
                        tb=&entry;
                        if(_rtl8651_getOutboundNaptFlow(0,ip_s,ip_sp,ip_d,ip_dp, &tb)!=0)
                        {
                                return 72;
                        }
                        break;


                case 1:
                case 3:
                case 17:




                        if(tb->alg_client_out){
                                int r;
                                r=tb->alg_client_out(phdr, pip, tb);
                                if(r==131) {
                                        return 131;
                                }
                        }
                        if(tb->alg_server_out){
                                int r;
                                r=tb->alg_server_out(phdr, pip, tb);
                                if(r==131) {
                                        return 131;
                                }
                        }
                        break;




                case 2:
                case 10:


                case 16:
                case 24:



                        if (tb2)
                        {
                                do {} while (0);

                                ip_alias = tb2->globalIp;
                                ip_aliasp = ip_sp - tb2->localPort + tb2->globalPort;
                        }else
                        {
                                do {} while (0);

                                ip_alias = upnpExtIp;
                                ip_aliasp = upnpExtPort;
                        }

                        if(_rtl8651_addNaptConnection(1,
                                        (1|0x0020|0x0040),
                                        0,ip_s,ip_sp,&ip_alias,&ip_aliasp,ip_d,ip_dp)!=0)
                        {
                                goto ServerPortOut;
                        }

                        tb=&entry;
                        if(_rtl8651_getOutboundNaptFlow(0,ip_s,ip_sp,ip_d,ip_dp, &tb)!=0){
                                goto ServerPortOut;
                        }

                        if (actionFlag & 0x08)
                                goto serverAlg_entry_run;
                        break;

                ServerPortOut:





                        ud->uh_sport = (ip_aliasp);
                        do{ *((uint8*)(&pip->ip_src)) = (uint8)((ip_alias)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((ip_alias)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((ip_alias)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((ip_alias)); }while(0);

                        return 0;



                case 6:
                case 4:







                case 20:



                        _rtl8651_softNaptPolicyRoute(0x40,ip_s,ip_d,ip_dp,&ip_alias,&ip_aliasp);
                        if (ip_alias)
                        {
                                tb = _rtl8651_addNaptAlgConnection(
                                                (1|0x0020|0x0040),
                                                0,ip_s,ip_sp,&ip_alias,&ip_aliasp,ip_d,ip_dp);
                        }else
                        {
                                tb = _rtl8651_addNaptAlgConnection(
                                        (0|0x0020|0x0040),
                                        0,ip_s,ip_sp,&ip_alias,&ip_aliasp,ip_d,ip_dp);
                        }

                        if(!tb)
                                return 76;
                        if ( client_alg_link->fwEngAdd && client_alg_link->alg_outboundClientcb){
                                int r;
                                tb->alg_client_out=client_alg_link->alg_outboundClientcb;
                                r = client_alg_link->alg_outboundClientcb(phdr, pip, tb);
                                if(r==131) {
                                        return 131;
                                }
                        }
                        break;



                case 7:
                case 5:

                case 19:



                        if ( client_alg_link->fwEngAdd && client_alg_link->alg_outboundClientcb){
                                int r;
                                tb->alg_client_out=client_alg_link->alg_outboundClientcb;
                                r = client_alg_link->alg_outboundClientcb(phdr, pip, tb);
                                if(r==131) {
                                        return 131;
                                }
                        }
                        break;



                case 8:




                        tb = _rtl8651_addNaptAlgConnection(
                                        (0|0x0020|0x0040),
                                        0,ip_s,ip_sp,&ip_alias,&ip_aliasp,ip_d,ip_dp);
                        if(!tb)
                                return 75;




                case 9:
                case 11:



serverAlg_entry_run:

                         if(server_alg_link->fwEngAdd && server_alg_link->alg_outboundServercb){
                                int r;
                                tb->alg_server_out=server_alg_link->alg_outboundServercb;
                                r=server_alg_link->alg_outboundServercb(phdr, pip, tb);
                                if(r==131) {
                                        return 131;
                                }
                         }
                        break;



                case 12:
                case 14:

                case 28:


                        tb = _rtl8651_addNaptAlgConnection(
                                (0|0x0020|0x0040),
                                0,ip_s,ip_sp, &ip_alias,&ip_aliasp,ip_d,ip_dp);
                        if(!tb)
                                return 75;




                case 13:
                case 15:

                case 29:


                        if ( client_alg_link->fwEngAdd && client_alg_link->alg_outboundClientcb){
                                int r;
                                tb->alg_client_out=client_alg_link->alg_outboundClientcb;
                                r = client_alg_link->alg_outboundClientcb(phdr, pip, tb);
                                if(r==131) {
                                        return 131;
                                }
                        }
                        if ( server_alg_link->fwEngAdd && server_alg_link->alg_outboundServercb){
                                int r;
                                tb->alg_server_out=server_alg_link->alg_outboundServercb;
                                r = server_alg_link->alg_outboundServercb(phdr, pip, tb);
                                if(r==131) {
                                        return 131;
                                }
                        }
                        break;



                default:
                        printk("%s: action=%d\n",__FUNCTION__,actionFlag );
                        return (77);
        }

        do {} while (0);


        do {} while (0);
        tb->out_rt_t = (void *)&DrvTbl.route[phdr->ph_routeIdx-1];
        tb->dsid = phdr->ph_un_sw.ROMEDRV_USG._ph_dsid;


        _rtl8651_updateNaptConnection(tb, 0, rtl8651GlobalControl.udpTimeout);

        ip_s = phdr->ph_sip;
        ip_d = phdr->ph_dip;
        ip_sp = (ud->uh_sport);
        ip_dp = (ud->uh_dport);

        ip_alias = tb->insideGlobalIpAddr;
        ip_aliasp = tb->insideGlobalPort;


        if ((!(actionFlag&0x01)) && tb)
        {
                do {} while (0);


                if ((_loggingModule[phdr->ph_un_sw.ROMEDRV_USG._ph_dsid]&0x00000010)&&_pUserLoggingFunc)
                {

                        rtl8651_logInfo_t info;

                        info.infoType = 1;
                        info.un.pkt.dsid = phdr->ph_un_sw.ROMEDRV_USG._ph_dsid;
                        info.un.pkt.sip = ip_s;
                        info.un.pkt.dip = ip_d;
                        info.un.pkt.protocol = 17;
                        info.un.pkt.direction = 0;
                        info.un.pkt.sport = ip_sp;
                        info.un.pkt.dport = ip_dp;
                        info.action = 3;
                        (* _pUserLoggingFunc)(0x00000010, 3, &info);
# 9609 "rtl8651_tblDrvFwd.c"
                }
        }



        if (((pip->ip_vhl & 0x0f) != 5) || (((pip->ip_off) & (0x2000|0x1fff)) == 0x2000))
        {
                if ((pip->ip_vhl & 0x0f) != 5)
                {

                        do { do { int32 accumulate = 0; if ((((ip_alias)) != 0) && (((ip_s)) != 0)){ accumulate = (((ip_s)) & 0xffff); accumulate += (( ((ip_s)) >> 16 ) & 0xffff); accumulate -= (((ip_alias)) & 0xffff); accumulate -= (( ((ip_alias)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                }

                if( ud->uh_sum)
                {
                        do { int32 accumulate = 0; if (((ip_alias) != 0) && ((ip_s) != 0)){ accumulate = ((ip_s) & 0xffff); accumulate += (( (ip_s) >> 16 ) & 0xffff); accumulate -= ((ip_alias) & 0xffff); accumulate -= (( (ip_alias) >> 16 ) & 0xffff); } if (((ip_aliasp) != 0) && ((ip_sp) != 0)){ accumulate += (ip_sp); accumulate -= (ip_aliasp); } do { accumulate += ((ud->uh_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) accumulate); } } while (0); }while(0);
                }

                if (((pip->ip_off) & (0x2000|0x1fff)) == 0x2000)
                {
                        phdr->ph_proto = 2;
                        _rtl8651_updateFragCache(1, ip_s, ip_d, (pip->ip_id), ip_alias, phdr->ph_routeIdx, ((void *)0), phdr->ph_un_sw.ROMEDRV_USG._ph_dsid);

                        _rtl8651_fragmentShortestPathCacheSet_firstHalf(phdr, (uint8*)ud, pip, ip_s, ip_d, 0, ip_alias);

                }
        }




        ud->uh_sport = (ip_aliasp);


        do{ *((uint8*)(&pip->ip_src)) = (uint8)((ip_alias)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((ip_alias)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((ip_alias)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((ip_alias)); }while(0);

        return (0);
}
# 9660 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4UdpNatAlgAliasOut(struct rtl_pktHdr *phdr, struct ip *pip, rtl8651_tblDrv_natEntry_t *natEntry)
{
        struct udphdr *ud;
        ipaddr_t ip_s, ip_d, ip_alias = 0;
        uint16 ip_sp, ip_dp, ip_aliasp = 0;
        struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s entry, *tb=&entry;
        rtl8651_tblDrv_algEntry_t *client_alg_link = ((void *)0);
        rtl8651_tblDrv_algEntry_t *server_alg_link = ((void *)0);

        uint32 actionFlag = 0;

        ip_s = phdr->ph_sip;
        ip_d = phdr->ph_dip;

        if (ip_s == natEntry->globalIp)
        {
                return 88;
        }

        ud = (struct udphdr *) ((int8 *) pip + ((*(uint8*)pip&0xf) << 2));

        ip_sp = (ud->uh_sport);
        ip_dp = (ud->uh_dport);

        client_alg_link = _rtl8651_l4FindLinkAlg(ip_dp, 0);
        if(ip_dp != ip_sp){
                server_alg_link = _rtl8651_l4FindLinkAlg(ip_sp, 0);
        }

        if(client_alg_link == ((void *)0) && server_alg_link == ((void *)0)){
                return 88;
        }

        if(_rtl8651_getOutboundAlgConnection(0,ip_s,ip_sp,ip_d,ip_dp, &tb)!=0){
                        tb=((void *)0);
        }







        if(tb)
                actionFlag |= 0x01;

        if(client_alg_link)
                actionFlag |= 0x04;

        if(server_alg_link)
                actionFlag |= 0x08;





        switch(actionFlag){
                case 1:

                        if(tb->alg_client_out){
                                int r;
                                r=tb->alg_client_out(phdr, pip, tb);
                                if(r==131) return 131;
                        }
                        if(tb->alg_server_out){
                                int r;
                                r=tb->alg_server_out(phdr, pip, tb);
                                if(r==131) return 131;
                        }
                        break;
                case 4:

                         ip_alias = natEntry->globalIp;
                         ip_aliasp = ip_sp;
                        tb = _rtl8651_addNaptAlgConnection(
                                        (1|0x0020|0x0040),
                                        0,ip_s,ip_sp, &ip_alias,&ip_aliasp,ip_d,ip_dp);
                        if(!tb)
                                return 89;
                        if ( client_alg_link->fwEngAdd && client_alg_link->alg_outboundClientcb){
                                int r;
                                tb->natlink = 1;
                                r=client_alg_link->alg_outboundClientcb(phdr, pip, tb);
                                if(r==131) return 131;
                        }
                        break;
                case 5:

                        if ( client_alg_link->fwEngAdd && client_alg_link->alg_outboundClientcb){
                                int r;
                                r=client_alg_link->alg_outboundClientcb(phdr, pip, tb);
                                if(r==131) return 131;
                        }
                        break;
                case 8:

                         ip_alias = natEntry->globalIp;
                         ip_aliasp = ip_sp;
                        tb = _rtl8651_addNaptAlgConnection(
                                        (1|0x0020|0x0040),
                                        0,ip_s,ip_sp, &ip_alias,&ip_aliasp,ip_d,ip_dp);
                        if(!tb)
                                return 90;

                        if ( server_alg_link->fwEngAdd && server_alg_link->alg_outboundServercb){
                                int r;
                                tb->natlink = 1;
                                r=server_alg_link->alg_outboundServercb(phdr, pip, tb);
                                if(r==131) return 131;
                        }
                        break;

                case 9:

                         if(server_alg_link->fwEngAdd && server_alg_link->alg_outboundServercb){
                                int r;
                                r=server_alg_link->alg_outboundServercb(phdr, pip, tb);
                                if(r==131) return 131;
                         }
                        break;

                default:
                        printk("%s: action=%d\n",__FUNCTION__,actionFlag );
                        return 87;
        }

        do {} while (0);


        _rtl8651_updateNaptConnection(tb, 0, rtl8651GlobalControl.udpTimeout);

        ip_s = phdr->ph_sip;
        ip_d = phdr->ph_dip;
        ip_sp = (ud->uh_sport);
        ip_dp = (ud->uh_dport);

        ip_alias = tb->insideGlobalIpAddr;
        ip_aliasp = tb->insideGlobalPort;


        if (((pip->ip_vhl & 0x0f) != 5) || (((pip->ip_off) & (0x2000 | 0x1fff)) == 0x2000))
        {

                if ((pip->ip_vhl & 0x0f) != 5)
                {
                        do { do { int32 accumulate = 0; if ((((ip_alias)) != 0) && (((ip_s)) != 0)){ accumulate = (((ip_s)) & 0xffff); accumulate += (( ((ip_s)) >> 16 ) & 0xffff); accumulate -= (((ip_alias)) & 0xffff); accumulate -= (( ((ip_alias)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                }

                if (ud->uh_sum)
                {
                        do { int32 accumulate = 0; if (((ip_alias) != 0) && ((ip_s) != 0)){ accumulate = ((ip_s) & 0xffff); accumulate += (( (ip_s) >> 16 ) & 0xffff); accumulate -= ((ip_alias) & 0xffff); accumulate -= (( (ip_alias) >> 16 ) & 0xffff); } if (((ip_aliasp) != 0) && ((ip_sp) != 0)){ accumulate += (ip_sp); accumulate -= (ip_aliasp); } do { accumulate += ((ud->uh_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) accumulate); } } while (0); }while(0);
                }
        }



        ud->uh_sport = (ip_aliasp);


        do{ *((uint8*)(&pip->ip_src)) = (uint8)((ip_alias)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((ip_alias)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((ip_alias)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((ip_alias)); }while(0);

        return (0);
}
# 9833 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4TcpNaptAliasIn(struct rtl_pktHdr *phdr, struct ip *pip)
{
        struct tcphdr *tc;
        ipaddr_t ip_s, ip_d, ip_org = 0, dmzhost=0;
        uint16 ip_sp, ip_dp, ip_orgp = 0;
        struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s entry, *tb = &entry;
        int32 accumulate = 0;
        rtl8651_tblDrv_algEntry_t *client_alg_link = ((void *)0);
        rtl8651_tblDrv_algEntry_t *server_alg_link = ((void *)0);
        rtl8651_tblDrv_naptServerPortEntry_t *tb2;
        uint32 actionFlag = 0,i,inTrigger=0;
        rtl8651_tblDrv_pppTable_t *thisPPPoE;
        rtl8651_tblDrv_arpEntry_t *arp_t;
        uint16 mtu;
        int8 initFlag = 3;
        int32 retval = -1;


        tc = (struct tcphdr *) ((int8 *) pip + ((*(uint8*)pip&0xf) << 2));

        ip_s = phdr->ph_sip;
        ip_d = phdr->ph_dip;
        ip_sp = (tc->th_sport);
        ip_dp = (tc->th_dport);







        if(_rtl8651_getInboundNaptFlow(1,ip_d,ip_dp,ip_s,ip_sp, &tb)!=0){
                tb=((void *)0);
        }else
        {
                if (tb->toProtocolStack == 1)
                {
                        if (ip_dp != tb->insideLocalPort)
                        {
                                tc->th_dport = (tb->insideLocalPort);
                                do { int32 accumulate = 0; if (((0) != 0) && ((0) != 0)){ accumulate = ((0) & 0xffff); accumulate += (( (0) >> 16 ) & 0xffff); accumulate -= ((0) & 0xffff); accumulate -= (( (0) >> 16 ) & 0xffff); } if (((tb->insideLocalPort) != 0) && ((ip_dp) != 0)){ accumulate += (ip_dp); accumulate -= (tb->insideLocalPort); } do { accumulate += ((tc->th_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) accumulate); } } while (0); }while(0);
                        }
                        _rtl8651_doProtoStackAction(phdr, pip);
                        _rtl8651_l4TcpMonitorIn(tc, tb);
                        return 132;
                }
        }

        tb2 = _rtl8651_getOutsideNaptServerPortMapping(1,ip_d,ip_dp);

        if (tb2 && (arp_t=_rtl8651_getArpEntry(((void *)0), tb2->localIp, 0))) {
                if (_rtl8651_isMacAccessControlPermit(&arp_t->macInfo->macAddr) == 0)
                        return 19;
        }

        client_alg_link = _rtl8651_l4FindLinkAlg(ip_sp, 1);
        if(ip_sp != ip_dp){
                server_alg_link = _rtl8651_l4FindLinkAlg(ip_dp, 1);
        }
# 9902 "rtl8651_tblDrvFwd.c"
        if (tb == ((void *)0)) {




                int32 local_val;
                rtl8651_tblDrv_vlanTable_t *local_vlanp = &DrvTbl.vlan[phdr->ph_vlanIdx];
                local_val = _rtl8651_ingressAcl(phdr->ph_un_sw.ROMEDRV_USG._ph_dsid, 0, local_vlanp, local_vlanp->vid, phdr->PKTHDRNXT.mbuf_first->m_data, (uint8 *) pip, 0x01, 0);
                if (((local_val > 0) && (local_val & 0x1000)) ||(local_val == 2))
                        return local_val;
        }




        if(tc->th_flags == 0x02)
                actionFlag |= 0x01;

        if(tb)
                actionFlag |= 0x02;

        if(tb2)
                actionFlag |= 0x04;


        if ((actionFlag == 0x01) || ((actionFlag == 0) && rtl8651_drvWeakTcpNaptEnable))



        {





                if (actionFlag == 0x01)
                        initFlag = 3;
                else
                        initFlag = 5;


                if (_rtl8651_getTriggeredIpAddr( 1,
                                                                                phdr->ph_un_sw.ROMEDRV_USG._ph_dsid,
                                                                                0,
                                                                                ip_dp,
                                                                                &ip_org) == 0)
                {
                        if ((retval = _rtl8651_addNaptConnection( 1,
                                                                                                        (1|0x0020),
                                                                                                        initFlag,
                                                                                                        ip_org, ip_dp, &ip_d, &ip_dp, ip_s, ip_sp)) != 0)
                        {
                                return 113;
                        }
                        tb = &entry;
                        if (_rtl8651_getInboundNaptFlow(1, ip_d, ip_dp, ip_s, ip_sp, &tb) != 0)
                        {
                                do {} while (0);
                                return 112;
                        }
                        inTrigger = 1;
                }

        }



        {
                if(client_alg_link)
                        actionFlag |= 0x08;

                if(server_alg_link)
                        actionFlag |= 0x10;
        }
# 10000 "rtl8651_tblDrvFwd.c"
        if((actionFlag&(0x01|0x02))==0)
        {
                if (actionFlag == 0x04)
                {
                        initFlag = 5;
                }else if (rtl8651_drvWeakTcpNaptEnable)
                {




                        initFlag = 5;
                        actionFlag |= 0x01;
                }else
                {
                        actionFlag = 0;
                }
        }
# 10037 "rtl8651_tblDrvFwd.c"
if((actionFlag&(0x01|0x02))==(0x01|0x02))
{

        if ((tb->tcpFlag > (1 - 1)) &&
                (tb->tcpFlag < (8 - 1)) &&
                (tb->tcpFlag != (3 - 1)))
        {
                return 112;
        }
        actionFlag = 3;
}

        switch(actionFlag){
        case 0:

                        i=_rtl8651_doProtoStackAction(phdr, pip);
                        if(i==1) return 131;

                return 112;
        case 1:
        case 9:
        case 17:

                if(inTrigger==1) {

                        break;
                }




                {

                        ipaddr_t local_ip = 0;
                        uint16 local_port = 0;
                        uint32 flags = 0, algIdx = 0;

                        if (_rtl8651_findInboundUpnpMapping(1, ip_s, ip_sp,ip_d, ip_dp, &local_ip, &local_port, &flags, &algIdx) != 0)
                        {
                                goto newDmzHostConn;
                        }

                        if(actionFlag==1)
                        {
                                struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s ttbe,*ttb;
                                ttb=&ttbe;
                                if(_rtl8651_getInboundNaptFlow(1,ip_d,ip_dp,ip_s,20, &ttb)==0) {
                                        if(ttb->tcpFlag==0) _rtl8651_delNaptConnection(ttb);
                                }

                                if(_rtl8651_addAlgQosNaptConnection(1,
                                                (1|0x0020|(flags & 0x0080)),
                                                3,
                                                local_ip,local_port,
                                                &ip_d, &ip_dp,
                                                ip_s, ip_sp,
                                                algIdx) != 0)
                                        {







                                                return 113;



                                        }

                                tb=&entry;
                                if(_rtl8651_getInboundNaptFlow(1,ip_d,ip_dp,ip_s,ip_sp, &tb) != 0)
                                {
                                        printk("error: _rtl8651_getInboundNaptFlow connection in upnp \n");
                                        return 112;
                                }
                                else
                                {


                                        break;
                                }
                        }
                        else
                        {
                                tb = _rtl8651_addNaptAlgConnection(
                                                (1|0x0020),3,
                                                local_ip,local_port,&ip_d, &ip_dp, ip_s, ip_sp);
                                if(!tb)
                                        return 111;
                                if(tb){
                                        tb-> tcpAckModified = 0;
                                        tb-> tcpFtpLastLineCRLFTermed = 0;
                                        tb->tcpStateINdex = 0;
                                        memset(&tb->ack[0],0,sizeof(struct l4ack_data_record)*2);
                                        }
                                break;
                        }
                }



newDmzHostConn:



                        i=_rtl8651_doProtoStackAction(phdr, pip);
                        if(i==1) return 131;
                        if(i==2) return 112;

                if (_rtl8651_getDmzHost(phdr->ph_un_sw.ROMEDRV_USG._ph_dsid,ip_d, &dmzhost) == 0)
                {
# 10168 "rtl8651_tblDrvFwd.c"
                        if (actionFlag!=1)
                        {

                                tb = _rtl8651_addNaptAlgConnection(
                                        (1|0x0020), 3,
                                        dmzhost, ip_dp, &ip_d, &ip_dp, ip_s, ip_sp);
                                if(!tb)
                                        return 111;
                                if(tb){
                                        tb-> tcpAckModified = 0;
                                        tb-> tcpFtpLastLineCRLFTermed = 0;
                                        tb->tcpStateINdex = 0;
                                        memset(&tb->ack[0],0,sizeof(struct l4ack_data_record)*2);
                                        }

                        }
                        else {
                                if(_rtl8651_addNaptConnection(1,
                                        (1|0x0020), 3,
                                        dmzhost,ip_dp, &ip_d, &ip_dp, ip_s, ip_sp) != 0)
                                {
                                        printk("add connection failed\n");
                                        return 113;
                                }
                                tb=&entry;
                                if(_rtl8651_getInboundNaptFlow(1,ip_d,ip_dp,ip_s,ip_sp, &tb)!=0) {
                                        printk("getInboundflow failed\n");
                                        return 112;
                                }
                        }

                        break;
                }else
                        return 112;
        case 2:
        case 6:




                if(tb->alg_client_in){
                        int r;
                        r = tb->alg_client_in(phdr, pip, tb);
                        if(r==131) {
                                return 131;
                        }
                }
# 10224 "rtl8651_tblDrvFwd.c"
                break;
        case 3:

                break;
        case 4:
                if((retval =
                        _rtl8651_addNaptConnection(1,
                                (1|0x0020), 5,
                                tb2->localIp, ip_dp-tb2->globalPort+tb2->localPort, &ip_d, &ip_dp, ip_s, ip_sp)) != 0)
                {
                        return 113;
                }
                tb=&entry;

                if(_rtl8651_getInboundNaptFlow(1,ip_d,ip_dp,ip_s,ip_sp, &tb)!=0)
                {
                        printk("error: _rtl8651_getInboundNaptFlow connection Failed\n");
                        return 112;
                }
                break;
        case 5:

                if((retval = _rtl8651_addNaptConnection(1,
                                (1|0x0020), 3,
                                tb2->localIp,ip_dp-tb2->globalPort+tb2->localPort,&ip_d, &ip_dp, ip_s, ip_sp)) != 0)
                {
                        return 113;
                }
                tb=&entry;

                if(_rtl8651_getInboundNaptFlow(1,ip_d,ip_dp,ip_s,ip_sp, &tb)!=0) {
                        printk("error: _rtl8651_getInboundNaptFlow connection in upnp \n");
                        return 112;
                }
                break;

        case 10:
        case 14:
                 if(client_alg_link->fwEngAdd && client_alg_link->alg_inboundClientcb){
                        client_alg_link->alg_inboundClientcb(phdr, pip, tb);
                 }
                 break;

        case 13:
        case 21:
        case 29:

                tb=_rtl8651_addNaptAlgConnection(
                                (1|0x0020),3,
                                tb2->localIp,ip_dp+tb2->localPort-tb2->globalPort,&ip_d, &ip_dp, ip_s, ip_sp);
                if(!tb)
                        return 111;
                if(tb){
                        tb-> tcpAckModified = 0;
                        tb-> tcpFtpLastLineCRLFTermed = 0;
                        tb->tcpStateINdex = 0;
                        memset(&tb->ack[0],0,sizeof(struct l4ack_data_record)*2);






                }
                break;


        case 18:
        case 22:
                 if(server_alg_link->fwEngAdd && server_alg_link->alg_inboundServercb){
                        server_alg_link->alg_inboundServercb(phdr, pip, tb);
                 }
                break;
        default:
                printk("%s: action=%d, flag=%d\n",__FUNCTION__,actionFlag,tc->th_flags );
                return 110;
        }

        do {} while (0);





        if (rtl8651_drvWeakTcpNaptEnable && (initFlag == 5) && (actionFlag != 4))
        {
                if (actionFlag & 0x10)
                {
                         if(server_alg_link->fwEngAdd && server_alg_link->alg_inboundServercb)
                         {
                                server_alg_link->alg_inboundServercb(phdr, pip, tb);
                         }
                }
                if (actionFlag & 0x08)
                {
                         if(client_alg_link->fwEngAdd && client_alg_link->alg_inboundClientcb)
                         {
                                client_alg_link->alg_inboundClientcb(phdr, pip, tb);
                         }
                }
        }



        if(tc->th_flags & 0x02){
                int8 auto_add = 0,auto_delete;
                rtl8651_getAsicNaptAutoAddDelete(&auto_add,&auto_delete);
                if(auto_add == 0){
                        uint8 *cp;
                        int32 opt, optlen,cnt;
                        uint16 mss;

                        cp = (uint8 *)(tc+1);
                        cnt = ((tc->th_off_x >>2)&0x3c) -sizeof(struct tcphdr);

                        for(; cnt > 0; cnt -= optlen, cp+= optlen){
                                opt = cp[0];
                                if(opt == 0)
                                        break;
                                if(opt == 1)
                                        optlen = 1;
                                else{
                                        optlen = cp[1];
                                        if(optlen <= 0)
                                                break;
                                }

                                switch (opt) {
                                case 2:
                                        mss = (*(uint16*)(&cp[2]));


                                        thisPPPoE=_rtl8651_getPppoeSessionByIpAddr(ip_d);
                                        if (thisPPPoE)
                                        {
                                                if (mss >pppoe_mss[thisPPPoE->dsid])
                                                {
                                                        mtu=pppoe_mss[thisPPPoE->dsid];
                                                        accumulate -=(mss-pppoe_mss[thisPPPoE->dsid]);
                                                        *(uint16*)(&cp[2]) = (mtu);
                                                }
                                        }else if(mss > rtl8651_mss){
                                                mtu=rtl8651_mss;
                                                accumulate -=(mss-rtl8651_mss);
                                                *(uint16*)(&cp[2]) = (mtu);
                                        }
                                        break;
                                default:
                                        continue;
                                }
                        }
                }
        }


        tb->dsid = phdr->ph_un_sw.ROMEDRV_USG._ph_dsid;







        ip_org = tb->insideLocalIpAddr;
        ip_orgp = tb->insideLocalPort;


        if (tb->tcpAckModified == 1)
        {
                int32 delta;
                uint32 ack_32_x;

                delta = _rtl8651_l4GetDeltaAckIn(pip, tc, tb);
                accumulate += delta;
                if (delta != 0)
                {
                        ack_32_x=((uint32) (*((uint8*)(&tc->th_ack))<<24)|(*(((uint8*)(&tc->th_ack))+1)<<16)|(*(((uint8*)(&tc->th_ack))+2)<<8) | *(((uint8*)(&tc->th_ack))+3));
                        ack_32_x = ((ack_32_x) - delta);
                        do{ *((uint8*)(&tc->th_ack)) = (uint8)((ack_32_x)>>24); *(((uint8*)(&tc->th_ack))+1) = (uint8)((ack_32_x)>>16); *(((uint8*)(&tc->th_ack))+2) = (uint8)((ack_32_x)>>8); *(((uint8*)(&tc->th_ack))+3) = (uint8)((ack_32_x)); }while(0);
                }
        }


        _rtl8651_l4TcpMonitorIn(tc, tb);




                if ((_urlFilterAclRuleNum>=0) &&
                        (!tb->urlFiltered||((phdr->ph_reason&0xe)==4
                        && ((phdr->ph_reason&0xff0)>>5)==_urlFilterAclRuleNum)))



                {
                        int32 position, len=64;
                        int8 matched[64];
                        int32 hlen = ((pip->ip_vhl & 0xf) + (( tc->th_off_x >>4)&0xf)) << 2;
                        if (((pip->ip_len))>hlen)
                        {
                                position = _rtl8651_urlFilter(phdr->ph_un_sw.ROMEDRV_USG._ph_dsid,phdr,pip,1,matched, &len);
                                if (position>0)
                                {
# 10436 "rtl8651_tblDrvFwd.c"
                                        _rtl8651_updateNaptConnection(tb,8, 3);
                                        return 101;
                                }
                                tb->urlFiltered = 1;
                        }
                }


        if ((!(actionFlag&0x02)) && tb)
        {
                do {} while (0);


                if ((_loggingModule[phdr->ph_un_sw.ROMEDRV_USG._ph_dsid]&0x00000010)&&_pUserLoggingFunc)
                {

                        rtl8651_logInfo_t info;
                        info.infoType = 1;
                        info.un.pkt.dsid = phdr->ph_un_sw.ROMEDRV_USG._ph_dsid;
                        info.un.pkt.sip = ip_s;
                        info.un.pkt.dip = ip_org;
                        info.un.pkt.protocol = 6;
                        info.un.pkt.direction = 1;
                        info.un.pkt.sport = ip_sp;
                        info.un.pkt.dport = ip_orgp;
                        info.action = 3;
                        (* _pUserLoggingFunc)(0x00000010, 2, &info);
# 10477 "rtl8651_tblDrvFwd.c"
                }
        }



        if (((pip->ip_vhl & 0x0f) != 5) || (((pip->ip_off) & (0x1fff|0x2000)) == 0x2000))
        {
                if ((pip->ip_vhl & 0x0f) != 5)
                {
                        do { do { int32 accumulate = 0; if ((((ip_org)) != 0) && (((ip_d)) != 0)){ accumulate = (((ip_d)) & 0xffff); accumulate += (( ((ip_d)) >> 16 ) & 0xffff); accumulate -= (((ip_org)) & 0xffff); accumulate -= (( ((ip_org)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                }

                do { int32 accumulate = 0; if (((ip_org) != 0) && ((ip_d) != 0)){ accumulate = ((ip_d) & 0xffff); accumulate += (( (ip_d) >> 16 ) & 0xffff); accumulate -= ((ip_org) & 0xffff); accumulate -= (( (ip_org) >> 16 ) & 0xffff); } if (((ip_orgp) != 0) && ((ip_dp) != 0)){ accumulate += (ip_dp); accumulate -= (ip_orgp); } do { accumulate += ((tc->th_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) accumulate); } } while (0); }while(0);
                do { accumulate += (tc->th_sum); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; tc->th_sum = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; tc->th_sum = ((uint16) accumulate); } } while (0);

                if ((((uint16)(pip->ip_off)) & (0x1fff|0x2000)))
                {
                        _rtl8651_updateFragCache(0, phdr->ph_sip, phdr->ph_dip, (pip->ip_id), ip_org, 0, ((void *)0), phdr->ph_un_sw.ROMEDRV_USG._ph_dsid);

                        _rtl8651_fragmentShortestPathCacheSet_firstHalf(phdr, (uint8*)tc, pip, ip_s, ip_d, 1, ip_org);

                }
        }



        tc->th_dport = (ip_orgp);

        do{ *((uint8*)(&pip->ip_dst)) = (uint8)((ip_org)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((ip_org)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((ip_org)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((ip_org)); }while(0);

        return (0);
}
# 10520 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4TcpNatAlgAliasIn(struct rtl_pktHdr *phdr, struct ip *pip, rtl8651_tblDrv_natEntry_t *natEntry)
{

        struct tcphdr *tc;
        ipaddr_t ip_s, ip_d, ip_org = 0;
        uint16 ip_sp, ip_dp, ip_orgp = 0;
        struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s entry, *tb = &entry;
        int32 accumulate = 0;
        rtl8651_tblDrv_algEntry_t *client_alg_link = ((void *)0);
        rtl8651_tblDrv_algEntry_t *server_alg_link = ((void *)0);
        uint32 actionFlag = 0;
        rtl8651_tblDrv_pppTable_t *thisPPPoE;
        uint16 mtu;

        tc = (struct tcphdr *) ((int8 *) pip + ((*(uint8*)pip&0xf) << 2));

        ip_s = phdr->ph_sip;
        ip_d = phdr->ph_dip;
        ip_sp = (tc->th_sport);
        ip_dp = (tc->th_dport);

        if (ip_d == natEntry->localIp)
        {
                tb = ((void *)0);
                goto adjust_mss;
        }







        client_alg_link = _rtl8651_l4FindLinkAlg(ip_sp, 1);
        if(ip_sp != ip_dp){
                server_alg_link = _rtl8651_l4FindLinkAlg(ip_dp, 1);
        }





        if(_rtl8651_getInboundNaptFlow(1,ip_d,ip_dp,ip_s,ip_sp, &tb)!=0){
                tb=((void *)0);
        }



        if(tc->th_flags & 0x02)
                actionFlag |= 0x01;

        if(tb)
                actionFlag |= 0x02;

        if(client_alg_link)
                actionFlag |= 0x08;

        if(server_alg_link)
                actionFlag |= 0x10;





        switch(actionFlag){
                case 2:


                        if(tb->alg_client_in){
                                int r;
                                r = tb->alg_client_in(phdr, pip, tb);
                                if(r==131) {
                                        return 131;
                                }
                        }
                        if(tb->alg_server_in){
                                int r;
                                r = tb->alg_server_in(phdr, pip, tb);
                                if(r==131) {
                                        return 131;
                                }
                        }
                case 10:
                case 11:

                         if(client_alg_link->fwEngAdd && client_alg_link->alg_inboundClientcb){
                                client_alg_link->alg_inboundClientcb(phdr, pip, tb);
                         }
                         break;
                case 18:
                case 19:

                         if(server_alg_link->fwEngAdd && server_alg_link->alg_inboundServercb){
                                server_alg_link->alg_inboundServercb(phdr, pip, tb);
                         }
                        break;
                case 9:
                case 17:

                        tb = _rtl8651_addNaptAlgConnection(
                                (1|0x0020), 3,
                                natEntry->localIp, ip_dp, &ip_d, &ip_dp, ip_s, ip_sp);
                        if(!tb)
                                return 115;
                        tb->natlink = 1;

                        break;
                case 1:
                        goto adjust_mss;
                case 0:
                        return 114;
                default:
                        printk("%s: action=%d, flag=%d\n",__FUNCTION__,actionFlag,tc->th_flags );
                        return 116;
        }

        do {} while (0);

        _rtl8651_l4TcpMonitorIn(tc, tb);


adjust_mss:
        if(tc->th_flags & 0x02){
                int8 auto_add = 0,auto_delete;
                rtl8651_getAsicNaptAutoAddDelete(&auto_add,&auto_delete);
                if(auto_add == 0){
                        uint8 *cp;
                        int32 opt, optlen,cnt;
                        uint16 mss;

                        cp = (uint8 *)(tc+1);
                        cnt = ((tc->th_off_x >>2)&0x3c) -sizeof(struct tcphdr);

                        for(; cnt > 0; cnt -= optlen, cp+= optlen){
                                opt = cp[0];
                                if(opt == 0)
                                        break;
                                if(opt == 1)
                                        optlen = 1;
                                else{
                                        optlen = cp[1];
                                        if(optlen <= 0)
                                                break;
                                }

                                switch (opt) {
                                case 2:
                                        mss = (*(uint16*)(&cp[2]));


                                        thisPPPoE=_rtl8651_getPppoeSessionByIpAddr(ip_d);
                                        if (thisPPPoE)
                                        {
                                                if (mss >pppoe_mss[thisPPPoE->dsid])
                                                {
                                                        mtu=pppoe_mss[thisPPPoE->dsid];
                                                        accumulate -=(mss-pppoe_mss[thisPPPoE->dsid]);
                                                        *(uint16*)(&cp[2]) = (mtu);
                                                }
                                        }else if(mss > rtl8651_mss){
                                                mtu=rtl8651_mss;
                                                accumulate -=(mss-rtl8651_mss);
                                                *(uint16*)(&cp[2]) = (mtu);
                                        }
                                        break;
                                default:
                                        continue;
                                }
                        }
                }
        }


        ip_s = phdr->ph_sip;
        ip_d = phdr->ph_dip;
        ip_sp = (tc->th_sport);
        ip_dp = (tc->th_dport);


        if(tb){
                ip_org = tb->insideLocalIpAddr;
                ip_orgp = tb->insideLocalPort;


                tc->th_dport = (ip_orgp);


                if (tb->tcpAckModified == 1)
                {
                        int32 delta;
                        uint32 ack_32_x;

                        delta = _rtl8651_l4GetDeltaAckIn(pip, tc, tb);
                        accumulate += delta;
                        if (delta != 0)
                        {
                                ack_32_x=((uint32) (*((uint8*)(&tc->th_ack))<<24)|(*(((uint8*)(&tc->th_ack))+1)<<16)|(*(((uint8*)(&tc->th_ack))+2)<<8) | *(((uint8*)(&tc->th_ack))+3));
                                ack_32_x = ((ack_32_x) - delta);
                                do{ *((uint8*)(&tc->th_ack)) = (uint8)((ack_32_x)>>24); *(((uint8*)(&tc->th_ack))+1) = (uint8)((ack_32_x)>>16); *(((uint8*)(&tc->th_ack))+2) = (uint8)((ack_32_x)>>8); *(((uint8*)(&tc->th_ack))+3) = (uint8)((ack_32_x)); }while(0);
                        }
                }
                do{ *((uint8*)(&pip->ip_dst)) = (uint8)((ip_org)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((ip_org)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((ip_org)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((ip_org)); }while(0);
        }else{
                do {} while (0);
                do{ *((uint8*)(&pip->ip_dst)) = (uint8)((natEntry->localIp)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((natEntry->localIp)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((natEntry->localIp)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((natEntry->localIp)); }while(0);
        }


        if(tb)
        {
                if (((pip->ip_vhl & 0x0f) != 5) || (((pip->ip_off) & (0x2000|0x1fff)) == 0x2000))
                {
                        if ((pip->ip_vhl & 0x0f) != 5)
                        {
                                do { do { int32 accumulate = 0; if ((((ip_org)) != 0) && (((ip_d)) != 0)){ accumulate = (((ip_d)) & 0xffff); accumulate += (( ((ip_d)) >> 16 ) & 0xffff); accumulate -= (((ip_org)) & 0xffff); accumulate -= (( ((ip_org)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                        }
                        do { int32 accumulate = 0; if (((ip_org) != 0) && ((ip_d) != 0)){ accumulate = ((ip_d) & 0xffff); accumulate += (( (ip_d) >> 16 ) & 0xffff); accumulate -= ((ip_org) & 0xffff); accumulate -= (( (ip_org) >> 16 ) & 0xffff); } if (((ip_orgp) != 0) && ((ip_dp) != 0)){ accumulate += (ip_dp); accumulate -= (ip_orgp); } do { accumulate += ((tc->th_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) accumulate); } } while (0); }while(0);
                        do { accumulate += (tc->th_sum); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; tc->th_sum = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; tc->th_sum = ((uint16) accumulate); } } while (0);
                }
        }
        else {

                ip_org = natEntry->localIp;

                if (((pip->ip_vhl & 0x0f) != 5) || (((pip->ip_off) & (0x2000|0x1fff)) == 0x2000))
                {
                        if ((pip->ip_vhl & 0x0f) != 5)
                        {
                                do { do { int32 accumulate = 0; if ((((ip_org)) != 0) && (((ip_d)) != 0)){ accumulate = (((ip_d)) & 0xffff); accumulate += (( ((ip_d)) >> 16 ) & 0xffff); accumulate -= (((ip_org)) & 0xffff); accumulate -= (( ((ip_org)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                        }
                        do { int32 accumulate = 0; if (((ip_org) != 0) && ((ip_d) != 0)){ accumulate = ((ip_d) & 0xffff); accumulate += (( (ip_d) >> 16 ) & 0xffff); accumulate -= ((ip_org) & 0xffff); accumulate -= (( (ip_org) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += ((tc->th_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) accumulate); } } while (0); }while(0);
                        do { accumulate += (tc->th_sum); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; tc->th_sum = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; tc->th_sum = ((uint16) accumulate); } } while (0);
                }
        }


        return (0);
}
# 10768 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4TcpNaptAliasOut(struct rtl_pktHdr *phdr, struct ip *pip)
{
        struct tcphdr *tc;
        ipaddr_t ip_s, ip_d, ip_alias = 0;
        uint16 ip_sp, ip_dp, ip_aliasp = 0;
        struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s entry, *tb=&entry;
        rtl8651_tblDrv_algEntry_t *client_alg_link = ((void *)0);
        rtl8651_tblDrv_algEntry_t *server_alg_link = ((void *)0);
        int32 accumulate = 0;
        rtl8651_tblDrv_naptServerPortEntry_t *tb2;
        uint32 actionFlag = 0;
        int inTrigger = 0;
        rtl8651_tblDrv_pppTable_t *thisPPPoE;
        uint16 mtu;
        int8 initFlag = 2;
        int32 retval = -1;
# 10801 "rtl8651_tblDrvFwd.c"
        int32 isUpnpMapping = 0;
        ipaddr_t upnpExtIp;
        uint16 upnpExtPort;
        uint32 upnpFlags;
        uint32 upnpAlgIdx;
# 10815 "rtl8651_tblDrvFwd.c"
        tc = (struct tcphdr *) ((int8 *) pip + ((*(uint8*)pip&0xf) << 2));

        ip_s = phdr->ph_sip;
        ip_d = phdr->ph_dip;
        ip_sp = (tc->th_sport);
        ip_dp = (tc->th_dport);

        if(_rtl8651_getOutboundNaptFlow(1,ip_s,ip_sp,ip_d,ip_dp, &tb)!=0) {
                tb=&entry;
                if( _rtl8651_getOutboundAlgConnection(1,ip_s,ip_sp,ip_d,ip_dp, &tb)!=0) {
                        tb=((void *)0);
                }
        }

        tb2 = _rtl8651_getInsideNaptServerPortMapping(1,ip_s,ip_sp);

        client_alg_link = _rtl8651_l4FindLinkAlg(ip_dp, 1);

        if(ip_sp!= ip_dp)
        {

                if(tb)
                {
                        server_alg_link = _rtl8651_l4FindLinkAlg(tb->insideGlobalPort, 1);
                }else
                {
                        server_alg_link = _rtl8651_l4FindLinkAlg(ip_sp, 1);
                }
        }
# 10854 "rtl8651_tblDrvFwd.c"
        if ((tb == ((void *)0)) && (tb2 == ((void *)0)))
        {
                if (_rtl8651_findOutboundUpnpMapping(
                        1,
                        ip_s,
                        ip_sp,
                        &upnpExtIp,
                        &upnpExtPort,
                        ip_d,
                        ip_dp,
                        &upnpFlags,
                        &upnpAlgIdx) == 0)
                {
                        isUpnpMapping = 1;
                }
        }
# 10880 "rtl8651_tblDrvFwd.c"
                if ((tb == ((void *)0)) && (tb2 == ((void *)0)) && (isUpnpMapping == 0))
                {
                        ipaddr_t redirectIp;
                        uint16 redirectPort;
                        if (_rtl8651_findNaptRedirectEntry(1, ip_s, ip_sp, ip_d, ip_dp, &redirectIp, &redirectPort, 1, phdr->ph_vlanIdx) == 0)
                        {

                                do{ *((uint8*)(&pip->ip_dst)) = (uint8)((redirectIp)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((redirectIp)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((redirectIp)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((redirectIp)); }while(0);
                                tc->th_dport = (redirectPort);

                                do { int32 accumulate = 0; if (((redirectIp) != 0) && ((ip_d) != 0)){ accumulate = ((ip_d) & 0xffff); accumulate += (( (ip_d) >> 16 ) & 0xffff); accumulate -= ((redirectIp) & 0xffff); accumulate -= (( (redirectIp) >> 16 ) & 0xffff); } if (((redirectPort) != 0) && ((ip_dp) != 0)){ accumulate += (ip_dp); accumulate -= (redirectPort); } do { accumulate += ((tc->th_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) accumulate); } } while (0); }while(0);
                                do { do { int32 accumulate = 0; if ((((redirectIp)) != 0) && (((ip_d)) != 0)){ accumulate = (((ip_d)) & 0xffff); accumulate += (( ((ip_d)) >> 16 ) & 0xffff); accumulate -= (((redirectIp)) & 0xffff); accumulate -= (( ((redirectIp)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);

                                if (((((uint16)(pip->ip_off)) & (0x1fff|0x2000)) == 0x2000))
                                {
                                        _rtl8651_updateFragCache(5, ip_s, ip_d, (pip->ip_id), redirectIp, 0, ((void *)0), phdr->ph_un_sw.ROMEDRV_USG._ph_dsid);
                                }

                                if (_rtl8651_fragQueueProcess == 1)
                                {
                                        _rtl8651_fragQueueNaptRedirect_MatchedIP = redirectIp;
                                }

                                return 132;
                        }
                }



        if (tb == ((void *)0)) {




                int32 local_val;
                rtl8651_tblDrv_vlanTable_t *local_vlanp = &DrvTbl.vlan[phdr->ph_vlanIdx];
                local_val = _rtl8651_ingressAcl(phdr->ph_un_sw.ROMEDRV_USG._ph_dsid, 0, local_vlanp, local_vlanp->vid, phdr->PKTHDRNXT.mbuf_first->m_data, (uint8 *) pip, 0x01, 0);
                if (((local_val > 0) && (local_val & 0x1000)) ||(local_val == 2))
                        return local_val;
        }


        if (rtl8651_drvWeakTcpNaptEnable == 0)




        if ((tc->th_flags & (0x02|0x10)) == (0x02|0x10) && tb == ((void *)0))
        {
                return 106;
        }

        if(tc->th_flags == 0x02)
        {
                actionFlag |= 0x01;
        }

        if(tb)
        {
                actionFlag |= 0x02;
        }

        if(tb2)
        {
                actionFlag |= 0x04;
        }

        if (isUpnpMapping == 1)
        {
                actionFlag |= 0x20;
        }




                if ((actionFlag == 0x01)||((actionFlag == 0) && rtl8651_drvWeakTcpNaptEnable))



                {
                        if (_rtl8651_tryActiveTriggerPort( 1,
                                                                                        phdr->ph_un_sw.ROMEDRV_USG._ph_dsid,
                                                                                        ip_dp,
                                                                                        0,
                                                                                        ip_s) > 0)
                        {
                                inTrigger = 1;
                        }
                }




        {
                if(client_alg_link)
                        actionFlag |= 0x08;

                if(server_alg_link)
                        actionFlag |= 0x10;
        }
# 10995 "rtl8651_tblDrvFwd.c"
        initFlag = 2;
# 11013 "rtl8651_tblDrvFwd.c"
        if ((actionFlag & (0x01 | 0x02)) == 0)
        {
                if ((actionFlag == 0x04) || (actionFlag == 0x20))
                {
                        initFlag = 5;
                }else if (rtl8651_drvWeakTcpNaptEnable)
                {




                        initFlag = 5;
                        actionFlag |= 0x01;
                }else
                {
                        actionFlag = 0;
                }
        }
# 11060 "rtl8651_tblDrvFwd.c"
        if((actionFlag&(0x01|0x02)) == (0x01|0x02))
        {
                actionFlag = (0x01|0x02);
        }







        switch ( actionFlag )
        {
                case 0:



                        _rtl8651_dosScanCheckTcpOutboundFailUnusual(phdr->ph_un_sw.ROMEDRV_USG._ph_dsid, pip, tc);

                        return 106;



                case 4:
                case 5:
                case 21:

                case 32:
                case 33:
                case 49:


                        if (tb2)
                        {
                                do {} while (0);
                                ip_alias = tb2->globalIp;
                                ip_aliasp = ip_sp - tb2->localPort + tb2->globalPort;
                        } else
                        {
                                do {} while (0);
                                ip_alias = upnpExtIp;
                                ip_aliasp = upnpExtPort;
                        }

                        if((retval = _rtl8651_addNaptConnection(1,
                                        (1|0x0020|0x0040),
                                        initFlag, ip_s, ip_sp, &ip_alias, &ip_aliasp, ip_d, ip_dp)) != 0)
                        {
                                return 107;
                        }
                        tb=&entry;
                        if(_rtl8651_getOutboundNaptFlow(1, ip_s, ip_sp, ip_d, ip_dp, &tb)!=0)
                        {
                                printk("error: _rtl8651_getOutboundNaptFlow connection Failed \n");
                                return 106;
                        }
                        tb-> tcpAckModified = 0;
                        tb-> tcpFtpLastLineCRLFTermed = 0;
                        tb->tcpStateINdex = 0;
                        memset(&tb->ack[0],0,sizeof(struct l4ack_data_record)*2);
                        break;



                case 1:
                case 17:



                        _rtl8651_softNaptPolicyRoute(0x20, ip_s, ip_d, ip_dp, &ip_alias, &ip_aliasp);

                        if (actionFlag == 1)
                        {
                                if (ip_alias)
                                {
                                        if ((rtl8651_drvStaticTcpNaptPortTranslation == 1) &&
                                                (_rtl8651_l4CheckOccupiedConnection(1, phdr->ph_un_sw.ROMEDRV_USG._ph_dsid, ip_s, ip_sp, ip_alias, ip_sp, ip_d, ip_dp) == 0))
                                        {
                                                if (_rtl8651_addNaptConnection(1,
                                                                (1|0x0002|0x0020|0x0040|0x0100),
                                                                initFlag, ip_s, ip_sp, &ip_alias, &ip_sp, ip_d, ip_dp )
                                                                == 0)
                                                        ip_aliasp = ip_sp;
                                                else
                                                        goto TcpPolicyDynamicPortAssign;
                                        }else
                                        {
TcpPolicyDynamicPortAssign:
                                                if( _rtl8651_addNaptConnection(1,
                                                                (1|0x0002|0x0020|0x0040),
                                                                initFlag, ip_s, ip_sp, &ip_alias, &ip_aliasp,
                                                                ip_d, ip_dp )
                                                                != 0)
                                                        return 107;
                                        }
                                }else
                                {
                                        if (rtl8651_drvStaticTcpNaptPortTranslation == 1)
                                        {
                                                ip_alias = _rtl8651_getNaptInsideGlobalIpAddr(1, ip_s, ip_sp, ip_d, ip_dp);

                                                if ((!ip_alias) ||(_rtl8651_l4CheckOccupiedConnection(1, phdr->ph_un_sw.ROMEDRV_USG._ph_dsid, ip_s, ip_sp, ip_alias, ip_sp, ip_d, ip_dp) == 1))
                                                        goto TcpNormalDynamicPortAssign;

                                                if (_rtl8651_addNaptConnection(1,
                                                                (1|0x0020|0x0040|0x0100),
                                                                initFlag, ip_s, ip_sp, &ip_alias, &ip_sp, ip_d, ip_dp )
                                                                == 0)
                                                        ip_aliasp = ip_sp;
                                                else
                                                        goto TcpNormalDynamicPortAssign;
                                        }else
                                        {
TcpNormalDynamicPortAssign:
                                                if(_rtl8651_addNaptConnection(1,
                                                                (0|0x0020|0x0040),
                                                                initFlag, ip_s, ip_sp, &ip_alias, &ip_aliasp, ip_d, ip_dp )
                                                                != 0)
                                                        return 107;
                                        }
                                }
                        }else
                        {
                                if (ip_alias)
                                {
                                        if( _rtl8651_addNaptConnection(1,
                                                        (1|0x0002|0x0020|0x0040),
                                                        initFlag, ip_s, ip_sp, &ip_alias, &ip_aliasp, ip_d, ip_dp) != 0)
                                                return 107;
                                }
                                else
                                {

                                        if( _rtl8651_addNaptConnection(1,
                                                        (0|0x0020|0x0040),
                                                        initFlag, ip_s, ip_sp, &ip_alias, &ip_aliasp, ip_d, ip_dp) != 0 )
                                                return 107;
                                }
                        }
# 11214 "rtl8651_tblDrvFwd.c"
                        tb = &entry;
                        if(_rtl8651_getOutboundNaptFlow(1, ip_s, ip_sp, ip_d, ip_dp, &tb) == 0)
                        {
                                tb-> tcpAckModified = 0;
                                tb-> tcpFtpLastLineCRLFTermed = 0;
                                tb->tcpStateINdex = 0;
                                memset(&tb->ack[0],0,sizeof(struct l4ack_data_record)*2);
                                break;
                        }
                        return 106;



                case 2:
                case 6:

                case 34:
# 11245 "rtl8651_tblDrvFwd.c"
                        if(tb->alg_client_out)
                        {
                                int r;

                                r = tb->alg_client_out(phdr, pip, tb);

                                if(r == 131)
                                {
                                        return 131;
                                }
                        }
                        break;



                case 3:



                        break;
# 11293 "rtl8651_tblDrvFwd.c"
                case 9:
                case 13:

                case 41:



                        if (client_alg_link->fwEngAdd)
                        {
                                _rtl8651_softNaptPolicyRoute(0x20,ip_s,ip_d,ip_dp,&ip_alias,&ip_aliasp);
                                if (ip_alias)
                                {
                                        tb = _rtl8651_addNaptAlgConnection(
                                                (1|0x0020|0x0040),
                                                initFlag, ip_s, ip_sp, &ip_alias, &ip_aliasp, ip_d, ip_dp);
                                }else
                                {
                                        tb = _rtl8651_addNaptAlgConnection(
                                                (0|0x0020|0x0040),
                                                initFlag, ip_s, ip_sp, &ip_alias, &ip_aliasp, ip_d, ip_dp);
                                }
                                        if(!tb)
                                                return 102;
                        }

                        tb=&entry;
                        if(_rtl8651_getOutboundAlgConnection(1, ip_s, ip_sp, ip_d, ip_dp, &tb) == 0)
                        {
                                tb-> tcpAckModified = 0;
                                tb-> tcpFtpLastLineCRLFTermed = 0;
                                tb->tcpStateINdex = 0;
                                memset(&tb->ack[0],0,sizeof(struct l4ack_data_record)*2);
                                break;
                        }
                        return 104;



                case 10:
                case 14:

                case 42:



                         if(client_alg_link->fwEngAdd && client_alg_link->alg_outboundClientcb)
                         {
                                int r;
                                r=client_alg_link->alg_outboundClientcb(phdr, pip, tb);
                                if(r==131) return 131;
                         }
                         break;
# 11388 "rtl8651_tblDrvFwd.c"
                case 18:
                case 22:

                case 50:



                         if(server_alg_link->fwEngAdd && server_alg_link->alg_outboundServercb)
                         {
                                int r;
                                r = server_alg_link->alg_outboundServercb(phdr, pip, tb);
                                if( r == 131 )
                                {
                                        return 131;
                                }
                         }
                        break;



                default:
                        printk("%s: action=%d, flag=%d\n",__FUNCTION__,actionFlag,tc->th_flags );
                        return 108;
        }
        do {} while (0);
        do {} while (0);





        if ( rtl8651_drvWeakTcpNaptEnable &&
                (initFlag == 5) &&
                (actionFlag != 0x04) &&
                (actionFlag != 0x20)
        )
        {
                if (actionFlag & 0x10)
                {
                         if(server_alg_link->fwEngAdd && server_alg_link->alg_outboundServercb)
                         {
                                int r;
                                r=server_alg_link->alg_outboundServercb(phdr, pip, tb);
                                if(r==131) return 131;
                         }
                }
                if (actionFlag & 0x08)
                {
                         if(client_alg_link->fwEngAdd && client_alg_link->alg_outboundClientcb)
                         {
                                int r;
                                r=client_alg_link->alg_outboundClientcb(phdr, pip, tb);
                                if(r==131) return 131;
                         }
                }
        }



        tb->out_rt_t = (void *)&DrvTbl.route[phdr->ph_routeIdx-1];
        tb->dsid = phdr->ph_un_sw.ROMEDRV_USG._ph_dsid;


        ip_s = phdr->ph_sip;
        ip_d = phdr->ph_dip;
        ip_sp = (tc->th_sport);
        ip_dp = (tc->th_dport);

        ip_alias = tb->insideGlobalIpAddr;
        ip_aliasp = tb->insideGlobalPort;


        _rtl8651_l4TcpMonitorOut(tc, tb);


        if(tc->th_flags & 0x02){
                int8 auto_add = 0,auto_delete;
                rtl8651_getAsicNaptAutoAddDelete(&auto_add,&auto_delete);
                if(auto_add == 0){
                        uint8 *cp;
                        int32 opt, optlen,cnt;
                        uint16 mss;

                        cp = (uint8 *)(tc+1);
                        cnt = ((tc->th_off_x >>2)&0x3c) -sizeof(struct tcphdr);

                        for(; cnt > 0; cnt -= optlen, cp+= optlen){
                                opt = cp[0];
                                if(opt == 0)
                                        break;
                                if(opt == 1)
                                        optlen = 1;
                                else{
                                        optlen = cp[1];
                                        if(optlen <= 0)
                                                break;
                                }

                                switch (opt) {
                                case 2:
                                        mss = (*(uint16*)(&cp[2]));


                                        thisPPPoE=_rtl8651_getPppoeSessionByIpAddr(ip_alias);
                                        if (thisPPPoE)
                                        {
                                                if (mss >pppoe_mss[thisPPPoE->dsid])
                                                {
                                                        mtu=pppoe_mss[thisPPPoE->dsid];
                                                        accumulate -=(mss-pppoe_mss[thisPPPoE->dsid]);
                                                        *(uint16*)(&cp[2]) = (mtu);
                                                }
                                        }else if(mss > rtl8651_mss){
                                                mtu=rtl8651_mss;
                                                accumulate -=(mss-rtl8651_mss);
                                                *(uint16*)(&cp[2]) = (mtu);
                                        }
                                        break;
                                default:
                                        continue;
                                }
                        }
                }
        }


        if (tb->tcpAckModified == 1)
        {
                int32 delta;

                delta = _rtl8651_l4GetDeltaSeqOut(pip, tc, tb);
                accumulate += delta;
                if (delta != 0)
                {
                        uint32 seq_32_x = ((uint32) (*((uint8*)(&tc->th_seq))<<24)|(*(((uint8*)(&tc->th_seq))+1)<<16)|(*(((uint8*)(&tc->th_seq))+2)<<8) | *(((uint8*)(&tc->th_seq))+3));
                        seq_32_x = ((seq_32_x) + delta);
                        do{ *((uint8*)(&tc->th_seq)) = (uint8)((seq_32_x)>>24); *(((uint8*)(&tc->th_seq))+1) = (uint8)((seq_32_x)>>16); *(((uint8*)(&tc->th_seq))+2) = (uint8)((seq_32_x)>>8); *(((uint8*)(&tc->th_seq))+3) = (uint8)((seq_32_x)); }while(0);
                }
        }



                if ((_urlFilterAclRuleNum>=0) &&
                        ((phdr->ph_reason&0xe)==4
                        && ((phdr->ph_reason&0xff0)>>5)==_urlFilterAclRuleNum))



                {
                        int32 position, len=64;
                        int8 matched[64];
                        int32 hlen = ((pip->ip_vhl & 0xf) + (( tc->th_off_x >>4)&0xf)) << 2;
                        if (((pip->ip_len))>hlen)
                        {
                                position = _rtl8651_urlFilter(phdr->ph_un_sw.ROMEDRV_USG._ph_dsid,phdr,pip,0,matched, &len);
                                if (position>0)
                                {
# 11554 "rtl8651_tblDrvFwd.c"
                                        _rtl8651_updateNaptConnection(tb,8, 3);
                                        return 101;
                                }



                        }
                }


        if ((!(actionFlag&0x02)) && tb)
        {
                do {} while (0);


                if ((_loggingModule[phdr->ph_un_sw.ROMEDRV_USG._ph_dsid]&0x00000010)&&_pUserLoggingFunc)
                {

                        rtl8651_logInfo_t info;
                        info.infoType = 1;
                        info.un.pkt.dsid = phdr->ph_un_sw.ROMEDRV_USG._ph_dsid;
                        info.un.pkt.sip = ip_s;
                        info.un.pkt.dip = ip_d;
                        info.un.pkt.protocol = 6;
                        info.un.pkt.direction = 0;
                        info.un.pkt.sport = ip_sp;
                        info.un.pkt.dport = ip_dp;
                        info.action = 3;
                        (* _pUserLoggingFunc)(0x00000010, 1, &info);
# 11597 "rtl8651_tblDrvFwd.c"
                }
        }



        if (((pip->ip_vhl & 0x0f) != 5) || (((pip->ip_off) & (0x2000|0x1fff)) == 0x2000))
        {
                if ((pip->ip_vhl & 0x0f) != 5)
                {

                        do { do { int32 accumulate = 0; if ((((ip_alias)) != 0) && (((ip_s)) != 0)){ accumulate = (((ip_s)) & 0xffff); accumulate += (( ((ip_s)) >> 16 ) & 0xffff); accumulate -= (((ip_alias)) & 0xffff); accumulate -= (( ((ip_alias)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                }

                do { int32 accumulate = 0; if (((ip_alias) != 0) && ((ip_s) != 0)){ accumulate = ((ip_s) & 0xffff); accumulate += (( (ip_s) >> 16 ) & 0xffff); accumulate -= ((ip_alias) & 0xffff); accumulate -= (( (ip_alias) >> 16 ) & 0xffff); } if (((ip_aliasp) != 0) && ((ip_sp) != 0)){ accumulate += (ip_sp); accumulate -= (ip_aliasp); } do { accumulate += ((tc->th_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) accumulate); } } while (0); }while(0);
                do { accumulate += (tc->th_sum); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; tc->th_sum = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; tc->th_sum = ((uint16) accumulate); } } while (0);

                if ((((uint16)(pip->ip_off)) & (0x1fff|0x2000)))
                {
                        _rtl8651_updateFragCache(1, phdr->ph_sip, phdr->ph_dip, (pip->ip_id), ip_alias, phdr->ph_routeIdx, ((void *)0), phdr->ph_un_sw.ROMEDRV_USG._ph_dsid);

                        _rtl8651_fragmentShortestPathCacheSet_firstHalf(phdr, (uint8*)tc, pip, ip_s, ip_d, 0, ip_alias);

                }
        }



        tc->th_sport = (ip_aliasp);

        do{ *((uint8*)(&pip->ip_src)) = (uint8)((ip_alias)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((ip_alias)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((ip_alias)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((ip_alias)); }while(0);

        return (0);
}
# 11641 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4TcpNatAlgAliasOut(struct rtl_pktHdr *phdr, struct ip *pip, rtl8651_tblDrv_natEntry_t *natEntry)
{
        struct tcphdr *tc;
        ipaddr_t ip_s, ip_d, ip_alias = 0;
        uint16 ip_sp, ip_dp, ip_aliasp = 0;
        struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s entry, *tb=&entry;
        rtl8651_tblDrv_algEntry_t *client_alg_link = ((void *)0);
        rtl8651_tblDrv_algEntry_t *server_alg_link = ((void *)0);
        int32 accumulate = 0;
        uint32 actionFlag = 0;
        rtl8651_tblDrv_pppTable_t *thisPPPoE;
        uint16 mtu;







        tc = (struct tcphdr *) ((int8 *) pip + ((*(uint8*)pip&0xf) << 2));

        ip_s = phdr->ph_sip;
        ip_d = phdr->ph_dip;
        ip_sp = (tc->th_sport);
        ip_dp = (tc->th_dport);

        if (ip_s == natEntry->globalIp)
        {
                ip_alias = natEntry->globalIp;
                tb = ((void *)0);
                goto adjust_mss;
        }

        client_alg_link = _rtl8651_l4FindLinkAlg(ip_dp, 1);
        if(ip_sp != ip_dp)
        {
                server_alg_link = _rtl8651_l4FindLinkAlg(ip_sp, 1);
        }






        if( _rtl8651_getOutboundAlgConnection(1,ip_s,ip_sp,ip_d,ip_dp, &tb)!=0)
        {
                tb=((void *)0);
        }


        if(tc->th_flags & 0x02)
                actionFlag |= 0x01;

        if(tb)
                actionFlag |= 0x02;

        if(client_alg_link)
                actionFlag |= 0x08;

        if(server_alg_link)
                actionFlag |= 0x10;





        switch(actionFlag){

                case 2:


                        if(tb->alg_client_out){
                                int r;
                                r = tb->alg_client_out(phdr, pip, tb);
                                if(r==131) {
                                        return 131;
                                }
                        }
                        if(tb->alg_server_out){
                                int r;
                                r = tb->alg_server_out(phdr, pip, tb);
                                if(r==131) {
                                        return 131;
                                }
                        }
                        break;
                case 9:
                case 17 :

                        ip_alias = natEntry->globalIp;
                        ip_aliasp = ip_sp;
                        tb= _rtl8651_addNaptAlgConnection(
                                (1|0x0020|0x0040),2,
                                ip_s,ip_sp, &ip_alias,&ip_aliasp,ip_d,ip_dp);
                        if(!tb)
                                return 119;

                        tb->tcpAckModified = 0;
                        tb->tcpFtpLastLineCRLFTermed = 0;
                        tb->tcpStateINdex = 0;
                        memset(&tb->ack[0],0,sizeof(struct l4ack_data_record)*2);
                        tb->natlink = 1;
                        break;

                case 10:
                case 11:

                         if(client_alg_link->fwEngAdd && client_alg_link->alg_outboundClientcb){
                                int r;
                                r=client_alg_link->alg_outboundClientcb(phdr, pip, tb);
                                if(r==131) return 131;
                         }
                         break;

                case 18:
                case 19:

                         if(server_alg_link->fwEngAdd && server_alg_link->alg_outboundServercb){
                                int r;
                                r=server_alg_link->alg_outboundServercb(phdr, pip, tb);
                                if(r==131) return 131;
                         }
                         break;
                case 1:
                        ip_alias = natEntry->globalIp;
                        goto adjust_mss;
                case 0:
                        return 117;
                default:
                        printk("%s: action=%d, flag=%d\n",__FUNCTION__,actionFlag,tc->th_flags );
                        return 118;
        }

        do {} while (0);
        ip_alias = tb->insideGlobalIpAddr;
        ip_aliasp = tb->insideGlobalPort;


        _rtl8651_l4TcpMonitorOut(tc, tb);


adjust_mss:
        if(tc->th_flags & 0x02)
        {
                int8 auto_add = 0,auto_delete;
                rtl8651_getAsicNaptAutoAddDelete(&auto_add,&auto_delete);
                if(auto_add == 0){
                        uint8 *cp;
                        int32 opt, optlen,cnt;
                        uint16 mss;

                        cp = (uint8 *)(tc+1);
                        cnt = ((tc->th_off_x >>2)&0x3c) -sizeof(struct tcphdr);

                        for(; cnt > 0; cnt -= optlen, cp+= optlen){
                                opt = cp[0];
                                if(opt == 0)
                                        break;
                                if(opt == 1)
                                        optlen = 1;
                                else{
                                        optlen = cp[1];
                                        if(optlen <= 0)
                                                break;
                                }

                                switch (opt) {
                                case 2:
                                        mss = (*(uint16*)(&cp[2]));


                                        thisPPPoE=_rtl8651_getPppoeSessionByIpAddr(ip_alias);



                                        if (thisPPPoE)
                                        {
                                                if (mss >pppoe_mss[thisPPPoE->dsid])
                                                {
                                                        mtu=pppoe_mss[thisPPPoE->dsid];
                                                        accumulate -=(mss-pppoe_mss[thisPPPoE->dsid]);
                                                        *(uint16*)(&cp[2]) = (mtu);
                                                }
                                        }else if(mss > rtl8651_mss){

                                                mtu=rtl8651_mss;
                                                accumulate -=(mss-rtl8651_mss);
                                                *(uint16*)(&cp[2]) = (mtu);
                                        }
                                        break;
                                default:
                                        continue;
                                }
                        }
                }
        }


        if(tb){
                tc->th_sport = ip_aliasp;

                if (tb->tcpAckModified == 1)
                {
                        int32 delta;

                        delta = _rtl8651_l4GetDeltaSeqOut(pip, tc, tb);
                        accumulate += delta;
                        if (delta != 0){
                                uint32 seq_32_x = ((uint32) (*((uint8*)(&tc->th_seq))<<24)|(*(((uint8*)(&tc->th_seq))+1)<<16)|(*(((uint8*)(&tc->th_seq))+2)<<8) | *(((uint8*)(&tc->th_seq))+3));
                                seq_32_x = ((seq_32_x) + delta);
                                do{ *((uint8*)(&tc->th_seq)) = (uint8)((seq_32_x)>>24); *(((uint8*)(&tc->th_seq))+1) = (uint8)((seq_32_x)>>16); *(((uint8*)(&tc->th_seq))+2) = (uint8)((seq_32_x)>>8); *(((uint8*)(&tc->th_seq))+3) = (uint8)((seq_32_x)); }while(0);
                        }
                }
                do{ *((uint8*)(&pip->ip_src)) = (uint8)((ip_alias)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((ip_alias)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((ip_alias)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((ip_alias)); }while(0);
        }else{
                do {} while (0);
                do{ *((uint8*)(&pip->ip_src)) = (uint8)((natEntry->globalIp)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((natEntry->globalIp)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((natEntry->globalIp)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((natEntry->globalIp)); }while(0);
        }

        if(tb)
        {
                if (((pip->ip_vhl & 0x0f) != 5) || (((pip->ip_off) & (0x2000 | 0x1fff)) == 0x2000))
                {

                        if ((pip->ip_vhl & 0x0f) != 5)
                        {
                                do { do { int32 accumulate = 0; if ((((ip_alias)) != 0) && (((ip_s)) != 0)){ accumulate = (((ip_s)) & 0xffff); accumulate += (( ((ip_s)) >> 16 ) & 0xffff); accumulate -= (((ip_alias)) & 0xffff); accumulate -= (( ((ip_alias)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                        }

                        do { int32 accumulate = 0; if (((ip_alias) != 0) && ((ip_s) != 0)){ accumulate = ((ip_s) & 0xffff); accumulate += (( (ip_s) >> 16 ) & 0xffff); accumulate -= ((ip_alias) & 0xffff); accumulate -= (( (ip_alias) >> 16 ) & 0xffff); } if (((ip_aliasp) != 0) && ((ip_sp) != 0)){ accumulate += (ip_sp); accumulate -= (ip_aliasp); } do { accumulate += ((tc->th_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) accumulate); } } while (0); }while(0);
                        do { accumulate += (tc->th_sum); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; tc->th_sum = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; tc->th_sum = ((uint16) accumulate); } } while (0);
                }
        } else
        {
                ip_alias = natEntry->globalIp;

                if (((pip->ip_vhl & 0x0f) != 5) || (((pip->ip_off) & (0x2000 | 0x1fff)) == 0x2000))
                {

                        if ((pip->ip_vhl & 0x0f) != 5)
                        {
                                do { do { int32 accumulate = 0; if ((((ip_alias)) != 0) && (((ip_s)) != 0)){ accumulate = (((ip_s)) & 0xffff); accumulate += (( ((ip_s)) >> 16 ) & 0xffff); accumulate -= (((ip_alias)) & 0xffff); accumulate -= (( ((ip_alias)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                        }


                        do { int32 accumulate = 0; if (((ip_alias) != 0) && ((ip_s) != 0)){ accumulate = ((ip_s) & 0xffff); accumulate += (( (ip_s) >> 16 ) & 0xffff); accumulate -= ((ip_alias) & 0xffff); accumulate -= (( (ip_alias) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += ((tc->th_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) accumulate); } } while (0); }while(0);
                        do { accumulate += (tc->th_sum); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; tc->th_sum = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; tc->th_sum = ((uint16) accumulate); } } while (0);
                }
        }


        return (0);
}


static inline int32 _rtl8651_l4NaptFlowGetDSID (uint8 fromInternal, struct rtl_pktHdr *pkthdr, struct ip *pip)
{
        rtl8651_tblDrv_naptTcpUdpFlowEntry_t tcpUdpDummy, *tcpUdpTb = &tcpUdpDummy;
        ipaddr_t sip = pkthdr->ph_sip;
        ipaddr_t dip = pkthdr->ph_dip;

        if ( fromInternal == 1 )
        {
                if ( (((uint16)(pip->ip_off)) & 0x1fff) )
                {
                        if ( _rtl8651_getFragCache( 1,
                                                                                sip,
                                                                                dip,
                                                                                (pip->ip_id),
                                                                                ((void *)0),
                                                                                ((void *)0),
                                                                                ((void *)0),
                                                                                &(pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid)) == 0)
                        {
                                goto dsidGetSuccess;
                        }
                        goto dsidGetFail;
                }

                switch ( pip->ip_p )
                {
                        case 6:
                        {
                                struct tcphdr *tc;
                                uint16 sport;
                                uint16 dport;

                                tc = (struct tcphdr *)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));
                                sport = tc->th_sport;
                                dport = tc->th_dport;

                                if (_rtl8651_getOutboundNaptFlow( 1,
                                                                                                        sip,
                                                                                                        sport,
                                                                                                        dip,
                                                                                                        dport,
                                                                                                        &tcpUdpTb) != 0)
                                {
                                        tcpUdpTb = &tcpUdpDummy;
                                        if (_rtl8651_getOutboundAlgConnection( 1,
                                                                                                        sip,
                                                                                                        sport,
                                                                                                        dip,
                                                                                                        dport,
                                                                                                        &tcpUdpTb) != 0)
                                        {
                                                tcpUdpTb = ((void *)0);
                                        }
                                }


                                if ( tcpUdpTb )
                                {
                                        pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid = tcpUdpTb->dsid;
                                        goto dsidGetSuccess;
                                }

                                break;
                        }
                        case 17:
                        {
                                struct udphdr *ud;
                                uint16 sport;
                                uint16 dport;

                                ud = (struct udphdr *)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));
                                sport = ud->uh_sport;
                                dport = ud->uh_dport;

                                if (_rtl8651_getOutboundNaptFlow( 0,
                                                                                                        sip,
                                                                                                        sport,
                                                                                                        dip,
                                                                                                        dport,
                                                                                                        &tcpUdpTb) != 0)
                                {
                                        tcpUdpTb = &tcpUdpDummy;
                                        if (_rtl8651_getOutboundAlgConnection( 0,
                                                                                                        sip,
                                                                                                        sport,
                                                                                                        dip,
                                                                                                        dport,
                                                                                                        &tcpUdpTb) != 0)
                                        {
                                                tcpUdpTb = ((void *)0);
                                        }
                                }


                                if ( tcpUdpTb )
                                {
                                        pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid = tcpUdpTb->dsid;
                                        goto dsidGetSuccess;
                                }

                                break;
                        }
                        case 1:
                        {
                                rtl8651_tblDrv_naptIcmpFlowEntry_t *icmpTb;
                                struct icmp *ic;
                                uint16 id;

                                icmpTb = ((void *)0);
                                tcpUdpTb = ((void *)0);

                                ic = (struct icmp *)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));
                                id = ic->icmp_hun.ih_idseq.icd_id;

                                switch ( ic->icmp_type )
                                {
                                        case 0:
                                        case 14:
                                        case 8:
                                        case 13:

                                                icmpTb = _rtl8651_getInsideNaptIcmpEntry( sip,
                                                                                                                                        id,
                                                                                                                                        dip,
                                                                                                                                        0,
                                                                                                                                        0);
                                                break;

                                        case 11:
                                        case 3:
                                        case 4:
                                        case 12:
                                        {
                                                struct ip *eip = ((void *)0);
                                                ipaddr_t esip, edip;

                                                eip = &(ic->icmp_dun.id_ip.idi_ip);
                                                esip = ((uint32) (*((uint8*)(&(eip->ip_src)))<<24)|(*(((uint8*)(&(eip->ip_src)))+1)<<16)|(*(((uint8*)(&(eip->ip_src)))+2)<<8) | *(((uint8*)(&(eip->ip_src)))+3));
                                                edip = ((uint32) (*((uint8*)(&(eip->ip_dst)))<<24)|(*(((uint8*)(&(eip->ip_dst)))+1)<<16)|(*(((uint8*)(&(eip->ip_dst)))+2)<<8) | *(((uint8*)(&(eip->ip_dst)))+3));

                                                if ((((uint16)(eip->ip_off)) & 0x1fff))
                                                {
                                                        ;

                                                } else
                                                {
                                                        if (eip->ip_p == 17)
                                                        {
                                                                struct udphdr *ud = (struct udphdr *)((uint8 *)eip + (((*(uint8*)eip)&0xf) << 2));
                                                                tcpUdpTb = &tcpUdpDummy;
                                                                if ( _rtl8651_getOutboundNaptFlow( 0,
                                                                                                                                        edip,
                                                                                                                                        (ud->uh_dport),
                                                                                                                                        esip,
                                                                                                                                        (ud->uh_sport)
                                                                                                                                        ,&tcpUdpTb )
                                                                        != 0 )
                                                                {
                                                                        tcpUdpTb = ((void *)0);
                                                                }
                                                        } else if (eip->ip_p == 6)
                                                        {
                                                                struct tcphdr *tc = (struct tcphdr *)((uint8 *)eip + (((*(uint8*)eip)&0xf) << 2));
                                                                tcpUdpTb = &tcpUdpDummy;
                                                                if(_rtl8651_getOutboundNaptFlow( 1,
                                                                                                                                        edip,
                                                                                                                                        (tc->th_dport),
                                                                                                                                        esip,
                                                                                                                                        (tc->th_sport),
                                                                                                                                        &tcpUdpTb )
                                                                        != 0 )
                                                                {
                                                                        tcpUdpTb = ((void *)0);
                                                                }
                                                        } else if (eip->ip_p == 1)
                                                        {
                                                                struct icmp *eic = (struct icmp *) ((uint8 *)eip + (((*(uint8*)eip)&0xf) << 2));
                                                                icmpTb = _rtl8651_getInsideNaptIcmpEntry( edip,
                                                                                                                                                        (eic->icmp_hun.ih_idseq.icd_id),
                                                                                                                                                        esip,
                                                                                                                                                        0,
                                                                                                                                                        0);
                                                        } else
                                                        {
                                                                ;

                                                        }
                                                }
                                        }
                                        break;
                                }

                                if ( icmpTb )
                                {
                                        pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid = icmpTb->dsid;
                                        goto dsidGetSuccess;
                                }

                                if ( tcpUdpTb )
                                {
                                        pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid = tcpUdpTb->dsid;
                                        goto dsidGetSuccess;
                                }


                                break;
                        }
                        default:
                        {
                                break;
                        }
                }
        } else
        {
                if ( (((uint16)(pip->ip_off)) & 0x1fff) )
                {
                        if ( _rtl8651_getFragCache( 0,
                                                                                sip,
                                                                                dip,
                                                                                (pip->ip_id),
                                                                                ((void *)0),
                                                                                ((void *)0),
                                                                                ((void *)0),
                                                                                &(pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid)) == 0)
                        {
                                goto dsidGetSuccess;
                        }
                        goto dsidGetFail;
                }

                switch ( pip->ip_p )
                {
                        case 6:
                        {
                                struct tcphdr *tc;
                                uint16 sport;
                                uint16 dport;

                                tc = (struct tcphdr *)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));
                                sport = tc->th_sport;
                                dport = tc->th_dport;

                                if ( _rtl8651_getInboundNaptFlow( 1,
                                                                                                        dip,
                                                                                                        dport,
                                                                                                        sip,
                                                                                                        sport,
                                                                                                        &tcpUdpTb) != 0)
                                {
                                        tcpUdpTb = ((void *)0);
                                }


                                if ( tcpUdpTb )
                                {
                                        pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid = tcpUdpTb->dsid;
                                        goto dsidGetSuccess;
                                }

                                break;
                        }
                        case 17:
                        {
                                struct udphdr *ud;
                                uint16 sport;
                                uint16 dport;

                                ud = (struct udphdr *)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));
                                sport = ud->uh_sport;
                                dport = ud->uh_dport;

                                if ( _rtl8651_getInboundNaptFlow( 0,
                                                                                                        dip,
                                                                                                        dport,
                                                                                                        sip,
                                                                                                        sport,
                                                                                                        &tcpUdpTb) != 0)
                                {
                                        tcpUdpTb = ((void *)0);
                                }


                                if ( tcpUdpTb )
                                {
                                        pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid = tcpUdpTb->dsid;
                                        goto dsidGetSuccess;
                                }

                                break;
                        }
                        case 1:
                        {
                                rtl8651_tblDrv_naptIcmpFlowEntry_t *icmpTb;
                                struct icmp *ic;
                                uint16 id;

                                icmpTb = ((void *)0);
                                tcpUdpTb = ((void *)0);

                                ic = (struct icmp *)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));
                                id = ic->icmp_hun.ih_idseq.icd_id;

                                switch ( ic->icmp_type )
                                {
                                        case 0:
                                        case 14:
                                        case 8:
                                        case 13:
                                        {
                                                icmpTb = _rtl8651_getOutsideNaptIcmpEntry( sip,
                                                                                                                                        id,
                                                                                                                                        dip,
                                                                                                                                        0,
                                                                                                                                        0);
                                                break;
                                        }
                                        case 11:
                                        case 3:
                                        case 4:
                                        case 12:
                                        {
                                                struct ip *eip = ((void *)0);
                                                ipaddr_t esip, edip;

                                                eip = &(ic->icmp_dun.id_ip.idi_ip);
                                                esip = ((uint32) (*((uint8*)(&(eip->ip_src)))<<24)|(*(((uint8*)(&(eip->ip_src)))+1)<<16)|(*(((uint8*)(&(eip->ip_src)))+2)<<8) | *(((uint8*)(&(eip->ip_src)))+3));
                                                edip = ((uint32) (*((uint8*)(&(eip->ip_dst)))<<24)|(*(((uint8*)(&(eip->ip_dst)))+1)<<16)|(*(((uint8*)(&(eip->ip_dst)))+2)<<8) | *(((uint8*)(&(eip->ip_dst)))+3));

                                                if ((((uint16)(eip->ip_off)) & 0x1fff))
                                                {
                                                        ;

                                                } else
                                                {
                                                        if (eip->ip_p == 17)
                                                        {
                                                                struct udphdr *ud = (struct udphdr *)((uint8 *)eip + (((*(uint8*)eip)&0xf) << 2));
                                                                tcpUdpTb = &tcpUdpDummy;
                                                                if ( _rtl8651_getInboundNaptFlow( 0,
                                                                                                                                        esip,
                                                                                                                                        (ud->uh_sport),
                                                                                                                                        edip,
                                                                                                                                        (ud->uh_dport),
                                                                                                                                        &tcpUdpTb )
                                                                        != 0 )
                                                                {
                                                                        tcpUdpTb = ((void *)0);
                                                                }
                                                        } else if (eip->ip_p == 6)
                                                        {
                                                                struct tcphdr *tc = (struct tcphdr *)((uint8 *)eip + (((*(uint8*)eip)&0xf) << 2));
                                                                tcpUdpTb = &tcpUdpDummy;
                                                                if ( _rtl8651_getInboundNaptFlow( 1,
                                                                                                                                        esip,
                                                                                                                                        (tc->th_sport),
                                                                                                                                        edip,
                                                                                                                                        (tc->th_dport),
                                                                                                                                        &tcpUdpTb )
                                                                        != 0 )
                                                                {
                                                                        tcpUdpTb = ((void *)0);
                                                                }
                                                        } else if (eip->ip_p == 1)
                                                        {
                                                                struct icmp *eic = (struct icmp *)((uint8 *)eip + (((*(uint8*)eip)&0xf) << 2));
                                                                icmpTb = _rtl8651_getOutsideNaptIcmpEntry( esip,
                                                                                                                                                        (eic->icmp_hun.ih_idseq.icd_id),
                                                                                                                                                        edip,
                                                                                                                                                        0,
                                                                                                                                                        0);
                                                        } else
                                                        {
                                                                ;

                                                        }
                                                }
                                                break;
                                        }
                                }

                                if ( icmpTb )
                                {
                                        pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid = icmpTb->dsid;
                                        goto dsidGetSuccess;
                                }

                                if ( tcpUdpTb )
                                {
                                        pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid = tcpUdpTb->dsid;
                                        goto dsidGetSuccess;
                                }

                                break;
                        }
                        default:
                        {
                                break;
                        }
                }

        }
dsidGetFail:
        return -1;

dsidGetSuccess:
        return 0;
}
# 12315 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4TcpFastAliasIn(struct rtl_pktHdr *phdr, struct ip *pip)
{
        struct tcphdr *tc;
        ipaddr_t ip_org;
        ipaddr_t ip_s, ip_d;
        uint16 ip_sp, ip_dp, ip_orgp;
        struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s entry, *tb;

        ip_s=phdr->ph_sip;
        ip_d=phdr->ph_dip;
# 12335 "rtl8651_tblDrvFwd.c"
                if ((((uint16)(pip->ip_off)) & 0x1fff))
                {
                        uint32 org_ip;
                        if (_rtl8651_getFragCache(0, ip_s, ip_d, (pip->ip_id), &org_ip, &(phdr->ph_routeIdx), ((void *)0), &(phdr->ph_un_sw.ROMEDRV_USG._ph_dsid)) == 0)
                        {
                                do{ *((uint8*)(&pip->ip_dst)) = (uint8)((org_ip)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((org_ip)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((org_ip)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((org_ip)); }while(0);
                                if (!(((*(uint8*)pip)&0xf) == 5))
                                {
                                        do { do { int32 accumulate = 0; if ((((org_ip)) != 0) && (((ip_d)) != 0)){ accumulate = (((ip_d)) & 0xffff); accumulate += (( ((ip_d)) >> 16 ) & 0xffff); accumulate -= (((org_ip)) & 0xffff); accumulate -= (( ((org_ip)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                                }
                                if (_rtl8651_l3FastActRouting(((uint32)(1)<<1), phdr, org_ip, pip, ((void *)0)) == 0)
                                        return 0;
                        }
                        return -1;
                }


        tb = &entry;
        tc = (struct tcphdr *)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));
        ip_sp = (tc->th_sport);
        ip_dp = (tc->th_dport);

        if (tc->th_flags & (0x02|0x01|0x04))
                return -1;


        if (((((uint16)(pip->ip_off)) & (0x1fff|0x2000))) && (_rtl8651_fragQueueProcessOk == 0) && (_rtl8651_frag_NeedFragmentProcess((pip->ip_id), ip_s, ip_d, 6) == 1))
                return -1;


        if (_rtl8651_getInboundNaptFlow(1, ip_d, ip_dp, ip_s, ip_sp, &tb) != 0)
        {
                return -1;
        }

        if (tb->inListType == 3)
        {
                return -1;
        }

        if (tb->toProtocolStack == 1)
        {
                return -1;
        }

        if(tb->alg_client_out || tb->alg_server_out || tb->alg_client_in || tb->alg_server_in )
                return -1;

        if(tb->tcpFlag != (5 -1))
        {
                return -1;
        }

        ip_org = tb->insideLocalIpAddr;
        ip_orgp = tb->insideLocalPort;



                if ((_urlFilterAclRuleNum>=0) &&
                        ((phdr->ph_reason&0xe)==4
                        && ((phdr->ph_reason&0xff0)>>5)==_urlFilterAclRuleNum))



                {
                        return -1;
                }



        tc->th_dport = (ip_orgp);


        do{ *((uint8*)(&pip->ip_dst)) = (uint8)((ip_org)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((ip_org)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((ip_org)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((ip_org)); }while(0);


        phdr->ph_un_sw.ROMEDRV_USG._ph_dsid = tb->dsid;

        if (tb->in_rt_t)
        {
                phdr->ph_routeIdx = ((rtl8651_tblDrv_routeTable_t *)tb->in_rt_t-DrvTbl.route) + 1;
        }else
        {
                rtl8651_tblDrv_routeTable_t *rt_entry;
                if (((rt_entry = _rtl8651_getSoftRoutingEntry(ip_s, ip_org, 6, ip_orgp)) == ((void *)0)) &&
                        ((rt_entry = _rtl8651_getRoutingEntry(ip_org)) == ((void *)0)))
                        return 0x1000;
                tb->in_rt_t = rt_entry;
                phdr->ph_routeIdx = (rt_entry-DrvTbl.route) + 1;
        }

        if(_rtl8651_l4TcpMonitorIn(tc, tb)!=0)
        {
                return 0x1000;
        }

        if (((((uint16)(pip->ip_off)) & (0x1fff|0x2000))) || (!(((*(uint8*)pip)&0xf) == 5)))
        {
                if (!(((*(uint8*)pip)&0xf) == 5))
                {
                        do { do { int32 accumulate = 0; if ((((ip_org)) != 0) && (((ip_d)) != 0)){ accumulate = (((ip_d)) & 0xffff); accumulate += (( ((ip_d)) >> 16 ) & 0xffff); accumulate -= (((ip_org)) & 0xffff); accumulate -= (( ((ip_org)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                }
                do { int32 accumulate = 0; if (((ip_org) != 0) && ((ip_d) != 0)){ accumulate = ((ip_d) & 0xffff); accumulate += (( (ip_d) >> 16 ) & 0xffff); accumulate -= ((ip_org) & 0xffff); accumulate -= (( (ip_org) >> 16 ) & 0xffff); } if (((ip_orgp) != 0) && ((ip_dp) != 0)){ accumulate += (ip_dp); accumulate -= (ip_orgp); } do { accumulate += ((tc->th_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) accumulate); } } while (0); }while(0);
                if ((((uint16)(pip->ip_off)) & (0x1fff|0x2000)))
                {
                        _rtl8651_updateFragCache(0, ip_s, ip_d, (pip->ip_id), ip_org, phdr->ph_routeIdx, ((void *)0), phdr->ph_un_sw.ROMEDRV_USG._ph_dsid);

                        _rtl8651_fragmentShortestPathCacheSet_firstHalf(phdr, (uint8*)tc, pip, ip_s, ip_d, 1, ip_org);

                }
        }

        if( _rtl8651_l3FastActRouting(((uint32)(1)<<1), phdr, ip_org, pip, &tb->in_macInfo_t) == 0)
        {
                return 0;
        }

        return 0x1000;
}
# 12467 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4TcpFastAliasOut(struct rtl_pktHdr *phdr, struct ip *pip)
{
        struct tcphdr *tc;
        ipaddr_t ip_alias;
        ipaddr_t ip_s, ip_d;
        uint16 ip_sp, ip_dp, ip_aliasp;
        struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s entry, *tb;

        ip_s=phdr->ph_sip;
        ip_d=phdr->ph_dip;
# 12492 "rtl8651_tblDrvFwd.c"
        if ((((uint16)(pip->ip_off)) & 0x1fff))
        {

                uint32 alias_ip;
                if (_rtl8651_getFragCache(1, ip_s, ip_d, (pip->ip_id), &alias_ip, &(phdr->ph_routeIdx), ((void *)0), &(phdr->ph_un_sw.ROMEDRV_USG._ph_dsid)) == 0)
                {
                        do{ *((uint8*)(&pip->ip_src)) = (uint8)((alias_ip)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((alias_ip)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((alias_ip)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((alias_ip)); }while(0);
                        if (!(((*(uint8*)pip)&0xf) == 5))
                        {
                                do { do { int32 accumulate = 0; if ((((alias_ip)) != 0) && (((ip_s)) != 0)){ accumulate = (((ip_s)) & 0xffff); accumulate += (( ((ip_s)) >> 16 ) & 0xffff); accumulate -= (((alias_ip)) & 0xffff); accumulate -= (( ((alias_ip)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                        }
                        if (_rtl8651_l3FastActRouting(((uint32)(1)<<1), phdr, ip_d, pip, ((void *)0)) == 0)
                                return 0;
                }
                return -1;
        }


        tb = &entry;
        tc = (struct tcphdr *)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));
        ip_sp = (tc->th_sport);
        ip_dp = (tc->th_dport);

        if (tc->th_flags & (0x02|0x01|0x04))
                return -1;


        if (((((uint16)(pip->ip_off)) & (0x1fff|0x2000))) && (_rtl8651_fragQueueProcessOk == 0) && (_rtl8651_frag_NeedFragmentProcess((pip->ip_id), ip_s, ip_d, 6) == 1))
                return -1;


        if (_rtl8651_getOutboundNaptFlow(1, ip_s, ip_sp, ip_d, ip_dp, &tb) != 0)
        {
                return -1;
        }

        if (tb->outListType == 2)
        {
                return -1;
        }

        if (tb->toProtocolStack == 1)
        {
                do {} while (0);
                return -1;
        }

        if(tb->alg_client_out || tb->alg_server_out)
                return -1;

        if(tb->tcpFlag != (5 -1))
        {
                return -1;
        }




                        if((_urlFilterAclRuleNum>=0) &&
                                ((phdr->ph_reason&0xe)==4
                                && ((phdr->ph_reason&0xff0)>>5)==_urlFilterAclRuleNum))



                {
                        return -1;
                }


        ip_alias = tb->insideGlobalIpAddr;
        ip_aliasp = tb->insideGlobalPort;


        phdr->ph_un_sw.ROMEDRV_USG._ph_dsid = tb->dsid;

        if(_rtl8651_l4TcpMonitorOut(tc, tb)!=0)
        {
                return 0x1000;
        }


        tc->th_sport = (ip_aliasp);
        do{ *((uint8*)(&pip->ip_src)) = (uint8)((ip_alias)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((ip_alias)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((ip_alias)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((ip_alias)); }while(0);
        if (tb->out_rt_t)
        {
                phdr->ph_routeIdx = ((rtl8651_tblDrv_routeTable_t *)tb->out_rt_t-DrvTbl.route) + 1;
        }else
        {
                rtl8651_tblDrv_routeTable_t *rt_entry;
                if (((rt_entry = _rtl8651_getSoftRoutingEntry(ip_alias, ip_d, 6, ip_dp)) == ((void *)0)) &&
                        ((rt_entry = _rtl8651_getRoutingEntry(ip_d)) == ((void *)0)))
                        return 0x1000;
                tb->out_rt_t = rt_entry;
                phdr->ph_routeIdx = (rt_entry-DrvTbl.route) + 1;
        }

        if (((((uint16)(pip->ip_off)) & (0x1fff|0x2000)) == 0x2000)||(!(((*(uint8*)pip)&0xf) == 5)))
        {
                if (!(((*(uint8*)pip)&0xf) == 5))
                {
                        do { do { int32 accumulate = 0; if ((((ip_alias)) != 0) && (((ip_s)) != 0)){ accumulate = (((ip_s)) & 0xffff); accumulate += (( ((ip_s)) >> 16 ) & 0xffff); accumulate -= (((ip_alias)) & 0xffff); accumulate -= (( ((ip_alias)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                }
                do { int32 accumulate = 0; if (((ip_alias) != 0) && ((ip_s) != 0)){ accumulate = ((ip_s) & 0xffff); accumulate += (( (ip_s) >> 16 ) & 0xffff); accumulate -= ((ip_alias) & 0xffff); accumulate -= (( (ip_alias) >> 16 ) & 0xffff); } if (((ip_aliasp) != 0) && ((ip_sp) != 0)){ accumulate += (ip_sp); accumulate -= (ip_aliasp); } do { accumulate += ((tc->th_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) accumulate); } } while (0); }while(0);
                if (((((uint16)(pip->ip_off)) & (0x1fff|0x2000)) == 0x2000))
                {
                        _rtl8651_updateFragCache(1, ip_s, ip_d, (pip->ip_id), ip_alias, phdr->ph_routeIdx, ((void *)0), phdr->ph_un_sw.ROMEDRV_USG._ph_dsid);

                        _rtl8651_fragmentShortestPathCacheSet_firstHalf(phdr, (uint8*)tc, pip, ip_s, ip_d, 0, ip_alias);

                }
        }


        if( _rtl8651_l3FastActRouting(((uint32)(1)<<1), phdr, ip_d, pip, &tb->out_macInfo_t) == 0)
        {
                return 0;
        }
        return 0x1000;
}
# 12622 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4UdpFastAliasIn(struct rtl_pktHdr *phdr, struct ip *pip)
{
        struct udphdr *ud;
        ipaddr_t ip_org;
        uint16 ip_sp, ip_dp, ip_orgp;
        struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s entry, *tb;
        ipaddr_t ip_s, ip_d;

        ip_s=phdr->ph_sip;
        ip_d=phdr->ph_dip;
# 12642 "rtl8651_tblDrvFwd.c"
        if ((((uint16)(pip->ip_off)) & 0x1fff))
        {
                ipaddr_t newIp;
                rtl8651_tblDrv_naptTcpUdpFlowEntry_t *napt_t = ((void *)0);
                if (_rtl8651_getFragCache(0, ip_s, ip_d, (pip->ip_id), &newIp, &(phdr->ph_routeIdx), &napt_t, &(phdr->ph_un_sw.ROMEDRV_USG._ph_dsid)) == 0)
                {
                        do{ *((uint8*)(&pip->ip_dst)) = (uint8)((newIp)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((newIp)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((newIp)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((newIp)); }while(0);
                        if (!(((*(uint8*)pip)&0xf) == 5))
                        {
                                do { do { int32 accumulate = 0; if ((((newIp)) != 0) && (((ip_d)) != 0)){ accumulate = (((ip_d)) & 0xffff); accumulate += (( ((ip_d)) >> 16 ) & 0xffff); accumulate -= (((newIp)) & 0xffff); accumulate -= (( ((newIp)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                        }
                        if (_rtl8651_l3FastActRouting(((uint32)(1)<<1), phdr, newIp, pip, napt_t?(&napt_t->in_macInfo_t):((void *)0)) == 0)
                                return 0;
                        else
                                return 0x1000;
                }
                return -1;
        }


        tb = &entry;
        ud = (struct udphdr *)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));
        ip_sp = (ud->uh_sport);
        ip_dp = (ud->uh_dport);


        if (((((uint16)(pip->ip_off)) & (0x1fff|0x2000))) && (_rtl8651_fragQueueProcessOk == 0) && (_rtl8651_frag_NeedFragmentProcess((pip->ip_id), ip_s, ip_d, 17) == 1))
                return -1;


        if (_rtl8651_getInboundNaptFlow(0,ip_d,ip_dp,ip_s,ip_sp, &tb) != 0)
        {
                return -1;
        }

        if (tb->inListType == 3)
        {
                return -1;
        }

        if (tb->toProtocolStack == 1)
        {
                return -1;
        }

        if (tb->alg_client_in != ((void *)0) || tb->alg_server_in)
                return -1;


        _rtl8651_updateNaptConnection(tb, 0, rtl8651GlobalControl.udpTimeout);

        ip_org = tb->insideLocalIpAddr;
        ip_orgp = tb->insideLocalPort;


        phdr->ph_un_sw.ROMEDRV_USG._ph_dsid = tb->dsid;


        ud->uh_dport = (ip_orgp);
        do{ *((uint8*)(&pip->ip_dst)) = (uint8)((ip_org)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((ip_org)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((ip_org)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((ip_org)); }while(0);
        if (tb->in_rt_t)
        {
                phdr->ph_routeIdx = ((rtl8651_tblDrv_routeTable_t *)tb->in_rt_t-DrvTbl.route) + 1;
        }else
        {
                rtl8651_tblDrv_routeTable_t *rt_entry;
                if (((rt_entry = _rtl8651_getSoftRoutingEntry(ip_s, ip_org, 17, ip_orgp)) == ((void *)0)) &&
                        ((rt_entry = _rtl8651_getRoutingEntry(ip_org)) == ((void *)0)))
                        return 0x1000;
                tb->in_rt_t = rt_entry;
                phdr->ph_routeIdx = (rt_entry-DrvTbl.route) + 1;
        }

        if (((((uint16)(pip->ip_off)) & (0x1fff|0x2000))) || (!(((*(uint8*)pip)&0xf) == 5)))
        {
                if (!(((*(uint8*)pip)&0xf) == 5))
                {
                        do { do { int32 accumulate = 0; if ((((ip_org)) != 0) && (((ip_d)) != 0)){ accumulate = (((ip_d)) & 0xffff); accumulate += (( ((ip_d)) >> 16 ) & 0xffff); accumulate -= (((ip_org)) & 0xffff); accumulate -= (( ((ip_org)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                }
                if (ud->uh_sum)
                {
                        do { int32 accumulate = 0; if (((ip_org) != 0) && ((ip_d) != 0)){ accumulate = ((ip_d) & 0xffff); accumulate += (( (ip_d) >> 16 ) & 0xffff); accumulate -= ((ip_org) & 0xffff); accumulate -= (( (ip_org) >> 16 ) & 0xffff); } if (((ip_orgp) != 0) && ((ip_dp) != 0)){ accumulate += (ip_dp); accumulate -= (ip_orgp); } do { accumulate += ((ud->uh_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) accumulate); } } while (0); }while(0);
                }
                if ((((uint16)(pip->ip_off)) & (0x1fff|0x2000)))
                {
                        _rtl8651_updateFragCache(0, ip_s, ip_d, (pip->ip_id), ip_org, phdr->ph_routeIdx, tb, phdr->ph_un_sw.ROMEDRV_USG._ph_dsid);

                        _rtl8651_fragmentShortestPathCacheSet_firstHalf(phdr, (uint8*)ud, pip, ip_s, ip_d, 1, ip_org);

                }
        }

        if( _rtl8651_l3FastActRouting(((uint32)(1)<<1), phdr, ip_org, pip, &tb->in_macInfo_t) == 0)
                return 0;
        return 0x1000;
 }
# 12748 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4UdpFastAliasOut(struct rtl_pktHdr *phdr, struct ip *pip)
{
        struct udphdr *ud;
        ipaddr_t ip_alias;
        uint16 ip_sp, ip_dp, ip_aliasp;
        struct rtl8651_tblDrv_naptTcpUdpFlowEntry_s entry, *tb;
        ipaddr_t ip_s, ip_d;

        ip_s=phdr->ph_sip;
        ip_d=phdr->ph_dip;
# 12769 "rtl8651_tblDrvFwd.c"
        if ((((uint16)(pip->ip_off)) & 0x1fff))
        {
                ipaddr_t newIp;
                rtl8651_tblDrv_naptTcpUdpFlowEntry_t *napt_t = ((void *)0);

                if (_rtl8651_getFragCache(1, ip_s, ip_d, (pip->ip_id), &newIp, &(phdr->ph_routeIdx), &napt_t, &(phdr->ph_un_sw.ROMEDRV_USG._ph_dsid)) == 0)
                {
                        do{ *((uint8*)(&pip->ip_src)) = (uint8)((newIp)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((newIp)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((newIp)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((newIp)); }while(0);
                        if (!(((*(uint8*)pip)&0xf) == 5))
                        {
                                do { do { int32 accumulate = 0; if ((((newIp)) != 0) && (((ip_s)) != 0)){ accumulate = (((ip_s)) & 0xffff); accumulate += (( ((ip_s)) >> 16 ) & 0xffff); accumulate -= (((newIp)) & 0xffff); accumulate -= (( ((newIp)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                        }
                        if (_rtl8651_l3FastActRouting(((uint32)(1)<<1), phdr, ip_d, pip, napt_t?(&napt_t->out_macInfo_t):((void *)0)) == 0)
                                return 0;
                        else
                                return 0x1000;
                }
                return -1;
        }


        tb = &entry;

        ud = (struct udphdr *)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));
        ip_sp = (ud->uh_sport);
        ip_dp = (ud->uh_dport);


        if (((pip->ip_off) & 0x2000) && (_rtl8651_fragQueueProcessOk == 0) && (_rtl8651_frag_NeedFragmentProcess((pip->ip_id), ip_s, ip_d, 17) == 1))
                return -1;


        if (_rtl8651_getOutboundNaptFlow(0, ip_s, ip_sp, ip_d, ip_dp, &tb) != 0)
        {
                return -1;
        }

        if (tb->outListType == 2)
        {
                return -1;
        }

        if (tb->toProtocolStack == 1)
        {
                do {} while (0);
                return -1;
        }

        if (tb->alg_client_out || tb->alg_server_out || tb->alg_client_in || tb->alg_server_in )
                return -1;


        _rtl8651_updateNaptConnection(tb, 0, rtl8651GlobalControl.udpTimeout);

        ip_alias = tb->insideGlobalIpAddr;
        ip_aliasp = tb->insideGlobalPort;


        ud->uh_sport = (ip_aliasp);


        do{ *((uint8*)(&pip->ip_src)) = (uint8)((ip_alias)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((ip_alias)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((ip_alias)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((ip_alias)); }while(0);


        phdr->ph_un_sw.ROMEDRV_USG._ph_dsid = tb->dsid;


        if (tb->out_rt_t)
        {
                phdr->ph_routeIdx = ((rtl8651_tblDrv_routeTable_t *)tb->out_rt_t-DrvTbl.route) + 1;
        }else
        {
                rtl8651_tblDrv_routeTable_t *rt_entry;
                if (((rt_entry = _rtl8651_getSoftRoutingEntry(ip_alias, ip_d, 17, ip_dp)) == ((void *)0)) &&
                        ((rt_entry = _rtl8651_getRoutingEntry(ip_d)) == ((void *)0)))
                        return 0x1000;
                tb->out_rt_t = rt_entry;
                phdr->ph_routeIdx = (rt_entry-DrvTbl.route) + 1;
        }

        if (((((uint16)(pip->ip_off)) & (0x1fff|0x2000))) || (!(((*(uint8*)pip)&0xf) == 5)))
        {
                if (!(((*(uint8*)pip)&0xf) == 5))
                {
                        do { do { int32 accumulate = 0; if ((((ip_alias)) != 0) && (((ip_s)) != 0)){ accumulate = (((ip_s)) & 0xffff); accumulate += (( ((ip_s)) >> 16 ) & 0xffff); accumulate -= (((ip_alias)) & 0xffff); accumulate -= (( ((ip_alias)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                }
                if (ud->uh_sum)
                {
                        do { int32 accumulate = 0; if (((ip_alias) != 0) && ((ip_s) != 0)){ accumulate = ((ip_s) & 0xffff); accumulate += (( (ip_s) >> 16 ) & 0xffff); accumulate -= ((ip_alias) & 0xffff); accumulate -= (( (ip_alias) >> 16 ) & 0xffff); } if (((ip_aliasp) != 0) && ((ip_sp) != 0)){ accumulate += (ip_sp); accumulate -= (ip_aliasp); } do { accumulate += ((ud->uh_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) accumulate); } } while (0); }while(0);
                }
                if ((((uint16)(pip->ip_off)) & (0x1fff|0x2000)))
                {
                        _rtl8651_updateFragCache(1, ip_s, ip_d, (pip->ip_id), ip_alias, phdr->ph_routeIdx, tb, phdr->ph_un_sw.ROMEDRV_USG._ph_dsid);

                        _rtl8651_fragmentShortestPathCacheSet_firstHalf(phdr, (uint8*)ud, pip, ip_s, ip_d, 0, ip_alias);

                }
        }

        if( _rtl8651_l3FastActRouting(((uint32)(1)<<1), phdr, ip_d, pip, &tb->out_macInfo_t) == 0)
                return 0;

        return 0x1000;
}
# 12886 "rtl8651_tblDrvFwd.c"
void _rtl8651_l4AddSeq(struct ip *pip, rtl8651_tblDrv_naptTcpUdpFlowEntry_t *tb, int32 delta)
{

        struct tcphdr *tc;
        struct l4ack_data_record x;
        int32 hlen, tlen, dlen;
        int32 i;
        uint32 seq_32_x;

        if ((pip->ip_p != 6) || (((uint16)(pip->ip_off)) & 0x1fff))
        {
                return;
        }

        tc = (struct tcphdr *)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));
        seq_32_x = ((uint32) (*((uint8*)(&tc->th_seq))<<24)|(*(((uint8*)(&tc->th_seq))+1)<<16)|(*(((uint8*)(&tc->th_seq))+2)<<8) | *(((uint8*)(&tc->th_seq))+3));
        hlen = ((pip->ip_vhl & 0xf) + (( tc->th_off_x >>4)&0xf)) << 2;
        tlen = (pip->ip_len);
        dlen = tlen - hlen;

        x.ack_old = ((seq_32_x) + dlen);
        x.ack_new = ((seq_32_x) + dlen + delta);

        x.delta = delta;
        x.active = 1;

        i = tb->tcpStateINdex;
        i %= 2;
        rtl8651_memcpy(&tb->ack[i],&x,sizeof(struct l4ack_data_record));

        i++;
        if (i == 2)
                tb->tcpStateINdex = 0;
        else
                tb->tcpStateINdex = i;
}
# 12935 "rtl8651_tblDrvFwd.c"
rtl8651_tblDrv_algEntry_t *_rtl8651_l4FindLinkAlg(uint16 alg_port, uint16 isTcp)
{
        rtl8651_tblDrv_algEntry_t *tb;
        int8 isServer, isClient;

        tb = _rtl8651_getAlgEntry(isTcp, &isServer, &isClient, alg_port, alg_port);

        if(tb){
                if( tb->fwEngAdd)
                        return tb;
                else
                        return ((void *)0);
        }

        return ((void *)0);
}
# 12961 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4napt_process(struct rtl_pktHdr * pkthdrPtr , struct ip *ip,uint8 proto, int32 dir)
{
        int32 status;

        if (dir == 2){


                if((((uint16)(ip->ip_off)) & 0x1fff))
                {

                        uint32 alias_ip;

                        ipaddr_t org_sip = ((uint32) (*((uint8*)(&ip->ip_src))<<24)|(*(((uint8*)(&ip->ip_src))+1)<<16)|(*(((uint8*)(&ip->ip_src))+2)<<8) | *(((uint8*)(&ip->ip_src))+3));
                        ipaddr_t org_dip = ((uint32) (*((uint8*)(&ip->ip_dst))<<24)|(*(((uint8*)(&ip->ip_dst))+1)<<16)|(*(((uint8*)(&ip->ip_dst))+2)<<8) | *(((uint8*)(&ip->ip_dst))+3));

                        if (_rtl8651_getFragCache(1, org_sip, org_dip, (ip->ip_id), &alias_ip, &(pkthdrPtr->ph_routeIdx), ((void *)0), &(pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid)) == 0)
                        {
                                do{ *((uint8*)(&ip->ip_src)) = (uint8)((alias_ip)>>24); *(((uint8*)(&ip->ip_src))+1) = (uint8)((alias_ip)>>16); *(((uint8*)(&ip->ip_src))+2) = (uint8)((alias_ip)>>8); *(((uint8*)(&ip->ip_src))+3) = (uint8)((alias_ip)); }while(0);
                                if (!(((*(uint8*)ip)&0xf) == 5))
                                {
                                        do { do { int32 accumulate = 0; if ((((alias_ip)) != 0) && (((pkthdrPtr->ph_sip)) != 0)){ accumulate = (((pkthdrPtr->ph_sip)) & 0xffff); accumulate += (( ((pkthdrPtr->ph_sip)) >> 16 ) & 0xffff); accumulate -= (((alias_ip)) & 0xffff); accumulate -= (( ((alias_ip)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((ip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                                }
                                pkthdrPtr->ph_proto = 2;
                                return 0;
                        }else if (_rtl8651_getFragCache(5, org_sip, org_dip, (ip->ip_id), &alias_ip, ((void *)0), ((void *)0), &(pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid)) == 0)
                        {
                                do{ *((uint8*)(&ip->ip_dst)) = (uint8)((alias_ip)>>24); *(((uint8*)(&ip->ip_dst))+1) = (uint8)((alias_ip)>>16); *(((uint8*)(&ip->ip_dst))+2) = (uint8)((alias_ip)>>8); *(((uint8*)(&ip->ip_dst))+3) = (uint8)((alias_ip)); }while(0);
                                do { do { int32 accumulate = 0; if ((((alias_ip)) != 0) && (((pkthdrPtr->ph_dip)) != 0)){ accumulate = (((pkthdrPtr->ph_dip)) & 0xffff); accumulate += (( ((pkthdrPtr->ph_dip)) >> 16 ) & 0xffff); accumulate -= (((alias_ip)) & 0xffff); accumulate -= (( ((alias_ip)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((ip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                                return 132;
                        }
                        return 40;
                }







                switch (proto){
                        case 6:
                                status = _rtl8651_l4TcpNaptAliasOut(pkthdrPtr, ip);
                                break;
                        case 17:
                                status = _rtl8651_l4UdpNaptAliasOut(pkthdrPtr, ip);
                                break;
                        case 1:
                                status = _rtl8651_l4IcmpNaptAliasOut(pkthdrPtr, ip);
                                break;
                        case 47:
                                if(rtl8651_l4GreNaptAliasOut)
                                {
                                        ipaddr_t ip_s;
                                        ip_s = pkthdrPtr->ph_sip;

                                        status = (*rtl8651_l4GreNaptAliasOut)(pkthdrPtr, ip);
                                        if (status == 0)
                                        {
                                                if (!(((*(uint8*)ip)&0xf) == 5))
                                                {

                                                        do { do { int32 accumulate = 0; if ((((pkthdrPtr->ph_sip)) != 0) && (((ip_s)) != 0)){ accumulate = (((ip_s)) & 0xffff); accumulate += (( ((ip_s)) >> 16 ) & 0xffff); accumulate -= (((pkthdrPtr->ph_sip)) & 0xffff); accumulate -= (( ((pkthdrPtr->ph_sip)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((ip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                                                }
                                                if (((((uint16)(ip->ip_off)) & (0x1fff|0x2000)) == 0x2000))
                                                {
                                                        _rtl8651_updateFragCache(1, ip_s, pkthdrPtr->ph_dip, (ip->ip_id), pkthdrPtr->ph_sip, pkthdrPtr->ph_routeIdx, ((void *)0), pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid);
                                                }
                                                pkthdrPtr->ph_sip = ip_s;
                                        }
                                }else
                                {
                                        status = 51;
                                }
                                if (status != 0)
                                {
                                        if (_rtl8651_outboundL4DMZForward(pkthdrPtr, ip, pkthdrPtr->ph_sip) == 0)
                                                status = 0;
                                }
                                break;
                        case 50:
                                if(rtl8651_l4EspNaptAliasOut)
                                {
                                        ipaddr_t ip_s;
                                        ip_s = pkthdrPtr->ph_sip;

                                        status = (*rtl8651_l4EspNaptAliasOut)(pkthdrPtr, ip);
                                        if (status == 0)
                                        {
                                                if (!(((*(uint8*)ip)&0xf) == 5))
                                                {

                                                        do { do { int32 accumulate = 0; if ((((pkthdrPtr->ph_sip)) != 0) && (((ip_s)) != 0)){ accumulate = (((ip_s)) & 0xffff); accumulate += (( ((ip_s)) >> 16 ) & 0xffff); accumulate -= (((pkthdrPtr->ph_sip)) & 0xffff); accumulate -= (( ((pkthdrPtr->ph_sip)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((ip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                                                }
                                                if (((((uint16)(ip->ip_off)) & (0x1fff|0x2000)) == 0x2000))
                                                {
                                                        _rtl8651_updateFragCache(1, ip_s, pkthdrPtr->ph_dip, (ip->ip_id), pkthdrPtr->ph_sip, pkthdrPtr->ph_routeIdx, ((void *)0), pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid);
                                                }
                                                pkthdrPtr->ph_sip = ip_s;
                                        }
                                }else
                                {
                                        status = 51;
                                }
                                if (status != 0)
                                {
                                        if (_rtl8651_outboundL4DMZForward(pkthdrPtr, ip, pkthdrPtr->ph_sip) == 0)
                                                status = 0;
                                }
                                break;
                        case 46:

                                if(rtl8651_l4RsvpNaptAliasOut)
                                {
                                        ipaddr_t ip_s;
                                        ip_s = pkthdrPtr->ph_sip;

                                        status = (*rtl8651_l4RsvpNaptAliasOut)(pkthdrPtr, ip);
                                        if (status == 0)
                                        {
                                                if (!(((*(uint8*)ip)&0xf) == 5))
                                                {

                                                        do { do { int32 accumulate = 0; if ((((pkthdrPtr->ph_sip)) != 0) && (((ip_s)) != 0)){ accumulate = (((ip_s)) & 0xffff); accumulate += (( ((ip_s)) >> 16 ) & 0xffff); accumulate -= (((pkthdrPtr->ph_sip)) & 0xffff); accumulate -= (( ((pkthdrPtr->ph_sip)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((ip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                                                }
                                                if (((((uint16)(ip->ip_off)) & (0x1fff|0x2000)) == 0x2000))
                                                {
                                                        _rtl8651_updateFragCache(1, ip_s, pkthdrPtr->ph_dip, (ip->ip_id), pkthdrPtr->ph_sip, pkthdrPtr->ph_routeIdx, ((void *)0), pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid);
                                                }
                                                pkthdrPtr->ph_sip = ip_s;
                                        }
                                }else
                                {
                                        status = 51;
                                }
                                if (status != 0)
                                {
                                        if (_rtl8651_outboundL4DMZForward(pkthdrPtr, ip, pkthdrPtr->ph_sip) == 0)
                                                status = 0;
                                }
                                break;
                        default:
                                if (_rtl8651_outboundL4DMZForward(pkthdrPtr, ip, pkthdrPtr->ph_sip) == 0)
                                        status = 0;
                                else
                                status = 50;
                }

        }else
        {

                if( (((uint16)(ip->ip_off)) & 0x1fff) )
                {

                        uint32 org_ip;

                        ipaddr_t org_sip = ((uint32) (*((uint8*)(&ip->ip_src))<<24)|(*(((uint8*)(&ip->ip_src))+1)<<16)|(*(((uint8*)(&ip->ip_src))+2)<<8) | *(((uint8*)(&ip->ip_src))+3));
                        ipaddr_t org_dip = ((uint32) (*((uint8*)(&ip->ip_dst))<<24)|(*(((uint8*)(&ip->ip_dst))+1)<<16)|(*(((uint8*)(&ip->ip_dst))+2)<<8) | *(((uint8*)(&ip->ip_dst))+3));

                        if (_rtl8651_getFragCache(0, org_sip, org_dip, (ip->ip_id), &org_ip, &(pkthdrPtr->ph_routeIdx), ((void *)0), &(pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid)) == 0)
                        {
                                do{ *((uint8*)(&ip->ip_dst)) = (uint8)((org_ip)>>24); *(((uint8*)(&ip->ip_dst))+1) = (uint8)((org_ip)>>16); *(((uint8*)(&ip->ip_dst))+2) = (uint8)((org_ip)>>8); *(((uint8*)(&ip->ip_dst))+3) = (uint8)((org_ip)); }while(0);
                                if (!(((*(uint8*)ip)&0xf) == 5))
                                {
                                        do { do { int32 accumulate = 0; if ((((org_ip)) != 0) && (((pkthdrPtr->ph_dip)) != 0)){ accumulate = (((pkthdrPtr->ph_dip)) & 0xffff); accumulate += (( ((pkthdrPtr->ph_dip)) >> 16 ) & 0xffff); accumulate -= (((org_ip)) & 0xffff); accumulate -= (( ((org_ip)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((ip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                                }
                                return 0;
                        }
                        return 40;
                }
# 13138 "rtl8651_tblDrvFwd.c"
                switch (proto){
                case 6:
                        status = _rtl8651_l4TcpNaptAliasIn(pkthdrPtr, ip);
                        break;
                case 17:
                        status = _rtl8651_l4UdpNaptAliasIn(pkthdrPtr, ip);
                        break;
                case 1:
                        status = _rtl8651_L4IcmpNaptAliasIn(pkthdrPtr, ip);
                        break;
                case 47:
                        if(rtl8651_l4GreNaptAliasIn)
                        {
                                ipaddr_t ip_d;
                                ip_d = pkthdrPtr->ph_dip;

                                status = (*rtl8651_l4GreNaptAliasIn)(pkthdrPtr, ip);
                                if (status == 0)
                                {

                                        if (!(((*(uint8*)ip)&0xf) == 5))
                                        {

                                                do { do { int32 accumulate = 0; if ((((pkthdrPtr->ph_dip)) != 0) && (((ip_d)) != 0)){ accumulate = (((ip_d)) & 0xffff); accumulate += (( ((ip_d)) >> 16 ) & 0xffff); accumulate -= (((pkthdrPtr->ph_dip)) & 0xffff); accumulate -= (( ((pkthdrPtr->ph_dip)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((ip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                                        }
                                        if (((((uint16)(ip->ip_off)) & (0x1fff|0x2000)) == 0x2000))
                                        {
                                                _rtl8651_updateFragCache(0, pkthdrPtr->ph_sip, ip_d, (ip->ip_id), pkthdrPtr->ph_dip, 0, ((void *)0), pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid);
                                        }
                                }
                        }else
                        {
                                status = 51;
                        }
                        if (status != 0)
                        {
                                if (_rtl8651_inboundL4DMZForward(pkthdrPtr, ip, pkthdrPtr->ph_dip) == 0)
                                        status = 0;
                        }
                        break;
                case 50:
                        if(rtl8651_l4EspNaptAliasIn)
                        {
                                ipaddr_t ip_d;
                                ip_d = pkthdrPtr->ph_dip;

                                status = (*rtl8651_l4EspNaptAliasIn)(pkthdrPtr, ip);

                                if (status == 0)
                                {
                                        if (!(((*(uint8*)ip)&0xf) == 5))
                                        {

                                                do { do { int32 accumulate = 0; if ((((pkthdrPtr->ph_dip)) != 0) && (((ip_d)) != 0)){ accumulate = (((ip_d)) & 0xffff); accumulate += (( ((ip_d)) >> 16 ) & 0xffff); accumulate -= (((pkthdrPtr->ph_dip)) & 0xffff); accumulate -= (( ((pkthdrPtr->ph_dip)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((ip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                                        }
                                        if (((((uint16)(ip->ip_off)) & (0x1fff|0x2000)) == 0x2000))
                                        {
                                                _rtl8651_updateFragCache(0, pkthdrPtr->ph_sip, ip_d, (ip->ip_id), pkthdrPtr->ph_dip, 0, ((void *)0), pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid);
                                        }
                                }
                        }else
                        {
                                status = 51;
                        }
                        if (status != 0)
                        {
                                if (_rtl8651_inboundL4DMZForward(pkthdrPtr, ip, pkthdrPtr->ph_dip) == 0)
                                        status = 0;
                        }
                        break;
                case 46:

                        if(rtl8651_l4RsvpNaptAliasIn)
                        {
                                ipaddr_t ip_d;
                                ip_d = pkthdrPtr->ph_dip;

                                status = (*rtl8651_l4RsvpNaptAliasIn)(pkthdrPtr, ip);

                                if (status == 0)
                                {
                                        if (!(((*(uint8*)ip)&0xf) == 5))
                                        {

                                                do { do { int32 accumulate = 0; if ((((pkthdrPtr->ph_dip)) != 0) && (((ip_d)) != 0)){ accumulate = (((ip_d)) & 0xffff); accumulate += (( ((ip_d)) >> 16 ) & 0xffff); accumulate -= (((pkthdrPtr->ph_dip)) & 0xffff); accumulate -= (( ((pkthdrPtr->ph_dip)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((ip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                                        }
                                        if (((((uint16)(ip->ip_off)) & (0x1fff|0x2000)) == 0x2000))
                                        {
                                                _rtl8651_updateFragCache(0, pkthdrPtr->ph_sip, ip_d, (ip->ip_id), pkthdrPtr->ph_dip, 0, ((void *)0), pkthdrPtr->ph_un_sw.ROMEDRV_USG._ph_dsid);
                                        }
                                }
                        }else
                        {
                                status = 51;
                        }
                        if (status != 0)
                        {
                                if (_rtl8651_inboundL4DMZForward(pkthdrPtr, ip, pkthdrPtr->ph_dip) == 0)
                                        status = 0;
                        }
                        break;
                default:
                        if (_rtl8651_inboundL4DMZForward(pkthdrPtr, ip, pkthdrPtr->ph_dip) == 0)
                                status = 0;
                        else
                                status = 50;
                }

        }

        switch (status){
        case 0:

                if((ip->ip_off) & (0x2000| 0x1fff))
                {
                        pkthdrPtr->ph_proto = 2;
                }

                return 0;
        case 131:

                return 2;
        default:
                return status;
        }
}
# 13274 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4nat_in_process(struct rtl_pktHdr *phdr, struct ip *pip)
{

        ipaddr_t ip_d, ip_org = 0;
        rtl8651_tblDrv_natEntry_t *tb =((void *)0);
        int32 iresult = 0;


        ip_d = phdr->ph_dip;

        tb = _rtl8651_getNatExternalMappingEntry(ip_d,phdr);

        if(tb == ((void *)0) || tb->localIp == 0){
                return 1;
        }

        ip_org = tb->localIp;

        if ((pip->ip_off) & 0x1fff)
                goto change_ip;

        switch(pip->ip_p){
                case 6:




                                if ((_urlFilterAclRuleNum>=0) &&
                                        ((phdr->ph_reason&0xe)==4 && ((phdr->ph_reason&0xff0)>>5)==_urlFilterAclRuleNum))



                                {
                                        struct tcphdr *tc=(struct tcphdr *)((int8 *) pip + ((*(uint8*)pip&0xf) << 2));
                                        int32 hlen = ((pip->ip_vhl & 0xf) + (( tc->th_off_x >>4)&0xf)) << 2;

                                        if (((pip->ip_len))>hlen)
                                        {
                                                int32 position, len=64;
                                                int8 matched[64];
                                                position = _rtl8651_urlFilter(phdr->ph_un_sw.ROMEDRV_USG._ph_dsid,phdr,pip,1,matched,&len);
                                                if (position>0)
                                                {
# 13326 "rtl8651_tblDrvFwd.c"
                                                        return 101;
                                                }
                                        }
                                }


                        iresult = _rtl8651_l4TcpNatAlgAliasIn(phdr, pip, tb);
                        break;
                case 17:
                        iresult = _rtl8651_l4UdpNatAlgAliasIn(phdr, pip, tb);
                        break;
                case 1:
                        {
                                struct icmp *ic = (struct icmp *)((int8 *) pip + ((*(uint8*)pip&0xf) << 2));
                                struct ip *ip = &ic->icmp_dun.id_ip.idi_ip;

                                switch (ic->icmp_type)
                                {
                                        case 3:
                                        case 4:
                                        case 11:
                                        case 12:
                                                do{ *((uint8*)(&ip->ip_src)) = (uint8)((ip_org)>>24); *(((uint8*)(&ip->ip_src))+1) = (uint8)((ip_org)>>16); *(((uint8*)(&ip->ip_src))+2) = (uint8)((ip_org)>>8); *(((uint8*)(&ip->ip_src))+3) = (uint8)((ip_org)); }while(0);
                                                        do { do { int32 accumulate = 0; if ((((ip_org)) != 0) && (((tb->globalIp)) != 0)){ accumulate = (((tb->globalIp)) & 0xffff); accumulate += (( ((tb->globalIp)) >> 16 ) & 0xffff); accumulate -= (((ip_org)) & 0xffff); accumulate -= (( ((ip_org)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((ip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                                }
                        }

                default:

                        goto change_ip;
        }

        if(iresult ==114||
                iresult==85)
        {
change_ip:
                if (((pip->ip_vhl & 0x0f) != 5) || ((((pip->ip_off)) & (0x2000|0x1fff)) == 0x2000))
                {
                        struct tcphdr *tc;
                        struct udphdr *ud;

                        if ((pip->ip_vhl & 0x0f) != 5)
                        {
                                do { do { int32 accumulate = 0; if ((((ip_org)) != 0) && (((phdr->ph_dip)) != 0)){ accumulate = (((phdr->ph_dip)) & 0xffff); accumulate += (( ((phdr->ph_dip)) >> 16 ) & 0xffff); accumulate -= (((ip_org)) & 0xffff); accumulate -= (( ((ip_org)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                        }

                        if (((pip->ip_off)&0x1fff) == 0)
                        {
                                switch(pip->ip_p)
                                {
                                        case 6:
                                                tc = (struct tcphdr *) ((int8 *) pip + ((*(uint8*)pip&0xf) << 2));
                                                do { int32 accumulate = 0; if (((ip_org) != 0) && ((phdr->ph_dip) != 0)){ accumulate = ((phdr->ph_dip) & 0xffff); accumulate += (( (phdr->ph_dip) >> 16 ) & 0xffff); accumulate -= ((ip_org) & 0xffff); accumulate -= (( (ip_org) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += ((tc->th_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) accumulate); } } while (0); }while(0);
                                                break;
                                        case 17:
                                                ud = (struct udphdr *) ((int8 *) pip + ((*(uint8*)pip&0xf) << 2));
                                                if (ud->uh_sum)
                                                {
                                                        do { int32 accumulate = 0; if (((ip_org) != 0) && ((phdr->ph_dip) != 0)){ accumulate = ((phdr->ph_dip) & 0xffff); accumulate += (( (phdr->ph_dip) >> 16 ) & 0xffff); accumulate -= ((ip_org) & 0xffff); accumulate -= (( (ip_org) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += ((ud->uh_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) accumulate); } } while (0); }while(0);
                                                }
                                                break;
                                }
                        }
                }
                do{ *((uint8*)(&pip->ip_dst)) = (uint8)((ip_org)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((ip_org)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((ip_org)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((ip_org)); }while(0);
        } else if(iresult != 0)
        {
                printk("%s: errno=%d\n",__FUNCTION__, iresult);
                return iresult;
        }
# 13440 "rtl8651_tblDrvFwd.c"
        if((pip->ip_off) & (0x2000|0x1fff))
        {
                phdr->ph_proto = 2;
        }

        phdr->ph_routeIdx = 0;
        if(_rtl8651_l3ActRouting((struct rtl_pktHdr *)phdr,ip_org,pip) != 0){
                return 2;
        }
        return (0);

}
# 13463 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_l4nat_out_process(struct rtl_pktHdr *phdr, struct ip *pip)
{
        ipaddr_t ip_s, ip_d, ip_alias = 0;
        rtl8651_tblDrv_natEntry_t *tb;
        int32 iresult = 0;


        ip_s = phdr->ph_sip;
        ip_d = phdr->ph_dip;


        tb = _rtl8651_getNatInternalMappingEntry(ip_s,phdr);
# 13493 "rtl8651_tblDrvFwd.c"
        if(tb == ((void *)0) || tb->localIp == 0){
                return 53;
        }

        ip_alias = tb->globalIp;

        if ((pip->ip_off) & 0x1fff)
                goto change_ip;

        switch (pip->ip_p)
        {
                case 6:


                                if ((_urlFilterAclRuleNum>=0) &&
                                        ((phdr->ph_reason&0xe)==4 && ((phdr->ph_reason&0xff0)>>5)==_urlFilterAclRuleNum))



                                {
                                        struct tcphdr *tc=(struct tcphdr *)((int8 *) pip + ((*(uint8*)pip&0xf) << 2));
                                        int32 hlen = ((pip->ip_vhl & 0xf) + (( tc->th_off_x >>4)&0xf)) << 2;

                                        if (((pip->ip_len))>hlen)
                                        {
                                                int32 position, len=64;
                                                int8 matched[64];

                                                position = _rtl8651_urlFilter(phdr->ph_un_sw.ROMEDRV_USG._ph_dsid,phdr,pip,0,matched, &len);

                                                if (position>0)
                                                {
# 13534 "rtl8651_tblDrvFwd.c"
                                                        return 101;
                                                }
                                        }
                                }

                        iresult = _rtl8651_l4TcpNatAlgAliasOut(phdr, pip, tb);
                        break;
                case 17:
                        iresult = _rtl8651_l4UdpNatAlgAliasOut(phdr, pip, tb);
                        break;
                case 1:
                        {
                                struct icmp *ic = (struct icmp *)((int8 *) pip + ((*(uint8*)pip&0xf) << 2));
                                struct ip *ip = &ic->icmp_dun.id_ip.idi_ip;

                                switch (ic->icmp_type)
                                {
                                        case 3:
                                        case 4:
                                        case 11:
                                        case 12:
                                                do{ *((uint8*)(&ip->ip_dst)) = (uint8)((ip_alias)>>24); *(((uint8*)(&ip->ip_dst))+1) = (uint8)((ip_alias)>>16); *(((uint8*)(&ip->ip_dst))+2) = (uint8)((ip_alias)>>8); *(((uint8*)(&ip->ip_dst))+3) = (uint8)((ip_alias)); }while(0);
                                                do { do { int32 accumulate = 0; if ((((ip_alias)) != 0) && (((tb->localIp)) != 0)){ accumulate = (((tb->localIp)) & 0xffff); accumulate += (( ((tb->localIp)) >> 16 ) & 0xffff); accumulate -= (((ip_alias)) & 0xffff); accumulate -= (( ((ip_alias)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((ip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((ip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                                }
                        }

                default:

                        goto change_ip;
        }

        if( (iresult == 117) ||
                (iresult == 88 ))
        {
change_ip:
                if ((((pip->ip_off) & (0x2000|0x1fff)) == 0x2000) ||((pip->ip_vhl & 0x0f) != 5))
                {
                        struct tcphdr *tc;
                        struct udphdr *ud;

                        if ((pip->ip_vhl & 0x0f) != 5)
                        {
                                do { do { int32 accumulate = 0; if ((((ip_alias)) != 0) && (((phdr->ph_sip)) != 0)){ accumulate = (((phdr->ph_sip)) & 0xffff); accumulate += (( ((phdr->ph_sip)) >> 16 ) & 0xffff); accumulate -= (((ip_alias)) & 0xffff); accumulate -= (( ((ip_alias)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                        }

                        if (((pip->ip_off) & 0x1fff) == 0)
                        {
                                switch(pip->ip_p)
                                {
                                        case 6:
                                                tc = (struct tcphdr *) ((int8 *) pip + ((*(uint8*)pip&0xf) << 2));
                                                do { int32 accumulate = 0; if (((ip_alias) != 0) && ((phdr->ph_sip) != 0)){ accumulate = ((phdr->ph_sip) & 0xffff); accumulate += (( (phdr->ph_sip) >> 16 ) & 0xffff); accumulate -= ((ip_alias) & 0xffff); accumulate -= (( (ip_alias) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += ((tc->th_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) accumulate); } } while (0); }while(0);
                                                break;
                                        case 17:
                                                ud = (struct udphdr *) ((int8 *) pip + ((*(uint8*)pip&0xf) << 2));
                                                if (ud->uh_sum)
                                                {
                                                        do { int32 accumulate = 0; if (((ip_alias) != 0) && ((phdr->ph_sip) != 0)){ accumulate = ((phdr->ph_sip) & 0xffff); accumulate += (( (phdr->ph_sip) >> 16 ) & 0xffff); accumulate -= ((ip_alias) & 0xffff); accumulate -= (( (ip_alias) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += ((ud->uh_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) accumulate); } } while (0); }while(0);
                                                }
                                                break;
                                }
                        }
                }
                do{ *((uint8*)(&pip->ip_src)) = (uint8)((ip_alias)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((ip_alias)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((ip_alias)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((ip_alias)); }while(0);

        } else if (iresult != 0)
        {
                printk("%s: errno=%d\n",__FUNCTION__, iresult);
                return iresult;
        }
# 13670 "rtl8651_tblDrvFwd.c"
        if((pip->ip_off) & (0x2000|0x1fff))
        {
                phdr->ph_flags &= (~0x0001);
                phdr->ph_proto = 2;
        }

        if(_rtl8651_l3ActRouting((struct rtl_pktHdr *)phdr,ip_d,pip) != 0)
        {
                return 2;
        }
        return (0);
}




static void _rtl8651_l34AdditionalExec_init(void)
{
        memset(_RTL8651_ADDITIONAL_PROC, 0, sizeof(_RTL8651_ADDITIONAL_PROC));


        _RTL8651_ADDITIONAL_PROC[_RTL8651_DEC_NPT] = 0x02;
        _RTL8651_ADDITIONAL_PROC[_RTL8651_DEC_NT] = 0x02;
        _RTL8651_ADDITIONAL_PROC[_RTL8651_DEC_RT_LR] = 0x02;


}


static inline int32 _rtl8651_l34AddtionalExec(int32 decision, ipaddr_t dip, void *pkt)
{
        int32 retval = 0;

        if ((((decision) > _RTL8651_DEC_NONE) && ((decision) < _RTL8651_DEC_MAX)))
        {


                if (_RTL8651_ADDITIONAL_PROC[decision] & 0x01)
                {
                        retval = 137;
                        goto exception_check;
                }


                if (_RTL8651_ADDITIONAL_PROC[decision] & 0x02)
                {
                        uint8 *ether = (uint8 *)pkt;
                        do {} while (0);

                        if (_rtl8651_isMacAccessControlPermit((ether_addr_t *)&ether[6]) == 0)
                        {
                                retval = 19;
                                goto exception_check;
                        }

                }
        }else do {} while (0);


        return 0;

exception_check:


        {
                int8 is_gwip;
                _rtl8651_getIpInfo(dip, ((void *)0), ((void *)0), &is_gwip);
                if (is_gwip == 1)
                {
                        return 132;
                }
        }

        return retval;
}


int32 _rtl8651_l34AdditionalExec_setParam(uint32 srcType, uint32 dstType, _rtl8651_l34AdditionalExec_t *para)
{
        int32 decision;

        if ((!(((srcType) >= _RTL8651_HOST_NPI) && ((srcType) < _RTL8651_HOST_MAX))) ||(!(((dstType) >= _RTL8651_HOST_NPI) && ((dstType) < _RTL8651_HOST_MAX))))
        {
                return -1;
        }

        decision = _RTL8651_PROC[srcType][dstType];

        do {} while (0);


        if ((decision == _RTL8651_DEC_NPT) || (decision == _RTL8651_DEC_NT) || (decision == _RTL8651_DEC_RT_LR))
        {
                if ((para->property & 0x02) == 0)
                {



                        return -1;
                }
        }


        _RTL8651_ADDITIONAL_PROC[decision] = para->property;

        return 0;
}

int32 _rtl8651_l34AdditionalExec_getParam(uint32 srcType, uint32 dstType, _rtl8651_l34AdditionalExec_t *para)
{
        int32 decision;

        if ((!(((srcType) >= _RTL8651_HOST_NPI) && ((srcType) < _RTL8651_HOST_MAX))) ||(!(((dstType) >= _RTL8651_HOST_NPI) && ((dstType) < _RTL8651_HOST_MAX))))
        {
                return -1;
        }

        decision = _RTL8651_PROC[srcType][dstType];

        do {} while (0);


        memset(para, 0, sizeof(_rtl8651_l34AdditionalExec_t));
        para->property = _RTL8651_ADDITIONAL_PROC[decision];

        return 0;
}
# 13810 "rtl8651_tblDrvFwd.c"
uint16
_rtl8651_ipChecksum(struct ip * pip)
{


        uint32 sum=0,oddbyte=0;
        uint16 *ptr = (uint16 *)pip;
        uint32 nbytes = ((pip->ip_vhl & 0xf) << 2);

        while (nbytes > 1)
        {

                sum += (*ptr++);
                nbytes -= 2;
        }
        if (nbytes == 1)
        {



                oddbyte = (*ptr & 0xff00);
                sum += oddbyte;
        }

        sum = (sum >> 16) + (sum & 0xffff);
        sum += (sum >> 16);

        return (~sum);


}
# 13853 "rtl8651_tblDrvFwd.c"
uint16 _rtl8651_tcpChecksum(struct ip *pip)
{
        int32 sum, nbytes, nhdr, i;
        uint16 *sip, *dip, *ptr;

        nhdr = ((pip->ip_vhl & 0xf) << 2);
        nbytes = (pip->ip_len) - nhdr;
        ptr = (uint16 *) ((char *) pip + nhdr);
        sum = 0;


        *(((uint8 *)pip) + nhdr + nbytes) = (uint8)0;
        for (i=0; i<nbytes ;i=i+2){
                sum += (unsigned long)*ptr++;
        }


        dip=(uint16 *)&pip->ip_dst;
        sum += *dip; dip++;
        sum += *dip;
        sip=(uint16 *)&pip->ip_src;
        sum += *sip; sip++;
        sum += *sip;

        sum += nbytes;
        sum += ((uint16) pip->ip_p);


        while (sum>>16)
                sum = (sum & 0xFFFF)+(sum >> 16);


        sum = ~sum;
        return (uint16)sum;

}
# 13990 "rtl8651_tblDrvFwd.c"
uint16
_rtl8651_icmpChecksum(struct ip * pip)
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






static void _rtl8651_initUpnpDb(void){
        upnp_tb = (struct _RTL8651_UPNP_ENTRY *)rtlglue_malloc(60 * sizeof (struct _RTL8651_UPNP_ENTRY));
        memset(upnp_tb,0,60 * sizeof (struct _RTL8651_UPNP_ENTRY));
}

static void _rtl8651_ReinitUpnpDb(void){
        memset(upnp_tb,0,60 * sizeof (struct _RTL8651_UPNP_ENTRY));
}
# 14045 "rtl8651_tblDrvFwd.c"
void rtl8651_addUpnpMap(uint32 inFlags,
        ipaddr_t remote_ip, uint16 remote_port,
        ipaddr_t alias_ip, uint16 alias_port,
        ipaddr_t local_ip, uint16 local_port){
        int32 ii;
        struct _RTL8651_UPNP_ENTRY *tb;

        rtlglue_drvMutexLock();

        tb = upnp_tb;

        for (ii = 0 ; ii < 60 ; ii++, tb++){
                if( (tb->flags & 0x01) == 0 || ((tb->alias_port == alias_port)&&((tb->flags&0x02) == (inFlags&0x02)))){

                        tb->remote_ip = remote_ip;
                        tb->remote_port = remote_port;
                        tb->alias_ip = alias_ip;
                        tb->alias_port = alias_port ;
                        tb->local_ip = local_ip;
                        tb->local_port = local_port;
                        tb->algIdx = 0;

                        tb->flags = 0x01;
                        tb->flags |= inFlags;

                        tb->age = 120;

                        break;
                }
        }

        rtlglue_drvMutexUnlock();

}

void _rtl8651_addAlgQosUpnpMap(uint32 inFlags,
        ipaddr_t remote_ip, uint16 remote_port,
        ipaddr_t alias_ip, uint16 alias_port,
        ipaddr_t local_ip, uint16 local_port,uint32 algIdx){

        int32 ii;
        struct _RTL8651_UPNP_ENTRY *tb;

        rtlglue_drvMutexLock();

        tb = upnp_tb;

        for (ii = 0 ; ii < 60 ; ii++, tb++){
                if( (tb->flags & 0x01) == 0 || ((tb->alias_port == alias_port)&&((tb->flags&0x02) == (inFlags&0x02)))){

                        tb->remote_ip = remote_ip;
                        tb->remote_port = remote_port;
                        tb->alias_ip = alias_ip;
                        tb->alias_port = alias_port ;
                        tb->local_ip = local_ip;
                        tb->local_port = local_port;
                        tb->algIdx = algIdx;
                        tb->flags = 0x01;
                        tb->flags |= inFlags;
                        tb->age = 120;

                        break;
                }
        }

        rtlglue_drvMutexUnlock();
}

void rtl8651_addUpnpMapLeaseTime(uint32 inFlags,
        ipaddr_t remote_ip, uint16 remote_port,
        ipaddr_t alias_ip, uint16 alias_port,
        ipaddr_t local_ip, uint16 local_port,uint32 age){
        int32 ii;
        struct _RTL8651_UPNP_ENTRY *tb;

        rtlglue_drvMutexLock();

        tb = upnp_tb;

        for (ii = 0 ; ii < 60 ; ii++, tb++){
                if( (tb->flags & 0x01) == 0 || ((tb->alias_port == alias_port)&&((tb->flags&0x02) == (inFlags&0x02)))){

                        tb->remote_ip = remote_ip;
                        tb->remote_port = remote_port;
                        tb->alias_ip = alias_ip;
                        tb->alias_port = alias_port ;
                        tb->local_ip = local_ip;
                        tb->local_port = local_port;
                        tb->algIdx = 0;

                        tb->flags = 0x01;
                        tb->flags |= inFlags;

                        if(age==0)
                                tb->age = 120;
                        else
                                tb->age = age;

                        break;
                }
        }

        rtlglue_drvMutexUnlock();

}
# 14165 "rtl8651_tblDrvFwd.c"
void rtl8651_delUpnpMap(uint32 isTcp, ipaddr_t remote_ip, uint16 remote_port,
        ipaddr_t alias_ip, uint16 alias_port,
        ipaddr_t local_ip, uint16 local_port){
        int32 ii;
        struct _RTL8651_UPNP_ENTRY *tb;

        rtlglue_drvMutexLock();

        tb = upnp_tb;

        for (ii = 0 ; ii < 60 ; ii++, tb++){
                if( tb->flags & 0x01 ){

                        if( (tb->remote_ip & remote_ip) == remote_ip &&
                                (tb->remote_port & remote_port)== remote_port &&
                                tb->alias_ip == alias_ip &&
                                tb->alias_port == alias_port &&
                                ((tb->local_ip == local_ip && tb->local_port == local_port) ||
                                (tb->local_ip == local_ip && tb->local_port == 0) ||
                                (tb->local_ip == 0 && tb->local_port == local_port) ||
                                (tb->local_ip == 0 && tb->local_port == 0))
                                ){

                                if(isTcp == 0){
                                        if(tb->flags & 0x02)
                                                continue;
                                }

                                tb->flags = 0;
                        }
                }
        }

        rtlglue_drvMutexUnlock();

}


static inline int32 _rtl8651_findInboundUpnpMapping (
        uint32 isTcp,
        ipaddr_t remote_ip, uint16 remote_port,
        ipaddr_t alias_ip, uint16 alias_port,
        ipaddr_t *local_ip, uint16 *local_port,
        uint32 *flags, uint32 *algIdx)
{
        int32 ii;
        struct _RTL8651_UPNP_ENTRY *tb = upnp_tb;
        for (ii = 0 ; ii < 60 ; ii++, tb++){
                if( tb->flags & 0x01 ){
                        if( (tb->remote_ip & remote_ip) == tb->remote_ip &&
                                (tb->remote_port & remote_port)== tb->remote_port &&
                                tb->alias_ip == alias_ip &&
                                tb->alias_port == alias_port ){

                                if ((isTcp && (!(tb->flags&0x02))) ||
                                                ((!isTcp) && (tb->flags&0x02)))
                                        continue;

                                if(tb->flags & 0x04)
                                {
                                        tb->flags = 0;
                                }


                                if(remote_port==20)
                                        return -1;

                                do {} while (0);

                                if (local_ip) *local_ip = tb->local_ip;
                                if (local_port) *local_port = tb->local_port;
                                if (flags) *flags = tb->flags;
                                if (algIdx) *algIdx = tb->algIdx;

                                return 0;
                        }
                }
        }

        return -1;
}
# 14255 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_findOutboundUpnpMapping (
        uint32 isTcp,
        ipaddr_t IntIp, uint16 IntPort,
        ipaddr_t *ExtIp, uint16 *ExtPort,
        ipaddr_t RemoteIp, uint16 RemotePort,
        uint32 *flags, uint32 *algIdx)
{
        struct _RTL8651_UPNP_ENTRY *upnp_t = upnp_tb;
        int32 idx;




        for (idx = 0 ; idx < 60 ; idx++, upnp_t++)
        {

                if ((upnp_t->flags & 0x01) == 0)
                        continue;


                if ( (isTcp && ((upnp_t->flags & 0x02) == 0)) ||
                        ((isTcp == 0) && ((upnp_t->flags & 0x02) == 0x02))
                   )
                        continue;


                if ( (upnp_t->remote_port && (upnp_t->remote_port != RemotePort)) ||
                        (upnp_t->remote_ip && (upnp_t->remote_ip != RemoteIp)) ||
                        (upnp_t->local_port != IntPort) ||
                        (upnp_t->local_ip != IntIp)
                   )
                        continue;


                if (upnp_t->flags & 0x04)
                {
                        upnp_t->flags = 0;
                }






                if(RemotePort == 20)
                {
                        return -1;
                }

                do {} while (0);




                if (ExtIp) *ExtIp = upnp_t->alias_ip;
                if (ExtPort) *ExtPort = upnp_t->alias_port;
                if (flags) *flags = upnp_t->flags;
                if (algIdx) *algIdx = upnp_t->algIdx;

                return 0;
        }

        return -1;
}

uint32 rtl8651_queryUpnpMapTimeAge(uint32 isTcp, ipaddr_t remote_ip, uint16 remote_port,
        ipaddr_t alias_ip, uint16 alias_port){

        int32 ii;
        struct _RTL8651_UPNP_ENTRY *tb;
        uint32 retval = 0;

        rtlglue_drvMutexLock();

        tb = upnp_tb;

        for (ii = 0 ; ii < 60 ; ii++, tb++){
                if( tb->flags & 0x01 ){
                        if( (tb->remote_ip & remote_ip) == tb->remote_ip &&
                                (tb->remote_port & remote_port)== tb->remote_port &&
                                tb->alias_ip == alias_ip &&
                                tb->alias_port == alias_port ){

                                if ((isTcp && (!(tb->flags&0x02))) ||
                                                ((!isTcp) && (tb->flags&0x02)))
                                        continue;

                                retval = tb->age;
                                goto out;
                        }
                }
        }

out:
        rtlglue_drvMutexUnlock();

        return retval;
}




static inline int32 _rtl8651_checkUsableUpnpEntry(uint32 isTcp, ipaddr_t IntIp, uint32 IntPort, ipaddr_t ExtIp, uint32 ExtPort, ipaddr_t RemoteIp, uint32 RemotePort)
{
        int32 i;
        struct _RTL8651_UPNP_ENTRY *tb = upnp_tb, *candidate = ((void *)0);

        for (i = 0 ; i < 60 ; i ++ , tb ++)
        {
                if ((tb->flags&0x01) &&
                        (tb->alias_ip == ExtIp) &&
                        (tb->alias_port == ExtPort) &&
                        (tb->remote_ip == 0 || tb->remote_ip == RemoteIp) &&
                        (tb->remote_port == 0 || tb->remote_port == RemotePort) &&
                        ((isTcp&&(tb->flags&0x02)) ||((!isTcp)&&(!(tb->flags&0x02))))
                        )
                {
                        if ((IntIp == tb->local_ip) && (IntPort == tb->local_port))
                        {
                                return 1;
                        }

                        candidate = tb;
                }
        }




        if (candidate)
                return 0;


        return 1;
}

static int32 _rtl8651_uPnPOneSecondTimer(){

        int32 ii;
        struct _RTL8651_UPNP_ENTRY *tb = upnp_tb;
        for (ii = 0 ; ii < 60 ; ii++, tb++){

                if( (tb->flags & (0x08|0x01)) ==
                        (0x08|0x01)){
                        continue;
                }

                if( tb->flags & 0x01 ){
                        tb->age--;
                        if(tb->age == 0){
                                tb->flags &= (~0x01);
                        }
                }
        }

        return 0;
}
# 14425 "rtl8651_tblDrvFwd.c"
void rtl8651a_setUdpSizeThreshValue(uint32 SessionID, uint32 value)
{
        uint32 dsid;
        uint32 idx;

        rtlglue_drvMutexLock();

        dsid=_rtl8651_SessionIDToDSID(SessionID);

        _rtl8651_udpSizeThreshValue[dsid]=(uint16)value;

        _rtl8651_udpBlockingEnable = 0;

        for (idx = 0 ; idx < rtl8651_tblDrvPara.dialSessionNumber ; idx ++)
        {
                if (_rtl8651_udpSizeThreshValue[idx] != 0xffff)
                        _rtl8651_udpBlockingEnable = 1;
        }

        rtlglue_drvMutexUnlock();
}
# 14458 "rtl8651_tblDrvFwd.c"
void rtl8651a_setWanStatus(uint32 SessionID, uint32 Status)
{
        uint32 dsid;
        rtlglue_drvMutexLock();
        dsid=_rtl8651_SessionIDToDSID(SessionID);
        rtl8651_wanStatus[dsid]=Status;
        rtlglue_drvMutexUnlock();
}
# 14475 "rtl8651_tblDrvFwd.c"
void rtl8651_setWanStatus(uint32 Status)
{
        rtlglue_drvMutexLock();
        rtl8651_wanStatus[0]=Status;
        rtlglue_drvMutexUnlock();
}





static int32 _rtl8651_protoStackActionInit(rtl8651_fwdEngineInitPara_t *para){

        rtl8651_ProtoStackActions = (rtl8651_PS_Action_Entry_t *)rtlglue_malloc(para->protoStackMaxActions * sizeof (rtl8651_PS_Action_Entry_t));
        memset(rtl8651_ProtoStackActions,0,para->protoStackMaxActions * sizeof (rtl8651_PS_Action_Entry_t));
        return 0;
}
# 14500 "rtl8651_tblDrvFwd.c"
void rtl8651_flushProtoStackActions(void)
{
        rtlglue_drvMutexLock();
        memset(rtl8651_ProtoStackActions,0,sizeof(rtl8651_PS_Action_Entry_t)*rtl8651_fwdEnginePara.protoStackMaxActions);
        rtlglue_drvMutexUnlock();
}

int32 _rtl8651_delProtocolStackActions(rtl8651_PS_Action_Entry_t *PSA)
{
        int i;
        rtl8651_PS_Action_Entry_t *psa_t = rtl8651_ProtoStackActions;


        if (PSA->dstIp != 0 && _rtl8651_extIpAddr(PSA->dstIp, ((void *)0)) == 0)
                return 1005;


        for (i = 0; i < rtl8651_fwdEnginePara.protoStackMaxActions; i++, psa_t++)
        {
                if (psa_t->action == 0)
                        continue;

                if (!memcmp(PSA, psa_t, sizeof(rtl8651_PS_Action_Entry_t)))
                {

                        memset(psa_t, 0, sizeof(rtl8651_PS_Action_Entry_t));
                        return 0;
                }
        }
        return 1007;
}

int32 _rtl8651_addProtocolStackActions(rtl8651_PS_Action_Entry_t *PSA)
{
        int i;
        rtl8651_PS_Action_Entry_t *empty_psa_t = ((void *)0);
        rtl8651_PS_Action_Entry_t *psa_t = rtl8651_ProtoStackActions;


        if (PSA->dstIp != 0 && _rtl8651_extIpAddr(PSA->dstIp, ((void *)0)) == 0)
                return 1005;;

        for(i = 0; i < rtl8651_fwdEnginePara.protoStackMaxActions; i++, psa_t++)
        {

                if (psa_t->action != 0) {
                        if ((PSA->dstIp == 0 || psa_t->dstIp == 0 || PSA->dstIp == psa_t->dstIp)
                                && PSA->role == psa_t->role && PSA->protocol == psa_t->protocol) {



                                if (!((PSA->upperIp < psa_t->lowerIp) || (PSA->lowerIp > psa_t->upperIp))) {




                                        if (!((PSA->orgPortEnd < psa_t->orgPort) ||(PSA->orgPort > psa_t->orgPortEnd)))
                                                return 1000;
                                        else {
                                                uint16 user_portRange = PSA->orgPortEnd - PSA->orgPort;
                                                uint16 tb_portRange = psa_t->orgPortEnd - psa_t->orgPort;


                                                if (!(((PSA->fwdPort + user_portRange) < psa_t->fwdPort) || (PSA->fwdPort > (psa_t->fwdPort + tb_portRange))))
                                                        return 1000;
                                        }
                                }
                        }
                }
                else if (empty_psa_t == ((void *)0))
                        empty_psa_t = psa_t;
        }


        if (empty_psa_t != ((void *)0))
        {
                empty_psa_t->dstIp = PSA->dstIp;
                empty_psa_t->action = PSA->action;
                empty_psa_t->lowerIp = PSA->lowerIp;
                empty_psa_t->upperIp = PSA->upperIp;
                empty_psa_t->role = PSA->role;
                empty_psa_t->protocol = PSA->protocol;
                empty_psa_t->orgPort = PSA->orgPort;
                empty_psa_t->orgPortEnd = PSA->orgPortEnd;
                empty_psa_t->fwdPort = PSA->fwdPort;
                return 0;
        }
        else
                return 1001;

}


int32 _rtl8651_checkPSAction(rtl8651_PS_Action_Entry_t *PSAction)
{
        if (!(PSAction->action == 1 || PSAction->action == 2 || PSAction->action == 3))
                return 1008;
        if (!(PSAction->role == 0 || PSAction->role == 1))
                return 1009;
        if (PSAction->lowerIp > PSAction->upperIp)
                return 1002;
        if (PSAction->protocol == 1 && ((PSAction->role != 0) || (PSAction->orgPort != 0) || (PSAction->orgPortEnd != 0) || (PSAction->fwdPort != 0)))
                return 1003;
        if (PSAction->orgPort > PSAction->orgPortEnd)
                return 1004;
        if ((PSAction->orgPortEnd - PSAction->orgPort) > (65535 - PSAction->fwdPort))
                return 1006;

        return 0;
}
# 14631 "rtl8651_tblDrvFwd.c"
int32 rtl8651_addGenericProtoStackActions(rtl8651_PS_Action_Entry_t *PSAction)
{
        int32 retval;


        if ((retval = _rtl8651_checkPSAction(PSAction)) != 0)
                return retval;

        rtlglue_drvMutexLock();
        retval = _rtl8651_addProtocolStackActions(PSAction);
        rtlglue_drvMutexUnlock();

        return retval;
}
# 14665 "rtl8651_tblDrvFwd.c"
int32 rtl8651_delGenericProtoStackActions(rtl8651_PS_Action_Entry_t *PSAction)
{
        int32 retval;


        if ((retval = _rtl8651_checkPSAction(PSAction)) != 0)
                return retval;

        rtlglue_drvMutexLock();
        retval = _rtl8651_delProtocolStackActions(PSAction);
        rtlglue_drvMutexUnlock();

        return retval;
}
# 14705 "rtl8651_tblDrvFwd.c"
int32 rtl8651_addProtoStackActions(ipaddr_t lowerIp, ipaddr_t upperIp, uint8 action, uint8 role, uint8 protocol, uint16 orgPort, uint16 fwdPort)
{
        int32 retval;
        rtl8651_PS_Action_Entry_t PSAction;

        memset(&PSAction, 0, sizeof(rtl8651_PS_Action_Entry_t));

        PSAction.lowerIp = lowerIp;
        PSAction.upperIp = upperIp;
        PSAction.action = action;
        PSAction.role = role;
        PSAction.protocol = protocol;
        PSAction.orgPort = orgPort;
        PSAction.orgPortEnd = orgPort;
        PSAction.fwdPort = fwdPort;
        PSAction.dstIp = 0;


        if ((retval = _rtl8651_checkPSAction(&PSAction)) != 0)
                return retval;

        rtlglue_drvMutexLock();
        retval = _rtl8651_addProtocolStackActions(&PSAction);
        rtlglue_drvMutexUnlock();

        return retval;
}
# 14741 "rtl8651_tblDrvFwd.c"
int32 rtl8651_delProtoStackActions(ipaddr_t lowerIp, ipaddr_t upperIp, uint8 action, uint8 role, uint8 protocol, uint16 orgPort, uint16 fwdPort)
{
        int32 retval;
        rtl8651_PS_Action_Entry_t PSAction;

        memset(&PSAction, 0, sizeof(rtl8651_PS_Action_Entry_t));

        PSAction.lowerIp = lowerIp;
        PSAction.upperIp = upperIp;
        PSAction.action = action;
        PSAction.role = role;
        PSAction.protocol = protocol;
        PSAction.orgPort = orgPort;
        PSAction.orgPortEnd = orgPort;
        PSAction.fwdPort = fwdPort;
        PSAction.dstIp = 0;


        if ((retval = _rtl8651_checkPSAction(&PSAction)) != 0)
                return retval;

        rtlglue_drvMutexLock();
        retval = _rtl8651_delProtocolStackActions(&PSAction);
        rtlglue_drvMutexUnlock();

        return retval;
}

int32 rtl8651_addProtoStackServerPortRange(ipaddr_t lowerIp, ipaddr_t upperIp, uint8 protocol, uint16 PortStart, uint16 PortEnd, uint16 fwdPortStart)
{
        int32 retval;
        rtl8651_PS_Action_Entry_t PSAction;

        memset(&PSAction, 0, sizeof(rtl8651_PS_Action_Entry_t));

        PSAction.lowerIp = lowerIp;
        PSAction.upperIp = upperIp;
        PSAction.action = 2;
        PSAction.role = 0;
        PSAction.protocol = protocol;
        PSAction.orgPort = PortStart;
        PSAction.orgPortEnd = PortEnd;
        PSAction.fwdPort = fwdPortStart;
        PSAction.dstIp = 0;


        if ((retval = _rtl8651_checkPSAction(&PSAction)) != 0)
                return retval;

        rtlglue_drvMutexLock();
        retval = _rtl8651_addProtocolStackActions(&PSAction);
        rtlglue_drvMutexUnlock();

        return retval;
}

int32 rtl8651_delProtoStackServerPortRange(ipaddr_t lowerIp, ipaddr_t upperIp, uint8 protocol, uint16 PortStart, uint16 PortEnd, uint16 fwdPortStart)
{
        int32 retval;
        rtl8651_PS_Action_Entry_t PSAction;

        memset(&PSAction, 0, sizeof(rtl8651_PS_Action_Entry_t));

        PSAction.lowerIp = lowerIp;
        PSAction.upperIp = upperIp;
        PSAction.action = 2;
        PSAction.role = 0;
        PSAction.protocol = protocol;
        PSAction.orgPort = PortStart;
        PSAction.orgPortEnd = PortEnd;
        PSAction.fwdPort = fwdPortStart;
        PSAction.dstIp = 0;


        if ((retval = _rtl8651_checkPSAction(&PSAction)) != 0)
                return retval;

        rtlglue_drvMutexLock();
        retval = _rtl8651_delProtocolStackActions(&PSAction);
        rtlglue_drvMutexUnlock();

        return retval;
}

static int32 _rtl8651_doProtoStackAction(struct rtl_pktHdr *pktHdr, struct ip *iph)
{
        int i;
        ipaddr_t sip = ((uint32) (*((uint8*)(&iph->ip_src))<<24)|(*(((uint8*)(&iph->ip_src))+1)<<16)|(*(((uint8*)(&iph->ip_src))+2)<<8) | *(((uint8*)(&iph->ip_src))+3));
        ipaddr_t dip = ((uint32) (*((uint8*)(&iph->ip_dst))<<24)|(*(((uint8*)(&iph->ip_dst))+1)<<16)|(*(((uint8*)(&iph->ip_dst))+2)<<8) | *(((uint8*)(&iph->ip_dst))+3));
        uint16 *sport = ((void *)0), *dport = ((void *)0), *chksum = ((void *)0);
        rtl8651_PS_Action_Entry_t *psa = rtl8651_ProtoStackActions;


        int32 retval = 0;


        if (pktHdr->ph_un_sw.ROMEDRV_USG._ph_procFlag & (1<<0))
        {
                return retval;
        }





        if (_rtl8651_extIpAddr(dip, ((void *)0)) == 0)
                return retval;


        if ((((uint16)(iph->ip_off)) & 0x1fff))
        {
                ipaddr_t returnValue;

                if (_rtl8651_getFragCache(4, sip, dip, (iph->ip_id), &returnValue, ((void *)0), ((void *)0), ((void *)0)) == 0)
                        return (int32)returnValue;
                return retval;
        }


        switch (iph->ip_p)
        {
                case 6:
                {
                        struct tcphdr *tcp;
                        tcp = (struct tcphdr *) ((int8 *) iph + ((iph->ip_vhl &0xf) << 2));
                        sport = &tcp->th_sport;
                        dport = &tcp->th_dport;
                        chksum = &tcp->th_sum;
                        break;
                }

                case 17:
                {
                        struct udphdr *udp;
                        udp = (struct udphdr *) ((int8 *) iph + ((iph->ip_vhl &0xf) << 2));
                        sport = &udp->uh_sport;
                        dport = &udp->uh_dport;
                        chksum = &udp->uh_sum;
                        break;
                }
        }


        for (i = 0; i < rtl8651_fwdEnginePara.protoStackMaxActions; i++, psa++)
        {
                if (psa->action == 0)
                        continue;

                if ((psa->dstIp == 0 || dip == psa->dstIp) && iph->ip_p == psa->protocol)
                {

                        if (psa->protocol == 6 || psa->protocol == 17)
                        {
                                uint16 *chkport = ((void *)0);

                                if (psa->role == 0)
                                        chkport = dport;
                                else if (psa->role == 1)
                                        chkport = sport;






                                if ((psa->orgPort <= (*chkport)) && (psa->orgPortEnd >= (*chkport)))
                                {
                                        if ((sip >= psa->lowerIp) && (sip <= psa->upperIp))
                                        {
                                                if (psa->action == 2)
                                                {
                                                        if (psa->orgPort != psa->fwdPort)
                                                        {
                                                                uint16 newFwdPort = psa->fwdPort + ((*chkport) - psa->orgPort);

                                                                if ((iph->ip_p != 17) || (*chksum != 0))
                                                                {
                                                                        do { int32 accumulate = 0; if (((0) != 0) && ((0) != 0)){ accumulate = ((0) & 0xffff); accumulate += (( (0) >> 16 ) & 0xffff); accumulate -= ((0) & 0xffff); accumulate -= (( (0) >> 16 ) & 0xffff); } if (((newFwdPort) != 0) && (((*chkport)) != 0)){ accumulate += ((*chkport)); accumulate -= (newFwdPort); } do { accumulate += ((*chksum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (*chksum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (*chksum) = ((uint16) accumulate); } } while (0); }while(0);
                                                                }
                                                                *chkport = (newFwdPort);
                                                        }
                                                }
                                                retval = psa->action;
                                                goto out;
                                        }
                                        else
                                                retval = 1;
                                }
                        }
                        else if(psa->protocol == 1)
                        {
                                struct icmp *im;
                                im = (struct icmp *) ((int8 *) iph + ((iph->ip_vhl &0xf) << 2));

                                if (im->icmp_type == 8)
                                {





                                        if ((sip >= psa->lowerIp) && (sip <= psa->upperIp))
                                        {
# 14952 "rtl8651_tblDrvFwd.c"
                                                retval = psa->action;

                                                if ((psa->action != 1) && rtl8651_DMZHostIcmpPassthroughEnable)
                                                        retval = 0;

                                                goto out;
                                        }
                                        else
                                                retval = 1;
                                }
                                else
                                {
                                        retval = 0;
                                        goto out;
                                }
                        }
                        else
                        {





                                if ((sip >= psa->lowerIp) && (sip <= psa->upperIp))
                                {
                                        retval = psa->action;
                                        goto out;
                                }
                                else
                                        retval = 1;
                        }
                }
        }
out:


        pktHdr->ph_un_sw.ROMEDRV_USG._ph_procFlag |= (1<<0);

        if (((((uint16)(iph->ip_off)) & (0x1fff|0x2000)) == 0x2000))
        {
                _rtl8651_updateFragCache(4, sip, dip, (iph->ip_id), retval, 0, ((void *)0), 0);
        }

        if (retval == 3)
                retval = 0;

        return retval;
}




static inline rtl8651_PS_Action_Entry_t *_rtl8651_checkProtoStackRegistedPort(uint16 port, uint8 l4proto)
{
        int i;
        rtl8651_PS_Action_Entry_t *psa;

        psa = rtl8651_ProtoStackActions;

        for ( i = 0 ; i < rtl8651_fwdEnginePara.protoStackMaxActions ; i++, psa++)
        {
                if (psa->action == 0)
                        continue;

                if (l4proto == psa->protocol)
                {
                        if (((l4proto == 6) ||(l4proto == 17)) && ((port < psa->orgPort )||(port>psa->orgPortEnd)))
                                continue;
                        return psa;
                }
        }
        return ((void *)0);
}

static void _rtl8651_aliasProtoStackSentIcmpErr(struct ip *ip)
{
        int i;
        uint16 *sport = ((void *)0), *dport = ((void *)0);
        ipaddr_t sip = ((uint32) (*((uint8*)(&ip->ip_src.s_addr))<<24)|(*(((uint8*)(&ip->ip_src.s_addr))+1)<<16)|(*(((uint8*)(&ip->ip_src.s_addr))+2)<<8) | *(((uint8*)(&ip->ip_src.s_addr))+3));
        ipaddr_t dip = ((uint32) (*((uint8*)(&ip->ip_dst.s_addr))<<24)|(*(((uint8*)(&ip->ip_dst.s_addr))+1)<<16)|(*(((uint8*)(&ip->ip_dst.s_addr))+2)<<8) | *(((uint8*)(&ip->ip_dst.s_addr))+3));
        rtl8651_PS_Action_Entry_t *psa = rtl8651_ProtoStackActions;

        if ((((uint16)(ip->ip_off)) & 0x1fff))
                return;

        switch(ip->ip_p)
        {
                case 6:
                {
                        struct tcphdr *tcp = (struct tcphdr *)((uint8 *)ip + (((*(uint8*)ip)&0xf) << 2));
                        sport = &tcp->th_sport;
                        dport = &tcp->th_dport;
                        break;
                }
                case 17:
                {
                        struct udphdr *udp = (struct udphdr *)((uint8 *)ip + (((*(uint8*)ip)&0xf) << 2));
                        sport = &udp->uh_sport;
                        dport = &udp->uh_dport;
                        break;
                }
                default:
                        return;
        }

        for (i = 0; i < rtl8651_fwdEnginePara.protoStackMaxActions; i++, psa++)
        {
                if (psa->action == 0)
                        continue;
                if ((psa->dstIp == 0 || dip == psa->dstIp) && ip->ip_p == psa->protocol)
                {
                        uint16 *chkport = ((void *)0);

                        if (psa->role == 0)
                                chkport = dport;
                        else if (psa->role == 1)
                                chkport = sport;

                        if ((*chkport) >= psa->fwdPort && (*chkport) <= (psa->fwdPort + psa->orgPortEnd - psa->orgPort))
                        {
                                if ((sip >= psa->lowerIp) && (sip <= psa->upperIp))
                                {
                                        if (psa->action == 2 && psa->orgPort != psa->fwdPort)
                                        {
                                                uint16 newFwdPort = (*chkport) - psa->fwdPort + psa->orgPort;
# 15086 "rtl8651_tblDrvFwd.c"
                                                *chkport = (newFwdPort);
                                        }
                                }
                        }
                }
        }

}

static void _rtl8651_aliasProtoStackSentPkt(uint32 outbound, uint32 dsid, struct ip *ip)
{
        if (rtl8651_getAsicOperationLayer() == 4) {

                struct ip *iph = ip;
                ipaddr_t sip = ((uint32) (*((uint8*)(&iph->ip_src.s_addr))<<24)|(*(((uint8*)(&iph->ip_src.s_addr))+1)<<16)|(*(((uint8*)(&iph->ip_src.s_addr))+2)<<8) | *(((uint8*)(&iph->ip_src.s_addr))+3));
                ipaddr_t dip = ((uint32) (*((uint8*)(&iph->ip_dst.s_addr))<<24)|(*(((uint8*)(&iph->ip_dst.s_addr))+1)<<16)|(*(((uint8*)(&iph->ip_dst.s_addr))+2)<<8) | *(((uint8*)(&iph->ip_dst.s_addr))+3));

                if (outbound)
                {

                        int i=0,dont_timeout=0;
                        uint16 *sport=((void *)0),*dport=((void *)0),*chkport=((void *)0),*chksum=((void *)0);
                        rtl8651_PS_Action_Entry_t *psa = rtl8651_ProtoStackActions;



                        if ((((uint16)(iph->ip_off)) & 0x1fff))
                                return;

                        switch(iph->ip_p)
                        {
                                case 6:
                                {
                                        struct tcphdr *tcp;
                                        tcp = (struct tcphdr *) ((int8 *) iph + ((iph->ip_vhl &0xf) << 2));
                                        sport=&tcp->th_sport;
                                        dport=&tcp->th_dport;
                                        chksum=&tcp->th_sum;

                                        if ( rtl8651_drvProtocolStackErrMsgDontTimeout == 1 )
                                        {
                                                if ( tcp->th_flags & 0x04 )
                                                {

                                                        dont_timeout = 1;
                                                }
                                        }

                                        break;
                                }

                                case 17:
                                {
                                        struct udphdr *udp;
                                        udp = (struct udphdr *) ((int8 *) iph + ((iph->ip_vhl &0xf) << 2));
                                        sport=&udp->uh_sport;
                                        dport=&udp->uh_dport;
                                        chksum=&udp->uh_sum;
                                        break;
                                }
                                case 1:
                                {

                                        struct icmp *ic = (struct icmp *)((int8 *)iph + ((*(uint8 *)iph & 0xf) << 2));

                                        if (ic->icmp_type == 3 || ic->icmp_type == 4 || ic->icmp_type == 11 || ic->icmp_type == 12)
                                        {

                                                if ( rtl8651_drvProtocolStackErrMsgDontTimeout == 1 )
                                                {

                                                        dont_timeout = 1;
                                                }

                                                _rtl8651_aliasProtoStackSentIcmpErr(&ic->icmp_dun.id_ip.idi_ip);
                                        }
                                        break;
                                }
                        }

                        for(; i < rtl8651_fwdEnginePara.protoStackMaxActions; i++, psa++)
                        {
                                if(psa->action == 0)
                                        continue;

                                if((psa->dstIp == 0 || sip == psa->dstIp) && iph->ip_p == psa->protocol)
                                {
                                        if(psa->protocol == 6 || psa->protocol == 17)
                                        {
                                                if(psa->role == 0)
                                                        chkport = sport;
                                                else if(psa->role == 1)
                                                        chkport = dport;

                                                if ((*chkport) >= psa->fwdPort && (*chkport) <= (psa->fwdPort + psa->orgPortEnd - psa->orgPort))
                                                {
                                                        if (dip >= psa->lowerIp && dip <= psa->upperIp)
                                                        {

                                                                if((psa->action == 2) && (psa->orgPort != psa->fwdPort))
                                                                {
                                                                        uint16 newFwdPort = (*chkport) - psa->fwdPort + psa->orgPort;

                                                                        if ((iph->ip_p != 17) || (*chksum != 0))
                                                                                do { int32 accumulate = 0; if (((0) != 0) && ((0) != 0)){ accumulate = ((0) & 0xffff); accumulate += (( (0) >> 16 ) & 0xffff); accumulate -= ((0) & 0xffff); accumulate -= (( (0) >> 16 ) & 0xffff); } if (((newFwdPort) != 0) && (((*chkport)) != 0)){ accumulate += ((*chkport)); accumulate -= (newFwdPort); } do { accumulate += ((*chksum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (*chksum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (*chksum) = ((uint16) accumulate); } } while (0); }while(0);
                                                                        *chkport = (newFwdPort);
                                                                }

                                                                if(psa->action == 3)
                                                                        dont_timeout = 1;

                                                                goto _check_idleTimer;
                                                        }
                                                }
                                        }
                                }
                        }
_check_idleTimer:
                        if ((dont_timeout == 0) && (rtl8651_drvProtocolStackDontTimeout == 0))
                        {
                                _rtl8651_recordTraffic(dsid, 1 );
                        }
                }



                else if (rtl8651_drvEnPortBouncingPSaction && _rtl8651_extIpAddr(sip, ((void *)0)) == 1 ) {
                        int i = 0 ;
                        uint16 *sport = ((void *)0), *dport = ((void *)0), *chkport = ((void *)0), *chksum = ((void *)0);
                        rtl8651_PS_Action_Entry_t *psa = rtl8651_ProtoStackActions;

                        if ((((uint16)(iph->ip_off)) & 0x1fff))
                                return;

                        switch(iph->ip_p) {
                                case 6:
                                {
                                        struct tcphdr *tcp;
                                        tcp = (struct tcphdr *) ((int8 *) iph + ((iph->ip_vhl &0xf) << 2));
                                        sport = &tcp->th_sport;
                                        dport = &tcp->th_dport;
                                        chksum = &tcp->th_sum;
                                        break;
                                }

                                case 17:
                                {
                                        struct udphdr *udp;
                                        udp = (struct udphdr *) ((int8 *) iph + ((iph->ip_vhl &0xf) << 2));
                                        sport=&udp->uh_sport;
                                        dport=&udp->uh_dport;
                                        chksum=&udp->uh_sum;
                                        break;
                                }

                                case 1:
                                {

                                        struct icmp *ic = (struct icmp *)((int8 *)iph + ((*(uint8 *)iph & 0xf) << 2));

                                        if (ic->icmp_type == 3 || ic->icmp_type == 4 || ic->icmp_type == 11 || ic->icmp_type == 12)
                                        {
                                                _rtl8651_aliasProtoStackSentIcmpErr(&ic->icmp_dun.id_ip.idi_ip);
                                        }
                                        break;
                                }

                                default:
                                        return;
                        }

                        for(; i < rtl8651_fwdEnginePara.protoStackMaxActions; i++, psa++) {
                                if (psa->action == 0)
                                        continue;
# 15269 "rtl8651_tblDrvFwd.c"
                                if ((psa->dstIp == 0 || sip == psa->dstIp) && iph->ip_p == psa->protocol)
                                {
                                        if (psa->protocol == 6 || psa->protocol == 17)
                                        {
                                                if (psa->role == 0)
                                                        chkport = sport;
                                                else if (psa->role == 1)
                                                        chkport = dport;

                                                if ((*chkport) >= psa->fwdPort && (*chkport) <= (psa->fwdPort + psa->orgPortEnd - psa->orgPort))
                                                {

                                                        if (dip >= psa->lowerIp && dip <= psa->upperIp)
                                                        {

                                                                if((psa->action == 2) && (psa->orgPort != psa->fwdPort))
                                                                {
                                                                        uint16 newFwdPort = (*chkport) - psa->fwdPort + psa->orgPort;

                                                                        if ((iph->ip_p != 17) || (*chksum != 0))
                                                                                do { int32 accumulate = 0; if (((0) != 0) && ((0) != 0)){ accumulate = ((0) & 0xffff); accumulate += (( (0) >> 16 ) & 0xffff); accumulate -= ((0) & 0xffff); accumulate -= (( (0) >> 16 ) & 0xffff); } if (((newFwdPort) != 0) && (((*chkport)) != 0)){ accumulate += ((*chkport)); accumulate -= (newFwdPort); } do { accumulate += ((*chksum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (*chksum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (*chksum) = ((uint16) accumulate); } } while (0); }while(0);
                                                                        *chkport = (newFwdPort);
                                                                }
                                                                return;
                                                        }
                                                }
                                        }
                                }
                        }
                }
        }
}
# 15309 "rtl8651_tblDrvFwd.c"
static int32 _rtl8651_aliasProtoStackRecvPkt(struct rtl_pktHdr *pktHdr, uint32 fromOutbound, struct ip *ip)
{
        uint16 *sportp = ((void *)0), *dportp = ((void *)0), *ckportp = ((void *)0), *cksump = ((void *)0);
        rtl8651_PS_Action_Entry_t * psa;
        ipaddr_t ip_s, ip_d;
        uint32 idx;
        int32 retval = 0;
        ip_d = ((uint32) (*((uint8*)(&ip->ip_dst))<<24)|(*(((uint8*)(&ip->ip_dst))+1)<<16)|(*(((uint8*)(&ip->ip_dst))+2)<<8) | *(((uint8*)(&ip->ip_dst))+3));
        ip_s = ((uint32) (*((uint8*)(&ip->ip_src))<<24)|(*(((uint8*)(&ip->ip_src))+1)<<16)|(*(((uint8*)(&ip->ip_src))+2)<<8) | *(((uint8*)(&ip->ip_src))+3));


        if (pktHdr->ph_un_sw.ROMEDRV_USG._ph_procFlag & (1<<0))
        {
                return retval;
        }

        if ( ((((uint16)(ip->ip_off)) & 0x1fff)) )
                goto out;

        switch (ip->ip_p)
        {
                case 6:
                {
                        struct tcphdr * tc = (struct tcphdr *)((uint8 *)ip + (((*(uint8*)ip)&0xf) << 2));
                        sportp = &(tc->th_sport);
                        dportp = &(tc->th_dport);
                        cksump = &(tc->th_sum);

                        break;
                }
                case 17:
                {
                        struct udphdr * ud = (struct udphdr *)((uint8 *)ip + (((*(uint8*)ip)&0xf) << 2));
                        sportp = &(ud->uh_sport);
                        dportp = &(ud->uh_dport);
                        cksump = &(ud->uh_sum);

                        break;
                }
                default:
                        goto out;
        }

        psa = rtl8651_ProtoStackActions;
        for ( idx = 0 ; idx < rtl8651_fwdEnginePara.protoStackMaxActions ; idx++, psa++ )
        {
                if (psa->action == 0)
                        continue;


                if ((psa->dstIp == 0 || psa->dstIp == ip_s) && ip->ip_p == psa->protocol)
                {
                        if(psa->role == 0)
                                ckportp = sportp;
                        else if (psa->role == 1)
                                ckportp = dportp;

                        if ((*ckportp) >= psa->orgPort && (*ckportp) <= psa->orgPortEnd)
                        {
                                if (ip_d >= psa->lowerIp && ip_d <= psa->upperIp)
                                {

                                        if ((psa->action == 2) && (psa->orgPort != psa->fwdPort))
                                        {





                                                *ckportp = ((*ckportp) - psa->orgPort + psa->fwdPort);
                                        }
                                        retval = psa->action;
                                        goto out;
                                } else
                                {
                                        retval = 1;
                                }
                        }
                }
        }

out:


        pktHdr->ph_un_sw.ROMEDRV_USG._ph_procFlag |= (1<<0);

        return retval;
}

static inline int32 _rtl8651_protoStackAction_filter(struct rtl_pktHdr* pktHdr, rtl8651_tblDrv_vlanTable_t *svlan, struct ip *pip)
{
        int32 retval = 0;


        if (pktHdr->ph_un_sw.ROMEDRV_USG._ph_procFlag & (1<<0))
        {
                goto out;
        }

        if (_rtl8651_extIpAddr(pktHdr->ph_dip, ((void *)0)) == 1)
        {
                if ( (pip->ip_p == 1) &&
                        (!(((uint16)(pip->ip_off)) & 0x1fff)))
                {
                        struct icmp *ic = (struct icmp *)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));

                        switch (ic->icmp_type)
                        {
                                case 3:
                                case 4:
                                case 11:
                                case 12:
                                {

                                        struct ip *cip = ((void *)0);
                                        struct tcphdr *tc = ((void *)0);
                                        struct udphdr *ud = ((void *)0);
                                        uint16 orgSPort, orgDPort;
                                        uint16 *pnewSPort;
                                        uint16 *pnewDPort;

                                        cip = (struct ip*)&(ic->icmp_dun.id_ip.idi_ip);

                                        if (!(((uint16)(cip->ip_off)) & 0x1fff))
                                        {
                                                switch ( cip->ip_p )
                                                {
                                                        case 6:
                                                        {
                                                                tc = (struct tcphdr *)((uint8 *)cip + (((*(uint8*)cip)&0xf) << 2));

                                                                orgSPort = (tc->th_sport);
                                                                orgDPort = (tc->th_dport);
                                                                pnewSPort = &(tc->th_sport);
                                                                pnewDPort = &(tc->th_dport);
                                                                break;
                                                        }
                                                        case 17:
                                                        {
                                                                ud = (struct udphdr *)((uint8 *)cip + (((*(uint8*)cip)&0xf) << 2));

                                                                orgSPort = (ud->uh_sport);
                                                                orgDPort = (ud->uh_dport);
                                                                pnewSPort = &(ud->uh_sport);
                                                                pnewDPort = &(ud->uh_dport);
                                                                break;
                                                        }
                                                        default:



                                                                goto out;
                                                }

                                                if ( (retval = _rtl8651_aliasProtoStackRecvPkt( pktHdr,
                                                                                                                                        (svlan->internal)?0:1,
                                                                                                                                        cip)) == 2 )
                                                {
# 15475 "rtl8651_tblDrvFwd.c"
                                                        do { int32 accumulate = 0; if (((0) != 0) && ((0) != 0)){ accumulate = ((0) & 0xffff); accumulate += (( (0) >> 16 ) & 0xffff); accumulate -= ((0) & 0xffff); accumulate -= (( (0) >> 16 ) & 0xffff); } if ((((*pnewSPort)) != 0) && ((orgSPort) != 0)){ accumulate += (orgSPort); accumulate -= ((*pnewSPort)); } do { accumulate += ((ic->icmp_cksum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) accumulate); } } while (0); }while(0);
                                                        do { int32 accumulate = 0; if (((0) != 0) && ((0) != 0)){ accumulate = ((0) & 0xffff); accumulate += (( (0) >> 16 ) & 0xffff); accumulate -= ((0) & 0xffff); accumulate -= (( (0) >> 16 ) & 0xffff); } if ((((*pnewDPort)) != 0) && ((orgDPort) != 0)){ accumulate += (orgDPort); accumulate -= ((*pnewDPort)); } do { accumulate += ((ic->icmp_cksum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ic->icmp_cksum) = ((uint16) accumulate); } } while (0); }while(0);
                                                }
                                        }


                                        goto out;
                                }
                                default:

                                        break;
                        }
                }




                retval = _rtl8651_doProtoStackAction(pktHdr, pip);

        }
out:


        pktHdr->ph_un_sw.ROMEDRV_USG._ph_procFlag |= (1<<0);

        switch ( retval )
        {
                case 2:
                        retval = 132;
                        break;
                case 1:
                        retval = 131;
                        break;
                default:
                        retval = 0;
                        break;
        }

        return retval;
}






void _rtl8651_flushPortBouncingEntry(void)
{
        memset(portBouncingTable,0,64 * sizeof (struct _RTL8651_PORT_BOUNCING_ENTRY));
}
# 15533 "rtl8651_tblDrvFwd.c"
static struct _RTL8651_PORT_BOUNCING_ENTRY * _rtl8651_addPortBouncingEntry(uint8 flowType,ipaddr_t cip,uint16 cport,ipaddr_t gip,uint16 gport,ipaddr_t sip,uint16 sport, uint16 id, uint32 tcpFlag, uint16 age)
{
        int i;
        struct _RTL8651_PORT_BOUNCING_ENTRY *ptr;
        struct _RTL8651_PORT_BOUNCING_ENTRY *candidate[4] = {((void *)0)};

        ptr = portBouncingTable;

        for(i=0;i<64;i++, ptr++)
        {
                if(ptr->age == 0)
                {
setNewEntry:
                        ptr->clientIpAddr = cip;
                        ptr->clientPort = cport;
                        ptr->serverIpAddr = sip;
                        ptr->serverPort = sport;
                        ptr->gatewayIpAddr = gip;
                        ptr->gatewayPort = gport;
                        ptr->id = id;
                        ptr->age = age;
                        ptr->flowType = flowType;
                        if (tcpFlag)
                        {
                                ptr->tcpFlag = (tcpFlag - 1);
                        }else
                        {
                                ptr->tcpFlag = 0;
                        }
                        return ptr;
                }else
                {


                        if (ptr->flowType == 5)
                        {
                                if (ptr->tcpFlag == (8 - 1))
                                        candidate[0] = ptr;
                                else if ( (candidate[3] == ((void *)0)) ||
                                                (candidate[3]->age > ptr->age) )
                                        candidate[3] = ptr;
                        } else if (ptr->flowType == 6)
                        {
                                if ( (candidate[2] == ((void *)0)) ||
                                                (candidate[2]->age > ptr->age) )
                                        candidate[2] = ptr;
                        } else if (ptr->flowType == 3)
                        {
                                if ( (candidate[1] == ((void *)0)) ||
                                                (candidate[1]->age > ptr->age) )
                                        candidate[1] = ptr;
                        }
                }
        }
# 15596 "rtl8651_tblDrvFwd.c"
        for (i = 0 ; i < 4 ; i ++)
        {
                if (candidate[i])
                {
                        ptr = candidate[i];
                        goto setNewEntry;
                }
        }


        return ((void *)0);
}

void _rtl8651_portBouncingTimeUpdate(uint32 secPassed)
{
        struct _RTL8651_PORT_BOUNCING_ENTRY *pb_t;
        int i;

        for(i=0, pb_t=portBouncingTable;i<64; i++, pb_t++)
        {
                if (pb_t->age < secPassed)
                {
                        pb_t->age = 0;
                } else pb_t->age -= secPassed;
        }
}

static int32 _rtl8651_l34PortBouncingIcmpErrMsg(struct rtl_pktHdr *pkthdr, struct ip *pip, struct icmp *ic)
{
        uint32 nCount;
        uint16 errFlowType;
        struct ip *eip;

        struct tcphdr *etc=((void *)0);
        struct udphdr *eud=((void *)0);
        uint16 esport=0, edport=0;
        struct icmp *eic;
        uint16 eid=0;


        switch (ic->icmp_type)
        {
                case 11:
                case 3:
                case 4:
                case 12:
                        break;
                default:
                        goto to_gw;
        }

        eip = &ic->icmp_dun.id_ip.idi_ip;
        switch (eip->ip_p)
        {
                case 6:
                        errFlowType = 5;
                        etc = (struct tcphdr*) ((int8 *) eip + ((*(uint8*)eip&0xf) << 2));
                        esport = (etc->th_sport);
                        edport = (etc->th_dport);
                        break;
                case 17:
                        errFlowType = 6;
                        eud = (struct udphdr*) ((int8 *) eip + ((*(uint8*)eip&0xf) << 2));
                        esport = (eud->uh_sport);
                        edport = (eud->uh_dport);
                        break;
                case 1:
                        errFlowType = 3;
                        eic = (struct icmp*) ((int8 *) eip + ((*(uint8*)eip&0xf) << 2));
                        eid = (eic->icmp_hun.ih_idseq.icd_id);
                        break;
                default:
                        goto to_gw;
        }


        for ( nCount = 0 ; nCount < 64 ; nCount++ )
        {
                if (portBouncingTable[nCount].age == 0)
                        continue;
                if (pkthdr->ph_dip != portBouncingTable[nCount].gatewayIpAddr)
                        continue;
                if (errFlowType != portBouncingTable[nCount].flowType)
                        continue;

                if (pkthdr->ph_sip == portBouncingTable[nCount].clientIpAddr)
                {
                        if (((eip->ip_p == 6) || (eip->ip_p == 17)) &&
                                (esport == portBouncingTable[nCount].gatewayPort) &&
                                (edport == portBouncingTable[nCount].clientPort))
                        {
                                do{ *((uint8*)(&eip->ip_src)) = (uint8)((portBouncingTable[nCount].serverIpAddr)>>24); *(((uint8*)(&eip->ip_src))+1) = (uint8)((portBouncingTable[nCount].serverIpAddr)>>16); *(((uint8*)(&eip->ip_src))+2) = (uint8)((portBouncingTable[nCount].serverIpAddr)>>8); *(((uint8*)(&eip->ip_src))+3) = (uint8)((portBouncingTable[nCount].serverIpAddr)); }while(0);
                                do{ *((uint8*)(&eip->ip_dst)) = (uint8)((portBouncingTable[nCount].gatewayIpAddr)>>24); *(((uint8*)(&eip->ip_dst))+1) = (uint8)((portBouncingTable[nCount].gatewayIpAddr)>>16); *(((uint8*)(&eip->ip_dst))+2) = (uint8)((portBouncingTable[nCount].gatewayIpAddr)>>8); *(((uint8*)(&eip->ip_dst))+3) = (uint8)((portBouncingTable[nCount].gatewayIpAddr)); }while(0);
                                do { do { int32 accumulate = 0; if ((((portBouncingTable[nCount].serverIpAddr)) != 0) && (((portBouncingTable[nCount].clientIpAddr)) != 0)){ accumulate = (((portBouncingTable[nCount].clientIpAddr)) & 0xffff); accumulate += (( ((portBouncingTable[nCount].clientIpAddr)) >> 16 ) & 0xffff); accumulate -= (((portBouncingTable[nCount].serverIpAddr)) & 0xffff); accumulate -= (( ((portBouncingTable[nCount].serverIpAddr)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((eip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((eip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((eip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                                if (eip->ip_p == 6)
                                {
                                        etc->th_sport = (portBouncingTable[nCount].serverPort);
                                }else
                                {
                                        eud->uh_sport = (portBouncingTable[nCount].serverPort);
                                }
                        }else if (eid == portBouncingTable[nCount].id)
                        {
                                do{ *((uint8*)(&eip->ip_src)) = (uint8)((portBouncingTable[nCount].serverIpAddr)>>24); *(((uint8*)(&eip->ip_src))+1) = (uint8)((portBouncingTable[nCount].serverIpAddr)>>16); *(((uint8*)(&eip->ip_src))+2) = (uint8)((portBouncingTable[nCount].serverIpAddr)>>8); *(((uint8*)(&eip->ip_src))+3) = (uint8)((portBouncingTable[nCount].serverIpAddr)); }while(0);
                                do{ *((uint8*)(&eip->ip_dst)) = (uint8)((portBouncingTable[nCount].gatewayIpAddr)>>24); *(((uint8*)(&eip->ip_dst))+1) = (uint8)((portBouncingTable[nCount].gatewayIpAddr)>>16); *(((uint8*)(&eip->ip_dst))+2) = (uint8)((portBouncingTable[nCount].gatewayIpAddr)>>8); *(((uint8*)(&eip->ip_dst))+3) = (uint8)((portBouncingTable[nCount].gatewayIpAddr)); }while(0);
                                do { do { int32 accumulate = 0; if ((((portBouncingTable[nCount].serverIpAddr)) != 0) && (((portBouncingTable[nCount].clientIpAddr)) != 0)){ accumulate = (((portBouncingTable[nCount].clientIpAddr)) & 0xffff); accumulate += (( ((portBouncingTable[nCount].clientIpAddr)) >> 16 ) & 0xffff); accumulate -= (((portBouncingTable[nCount].serverIpAddr)) & 0xffff); accumulate -= (( ((portBouncingTable[nCount].serverIpAddr)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((eip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((eip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((eip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                        }else
                        {
                                goto checkS2C;
                        }
                        pkthdr->ph_sip = pkthdr->ph_dip;
                        do{ *((uint8*)(&pip->ip_src)) = (uint8)((pkthdr->ph_sip)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((pkthdr->ph_sip)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((pkthdr->ph_sip)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((pkthdr->ph_sip)); }while(0);
                        pkthdr->ph_dip = portBouncingTable[nCount].serverIpAddr;
                        do{ *((uint8*)(&pip->ip_dst)) = (uint8)((pkthdr->ph_dip)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((pkthdr->ph_dip)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((pkthdr->ph_dip)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((pkthdr->ph_dip)); }while(0);
                        goto out;
                }
checkS2C:
                if (pkthdr->ph_sip == portBouncingTable[nCount].serverIpAddr)
                {
                        if (((eip->ip_p == 6) || (eip->ip_p == 17)) &&
                                (esport == portBouncingTable[nCount].clientPort) &&
                                (edport == portBouncingTable[nCount].serverPort))
                        {
                                do{ *((uint8*)(&eip->ip_src)) = (uint8)((portBouncingTable[nCount].clientIpAddr)>>24); *(((uint8*)(&eip->ip_src))+1) = (uint8)((portBouncingTable[nCount].clientIpAddr)>>16); *(((uint8*)(&eip->ip_src))+2) = (uint8)((portBouncingTable[nCount].clientIpAddr)>>8); *(((uint8*)(&eip->ip_src))+3) = (uint8)((portBouncingTable[nCount].clientIpAddr)); }while(0);
                                do{ *((uint8*)(&eip->ip_dst)) = (uint8)((portBouncingTable[nCount].gatewayIpAddr)>>24); *(((uint8*)(&eip->ip_dst))+1) = (uint8)((portBouncingTable[nCount].gatewayIpAddr)>>16); *(((uint8*)(&eip->ip_dst))+2) = (uint8)((portBouncingTable[nCount].gatewayIpAddr)>>8); *(((uint8*)(&eip->ip_dst))+3) = (uint8)((portBouncingTable[nCount].gatewayIpAddr)); }while(0);
                                do { do { int32 accumulate = 0; if ((((portBouncingTable[nCount].clientIpAddr)) != 0) && (((portBouncingTable[nCount].serverIpAddr)) != 0)){ accumulate = (((portBouncingTable[nCount].serverIpAddr)) & 0xffff); accumulate += (( ((portBouncingTable[nCount].serverIpAddr)) >> 16 ) & 0xffff); accumulate -= (((portBouncingTable[nCount].clientIpAddr)) & 0xffff); accumulate -= (( ((portBouncingTable[nCount].clientIpAddr)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((eip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((eip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((eip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                                if (eip->ip_p == 6)
                                {
                                        etc->th_dport = (portBouncingTable[nCount].gatewayPort);
                                }else
                                {
                                        eud->uh_dport = (portBouncingTable[nCount].gatewayPort);
                                }
                        }else if (eid == portBouncingTable[nCount].id)
                        {
                                do{ *((uint8*)(&eip->ip_src)) = (uint8)((portBouncingTable[nCount].clientIpAddr)>>24); *(((uint8*)(&eip->ip_src))+1) = (uint8)((portBouncingTable[nCount].clientIpAddr)>>16); *(((uint8*)(&eip->ip_src))+2) = (uint8)((portBouncingTable[nCount].clientIpAddr)>>8); *(((uint8*)(&eip->ip_src))+3) = (uint8)((portBouncingTable[nCount].clientIpAddr)); }while(0);
                                do{ *((uint8*)(&eip->ip_dst)) = (uint8)((portBouncingTable[nCount].gatewayIpAddr)>>24); *(((uint8*)(&eip->ip_dst))+1) = (uint8)((portBouncingTable[nCount].gatewayIpAddr)>>16); *(((uint8*)(&eip->ip_dst))+2) = (uint8)((portBouncingTable[nCount].gatewayIpAddr)>>8); *(((uint8*)(&eip->ip_dst))+3) = (uint8)((portBouncingTable[nCount].gatewayIpAddr)); }while(0);
                                do { do { int32 accumulate = 0; if ((((portBouncingTable[nCount].clientIpAddr)) != 0) && (((portBouncingTable[nCount].serverIpAddr)) != 0)){ accumulate = (((portBouncingTable[nCount].serverIpAddr)) & 0xffff); accumulate += (( ((portBouncingTable[nCount].serverIpAddr)) >> 16 ) & 0xffff); accumulate -= (((portBouncingTable[nCount].clientIpAddr)) & 0xffff); accumulate -= (( ((portBouncingTable[nCount].clientIpAddr)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((eip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((eip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((eip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);

                        }else
                        {
                                continue;
                        }
                        pkthdr->ph_sip = pkthdr->ph_dip;
                        do{ *((uint8*)(&pip->ip_src)) = (uint8)((pkthdr->ph_sip)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((pkthdr->ph_sip)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((pkthdr->ph_sip)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((pkthdr->ph_sip)); }while(0);
                        pkthdr->ph_dip = portBouncingTable[nCount].clientIpAddr;
                        do{ *((uint8*)(&pip->ip_dst)) = (uint8)((pkthdr->ph_dip)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((pkthdr->ph_dip)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((pkthdr->ph_dip)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((pkthdr->ph_dip)); }while(0);
                        goto out;
                }
        }

        return -1;
to_gw:
        return 132;
out:
        return 0;
}





static inline int32 _rtl8651_l4NaptPortBouncing(struct rtl_pktHdr *pkthdr, struct ip *pip)
{
        struct _RTL8651_PORT_BOUNCING_ENTRY *pb_entry = ((void *)0);
        rtl8651_tblDrv_vlanTable_t * ingress_vlan;
        uint32 netIdx;
        struct tcphdr *tc=((void *)0);
        struct udphdr *ud=((void *)0);
        struct icmp *ic=((void *)0);
        ipaddr_t sip = pkthdr->ph_sip;
        ipaddr_t dip = pkthdr->ph_dip;
        uint16 sport=0;
        uint16 dport=0;
        uint16 id=0;
        int16 idx = -1;
        int16 nCount;


        if (_rtl8651_extIpAddr(dip, &netIdx) != 1)
        {
                goto to_gw;
        }

        ingress_vlan = &DrvTbl.vlan[pkthdr->ph_vlanIdx & (8 - 1)];
        if (!ingress_vlan->internal)
        {
                goto to_gw;
        }


        if ((pip->ip_off) & 0x1fff)
        {
                ipaddr_t mod_ip;

                if (_rtl8651_getFragCache(2, sip, dip, (pip->ip_id), &mod_ip, ((void *)0), ((void *)0), &(pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid)) != 0)
                {
                        goto to_gw;
                }
                pkthdr->ph_sip = pkthdr->ph_dip;
                pkthdr->ph_dip = mod_ip;
                do{ *((uint8*)(&pip->ip_src)) = (uint8)((pkthdr->ph_sip)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((pkthdr->ph_sip)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((pkthdr->ph_sip)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((pkthdr->ph_sip)); }while(0);
                do{ *((uint8*)(&pip->ip_dst)) = (uint8)((pkthdr->ph_dip)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((pkthdr->ph_dip)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((pkthdr->ph_dip)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((pkthdr->ph_dip)); }while(0);
                goto out;
        }
# 15809 "rtl8651_tblDrvFwd.c"
        switch (pkthdr->ph_proto)
        {
                case 5:
                        tc = (struct tcphdr*)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));
                        sport = (tc->th_sport);
                        dport = (tc->th_dport);
                        break;
                case 6:
                        ud = (struct udphdr*)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));
                        sport = (ud->uh_sport);
                        dport = (ud->uh_dport);
                        break;
                case 3:
                        ic = (struct icmp*)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));
                        id = (ic->icmp_hun.ih_idseq.icd_id);
                        break;
                default:
                        goto to_gw;
        }


        for ( nCount = 0 ; nCount < 64 ; nCount++ )
        {
                if (portBouncingTable[nCount].age == 0)
                        continue;

                if (pkthdr->ph_proto != portBouncingTable[nCount].flowType)
                        continue;

                if (dip != portBouncingTable[nCount].gatewayIpAddr)
                        continue;

                if (sip == portBouncingTable[nCount].clientIpAddr)
                {
                        if( (((pkthdr->ph_proto == 5) ||(pkthdr->ph_proto == 6))) &&
                                (sport == portBouncingTable[nCount].clientPort) &&
                                (dport == portBouncingTable[nCount].gatewayPort))
                        {
                                if(pkthdr->ph_proto == 5)
                                {
                                        tc->th_dport = (portBouncingTable[nCount].serverPort);
                                        portBouncingTable[nCount].age =
                                                _rtl8651_portBouncingTcpMonitor(tc, &(portBouncingTable[nCount].tcpFlag), 1);
                                }else
                                {
                                        int j;
                                        for(j=0;j < 64 ;j++ )
                                        {
                                                if (portBouncingTable[j].age == 0)
                                                        continue;

                                                if (pkthdr->ph_proto != portBouncingTable[j].flowType)
                                                        continue;

                                                if (sip != portBouncingTable[j].serverIpAddr)
                                                        continue;

                                                if (ud->uh_sport != portBouncingTable[j].serverPort)
                                                        continue;

                                                ud->uh_sport= portBouncingTable[j].gatewayPort;
                                                break;
                                        }
                                        ud->uh_dport = (portBouncingTable[nCount].serverPort);
                                        portBouncingTable[nCount].age = rtl8651GlobalControl.udpTimeout;
                                }
                        }else if ((pkthdr->ph_proto == 3) && (id == portBouncingTable[nCount].id))
                        {
                                switch (ic->icmp_type)
                                {





                                        case 8:
                                        case 13:
                                                if (!rtl8651_DMZHostIcmpPassthroughEnable)
                                                        goto to_gw;
                                                break;
                                        default:
                                                break;
                                }

                                portBouncingTable[nCount].age = rtl8651GlobalControl.icmpTimeout;

                        }else
                        {
                                goto checkS2C;
                        }

                        pkthdr->ph_sip = pkthdr->ph_dip;
                        do{ *((uint8*)(&pip->ip_src)) = (uint8)((pkthdr->ph_sip)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((pkthdr->ph_sip)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((pkthdr->ph_sip)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((pkthdr->ph_sip)); }while(0);
                        pkthdr->ph_dip = portBouncingTable[nCount].serverIpAddr;
                        do{ *((uint8*)(&pip->ip_dst)) = (uint8)((pkthdr->ph_dip)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((pkthdr->ph_dip)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((pkthdr->ph_dip)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((pkthdr->ph_dip)); }while(0);
                        idx = nCount;
                        pb_entry = &(portBouncingTable[nCount]);
                        goto out;
                }
checkS2C:
                if (sip == portBouncingTable[nCount].serverIpAddr)
                {
                        if (((pkthdr->ph_proto == 5) || (pkthdr->ph_proto == 6)) &&
                                (sport == portBouncingTable[nCount].serverPort) &&
                                (dport == portBouncingTable[nCount].clientPort))
                        {
                                if (pkthdr->ph_proto == 5)
                                {
                                        tc->th_sport = (portBouncingTable[nCount].gatewayPort);
                                        portBouncingTable[nCount].age =
                                                _rtl8651_portBouncingTcpMonitor(tc, &(portBouncingTable[nCount].tcpFlag), 0);
                                }else
                                {
                                        int j;
                                        for(j=0;j < 64 ;j++ )
                                        {
                                                if (portBouncingTable[j].age == 0)
                                                        continue;

                                                if (pkthdr->ph_proto != portBouncingTable[j].flowType)
                                                        continue;

                                                if (sip != portBouncingTable[j].clientIpAddr)
                                                        continue;

                                                if (ud->uh_sport != portBouncingTable[j].clientPort)
                                                        continue;

                                                ud->uh_dport= portBouncingTable[j].serverPort;
                                                break;
                                        }
                                        ud->uh_sport = (portBouncingTable[nCount].gatewayPort);
                                        portBouncingTable[nCount].age = rtl8651GlobalControl.udpTimeout;
                                }
                        }else if ((pkthdr->ph_proto == 3) && (id == portBouncingTable[nCount].id))
                        {

                                portBouncingTable[nCount].age = rtl8651GlobalControl.icmpTimeout;
                        }else
                        {
                                continue;
                        }

                        pkthdr->ph_sip = pkthdr->ph_dip;
                        do{ *((uint8*)(&pip->ip_src)) = (uint8)((pkthdr->ph_sip)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((pkthdr->ph_sip)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((pkthdr->ph_sip)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((pkthdr->ph_sip)); }while(0);
                        pkthdr->ph_dip = portBouncingTable[nCount].clientIpAddr;
                        do{ *((uint8*)(&pip->ip_dst)) = (uint8)((pkthdr->ph_dip)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((pkthdr->ph_dip)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((pkthdr->ph_dip)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((pkthdr->ph_dip)); }while(0);
                        idx = nCount;
                        pb_entry = &(portBouncingTable[nCount]);
                        goto out;
                }
        }

        {




                int32 local_val;
                rtl8651_tblDrv_vlanTable_t *local_vlanp = &DrvTbl.vlan[pkthdr->ph_vlanIdx];
                local_val = _rtl8651_ingressAcl(pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid, 0, local_vlanp, local_vlanp->vid, pkthdr->PKTHDRNXT.mbuf_first->m_data, (uint8 *) pip, 0x01, 0);
                if (((local_val > 0) && (local_val & 0x1000)) ||(local_val == 2))
                        return local_val;
        }



                if(idx == -1)
                {
                        rtl8651_tblDrv_naptServerPortEntry_t * sp = ((void *)0);
                        if(pkthdr->ph_proto == 5)
                        {
                                sp = _rtl8651_getOutsideNaptServerPortMapping(1, dip, dport);
                                if (sp)
                                {
                                        if ((pb_entry = _rtl8651_addPortBouncingEntry(5,
                                                sip, sport,
                                                dip, dport,
                                                sp->localIp, (dport + sp->localPort - sp->globalPort),
                                                0,
                                                2,
                                                rtl8651GlobalControl.tcpFastTimeout)) == ((void *)0))
                                        {
                                                goto drop;
                                        }
                                        tc->th_dport = ((dport + sp->localPort - sp->globalPort));
                                }
                        }else if(pkthdr->ph_proto == 6)
                        {
                                sp = _rtl8651_getOutsideNaptServerPortMapping(0, dip, dport);
                                if (sp)
                                {
                                        if ((pb_entry = _rtl8651_addPortBouncingEntry(6,
                                                sip, sport,
                                                dip, dport,
                                                sp->localIp, (dport + sp->localPort - sp->globalPort),
                                                0,
                                                0,
                                                rtl8651GlobalControl.udpTimeout)) == ((void *)0))
                                        {
                                                goto drop;
                                        }
                                        ud->uh_dport = ((dport + sp->localPort - sp->globalPort));
                                }
                        }
                        if (sp)
                        {
                                pkthdr->ph_sip = pkthdr->ph_dip;
                                do{ *((uint8*)(&pip->ip_src)) = (uint8)((pkthdr->ph_sip)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((pkthdr->ph_sip)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((pkthdr->ph_sip)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((pkthdr->ph_sip)); }while(0);
                                pkthdr->ph_dip = sp->localIp;
                                do{ *((uint8*)(&pip->ip_dst)) = (uint8)((pkthdr->ph_dip)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((pkthdr->ph_dip)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((pkthdr->ph_dip)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((pkthdr->ph_dip)); }while(0);
                                goto out;
                        }
                        do {} while (0);

                        if (rtl8651_drvProcessUpnpPortBouncing == 1)
                        {
                                if ((pkthdr->ph_proto == 5) || (pkthdr->ph_proto == 6))
                                {
                                        ipaddr_t localIp = 0;
                                        uint16 localPort = 0;


                                        _rtl8651_findInboundUpnpMapping((pkthdr->ph_proto == 5)?1:0, sip, sport, dip, dport, &localIp, &localPort, ((void *)0), ((void *)0));
                                        if (localIp)
                                        {
                                                if ((pb_entry = _rtl8651_addPortBouncingEntry(pkthdr->ph_proto,
                                                        sip, sport,
                                                        dip, dport,
                                                        localIp, localPort,
                                                        0,
                                                        (pkthdr->ph_proto == 5)?2:0,
                                                        (pkthdr->ph_proto == 5)?rtl8651GlobalControl.tcpFastTimeout:rtl8651GlobalControl.udpTimeout)) == ((void *)0))
                                                {
                                                        goto drop;
                                                }
                                                if (pkthdr->ph_proto == 5)
                                                        tc->th_dport = (localPort);
                                                else
                                                        ud->uh_dport = (localPort);


                                                pkthdr->ph_sip = pkthdr->ph_dip;
                                                do{ *((uint8*)(&pip->ip_src)) = (uint8)((pkthdr->ph_sip)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((pkthdr->ph_sip)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((pkthdr->ph_sip)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((pkthdr->ph_sip)); }while(0);
                                                pkthdr->ph_dip = localIp;
                                                do{ *((uint8*)(&pip->ip_dst)) = (uint8)((pkthdr->ph_dip)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((pkthdr->ph_dip)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((pkthdr->ph_dip)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((pkthdr->ph_dip)); }while(0);
                                                goto out;
                                        }
                                }
                        }
# 16069 "rtl8651_tblDrvFwd.c"
                        if (rtl8651_drvEnPortBouncingPSaction) {

                                int32 val;
                                rtl8651_tblDrv_vlanTable_t *local_vlanp = &DrvTbl.vlan[pkthdr->ph_vlanIdx];

                                if ((val = _rtl8651_protoStackAction_filter(pkthdr, local_vlanp, pip)) != 0)
                                {
                                        switch (val)
                                        {
                                                case 132:
                                                        goto to_gw;
                                                case 131:
                                                        goto drop;
                                        }
                                }
                        }





                        {
                                ipaddr_t dmzhost;
                                if (_rtl8651_getDmzHost(pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid, dip, &dmzhost) == 0)
                                {
                                        switch (pkthdr->ph_proto)
                                        {
                                                case 5:
                                                        if ((pb_entry = _rtl8651_addPortBouncingEntry(5,
                                                                sip, sport,
                                                                dip, dport,
                                                                dmzhost, dport,
                                                                0,
                                                                2,
                                                                rtl8651GlobalControl.tcpFastTimeout)) == ((void *)0))
                                                        {
                                                                goto drop;
                                                        }
                                                        break;
                                                case 6:
                                                        if ((pb_entry = _rtl8651_addPortBouncingEntry(6,
                                                                sip, sport,
                                                                dip, dport,
                                                                dmzhost, dport,
                                                                0,
                                                                0,
                                                                rtl8651GlobalControl.udpTimeout)) == ((void *)0))
                                                        {
                                                                goto drop;
                                                        }
                                                        break;
                                                case 3:
                                                        switch (ic->icmp_type)
                                                        {





                                                                case 8:
                                                                case 13:
                                                                        if (!rtl8651_DMZHostIcmpPassthroughEnable)
                                                                                goto to_gw;
                                                                        break;
                                                                case 11:
                                                                case 3:
                                                                case 4:
                                                                case 12:
                                                                        goto icmp_errMsg;
                                                                default:
                                                                        break;
                                                        }
                                                        if ((pb_entry = _rtl8651_addPortBouncingEntry(3,
                                                                sip, 0,
                                                                dip, 0,
                                                                dmzhost, 0,
                                                                id,
                                                                0,
                                                                rtl8651GlobalControl.icmpTimeout)) == ((void *)0))
                                                        {
                                                                goto drop;
                                                        }
                                                        break;
                                        }
                                        pkthdr->ph_sip = pkthdr->ph_dip;
                                        do{ *((uint8*)(&pip->ip_src)) = (uint8)((pkthdr->ph_sip)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((pkthdr->ph_sip)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((pkthdr->ph_sip)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((pkthdr->ph_sip)); }while(0);
                                        pkthdr->ph_dip = dmzhost;
                                        do{ *((uint8*)(&pip->ip_dst)) = (uint8)((pkthdr->ph_dip)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((pkthdr->ph_dip)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((pkthdr->ph_dip)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((pkthdr->ph_dip)); }while(0);
                                        goto out;
                                }
                        }
                }
                goto icmp_errMsg;
out:
        {

                rtl8651_tblDrv_networkIntfTable_t * netIface = &DrvTbl.netIface[netIdx];

                pkthdr->ph_vlanIdx = netIface->vid;
                pkthdr->ph_routeIdx = 0;
                pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid = 0;
                pkthdr->ph_portlist = 0;
        }

        if (((pip->ip_vhl & 0x0f) != 5) || (((pip->ip_off) & (0x2000|0x1fff)) == 0x2000))
        {
                if ((pip->ip_vhl & 0x0f) != 5)
                {
                        do { do { int32 accumulate = 0; if ((((pkthdr->ph_sip)) != 0) && (((sip)) != 0)){ accumulate = (((sip)) & 0xffff); accumulate += (( ((sip)) >> 16 ) & 0xffff); accumulate -= (((pkthdr->ph_sip)) & 0xffff); accumulate -= (( ((pkthdr->ph_sip)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                        do { do { int32 accumulate = 0; if ((((pkthdr->ph_dip)) != 0) && (((dip)) != 0)){ accumulate = (((dip)) & 0xffff); accumulate += (( ((dip)) >> 16 ) & 0xffff); accumulate -= (((pkthdr->ph_dip)) & 0xffff); accumulate -= (( ((pkthdr->ph_dip)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                }

                if (((pip->ip_off) & 0x1fff) == 0)
                {
                        if (pkthdr->ph_proto == 5)
                        {
                                do { int32 accumulate = 0; if (((pkthdr->ph_sip) != 0) && ((sip) != 0)){ accumulate = ((sip) & 0xffff); accumulate += (( (sip) >> 16 ) & 0xffff); accumulate -= ((pkthdr->ph_sip) & 0xffff); accumulate -= (( (pkthdr->ph_sip) >> 16 ) & 0xffff); } if (((tc->th_sport) != 0) && (((sport)) != 0)){ accumulate += ((sport)); accumulate -= (tc->th_sport); } do { accumulate += ((tc->th_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) accumulate); } } while (0); }while(0);
                                do { int32 accumulate = 0; if (((pkthdr->ph_dip) != 0) && ((dip) != 0)){ accumulate = ((dip) & 0xffff); accumulate += (( (dip) >> 16 ) & 0xffff); accumulate -= ((pkthdr->ph_dip) & 0xffff); accumulate -= (( (pkthdr->ph_dip) >> 16 ) & 0xffff); } if (((tc->th_dport) != 0) && (((dport)) != 0)){ accumulate += ((dport)); accumulate -= (tc->th_dport); } do { accumulate += ((tc->th_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) accumulate); } } while (0); }while(0);
                        }else if ((pkthdr->ph_proto == 6) && (ud->uh_sum))
                        {
                                do { int32 accumulate = 0; if (((pkthdr->ph_sip) != 0) && ((sip) != 0)){ accumulate = ((sip) & 0xffff); accumulate += (( (sip) >> 16 ) & 0xffff); accumulate -= ((pkthdr->ph_sip) & 0xffff); accumulate -= (( (pkthdr->ph_sip) >> 16 ) & 0xffff); } if (((ud->uh_sport) != 0) && (((sport)) != 0)){ accumulate += ((sport)); accumulate -= (ud->uh_sport); } do { accumulate += ((ud->uh_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) accumulate); } } while (0); }while(0);
                                do { int32 accumulate = 0; if (((pkthdr->ph_dip) != 0) && ((dip) != 0)){ accumulate = ((dip) & 0xffff); accumulate += (( (dip) >> 16 ) & 0xffff); accumulate -= ((pkthdr->ph_dip) & 0xffff); accumulate -= (( (pkthdr->ph_dip) >> 16 ) & 0xffff); } if (((ud->uh_dport) != 0) && (((dport)) != 0)){ accumulate += ((dport)); accumulate -= (ud->uh_dport); } do { accumulate += ((ud->uh_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) accumulate); } } while (0); }while(0);
                        }


                        if ((((uint16)(pip->ip_off)) & (0x1fff|0x2000)))
                        {
                                _rtl8651_updateFragCache(2, sip, dip, (pip->ip_id), pkthdr->ph_dip, 0, ((void *)0), pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid);
                        }
                }
        }

        if (_rtl8651_l3ActRouting(pkthdr, pkthdr->ph_dip, pip) != 0)
        {
                goto drop;
        }
        return 0;

icmp_errMsg:
        if (pkthdr->ph_proto == 3)
        {
                if (_rtl8651_l34PortBouncingIcmpErrMsg(pkthdr, pip, ic) == 0)
                {
                        goto out;
                }
        }
        goto to_gw;

drop:
        if (pb_entry)
        {
                pb_entry->age = 0;
        }
        return 0x1000;
to_gw:

        return -1;
}

static inline int32 _rtl8651_l4NatPortBouncing(struct rtl_pktHdr *pkthdr, struct ip *pip)
{
        struct _RTL8651_PORT_BOUNCING_ENTRY *pb_entry = ((void *)0);
        rtl8651_tblDrv_vlanTable_t * ingress_vlan;
        rtl8651_tblDrv_natEntry_t * nat;
        struct tcphdr *tc=0;
        struct udphdr *ud=0;
        ipaddr_t sip = pkthdr->ph_sip;
        ipaddr_t dip = pkthdr->ph_dip;
        uint16 sport=0, dport=0;
        struct icmp *ic=0;
        uint16 id=0;
        int16 idx = -1;
        int16 nCount;


        if ((nat = _rtl8651_getNatExternalMappingEntry(dip, pkthdr)) == ((void *)0))
        {
                goto to_gw;
        }

        ingress_vlan = &DrvTbl.vlan[pkthdr->ph_vlanIdx & (8 - 1)];
        if (!ingress_vlan->internal)
        {
                goto to_gw;
        }


        if (nat->globalIp == nat->localIp)
        {
                goto out;
        }


        if ((pip->ip_off) & 0x1fff)
        {
                ipaddr_t mod_ip;

                if (_rtl8651_getFragCache(2, sip, dip, (pip->ip_id), &mod_ip, ((void *)0), ((void *)0), &(pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid)) != 0)
                {
                        goto to_gw;
                }

                pkthdr->ph_sip = pkthdr->ph_dip;
                pkthdr->ph_dip = mod_ip;
                do{ *((uint8*)(&pip->ip_src)) = (uint8)((pkthdr->ph_sip)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((pkthdr->ph_sip)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((pkthdr->ph_sip)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((pkthdr->ph_sip)); }while(0);
                do{ *((uint8*)(&pip->ip_dst)) = (uint8)((pkthdr->ph_dip)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((pkthdr->ph_dip)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((pkthdr->ph_dip)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((pkthdr->ph_dip)); }while(0);
                goto out;
        }







        switch (pkthdr->ph_proto)
        {
                case 5:
                        tc = (struct tcphdr*)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));
                        sport = (tc->th_sport);
                        dport = (tc->th_dport);
                        break;
                case 6:
                        ud = (struct udphdr*)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));
                        sport = (ud->uh_sport);
                        dport = (ud->uh_dport);
                        break;
                case 3:
                        ic = (struct icmp*)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));
                        id = (ic->icmp_hun.ih_idseq.icd_id);
                        break;
                default:
                        goto to_gw;
        }


        for ( nCount = 0 ; nCount < 64 ; nCount++ )
        {
                if (portBouncingTable[nCount].age == 0)
                        continue;

                if (pkthdr->ph_proto != portBouncingTable[nCount].flowType)
                        continue;

                if (pkthdr->ph_dip != portBouncingTable[nCount].gatewayIpAddr)
                        continue;

                if (pkthdr->ph_sip == portBouncingTable[nCount].clientIpAddr)
                {
                        if( (((pkthdr->ph_proto == 5) ||(pkthdr->ph_proto == 6))) &&
                                (sport == portBouncingTable[nCount].clientPort) &&
                                (dport == portBouncingTable[nCount].gatewayPort))
                        {
                                if(pkthdr->ph_proto == 5)
                                {
                                        tc->th_dport = (portBouncingTable[nCount].serverPort);
                                        portBouncingTable[nCount].age =
                                                _rtl8651_portBouncingTcpMonitor(tc, &(portBouncingTable[nCount].tcpFlag), 1);
                                }else
                                {
                                        ud->uh_dport = (portBouncingTable[nCount].serverPort);
                                        portBouncingTable[nCount].age = rtl8651GlobalControl.udpTimeout;
                                }
                        }else if ((pkthdr->ph_proto == 3) && (id == portBouncingTable[nCount].id))
                        {
                                portBouncingTable[nCount].age = rtl8651GlobalControl.icmpTimeout;

                        }else
                        {
                                goto checkS2C;
                        }

                        pkthdr->ph_sip = pkthdr->ph_dip;
                        do{ *((uint8*)(&pip->ip_src)) = (uint8)((pkthdr->ph_sip)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((pkthdr->ph_sip)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((pkthdr->ph_sip)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((pkthdr->ph_sip)); }while(0);
                        pkthdr->ph_dip = portBouncingTable[nCount].serverIpAddr;
                        do{ *((uint8*)(&pip->ip_dst)) = (uint8)((pkthdr->ph_dip)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((pkthdr->ph_dip)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((pkthdr->ph_dip)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((pkthdr->ph_dip)); }while(0);
                        idx = nCount;
                        pb_entry = &(portBouncingTable[nCount]);
                        goto out;
                }
checkS2C:
                if (pkthdr->ph_sip == portBouncingTable[nCount].serverIpAddr)
                {
                        if (((pkthdr->ph_proto == 5) || (pkthdr->ph_proto == 6)) &&
                                (sport == portBouncingTable[nCount].serverPort) &&
                                (dport == portBouncingTable[nCount].clientPort))
                        {
                                if (pkthdr->ph_proto == 5)
                                {
                                        tc->th_sport = (portBouncingTable[nCount].gatewayPort);
                                        portBouncingTable[nCount].age =
                                                _rtl8651_portBouncingTcpMonitor(tc, &(portBouncingTable[nCount].tcpFlag), 0);
                                }else
                                {
                                        ud->uh_sport = (portBouncingTable[nCount].gatewayPort);
                                        portBouncingTable[nCount].age = rtl8651GlobalControl.udpTimeout;
                                }
                        }else if ((pkthdr->ph_proto == 3) && (id == portBouncingTable[nCount].id))
                        {
                                portBouncingTable[nCount].age = rtl8651GlobalControl.icmpTimeout;
                        }else
                        {
                                continue;
                        }

                        pkthdr->ph_sip = pkthdr->ph_dip;
                        do{ *((uint8*)(&pip->ip_src)) = (uint8)((pkthdr->ph_sip)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((pkthdr->ph_sip)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((pkthdr->ph_sip)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((pkthdr->ph_sip)); }while(0);
                        pkthdr->ph_dip = portBouncingTable[nCount].clientIpAddr;
                        do{ *((uint8*)(&pip->ip_dst)) = (uint8)((pkthdr->ph_dip)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((pkthdr->ph_dip)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((pkthdr->ph_dip)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((pkthdr->ph_dip)); }while(0);
                        idx = nCount;
                        pb_entry = &(portBouncingTable[nCount]);
                        goto out;
                }
        }

        {




                int32 local_val;
                rtl8651_tblDrv_vlanTable_t *local_vlanp = &DrvTbl.vlan[pkthdr->ph_vlanIdx];
                local_val = _rtl8651_ingressAcl(pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid, 0, local_vlanp, local_vlanp->vid, pkthdr->PKTHDRNXT.mbuf_first->m_data, (uint8 *) pip, 0x01, 0);
                if (((local_val > 0) && (local_val & 0x1000)) ||(local_val == 2))
                        return local_val;
        }



        if (idx == -1)
        {
                if (sip != nat->localIp)
                {
                        switch (pkthdr->ph_proto)
                        {
                                case 5:
                                        if ((pb_entry = _rtl8651_addPortBouncingEntry(5,
                                                sip, sport,
                                                dip, dport,
                                                nat->localIp, dport,
                                                0,
                                                2,
                                                rtl8651GlobalControl.tcpFastTimeout)) == ((void *)0))
                                        {
                                                goto drop;
                                        }
                                        break;
                                case 6:
                                        if ((pb_entry = _rtl8651_addPortBouncingEntry(6,
                                                sip, sport,
                                                dip, dport,
                                                nat->localIp, dport,
                                                0,
                                                0,
                                                rtl8651GlobalControl.udpTimeout)) == ((void *)0))
                                        {
                                                goto drop;
                                        }
                                        break;
                                case 3:
                                        switch(ic->icmp_type)
                                        {
                                                case 11:
                                                case 3:
                                                case 4:
                                                case 12:
                                                        goto icmp_errMsg;
                                        }
                                        if ((pb_entry = _rtl8651_addPortBouncingEntry(3,
                                                sip, 0,
                                                dip, 0,
                                                nat->localIp, 0,
                                                id,
                                                0,
                                                rtl8651GlobalControl.icmpTimeout)) == ((void *)0))
                                        {
                                                goto drop;
                                        }
                                        break;
                        }
                        pkthdr->ph_sip = pkthdr->ph_dip;
                        do{ *((uint8*)(&pip->ip_src)) = (uint8)((pkthdr->ph_sip)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((pkthdr->ph_sip)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((pkthdr->ph_sip)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((pkthdr->ph_sip)); }while(0);
                        pkthdr->ph_dip = nat->localIp;
                        do{ *((uint8*)(&pip->ip_dst)) = (uint8)((pkthdr->ph_dip)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((pkthdr->ph_dip)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((pkthdr->ph_dip)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((pkthdr->ph_dip)); }while(0);
                        goto out;
                }
        }

        goto icmp_errMsg;
out:
        {

                uint32 netIdx;
                int8 ret;
                rtl8651_tblDrv_networkIntfTable_t *netIface;

                ret = _rtl8651_extNetIpAddr(nat->globalIp, &netIdx);
                do {} while (0);
                netIface = &DrvTbl.netIface[netIdx];
                pkthdr->ph_vlanIdx = netIface->vid;
                pkthdr->ph_routeIdx = 0;
                pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid = 0;
                pkthdr->ph_portlist = 0;
        }

        if (((pip->ip_vhl & 0x0f) != 5) || (((pip->ip_off) & (0x2000|0x1fff)) == 0x2000))
        {
                if ((pip->ip_vhl & 0x0f) != 5)
                {
                        do { do { int32 accumulate = 0; if ((((pkthdr->ph_sip)) != 0) && (((sip)) != 0)){ accumulate = (((sip)) & 0xffff); accumulate += (( ((sip)) >> 16 ) & 0xffff); accumulate -= (((pkthdr->ph_sip)) & 0xffff); accumulate -= (( ((pkthdr->ph_sip)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                        do { do { int32 accumulate = 0; if ((((pkthdr->ph_dip)) != 0) && (((dip)) != 0)){ accumulate = (((dip)) & 0xffff); accumulate += (( ((dip)) >> 16 ) & 0xffff); accumulate -= (((pkthdr->ph_dip)) & 0xffff); accumulate -= (( ((pkthdr->ph_dip)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                }

                if (((pip->ip_off) & 0x1fff) == 0)
                {
                        if (pkthdr->ph_proto == 5)
                        {
                                do { int32 accumulate = 0; if (((pkthdr->ph_sip) != 0) && ((sip) != 0)){ accumulate = ((sip) & 0xffff); accumulate += (( (sip) >> 16 ) & 0xffff); accumulate -= ((pkthdr->ph_sip) & 0xffff); accumulate -= (( (pkthdr->ph_sip) >> 16 ) & 0xffff); } if (((tc->th_sport) != 0) && (((sport)) != 0)){ accumulate += ((sport)); accumulate -= (tc->th_sport); } do { accumulate += ((tc->th_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) accumulate); } } while (0); }while(0);
                                do { int32 accumulate = 0; if (((pkthdr->ph_dip) != 0) && ((dip) != 0)){ accumulate = ((dip) & 0xffff); accumulate += (( (dip) >> 16 ) & 0xffff); accumulate -= ((pkthdr->ph_dip) & 0xffff); accumulate -= (( (pkthdr->ph_dip) >> 16 ) & 0xffff); } if (((tc->th_dport) != 0) && (((dport)) != 0)){ accumulate += ((dport)); accumulate -= (tc->th_dport); } do { accumulate += ((tc->th_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (tc->th_sum) = ((uint16) accumulate); } } while (0); }while(0);
                        }else if ((pkthdr->ph_proto == 6) && (ud->uh_sum))
                        {
                                do { int32 accumulate = 0; if (((pkthdr->ph_sip) != 0) && ((sip) != 0)){ accumulate = ((sip) & 0xffff); accumulate += (( (sip) >> 16 ) & 0xffff); accumulate -= ((pkthdr->ph_sip) & 0xffff); accumulate -= (( (pkthdr->ph_sip) >> 16 ) & 0xffff); } if (((ud->uh_sport) != 0) && (((sport)) != 0)){ accumulate += ((sport)); accumulate -= (ud->uh_sport); } do { accumulate += ((ud->uh_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) accumulate); } } while (0); }while(0);
                                do { int32 accumulate = 0; if (((pkthdr->ph_dip) != 0) && ((dip) != 0)){ accumulate = ((dip) & 0xffff); accumulate += (( (dip) >> 16 ) & 0xffff); accumulate -= ((pkthdr->ph_dip) & 0xffff); accumulate -= (( (pkthdr->ph_dip) >> 16 ) & 0xffff); } if (((ud->uh_dport) != 0) && (((dport)) != 0)){ accumulate += ((dport)); accumulate -= (ud->uh_dport); } do { accumulate += ((ud->uh_sum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (ud->uh_sum) = ((uint16) accumulate); } } while (0); }while(0);
                        }


                        if ((((uint16)(pip->ip_off)) & (0x1fff|0x2000)))
                        {
                                _rtl8651_updateFragCache(2, sip, dip, (pip->ip_id), pkthdr->ph_dip, 0, ((void *)0), pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid);
                        }
                }
        }

        if (_rtl8651_l3ActRouting(pkthdr, pkthdr->ph_dip, pip) != 0)
        {
                goto drop;
        }
        return 0;
icmp_errMsg:
        if (pkthdr->ph_proto == 3)
        {
                if (_rtl8651_l34PortBouncingIcmpErrMsg(pkthdr, pip, ic) == 0)
                {
                        goto out;
                }
        }
        goto to_gw;

drop:
        if (pb_entry)
        {
                pb_entry->age = 0;
        }
        return 0x1000;
to_gw:

        return -1;
}

static inline uint32 _rtl8651_portBouncingTcpMonitor(struct tcphdr *tc, uint32 *currentState, int8 IsClientToServer)
{
        uint32 pktFlags;
        uint32 retval = 0;
        int8 *StateTable = ((void *)0);



        pktFlags = tc->th_flags & (0x04|0x02|0x01);
        do {} while (0);

        if (IsClientToServer == 1)
        {
                StateTable = (int8*)_outNextState;
        }
        else
        {
                StateTable = (int8*)_inNextState;
        }

        if(pktFlags & 0x04){
                *currentState = (8 - 1);
                retval = (rtl8651GlobalControl.tcpFastTimeout);
        }else if(pktFlags == 0){
resetage:

                retval = (*_ageTimer[(*currentState)+1]);
        }else if(pktFlags == 0x02){

                int8 state = StateTable[(8*0) + (*currentState)];
                do {} while (0);
                if(state > 0){
                        *currentState = (state - 1);
                        retval = *(_ageTimer[(int)state]);
                }else if(state == 0)
                        goto resetage;
        }else{

                int8 state = StateTable[(8*1) + (*currentState)];
                do {} while (0);
                if(state > 0){
                        *currentState = (state - 1);
                        retval = *(_ageTimer[(int)state]);
                }else if(state == 0)
                        goto resetage;
        }
        return retval;
}
# 16621 "rtl8651_tblDrvFwd.c"
static inline void _rtl8651_TriggerPort_FreeCache(uint8 isStatic, _rtl8651_triggerPort_cache_t *cache)
{

        do { if ((cache)->prev) {(cache)->prev->next=(cache)->next;} if ((cache)->next) {(cache)->next->prev=(cache)->prev;} if (*((cache)->hdr)==(cache)) {(*((cache)->hdr)=(cache)->next);} } while (0);;
        do { if (cache->lru_next) { cache->lru_next->lru_prev = cache->lru_prev; } if (cache->lru_prev) { cache->lru_prev->lru_next = cache->lru_next; } if (triggerPort_cache_lruHdr == cache) { triggerPort_cache_lruHdr = cache->lru_next; } if (triggerPort_cache_lruTail == cache) { triggerPort_cache_lruTail = cache->lru_prev; } cache->lru_next = cache->lru_prev = ((void *)0); } while (0);;


        if (isStatic == 0)
        {
                do { if ((cache)->entryList_prev){(cache)->entryList_prev->entryList_next=(cache)->entryList_next;} if ((cache)->entryList_next){(cache)->entryList_next->entryList_prev=(cache)->entryList_prev;} if ((cache)->entryHdr->normalCache==(cache)){(cache)->entryHdr->normalCache=(cache)->entryList_next;} } while (0);;
        }


        memset(cache, 0, sizeof(_rtl8651_triggerPort_cache_t));


        (cache)->next=(triggerPort_cache_freeList); (triggerPort_cache_freeList)=(cache);;
}






static inline _rtl8651_triggerPort_cache_t * _rtl8651_TriggerPort_getCache(void)
{
        _rtl8651_triggerPort_cache_t *cache = ((void *)0);

        if ( (triggerPort_cache_freeList == ((void *)0)) &&
                (triggerPort_cache_lruHdr) )
        {
                _rtl8651_TriggerPort_FreeCache((cache->entryHdr)?0:1, cache);
                do {} while (0);
        }


        (cache)=(triggerPort_cache_freeList); if (triggerPort_cache_freeList) {(triggerPort_cache_freeList)=(triggerPort_cache_freeList)->next;};

        return cache;
}






static inline void _rtl8651_TriggerPort_FreeEntry(_rtl8651_triggerPort_entry_t *entry)
{

        do { if ((entry)->prev) {(entry)->prev->next=(entry)->next;} if ((entry)->next) {(entry)->next->prev=(entry)->prev;} if (*((entry)->hdr)==(entry)) {(*((entry)->hdr)=(entry)->next);} } while (0);;


        while (entry->normalCache)
        {
                _rtl8651_TriggerPort_FreeCache(0, entry->normalCache);
        }


        (entry)->next=(triggerPort_entry_freeList); (triggerPort_entry_freeList)=(entry);;
}






static int32 _rtl8651_TriggerPortInit(rtl8651_fwdEngineInitPara_t *para)
{





        triggerPort_entry_tbl = ((void *)0);
        triggerPort_entry_freeList = ((void *)0);
        do { memset((triggerPort_entry_Hdr), 0, sizeof((triggerPort_entry_Hdr))); } while (0);;

        triggerPort_cache_tbl = ((void *)0);
        triggerPort_cache_freeList = ((void *)0);
        triggerPort_cache_staticEntry = ((void *)0);
        triggerPort_cache_lruHdr = ((void *)0);
        triggerPort_cache_lruTail = ((void *)0);
        do { memset((triggerPort_cache_hashTbl), 0, sizeof((triggerPort_cache_hashTbl))); } while (0);;

        triggerPort_entry_cnt = para->triggerPortEntryCnt;
        triggerPort_cache_cnt = para->triggerPortCacheSize;

        if ( (triggerPort_entry_cnt == 0) || (triggerPort_cache_cnt == 0) )
        {




                return 0;
        }



        do { triggerPort_entry_tbl = (void*)rtlglue_malloc(triggerPort_entry_cnt * sizeof(_rtl8651_triggerPort_entry_t)); if ( triggerPort_entry_tbl ) do { if (triggerPort_entry_cnt * sizeof(_rtl8651_triggerPort_entry_t)) { memset(triggerPort_entry_tbl, 0, triggerPort_entry_cnt * sizeof(_rtl8651_triggerPort_entry_t)); } } while (0);; } while (0);;

        if ( triggerPort_entry_tbl == ((void *)0) )
        {





                return -1;
        }



        do { triggerPort_cache_tbl = (void*)rtlglue_malloc(triggerPort_cache_cnt * sizeof(_rtl8651_triggerPort_cache_t)); if ( triggerPort_cache_tbl ) do { if (triggerPort_cache_cnt * sizeof(_rtl8651_triggerPort_cache_t)) { memset(triggerPort_cache_tbl, 0, triggerPort_cache_cnt * sizeof(_rtl8651_triggerPort_cache_t)); } } while (0);; } while (0);;

        if ( triggerPort_cache_tbl == ((void *)0) )
        {





                return -1;
        }

        _rtl8651_TriggerPortReinit();





        return 0;
}







static void _rtl8651_TriggerPortReinit(void)
{
        _rtl8651_triggerPort_entry_t *entry;
        _rtl8651_triggerPort_cache_t *cache;
        uint32 idx;





        if ( (triggerPort_entry_tbl == ((void *)0)) || (triggerPort_cache_tbl == ((void *)0)) )
        {




                return;
        }

        do { memset((triggerPort_entry_Hdr), 0, sizeof((triggerPort_entry_Hdr))); } while (0);;
        do { memset((triggerPort_cache_hashTbl), 0, sizeof((triggerPort_cache_hashTbl))); } while (0);;
        triggerPort_cache_staticEntry = ((void *)0);
        triggerPort_cache_lruHdr = ((void *)0);
        triggerPort_cache_lruTail = ((void *)0);
        do { if (triggerPort_entry_cnt * sizeof(_rtl8651_triggerPort_entry_t)) { memset(triggerPort_entry_tbl, 0, triggerPort_entry_cnt * sizeof(_rtl8651_triggerPort_entry_t)); } } while (0);;
        do { if (triggerPort_cache_cnt * sizeof(_rtl8651_triggerPort_cache_t)) { memset(triggerPort_cache_tbl, 0, triggerPort_cache_cnt * sizeof(_rtl8651_triggerPort_cache_t)); } } while (0);;


        entry = triggerPort_entry_freeList = triggerPort_entry_tbl;
        for ( idx=0 ; idx<(triggerPort_entry_cnt-1) ; idx++,entry++ )
        {
                entry->next = entry + 1;
        }


        cache = triggerPort_cache_freeList = triggerPort_cache_tbl;
        for ( idx=0 ; idx<(triggerPort_cache_cnt-1) ; idx++, cache++ )
        {
                cache->next = cache + 1;
        }





}
# 16814 "rtl8651_tblDrvFwd.c"
void rtl8651_flushTriggerPortRules(void)
{
        rtlglue_drvMutexLock();
        _rtl8651_flushNetTriggerPortRules(0);
        rtlglue_drvMutexUnlock();
}
# 16828 "rtl8651_tblDrvFwd.c"
void rtl8651a_flushNetTriggerPortRules(uint32 netIntfId)
{
        rtlglue_drvMutexLock();
        _rtl8651_flushNetTriggerPortRules(netIntfId);
        rtlglue_drvMutexUnlock();
}

static void _rtl8651_flushNetTriggerPortRules(uint32 netIntfId)
{
        uint32 index;
        _rtl8651_triggerPort_cache_t *cache, *next;






        for ( index=0 ; index<2 ; index++ )
        {
                _rtl8651_triggerPort_entry_t *entry;
                _rtl8651_triggerPort_entry_t *next;

                entry = triggerPort_entry_Hdr[index];

                while ( entry )
                {
                        next = entry->next;

                        if ( entry->netIntfId == netIntfId )
                        {
                                _rtl8651_TriggerPort_FreeEntry(entry);
                        }
                        entry = next;
                }
        }


        cache = triggerPort_cache_staticEntry;
        while ( cache )
        {
                next = cache->next;

                if ( cache->netIntfId == netIntfId )
                {
# 16881 "rtl8651_tblDrvFwd.c"
                        _rtl8651_TriggerPort_FreeCache(1, cache);
                }
                cache = next;
        }

}
# 16973 "rtl8651_tblDrvFwd.c"
int32 rtl8651_addTriggerPortMappingRule (
        uint32 netIntfId,
        uint8 inType,
        uint16 inPortStart,
        uint16 inPortEnd,
        _rtl8651_triggerPort_param_t *mappingInfo)
{
        int32 retval;

        if ( (netIntfId >= 2) ||
                (inPortStart > inPortEnd) ||
                (mappingInfo == ((void *)0)))
        {
                return -1;
        }
        rtlglue_drvMutexLock();
        retval = _rtl8651_addTriggerPortRule( netIntfId,
                                                                                inType,
                                                                                inPortStart,
                                                                                inPortEnd,
                                                                                mappingInfo);
        rtlglue_drvMutexUnlock();
        return retval;
}
# 17029 "rtl8651_tblDrvFwd.c"
int32 rtl8651_addTriggerPortRule(
        uint8 inType, uint16 inPortStart, uint16 inPortEnd,
        uint8 outType,uint16 outPortStart,uint16 outPortEnd,
        ipaddr_t localIpAddr)
{
        return rtl8651a_addTriggerPortRule( 0,
                                                                                inType,
                                                                                inPortStart,
                                                                                inPortEnd,
                                                                                outType,
                                                                                outPortStart,
                                                                                outPortEnd,
                                                                                localIpAddr);
}
# 17076 "rtl8651_tblDrvFwd.c"
int32 rtl8651a_addTriggerPortRule(
        uint32 netIntfId,
        uint8 inType, uint16 inPortStart, uint16 inPortEnd,
        uint8 outType,uint16 outPortStart,uint16 outPortEnd,
        ipaddr_t localIpAddr)
{
        int32 retval;
        _rtl8651_triggerPort_param_t mapInfo;


        if (localIpAddr)
        {
                mapInfo.isStaticMapping = 1;
                mapInfo.age = 0;

                mapInfo.UN_MAPPING.STATIC_MAPPING.__isStatic = 1;
                mapInfo.UN_MAPPING.STATIC_MAPPING.__mappedInsideLocalIpAddr = localIpAddr;
        } else
        {
                mapInfo.isStaticMapping = 0;
                mapInfo.age = 3600;

                mapInfo.UN_MAPPING.DYNAMIC_MAPPING.__outType = outType;
                mapInfo.UN_MAPPING.DYNAMIC_MAPPING.__outPortStart = outPortStart;
                mapInfo.UN_MAPPING.DYNAMIC_MAPPING.__outPortEnd = outPortEnd;
                mapInfo.UN_MAPPING.DYNAMIC_MAPPING.__triggeringInsideLocalIpAddrStart = 0;
                mapInfo.UN_MAPPING.DYNAMIC_MAPPING.__triggeringInsideLocalIpAddrEnd = 0;
        }

        rtlglue_drvMutexLock();
        retval = _rtl8651_addTriggerPortRule( netIntfId,
                                                                                inType,
                                                                                inPortStart,
                                                                                inPortEnd,
                                                                                &mapInfo);
        rtlglue_drvMutexUnlock();
        return retval;
}






static int32 _rtl8651_addTriggerPortRule(
        uint32 netIntfId,
        uint8 inType, uint16 inPortStart, uint16 inPortEnd,
        _rtl8651_triggerPort_param_t *mappingInfo)

{
        do {} while (0);
        do {} while (0);
# 17148 "rtl8651_tblDrvFwd.c"
        if ( mappingInfo->isStaticMapping == 1 )
        {
                _rtl8651_triggerPort_cache_t *cache;


                cache = triggerPort_cache_staticEntry;

                while ( cache )
                {
                        if ( (cache->netIntfId==netIntfId) &&
                              (cache->inPortStart==inPortStart) &&
                              (cache->inPortEnd==inPortEnd))
                        {
                                if ( cache->inType==inType )
                                {
                                        goto updateCache;
                                } else if ((cache->inType==2)||(inType==2))
                                {
                                        goto errout;
                                }
                        }

                        if ( (!(cache->inPortStart>inPortEnd||cache->inPortEnd<inPortStart)) &&
                              (cache->inType==inType||cache->inType==2||inType==2))
                        {
                                goto errout;
                        }

                        cache = cache->next;
                }


                if ( (cache = _rtl8651_TriggerPort_getCache()) == ((void *)0) )
                {
                        goto errout;
                }

                do { (cache)->hdr=&(triggerPort_cache_staticEntry); (cache)->next=(triggerPort_cache_staticEntry); (cache)->prev=((void *)0); if (triggerPort_cache_staticEntry){((triggerPort_cache_staticEntry)->prev=(cache));} (triggerPort_cache_staticEntry)=(cache); } while (0);;

                cache->ExternalIpAddr = 0;
                cache->netIntfId = netIntfId;
                cache->inPortStart = inPortStart;
                cache->inPortEnd = inPortEnd;
                cache->inType = inType;
updateCache:
                cache->isStatic = mappingInfo->UN_MAPPING.STATIC_MAPPING.__isStatic;
                cache->localIpAddr = mappingInfo->UN_MAPPING.STATIC_MAPPING.__mappedInsideLocalIpAddr;
                cache->age = mappingInfo->age;
                cache->maxAge = mappingInfo->age;


                do { if (cache->lru_next) { cache->lru_next->lru_prev = cache->lru_prev; } if (cache->lru_prev) { cache->lru_prev->lru_next = cache->lru_next; } if (triggerPort_cache_lruHdr == cache) { triggerPort_cache_lruHdr = cache->lru_next; } if (triggerPort_cache_lruTail == cache) { triggerPort_cache_lruTail = cache->lru_prev; } cache->lru_next = cache->lru_prev = ((void *)0); } while (0);;
                if (mappingInfo->UN_MAPPING.STATIC_MAPPING.__isStatic == 0)
                {
                        do { if (triggerPort_cache_lruTail) { triggerPort_cache_lruTail->lru_next = cache; } else { triggerPort_cache_lruHdr = cache; } cache->lru_prev = triggerPort_cache_lruTail; cache->lru_next = ((void *)0); triggerPort_cache_lruTail = cache; } while (0);;
                }
        } else
        {
                _rtl8651_triggerPort_entry_t *entry;

                if ( (mappingInfo->UN_MAPPING.DYNAMIC_MAPPING.__outPortStart > mappingInfo->UN_MAPPING.DYNAMIC_MAPPING.__outPortEnd) ||
                        (mappingInfo->UN_MAPPING.DYNAMIC_MAPPING.__triggeringInsideLocalIpAddrStart > mappingInfo->UN_MAPPING.DYNAMIC_MAPPING.__triggeringInsideLocalIpAddrEnd))
                {
                        goto errout;
                }


                entry = triggerPort_entry_Hdr[netIntfId];

                while ( entry )
                {
                        if ( (entry->netIntfId==netIntfId) &&
                                (entry->outPortStart==mappingInfo->UN_MAPPING.DYNAMIC_MAPPING.__outPortStart) &&
                                (entry->outPortEnd==mappingInfo->UN_MAPPING.DYNAMIC_MAPPING.__outPortEnd) &&
                                (entry->outType==mappingInfo->UN_MAPPING.DYNAMIC_MAPPING.__outType) &&
                                (entry->triggeringInsideLocalIpAddrStart==mappingInfo->UN_MAPPING.DYNAMIC_MAPPING.__triggeringInsideLocalIpAddrStart) &&
                                (entry->triggeringInsideLocalIpAddrEnd==mappingInfo->UN_MAPPING.DYNAMIC_MAPPING.__triggeringInsideLocalIpAddrEnd) &&
                                (entry->inPortStart==inPortStart) &&
                                (entry->inPortEnd==inPortEnd))
                        {
                                if (entry->inType != inType)
                                {
                                        entry->inType = 2;
                                }
                                goto out;
                        }
                        entry = entry->next;
                }


                (entry)=(triggerPort_entry_freeList); if (triggerPort_entry_freeList) {(triggerPort_entry_freeList)=(triggerPort_entry_freeList)->next;};
                if ( entry==((void *)0) )
                {
                        goto errout;
                }

                entry->netIntfId = netIntfId;
                entry->outType = mappingInfo->UN_MAPPING.DYNAMIC_MAPPING.__outType;
                entry->outPortStart = mappingInfo->UN_MAPPING.DYNAMIC_MAPPING.__outPortStart;
                entry->outPortEnd = mappingInfo->UN_MAPPING.DYNAMIC_MAPPING.__outPortEnd;
                entry->triggeringInsideLocalIpAddrStart = mappingInfo->UN_MAPPING.DYNAMIC_MAPPING.__triggeringInsideLocalIpAddrStart;
                entry->triggeringInsideLocalIpAddrEnd = mappingInfo->UN_MAPPING.DYNAMIC_MAPPING.__triggeringInsideLocalIpAddrEnd;
                entry->inType = inType;
                entry->inPortStart = inPortStart;
                entry->inPortEnd = inPortEnd;
                entry->cacheAge = mappingInfo->age;
                entry->normalCache = ((void *)0);

                do { (entry)->hdr=&(triggerPort_entry_Hdr[netIntfId]); (entry)->next=(triggerPort_entry_Hdr[netIntfId]); (entry)->prev=((void *)0); if (triggerPort_entry_Hdr[netIntfId]){((triggerPort_entry_Hdr[netIntfId])->prev=(entry));} (triggerPort_entry_Hdr[netIntfId])=(entry); } while (0);;
        }
out:




        return 0;
errout:





        return -1;
}

static inline int32 _rtl8651_checkUsableTriggeredPortEntry(uint32 isTcp, uint32 netIntfId, ipaddr_t intIp, uint32 extPort)
{
        _rtl8651_triggerPort_cache_t *cache, *candidate = ((void *)0);
        uint32 hashTblIdx;
# 17286 "rtl8651_tblDrvFwd.c"
        for ( hashTblIdx = 0 ; hashTblIdx < 8 ; hashTblIdx ++ )
        {
                cache = triggerPort_cache_hashTbl[hashTblIdx];

                while ( cache )
                {
                        if ( (cache->netIntfId == netIntfId) &&
                                (cache->inPortStart<=extPort) &&
                                (cache->inPortEnd>=extPort) &&
                                (cache->inType==2 || (isTcp&&cache->inType==0) || ((!isTcp)&&cache->inType==1)))
                        {
                                if (cache->localIpAddr==intIp)
                                {



                                        return 1;
                                }
                                candidate = cache;
                        }

                        cache = cache->next;
                }
        }

        if (candidate)
        {



                return 0;
        }





        return 1;

}







static inline _rtl8651_triggerPort_cache_t *_rtl8651_getTriggerPortCache(uint8 refreshAge, uint8 isTcp, uint32 netIntfId, ipaddr_t extIp, uint16 extPort)
{
        _rtl8651_triggerPort_cache_t *cache;
        uint32 hash = (((uint32)(netIntfId) + (uint32)(extIp)) & ((8) - 1));
# 17347 "rtl8651_tblDrvFwd.c"
        cache = triggerPort_cache_hashTbl[hash];
        while ( cache )
        {
                if ( (cache->netIntfId==netIntfId) &&
                      (cache->ExternalIpAddr==extIp) &&
                      (cache->inPortStart<=extPort) &&
                      (cache->inPortEnd>=extPort) &&
                      (cache->inType==2||(isTcp&&cache->inType==0)||(!isTcp&&cache->inType==1)))
                {
                        goto found;
                }
                cache = cache->next;
        }


        cache = triggerPort_cache_staticEntry;
        while ( cache )
        {
                if ( (cache->netIntfId==netIntfId) &&
                      (cache->inPortStart<=extPort) &&
                      (cache->inPortEnd>=extPort) &&
                      (cache->inType==2||(isTcp&&cache->inType==0)||(!isTcp&&cache->inType==1)))
                {
                        goto found;
                }
                cache = cache->next;
        }





        return ((void *)0);

found:




        if (refreshAge == 1)
        {

                if (cache->isStatic == 0)
                {
                        do { do { if (cache->lru_next) { cache->lru_next->lru_prev = cache->lru_prev; } if (cache->lru_prev) { cache->lru_prev->lru_next = cache->lru_next; } if (triggerPort_cache_lruHdr == cache) { triggerPort_cache_lruHdr = cache->lru_next; } if (triggerPort_cache_lruTail == cache) { triggerPort_cache_lruTail = cache->lru_prev; } cache->lru_next = cache->lru_prev = ((void *)0); } while (0);; do { if (triggerPort_cache_lruTail) { triggerPort_cache_lruTail->lru_next = cache; } else { triggerPort_cache_lruHdr = cache; } cache->lru_prev = triggerPort_cache_lruTail; cache->lru_next = ((void *)0); triggerPort_cache_lruTail = cache; } while (0);; } while (0);;
                }

                cache->age = cache->maxAge;
        }

        return cache;

}
# 17409 "rtl8651_tblDrvFwd.c"
static inline void _rtl8651_addTriggerPortCache(_rtl8651_triggerPort_entry_t *entry, ipaddr_t extIp, ipaddr_t localIpAddr)
{
        _rtl8651_triggerPort_cache_t *cache;
        uint32 hash = (((uint32)((entry->netIntfId)) + (uint32)(extIp)) & ((8) - 1));
# 17423 "rtl8651_tblDrvFwd.c"
        cache = entry->normalCache;
        while ( cache )
        {
                if ( (cache->netIntfId==entry->netIntfId) &&
                      (cache->ExternalIpAddr==extIp) &&
                      (cache->inPortStart==entry->inPortStart) &&
                      (cache->inPortEnd>=entry->inPortEnd) &&
                      (cache->inType==entry->inType||cache->inType==2||entry->inType==2))
                {





                        goto updateCache;
                }
                cache = cache->entryList_next;
        }


        if ( (cache = _rtl8651_TriggerPort_getCache()) == ((void *)0) )
        {





                return;
        }





        do { (cache)->hdr=&(triggerPort_cache_hashTbl[hash]); (cache)->next=(triggerPort_cache_hashTbl[hash]); (cache)->prev=((void *)0); if (triggerPort_cache_hashTbl[hash]){((triggerPort_cache_hashTbl[hash])->prev=(cache));} (triggerPort_cache_hashTbl[hash])=(cache); } while (0);;
        do { (cache)->entryHdr=(entry); (cache)->entryList_next=(entry)->normalCache; (cache)->entryList_prev=((void *)0); if ((entry)->normalCache){(entry)->normalCache->entryList_prev=(cache);} (entry)->normalCache=(cache); } while (0);;

        cache->ExternalIpAddr = extIp;
        cache->netIntfId = entry->netIntfId;
        cache->inPortStart = entry->inPortStart;
        cache->inPortEnd = entry->inPortEnd;
        cache->inType = entry->inType;
        cache->isStatic = 0;
updateCache:
        cache->localIpAddr = localIpAddr;
        cache->maxAge = cache->age = entry->cacheAge;


        do { do { if (cache->lru_next) { cache->lru_next->lru_prev = cache->lru_prev; } if (cache->lru_prev) { cache->lru_prev->lru_next = cache->lru_next; } if (triggerPort_cache_lruHdr == cache) { triggerPort_cache_lruHdr = cache->lru_next; } if (triggerPort_cache_lruTail == cache) { triggerPort_cache_lruTail = cache->lru_prev; } cache->lru_next = cache->lru_prev = ((void *)0); } while (0);; do { if (triggerPort_cache_lruTail) { triggerPort_cache_lruTail->lru_next = cache; } else { triggerPort_cache_lruHdr = cache; } cache->lru_prev = triggerPort_cache_lruTail; cache->lru_next = ((void *)0); triggerPort_cache_lruTail = cache; } while (0);; } while (0);;





}
# 17489 "rtl8651_tblDrvFwd.c"
static inline int32 _rtl8651_tryActiveTriggerPort(uint8 isTcp, uint32 netIntfId, uint16 outPort, ipaddr_t extIp, ipaddr_t localIpAddr)
{
        _rtl8651_triggerPort_entry_t *entry;
# 17502 "rtl8651_tblDrvFwd.c"
        entry = triggerPort_entry_Hdr[netIntfId];

        while ( entry )
        {
# 17517 "rtl8651_tblDrvFwd.c"
                if ( (entry->outPortStart<=outPort) &&
                        (entry->outPortEnd>=outPort) &&
                        ( (entry->triggeringInsideLocalIpAddrStart==0 && entry->triggeringInsideLocalIpAddrEnd==0)||
                                (entry->triggeringInsideLocalIpAddrStart<=localIpAddr&&entry->triggeringInsideLocalIpAddrEnd>=localIpAddr)) &&
                        ((isTcp&&entry->outType==0)||((!isTcp)&&entry->outType==1)||(entry->outType==2)) &&
                        (entry->netIntfId==netIntfId) )
                {






                        _rtl8651_addTriggerPortCache(entry, extIp, localIpAddr);
                        return 1;
                }
                entry = entry->next;
        }





        return 0;
}






static inline int32 _rtl8651_getTriggeredIpAddr(uint8 isTcp, uint32 netIntfId, ipaddr_t extIp, uint16 inPort, ipaddr_t *localIpAddrp)
{
        _rtl8651_triggerPort_cache_t *cache;
# 17560 "rtl8651_tblDrvFwd.c"
        cache = _rtl8651_getTriggerPortCache(1, isTcp, netIntfId, extIp, inPort);
        if ( cache )
        {





                *localIpAddrp = cache->localIpAddr;
                return 0;
        }
        return -1;
}






static void _rtl8651_TriggerPortTimeUpdate(uint32 secPassed)
{
        uint32 idx;
        _rtl8651_triggerPort_cache_t *cache;
        _rtl8651_triggerPort_cache_t *next;


        for ( idx=0;idx<8;idx++ )
        {
                cache = triggerPort_cache_hashTbl[idx];
                while( cache )
                {
                        next = cache->next;

                        if (cache->age == 0)
                        {


                        } else if (cache->age>secPassed )
                        {
                                cache->age -= secPassed;
                        }else
                        {
# 17611 "rtl8651_tblDrvFwd.c"
                                _rtl8651_TriggerPort_FreeCache(0, cache);
                        }
                        cache = next;
                }
        }

        cache = triggerPort_cache_staticEntry;
        while ( cache )
        {
                next = cache->next;
                if (cache->age == 0)
                {


                } else if ( cache->age>secPassed )
                {
                        cache->age -= secPassed;
                }else
                {
# 17639 "rtl8651_tblDrvFwd.c"
                        _rtl8651_TriggerPort_FreeCache(1, cache);
                }
                cache = next;
        }
}





static int32 _rtl8651_queueInit(void){
        queue_packet_tb = (struct _RTL8651_QUEUE_PACKET_ENTRY *)rtlglue_malloc(32 * sizeof (struct _RTL8651_QUEUE_PACKET_ENTRY));
        memset(queue_packet_tb,0,32 * sizeof (struct _RTL8651_QUEUE_PACKET_ENTRY));
        return 0;
}

static int32 _rtl8651_queueReinit(void){
        memset(queue_packet_tb,0,32 * sizeof (struct _RTL8651_QUEUE_PACKET_ENTRY));
        return 0;
}



static int32 _rtl8651_enQueuePacket(struct rtl_pktHdr * pkthdrPtr, struct ip* ip, ipaddr_t waitIp, uint8 type){
        int32 i;
        struct _RTL8651_QUEUE_PACKET_ENTRY *tb;
        tb = queue_packet_tb;
# 17678 "rtl8651_tblDrvFwd.c"
        tb = queue_packet_tb;
        for(i = 0 ; i < 32 ; i++){
                if(tb->q_time== 0 &&
                        tb->q_pkthdrPtr == ((void *)0)){
                           struct rtl_pktHdr *newPh=((void *)0);
                           struct rtl_mBuf *newmb=((void *)0), *oldMbuf;
                           uint8 *newCluster, *newClusterData;
                           uint32 newClusterId;
                           int16 rxdesc;

                        if (pkthdrPtr->ph_rxdesc<0)
                        {
                                newPh = pkthdrPtr;
                        }else
                        {
                                oldMbuf=pkthdrPtr->PKTHDRNXT.mbuf_first;


                                if((newmb = mBuf_get(0x02,0x01, 1)) == ((void *)0)){

                                        return -1;
                                }
                                if((mBuf_getPkthdr(newmb, 0x02) == (struct rtl_mBuf *) ((void *)0))||
                                        (mBuf_reserve(newmb,rtl8651_fwdEnginePara.mbufHeadroom))){

                                        mBuf_freeMbufChain(newmb);
                                        return -1;
                                }
                                do {} while (0);
                                newPh=newmb->m_pkthdr;
                                newCluster=newmb->m_extbuf;
                                newClusterData=newmb->m_data;
                                newClusterId=newmb->m_extClusterId;
                                do {} while (0);

                                *newmb=*oldMbuf;
                                newmb->m_next=((void *)0);
                                newmb->m_pkthdr=newPh;

                                rxdesc = newPh->ph_rxdesc;
                                *newPh=*pkthdrPtr;
                                newPh->PKTHDRNXT.mbuf_first=newmb;
                                newPh->ph_rxdesc=rxdesc;

                                oldMbuf->m_extClusterId=newClusterId;
                                oldMbuf->m_data=newClusterData;
                                oldMbuf->m_extbuf=newCluster;
                                oldMbuf->m_len=0;
                                mBuf_freeMbufChain(oldMbuf);
                        }

                        tb->q_time=3;
                        tb->q_waitIp = waitIp;
                        tb->q_type = type;
                        tb->q_id = (ip->ip_id);
                        tb->q_ip = ip;
                        tb->q_pkthdrPtr = newPh;

                        return 0;
                }
                tb++;
        }
        return -1;
}

static struct rtl_pktHdr * _rtl8651_queryQuenePacket(struct ip* ip, uint8 type,
                                        uint32 *dst_ip, struct ip **ipp){
        int32 i;
        struct rtl_pktHdr * pkt;
        struct _RTL8651_QUEUE_PACKET_ENTRY *tb;

        tb = queue_packet_tb;
        for(i = 0 ; i < 32 ; i++){
                if(tb->q_time && tb->q_type == type && tb->q_pkthdrPtr){
                        switch(type){
                        case 1:
                                if(memcmp(&tb->q_waitIp, &ip->ip_dst, 4) == 0 ){
                                        pkt = tb->q_pkthdrPtr;
                                        if(dst_ip)
                                        {
                                                *dst_ip = ((uint32) (*((uint8*)(&tb->q_ip->ip_dst))<<24)|(*(((uint8*)(&tb->q_ip->ip_dst))+1)<<16)|(*(((uint8*)(&tb->q_ip->ip_dst))+2)<<8) | *(((uint8*)(&tb->q_ip->ip_dst))+3));
                                        }
                                        if(ipp)
                                        {
                                                *ipp = tb->q_ip;
                                        }
                                        memset(tb,0, sizeof(struct _RTL8651_QUEUE_PACKET_ENTRY));
                                        return pkt;
                                }
                                break;
                        }
                }
                tb++;
        }
        return ((void *)0);
}


static int32 _rtl8651_queuePacketSecondTimer(void){
        int32 i;
        struct rtl_pktHdr * pkt;
        struct _RTL8651_QUEUE_PACKET_ENTRY *tb;
        tb = queue_packet_tb;

        for(i = 0 ; i < 32 ; i++){
                if(tb->q_time)
                        tb->q_time--;

                if(tb->q_time == 0 && tb->q_pkthdrPtr){
                        pkt = tb->q_pkthdrPtr;
                        tb->q_pkthdrPtr = ((void *)0);
                        tb->q_type = 0;
                        tb->q_id = 0;
                        tb->q_ip = ((void *)0);
                        mBuf_freeMbufChain(pkt->PKTHDRNXT.mbuf_first);
                }
                tb++;
        }

        return 0;
}





void _rtl8651_freeAllPppoeActiveSession(void) {
        _rtl8651_pppoeActiveSession_entry_t * tempPtr;
        while(pppoeActiveSessionHead) {
                tempPtr = pppoeActiveSessionHead;
                pppoeActiveSessionHead = pppoeActiveSessionHead->next;
                tempPtr->next = pppoeFreeActiveSession;
                pppoeFreeActiveSession = tempPtr;
        }
}

void _rtl8651_updatePppoeActiveSession(uint16 pppoeSessionId) {
        _rtl8651_pppoeActiveSession_entry_t * tempActivePppoeSessionPtr, * trackingActivePppoeSessionPtr, * removedActivePppoeSessionPtr=((void *)0);
        uint16 smallestKeepAlive;


        smallestKeepAlive = 0xFFFF;
        tempActivePppoeSessionPtr = pppoeActiveSessionHead;
        while (tempActivePppoeSessionPtr) {
                if(tempActivePppoeSessionPtr->keepAlive == 0) {
                        if(tempActivePppoeSessionPtr == pppoeActiveSessionHead) {
                                pppoeActiveSessionHead = pppoeActiveSessionHead->next;
                                removedActivePppoeSessionPtr = tempActivePppoeSessionPtr;
                                tempActivePppoeSessionPtr = tempActivePppoeSessionPtr->next;
                        } else {
                                trackingActivePppoeSessionPtr = pppoeActiveSessionHead;
                                while(trackingActivePppoeSessionPtr->next) {
                                        if(trackingActivePppoeSessionPtr->next == tempActivePppoeSessionPtr) {
                                                trackingActivePppoeSessionPtr->next = trackingActivePppoeSessionPtr->next->next;
                                                removedActivePppoeSessionPtr = tempActivePppoeSessionPtr;
                                                tempActivePppoeSessionPtr = trackingActivePppoeSessionPtr->next;
                                                break;
                                        }
                                        trackingActivePppoeSessionPtr = trackingActivePppoeSessionPtr->next;
                                }
                                do {} while (0);
                        }
                        removedActivePppoeSessionPtr->next = pppoeFreeActiveSession;
                        pppoeFreeActiveSession = removedActivePppoeSessionPtr;
                }
                else {
                        tempActivePppoeSessionPtr->keepAlive--;
                        if(smallestKeepAlive > tempActivePppoeSessionPtr->keepAlive)
                                smallestKeepAlive = tempActivePppoeSessionPtr->keepAlive;
                        tempActivePppoeSessionPtr = tempActivePppoeSessionPtr->next;
                }
        }

        tempActivePppoeSessionPtr = pppoeActiveSessionHead;
        while(tempActivePppoeSessionPtr) {
                if(tempActivePppoeSessionPtr->sessionId == pppoeSessionId)
                        break;
                tempActivePppoeSessionPtr = tempActivePppoeSessionPtr->next;
        }
        if(tempActivePppoeSessionPtr == ((void *)0)) {
                if(pppoeFreeActiveSession) {
                        tempActivePppoeSessionPtr = pppoeFreeActiveSession;
                        pppoeFreeActiveSession = pppoeFreeActiveSession->next;
                        tempActivePppoeSessionPtr->next = pppoeActiveSessionHead;
                        pppoeActiveSessionHead = tempActivePppoeSessionPtr;
                }
                else {
                        trackingActivePppoeSessionPtr = pppoeActiveSessionHead;
                        while(trackingActivePppoeSessionPtr) {
                                if(trackingActivePppoeSessionPtr->keepAlive == smallestKeepAlive) {
                                        tempActivePppoeSessionPtr = trackingActivePppoeSessionPtr;
                                        break;
                                }
                                trackingActivePppoeSessionPtr = trackingActivePppoeSessionPtr->next;
                        }
                }
                tempActivePppoeSessionPtr->sessionId = pppoeSessionId;
        }
        tempActivePppoeSessionPtr->keepAlive = 0xFFFF;

}

void _rtl8651_terminatePppoeActiveSession(uint16 pppoeSessionId) {
        _rtl8651_pppoeActiveSession_entry_t * tempActivePppoeSessionPtr, * trackingActivePppoeSessionPtr;


        tempActivePppoeSessionPtr = pppoeActiveSessionHead;
        while(tempActivePppoeSessionPtr) {
                if(tempActivePppoeSessionPtr->sessionId == pppoeSessionId)
                        break;
                tempActivePppoeSessionPtr = tempActivePppoeSessionPtr->next;
        }
        if(tempActivePppoeSessionPtr) {
                if(tempActivePppoeSessionPtr == pppoeActiveSessionHead) {
                        pppoeActiveSessionHead = pppoeActiveSessionHead->next;
                } else {
                        trackingActivePppoeSessionPtr = pppoeActiveSessionHead;
                        while(trackingActivePppoeSessionPtr->next) {
                                if(trackingActivePppoeSessionPtr->next == tempActivePppoeSessionPtr) {
                                        trackingActivePppoeSessionPtr->next = trackingActivePppoeSessionPtr->next->next;
                                        break;
                                }
                                trackingActivePppoeSessionPtr = trackingActivePppoeSessionPtr->next;
                        }
                }
                tempActivePppoeSessionPtr->next = pppoeFreeActiveSession;
                pppoeFreeActiveSession = tempActivePppoeSessionPtr;
        }
}
# 17916 "rtl8651_tblDrvFwd.c"
inline int32 _rtl8651_pppoeSessionActive(uint16 pppoeSessionId) {
        _rtl8651_pppoeActiveSession_entry_t * tempActivePppoeSessionPtr;

        tempActivePppoeSessionPtr = pppoeActiveSessionHead;
        while(tempActivePppoeSessionPtr) {
                if(tempActivePppoeSessionPtr->sessionId == pppoeSessionId)
                        break;
                tempActivePppoeSessionPtr = tempActivePppoeSessionPtr->next;
        }
        if(tempActivePppoeSessionPtr)
                return 1;
        return 0;
}
# 17937 "rtl8651_tblDrvFwd.c"
uint16 * _rtl8651_getNextPppoeActiveSession(uint16 *curPppoeSessionId, uint16 * nextPppoeSessionId) {
        _rtl8651_pppoeActiveSession_entry_t * tempActivePppoeSessionPtr;

        if(nextPppoeSessionId == ((void *)0))
                return ((void *)0);
        if(curPppoeSessionId == ((void *)0)) {
                if(pppoeActiveSessionHead) {
                        *nextPppoeSessionId = pppoeActiveSessionHead->sessionId;
                        return nextPppoeSessionId;
                }
                return ((void *)0);
        }

        tempActivePppoeSessionPtr = pppoeActiveSessionHead;
        while(tempActivePppoeSessionPtr) {
                if(tempActivePppoeSessionPtr->sessionId == *curPppoeSessionId) {
                        if(tempActivePppoeSessionPtr->next) {
                                *nextPppoeSessionId = tempActivePppoeSessionPtr->next->sessionId;
                                return nextPppoeSessionId;
                        }
                        return ((void *)0);
                }
                tempActivePppoeSessionPtr = tempActivePppoeSessionPtr->next;
        }
        return ((void *)0);
}







static inline void _rtl8651_fragmentShortestPathCacheSet_firstHalf(struct rtl_pktHdr *pkthdr, uint8*l4hdr, struct ip *pip, ipaddr_t sip, ipaddr_t dip, uint32 mode, ipaddr_t aliasIp)
{
        uint16 idx = ((sip+dip+(pip->ip_id))&(32 -1));


        pkthdr->ph_un_sw.ROMEDRV_USG._ph_fragOffset = idx;
# 17991 "rtl8651_tblDrvFwd.c"
        if ((_rtl8651_dos_enable == 1) && (_rtl8651_dosIgnoreTypeCheck(((mode==0)?0:1)) == 0))
        {
                if (pip->ip_p == 17)
                {
                        if (_rtl8651_dos_sw[pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid] & (0x00000800|0x00000040|0x00001000|0x00000008|0x00020000))
                                return;
                }else
                {
                        struct tcphdr *tc;

                        do {} while (0);

                        tc = (struct tcphdr *)l4hdr;
                        if ((tc->th_flags & 0x02) && (_rtl8651_dos_sw[pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid] & (0x00000800|0x00000040|0x00000001|0x00004000)))
                        {
                                return;
                        }else if ((tc->th_flags & 0x01) && (_rtl8651_dos_sw[pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid] & (0x00000800|0x00000040|0x00000002|0x00008000)))
                        {
                                return;
                        }
                }
        }





        if ((pip->ip_p == 17) && (_rtl8651_udpSizeThreshValue[pkthdr->ph_un_sw.ROMEDRV_USG._ph_dsid] != 0xffff))
                return;


        if ((((*(uint8*)pip)&0xf) == 5))
        {
                _rtl8651_FragmentShortestPathFwdCache_t *cache;


                cache = &(fragmentShortestPathCache[idx]);

                cache->sip = sip;
                cache->dip = dip;
                cache->id = (pip->ip_id);
                cache->aliasIp = aliasIp;
                cache->mode = mode;
                cache->status = 1;
        }
}



inline void _rtl8651_fragmentShortestPathCacheSet_secondHalf(struct rtl_pktHdr *pkthdr, uint8 *m_data, struct ip*pip)
{
        if ((((uint16)(pip->ip_off)) & (0x1fff|0x2000)) && ((((*(uint8*)pip)&0xf) == 5)))
        {
                _rtl8651_FragmentShortestPathFwdCache_t *cache;


                cache = &(fragmentShortestPathCache[(pkthdr->ph_un_sw.ROMEDRV_USG._ph_fragOffset&(32 -1))]);

                if (cache->status == 1)
                {
                        rtl8651_memcpy(&cache->dmac, (void*)m_data, 6);
                        rtl8651_memcpy(&cache->smac, (void*)(m_data + 6), 6);

                        cache->vlanIdx = pkthdr->ph_vlanIdx;
                        cache->portList = pkthdr->ph_portlist;
                        cache->pppoeIdx = pkthdr->ph_pppoeIdx;
                        cache->extPortList = pkthdr->ph_extPortList;
                        cache->srcExtPortNum = pkthdr->ph_srcExtPortNum;
                        cache->flags = (pkthdr->ph_flags & 0x000f);
                        cache->status = 2;
                        cache->age = 3;
                }
        }
}



inline void _rtl8651_fragmentShortestPathCache_clear(struct rtl_pktHdr *pkthdr, struct ip*pip)
{
        if ((((uint16)(pip->ip_off)) & (0x1fff|0x2000)) && ((((*(uint8*)pip)&0xf) == 5)))
        {
                _rtl8651_FragmentShortestPathFwdCache_t *cache;


                cache = &(fragmentShortestPathCache[(pkthdr->ph_un_sw.ROMEDRV_USG._ph_fragOffset&(32 -1))]);

                cache->status = 0;
        }
}

static void _rtl8651_fragmentShortestPathCache_timeUpdate(uint32 passed)
{
        _rtl8651_FragmentShortestPathFwdCache_t *ptr;
        uint32 idx;

        ptr = fragmentShortestPathCache;

        for (idx = 0 ; idx < 32; idx ++, ptr ++)
        {
                if (ptr->age == 0)
                        continue;

                if (ptr->age > passed)
                        ptr->age = (ptr->age - passed);
                else
                {
                        ptr->age = 0;
                        ptr->status = 0;
                }
        }
}

static inline int32 _rtl8651_fragmentShortestPathFwd(struct rtl_pktHdr*pkthdr, struct ip *pip)
{
        if ((((uint16)(pip->ip_off)) & 0x1fff) && (((*(uint8*)pip)&0xf) == 5))
        {
                _rtl8651_FragmentShortestPathFwdCache_t *cache;
                ipaddr_t sip;
                ipaddr_t dip;
                uint16 id;

                sip = ((uint32) (*((uint8*)(&pip->ip_src))<<24)|(*(((uint8*)(&pip->ip_src))+1)<<16)|(*(((uint8*)(&pip->ip_src))+2)<<8) | *(((uint8*)(&pip->ip_src))+3));
                dip = ((uint32) (*((uint8*)(&pip->ip_dst))<<24)|(*(((uint8*)(&pip->ip_dst))+1)<<16)|(*(((uint8*)(&pip->ip_dst))+2)<<8) | *(((uint8*)(&pip->ip_dst))+3));
                id = (pip->ip_id);


                cache = &(fragmentShortestPathCache[(sip+dip+id)&(32 -1)]);

                if ((cache->status != 2) ||
                        (sip != cache->sip) || (dip != cache->dip) || (id != cache->id))
                        return -1;


                if (pkthdr->ph_pppeTagged)
                {
                        mBuf_adjHead(pkthdr->PKTHDRNXT.mbuf_first, 8);
                        *((uint16 *)((uint32)pip - (uint32)2)) = (0x0800);
                        pkthdr->ph_pppeTagged = 0;
                }

                if (cache->mode == 0)
                {
                        do{ *((uint8*)(&pip->ip_src)) = (uint8)((cache->aliasIp)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((cache->aliasIp)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((cache->aliasIp)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((cache->aliasIp)); }while(0);
                }else
                {
                        do{ *((uint8*)(&pip->ip_dst)) = (uint8)((cache->aliasIp)>>24); *(((uint8*)(&pip->ip_dst))+1) = (uint8)((cache->aliasIp)>>16); *(((uint8*)(&pip->ip_dst))+2) = (uint8)((cache->aliasIp)>>8); *(((uint8*)(&pip->ip_dst))+3) = (uint8)((cache->aliasIp)); }while(0);
                }

                pip->ip_ttl --;

                rtl8651_memcpy((void *)((uint32)pip - (uint32)14), &cache->dmac, 6);
                rtl8651_memcpy((void *)((uint32)pip - (uint32)8), &cache->smac, 6);

                pkthdr->ph_proto = 2;
                pkthdr->ph_portlist = cache->portList;
                pkthdr->ph_extPortList = cache->extPortList;
                pkthdr->ph_srcExtPortNum = cache->srcExtPortNum;
                pkthdr->ph_pppoeIdx = cache->pppoeIdx;
                pkthdr->ph_vlanIdx = cache->vlanIdx;
                pkthdr->ph_flags = ((pkthdr->ph_flags & 0xfff0) | cache->flags);

                rtlglue_drvSend((void*)pkthdr);
                return 0;
        }
        return -1;
}
# 18216 "rtl8651_tblDrvFwd.c"
static int32 _rtl8651_naptRedirectInit(rtl8651_fwdEngineInitPara_t *para)
{
        uint32 redirectTblSize;
        uint32 flowCacheSize;

        redirectTblSize = para->redirectTblSize;
        flowCacheSize = para->redirectFlowCacheSize;




        _rtl8651_naptRedirectEntry_inuse = ((void *)0);
        _rtl8651_naptRedirectEntry_freelist = ((void *)0);


        if (redirectTblSize)
        {
                uint32 idx;
                _rtl8651_naptRedirectEntry_t *ptr;

                _rtl8651_naptRedirectEntry_freelist = (_rtl8651_naptRedirectEntry_t *)rtlglue_malloc(redirectTblSize * sizeof(_rtl8651_naptRedirectEntry_t));

                if (!_rtl8651_naptRedirectEntry_freelist)
                        return -1;


                memset(_rtl8651_naptRedirectEntry_freelist, 0, (redirectTblSize*sizeof(_rtl8651_naptRedirectEntry_t)));

                for (idx = 0, ptr = _rtl8651_naptRedirectEntry_freelist ; idx < redirectTblSize ; idx ++, ptr ++)
                {
                        if (idx < (redirectTblSize - 1))
                                ptr->next = ptr + 1;
                }
        }





        _rtl8651_naptRedirectFlowCache_lru_head = ((void *)0);
        _rtl8651_naptRedirectFlowCache_lru_tail = ((void *)0);
        _rtl8651_naptRedirectFlowCache_freelist = ((void *)0);


        if (flowCacheSize)
        {
                uint32 idx;
                _rtl8651_naptRedirectFlow_t *ptr;

                _rtl8651_naptRedirectFlowCache_freelist = (_rtl8651_naptRedirectFlow_t *)rtlglue_malloc(flowCacheSize * sizeof(_rtl8651_naptRedirectFlow_t));

                if (!_rtl8651_naptRedirectFlowCache_freelist)
                        return -1;


                memset(_rtl8651_naptRedirectFlowCache_freelist, 0, (flowCacheSize*sizeof(_rtl8651_naptRedirectFlow_t)));

                for (idx = 0 , ptr = _rtl8651_naptRedirectFlowCache_freelist ; idx < flowCacheSize ; idx ++, ptr ++)
                {
                        if (idx < (flowCacheSize - 1))
                                ptr->next = ptr + 1;
                }
        }

        return 0;
}





static void _rtl8651_naptRedirectReinit(void)
{

        {
                _rtl8651_naptRedirectEntry_t *ptr;

                while ((ptr = _rtl8651_naptRedirectEntry_inuse) != ((void *)0))
                {

                        _rtl8651_naptRedirectEntry_inuse = _rtl8651_naptRedirectEntry_inuse->next;

                        ptr->next = _rtl8651_naptRedirectEntry_freelist;
                        _rtl8651_naptRedirectEntry_freelist = ptr;
                }
        }


        {
# 18327 "rtl8651_tblDrvFwd.c"
                if (_rtl8651_naptRedirectFlowCache_lru_tail)
                {
                        _rtl8651_naptRedirectFlowCache_lru_tail->next = _rtl8651_naptRedirectFlowCache_freelist;
                }

                if (_rtl8651_naptRedirectFlowCache_lru_head)
                {
                        _rtl8651_naptRedirectFlowCache_freelist = _rtl8651_naptRedirectFlowCache_lru_head;
                }

                _rtl8651_naptRedirectFlowCache_lru_head = ((void *)0);
                _rtl8651_naptRedirectFlowCache_lru_tail = ((void *)0);
        }
}
# 18349 "rtl8651_tblDrvFwd.c"
static _rtl8651_naptRedirectEntry_t *_rtl8651_findExistNaptRedirectEntry(
        uint8 isExceptionList,
        uint8 isTcp,
        ipaddr_t sip,
        uint16 sport,
        ipaddr_t originalDip,
        uint16 originalDport)
{
        _rtl8651_naptRedirectEntry_t *ptr;






        ptr = _rtl8651_naptRedirectEntry_inuse;

        while (ptr)
        {






                if (ptr->isExceptionList != isExceptionList)
                        goto next;
                if (ptr->isTcp != isTcp)
                        goto next;
                if (ptr->sip && sip && (ptr->sip != sip))
                        goto next;
                if (ptr->sport && sport && (ptr->sport != sport))
                        goto next;
                if (ptr->dip && originalDip && (ptr->dip != originalDip))
                        goto next;
                if (ptr->dport && originalDport && (ptr->dport != originalDport))
                        goto next;

                return ptr;
        next:
                ptr = ptr->next;
        }

        return ((void *)0);
}





static inline int32 _rtl8651_findNaptRedirectEntry(
        uint8 isTcp,
        ipaddr_t sip,
        uint16 sport,
        ipaddr_t dip,
        uint16 dport,
        ipaddr_t *pNewDip,
        uint16 *pNewDport,
        uint8 createCache,
        uint16 vlanIdx
)
{
        _rtl8651_naptRedirectEntry_t *ptr;

        do {} while (0);
        do {} while (0);






        if ((ptr = _rtl8651_findExistNaptRedirectEntry(1, isTcp, sip, sport, dip, dport)) != ((void *)0))
        {
                return -1;
        } else if ((ptr = _rtl8651_findExistNaptRedirectEntry(0, isTcp, sip, sport, dip, dport)) != ((void *)0))
        {
                ipaddr_t newDip = 0;
                uint16 newDport = 0;

                if (ptr->newDport >= 0)
                {

                        newDport = ptr->newDport;


                        if (ptr->newDip == 0)
                        {
                                rtl8651_tblDrv_vlanTable_t *inVlan;
                                rtl8651_tblDrv_networkIntfTable_t *netif;

                                inVlan = &DrvTbl.vlan[vlanIdx];
                                if (!inVlan->valid)
                                        return -1;

                                netif = _rtl8651_getNetworkIntfEntryByVid(inVlan->vid);

                                switch (netif->linkLayerType)
                                {
                                        case 0x01:
                                        {
                                                rtl8651_tblDrv_ipIntfEntry_t * ipIntfPtr;
                                                rtl8651_tblDrv_ipIntfIpAddrEntry_t * ipAddrPtr;

                                                ipIntfPtr = ((&netif->IpHead)->slh_first);
                                                if (!ipIntfPtr)
                                                        return -1;
                                                ipAddrPtr = ((&ipIntfPtr->ipAddr)->slh_first);
                                                if (!ipAddrPtr)
                                                        return -1;
                                                newDip = ipAddrPtr->ipAddr;
                                        }
                                                break;
                                        case 0x02:

                                        case 0x05:
                                        case 0x06:

                                        {
                                                rtl8651_tblDrvSession_t *sessionPtr;

                                                sessionPtr = ((&netif->sessionHead)->tqh_first);
                                                if ((!sessionPtr) || (!sessionPtr->ip_t))
                                                        return -1;
                                                        newDip = sessionPtr->ip_t->ipAddr;
                                        }
                                                break;
                                        default:



                                                break;
                                }
                        }else
                        {
                                newDip = ptr->newDip;
                        }
                }else
                {

                        newDport = dport;

                        newDip = dip;
                }



                if (createCache == 1)
                {
                        if (_rtl8651_addNaptRedirectFlow(isTcp, sip, sport, dip, dport, newDip, newDport) != 0)
                        {
                                return -1;
                        }
                }




                *pNewDip = newDip;
                *pNewDport = newDport;

                return 0;
        }


        return -1;
}
# 18537 "rtl8651_tblDrvFwd.c"
static inline _rtl8651_naptRedirectFlow_t *_rtl8651_findNaptRedirectFlow(
        uint8 isTcp,
        ipaddr_t sip,
        uint16 sport,
        ipaddr_t originalDip,
        uint16 originalDport,
        ipaddr_t newDip,
        uint16 newDport,
        uint8 isExternalQuery,
        uint8 refresh
)
{
        _rtl8651_naptRedirectFlow_t *prev;
        _rtl8651_naptRedirectFlow_t *ptr;

        do {} while (0);
        do {} while (0);

        prev = ((void *)0);
        ptr = _rtl8651_naptRedirectFlowCache_lru_head;

        while (ptr)
        {
                if ( (isTcp == ptr->isTcp) &&
                        (sip == ptr->sip) &&
                        (sport == ptr->sport) &&
                        (newDip == ptr->newDip) &&
                        (newDport == ptr->newDport) &&
                        (!originalDip || (originalDip == ptr->dip)) &&
                        (!originalDip || (originalDport == ptr->dport)))
                {
                        goto found;
                }
                prev = ptr;
                ptr = ptr->next;
        }

        return ((void *)0);
found:
        do {} while (0);

        if (isExternalQuery)
        {
                ptr->queryCnt ++;
        }

        if (refresh)
        {
                ptr->queryCnt = 0;
                ptr->age = 32;

                if (ptr != _rtl8651_naptRedirectFlowCache_lru_tail)
                {

                        if (prev)
                        {
                                prev->next = ptr->next;
                        }else
                        {
                                do {} while (0);
                                _rtl8651_naptRedirectFlowCache_lru_head = _rtl8651_naptRedirectFlowCache_lru_head->next;
                        }

                        do {} while (0);
                        _rtl8651_naptRedirectFlowCache_lru_tail->next = ptr;
                        ptr->next = ((void *)0);
                        _rtl8651_naptRedirectFlowCache_lru_tail = ptr;
                }
        }

        return ptr;
}




static inline int32 _rtl8651_addNaptRedirectFlow(
        uint8 isTcp,
        ipaddr_t sip,
        uint16 sport,
        ipaddr_t originalDip,
        uint16 originalDport,
        ipaddr_t newDip,
        uint16 newDport
)
{
        _rtl8651_naptRedirectFlow_t *prev;
        _rtl8651_naptRedirectFlow_t *ptr;




        ptr = _rtl8651_findNaptRedirectFlow(isTcp, sip, sport, originalDip, originalDport, newDip, newDport, 0, 1);
        if (ptr)
        {
                return 0;
        }





        if (_rtl8651_naptRedirectFlowCache_freelist)
        {
                ptr = _rtl8651_naptRedirectFlowCache_freelist;
                _rtl8651_naptRedirectFlowCache_freelist = _rtl8651_naptRedirectFlowCache_freelist->next;
        }else
        {


                prev = ((void *)0);
                ptr = _rtl8651_naptRedirectFlowCache_lru_head;
                while (ptr)
                {
                        if (ptr->queryCnt > 0)
                        {
                                if (prev)
                                {
                                        prev->next = ptr->next;
                                }else
                                {
                                        _rtl8651_naptRedirectFlowCache_lru_head = ptr->next;
                                }

                                if (ptr == _rtl8651_naptRedirectFlowCache_lru_tail)
                                {
                                        _rtl8651_naptRedirectFlowCache_lru_tail = prev;
                                }
                                goto setNewCache;
                        }
                        prev = ptr;
                        ptr = ptr->next;
                }


                if (!_rtl8651_naptRedirectFlowCache_lru_head)
                        return -1;

                ptr = _rtl8651_naptRedirectFlowCache_lru_head;

                if (_rtl8651_naptRedirectFlowCache_lru_head == _rtl8651_naptRedirectFlowCache_lru_tail)
                {
                        _rtl8651_naptRedirectFlowCache_lru_head = ((void *)0);
                        _rtl8651_naptRedirectFlowCache_lru_tail = ((void *)0);
                }else
                {
                        _rtl8651_naptRedirectFlowCache_lru_head = _rtl8651_naptRedirectFlowCache_lru_head->next;
                }
        }


setNewCache:

        do {} while (0);

        ptr->isTcp = isTcp;
        ptr->sip = sip;
        ptr->sport = sport;
        ptr->dip = originalDip;
        ptr->dport = originalDport;
        ptr->newDip = newDip;
        ptr->newDport = newDport;
        ptr->age = 32;
        ptr->queryCnt = 0;
        ptr->next = ((void *)0);




        if (_rtl8651_naptRedirectFlowCache_lru_tail)
                _rtl8651_naptRedirectFlowCache_lru_tail->next = ptr;
        _rtl8651_naptRedirectFlowCache_lru_tail = ptr;
        if (_rtl8651_naptRedirectFlowCache_lru_head == ((void *)0))
                _rtl8651_naptRedirectFlowCache_lru_head = ptr;

        return 0;
}



static void _rtl8651_naptRedirectFlowTimeUpdate(uint32 secPassed)
{
        _rtl8651_naptRedirectFlow_t *ptr;

        ptr = _rtl8651_naptRedirectFlowCache_lru_head;

        while (ptr)
        {
                if (ptr->age > secPassed)
                {
                        ptr->age -= secPassed;
                        ptr = ptr->next;
                }else
                {

                        do {} while (0);


                        _rtl8651_naptRedirectFlowCache_lru_head = _rtl8651_naptRedirectFlowCache_lru_head->next;
                        if (_rtl8651_naptRedirectFlowCache_lru_tail == ptr)
                                _rtl8651_naptRedirectFlowCache_lru_tail = ((void *)0);

                        ptr->next = _rtl8651_naptRedirectFlowCache_freelist;
                        _rtl8651_naptRedirectFlowCache_freelist = ptr;


                        ptr = _rtl8651_naptRedirectFlowCache_lru_head;
                }
        }
}






int32 rtl8651_registerRedirectOutboundNaptFlow(
                uint8 isTcp,
                ipaddr_t sip,
                uint16 sport,
                ipaddr_t originalDip,
                uint16 originalDport,
                ipaddr_t newDip,
                int32 newDport
)
{
        int32 retval = -1;

        rtlglue_drvMutexLock();




        if (_rtl8651_findExistNaptRedirectEntry(0, isTcp, sip, sport, originalDip, originalDport))
                goto out;



        if (newDport == 0)
                goto out;



        {
                _rtl8651_naptRedirectEntry_t *ptr;

                if (_rtl8651_naptRedirectEntry_freelist == ((void *)0))
                        goto out;

                ptr = _rtl8651_naptRedirectEntry_freelist;
                _rtl8651_naptRedirectEntry_freelist = _rtl8651_naptRedirectEntry_freelist->next;

                ptr->isExceptionList = 0;
                ptr->isTcp = isTcp;
                ptr->sip = sip;
                ptr->sport = sport;
                ptr->dip = originalDip;
                ptr->dport = originalDport;
                ptr->newDip = newDip;
                ptr->newDport = newDport;

                ptr->next = _rtl8651_naptRedirectEntry_inuse;
                _rtl8651_naptRedirectEntry_inuse = ptr;
        }
        retval = 0;

out:
        rtlglue_drvMutexUnlock();
        return retval;
}



int32 rtl8651_unregisterRedirectOutboundNaptFlow(
                uint8 isTcp,
                ipaddr_t sip,
                uint16 sport,
                ipaddr_t originalDip,
                uint16 originalDport,
                ipaddr_t newDip,
                int32 newDport
)
{



        _rtl8651_naptRedirectEntry_t *prev;
        _rtl8651_naptRedirectEntry_t *ptr;
        uint32 removeCnt;

        rtlglue_drvMutexLock();

        prev = ((void *)0);
        ptr = _rtl8651_naptRedirectEntry_inuse;
        removeCnt = 0;

        while (ptr)
        {
                if ( (ptr->isExceptionList == 0) &&
                        (isTcp == ptr->isTcp) &&
                        (!sip || (sip == ptr->sip)) &&
                        (!sport || (sport == ptr->sport)) &&
                        (!originalDip || (originalDip == ptr->dip)) &&
                        (!originalDport || (originalDport == ptr->dport)) &&
                        (!newDip || (newDip == ptr->newDip)) &&
                        (!newDport || (newDport == ptr->newDport)))
                {

                        if (prev)
                        {
                                prev->next = ptr->next;
                        }else
                        {
                                _rtl8651_naptRedirectEntry_inuse = ptr->next;
                        }
                        ptr->next = _rtl8651_naptRedirectEntry_freelist;
                        _rtl8651_naptRedirectEntry_freelist = ptr;

                        removeCnt ++;



                        if (prev)
                        {
                                ptr = prev->next;
                        }else
                        {
                                ptr = _rtl8651_naptRedirectEntry_inuse;
                        }
                }else
                {
                        prev = ptr;
                        ptr = ptr->next;
                }
        }


        rtlglue_drvMutexUnlock();
        return removeCnt;
}




int32 rtl8651_queryRedirectOutboundNaptFlow(
                uint8 isTcp,
                ipaddr_t sip,
                uint16 sport,
                ipaddr_t *pOriginalDip,
                uint16 *pOriginalDport,
                ipaddr_t newDip,
                uint16 newDport
)
{
        int32 retval = -1;
        rtlglue_drvMutexLock();
        retval = _rtl8651_queryRedirectOutboundNaptFlow( isTcp,
                                                                                                        sip, sport,
                                                                                                        pOriginalDip, pOriginalDport,
                                                                                                        newDip, newDport);
        rtlglue_drvMutexUnlock();
        return retval;
}

static inline int32 _rtl8651_queryRedirectOutboundNaptFlow(
                uint8 isTcp,
                ipaddr_t sip,
                uint16 sport,
                ipaddr_t *pOriginalDip,
                uint16 *pOriginalDport,
                ipaddr_t newDip,
                uint16 newDport
)
{
        _rtl8651_naptRedirectFlow_t *ptr;


        do {} while (0);
        do {} while (0);

        ptr = _rtl8651_findNaptRedirectFlow(isTcp, sip, sport, 0, 0, newDip, newDport, 1, 0);

        if (ptr)
        {
                *pOriginalDip = ptr->dip;
                *pOriginalDport = ptr->dport;

                return 0;
        }
        return -1;
}




int32 _rtl8651_resolveProxyInboundFlow(rtl8651_tblDrv_vlanTable_t *dvlan, struct ip *pip)
{
        struct tcphdr *tc = ((void *)0);
        struct udphdr *ud = ((void *)0);
        uint8 isTcp = 0;
        ipaddr_t sip = 0;
        ipaddr_t dip = 0;
        uint16 sport = 0;
        uint16 dport = 0;

        ipaddr_t newSip = 0;
        uint16 newSport = 0;


        if (!(dvlan->internal))
                goto out;


        if ((((uint16)(pip->ip_off)) & 0x1fff))
        {
                if ((pip->ip_p == 6) || (pip->ip_p == 17))
                {
                        sip = ((uint32) (*((uint8*)(&pip->ip_src))<<24)|(*(((uint8*)(&pip->ip_src))+1)<<16)|(*(((uint8*)(&pip->ip_src))+2)<<8) | *(((uint8*)(&pip->ip_src))+3));
                        dip = ((uint32) (*((uint8*)(&pip->ip_dst))<<24)|(*(((uint8*)(&pip->ip_dst))+1)<<16)|(*(((uint8*)(&pip->ip_dst))+2)<<8) | *(((uint8*)(&pip->ip_dst))+3));

                        if (_rtl8651_getFragCache(6, sip, dip, (pip->ip_id), &newSip, ((void *)0), ((void *)0), ((void *)0)) == 0)
                        {

                                do{ *((uint8*)(&pip->ip_src)) = (uint8)((newSip)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((newSip)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((newSip)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((newSip)); }while(0);

                                do { do { int32 accumulate = 0; if ((((newSip)) != 0) && (((sip)) != 0)){ accumulate = (((sip)) & 0xffff); accumulate += (( ((sip)) >> 16 ) & 0xffff); accumulate -= (((newSip)) & 0xffff); accumulate -= (( ((newSip)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
                        }
                }
                goto out;
        }


        switch (pip->ip_p)
        {
                case 6:
                        isTcp = 1;
                        tc = (struct tcphdr *) ((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));
                        sport = (tc->th_sport);
                        dport = (tc->th_dport);
                        break;
                case 17:
                        isTcp = 0;
                        ud = (struct udphdr *) ((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));
                        sport = (ud->uh_sport);
                        dport= (ud->uh_dport);
                        break;
                default:
                        goto out;
        }

        sip = ((uint32) (*((uint8*)(&pip->ip_src))<<24)|(*(((uint8*)(&pip->ip_src))+1)<<16)|(*(((uint8*)(&pip->ip_src))+2)<<8) | *(((uint8*)(&pip->ip_src))+3));
        dip = ((uint32) (*((uint8*)(&pip->ip_dst))<<24)|(*(((uint8*)(&pip->ip_dst))+1)<<16)|(*(((uint8*)(&pip->ip_dst))+2)<<8) | *(((uint8*)(&pip->ip_dst))+3));


        if (_rtl8651_queryRedirectOutboundNaptFlow(isTcp, dip, dport, &newSip, &newSport, sip, sport) != 0)
                goto out;


        {
                uint16 *l4cksum;

                do {} while (0);


                do{ *((uint8*)(&pip->ip_src)) = (uint8)((newSip)>>24); *(((uint8*)(&pip->ip_src))+1) = (uint8)((newSip)>>16); *(((uint8*)(&pip->ip_src))+2) = (uint8)((newSip)>>8); *(((uint8*)(&pip->ip_src))+3) = (uint8)((newSip)); }while(0);
                if (isTcp == 1)
                {
                        l4cksum = &(tc->th_sum);
                        tc->th_sport = (newSport);
                }else
                {
                        l4cksum = &(ud->uh_sum);
                        ud->uh_sport = (newSport);
                }


                if ((isTcp != 0) || (*l4cksum))
                        do { int32 accumulate = 0; if (((newSip) != 0) && ((sip) != 0)){ accumulate = ((sip) & 0xffff); accumulate += (( (sip) >> 16 ) & 0xffff); accumulate -= ((newSip) & 0xffff); accumulate -= (( (newSip) >> 16 ) & 0xffff); } if (((newSport) != 0) && ((sport) != 0)){ accumulate += (sport); accumulate -= (newSport); } do { accumulate += ((*l4cksum)); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (*l4cksum) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; (*l4cksum) = ((uint16) accumulate); } } while (0); }while(0);
                do { do { int32 accumulate = 0; if ((((newSip)) != 0) && (((sip)) != 0)){ accumulate = (((sip)) & 0xffff); accumulate += (( ((sip)) >> 16 ) & 0xffff); accumulate -= (((newSip)) & 0xffff); accumulate -= (( ((newSip)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);


                _rtl8651_updateFragCache(6, sip, dip, (pip->ip_id), newSip, 0, ((void *)0), 0);
        }
out:
        return 0;
}




int32 rtl8651_registerRedirectOutboundNaptExceptionList(
                uint8 isTcp,
                ipaddr_t sip,
                uint16 sport,
                ipaddr_t dip,
                uint16 dport
)
{
        int32 retval = -1;

        rtlglue_drvMutexLock();



        if (_rtl8651_findExistNaptRedirectEntry(1, isTcp, sip, sport, dip, dport))
                goto out;



        {
                _rtl8651_naptRedirectEntry_t *ptr;

                if (_rtl8651_naptRedirectEntry_freelist == ((void *)0))
                        goto out;

                ptr = _rtl8651_naptRedirectEntry_freelist;
                _rtl8651_naptRedirectEntry_freelist = _rtl8651_naptRedirectEntry_freelist->next;

                ptr->isExceptionList = 1;
                ptr->isTcp = isTcp;
                ptr->sip = sip;
                ptr->sport = sport;
                ptr->dip = dip;
                ptr->dport = dport;
                ptr->newDip = 0;
                ptr->newDport = 0;

                ptr->next = _rtl8651_naptRedirectEntry_inuse;
                _rtl8651_naptRedirectEntry_inuse = ptr;
        }
        retval = 0;

out:
        rtlglue_drvMutexUnlock();
        return retval;
}



int32 rtl8651_unregisterRedirectOutboundNaptExceptionList(
                uint8 isTcp,
                ipaddr_t sip,
                uint16 sport,
                ipaddr_t dip,
                uint16 dport
)
{



        _rtl8651_naptRedirectEntry_t *prev;
        _rtl8651_naptRedirectEntry_t *ptr;
        uint32 removeCnt;

        rtlglue_drvMutexLock();

        prev = ((void *)0);
        ptr = _rtl8651_naptRedirectEntry_inuse;
        removeCnt = 0;

        while (ptr)
        {
                if ( (ptr->isExceptionList == 1) &&
                        (isTcp == ptr->isTcp) &&
                        (!sip || (sip == ptr->sip)) &&
                        (!sport || (sport == ptr->sport)) &&
                        (!dip || (dip == ptr->dip)) &&
                        (!dport || (dport == ptr->dport)))
                {

                        if (prev)
                        {
                                prev->next = ptr->next;
                        }else
                        {
                                _rtl8651_naptRedirectEntry_inuse = ptr->next;
                        }
                        ptr->next = _rtl8651_naptRedirectEntry_freelist;
                        _rtl8651_naptRedirectEntry_freelist = ptr;

                        removeCnt ++;



                        if (prev)
                        {
                                ptr = prev->next;
                        }else
                        {
                                ptr = _rtl8651_naptRedirectEntry_inuse;
                        }
                }else
                {
                        prev = ptr;
                        ptr = ptr->next;
                }
        }



        rtlglue_drvMutexUnlock();

        return removeCnt;
}





static int32 _rtl8651_pptpHdrCacheInit(rtl8651_fwdEngineInitPara_t *para)
{
        uint32 cnt;

        cnt = para->pptpHdrCacheSize;


        memset(_rtl8651_pptpHdrCache_hashTbl, 0, sizeof(_rtl8651_pptpHdrCache_hashTbl));
        _rtl8651_pptpHdrCache_lru_head = ((void *)0);
        _rtl8651_pptpHdrCache_lru_tail = ((void *)0);
        _rtl8651_pptpHdrCache_unused = ((void *)0);


        if (cnt)
        {
                uint32 idx;
                _rtl8651_pptpHdrCacheEntry_t *ptr;

                _rtl8651_pptpHdrCache_unused = (_rtl8651_pptpHdrCacheEntry_t*)rtlglue_malloc(cnt * sizeof(_rtl8651_pptpHdrCacheEntry_t));

                if (_rtl8651_pptpHdrCache_unused == ((void *)0))
                        return -1;


                memset(_rtl8651_pptpHdrCache_unused, 0, (cnt * sizeof(_rtl8651_pptpHdrCacheEntry_t)));

                ptr = _rtl8651_pptpHdrCache_unused;
                for (idx = 0 ; idx < (cnt-1) ; idx ++, ptr ++)
                {
                        ptr->next = ptr + 1;
                }
        }

        return 0;
}

static void _rtl8651_pptpHdrCacheReinit(void)
{

        while (_rtl8651_pptpHdrCache_lru_head)
        {
                _rtl8651_pptpHdrCache_Del(_rtl8651_pptpHdrCache_lru_head);
        }
}


void _rtl8651_pptpHdrCache_Add(uint16 ip_id, uint16 ip_off, uint32 seq, uint32 ack, uint8 type)
{
        uint32 hashIdx = (((uint32)(0)+(uint32)((uint32)ip_off)+(uint32)((ip_id))) & (64 -1));
        _rtl8651_pptpHdrCacheEntry_t **pHashTbl;
        _rtl8651_pptpHdrCacheEntry_t *ptr;


        if (_rtl8651_pptpHdrCache_unused)
        {
fromUnused:
                ptr = _rtl8651_pptpHdrCache_unused;
                _rtl8651_pptpHdrCache_unused = _rtl8651_pptpHdrCache_unused->next;
        }else if (_rtl8651_pptpHdrCache_lru_head)
        {
                _rtl8651_pptpHdrCache_Del(_rtl8651_pptpHdrCache_lru_head);
                do {} while (0);
                goto fromUnused;
        }else
                goto out;

        ptr->hdr = ((void *)0);
        ptr->next = ((void *)0);
        ptr->prev = ((void *)0);
        ptr->lru_next = ((void *)0);
        ptr->lru_prev = ((void *)0);



        ptr->id = ip_id;
        ptr->offset = ip_off;
        ptr->seq = seq;
        ptr->ack = ack;
        ptr->type = type;

        pHashTbl = &(_rtl8651_pptpHdrCache_hashTbl[hashIdx]);
        ptr->hdr = pHashTbl;
        ptr->prev = ((void *)0);
        ptr->next = *pHashTbl;
        if (*pHashTbl)
                (*pHashTbl)->prev = ptr;
        *pHashTbl = ptr;

        if (_rtl8651_pptpHdrCache_lru_tail)
        {
                ptr->lru_next = ((void *)0);
                ptr->lru_prev = _rtl8651_pptpHdrCache_lru_tail;
                _rtl8651_pptpHdrCache_lru_tail->lru_next = ptr;
                _rtl8651_pptpHdrCache_lru_tail = ptr;
        }else
        {
                ptr->lru_next = ((void *)0);
                ptr->lru_prev = ((void *)0);
                _rtl8651_pptpHdrCache_lru_head = ptr;
                _rtl8651_pptpHdrCache_lru_tail = ptr;
        }
out:
        return;
}


static void _rtl8651_pptpHdrCache_Del(_rtl8651_pptpHdrCacheEntry_t *ptr)
{
        _rtl8651_pptpHdrCacheEntry_t **hashTbl;

        do {} while (0);
        hashTbl = ptr->hdr;
        if (*hashTbl == ptr)
        {
                do {} while (0);
                *hashTbl = ptr->next;
                if (ptr->next)
                        ptr->next->prev = ((void *)0);
        }else
        {
                do {} while (0);
                ptr->prev->next = ptr->next;
                if (ptr->next)
                        ptr->next->prev = ptr->prev;
        }
        ptr->hdr = ((void *)0);
        ptr->prev = ((void *)0);
        ptr->next = ((void *)0);


        if (ptr->lru_prev)
        {
                ptr->lru_prev->lru_next = ptr->lru_next;
        }else
        {
                _rtl8651_pptpHdrCache_lru_head = ptr->lru_next;
        }
        if (ptr->lru_next)
        {
                ptr->lru_next->lru_prev = ptr->lru_prev;
        }else
        {
                _rtl8651_pptpHdrCache_lru_tail = ptr->lru_prev;
        }
        ptr->lru_prev = ((void *)0);
        ptr->lru_next = ((void *)0);

        ptr->next = _rtl8651_pptpHdrCache_unused;
        _rtl8651_pptpHdrCache_unused = ptr;
}


static inline int32 _rtl8651_pptpHdrCache_Find(uint16 ip_id, uint16 ip_off, uint32 *pSeq, uint32 *pAck, uint8 *pType)
{
        uint32 hashIdx = (((uint32)(0)+(uint32)((uint32)ip_off)+(uint32)((ip_id))) & (64 -1));
        _rtl8651_pptpHdrCacheEntry_t *ptr;

        do {} while (0);

        ptr = _rtl8651_pptpHdrCache_hashTbl[hashIdx];
        while (ptr)
        {
                if ((ptr->id == ip_id) && (ptr->offset == ip_off))
                {
                        *pSeq = ptr->seq;
                        *pAck = ptr->ack;
                        *pType = ptr->type;
                        _rtl8651_pptpHdrCache_Del(ptr);
                        return 0;
                }
                ptr = ptr->next;
        }
        return -1;
}






static inline int32 _rtl8651_refillHeader(int32 result, struct rtl_pktHdr *pkt, struct ip*pktip, rtl8651_tblDrv_vlanTable_t *svlan, uint16 srcPortList)
{
        uint8 wanType;
        rtl8651_tblDrv_routeTable_t *rt_t;
        rtl8651_tblDrv_pppTable_t *pppEntry_t;
        struct rtl_mBuf *mbuf;
        uint8 *data;
        struct rtl_pktHdr * pkthdr;
        struct ip*pip;

        pkthdr = pkt;
        pip = pktip;


        if (tunnel.valid != 1)
                goto out;

        if ((svlan->vid != tunnel.loopBackVid) || (srcPortList != tunnel.loopbackPort))
                goto out;


        wanType = 0;
        rt_t = DrvTbl.route + (rtl8651_tblDrvPara.routingTableSize - 1);
        if ((rt_t->valid == 0) || (rt_t->ifrt_flag != 0))
                goto out;

        pppEntry_t = rt_t->un.nxthop.un1.session.session_t;

        if ((!pppEntry_t) || (!pppEntry_t->initiated))
                goto out;
        if (rt_t->netif_t->linkLayerType == 0x05)
        {
                wanType = 0x05;
        } else if (rt_t->netif_t->linkLayerType == 0x06)
        {
                wanType = 0x06;
        }else
        {
                goto out;
        }

        while (pkthdr)
        {
                mbuf = pkthdr->PKTHDRNXT.mbuf_first;
                data = mbuf->m_data;

                do {} while (0);

                if (memcmp(data+6, &(pppEntry_t->macInfo->macAddr.octet), 6))
                        goto out;


                pkthdr->ph_vlanIdx = (tunnel.wanVid& (8 -1));
                pkthdr->ph_portlist = tunnel.wanPort;


                if (wanType == 0x05)
                {
                        if ((pppEntry_t->un.pptp.greBuf2__ == ((void *)0)) || (pppEntry_t->un.pptp.greOffset2__ == 0))
                                goto out;
                        if (((uint32)data - (uint32)(mbuf->m_extbuf)) >= pppEntry_t->un.pptp.greOffset2__)
                        {
                                uint16 pipLen;
                                struct ip *ipBuf;

                                struct ip *ipHdr;

                                struct wan_gre_header *greBuf;
                                struct wan_gre_header *greHdr;
                                uint16 pipId;
                                uint16 pipOff;
                                uint32 gre_seq;
                                uint32 gre_ack;
                                uint8 gre_type;
                                int16 offset;
                                uint8 *remain;
                                int16 remainLen;
                                uint8 *hdrRemain;


                                pipId = (pip->ip_id);
                                pipOff = (pip->ip_off);
                                if (_rtl8651_pptpHdrCache_Find(pipId, pipOff, &gre_seq, &gre_ack, &gre_type) != 0)
                                {
                                        do {} while (0);
                                        gre_seq = 0;
                                        gre_ack = 0;
                                        gre_type = 0;
                                }






                                do {} while (0);


                                pipLen = (pip->ip_len);
                                ipBuf = (struct ip *)(pppEntry_t->un.pptp.greBuf2__);
                                greBuf = (struct wan_gre_header *)((uint8 *)ipBuf + (((*(uint8*)ipBuf)&0xf) << 2));
                                remain = (uint8 *)((uint32)greBuf + sizeof(struct wan_gre_header));


                                ipBuf->ip_id = ((ipBuf->ip_id) + 1);
                                ipBuf->ip_off = ((ipBuf->ip_off) & ~(0x1fff));


                                if (!(greBuf->flags & 0x10))
                                {
                                        remain -= 4;
                                }
                                if (!(greBuf->ver& 0x80))
                                {
                                        remain -= 4;
                                }

                                remainLen = pppEntry_t->un.pptp.greOffset2__ - ((uint32)remain - (uint32)ipBuf);


                                offset = (((*(uint8*)ipBuf)&0xf) << 2) + sizeof(struct wan_gre_header) + remainLen;
                                if (!(gre_type & 0x01))
                                {
                                        offset -= 4;
                                }
                                if (!(gre_type & 0x02))
                                {
                                        offset -= 4;
                                }


                                ipBuf->ip_len = (offset + pipLen);
                                greBuf->payload_len = (remainLen + pipLen);


                                pkthdr->ph_len += offset;
                                mbuf->m_len += offset;
                                mbuf->m_data -= offset;


                                data = mbuf->m_data;
# 19511 "rtl8651_tblDrvFwd.c"
                                rtl8651_memcpy(data + 14, pppEntry_t->un.pptp.greBuf2__, ((((*(uint8*)ipBuf)&0xf) << 2) + (sizeof(struct wan_gre_header) - 8)));

                                ipHdr = (struct ip*)((uint32)data + 14);
                                greHdr = (struct wan_gre_header *)((uint8 *)ipHdr + (((*(uint8*)ipHdr)&0xf) << 2));
                                hdrRemain = (uint8*)greHdr + (sizeof(struct wan_gre_header) - 8);
                                if (gre_type & 0x01)
                                {
                                        greHdr->flags |= 0x10;
                                        do{ *((uint8*)(&(greHdr->seq))) = (uint8)((gre_seq)>>24); *(((uint8*)(&(greHdr->seq)))+1) = (uint8)((gre_seq)>>16); *(((uint8*)(&(greHdr->seq)))+2) = (uint8)((gre_seq)>>8); *(((uint8*)(&(greHdr->seq)))+3) = (uint8)((gre_seq)); }while(0);
                                        hdrRemain += 4;
                                }else
                                {
                                        greHdr->flags &= ~(0x10);
                                }
                                if (gre_type & 0x02)
                                {
                                        greHdr->ver |= 0x80;
                                        if (gre_type & 0x01)
                                        {
                                                do{ *((uint8*)(&(greHdr->ack))) = (uint8)(((gre_ack - pppEntry_t->un.pptp.delta__))>>24); *(((uint8*)(&(greHdr->ack)))+1) = (uint8)(((gre_ack - pppEntry_t->un.pptp.delta__))>>16); *(((uint8*)(&(greHdr->ack)))+2) = (uint8)(((gre_ack - pppEntry_t->un.pptp.delta__))>>8); *(((uint8*)(&(greHdr->ack)))+3) = (uint8)(((gre_ack - pppEntry_t->un.pptp.delta__))); }while(0);
                                        }else
                                        {
                                                do{ *((uint8*)(&(greHdr->seq))) = (uint8)(((gre_ack - pppEntry_t->un.pptp.delta__))>>24); *(((uint8*)(&(greHdr->seq)))+1) = (uint8)(((gre_ack - pppEntry_t->un.pptp.delta__))>>16); *(((uint8*)(&(greHdr->seq)))+2) = (uint8)(((gre_ack - pppEntry_t->un.pptp.delta__))>>8); *(((uint8*)(&(greHdr->seq)))+3) = (uint8)(((gre_ack - pppEntry_t->un.pptp.delta__))); }while(0);
                                        }
                                        hdrRemain += 4;
                                }else
                                {
                                        greHdr->ver &= ~(0x80);
                                }

                                rtl8651_memcpy(hdrRemain, remain, remainLen);





                                rtl8651_memcpy(data, &(svlan->macAddr), 6);
                                rtl8651_memcpy(data + 6, &(pppEntry_t->macInfo->macAddr), 6);
                                *(uint16*)((uint32)data + 12) = (0x0800);


                                ipHdr->ip_sum = 0;
                                ipHdr->ip_sum = (_rtl8651_ipChecksum(ipHdr));

                        }
                }else
                {
                        if ((pppEntry_t->un.l2tp.l2tpBuf2__ == ((void *)0)) || (pppEntry_t->un.l2tp.l2tpOffset2__ == 0))
                                goto out;
                        if (((uint32)data - (uint32)(mbuf->m_extbuf)) >= pppEntry_t->un.l2tp.l2tpOffset2__)
                        {
                                uint16 pipLen;
                                struct ip *ipBuf;
                                struct udphdr *udpBuf;
# 19573 "rtl8651_tblDrvFwd.c"
                                pipLen = (pip->ip_len);
                                ipBuf = (struct ip *)(pppEntry_t->un.l2tp.l2tpBuf2__);
                                udpBuf = (struct udphdr*)((uint8 *)ipBuf + (((*(uint8*)ipBuf)&0xf) << 2));

                                ipBuf->ip_id = ((ipBuf->ip_id) + 1);
                                ipBuf->ip_off = ((ipBuf->ip_off) & ~(0x1fff));

                                ipBuf->ip_len = (pipLen + pppEntry_t->un.l2tp.l2tpOffset2__);
                                udpBuf->uh_ulen = (pipLen + pppEntry_t->un.l2tp.l2tpOffset2__ - (((*(uint8*)ipBuf)&0xf) << 2));


                                if (*(uint8 *)((uint32)udpBuf + sizeof(struct udphdr)) & 0x40)
                                {
                                        uint16 *pLen = (uint16 *)((uint32)udpBuf + sizeof(struct udphdr) + 2);
                                        if ((pppEntry_t->un.l2tp.l2tpBuf2__[pppEntry_t->un.l2tp.l2tpOffset2__ - 2] == 0) &&
                                                (pppEntry_t->un.l2tp.l2tpBuf2__[pppEntry_t->un.l2tp.l2tpOffset2__ - 3] == 3))
                                        {
                                                *pLen = (pipLen + 12);
                                        }else
                                        {
                                                *pLen = (pipLen + 9);
                                        }
                                }

                                do {} while (0);


                                pkthdr->ph_len += pppEntry_t->un.l2tp.l2tpOffset2__;
                                mbuf->m_len += pppEntry_t->un.l2tp.l2tpOffset2__;
                                mbuf->m_data -= pppEntry_t->un.l2tp.l2tpOffset2__;


                                data = mbuf->m_data;

                                rtl8651_memcpy(data + 14, pppEntry_t->un.l2tp.l2tpBuf2__, pppEntry_t->un.l2tp.l2tpOffset2__);

                                rtl8651_memcpy(data, &(svlan->macAddr), 6);
                                rtl8651_memcpy(data + 6, &(pppEntry_t->macInfo->macAddr), 6);
                                *(uint16*)((uint32)data + 12) = (0x0800);

                                ipBuf = (struct ip *)(data + 14);
                                udpBuf = (struct udphdr *)((uint8 *)ipBuf + (((*(uint8*)ipBuf)&0xf) << 2));
                                ipBuf->ip_sum = 0;
                                udpBuf->uh_sum = 0;
                                udpBuf->uh_sum = (_rtl8651_tcpChecksum(ipBuf));
                                ipBuf->ip_sum = (_rtl8651_ipChecksum(ipBuf));
                        }
                }


                if (result != 134)
                        goto out;

                pkthdr = pkthdr->ph_nextHdr;
                if (pkthdr)
                {
                        do {} while (0);
                        pip = (struct ip *)((uint32)(pkthdr->PKTHDRNXT.mbuf_first->m_data) + pkthdr->ph_iphdrOffset);
                }
        }
out:
        return 0;
}







int _rtl8651_markDiffserv( int32 ruleNo, struct rtl_pktHdr *pkthdr, struct ip *pip, void *userDefined )
{



        if ((((*(uint8*)pip)&0xf) == 5))
        {
                pip->ip_tos = *(uint8 *)userDefined;
        } else
        {
                uint8 oldTos, newTos;

                oldTos = pip->ip_tos;
                newTos = (*(uint8 *)userDefined);

                pip->ip_tos = newTos;

                do { do { int32 accumulate = 0; if ((((newTos)) != 0) && (((oldTos)) != 0)){ accumulate = (((oldTos)) & 0xffff); accumulate += (( ((oldTos)) >> 16 ) & 0xffff); accumulate -= (((newTos)) & 0xffff); accumulate -= (( ((newTos)) >> 16 ) & 0xffff); } if (((0) != 0) && ((0) != 0)){ accumulate += (0); accumulate -= (0); } do { accumulate += (((pip->ip_sum))); if (accumulate < 0) { accumulate = -accumulate; accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) ~accumulate); } else { accumulate = (accumulate >> 16) + (accumulate & 0xffff); accumulate += accumulate >> 16; ((pip->ip_sum)) = ((uint16) accumulate); } } while (0); }while(0); }while(0);
        }

        return -1;
}







void _rtl8651_fwdEngineRetValueStatisticInit(void)
{
        memset(rtl8651_returnValue, 0, (140 + 3));
}
void _rtl8651_fwdEngineRetValueStatisticReset(void)
{
        _rtl8651_fwdEngineRetValueStatisticInit();
}
void _rtl8651_fwdEngineRetValueStatisticUpdate(int32 retval)
{
        if (retval == -1)
        {
                rtl8651_returnValue[140 + 1] ++;
                return;
        }
        if ((retval > 0) &&(retval & 0x1000))
        {
                rtl8651_returnValue[140] ++;
                retval &= ~0x1000;
        }
        if (retval > 0 && retval < 140)
        {
                rtl8651_returnValue[retval] ++;
                return;
        }
        rtl8651_returnValue[140 + 2] ++;
        return;
}
int32 _rtl8651_fwdEngineRetValueStaticDump(void)
{
        int i;
        printk("fwdEngine non-success return value Statistic:\n");
        for ( i = 0 ; i < 140 ; i ++)
        {
                if (rtl8651_returnValue[i])
                {
                        printk("Return [%d] -- count: %d\n", i, rtl8651_returnValue[i]);
                }
        }
        printk("---other ---\n");

        printk("FAILED: %d\n", rtl8651_returnValue[140 + 1]);

        printk("FWD DROP: %d\n", rtl8651_returnValue[140]);

        if (rtl8651_returnValue[140 + 2])
        {
                printk("other return values: %d\n", rtl8651_returnValue[140 + 2]);
        }
        return 0;
}
# 19732 "rtl8651_tblDrvFwd.c"
static int32 _rtl8651_trappingDispatchInit(rtl8651_fwdEngineInitPara_t *para)
{
        uint32 trappingDispatchTblSize, i;
        _rtl8651_trapping_dispatch_entry_t *ptr;


        rtl8651_trappingDispatchSystem_inUsed = ((void *)0);
        rtl8651_trappingDispatchSystem_freeHdr = ((void *)0);
        bzero(&rtl8651_trappingDispatchSystem_cache, sizeof(rtl8651_trappingDispatchSystem_cache));

        trappingDispatchTblSize = para->trappingPktDispatchTblSize;


        if (trappingDispatchTblSize == 0)
        {
                return 0;
        }

        rtl8651_trappingDispatchSystem_freeHdr =
                (_rtl8651_trapping_dispatch_entry_t *)rtlglue_malloc(trappingDispatchTblSize * sizeof(_rtl8651_trapping_dispatch_entry_t));


        if (rtl8651_trappingDispatchSystem_freeHdr == ((void *)0))
        {
                return -1;
        }


        bzero(rtl8651_trappingDispatchSystem_freeHdr, (trappingDispatchTblSize * sizeof(_rtl8651_trapping_dispatch_entry_t)));

        for (i = 0, ptr = rtl8651_trappingDispatchSystem_freeHdr;
                i < (trappingDispatchTblSize - 1) ;
                i ++, ptr ++)
        {
                ptr->next = ptr + 1;
        }

        return 0;
}




static void _rtl8651_trappingDispatchReinit(void)
{
        while (rtl8651_trappingDispatchSystem_inUsed)
        {




                        _rtl8651_removeTrappingDispatchEntry(rtl8651_trappingDispatchSystem_inUsed);




        }
}





static _rtl8651_trapping_dispatch_entry_t *_rtl8651_findTrappingDispatchEntry(
        uint8 l4Proto,
        ipaddr_t srcIp,
        ipaddr_t dstIp,
        int32 srcPort,
        int32 dstPort,
        uint8 isExactlyMatch
)
{
        _rtl8651_trapping_dispatch_entry_t *ptr;

        ptr = rtl8651_trappingDispatchSystem_inUsed;

        if (isExactlyMatch == 1)
        {
                while (ptr)
                {
                        if ((l4Proto == ptr->l4Proto) &&
                             (srcIp == ptr->srcIp) &&
                             (dstIp == ptr->dstIp) &&
                             ((srcPort < 0 && ptr->srcPort < 0) || (srcPort == ptr->srcPort)) &&
                             ((dstPort < 0 && ptr->dstPort < 0) || (dstPort == ptr->dstPort)))
                        {
                                return ptr;
                        }
                        ptr = ptr->next;
                }
        }else
        {


                if ( (l4Proto == rtl8651_trappingDispatchSystem_cache.l4Proto) &&
                        (srcIp == rtl8651_trappingDispatchSystem_cache.srcIp) &&
                        (dstIp == rtl8651_trappingDispatchSystem_cache.dstIp) &&
                        (srcPort == rtl8651_trappingDispatchSystem_cache.srcPort) &&
                        (dstPort == rtl8651_trappingDispatchSystem_cache.dstPort) &&
                        rtl8651_trappingDispatchSystem_cache.ptr)
                {
                        return rtl8651_trappingDispatchSystem_cache.ptr;
                }


                while (ptr)
                {
                        if ( (ptr->l4Proto == 0 || l4Proto == ptr->l4Proto) &&
                             (ptr->srcIp == 0 || srcIp == ptr->srcIp) &&
                             (ptr->dstIp == 0 || dstIp == ptr->dstIp) &&
                             (ptr->srcPort < 0 || srcPort == ptr->srcPort) &&
                             (ptr->dstPort < 0 || dstPort == ptr->dstPort))
                        {


                                rtl8651_trappingDispatchSystem_cache.l4Proto = l4Proto;
                                rtl8651_trappingDispatchSystem_cache.srcIp = srcIp;
                                rtl8651_trappingDispatchSystem_cache.dstIp = dstIp;
                                rtl8651_trappingDispatchSystem_cache.srcPort = srcPort;
                                rtl8651_trappingDispatchSystem_cache.dstPort = dstPort;
                                rtl8651_trappingDispatchSystem_cache.ptr = ptr;

                                return ptr;
                        }
                        ptr = ptr->next;
                }
        }

        return ((void *)0);
}
# 19883 "rtl8651_tblDrvFwd.c"
int32 rtl8651_registerTrappingDispatchEntry(
        uint8 l4Proto,
        ipaddr_t srcIp,
        ipaddr_t dstIp,
        int32 srcPort,
        int32 dstPort,
        uint16 category
)
{
        int32 retval;
# 19902 "rtl8651_tblDrvFwd.c"
        if ( (l4Proto != 6) &&
              (l4Proto != 17))
        {
                srcPort = -1;
                dstPort = -1;
        }

        rtlglue_drvMutexLock();

        retval = _rtl8651_registerTrappingDispatchEntry(l4Proto,
                                                                                         srcIp,
                                                                                         dstIp,
                                                                                         srcPort,
                                                                                         dstPort,
                                                                                         category);

        rtlglue_drvMutexUnlock();

        return retval;
}







static int32 _rtl8651_registerTrappingDispatchEntry(
        uint8 l4Proto,
        ipaddr_t srcIp,
        ipaddr_t dstIp,
        int32 srcPort,
        int32 dstPort,
        uint16 category
)
{
        _rtl8651_trapping_dispatch_entry_t *newEntry;
        int32 retval = -1;


        if ((newEntry = _rtl8651_findTrappingDispatchEntry(
                                l4Proto,
                                srcIp,
                                dstIp,
                                srcPort,
                                dstPort,
                                1 )) != ((void *)0))
        {
                newEntry->category = category;
                retval = 0;
                goto out;
        }


        if (rtl8651_trappingDispatchSystem_freeHdr == ((void *)0))
        {
                retval = -1;
                goto out;
        }




        bzero(&rtl8651_trappingDispatchSystem_cache, sizeof(rtl8651_trappingDispatchSystem_cache));


        newEntry = rtl8651_trappingDispatchSystem_freeHdr;
        rtl8651_trappingDispatchSystem_freeHdr = rtl8651_trappingDispatchSystem_freeHdr->next;


        newEntry->next = rtl8651_trappingDispatchSystem_inUsed;
        newEntry->prev = ((void *)0);

        if (rtl8651_trappingDispatchSystem_inUsed)
        {
                rtl8651_trappingDispatchSystem_inUsed->prev = newEntry;
        }
        rtl8651_trappingDispatchSystem_inUsed = newEntry;


        newEntry->l4Proto = l4Proto;
        newEntry->srcIp = srcIp;
        newEntry->dstIp = dstIp;
        newEntry->srcPort = srcPort;
        newEntry->dstPort = dstPort;
        newEntry->category = category;

        retval = 0;

out:
        return retval;
}





static void _rtl8651_removeTrappingDispatchEntry(_rtl8651_trapping_dispatch_entry_t *delEntry)
{

        if (rtl8651_trappingDispatchSystem_cache.ptr == delEntry)
        {
                bzero(&rtl8651_trappingDispatchSystem_cache, sizeof(rtl8651_trappingDispatchSystem_cache));
        }


        if (delEntry->prev)
        {
                delEntry->prev->next = delEntry->next;
        }
        if (delEntry->next)
        {
                delEntry->next->prev = delEntry->prev;
        }
        if (rtl8651_trappingDispatchSystem_inUsed == delEntry)
        {
                rtl8651_trappingDispatchSystem_inUsed = delEntry->next;
        }


        delEntry->next = rtl8651_trappingDispatchSystem_freeHdr;
        rtl8651_trappingDispatchSystem_freeHdr = delEntry;
}
# 20041 "rtl8651_tblDrvFwd.c"
int32 rtl8651_unregisterTrappingDispatchEntry(
        uint8 l4Proto,
        ipaddr_t srcIp,
        ipaddr_t dstIp,
        int32 srcPort,
        int32 dstPort
)
{
        int32 retval;

        if ( (l4Proto != 6) &&
              (l4Proto != 17))
        {
                srcPort = -1;
                dstPort = -1;
        }

        rtlglue_drvMutexLock();
        retval = _rtl8651_unregisterTrappingDispatchEntry(
                                l4Proto,
                                srcIp,
                                dstIp,
                                srcPort,
                                dstPort);
        rtlglue_drvMutexUnlock();
        return retval;
}






static int32 _rtl8651_unregisterTrappingDispatchEntry(
        uint8 l4Proto,
        ipaddr_t srcIp,
        ipaddr_t dstIp,
        int32 srcPort,
        int32 dstPort
)
{
        _rtl8651_trapping_dispatch_entry_t *delEntry;

        delEntry = _rtl8651_findTrappingDispatchEntry(
                                l4Proto,
                                srcIp,
                                dstIp,
                                srcPort,
                                dstPort,
                                1);

        if (delEntry)
        {
                _rtl8651_removeTrappingDispatchEntry(delEntry);


                return 1;
        }


        return 0;

}





static uint16 _rtl8651_getTrappingDispatchCategory(struct ip *pip)
{
        ipaddr_t srcIp, dstIp;
        int32 srcPort, dstPort;
        uint8 l4Proto;
        uint16 offset;
        uint16 category = 0;
        _rtl8651_trapping_dispatch_entry_t *ptr;


        srcIp = ((uint32) (*((uint8*)(&pip->ip_src))<<24)|(*(((uint8*)(&pip->ip_src))+1)<<16)|(*(((uint8*)(&pip->ip_src))+2)<<8) | *(((uint8*)(&pip->ip_src))+3));
        dstIp = ((uint32) (*((uint8*)(&pip->ip_dst))<<24)|(*(((uint8*)(&pip->ip_dst))+1)<<16)|(*(((uint8*)(&pip->ip_dst))+2)<<8) | *(((uint8*)(&pip->ip_dst))+3));
        offset = pip->ip_off;
        l4Proto = pip->ip_p;

        if ((((uint16)(offset)) & 0x1fff))
        {

                uint16 ipId;

                ipId = (pip->ip_id);

                if (_rtl8651_getFragCache(7,
                                srcIp,
                                dstIp,
                                ipId,
                                (ipaddr_t *)(&category), ((void *)0), ((void *)0), ((void *)0)) == 0)
                {
                        goto out;
                }


                srcPort = -1;
                dstPort = -1;
                goto find;
        }


        switch (l4Proto)
        {
                case 6:
                {
                        struct tcphdr *tcpHdr;

                        tcpHdr = (struct tcphdr *)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));
                        srcPort = (tcpHdr->th_sport);
                        dstPort = (tcpHdr->th_dport);
                        break;
                }

                case 17:
                {
                        struct udphdr *udpHdr;

                        udpHdr = (struct udphdr *)((uint8 *)pip + (((*(uint8*)pip)&0xf) << 2));
                        srcPort = (udpHdr->uh_sport);
                        dstPort = (udpHdr->uh_dport);
                        break;
                }

                default:

                        srcPort = -1;
                        dstPort = -1;
        }

find:

        if ((ptr = _rtl8651_findTrappingDispatchEntry(
                                l4Proto,
                                srcIp,
                                dstIp,
                                srcPort,
                                dstPort,
                                0)) != ((void *)0))
        {

                category = ptr->category;

                if (((((uint16)(offset)) & (0x1fff|0x2000)) == 0x2000))
                {

                        uint16 ipId;

                        ipId = (pip->ip_id);

                        _rtl8651_updateFragCache(7,
                                srcIp,
                                dstIp,
                                ipId,
                                (ipaddr_t)category,
                                0, ((void *)0), 0);
                }
                goto out;
        }

        category = 0;

out:
        return category;
}
