#include "pc_quat_norm2_q.h"

#include <stddef.h>

#define Q30_ONE INT32_C(1073741824)

bool pc_quat_norm2_q(const int32_t q[4], uint64_t *norm2_q2_60)
{
    uint64_t sum = 0u;
    unsigned i;
    if (q == NULL || norm2_q2_60 == NULL) return false;
    for (i = 0u; i < 4u; ++i) {
        int64_t component;
        if (q[i] < -Q30_ONE || q[i] > Q30_ONE) return false;
        component = q[i];
        sum += (uint64_t)(component * component);
    }
    *norm2_q2_60 = sum;
    return true;
}
