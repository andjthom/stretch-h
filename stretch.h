// Usage:
//   TYPE *my_sb = NULL;
//   ...

#ifndef STRETCH_H
#define STRETCH_H

#include <stdlib.h>

#define __SB_HDR(v) ((int *)(v) - 2)
#define __SB_LEN(v) __SB_HDR(v)[0]
#define __SB_CAP(v) __SB_HDR(v)[1]

#define __SB_FITS(v, n) (sbLen(v) + (n) <= sbCap(v))
#define __SB_FIT(v, n) (__SB_FITS(v, n) ? 0 : ((v) = __sbGrow((v), sbLen(v) + (n), sizeof(*(v)))))

#define sbLen(v) ((v) ? (__SB_LEN(v)) : 0)
#define sbCap(v) ((v) ? (__SB_CAP(v)) : 0)
#define sbPush(v, x) (__SB_FIT(v, 1), (v)[__SB_LEN(v)++] = (x))
#define sbFree(v) ((v) ? (free(__SB_HDR(v)), (v) = NULL) : 0)

static void * __sbGrow(const void *buf, const int new_len, const int elem_size)
{
    int new_cap = 2 * sbCap(buf) + 1;
    if (new_cap < new_len) {
        new_cap = new_len;
    }

    int new_size = new_cap * elem_size + 2 * sizeof(int);
    int *new_buf;
    if (buf) {
        new_buf = (int *)realloc(__SB_HDR(buf), new_size);
    } else {
        new_buf = (int *)malloc(new_size);
    }

    if (new_buf) {
        if (!buf) {
            new_buf[0] = 0;
        }

        new_buf[1] = new_cap;
        return new_buf + 2;
    } else {
        return NULL;
    }
}

#endif
