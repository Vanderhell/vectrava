#ifndef VECTRAVA_GEOMETRY_QUAT_NLERP_Q_H
#define VECTRAVA_GEOMETRY_QUAT_NLERP_Q_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Shortest-path normalized lerp; scalar-first Q1.30, ratio numerator/denominator. */
bool vectrava_quat_nlerp_q(const int32_t a_q1_30[4], const int32_t b_q1_30[4],
                     uint32_t numerator, uint32_t denominator,
                     int32_t output_q1_30[4]);

#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_QUAT_NLERP_Q_H */
