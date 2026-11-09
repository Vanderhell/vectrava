#ifndef RM_LINEAR_INTERP_RATIO_I32_H
#define RM_LINEAR_INTERP_RATIO_I32_H

#include <stdbool.h>
#include <stdint.h>

/* Convex interpolation at numerator/denominator in [0,1]. The exact result
 * rounds to nearest, ties-to-even. Invalid ratio/output preserves *result. */
bool rm_linear_interp_ratio_i32(int32_t a, int32_t b, uint32_t numerator,
                                uint32_t denominator, int32_t *result);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_linear_interp_ratio_i32
#define pc_linear_interp_ratio_i32 rm_linear_interp_ratio_i32
#endif
#ifndef pc_linear_interp_ratio_i32
#define pc_linear_interp_ratio_i32 rm_linear_interp_ratio_i32
#endif
#ifndef PC_LINEAR_INTERP_RATIO_I32_H
#define PC_LINEAR_INTERP_RATIO_I32_H RM_LINEAR_INTERP_RATIO_I32_H
#endif

