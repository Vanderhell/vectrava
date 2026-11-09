#ifndef PRIMITIVECORE_MATRIX2_SUB_Q_H
#define PRIMITIVECORE_MATRIX2_SUB_Q_H
#include <stdbool.h>
#include "pc_matrix2_q.h"

/* Exact elementwise subtraction. On any component overflow, write nothing. */
bool rm_matrix2_sub_q(const rm_matrix2_q *a, const rm_matrix2_q *b,
                      rm_matrix2_q *result);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_matrix2_sub_q
#define pc_matrix2_sub_q rm_matrix2_sub_q
#endif
#ifndef pc_matrix2_q
#define pc_matrix2_q rm_matrix2_q
#endif
#ifndef pc_matrix2_sub_q
#define pc_matrix2_sub_q rm_matrix2_sub_q
#endif
#ifndef PC_PRIMITIVECORE_MATRIX2_SUB_Q_H
#define PC_PRIMITIVECORE_MATRIX2_SUB_Q_H PRIMITIVECORE_MATRIX2_SUB_Q_H
#endif

