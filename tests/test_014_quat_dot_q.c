#include "pc_quat_dot_q.h"

#include <stddef.h>
#include <stdint.h>

#define ONE INT32_C(1073741824)
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)

int main(void)
{
    int32_t a[4] = { ONE, 0, 0, 0 };
    int32_t b[4] = { ONE, 0, 0, 0 };
    int32_t dot = 99;
    uint32_t state = UINT32_C(0x1366cafe);
    unsigned i;
    CHECK(!pc_quat_dot_q(NULL, b, &dot));
    CHECK(!pc_quat_dot_q(a, NULL, &dot));
    CHECK(!pc_quat_dot_q(a, b, NULL));
    CHECK(dot == 99);
    CHECK(pc_quat_dot_q(a, b, &dot) && dot == ONE);
    b[0] = -ONE;
    CHECK(pc_quat_dot_q(a, b, &dot) && dot == -ONE);
    a[0] = 1; b[0] = ONE / 2;
    CHECK(pc_quat_dot_q(a, b, &dot) && dot == 0);
    a[0] = 3;
    CHECK(pc_quat_dot_q(a, b, &dot) && dot == 2);
    a[0] = -3;
    CHECK(pc_quat_dot_q(a, b, &dot) && dot == -2);
    a[0] = ONE + 1;
    dot = 99;
    CHECK(!pc_quat_dot_q(a, b, &dot) && dot == 99);

    for (i = 0u; i < 10000u; ++i) {
        unsigned j;
        for (j = 0u; j < 4u; ++j) {
            state = state * UINT32_C(1664525) + UINT32_C(1013904223);
            a[j] = (int32_t)((int64_t)(state % UINT32_C(2147483649)) - (int64_t)ONE);
            state = state * UINT32_C(1664525) + UINT32_C(1013904223);
            b[j] = (int32_t)((int64_t)(state % UINT32_C(2147483649)) - (int64_t)ONE);
        }
        dot = 99;
        if (!pc_quat_dot_q(a, b, &dot)) CHECK(dot == 99);
    }
    return 0;
}
