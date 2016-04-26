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

#endif /* _UVTYPES_H_ */
