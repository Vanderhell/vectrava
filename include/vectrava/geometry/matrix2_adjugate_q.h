#ifndef VECTRAVA_GEOMETRY_MATRIX2_ADJUGATE_Q_H
#define VECTRAVA_GEOMETRY_MATRIX2_ADJUGATE_Q_H
#include <stdbool.h>
#include <vectrava/geometry/matrix2_q.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Adjugate [[a,b],[c,d]] to [[d,-b],[-c,a]], checked and alias-safe. */
bool vectrava_matrix2_adjugate_q(const vectrava_matrix2_q *input, vectrava_matrix2_q *result);


#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_MATRIX2_ADJUGATE_Q_H */
