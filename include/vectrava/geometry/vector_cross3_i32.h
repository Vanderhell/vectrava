#ifndef VECTRAVA_GEOMETRY_VECTOR_CROSS3_I32_H
#define VECTRAVA_GEOMETRY_VECTOR_CROSS3_I32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Exact cross product of two signed int32 3D vectors; output components are int64. */
bool vectrava_vector_cross3_i32(const int32_t a[3], const int32_t b[3], int64_t out[3]);


#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_VECTOR_CROSS3_I32_H */
