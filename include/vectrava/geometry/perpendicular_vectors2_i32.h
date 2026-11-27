#ifndef VECTRAVA_GEOMETRY_PERPENDICULAR_VECTORS2_I32_H
#define VECTRAVA_GEOMETRY_PERPENDICULAR_VECTORS2_I32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* True iff the exact dot product of the two int32 vectors is zero.
 * A zero vector is perpendicular to every vector under this definition. */
bool vectrava_perpendicular_vectors2_i32(int32_t ax,int32_t ay,int32_t bx,int32_t by);

#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_PERPENDICULAR_VECTORS2_I32_H */
