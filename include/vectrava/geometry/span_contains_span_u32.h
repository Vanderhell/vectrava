#ifndef VECTRAVA_GEOMETRY_SPAN_CONTAINS_SPAN_U32_H
#define VECTRAVA_GEOMETRY_SPAN_CONTAINS_SPAN_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Check whether a valid half-open inner span is contained by an outer span. */
bool vectrava_span_contains_span_u32(uint32_t outer_start, uint32_t outer_length,
                               uint32_t inner_start, uint32_t inner_length);

#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_SPAN_CONTAINS_SPAN_U32_H */
