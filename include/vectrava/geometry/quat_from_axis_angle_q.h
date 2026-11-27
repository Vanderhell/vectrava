#ifndef VECTRAVA_GEOMETRY_QUAT_FROM_AXIS_ANGLE_Q_H
#define VECTRAVA_GEOMETRY_QUAT_FROM_AXIS_ANGLE_Q_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Q0.32 full-turn angle and nonzero Q1.30 axis -> scalar-first Q1.30 quaternion. */
bool vectrava_quat_from_axis_angle_q(const int32_t axis_q1_30[3], uint32_t angle_turns_q0_32,
                               int32_t output_q1_30[4]);

#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_QUAT_FROM_AXIS_ANGLE_Q_H */
