#ifndef VECTRAVA_GEOMETRY_QUAT_DOT_Q_H
#define VECTRAVA_GEOMETRY_QUAT_DOT_Q_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Dot scalar-first Q1.30 quaternion components in [-1,1]; round to Q1.30. */
bool vectrava_quat_dot_q(const int32_t a_q1_30[4], const int32_t b_q1_30[4],
                   int32_t *dot_q1_30);



#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_QUAT_DOT_Q_H */
