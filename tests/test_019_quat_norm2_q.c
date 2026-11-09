#include "pc_quat_norm2_q.h"

#include <stddef.h>
#include <stdint.h>

#define ONE INT32_C(1073741824)
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)

int main(void)
{
    int32_t q[4] = { ONE, 0, 0, 0 };
    uint64_t norm2 = 123u;
    uint32_t state = UINT32_C(0x1367cafe);
    unsigned i;
    CHECK(!pc_quat_norm2_q(NULL, &norm2));
    CHECK(!pc_quat_norm2_q(q, NULL));
    CHECK(norm2 == 123u);
    CHECK(pc_quat_norm2_q(q, &norm2) && norm2 == UINT64_C(1152921504606846976));
    q[0] = q[1] = q[2] = q[3] = ONE;
    CHECK(pc_quat_norm2_q(q, &norm2) && norm2 == UINT64_C(4611686018427387904));
    q[3] = ONE + 1;
    norm2 = 123u;
    CHECK(!pc_quat_norm2_q(q, &norm2) && norm2 == 123u);

    for (i = 0u; i < 10000u; ++i) {
        unsigned j;
        uint64_t expected = 0u;
        for (j = 0u; j < 4u; ++j) {
            int64_t component;
            state = state * UINT32_C(1664525) + UINT32_C(1013904223);
            q[j] = (int32_t)((int64_t)(state % UINT32_C(2147483649)) - (int64_t)ONE);
            component = q[j];
            expected += (uint64_t)(component * component);
        }
        CHECK(pc_quat_norm2_q(q, &norm2) && norm2 == expected);
    }
    return 0;
}
