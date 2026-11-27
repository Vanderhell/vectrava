#ifndef VECTRAVA_GEOMETRY_QUAT_NORMALIZE_Q_H
#define VECTRAVA_GEOMETRY_QUAT_NORMALIZE_Q_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Normalize scalar-first Q1.30 quaternion; reject zero and preserve output. */
bool vectrava_quat_normalize_q(const int32_t input_q1_30[4], int32_t output_q1_30[4]);



#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_QUAT_NORMALIZE_Q_H */
