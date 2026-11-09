#ifndef PC_QUAT_DOT_Q_H
#define PC_QUAT_DOT_Q_H

#include <stdbool.h>
#include <stdint.h>

/* Dot scalar-first Q1.30 quaternion components in [-1,1]; round to Q1.30. */
bool pc_quat_dot_q(const int32_t a_q1_30[4], const int32_t b_q1_30[4],
                   int32_t *dot_q1_30);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_quat_dot_q
#define pc_quat_dot_q pc_quat_dot_q
#endif
#ifndef pc_quat_dot_q
#define pc_quat_dot_q pc_quat_dot_q
#endif
#ifndef PC_PC_QUAT_DOT_Q_H
#define PC_PC_QUAT_DOT_Q_H PC_QUAT_DOT_Q_H
#endif

