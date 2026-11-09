#ifndef PC_RANGE_DISTANCE_I32_H
#define PC_RANGE_DISTANCE_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Distance from value to closed interval; zero inside; inverted interval fails. */
bool pc_range_distance_i32(int32_t value, int32_t lower, int32_t upper,
                           uint32_t *distance);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_range_distance_i32
#define pc_range_distance_i32 pc_range_distance_i32
#endif
#ifndef pc_range_distance_i32
#define pc_range_distance_i32 pc_range_distance_i32
#endif
#ifndef PC_PC_RANGE_DISTANCE_I32_H
#define PC_PC_RANGE_DISTANCE_I32_H PC_RANGE_DISTANCE_I32_H
#endif

