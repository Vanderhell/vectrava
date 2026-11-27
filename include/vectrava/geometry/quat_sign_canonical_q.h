#ifndef VECTRAVA_GEOMETRY_QUAT_SIGN_CANONICAL_Q_H
#define VECTRAVA_GEOMETRY_QUAT_SIGN_CANONICAL_Q_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Canonicalize q/-q by making the first nonzero scalar-first component
 * positive. Components must be in the inclusive Q1.30 range [-1,1]. */
bool vectrava_quat_sign_canonical_q(const int32_t input_q1_30[4],
                              int32_t output_q1_30[4]);

#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_QUAT_SIGN_CANONICAL_Q_H */
