#ifndef PC_QUAT_IDENTITY_Q_H
#define PC_QUAT_IDENTITY_Q_H

#include <stdbool.h>
#include <stdint.h>

/* Store scalar-first Q1.30 identity quaternion [w, x, y, z]. */
bool pc_quat_identity_q(int32_t out_q1_30[4]);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_quat_identity_q
#define pc_quat_identity_q pc_quat_identity_q
#endif
#ifndef pc_quat_identity_q
#define pc_quat_identity_q pc_quat_identity_q
#endif
#ifndef PC_PC_QUAT_IDENTITY_Q_H
#define PC_PC_QUAT_IDENTITY_Q_H PC_QUAT_IDENTITY_Q_H
#endif

