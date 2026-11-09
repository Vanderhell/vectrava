#ifndef PC_VECTOR_CROSS3_I32_H
#define PC_VECTOR_CROSS3_I32_H
#include <stdbool.h>
#include <stdint.h>

/* Exact cross product of two signed int32 3D vectors; output components are int64. */
bool pc_vector_cross3_i32(const int32_t a[3], const int32_t b[3], int64_t out[3]);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_vector_cross3_i32
#define pc_vector_cross3_i32 pc_vector_cross3_i32
#endif
#ifndef pc_vector_cross3_i32
#define pc_vector_cross3_i32 pc_vector_cross3_i32
#endif
#ifndef PC_PC_VECTOR_CROSS3_I32_H
#define PC_PC_VECTOR_CROSS3_I32_H PC_VECTOR_CROSS3_I32_H
#endif

