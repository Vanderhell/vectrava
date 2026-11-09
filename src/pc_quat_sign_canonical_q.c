#include "pc_quat_sign_canonical_q.h"

#include <stddef.h>

#define ONE INT32_C(1073741824)

bool pc_quat_sign_canonical_q(const int32_t input[4], int32_t output[4])
{
    int32_t value[4];
    bool negate = false;
    unsigned i;

    if (input == NULL || output == NULL) return false;
    for (i = 0u; i < 4u; ++i) {
        if (input[i] < -ONE || input[i] > ONE) return false;
    }
    for (i = 0u; i < 4u; ++i) {
        if (input[i] != 0) {
            negate = input[i] < 0;
            break;
        }
    }
    if (i == 4u) return false;
    for (i = 0u; i < 4u; ++i) value[i] = negate ? -input[i] : input[i];
    for (i = 0u; i < 4u; ++i) output[i] = value[i];
    return true;
}
