#ifndef VECTRAVA_GEOMETRY_CALIBRATE_PIECEWISE_I32_H
#define VECTRAVA_GEOMETRY_CALIBRATE_PIECEWISE_I32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct { int32_t input; int32_t output; } vectrava_calibration_point_i32;
/* Piecewise-linear map, clamp beyond endpoints, nearest/ties-away rounding.
 * Count is 2..255; input knots must be strictly increasing. */
bool vectrava_calibrate_piecewise_i32(const vectrava_calibration_point_i32 *points,
                                 uint8_t count, int32_t input, int32_t *output);


#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_CALIBRATE_PIECEWISE_I32_H */
