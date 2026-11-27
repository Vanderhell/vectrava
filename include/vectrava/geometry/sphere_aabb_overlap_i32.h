#ifndef VECTRAVA_GEOMETRY_SPHERE_AABB_OVERLAP_I32_H
#define VECTRAVA_GEOMETRY_SPHERE_AABB_OVERLAP_I32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Closed sphere/AABB overlap; any inverted box axis returns false. */
bool vectrava_sphere_aabb_overlap_i32(int32_t cx,int32_t cy,int32_t cz,uint32_t radius,
                                int32_t min_x,int32_t min_y,int32_t min_z,
                                int32_t max_x,int32_t max_y,int32_t max_z);

#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_SPHERE_AABB_OVERLAP_I32_H */
