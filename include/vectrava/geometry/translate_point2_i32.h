#ifndef VECTRAVA_GEOMETRY_TRANSLATE_POINT2_I32_H
#define VECTRAVA_GEOMETRY_TRANSLATE_POINT2_I32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Add a delta to an int32 coordinate pair. False on null/aliased outputs or
 * if either result overflows; failure preserves both output values. */
bool vectrava_translate_point2_i32(int32_t x, int32_t y, int32_t dx, int32_t dy,
                             int32_t *out_x, int32_t *out_y);


#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_TRANSLATE_POINT2_I32_H */
