#ifndef PRIMITIVECORE_SPAN_INTERSECTION_U32_H
#define PRIMITIVECORE_SPAN_INTERSECTION_U32_H

#include <stdbool.h>
#include <stdint.h>

/* Write the nonempty half-open intersection. False preserves both outputs. */
bool pc_span_intersection_u32(uint32_t a_start, uint32_t a_length,
                              uint32_t b_start, uint32_t b_length,
                              uint32_t *out_start, uint32_t *out_length);

#endif
