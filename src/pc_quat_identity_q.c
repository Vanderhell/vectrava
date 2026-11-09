#include "pc_quat_identity_q.h"

#include <stddef.h>

bool rm_quat_identity_q(int32_t out_q1_30[4])
{
    if (out_q1_30 == NULL) return false;
    out_q1_30[0] = INT32_C(1073741824);
    out_q1_30[1] = 0;
    out_q1_30[2] = 0;
    out_q1_30[3] = 0;
    return true;
}
