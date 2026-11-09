#include "pc_vector_rotate2_q.h"
#include <stddef.h>

static const int64_t atan_turns_q31[30] = {
    INT64_C(268435456),INT64_C(158466703),INT64_C(83729454),INT64_C(42502378),INT64_C(21333666),
    INT64_C(10677233),INT64_C(5339919),INT64_C(2670123),INT64_C(1335082),INT64_C(667543),
    INT64_C(333772),INT64_C(166886),INT64_C(83443),INT64_C(41722),INT64_C(20861),INT64_C(10430),
    INT64_C(5215),INT64_C(2608),INT64_C(1304),INT64_C(652),INT64_C(326),INT64_C(163),INT64_C(81),
    INT64_C(41),INT64_C(20),INT64_C(10),INT64_C(5),INT64_C(3),INT64_C(1),INT64_C(1)
};

static int64_t shift_zero(int64_t value, unsigned shift)
{
    const uint64_t mag = value < 0 ? (uint64_t)(-value) : (uint64_t)value;
    const int64_t q = (int64_t)(mag >> shift);
    return value < 0 ? -q : q;
}

static int64_t round_even_q30(int64_t value)
{
    const uint64_t mag = value < 0 ? (uint64_t)(-value) : (uint64_t)value;
    uint64_t q = mag >> 30;
    const uint64_t r = mag & ((UINT64_C(1) << 30) - 1u);
    if (r > (UINT64_C(1) << 29) || (r == (UINT64_C(1) << 29) && (q & 1u) != 0u)) ++q;
    return value < 0 ? -(int64_t)q : (int64_t)q;
}

static int16_t saturate_i16(int64_t value)
{
    if (value > INT16_MAX) return INT16_MAX;
    if (value < INT16_MIN) return INT16_MIN;
    return (int16_t)value;
}

bool pc_vector_rotate2_q(const int16_t input_q15[2], uint32_t angle_turns_q0_32, int16_t output_q15[2])
{
    int64_t x, y, z, x_next, y_next;
    int64_t result_x, result_y;
    unsigned i;
    if (input_q15 == NULL || output_q15 == NULL) return false;
    x = (int64_t)input_q15[0] * INT64_C(652032874);
    y = (int64_t)input_q15[1] * INT64_C(652032874);
    z = (int64_t)(angle_turns_q0_32 >> 1);
    if ((angle_turns_q0_32 & UINT32_C(0x80000000)) != 0u) z -= INT64_C(2147483648);
    if (z > INT64_C(536870912)) { z -= INT64_C(1073741824); x = -x; y = -y; }
    else if (z < -INT64_C(536870912)) { z += INT64_C(1073741824); x = -x; y = -y; }
    for (i = 0u; i < 30u; ++i) {
        const int64_t sx = shift_zero(x, i), sy = shift_zero(y, i);
        if (z >= 0) { x_next = x - sy; y_next = y + sx; z -= atan_turns_q31[i]; }
        else { x_next = x + sy; y_next = y - sx; z += atan_turns_q31[i]; }
        x = x_next; y = y_next;
    }
    result_x = round_even_q30(x);
    result_y = round_even_q30(y);
    output_q15[0] = saturate_i16(result_x);
    output_q15[1] = saturate_i16(result_y);
    return true;
}
