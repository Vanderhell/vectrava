#include <vectrava/geometry/range_contains_i32.h>

bool vectrava_range_contains_i32(int32_t value, int32_t lower, int32_t upper)
{
    return lower <= upper && value >= lower && value <= upper;
}
