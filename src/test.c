#include <stdio.h>
#include <stdlib.h>

#include "uvec.h"

int main(int argc, char **argv)
{
    uvec *v, *w;
    int ndims = 2;
    int dims[] = {3, 2};
    int i, rc;

    union utype c;
    c.i = 42;

    v = uv_create(UV_INT, ndims, dims);
    uv_assign(v, c);

    for (i = 0; i < v->nbytes; i += v->itemsize)
        printf("(%i): %i\n", i, *(int *)(v->data + i));

    w = uv_create(UV_INT, ndims, dims);
    v->add(w, v, v);

    for (i = 0; i < w->nbytes; i += w->itemsize)
        printf("(%i): %i\n", i, *(int *)(w->data + i));

    return rc;
}
