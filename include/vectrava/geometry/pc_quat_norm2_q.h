#ifndef PRIMITIVECORE_QUAT_NORM2_Q_H
#define PRIMITIVECORE_QUAT_NORM2_Q_H

#include <stdbool.h>
#include <stdint.h>

/* Exact sum of squares for scalar-first Q1.30 quaternion in [-1,1]^4. */
bool pc_quat_norm2_q(const int32_t q_q1_30[4], uint64_t *norm2_q2_60);

#endif
