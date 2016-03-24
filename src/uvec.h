#ifndef _UVEC_H_
#define _UVEC_H_

typedef struct _UVec {
    char *data;
    int ndims;
    int *dims;
    int *strides;
} UVec;

/* UVec API */

int UVec_create(UVec *v, int *dims, int *strides);
int UVec_free(UVec *v);

#endif /* _UVEC_H_ */
