#ifndef PC_PC_TRANSLATE_POINT2_I32_H
#define PC_PC_TRANSLATE_POINT2_I32_H
#include <stdbool.h>
#include <stdint.h>

/* Add a delta to an int32 coordinate pair. False on null/aliased outputs or
 * if either result overflows; failure preserves both output values. */
bool pc_translate_point2_i32(int32_t x, int32_t y, int32_t dx, int32_t dy,
                             int32_t *out_x, int32_t *out_y);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_translate_point2_i32
#define pc_translate_point2_i32 pc_translate_point2_i32
#endif
#ifndef pc_translate_point2_i32
#define pc_translate_point2_i32 pc_translate_point2_i32
#endif
#ifndef PC_PC_PC_TRANSLATE_POINT2_I32_H
#define PC_PC_PC_TRANSLATE_POINT2_I32_H PC_PC_TRANSLATE_POINT2_I32_H
#endif

