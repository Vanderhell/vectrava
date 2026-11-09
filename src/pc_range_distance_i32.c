#include "pc_range_distance_i32.h"
#include <stddef.h>

bool rm_range_distance_i32(int32_t value, int32_t lower, int32_t upper,
                           uint32_t *distance)
{
    uint32_t delta;
    if (distance == NULL || lower > upper) return false;
    if (value < lower) delta = (uint32_t)lower - (uint32_t)value;
    else if (value > upper) delta = (uint32_t)value - (uint32_t)upper;
    else delta = 0;
    *distance = delta;
    return true;
}
