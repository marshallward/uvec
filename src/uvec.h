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

/* Dummy testing type */
union utype {
    int i;
    float f;
};

/* UVec API */

UVec * uv_create(size_t itemsize, int ndims, int *dims);
int uv_assign(UVec *v, union utype c);
int uv_add(UVec *t, UVec *u, UVec *v);

#endif /* _UVEC_H_ */
