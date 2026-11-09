#include "pc_ring_distance_forward_u32.h"
#include <stddef.h>

bool pc_ring_distance_forward_u32(uint32_t from, uint32_t to,
                                  uint32_t capacity, uint32_t *distance)
{
    if (distance == NULL || capacity == 0u || from >= capacity ||
        to >= capacity) {
        return false;
    }
    *distance = to >= from ? to - from : capacity - from + to;
    return true;
}
