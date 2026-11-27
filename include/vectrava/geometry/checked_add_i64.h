#ifndef VECTRAVA_GEOMETRY_CHECKED_ADD_I64_H
#define VECTRAVA_GEOMETRY_CHECKED_ADD_I64_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Store a+b exactly. False for null output or signed overflow; failure writes
 * nothing to result. */
bool vectrava_checked_add_i64(int64_t a, int64_t b, int64_t *result);


#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_CHECKED_ADD_I64_H */
