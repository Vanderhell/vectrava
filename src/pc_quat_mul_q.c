#include "pc_quat_mul_q.h"

#include <limits.h>
#include <stddef.h>

#define Q30_ONE INT32_C(1073741824)

static int64_t round_shift_q30(int64_t value)
{
    uint64_t magnitude = value < 0 ? (uint64_t)(-value) : (uint64_t)value;
    uint64_t quotient = magnitude >> 30;
    uint64_t remainder = magnitude & ((UINT64_C(1) << 30) - 1u);
    uint64_t half = UINT64_C(1) << 29;
    if (remainder > half || (remainder == half && (quotient & 1u) != 0u)) ++quotient;
    return value < 0 ? -(int64_t)quotient : (int64_t)quotient;
}

bool rm_quat_mul_q(const int32_t a[4], const int32_t b[4], int32_t output[4])
{
    int64_t aw, ax, ay, az, bw, bx, by, bz;
    int64_t sums[4];
    int32_t result[4];
    unsigned i;
    if (a == NULL || b == NULL || output == NULL) return false;
    for (i = 0u; i < 4u; ++i) {
        if (a[i] < -Q30_ONE || a[i] > Q30_ONE ||
            b[i] < -Q30_ONE || b[i] > Q30_ONE) return false;
    }
    aw = a[0]; ax = a[1]; ay = a[2]; az = a[3];
    bw = b[0]; bx = b[1]; by = b[2]; bz = b[3];
    sums[0] = aw*bw - ax*bx - ay*by - az*bz;
    sums[1] = aw*bx + ax*bw + ay*bz - az*by;
    sums[2] = aw*by - ax*bz + ay*bw + az*bx;
    sums[3] = aw*bz + ax*by - ay*bx + az*bw;
    for (i = 0u; i < 4u; ++i) {
        int64_t rounded = round_shift_q30(sums[i]);
        if (rounded < INT32_MIN || rounded > INT32_MAX) return false;
        result[i] = (int32_t)rounded;
    }
    for (i = 0u; i < 4u; ++i) output[i] = result[i];
    return true;
}
