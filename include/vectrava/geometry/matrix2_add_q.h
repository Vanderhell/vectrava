#ifndef VECTRAVA_GEOMETRY_MATRIX2_ADD_Q_H
#define VECTRAVA_GEOMETRY_MATRIX2_ADD_Q_H
#include <stdbool.h>
#include <vectrava/geometry/matrix2_q.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Exact elementwise addition. On any component overflow, write nothing. */
bool vectrava_matrix2_add_q(const vectrava_matrix2_q *a, const vectrava_matrix2_q *b,
                      vectrava_matrix2_q *result);


#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_MATRIX2_ADD_Q_H */
