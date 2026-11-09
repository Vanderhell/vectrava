#ifndef PRIMITIVECORE_GEOMETRY_MATRICES_PC_MATRIX2_Q_H
#define PRIMITIVECORE_GEOMETRY_MATRICES_PC_MATRIX2_Q_H

#include <stdint.h>

/* Row-major 2x2 signed Q matrix; all elements share one caller-selected scale. */
typedef struct { int32_t element[4]; } pc_matrix2_q;

/* Implementation-facing spelling retained inside the migrated C modules. */
typedef pc_matrix2_q rm_matrix2_q;

#endif
