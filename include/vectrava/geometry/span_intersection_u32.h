#ifndef VECTRAVA_GEOMETRY_SPAN_INTERSECTION_U32_H
#define VECTRAVA_GEOMETRY_SPAN_INTERSECTION_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Write the nonempty half-open intersection. False preserves both outputs. */
bool vectrava_span_intersection_u32(uint32_t a_start, uint32_t a_length,
                              uint32_t b_start, uint32_t b_length,
                              uint32_t *out_start, uint32_t *out_length);

#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_SPAN_INTERSECTION_U32_H */
