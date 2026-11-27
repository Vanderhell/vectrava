#ifndef VECTRAVA_GEOMETRY_CHECKED_NEG_I64_H
#define VECTRAVA_GEOMETRY_CHECKED_NEG_I64_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Store -value exactly; false for null output or INT64_MIN, preserving output. */
bool vectrava_checked_neg_i64(int64_t value, int64_t *result);


#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_CHECKED_NEG_I64_H */
