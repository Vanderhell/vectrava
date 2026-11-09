#include "pc_quat_from_axis_angle_q.h"

#include <limits.h>
#include <stddef.h>
#include <stdint.h>

#define ONE INT32_C(1073741824)
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)

int main(void)
{
    int32_t axis[3] = { ONE, 0, 0 };
    int32_t out[4] = { 7, 8, 9, 10 };
    uint32_t state = UINT32_C(0x1370cafe);
    unsigned i;
    CHECK(!pc_quat_from_axis_angle_q(NULL, 0u, out));
    CHECK(!pc_quat_from_axis_angle_q(axis, 0u, NULL));
    axis[0] = axis[1] = axis[2] = 0;
    CHECK(!pc_quat_from_axis_angle_q(axis, 0u, out));
    CHECK(out[0] == 7 && out[1] == 8 && out[2] == 9 && out[3] == 10);
    axis[0] = ONE;
    CHECK(pc_quat_from_axis_angle_q(axis, 0u, out));
    CHECK(out[0] == ONE && out[1] == 0 && out[2] == 0 && out[3] == 0);
    CHECK(pc_quat_from_axis_angle_q(axis, UINT32_C(0x80000000), out));
    CHECK(out[0] > -16 && out[0] < 16 && out[1] > ONE - 16 && out[1] < ONE + 16 &&
          out[2] == 0 && out[3] == 0);
    CHECK(pc_quat_from_axis_angle_q(axis, UINT32_C(0x40000000), out));
    CHECK(out[0] > 0 && out[1] > 0 && out[2] == 0 && out[3] == 0);

    for (i = 0u; i < 10000u; ++i) {
        unsigned j;
        uint64_t norm2 = 0u;
        for (j = 0u; j < 3u; ++j) {
            state = state * UINT32_C(1664525) + UINT32_C(1013904223);
            axis[j] = (int32_t)state;
        }
        if ((axis[0] | axis[1] | axis[2]) == 0) axis[0] = 1;
        state = state * UINT32_C(1664525) + UINT32_C(1013904223);
        CHECK(pc_quat_from_axis_angle_q(axis, state, out));
        for (j = 0u; j < 4u; ++j) {
            int64_t component = out[j];
            norm2 += (uint64_t)(component * component);
        }
        CHECK(norm2 > UINT64_C(1152921504606846976) - (UINT64_C(1) << 36));
        CHECK(norm2 < UINT64_C(1152921504606846976) + (UINT64_C(1) << 36));
    }
    return 0;
}
