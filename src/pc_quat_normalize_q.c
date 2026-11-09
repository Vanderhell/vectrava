#include "pc_quat_normalize_q.h"

#include <stddef.h>

#define Q30_ONE INT64_C(1073741824)

static uint64_t abs_i32(int32_t value)
{
    return value < 0 ? (uint64_t)(-(int64_t)value) : (uint64_t)value;
}

static uint64_t sqrt_round_nearest_even(uint64_t value)
{
    uint64_t lo = 0u;
    uint64_t hi = UINT64_C(4294967296);
    uint64_t root;
    uint64_t delta;
    while (lo + 1u < hi) {
        uint64_t mid = lo + (hi - lo) / 2u;
        if (mid * mid <= value) lo = mid;
        else hi = mid;
    }
    root = lo;
    delta = value - root * root;
    if (delta > root) ++root;
    return root;
}

static int64_t divide_round_nearest_even(uint64_t numerator, uint64_t denominator)
{
    uint64_t quotient = numerator / denominator;
    uint64_t remainder = numerator % denominator;
    uint64_t twice = remainder * 2u;
    if (twice > denominator ||
        (twice == denominator && (quotient & 1u) != 0u)) {
        ++quotient;
    }
    return (int64_t)quotient;
}

bool pc_quat_normalize_q(const int32_t input_q1_30[4], int32_t output_q1_30[4])
{
    uint64_t maximum = 0u;
    int64_t scaled[4];
    int32_t result[4];
    uint64_t norm_squared = 0u;
    uint64_t norm;
    unsigned i;

    if (input_q1_30 == NULL || output_q1_30 == NULL) return false;
    for (i = 0u; i < 4u; ++i) {
        uint64_t magnitude = abs_i32(input_q1_30[i]);
        if (magnitude > maximum) maximum = magnitude;
    }
    if (maximum == 0u) return false;

    for (i = 0u; i < 4u; ++i) {
        uint64_t magnitude = abs_i32(input_q1_30[i]);
        uint64_t scaled_magnitude = (magnitude * (uint64_t)Q30_ONE) / maximum;
        scaled[i] = input_q1_30[i] < 0 ? -(int64_t)scaled_magnitude :
                                         (int64_t)scaled_magnitude;
        norm_squared += (uint64_t)(scaled[i] * scaled[i]);
    }
    norm = sqrt_round_nearest_even(norm_squared);
    if (norm == 0u) return false;

    for (i = 0u; i < 4u; ++i) {
        uint64_t magnitude = scaled[i] < 0 ? (uint64_t)(-scaled[i]) : (uint64_t)scaled[i];
        int64_t component = divide_round_nearest_even(magnitude * (uint64_t)Q30_ONE, norm);
        result[i] = scaled[i] < 0 ? (int32_t)-component : (int32_t)component;
    }
    for (i = 0u; i < 4u; ++i) output_q1_30[i] = result[i];
    return true;
}
