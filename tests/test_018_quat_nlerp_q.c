#include "pc_quat_nlerp_q.h"

#include <stddef.h>
#include <stdint.h>

#define ONE INT32_C(1073741824)
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)

int main(void)
{
    int32_t a[4] = { ONE, 0, 0, 0 };
    int32_t b[4] = { 0, 0, 0, ONE };
    int32_t out[4] = { 7, 8, 9, 10 };
    uint32_t state = UINT32_C(0x1369cafe);
    unsigned i;
    CHECK(!pc_quat_nlerp_q(NULL, b, 0u, 1u, out));
    CHECK(!pc_quat_nlerp_q(a, NULL, 0u, 1u, out));
    CHECK(!pc_quat_nlerp_q(a, b, 0u, 0u, out));
    CHECK(!pc_quat_nlerp_q(a, b, 2u, 1u, out));
    CHECK(!pc_quat_nlerp_q(a, b, 0u, 1u, NULL));
    CHECK(out[0] == 7 && out[1] == 8 && out[2] == 9 && out[3] == 10);
    CHECK(pc_quat_nlerp_q(a, b, 0u, 1u, out));
    CHECK(out[0] == ONE && out[1] == 0 && out[2] == 0 && out[3] == 0);
    CHECK(pc_quat_nlerp_q(a, b, 1u, 1u, out));
    CHECK(out[0] == 0 && out[1] == 0 && out[2] == 0 && out[3] == ONE);

    b[0] = -ONE; b[3] = 0;
    CHECK(pc_quat_nlerp_q(a, b, 1u, 2u, out));
    CHECK(out[0] == ONE && out[1] == 0 && out[2] == 0 && out[3] == 0);
    CHECK(pc_quat_nlerp_q(a, b, 1u, 2u, a));
    CHECK(a[0] == ONE && a[1] == 0 && a[2] == 0 && a[3] == 0);

    a[0] = a[1] = a[2] = a[3] = 0;
    out[0] = 7; out[1] = 8; out[2] = 9; out[3] = 10;
    CHECK(!pc_quat_nlerp_q(a, b, 0u, 1u, out));
    CHECK(out[0] == 7 && out[1] == 8 && out[2] == 9 && out[3] == 10);

    for (i = 0u; i < 10000u; ++i) {
        unsigned j;
        for (j = 0u; j < 4u; ++j) {
            state = state * UINT32_C(1664525) + UINT32_C(1013904223);
            a[j] = (int32_t)((int64_t)(state % UINT32_C(2147483649)) - (int64_t)ONE);
            state = state * UINT32_C(1664525) + UINT32_C(1013904223);
            b[j] = (int32_t)((int64_t)(state % UINT32_C(2147483649)) - (int64_t)ONE);
        }
        if ((a[0]|a[1]|a[2]|a[3]) == 0) a[0] = 1;
        if ((b[0]|b[1]|b[2]|b[3]) == 0) b[0] = 1;
        CHECK(pc_quat_nlerp_q(a, b, i % 101u, 100u, out));
        CHECK(out[0] >= -ONE && out[0] <= ONE);
        {
            uint64_t norm2 = 0u;
            uint64_t unit2 = UINT64_C(1073741824) * UINT64_C(1073741824);
            for (j = 0u; j < 4u; ++j) {
                int64_t component = out[j];
                norm2 += (uint64_t)(component * component);
            }
            CHECK(norm2 > unit2 - (UINT64_C(1) << 36));
            CHECK(norm2 < unit2 + (UINT64_C(1) << 36));
        }
    }
    return 0;
}
