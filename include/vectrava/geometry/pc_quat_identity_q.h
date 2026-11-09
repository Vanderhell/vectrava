#ifndef PRIMITIVECORE_QUAT_IDENTITY_Q_H
#define PRIMITIVECORE_QUAT_IDENTITY_Q_H

#include <stdbool.h>
#include <stdint.h>

/* Store scalar-first Q1.30 identity quaternion [w, x, y, z]. */
bool rm_quat_identity_q(int32_t out_q1_30[4]);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_quat_identity_q
#define pc_quat_identity_q rm_quat_identity_q
#endif
#ifndef pc_quat_identity_q
#define pc_quat_identity_q rm_quat_identity_q
#endif
#ifndef PC_PRIMITIVECORE_QUAT_IDENTITY_Q_H
#define PC_PRIMITIVECORE_QUAT_IDENTITY_Q_H PRIMITIVECORE_QUAT_IDENTITY_Q_H
#endif

