#ifndef PC_BBOX_OF_POINTS2_I32_H
#define PC_BBOX_OF_POINTS2_I32_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
typedef struct { int32_t x; int32_t y; } pc_point2_i32;
typedef struct { int32_t min_x; int32_t min_y; int32_t max_x; int32_t max_y; } pc_bbox2_i32;
/* Compute the closed AABB of count points. Reject null pointers or count==0;
 * on failure, preserve *bounds. The input array is read-only. */
bool pc_bbox_of_points2_i32(const pc_point2_i32 *points,size_t count,pc_bbox2_i32 *bounds);
#endif
