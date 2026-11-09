#ifndef PRIMITIVECORE_SPAN_CONTAINS_SPAN_U32_H
#define PRIMITIVECORE_SPAN_CONTAINS_SPAN_U32_H

#include <stdbool.h>
#include <stdint.h>

/* Check whether a valid half-open inner span is contained by an outer span. */
bool pc_span_contains_span_u32(uint32_t outer_start, uint32_t outer_length,
                               uint32_t inner_start, uint32_t inner_length);

#endif
