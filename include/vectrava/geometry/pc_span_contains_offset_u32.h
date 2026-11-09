#ifndef PC_SPAN_CONTAINS_OFFSET_U32_H
#define PC_SPAN_CONTAINS_OFFSET_U32_H

#include <stdbool.h>
#include <stdint.h>

/* Test offset membership in a valid half-open [start, start+length) span. */
bool pc_span_contains_offset_u32(uint32_t start, uint32_t length,
                                 uint32_t offset);

#endif
