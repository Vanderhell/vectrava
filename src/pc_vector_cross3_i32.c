#include "pc_vector_cross3_i32.h"
#include <stddef.h>

bool rm_vector_cross3_i32(const int32_t a[3], const int32_t b[3], int64_t out[3])
{
    int64_t result[3];
    unsigned i;
    if (a == NULL || b == NULL || out == NULL) return false;
    result[0] = (int64_t)a[1] * b[2] - (int64_t)a[2] * b[1];
    result[1] = (int64_t)a[2] * b[0] - (int64_t)a[0] * b[2];
    result[2] = (int64_t)a[0] * b[1] - (int64_t)a[1] * b[0];
    for (i = 0u; i < 3u; ++i) out[i] = result[i];
    return true;
}
