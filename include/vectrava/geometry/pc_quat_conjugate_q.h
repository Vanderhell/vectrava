#ifndef PC_QUAT_CONJUGATE_Q_H
#define PC_QUAT_CONJUGATE_Q_H

#include <stdbool.h>
#include <stdint.h>

/* Conjugate scalar-first Q1.30 quaternion; reject unnegatable INT32_MIN. */
bool pc_quat_conjugate_q(const int32_t input_q1_30[4], int32_t output_q1_30[4]);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_quat_conjugate_q
#define pc_quat_conjugate_q pc_quat_conjugate_q
#endif
#ifndef pc_quat_conjugate_q
#define pc_quat_conjugate_q pc_quat_conjugate_q
#endif
#ifndef PC_PC_QUAT_CONJUGATE_Q_H
#define PC_PC_QUAT_CONJUGATE_Q_H PC_QUAT_CONJUGATE_Q_H
#endif

