#ifndef PC_OFFSET_RANGE_CHECK_U32_H
#define PC_OFFSET_RANGE_CHECK_U32_H

#include <stdbool.h>
#include <stdint.h>

/* Check the half-open span [offset, offset + length) against capacity.
 * An empty span at offset == capacity is valid. */
bool pc_offset_range_check_u32(uint32_t offset, uint32_t length,
                               uint32_t capacity);

#endif
