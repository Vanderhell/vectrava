#ifndef PC_CALIBRATE_PIECEWISE_I32_H
#define PC_CALIBRATE_PIECEWISE_I32_H
#include <stdbool.h>
#include <stdint.h>
typedef struct { int32_t input; int32_t output; } pc_calibration_point_i32;
/* Piecewise-linear map, clamp beyond endpoints, nearest/ties-away rounding.
 * Count is 2..255; input knots must be strictly increasing. */
bool pc_calibrate_piecewise_i32(const pc_calibration_point_i32 *points,
                                 uint8_t count, int32_t input, int32_t *output);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_calibrate_piecewise_i32
#define pc_calibrate_piecewise_i32 pc_calibrate_piecewise_i32
#endif
#ifndef pc_calibrate_piecewise_i32
#define pc_calibrate_piecewise_i32 pc_calibrate_piecewise_i32
#endif
#ifndef pc_calibration_point_i32
#define pc_calibration_point_i32 pc_calibration_point_i32
#endif
#ifndef PC_CALIBRATE_PIECEWISE_I32_H
#define PC_CALIBRATE_PIECEWISE_I32_H PC_CALIBRATE_PIECEWISE_I32_H
#endif

