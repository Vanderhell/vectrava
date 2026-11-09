#include "pc_span_intersection_u32.h"
#include <stddef.h>

bool pc_span_intersection_u32(uint32_t a_start, uint32_t a_length,
                              uint32_t b_start, uint32_t b_length,
                              uint32_t *out_start, uint32_t *out_length)
{
    uint32_t a_end, b_end, start, end;
    if (out_start == NULL || out_length == NULL || out_start == out_length ||
        a_length == 0u || b_length == 0u ||
        a_length > UINT32_MAX - a_start ||
        b_length > UINT32_MAX - b_start) {
        return false;
    }
    a_end = a_start + a_length;
    b_end = b_start + b_length;
    start = a_start > b_start ? a_start : b_start;
    end = a_end < b_end ? a_end : b_end;
    if (start >= end) {
        return false;
    }
    *out_start = start;
    *out_length = end - start;
    return true;
}
