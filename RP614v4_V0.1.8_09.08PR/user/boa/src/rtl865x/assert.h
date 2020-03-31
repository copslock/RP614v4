#if 0
#  define assert(expr) do {} while (0)
#else
#  define assert(expr) \
        if(!(expr)) {					\
        printk( "%s:%d: %s\n",	\
        __FILE__,__LINE__,#expr);		\
        }
#endif


