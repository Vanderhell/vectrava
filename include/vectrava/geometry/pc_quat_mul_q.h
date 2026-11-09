#ifndef PC_QUAT_MUL_Q_H
#define PC_QUAT_MUL_Q_H

#include <stdbool.h>
#include <stdint.h>

/* Hamilton product of scalar-first Q1.30 quaternions with components in [-1,1]. */
bool pc_quat_mul_q(const int32_t a_q1_30[4], const int32_t b_q1_30[4],
                   int32_t output_q1_30[4]);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_quat_mul_q
#define pc_quat_mul_q pc_quat_mul_q
#endif
#ifndef pc_quat_mul_q
#define pc_quat_mul_q pc_quat_mul_q
#endif
#ifndef PC_PC_QUAT_MUL_Q_H
#define PC_PC_QUAT_MUL_Q_H PC_QUAT_MUL_Q_H
#endif

