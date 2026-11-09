#include "pc_quat_dot_q.h"

#include <limits.h>
#include <stddef.h>

#define Q30_ONE INT32_C(1073741824)

bool rm_quat_dot_q(const int32_t a[4], const int32_t b[4], int32_t *dot_q1_30)
{
    int64_t sum = 0;
    uint64_t magnitude;
    uint64_t quotient;
    uint64_t remainder;
    unsigned i;
    int64_t rounded;
    if (a == NULL || b == NULL || dot_q1_30 == NULL) return false;
    for (i = 0u; i < 4u; ++i) {
        if (a[i] < -Q30_ONE || a[i] > Q30_ONE ||
            b[i] < -Q30_ONE || b[i] > Q30_ONE) return false;
        sum += (int64_t)a[i] * (int64_t)b[i];
    }
    magnitude = sum < 0 ? (uint64_t)(-sum) : (uint64_t)sum;
    quotient = magnitude >> 30;
    remainder = magnitude & ((UINT64_C(1) << 30) - 1u);
    if (remainder > (UINT64_C(1) << 29) ||
        (remainder == (UINT64_C(1) << 29) && (quotient & 1u) != 0u)) ++quotient;
    rounded = sum < 0 ? -(int64_t)quotient : (int64_t)quotient;
    if (rounded < INT32_MIN || rounded > INT32_MAX) return false;
    *dot_q1_30 = (int32_t)rounded;
    return true;
}
