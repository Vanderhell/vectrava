#ifndef VECTRAVA_GEOMETRY_QUAT_NORM2_Q_H
#define VECTRAVA_GEOMETRY_QUAT_NORM2_Q_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Exact sum of squares for scalar-first Q1.30 quaternion in [-1,1]^4. */
bool vectrava_quat_norm2_q(const int32_t q_q1_30[4], uint64_t *norm2_q2_60);

#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_QUAT_NORM2_Q_H */
