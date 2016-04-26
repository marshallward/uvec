#ifndef _UVMETHODS_H_
#define _UVMETHODS_H_

#include "types.h"
#include "uvec.h"

size_t dtypesize[UV_NTYPES] = {
    sizeof(char),               /* UV_CHAR */
    sizeof(signed char),        /* UV_SCHAR */
    sizeof(unsigned char),      /* UV_UCHAR */
    sizeof(short),              /* UV_SHORT */
    sizeof(unsigned short),     /* UV_USHORT */
    sizeof(int),                /* UV_INT */
    sizeof(unsigned int),       /* UV_UINT */
    sizeof(long),               /* UV_LONG */
    sizeof(unsigned long),      /* UV_ULONG */
    sizeof(long long),          /* UV_LONGLONG */
    sizeof(unsigned long long), /* UV_ULONGLONG */
    sizeof(float),              /* UV_FLOAT */
    sizeof(double),             /* UV_DOUBLE */
    sizeof(long double)         /* UV_LONGDOUBLE */
};

int (*uv_add_funcs[UV_NTYPES])(uvec *t, uvec *u, uvec *v) = {
    NULL, /* UV_CHAR */
    NULL, /* UV_SCHAR */
    NULL, /* UV_UCHAR */
    NULL, /* UV_SHORT */
    NULL, /* UV_USHORT */
    uv_add_int, /* UV_INT */
    NULL, /* UV_UINT */
    NULL, /* UV_LONG */
    NULL, /* UV_ULONG */
    NULL, /* UV_LONGLONG */
    NULL, /* UV_ULONGLONG */
    NULL, /* UV_FLOAT */
    NULL, /* UV_DOUBLE */
    NULL, /* UV_LONGDOUBLE */
};

/* TODO: They can't all return `int`... */
/*       But sum needs to support vector output anyway */
static int (*uv_sum_funcs[UV_NTYPES])(uvec *u) = {
    NULL, /* UV_CHAR */
    NULL, /* UV_SCHAR */
    NULL, /* UV_UCHAR */
    NULL, /* UV_SHORT */
    NULL, /* UV_USHORT */
    uv_sum_int, /* UV_INT */
    NULL, /* UV_UINT */
    NULL, /* UV_LONG */
    NULL, /* UV_ULONG */
    NULL, /* UV_LONGLONG */
    NULL, /* UV_ULONGLONG */
    NULL, /* UV_FLOAT */
    NULL, /* UV_DOUBLE */
    NULL, /* UV_LONGDOUBLE */
};

#endif /* _UVMETHODS_H_ */
