#ifndef _UVEC_H_
#define _UVEC_H_

#include <stddef.h>     /* size_t */
#include "types.h"      /* uv_type */

typedef struct _uvec {
    int size;
    size_t itemsize;
    size_t nbytes;

    int ndims;
    int *dims;
    int *strides;

    uv_type dtype;

    /* Methods */
    int (*add)();
    int (*sum)();

    char *data;
} uvec;


/* Dummy testing type */
/* TODO: Remove, replace with pointer */
union utype {
    int i;
    float f;
};


/* uvec API */

uvec * uv_create(uv_type dtype, int ndims, int *dims);
void uv_free(uvec *v);

int uv_add_int(uvec *t, uvec *u, uvec *v);
int uv_sum_int(uvec *v);

int uv_assign(uvec *v, union utype c);

#endif /* _UVEC_H_ */
