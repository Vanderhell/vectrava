#include "pc_segment_progress_q.h"
#include <stddef.h>

bool pc_segment_progress_q(int16_t ax, int16_t ay, int16_t bx, int16_t by,
                           int16_t px, int16_t py, uint32_t *out)
{
    const int64_t dx = (int32_t)bx - (int32_t)ax;
    const int64_t dy = (int32_t)by - (int32_t)ay;
    const int64_t qx = (int32_t)px - (int32_t)ax;
    const int64_t qy = (int32_t)py - (int32_t)ay;
    const int64_t dot = dx * qx + dy * qy;
    const int64_t norm2 = dx * dx + dy * dy;
    int64_t numerator, quotient, remainder;

    if (out == NULL || norm2 == 0) return false;
    if (dot <= 0) {
        *out = 0u;
        return true;
    }
    if (dot >= norm2) {
        *out = UINT32_C(65536);
        return true;
    }
    numerator = dot * INT64_C(65536);
    quotient = numerator / norm2;
    remainder = numerator % norm2;
    if (remainder > norm2 - remainder ||
        (remainder == norm2 - remainder && (quotient & 1) != 0)) {
        ++quotient;
    }
    *out = (uint32_t)quotient;
    return true;
}
