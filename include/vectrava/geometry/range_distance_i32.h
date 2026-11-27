#ifndef VECTRAVA_GEOMETRY_RANGE_DISTANCE_I32_H
#define VECTRAVA_GEOMETRY_RANGE_DISTANCE_I32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Distance from value to closed interval; zero inside; inverted interval fails. */
bool vectrava_range_distance_i32(int32_t value, int32_t lower, int32_t upper,
                           uint32_t *distance);


#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_RANGE_DISTANCE_I32_H */
