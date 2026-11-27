#ifndef VECTRAVA_GEOMETRY_SPAN_CONTAINS_OFFSET_U32_H
#define VECTRAVA_GEOMETRY_SPAN_CONTAINS_OFFSET_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Test offset membership in a valid half-open [start, start+length) span. */
bool vectrava_span_contains_offset_u32(uint32_t start, uint32_t length,
                                 uint32_t offset);

#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_SPAN_CONTAINS_OFFSET_U32_H */
