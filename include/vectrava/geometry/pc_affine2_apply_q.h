#ifndef PC_PC_AFFINE2_APPLY_Q_H
#define PC_PC_AFFINE2_APPLY_Q_H
#include "pc_matrix2_q.h"
#include <stdbool.h>
#include <stdint.h>

/* Apply a row-major 2x2 Q matrix and Q translation. Each dot product is
 * rounded nearest-even once. False on invalid pointers/fractional_bits or
 * result overflow; failure preserves output. Output may alias point/translation. */
bool pc_affine2_apply_q(const pc_matrix2_q *matrix, const int32_t point[2],
                        const int32_t translation[2], unsigned fractional_bits,
                        int32_t output[2]);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_affine2_apply_q
#define pc_affine2_apply_q pc_affine2_apply_q
#endif
#ifndef pc_affine2_apply_q
#define pc_affine2_apply_q pc_affine2_apply_q
#endif
#ifndef pc_matrix2_q
#define pc_matrix2_q pc_matrix2_q
#endif
#ifndef PC_PC_PC_AFFINE2_APPLY_Q_H
#define PC_PC_PC_AFFINE2_APPLY_Q_H PC_PC_AFFINE2_APPLY_Q_H
#endif

