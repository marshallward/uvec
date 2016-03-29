#ifndef _UVEC_H_
#define _UVEC_H_

#include <stddef.h>     /* size_t */

typedef struct _UVec {
    int size;
    int itemsize;

    int ndims;
    int *dims;
    int *strides;

    char *data;
} UVec;

/* UVec API */

int uv_create(UVec *v, size_t itemsize, int ndims, int *dims);
int uv_assign(UVec *v, char *val);

#endif /* _UVEC_H_ */
