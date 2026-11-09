#ifndef PRIMITIVECORE_PC_TOF_DISTANCE_FROM_TIME_Q_H
#define PRIMITIVECORE_PC_TOF_DISTANCE_FROM_TIME_Q_H

#include <stdbool.h>
#include <stdint.h>

/* Convert monostatic ultrasonic round-trip time to one-way distance.
 * Time is in microseconds; sound speed is in millimetres/second; output is
 * micrometres rounded to nearest, ties to even. Zero speed or null output
 * fails without modifying the output. */
bool pc_tof_distance_from_time_q(uint32_t round_trip_time_us,
                                 uint32_t speed_mm_per_s,
                                 uint64_t *distance_um);

#endif