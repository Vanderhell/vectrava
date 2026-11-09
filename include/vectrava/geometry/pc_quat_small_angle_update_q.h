#ifndef PC_QUAT_SMALL_ANGLE_UPDATE_Q_H
#define PC_QUAT_SMALL_ANGLE_UPDATE_Q_H

#include <stdbool.h>
#include <stdint.h>

/* Apply a body-frame gyro sample (Q16.16 rad/s) over dt microseconds.
 * Rejects when |gyro|*dt exceeds 0.01 rad; intended for small high-rate steps. */
bool pc_quat_small_angle_update_q(const int32_t orientation_q1_30[4],
                                  const int32_t gyro_rad_s_q16_16[3],
                                  uint32_t dt_us,
                                  int32_t output_q1_30[4]);

#endif
