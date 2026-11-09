#ifndef PC_PC_WAYPOINT_DISTANCE2_I32_H
#define PC_PC_WAYPOINT_DISTANCE2_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Exact squared Euclidean distance between int32 coordinates. False on null
 * output or uint64 result overflow; failure preserves *out. */
bool pc_waypoint_distance2_i32(int32_t ax, int32_t ay,
                               int32_t bx, int32_t by, uint64_t *out);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_waypoint_distance2_i32
#define pc_waypoint_distance2_i32 pc_waypoint_distance2_i32
#endif
#ifndef pc_waypoint_distance2_i32
#define pc_waypoint_distance2_i32 pc_waypoint_distance2_i32
#endif
#ifndef PC_PC_PC_WAYPOINT_DISTANCE2_I32_H
#define PC_PC_PC_WAYPOINT_DISTANCE2_I32_H PC_PC_WAYPOINT_DISTANCE2_I32_H
#endif

