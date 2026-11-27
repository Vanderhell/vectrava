#ifndef VECTRAVA_GEOMETRY_LINEAR_INTERP_RATIO_U32_H
#define VECTRAVA_GEOMETRY_LINEAR_INTERP_RATIO_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Convex interpolation for a ratio in [0,1]. Rounds nearest, ties-to-even;
 * invalid ratios or output pointer preserve *result. */
bool vectrava_linear_interp_ratio_u32(uint32_t a, uint32_t b, uint32_t numerator,
                                uint32_t denominator, uint32_t *result);



#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_LINEAR_INTERP_RATIO_U32_H */
