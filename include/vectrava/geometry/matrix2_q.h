#ifndef VECTRAVA_GEOMETRY_MATRIX2_Q_H
#define VECTRAVA_GEOMETRY_MATRIX2_Q_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Row-major 2x2 signed Q matrix; all elements share one caller-selected scale. */
typedef struct { int32_t element[4]; } vectrava_matrix2_q;

/* Implementation-facing spelling retained inside the migrated C modules. */

#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_MATRIX2_Q_H */
