#ifndef PRIMITIVECORE_PC_CIRCLE_AABB_OVERLAP_I32_H
#define PRIMITIVECORE_PC_CIRCLE_AABB_OVERLAP_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Closed circle/AABB overlap; inverted box bounds return false. */
bool pc_circle_aabb_overlap_i32(int32_t cx,int32_t cy,uint32_t radius,
                                int32_t min_x,int32_t min_y,int32_t max_x,int32_t max_y);
#endif
