#ifndef VECTRAVA_GEOMETRY_RANGE_CONTAINS_I32_H
#define VECTRAVA_GEOMETRY_RANGE_CONTAINS_I32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Closed interval predicate. An inverted interval returns false. */
bool vectrava_range_contains_i32(int32_t value, int32_t lower, int32_t upper);


#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_RANGE_CONTAINS_I32_H */
