#include "pc_affine2_apply_q.h"
#include "pc_checked_add_i64.h"
#include <limits.h>
#include <stddef.h>

static int64_t round_i64_rne(int64_t value, unsigned fractional_bits)
{
    const uint64_t magnitude = value < 0 ? (uint64_t)(-(value + 1)) + 1u : (uint64_t)value;
    const uint64_t denominator = UINT64_C(1) << fractional_bits;
    uint64_t quotient = magnitude / denominator;
    const uint64_t remainder = magnitude % denominator;
    if (remainder > denominator - remainder ||
        (remainder == denominator - remainder && (quotient & 1u) != 0u)) ++quotient;
    if (value >= 0) return (int64_t)quotient;
    if (quotient == (UINT64_C(1) << 63)) return INT64_MIN;
    return -(int64_t)quotient;
}

bool rm_affine2_apply_q(const rm_matrix2_q *matrix, const int32_t point[2],
                        const int32_t translation[2], unsigned fractional_bits,
                        int32_t output[2])
{
    int32_t p[2], t[2], result[2];
    unsigned i;
    if (matrix == NULL || point == NULL || translation == NULL || output == NULL ||
        fractional_bits > 31u) return false;
    p[0] = point[0]; p[1] = point[1];
    t[0] = translation[0]; t[1] = translation[1];
    for (i = 0u; i < 2u; ++i) {
        const int64_t p0 = (int64_t)matrix->element[2u*i] * p[0];
        const int64_t p1 = (int64_t)matrix->element[2u*i+1u] * p[1];
        int64_t dot, translated;
        /* If the dot sum exceeds int64, its magnitude is >=2^63. At f<=31,
         * rounding and adding any int32 translation cannot yield int32. */
        if (!rm_checked_add_i64(p0, p1, &dot)) return false;
        if (!rm_checked_add_i64(round_i64_rne(dot, fractional_bits), t[i], &translated) ||
            translated < INT32_MIN || translated > INT32_MAX) return false;
        result[i] = (int32_t)translated;
    }
    output[0] = result[0]; output[1] = result[1];
    return true;
}
