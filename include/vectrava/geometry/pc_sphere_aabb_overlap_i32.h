#ifndef PC_PC_SPHERE_AABB_OVERLAP_I32_H
#define PC_PC_SPHERE_AABB_OVERLAP_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Closed sphere/AABB overlap; any inverted box axis returns false. */
bool pc_sphere_aabb_overlap_i32(int32_t cx,int32_t cy,int32_t cz,uint32_t radius,
                                int32_t min_x,int32_t min_y,int32_t min_z,
                                int32_t max_x,int32_t max_y,int32_t max_z);
#endif
