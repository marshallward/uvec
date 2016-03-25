#include <stddef.h>
#include <stdlib.h>

#include "uvec.h"

int uv_create(UVec *v, size_t dsize, int ndims, int *dims)
{
    int i, size;

    size = dsize;
    for (i = 0; i < ndims; i++)
        size *= dims[i];
    v->data = malloc((size_t) size);

    v->ndims = ndims;
    v->dims = malloc((size_t) ndims);
    for (i = 0; i < ndims; i++)
        v->dims[i] = dims[i];

    return 0;
}
