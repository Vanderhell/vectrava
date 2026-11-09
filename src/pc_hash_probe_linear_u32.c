#include "pc_hash_probe_linear_u32.h"

#include <stddef.h>

bool pc_hash_probe_linear_u32(uint32_t start, uint32_t ordinal,
                              uint32_t capacity, uint32_t *index)
{
    uint32_t offset;
    uint32_t distance_to_wrap;
    uint32_t result;

    if (index == NULL || capacity == 0u || start >= capacity) return false;
    offset = ordinal % capacity;
    distance_to_wrap = capacity - start;
    if (offset >= distance_to_wrap) {
        result = offset - distance_to_wrap;
    } else {
        result = start + offset;
    }
    *index = result;
    return true;
}
