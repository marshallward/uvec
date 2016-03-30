#ifndef _UVEC_H_
#define _UVEC_H_

#include <stddef.h>     /* size_t */

typedef struct _UVec {
    int size;
    size_t itemsize;
    size_t nbytes;

    int ndims;
    int *dims;
    int *strides;

    char *data;
} UVec;

/* Dummy testing function */
union utype {
    int i;
    float f;
};

/* UVec API */

int uv_create(UVec *v, size_t itemsize, int ndims, int *dims);
int uv_assign(UVec *v, union utype c);

#endif /* _UVEC_H_ */
