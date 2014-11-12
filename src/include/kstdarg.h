#ifndef _KERNEL_STDARG_H_
#define _KERNEL_STDARG_H_

typedef unsigned char *va_list;

#define VA_SIZE(TYPE) ((sizeof(TYPE) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define va_start(AP, LASTARG) (AP=((va_list)&(LASTARG) + VA_SIZE(LASTARG)))
#define va_end(AP)
#define va_arg(AP, TYPE) (AP += VA_SIZE(TYPE), *((TYPE *)(AP - VA_SIZE(TYPE))))

#endif /*!_KERNEL_STDARG_H_*/
