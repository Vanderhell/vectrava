#include "pc_quat_from_axis_angle_q.h"

#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <math.h>
#include <stdio.h>

#define ONE INT32_C(1073741824)
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)

static int32_t round_even_q30(long double value)
{
    long double magnitude = fabsl(value);
    long double integral = floorl(magnitude);
    uint64_t q = (uint64_t)integral;
    long double fraction = magnitude - integral;
    if (fraction > 0.5L || (fraction == 0.5L && (q & 1u) != 0u)) ++q;
    return value < 0.0L ? -(int32_t)q : (int32_t)q;
}

int main(void)
{
    int32_t axis[3] = { ONE, 0, 0 };
    int32_t out[4] = { 7, 8, 9, 10 };
    uint32_t state = UINT32_C(0x1370cafe);
    unsigned i;
    uint32_t max_trig_error = 0u;
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

    {
        static const uint32_t edges[] = {0u, 1u, UINT32_C(0x3fffffff),
            UINT32_C(0x40000000), UINT32_C(0x40000001), UINT32_C(0x7fffffff),
            UINT32_C(0x80000000), UINT32_C(0xbfffffff), UINT32_C(0xc0000000),
            UINT32_C(0xc0000001), UINT32_MAX};
        unsigned k;
        for (k = 0u; k < sizeof(edges) / sizeof(edges[0]); ++k) {
            int32_t expected_w, expected_x;
            uint32_t error_w, error_x;
            long double half_angle = (long double)edges[k] * acosl(-1.0L) / 4294967296.0L;
            CHECK(pc_quat_from_axis_angle_q(axis, edges[k], out));
            expected_w = round_even_q30(cosl(half_angle) * ONE);
            expected_x = round_even_q30(sinl(half_angle) * ONE);
            { int64_t d=(int64_t)out[0]-expected_w; error_w=(uint32_t)(d<0?-d:d); }
            { int64_t d=(int64_t)out[1]-expected_x; error_x=(uint32_t)(d<0?-d:d); }
            if(error_w>max_trig_error)max_trig_error=error_w;
            if(error_x>max_trig_error)max_trig_error=error_x;
            CHECK(error_w<=20u && error_x<=20u);
        }
    }

    /* Differentially validate the CORDIC half-angle sine/cosine over all turns. */
    for (i = 0u; i < 100000u; ++i) {
        int32_t expected_w, expected_x;
        int64_t ew, ex;
        long double half_angle;
        uint32_t error_w, error_x;
        state = state * UINT32_C(1664525) + UINT32_C(1013904223);
        half_angle = (long double)state * acosl(-1.0L) / 4294967296.0L;
        CHECK(pc_quat_from_axis_angle_q(axis, state, out));
        expected_w = round_even_q30(cosl(half_angle) * ONE);
        expected_x = round_even_q30(sinl(half_angle) * ONE);
        ew = (int64_t)out[0] - expected_w; ex = (int64_t)out[1] - expected_x;
        error_w = (uint32_t)(ew < 0 ? -ew : ew);
        error_x = (uint32_t)(ex < 0 ? -ex : ex);
        if (error_w > max_trig_error) max_trig_error = error_w;
        if (error_x > max_trig_error) max_trig_error = error_x;
        CHECK(error_w <= 20u && error_x <= 20u);
    }
    printf("axis-angle CORDIC maximum component error: %u Q1.30 codes\n", max_trig_error);

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
