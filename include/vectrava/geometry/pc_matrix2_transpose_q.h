#ifndef PRIMITIVECORE_MATRIX2_TRANSPOSE_Q_H
#define PRIMITIVECORE_MATRIX2_TRANSPOSE_Q_H
#include <stdbool.h>
#include "pc_matrix2_q.h"

/* Transpose a row-major 2x2 Q matrix; result may alias input. */
bool rm_matrix2_transpose_q(const rm_matrix2_q *input, rm_matrix2_q *result);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_matrix2_transpose_q
#define pc_matrix2_transpose_q rm_matrix2_transpose_q
#endif
#ifndef pc_matrix2_q
#define pc_matrix2_q rm_matrix2_q
#endif
#ifndef pc_matrix2_transpose_q
#define pc_matrix2_transpose_q rm_matrix2_transpose_q
#endif
#ifndef PC_PRIMITIVECORE_MATRIX2_TRANSPOSE_Q_H
#define PC_PRIMITIVECORE_MATRIX2_TRANSPOSE_Q_H PRIMITIVECORE_MATRIX2_TRANSPOSE_Q_H
#endif

