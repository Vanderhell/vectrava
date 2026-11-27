#ifndef VECTRAVA_GEOMETRY_ROTATION_MATRIX3_TRANSPOSE_Q_H
#define VECTRAVA_GEOMETRY_ROTATION_MATRIX3_TRANSPOSE_Q_H
#include <vectrava/geometry/matrix3_q.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif




/* Transpose a row-major 3x3 Q matrix. Input and output may be the same object.
 * For an orthogonal rotation matrix, the result is its inverse. */
bool vectrava_rotation_matrix3_transpose_q(const vectrava_matrix3_q *input,
                                     vectrava_matrix3_q *output);

#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_ROTATION_MATRIX3_TRANSPOSE_Q_H */
