#include <stddef.h>
#include <stdlib.h>

#include "uvec.h"

int uv_create(UVec *v, size_t itemsize, int ndims, int *dims)
{
    int i, size;

    size = 1;
    for (i = 0; i < ndims; i++)
        size *= dims[i];

    v->size = size;
    v->itemsize = itemsize;
    v->data = malloc((size_t) size * itemsize);

    v->ndims = ndims;
    v->dims = malloc((size_t) ndims);
    for (i = 0; i < ndims; i++)
        v->dims[i] = dims[i];



    /* XXX: Assume row-major (C-ordered) strides */
    v->strides = malloc((size_t) ndims);
    v->strides[ndims - 1] = itemsize;
    for (i = ndims - 2; i >= 0; i--)
        v->strides[i] = v->strides[i + 1] * dims[i + 1];

    /* TODO: Column-major strides */

    /*
    v->strides = malloc((size_t) ndims);
    v->strides[0] = itemsize;
    for (i = 1; i < ndims; i++)
        v->strides[i] = v->strides[i - 1] * dims[i - 1];
    */

    return 0;
}


/* Dummy testing function */
int uv_assign(UVec *v, char *val)
{
    int i, b, offset;

    for (i = 0; i < v->size; i++) {
        offset += v->itemsize;
        for (b = 0; b < v->itemsize; b++) {
            v->data[offset + b] = val[b];
        }
    }

    return 0;
}
