#ifndef PC_MATRIX2_SUB_Q_H
#define PC_MATRIX2_SUB_Q_H
#include <stdbool.h>
#include "pc_matrix2_q.h"

/* Exact elementwise subtraction. On any component overflow, write nothing. */
bool pc_matrix2_sub_q(const pc_matrix2_q *a, const pc_matrix2_q *b,
                      pc_matrix2_q *result);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_matrix2_sub_q
#define pc_matrix2_sub_q pc_matrix2_sub_q
#endif
#ifndef pc_matrix2_q
#define pc_matrix2_q pc_matrix2_q
#endif
#ifndef pc_matrix2_sub_q
#define pc_matrix2_sub_q pc_matrix2_sub_q
#endif
#ifndef PC_PC_MATRIX2_SUB_Q_H
#define PC_PC_MATRIX2_SUB_Q_H PC_MATRIX2_SUB_Q_H
#endif

