#ifndef PRIMITIVECORE_QUAT_SIGN_CANONICAL_Q_H
#define PRIMITIVECORE_QUAT_SIGN_CANONICAL_Q_H

#include <stdbool.h>
#include <stdint.h>

/* Canonicalize q/-q by making the first nonzero scalar-first component
 * positive. Components must be in the inclusive Q1.30 range [-1,1]. */
bool pc_quat_sign_canonical_q(const int32_t input_q1_30[4],
                              int32_t output_q1_30[4]);

#endif
