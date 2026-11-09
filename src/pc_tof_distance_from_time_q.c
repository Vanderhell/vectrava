#include <stdbool.h>
#include <stdint.h>

/* Convert a monostatic ultrasonic round-trip time to one-way distance.
 * time is in microseconds, sound speed in millimetres/second, result in
 * micrometres rounded to nearest, ties to even. A zero speed or null output
 * fails without modifying the output. */
bool pc_tof_distance_from_time_q(uint32_t round_trip_time_us,
                                 uint32_t speed_mm_per_s,
                                 uint64_t *distance_um)
{
    uint64_t numerator;
    uint64_t quotient;
    uint64_t remainder;
    const uint64_t denominator = UINT64_C(2000);
    if (distance_um == 0 || speed_mm_per_s == 0u) return false;
    numerator = (uint64_t)round_trip_time_us * (uint64_t)speed_mm_per_s;
    quotient = numerator / denominator;
    remainder = numerator % denominator;
    if (remainder > denominator - remainder ||
        (remainder == denominator - remainder && (quotient & UINT64_C(1)) != 0u)) {
        ++quotient;
    }
    *distance_um = quotient;
    return true;
}