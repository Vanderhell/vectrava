#ifndef PRIMITIVECORE_QUAT_FROM_AXIS_ANGLE_Q_H
#define PRIMITIVECORE_QUAT_FROM_AXIS_ANGLE_Q_H

#include <stdbool.h>
#include <stdint.h>

/* Q0.32 full-turn angle and nonzero Q1.30 axis -> scalar-first Q1.30 quaternion. */
bool pc_quat_from_axis_angle_q(const int32_t axis_q1_30[3], uint32_t angle_turns_q0_32,
                               int32_t output_q1_30[4]);

#endif
