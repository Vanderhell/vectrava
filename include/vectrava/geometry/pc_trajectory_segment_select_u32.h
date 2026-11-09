#ifndef PC_TRAJECTORY_SEGMENT_SELECT_U32_H
#define PC_TRAJECTORY_SEGMENT_SELECT_U32_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
/* Select interval i in strictly increasing time_knots[0..count-1]. Exact
 * interior knots select the interval to their right; endpoints clamp to the
 * first/last segment. count must be at least 2. */
bool pc_trajectory_segment_select_u32(const uint32_t *time_knots,
    size_t count, uint32_t time, size_t *segment_index);
#endif
