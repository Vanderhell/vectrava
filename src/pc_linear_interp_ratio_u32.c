#include "pc_linear_interp_ratio_u32.h"
#include <stddef.h>

bool rm_linear_interp_ratio_u32(uint32_t a, uint32_t b, uint32_t numerator,
                                uint32_t denominator, uint32_t *result)
{
    uint64_t magnitude, product, q, rem;
    uint64_t base;
    int increasing;
    if (result == NULL || denominator == 0u || numerator > denominator) return false;
    increasing = b >= a;
    magnitude = increasing ? (uint64_t)b - a : (uint64_t)a - b;
    product = magnitude * numerator;
    q = product / denominator;
    rem = product % denominator;
    base = increasing ? (uint64_t)a + q : (uint64_t)a - q;
    if (rem > (uint64_t)denominator - rem ||
        (rem == (uint64_t)denominator - rem && (base & 1u) != 0u))
        base = increasing ? base + 1u : base - 1u;
    *result = (uint32_t)base;
    return true;
}
