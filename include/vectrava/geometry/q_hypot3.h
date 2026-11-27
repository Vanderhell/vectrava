#ifndef VECTRAVA_GEOMETRY_Q_HYPOT3_H
#define VECTRAVA_GEOMETRY_Q_HYPOT3_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Nearest-even Euclidean norm of three same-scale signed Q raw values.
 * False on null output or int32 overflow; failure preserves *out. */
bool vectrava_q_hypot3(int32_t x, int32_t y, int32_t z, int32_t *out);


#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_Q_HYPOT3_H */
