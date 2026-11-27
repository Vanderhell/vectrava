#ifndef VECTRAVA_GEOMETRY_BBOX_OF_POINTS2_I32_H
#define VECTRAVA_GEOMETRY_BBOX_OF_POINTS2_I32_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct { int32_t x; int32_t y; } vectrava_point2_i32;
typedef struct { int32_t min_x; int32_t min_y; int32_t max_x; int32_t max_y; } vectrava_bbox2_i32;
/* Compute the closed AABB of count points. Reject null pointers or count==0;
 * on failure, preserve *bounds. The input array is read-only. */
bool vectrava_bbox_of_points2_i32(const vectrava_point2_i32 *points,size_t count,vectrava_bbox2_i32 *bounds);

#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_BBOX_OF_POINTS2_I32_H */
