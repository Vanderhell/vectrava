#ifndef PC_PC_TOF_TIME_FROM_DISTANCE_Q_H
#define PC_PC_TOF_TIME_FROM_DISTANCE_Q_H

#include <stdbool.h>
#include <stdint.h>

/* Convert one-way distance to monostatic ultrasonic round-trip time.
 * Distance is in micrometres; sound speed is in millimetres/second; result is
 * microseconds rounded to nearest, ties to even. Zero speed or null output
 * fails without modifying the output. */
bool pc_tof_time_from_distance_q(uint32_t distance_um,
                                 uint32_t speed_mm_per_s,
                                 uint64_t *round_trip_time_us);

#endif