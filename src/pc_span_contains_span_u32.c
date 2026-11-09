#include "pc_span_contains_span_u32.h"
#include <stdint.h>

bool pc_span_contains_span_u32(uint32_t outer_start, uint32_t outer_length,
                               uint32_t inner_start, uint32_t inner_length)
{
    uint32_t relative_start;
    if (outer_length > UINT32_MAX - outer_start || inner_start < outer_start) {
        return false;
    }
    relative_start = inner_start - outer_start;
    if (relative_start > outer_length) {
        return false;
    }
    return inner_length <= outer_length - relative_start;
}
