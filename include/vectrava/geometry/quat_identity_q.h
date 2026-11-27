#ifndef VECTRAVA_GEOMETRY_QUAT_IDENTITY_Q_H
#define VECTRAVA_GEOMETRY_QUAT_IDENTITY_Q_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Store scalar-first Q1.30 identity quaternion [w, x, y, z]. */
bool vectrava_quat_identity_q(int32_t out_q1_30[4]);



#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_QUAT_IDENTITY_Q_H */
