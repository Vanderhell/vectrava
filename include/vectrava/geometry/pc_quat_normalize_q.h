#ifndef PRIMITIVECORE_QUAT_NORMALIZE_Q_H
#define PRIMITIVECORE_QUAT_NORMALIZE_Q_H

#include <stdbool.h>
#include <stdint.h>

/* Normalize scalar-first Q1.30 quaternion; reject zero and preserve output. */
bool rm_quat_normalize_q(const int32_t input_q1_30[4], int32_t output_q1_30[4]);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_quat_normalize_q
#define pc_quat_normalize_q rm_quat_normalize_q
#endif
#ifndef pc_quat_normalize_q
#define pc_quat_normalize_q rm_quat_normalize_q
#endif
#ifndef PC_PRIMITIVECORE_QUAT_NORMALIZE_Q_H
#define PC_PRIMITIVECORE_QUAT_NORMALIZE_Q_H PRIMITIVECORE_QUAT_NORMALIZE_Q_H
#endif

