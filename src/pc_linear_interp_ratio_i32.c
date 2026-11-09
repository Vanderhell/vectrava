#include "pc_linear_interp_ratio_i32.h"
#include <stddef.h>

bool pc_linear_interp_ratio_i32(int32_t a, int32_t b, uint32_t numerator,
                                uint32_t denominator, int32_t *result)
{
    uint64_t magnitude, product, q, rem;
    int64_t base;
    int increasing;
    if (result == NULL || denominator == 0u || numerator > denominator) return false;
    increasing = b >= a;
    magnitude = increasing ? (uint64_t)((int64_t)b - a)
                          : (uint64_t)((int64_t)a - b);
    product = magnitude * numerator;
    q = product / denominator;
    rem = product % denominator;
    base = (int64_t)a + (increasing ? (int64_t)q : -(int64_t)q);
    if (rem > (uint64_t)denominator - rem ||
        (rem == (uint64_t)denominator - rem && base % 2 != 0))
        base += increasing ? 1 : -1;
    *result = (int32_t)base;
    return true;
}
