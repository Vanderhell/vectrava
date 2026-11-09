#ifndef PRIMITIVECORE_RM_SEGMENT_PROGRESS_Q_H
#define PRIMITIVECORE_RM_SEGMENT_PROGRESS_Q_H
#include <stdbool.h>
#include <stdint.h>
/* Return the clamped projection parameter of point P on segment A->B as
 * unsigned Q16.16 in [0,65536]. Coordinates are int16 grid units. False on
 * A==B or null output; failure preserves *out. */
bool rm_segment_progress_q(int16_t ax, int16_t ay, int16_t bx, int16_t by,
                           int16_t px, int16_t py, uint32_t *out);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_segment_progress_q
#define pc_segment_progress_q rm_segment_progress_q
#endif
#ifndef pc_segment_progress_q
#define pc_segment_progress_q rm_segment_progress_q
#endif
#ifndef PC_PRIMITIVECORE_RM_SEGMENT_PROGRESS_Q_H
#define PC_PRIMITIVECORE_RM_SEGMENT_PROGRESS_Q_H PRIMITIVECORE_RM_SEGMENT_PROGRESS_Q_H
#endif

