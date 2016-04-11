#ifndef _UVTYPES_H_
#define _UVTYPES_H_

typedef enum _uv_type {
    UV_CHAR = 0,
    UV_SCHAR,
    UV_UCHAR,

    UV_SHORT,
    UV_USHORT,

    UV_INT,
    UV_UINT,

    UV_LONG,
    UV_ULONG,

    UV_LONGLONG,
    UV_ULONGLONG,

    UV_FLOAT,
    UV_DOUBLE,
    UV_LONGDOUBLE
} uv_type;

#define UV_NTYPES (UV_LONGDOUBLE + 1)

/* TODO: I don't know how to set the values of uv_tsize */
extern size_t uv_tsize;

/*
uv_tsize[UV_CHAR] = sizeof(char);
uv_tsize[UV_SCHAR] = sizeof(signed char);
uv_tsize[UV_UCHAR] = sizeof(unsigned char);

uv_tsize[UV_SHORT] = sizeof(short);
uv_tsize[UV_USHORT] = sizeof(unsigned short);

uv_tsize[UV_INT] = sizeof(int);
uv_tsize[UV_UINT] = sizeof(int);

uv_tsize[UV_LONG] = sizeof(long);
uv_tsize[UV_ULONG] = sizeof(unsigned long);

uv_tsize[UV_LONGLONG] = sizeof(long long);
uv_tsize[UV_ULONGLONG] = sizeof(unsigned long long);

uv_tsize[UV_FLOAT] = sizeof(float);
uv_tsize[UV_DOUBLE] = sizeof(double);
uv_tsize[UV_LONGDOUBLE] = sizeof(long double);
*/
#endif /* _UVTYPES_H_ */
