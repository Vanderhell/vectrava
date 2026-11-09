#include "pc_range_contains_i32.h"

bool rm_range_contains_i32(int32_t value, int32_t lower, int32_t upper)
{
    return lower <= upper && value >= lower && value <= upper;
}
