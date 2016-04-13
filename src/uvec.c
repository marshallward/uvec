#include <stddef.h> /* size_t */
#include <stdlib.h> /* malloc */
#include <string.h> /* memcpy */

#include "uvec.h"

uvec * uv_create(uv_type dtype, int ndims, int *dims)
{
    uvec *v;
    int size;
    size_t itemsize;

    int i;

    /* Datatype lookup tables */
    /* TODO: Define externally? */

    static size_t dtypesize[UV_NTYPES] = {
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

    static int (*uv_add_funcs[UV_NTYPES])(uvec *t, uvec *u, uvec *v) = {
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

    /* Object fields */

    v = malloc(sizeof(uvec));

    size = 1;
    for (i = 0; i < ndims; i++)
        size *= dims[i];

    itemsize = dtypesize[dtype];

    v->dtype = dtype;
    v->size = size;
    v->itemsize = itemsize;
    v->nbytes = (size_t) size * itemsize;
    v->data = malloc(v->nbytes);

    v->ndims = ndims;
    v->dims = malloc((size_t) ndims);
    for (i = 0; i < ndims; i++)
        v->dims[i] = dims[i];

    /* Method assignment */
    /* TODO: Pre-calculated hash tables */
    v->add = uv_add_funcs[dtype];
    v->sum = uv_sum_funcs[dtype];

    /* XXX: Temporary explicit stride settings */

    /* Row-major (C-ordered) strides */
    v->strides = malloc((size_t) ndims);
    v->strides[ndims - 1] = itemsize;
    for (i = ndims - 2; i >= 0; i--)
        v->strides[i] = v->strides[i + 1] * dims[i + 1];

    /* Column-major strides */
    // v->strides = malloc((size_t) ndims);
    // v->strides[0] = itemsize;
    // for (i = 1; i < ndims; i++)
    //     v->strides[i] = v->strides[i - 1] * dims[i - 1];

    return v;
}


void uv_free(uvec *v)
{
    free(v->data);
    free(v->strides);
    free(v->dims);
    free(v);
}


int uv_add_int(uvec *t, uvec *u, uvec *v)
{
    int i;

    int *tt, *uu, *vv;

    tt = (int *)t->data;
    uu = (int *)u->data;
    vv = (int *)v->data;

    for (i = 0; i < v->size; i++)
        tt[i] = uu[i] + vv[i];

    return 0;
}


int uv_sum_int(uvec *v)
{
    int i, sum;
    int *vv;

    vv = (int *)v->data;

    sum = 0;
    for (i = 0; i < v->size; i++)
        sum += vv[i];

    return sum;
}


/* XXX: Temporary assignment function */
/* PS: unions are dumb */
int uv_assign(uvec *v, union utype c)
{
    int b;
    for (b = 0; b < v->nbytes; b += v->itemsize)
        memcpy(v->data + b, &c, v->itemsize);

    return 0;
}
