#include "pc_translate_point2_i32.h"
#include <limits.h>
#include <stddef.h>

bool pc_translate_point2_i32(int32_t x, int32_t y, int32_t dx, int32_t dy,
                             int32_t *out_x, int32_t *out_y)
{
    const int64_t nx = (int64_t)x + (int64_t)dx;
    const int64_t ny = (int64_t)y + (int64_t)dy;
    if (out_x == NULL || out_y == NULL || out_x == out_y ||
        nx < INT32_MIN || nx > INT32_MAX || ny < INT32_MIN || ny > INT32_MAX) return false;
    *out_x = (int32_t)nx;
    *out_y = (int32_t)ny;
    return true;
}
