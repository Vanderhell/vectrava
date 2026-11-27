#ifndef VECTRAVA_GEOMETRY_AFFINE2_APPLY_Q_H
#define VECTRAVA_GEOMETRY_AFFINE2_APPLY_Q_H
#include <vectrava/geometry/matrix2_q.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Apply a row-major 2x2 Q matrix and Q translation. Each dot product is
 * rounded nearest-even once. False on invalid pointers/fractional_bits or
 * result overflow; failure preserves output. Output may alias point/translation. */
bool vectrava_affine2_apply_q(const vectrava_matrix2_q *matrix, const int32_t point[2],
                        const int32_t translation[2], unsigned fractional_bits,
                        int32_t output[2]);


#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_AFFINE2_APPLY_Q_H */
