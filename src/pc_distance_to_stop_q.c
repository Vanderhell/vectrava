#include "pc_distance_to_stop_q.h"
#include <stddef.h>
#include <stdint.h>
bool pc_distance_to_stop_q(int32_t velocity_q16_16_per_s,
                           int32_t braking_deceleration_q16_16_per_s2,
                           uint64_t *distance_q16_16)
{
    const int64_t velocity = velocity_q16_16_per_s;
    const uint64_t speed = velocity < 0 ? (uint64_t)(-velocity) : (uint64_t)velocity;
    uint64_t numerator, denominator, quotient;
    if (distance_q16_16 == NULL) return false;
    if (speed == 0u) { *distance_q16_16 = 0u; return true; }
    if (braking_deceleration_q16_16_per_s2 <= 0) return false;
    numerator = speed * speed;
    denominator = UINT64_C(2) * (uint64_t)braking_deceleration_q16_16_per_s2;
    quotient = numerator / denominator;
    if (numerator % denominator != 0u) ++quotient;
    *distance_q16_16 = quotient;
    return true;
}
