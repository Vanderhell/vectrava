#ifndef VECTRAVA_GEOMETRY_QUAT_MUL_Q_H
#define VECTRAVA_GEOMETRY_QUAT_MUL_Q_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Hamilton product of scalar-first Q1.30 quaternions with components in [-1,1]. */
bool vectrava_quat_mul_q(const int32_t a_q1_30[4], const int32_t b_q1_30[4],
                   int32_t output_q1_30[4]);



#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_QUAT_MUL_Q_H */
