#ifndef VECTRAVA_GEOMETRY_MATRIX2_TRANSPOSE_Q_H
#define VECTRAVA_GEOMETRY_MATRIX2_TRANSPOSE_Q_H
#include <stdbool.h>
#include <vectrava/geometry/matrix2_q.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Transpose a row-major 2x2 Q matrix; result may alias input. */
bool vectrava_matrix2_transpose_q(const vectrava_matrix2_q *input, vectrava_matrix2_q *result);


#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_MATRIX2_TRANSPOSE_Q_H */
