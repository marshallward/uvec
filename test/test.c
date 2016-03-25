#include "uvec.h"

int main(int argc, char **argv)
{
    UVec *v;
    int ndims = 2;
    int dims[] = {3, 2};
    int rc;

    rc = uv_create(v, sizeof(int), ndims, dims);
    return rc;
}
