#include "pc_quat_conjugate_q.h"

#include <limits.h>
#include <stddef.h>

bool pc_quat_conjugate_q(const int32_t input_q1_30[4], int32_t output_q1_30[4])
{
    int32_t result[4];
    unsigned i;
    if (input_q1_30 == NULL || output_q1_30 == NULL) return false;
    for (i = 1u; i < 4u; ++i) {
        if (input_q1_30[i] == INT32_MIN) return false;
    }
    result[0] = input_q1_30[0];
    for (i = 1u; i < 4u; ++i) result[i] = -input_q1_30[i];
    for (i = 0u; i < 4u; ++i) output_q1_30[i] = result[i];
    return true;
}
