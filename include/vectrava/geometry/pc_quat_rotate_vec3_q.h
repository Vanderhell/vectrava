#ifndef PC_QUAT_ROTATE_VEC3_Q_H
#define PC_QUAT_ROTATE_VEC3_Q_H

#include <stdbool.h>
#include <stdint.h>

/* Rotate a Q1.30 vector whose components are in [-1,1] by a scalar-first
 * quaternion. The nonzero quaternion is normalized internally. */
bool pc_quat_rotate_vec3_q(const int32_t quaternion_q1_30[4],
                           const int32_t vector_q1_30[3],
                           int32_t output_q1_30[3]);

#endif
