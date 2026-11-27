#ifndef VECTRAVA_GEOMETRY_LINEAR_INTERP_RATIO_I32_H
#define VECTRAVA_GEOMETRY_LINEAR_INTERP_RATIO_I32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Convex interpolation at numerator/denominator in [0,1]. The exact result
 * rounds to nearest, ties-to-even. Invalid ratio/output preserves *result. */
bool vectrava_linear_interp_ratio_i32(int32_t a, int32_t b, uint32_t numerator,
                                uint32_t denominator, int32_t *result);



#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_LINEAR_INTERP_RATIO_I32_H */
