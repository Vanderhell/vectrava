#include "pc_piecewise_segment_index_i32.h"
#include <stddef.h>

bool rm_piecewise_segment_index_i32(const rm_calibration_point_i32 *points,
                                    uint8_t count, int32_t input,
                                    uint8_t *segment_index)
{
    uint16_t lo, hi;
    if (points == NULL || segment_index == NULL || count < 2u) return false;
    if (input <= points[0].input) {
        *segment_index = 0u;
        return true;
    }
    if (input >= points[(uint16_t)count - 1u].input) {
        *segment_index = (uint8_t)(count - 2u);
        return true;
    }
    lo = 0u;
    hi = count;
    while (lo < hi) {
        const uint16_t mid = (uint16_t)(lo + (hi - lo) / 2u);
        if (points[mid].input <= input) lo = mid + 1u;
        else hi = mid;
    }
    *segment_index = (uint8_t)(lo - 1u);
    return true;
}
