#ifndef RM_PIECEWISE_SEGMENT_INDEX_I32_H
#define RM_PIECEWISE_SEGMENT_INDEX_I32_H
#include <stdbool.h>
#include <stdint.h>
#include "pc_calibrate_piecewise_i32.h"
/* Find clamped interval i for strictly increasing points[].input, count 2..255.
 * Segment i spans knot i to i+1; exact interior knots select the segment to
 * their right, and endpoints/outside clamp to [0,count-2]. */
bool rm_piecewise_segment_index_i32(const rm_calibration_point_i32 *points,
                                    uint8_t count, int32_t input,
                                    uint8_t *segment_index);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_piecewise_segment_index_i32
#define pc_piecewise_segment_index_i32 rm_piecewise_segment_index_i32
#endif
#ifndef pc_calibration_point_i32
#define pc_calibration_point_i32 rm_calibration_point_i32
#endif
#ifndef pc_piecewise_segment_index_i32
#define pc_piecewise_segment_index_i32 rm_piecewise_segment_index_i32
#endif
#ifndef PC_PIECEWISE_SEGMENT_INDEX_I32_H
#define PC_PIECEWISE_SEGMENT_INDEX_I32_H RM_PIECEWISE_SEGMENT_INDEX_I32_H
#endif

