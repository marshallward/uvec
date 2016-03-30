#include <stdio.h>
#include "uvec.h"

int main(int argc, char **argv)
{
    UVec *v;
    int ndims = 2;
    int dims[] = {3, 2};
    int i, rc;

    union utype c;
    c.i = 42;

    rc = uv_create(v, sizeof(int), ndims, dims);
    rc = uv_assign(v, c);

    for (i = 0; i < v->nbytes; i += v->itemsize)
        printf("(%i): %i\n", i, *(int *)(v->data + i));

    return rc;
}
