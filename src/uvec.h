#ifndef _UVEC_H_
#define _UVEC_H_

#include <stddef.h>     /* size_t */

typedef struct _UVec {
    char *data;
    int ndims;
    int *dims;
    int *strides;
} UVec;

/* UVec API */

int uv_create(UVec *v, size_t dsize, int ndims, int *dims);
int uv_free(UVec *v);

#endif /* _UVEC_H_ */
