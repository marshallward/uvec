#ifndef _UVEC_H_
#define _UVEC_H_

#include <stddef.h>     /* size_t */

/* uvec dtypes (cut and pasted from NumPy) */
/* TODO: Unsigned types */
typedef enum _uv_type {
    UV_BOOL = 0,
    UV_BYTE,
    UV_SHORT,
    UV_INT,
    UV_LONG,
    UV_LONGLONG,
    UV_FLOAT,
    UV_DOUBLE,
    UV_LONGDOUBLE
} uv_type;


typedef struct _uvec {
    int size;
    size_t itemsize;
    size_t nbytes;

    int ndims;
    int *dims;
    int *strides;

    uv_type dtype;

    char *data;
} uvec;


/* Dummy testing type */
union utype {
    int i;
    float f;
};


/* uvec API */

uvec * uv_create(size_t itemsize, int ndims, int *dims);
int uv_assign(uvec *v, union utype c);
int uv_add(uvec *t, uvec *u, uvec *v);

#endif /* _UVEC_H_ */
