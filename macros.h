#ifndef SB_MACROS_H___
#define SB_MACROS_H___

#define Check(x) if(!(#x)) printf("%s:%d %s", __FILE__, __LINE__, #x);
#endif
