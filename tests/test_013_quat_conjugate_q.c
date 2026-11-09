#include "pc_quat_conjugate_q.h"

#include <limits.h>
#include <stddef.h>
#include <stdint.h>

#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)

int main(void)
{
    int32_t q[4] = { INT32_MIN, INT32_MIN, 2, 3 };
    int32_t out[4] = { 7, 8, 9, 10 };
    uint32_t state = UINT32_C(0x1363cafe);
    unsigned i;

    CHECK(!pc_quat_conjugate_q(NULL, out));
    CHECK(!pc_quat_conjugate_q(q, NULL));
    CHECK(out[0] == 7 && out[1] == 8 && out[2] == 9 && out[3] == 10);
    CHECK(!pc_quat_conjugate_q(q, out));
    CHECK(out[0] == 7 && out[1] == 8 && out[2] == 9 && out[3] == 10);
    q[1] = 1;
    CHECK(pc_quat_conjugate_q(q, out));
    CHECK(out[0] == INT32_MIN && out[1] == -1 && out[2] == -2 && out[3] == -3);
    CHECK(pc_quat_conjugate_q(out, out));
    CHECK(out[0] == INT32_MIN && out[1] == 1 && out[2] == 2 && out[3] == 3);

    for (i = 0u; i < 10000u; ++i) {
        unsigned j;
        for (j = 0u; j < 4u; ++j) {
            state = state * UINT32_C(1664525) + UINT32_C(1013904223);
            q[j] = (int32_t)state;
        }
        if (q[1] == INT32_MIN) q[1] = 0;
        if (q[2] == INT32_MIN) q[2] = 0;
        if (q[3] == INT32_MIN) q[3] = 0;
        CHECK(pc_quat_conjugate_q(q, out));
        CHECK(out[0] == q[0]);
        for (j = 1u; j < 4u; ++j) CHECK(out[j] == -q[j]);
        CHECK(pc_quat_conjugate_q(out, out));
        for (j = 0u; j < 4u; ++j) CHECK(out[j] == q[j]);
    }
    return 0;
}
