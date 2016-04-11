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

    v = malloc(sizeof(uvec));

    size = 1;
    for (i = 0; i < ndims; i++)
        size *= dims[i];

    /* TODO: Pre-calculate item sizes, save to uv_tsize */
    switch(dtype) {
        case UV_CHAR:
            itemsize = sizeof(char);
            break;
        case UV_INT:
            itemsize = sizeof(int);
            break;
        case UV_FLOAT:
            itemsize = sizeof(float);
            break;
        case UV_DOUBLE:
            itemsize = sizeof(double);
            break;
        default:
            /* TODO */
            itemsize = sizeof(char);
    }

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
    switch(dtype) {
        case UV_INT:
            v->add = uv_add_int;
            v->sum = uv_sum_int;
            break;
        default:
            /* TODO */
            v->add = uv_add_int;
            v->sum = uv_sum_int;
    }

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
