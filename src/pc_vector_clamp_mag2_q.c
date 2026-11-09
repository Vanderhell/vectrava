#include "pc_vector_clamp_mag2_q.h"
#include <stddef.h>

static uint64_t isqrt_u64(uint64_t value)
{
    uint64_t result = 0u, bit = UINT64_C(1) << 62;
    while (bit > value) bit >>= 2;
    while (bit != 0u) {
        if (value >= result + bit) { value -= result + bit; result = (result >> 1) + bit; }
        else result >>= 1;
        bit >>= 2;
    }
    return result;
}

bool rm_vector_clamp_mag2_q(const int16_t input_q15[2], int16_t max_magnitude_q15, int16_t output_q15[2])
{
    const int32_t x = input_q15 == NULL ? 0 : input_q15[0];
    const int32_t y = input_q15 == NULL ? 0 : input_q15[1];
    const uint64_t norm2 = (uint64_t)(x * x) + (uint64_t)(y * y);
    int16_t result[2];
    uint64_t root, denominator, cap2;
    unsigned i;
    const int32_t v[2] = {x, y};
    if (input_q15 == NULL || output_q15 == NULL || max_magnitude_q15 < 0) return false;
    cap2 = (uint64_t)(uint16_t)max_magnitude_q15 * (uint16_t)max_magnitude_q15;
    if (norm2 <= cap2) { result[0] = (int16_t)x; result[1] = (int16_t)y; }
    else {
        root = isqrt_u64(norm2);
        denominator = root * root == norm2 ? root : root + 1u;
        for (i = 0u; i < 2u; ++i) {
            const uint32_t magnitude = v[i] < 0 ? (uint32_t)-v[i] : (uint32_t)v[i];
            const uint32_t scaled = (uint32_t)(((uint64_t)magnitude * (uint16_t)max_magnitude_q15) / denominator);
            result[i] = v[i] < 0 ? (int16_t)-(int32_t)scaled : (int16_t)scaled;
        }
    }
    output_q15[0] = result[0]; output_q15[1] = result[1];
    return true;
}
