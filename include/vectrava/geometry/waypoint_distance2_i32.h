#ifndef VECTRAVA_GEOMETRY_WAYPOINT_DISTANCE2_I32_H
#define VECTRAVA_GEOMETRY_WAYPOINT_DISTANCE2_I32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Exact squared Euclidean distance between int32 coordinates. False on null
 * output or uint64 result overflow; failure preserves *out. */
bool vectrava_waypoint_distance2_i32(int32_t ax, int32_t ay,
                               int32_t bx, int32_t by, uint64_t *out);


#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_WAYPOINT_DISTANCE2_I32_H */
