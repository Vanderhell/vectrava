#include "pc_trajectory_segment_select_u32.h"
#include <stddef.h>

bool pc_trajectory_segment_select_u32(const uint32_t *knots, size_t count,
                                      uint32_t time, size_t *segment_index)
{
    size_t low, high;

    if (knots == NULL || segment_index == NULL || count < 2u) {
        return false;
    }
    if (time < knots[0]) {
        *segment_index = 0u;
        return true;
    }
    if (time >= knots[count - 1u]) {
        *segment_index = count - 2u;
        return true;
    }

    low = 0u;
    high = count - 1u;
    while (high - low > 1u) {
        const size_t mid = low + (high - low) / 2u;
        if (knots[mid] <= time) {
            low = mid;
        } else {
            high = mid;
        }
    }
    *segment_index = low;
    return true;
}
