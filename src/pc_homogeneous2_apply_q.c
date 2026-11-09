#include "pc_homogeneous2_apply_q.h"
#include "pc_checked_add_i64.h"
#include <limits.h>
#include <stddef.h>

static int64_t rne_i64(int64_t value, unsigned f)
{
    const uint64_t mag = value < 0 ? (uint64_t)(-(value + 1)) + 1u : (uint64_t)value;
    const uint64_t den = UINT64_C(1) << f;
    uint64_t q = mag / den;
    const uint64_t r = mag % den;
    if (r > den-r || (r == den-r && (q & 1u))) ++q;
    if (value >= 0) return (int64_t)q;
    if (q == (UINT64_C(1) << 63)) return INT64_MIN;
    return -(int64_t)q;
}

bool pc_homogeneous2_apply_q(const int32_t matrix[9], const int32_t vector[3],
                             unsigned fractional_bits, int32_t output[3])
{
    int32_t m[9], v[3], result[3];
    unsigned i, j;
    if (matrix == NULL || vector == NULL || output == NULL || fractional_bits > 31u) return false;
    for (i = 0u; i < 9u; ++i) m[i] = matrix[i];
    for (i = 0u; i < 3u; ++i) v[i] = vector[i];
    for (i = 0u; i < 3u; ++i) {
        int64_t sum = 0;
        for (j = 0u; j < 3u; ++j) {
            const int64_t product = (int64_t)m[3u*i+j] * v[j];
            if (!pc_checked_add_i64(sum, product, &sum)) return false;
        }
        {
            const int64_t rounded = rne_i64(sum, fractional_bits);
            if (rounded < INT32_MIN || rounded > INT32_MAX) return false;
            result[i] = (int32_t)rounded;
        }
    }
    output[0] = result[0]; output[1] = result[1]; output[2] = result[2];
    return true;
}
