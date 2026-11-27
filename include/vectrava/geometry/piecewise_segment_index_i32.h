#ifndef VECTRAVA_GEOMETRY_PIECEWISE_SEGMENT_INDEX_I32_H
#define VECTRAVA_GEOMETRY_PIECEWISE_SEGMENT_INDEX_I32_H
#include <stdbool.h>
#include <stdint.h>
#include <vectrava/geometry/calibrate_piecewise_i32.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Find clamped interval i for strictly increasing points[].input, count 2..255.
 * Segment i spans knot i to i+1; exact interior knots select the segment to
 * their right, and endpoints/outside clamp to [0,count-2]. */
bool vectrava_piecewise_segment_index_i32(const vectrava_calibration_point_i32 *points,
                                    uint8_t count, int32_t input,
                                    uint8_t *segment_index);


#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_PIECEWISE_SEGMENT_INDEX_I32_H */
