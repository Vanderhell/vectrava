#ifndef PRIMITIVECORE_PC_ROTATION_MATRIX3_TRANSPOSE_Q_H
#define PRIMITIVECORE_PC_ROTATION_MATRIX3_TRANSPOSE_Q_H

#include "pc_matrix3_q.h"

#include <stdbool.h>

/* Transpose a row-major 3x3 Q matrix. Input and output may be the same object.
 * For an orthogonal rotation matrix, the result is its inverse. */
bool pc_rotation_matrix3_transpose_q(const pc_matrix3_q *input,
                                     pc_matrix3_q *output);

#endif