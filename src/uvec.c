#include <stddef.h> /* size_t */
#include <stdlib.h> /* malloc */
#include <string.h> /* memcpy */

#include "uvec.h"

UVec * uv_create(size_t itemsize, int ndims, int *dims)
{
    UVec *v;
    int i, size;

    /* TODO: Contiguous struct content (header?) */
    v = malloc(sizeof(UVec));

    size = 1;
    for (i = 0; i < ndims; i++)
        size *= dims[i];

    v->size = size;
    v->itemsize = itemsize;
    v->nbytes = (size_t) size * itemsize;
    v->data = malloc(v->nbytes);

    v->ndims = ndims;
    v->dims = malloc((size_t) ndims);
    for (i = 0; i < ndims; i++)
        v->dims[i] = dims[i];

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


int uv_add(UVec *t, UVec *u, UVec *v)
{
    int i;

    int *tt, *uu, *vv;

    tt = (int *)t->data;
    uu = (int *)u->data;
    vv = (int *)v->data;

    for (i = 0; i < v->size; i++) {
        tt[i] = uu[i] + vv[i];
    }

    return 0;
}


/* XXX: Temporary assignment function */
int uv_assign(UVec *v, union utype c)
{
    int b;
    for (b = 0; b < v->nbytes; b += v->itemsize)
        memcpy(v->data + b, &c, v->itemsize);

    return 0;
}
