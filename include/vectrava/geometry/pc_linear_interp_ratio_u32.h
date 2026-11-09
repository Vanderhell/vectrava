#ifndef PC_LINEAR_INTERP_RATIO_U32_H
#define PC_LINEAR_INTERP_RATIO_U32_H

#include <stdbool.h>
#include <stdint.h>

/* Convex interpolation for a ratio in [0,1]. Rounds nearest, ties-to-even;
 * invalid ratios or output pointer preserve *result. */
bool pc_linear_interp_ratio_u32(uint32_t a, uint32_t b, uint32_t numerator,
                                uint32_t denominator, uint32_t *result);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_linear_interp_ratio_u32
#define pc_linear_interp_ratio_u32 pc_linear_interp_ratio_u32
#endif
#ifndef pc_linear_interp_ratio_u32
#define pc_linear_interp_ratio_u32 pc_linear_interp_ratio_u32
#endif
#ifndef PC_LINEAR_INTERP_RATIO_U32_H
#define PC_LINEAR_INTERP_RATIO_U32_H PC_LINEAR_INTERP_RATIO_U32_H
#endif

