#ifndef VECTRAVA_GEOMETRY_ROTATION_MATRIX2_FROM_ANGLE_Q_H
#define VECTRAVA_GEOMETRY_ROTATION_MATRIX2_FROM_ANGLE_Q_H
#include <vectrava/geometry/matrix2_q.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Active CCW 2D rotation matrix, row-major Q1.30 coefficients. */
bool vectrava_rotation_matrix2_from_angle_q(uint32_t angle_turns_q0_32,
                                      vectrava_matrix2_q *output_q1_30);

#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_ROTATION_MATRIX2_FROM_ANGLE_Q_H */
