#include "pc_waypoint_distance2_i32.h"
#include <stddef.h>

static uint64_t square_delta(int32_t a, int32_t b)
{
    const int64_t delta = (int64_t)a - (int64_t)b;
    const uint64_t magnitude = delta < 0 ? (uint64_t)(-delta) : (uint64_t)delta;
    return magnitude * magnitude;
}

bool pc_waypoint_distance2_i32(int32_t ax, int32_t ay,
                               int32_t bx, int32_t by, uint64_t *out)
{
    const uint64_t dx2 = square_delta(ax, bx);
    const uint64_t dy2 = square_delta(ay, by);
    if (out == NULL || UINT64_MAX - dx2 < dy2) return false;
    *out = dx2 + dy2;
    return true;
}
