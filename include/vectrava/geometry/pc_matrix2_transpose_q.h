#ifndef PC_MATRIX2_TRANSPOSE_Q_H
#define PC_MATRIX2_TRANSPOSE_Q_H
#include <stdbool.h>
#include "pc_matrix2_q.h"

/* Transpose a row-major 2x2 Q matrix; result may alias input. */
bool pc_matrix2_transpose_q(const pc_matrix2_q *input, pc_matrix2_q *result);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_matrix2_transpose_q
#define pc_matrix2_transpose_q pc_matrix2_transpose_q
#endif
#ifndef pc_matrix2_q
#define pc_matrix2_q pc_matrix2_q
#endif
#ifndef pc_matrix2_transpose_q
#define pc_matrix2_transpose_q pc_matrix2_transpose_q
#endif
#ifndef PC_PC_MATRIX2_TRANSPOSE_Q_H
#define PC_PC_MATRIX2_TRANSPOSE_Q_H PC_MATRIX2_TRANSPOSE_Q_H
#endif

