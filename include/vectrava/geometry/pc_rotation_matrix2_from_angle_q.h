#ifndef PC_ROTATION_MATRIX2_FROM_ANGLE_Q_H
#define PC_ROTATION_MATRIX2_FROM_ANGLE_Q_H
#include "pc_matrix2_q.h"
#include <stdbool.h>
#include <stdint.h>
/* Active CCW 2D rotation matrix, row-major Q1.30 coefficients. */
bool pc_rotation_matrix2_from_angle_q(uint32_t angle_turns_q0_32,
                                      pc_matrix2_q *output_q1_30);
#endif
