#include "pc_span_contains_offset_u32.h"
#include <stdint.h>

bool pc_span_contains_offset_u32(uint32_t start, uint32_t length,
                                 uint32_t offset)
{
    if (length > UINT32_MAX - start || offset < start) {
        return false;
    }
    return offset - start < length;
}
