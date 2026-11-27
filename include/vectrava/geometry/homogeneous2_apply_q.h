#ifndef VECTRAVA_GEOMETRY_HOMOGENEOUS2_APPLY_Q_H
#define VECTRAVA_GEOMETRY_HOMOGENEOUS2_APPLY_Q_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Apply a row-major 3x3 Q matrix to a homogeneous 3-vector. Each row dot
 * product is rounded nearest-even once. Returns homogeneous output; it does
 * not divide by W. False preserves output. Output may alias matrix/vector. */
bool vectrava_homogeneous2_apply_q(const int32_t matrix[9], const int32_t vector[3],
                             unsigned fractional_bits, int32_t output[3]);


#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_HOMOGENEOUS2_APPLY_Q_H */
