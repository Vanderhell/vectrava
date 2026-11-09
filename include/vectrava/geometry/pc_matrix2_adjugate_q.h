#ifndef PC_MATRIX2_ADJUGATE_Q_H
#define PC_MATRIX2_ADJUGATE_Q_H
#include <stdbool.h>
#include "pc_matrix2_q.h"

/* Adjugate [[a,b],[c,d]] to [[d,-b],[-c,a]], checked and alias-safe. */
bool pc_matrix2_adjugate_q(const pc_matrix2_q *input, pc_matrix2_q *result);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_matrix2_adjugate_q
#define pc_matrix2_adjugate_q pc_matrix2_adjugate_q
#endif
#ifndef pc_matrix2_adjugate_q
#define pc_matrix2_adjugate_q pc_matrix2_adjugate_q
#endif
#ifndef pc_matrix2_q
#define pc_matrix2_q pc_matrix2_q
#endif
#ifndef PC_PC_MATRIX2_ADJUGATE_Q_H
#define PC_PC_MATRIX2_ADJUGATE_Q_H PC_MATRIX2_ADJUGATE_Q_H
#endif

