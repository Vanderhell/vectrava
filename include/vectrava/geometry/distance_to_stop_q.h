#ifndef VECTRAVA_GEOMETRY_DISTANCE_TO_STOP_Q_H
#define VECTRAVA_GEOMETRY_DISTANCE_TO_STOP_Q_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Constant-deceleration stopping distance: ceil(|v|^2/(2*a)). Velocity is
 * signed Q16.16 units/s, positive braking deceleration is Q16.16 units/s^2,
 * result is unsigned Q16.16 distance. Zero speed returns 0; nonzero speed
 * with zero deceleration fails atomically. */
bool vectrava_distance_to_stop_q(int32_t velocity_q16_16_per_s,
                           int32_t braking_deceleration_q16_16_per_s2,
                           uint64_t *distance_q16_16);

#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_DISTANCE_TO_STOP_Q_H */
