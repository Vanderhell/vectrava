#ifndef PRIMITIVECORE_RM_HOMOGENEOUS2_APPLY_Q_H
#define PRIMITIVECORE_RM_HOMOGENEOUS2_APPLY_Q_H
#include <stdbool.h>
#include <stdint.h>

/* Apply a row-major 3x3 Q matrix to a homogeneous 3-vector. Each row dot
 * product is rounded nearest-even once. Returns homogeneous output; it does
 * not divide by W. False preserves output. Output may alias matrix/vector. */
bool rm_homogeneous2_apply_q(const int32_t matrix[9], const int32_t vector[3],
                             unsigned fractional_bits, int32_t output[3]);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_homogeneous2_apply_q
#define pc_homogeneous2_apply_q rm_homogeneous2_apply_q
#endif
#ifndef pc_homogeneous2_apply_q
#define pc_homogeneous2_apply_q rm_homogeneous2_apply_q
#endif
#ifndef PC_PRIMITIVECORE_RM_HOMOGENEOUS2_APPLY_Q_H
#define PC_PRIMITIVECORE_RM_HOMOGENEOUS2_APPLY_Q_H PRIMITIVECORE_RM_HOMOGENEOUS2_APPLY_Q_H
#endif

