#ifndef VECTRAVA_GEOMETRY_SEGMENT_PROGRESS_Q_H
#define VECTRAVA_GEOMETRY_SEGMENT_PROGRESS_Q_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Return the clamped projection parameter of point P on segment A->B as
 * unsigned Q16.16 in [0,65536]. Coordinates are int16 grid units. False on
 * A==B or null output; failure preserves *out. */
bool vectrava_segment_progress_q(int16_t ax, int16_t ay, int16_t bx, int16_t by,
                           int16_t px, int16_t py, uint32_t *out);


#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_SEGMENT_PROGRESS_Q_H */
