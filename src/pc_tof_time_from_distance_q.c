#include <stdbool.h>
#include <stdint.h>

/* Convert one-way distance to monostatic ultrasonic round-trip time.
 * Distance is in micrometres; sound speed is in millimetres/second; result is
 * microseconds rounded nearest, ties-to-even. Zero speed or null output fails
 * without modifying the output. */
bool pc_tof_time_from_distance_q(uint32_t distance_um,
                                 uint32_t speed_mm_per_s,
                                 uint64_t *round_trip_time_us)
{
    uint64_t numerator;
    uint64_t quotient;
    uint64_t remainder;
    if (round_trip_time_us == 0 || speed_mm_per_s == 0u) return false;
    numerator = (uint64_t)distance_um * UINT64_C(2000);
    quotient = numerator / speed_mm_per_s;
    remainder = numerator % speed_mm_per_s;
    if (remainder > (uint64_t)speed_mm_per_s - remainder ||
        (remainder == (uint64_t)speed_mm_per_s - remainder &&
         (quotient & UINT64_C(1)) != 0u)) {
        ++quotient;
    }
    *round_trip_time_us = quotient;
    return true;
}