#include "pc_quat_rotate_vec3_q.h"
#include "pc_quat_normalize_q.h"

#include <limits.h>
#include <stddef.h>

#define ONE INT64_C(1073741824)

static int64_t round_shift30(int64_t x)
{
    uint64_t m = x < 0 ? (uint64_t)(-x) : (uint64_t)x;
    uint64_t q = m >> 30;
    uint64_t r = m & ((UINT64_C(1) << 30) - 1u);
    uint64_t h = UINT64_C(1) << 29;
    if (r > h || (r == h && (q & 1u))) ++q;
    return x < 0 ? -(int64_t)q : (int64_t)q;
}

static void cross_q30(const int32_t a[3], const int32_t b[3], int32_t out[3])
{
    int64_t x = (int64_t)a[1]*b[2] - (int64_t)a[2]*b[1];
    int64_t y = (int64_t)a[2]*b[0] - (int64_t)a[0]*b[2];
    int64_t z = (int64_t)a[0]*b[1] - (int64_t)a[1]*b[0];
    out[0] = (int32_t)round_shift30(x);
    out[1] = (int32_t)round_shift30(y);
    out[2] = (int32_t)round_shift30(z);
}

bool pc_quat_rotate_vec3_q(const int32_t q[4], const int32_t v[3], int32_t output[3])
{
    int32_t n[4], u[3], uv[3], inner[3], outer[3], result[3];
    unsigned i;
    if (q == NULL || v == NULL || output == NULL) return false;
    for (i=0u;i<3u;i++) if (v[i] < -ONE || v[i] > ONE) return false;
    if (!pc_quat_normalize_q(q,n)) return false;
    for (i=0u;i<3u;i++) u[i]=n[i+1u];
    cross_q30(u,v,uv);
    for (i=0u;i<3u;i++) {
        int64_t t=round_shift30((int64_t)n[0]*v[i])+(int64_t)uv[i];
        if (t < INT32_MIN || t > INT32_MAX) return false;
        inner[i]=(int32_t)t;
    }
    cross_q30(u,inner,outer);
    for (i=0u;i<3u;i++) {
        int64_t x=(int64_t)v[i]+2*(int64_t)outer[i];
        if (x < INT32_MIN || x > INT32_MAX) return false;
        result[i]=(int32_t)x;
    }
    for (i=0u;i<3u;i++) output[i]=result[i];
    return true;
}
