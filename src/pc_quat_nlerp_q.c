#include "pc_quat_nlerp_q.h"

#include "pc_quat_normalize_q.h"

#include <stddef.h>

#define Q30_ONE INT32_C(1073741824)

static int64_t divide_round_even(int64_t numerator, uint32_t denominator)
{
    uint64_t magnitude = numerator < 0 ? (uint64_t)(-numerator) : (uint64_t)numerator;
    uint64_t quotient = magnitude / denominator;
    uint64_t remainder = magnitude % denominator;
    if (remainder > (uint64_t)denominator - remainder ||
        (remainder == (uint64_t)denominator - remainder && (quotient & 1u) != 0u)) ++quotient;
    return numerator < 0 ? -(int64_t)quotient : (int64_t)quotient;
}

bool pc_quat_nlerp_q(const int32_t a[4], const int32_t b[4],
                     uint32_t numerator, uint32_t denominator,
                     int32_t output[4])
{
    int64_t dot = 0;
    int32_t adjusted_b[4];
    int32_t blend[4];
    int32_t normalized[4];
    unsigned i;
    if (a == NULL || b == NULL || output == NULL || denominator == 0u ||
        numerator > denominator) return false;
    for (i = 0u; i < 4u; ++i) {
        if (a[i] < -Q30_ONE || a[i] > Q30_ONE ||
            b[i] < -Q30_ONE || b[i] > Q30_ONE) return false;
        dot += (int64_t)a[i] * b[i];
    }
    for (i = 0u; i < 4u; ++i) adjusted_b[i] = dot < 0 ? -b[i] : b[i];
    for (i = 0u; i < 4u; ++i) {
        int64_t weighted = (int64_t)a[i] * (int64_t)(denominator - numerator) +
                           (int64_t)adjusted_b[i] * (int64_t)numerator;
        int64_t component = divide_round_even(weighted, denominator);
        if (component < -Q30_ONE || component > Q30_ONE) return false;
        blend[i] = (int32_t)component;
    }
    if (!pc_quat_normalize_q(blend, normalized)) return false;
    for (i = 0u; i < 4u; ++i) output[i] = normalized[i];
    return true;
}
