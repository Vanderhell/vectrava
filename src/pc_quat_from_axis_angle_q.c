#include "pc_quat_from_axis_angle_q.h"

#include "pc_quat_normalize_q.h"

#include <stddef.h>

#define Q30_ONE INT32_C(1073741824)
#define QUARTER_TURN UINT32_C(0x40000000)
#define HALF_TURN UINT32_C(0x80000000)
#define THREE_QUARTERS UINT32_C(0xc0000000)

static const int64_t atan_turns_q32[31] = {
    INT64_C(536870912), INT64_C(316933406), INT64_C(167458907), INT64_C(85004756),
    INT64_C(42667331), INT64_C(21354465), INT64_C(10679838), INT64_C(5340245),
    INT64_C(2670163), INT64_C(1335087), INT64_C(667544), INT64_C(333772),
    INT64_C(166886), INT64_C(83443), INT64_C(41722), INT64_C(20861),
    INT64_C(10430), INT64_C(5215), INT64_C(2608), INT64_C(1304), INT64_C(652),
    INT64_C(326), INT64_C(163), INT64_C(81), INT64_C(41), INT64_C(20),
    INT64_C(10), INT64_C(5), INT64_C(3), INT64_C(1), INT64_C(1)
};

static int64_t shift_zero(int64_t value, unsigned shift)
{
    uint64_t magnitude = value < 0 ? (uint64_t)(-value) : (uint64_t)value;
    int64_t quotient = (int64_t)(magnitude >> shift);
    return value < 0 ? -quotient : quotient;
}

static int32_t clamp_q30(int64_t value)
{
    if (value > Q30_ONE) return Q30_ONE;
    if (value < -Q30_ONE) return -Q30_ONE;
    return (int32_t)value;
}

static int64_t divide_round_even(int64_t numerator, uint64_t denominator)
{
    uint64_t magnitude = numerator < 0 ? (uint64_t)(-numerator) : (uint64_t)numerator;
    uint64_t quotient = magnitude / denominator;
    uint64_t remainder = magnitude % denominator;
    if (remainder > denominator - remainder ||
        (remainder == denominator - remainder && (quotient & 1u) != 0u)) ++quotient;
    return numerator < 0 ? -(int64_t)quotient : (int64_t)quotient;
}

static void sin_cos_half_angle(uint32_t angle_turns, int32_t *cosine, int32_t *sine)
{
    int64_t x = INT64_C(652032874);
    int64_t y = 0;
    uint32_t half_phase = angle_turns >> 1;
    int64_t z;
    bool negate = false;
    unsigned i;
    if (angle_turns == 0u) {
        *cosine = Q30_ONE; *sine = 0;
        return;
    }
    if (half_phase <= QUARTER_TURN) z = half_phase;
    else if (half_phase < THREE_QUARTERS) {
        z = (int64_t)half_phase - (int64_t)HALF_TURN;
        negate = true;
    } else z = (int64_t)half_phase - INT64_C(4294967296);
    for (i = 0u; i < 31u; ++i) {
        int64_t sx = shift_zero(x, i), sy = shift_zero(y, i);
        if (z >= 0) { x -= sy; y += sx; z -= atan_turns_q32[i]; }
        else { x += sy; y -= sx; z += atan_turns_q32[i]; }
    }
    if (negate) { x = -x; y = -y; }
    *cosine = clamp_q30(x); *sine = clamp_q30(y);
}

bool pc_quat_from_axis_angle_q(const int32_t axis[3], uint32_t angle_turns_q0_32,
                               int32_t output[4])
{
    int32_t axis_quat[4], unit_axis[4], result[4];
    int32_t cosine, sine;
    unsigned i;
    if (axis == NULL || output == NULL) return false;
    axis_quat[0] = 0;
    for (i = 0u; i < 3u; ++i) axis_quat[i + 1u] = axis[i];
    if (!pc_quat_normalize_q(axis_quat, unit_axis)) return false;
    sin_cos_half_angle(angle_turns_q0_32, &cosine, &sine);
    result[0] = cosine;
    for (i = 0u; i < 3u; ++i) {
        int64_t product = (int64_t)unit_axis[i + 1u] * sine;
        result[i + 1u] = clamp_q30(divide_round_even(product, UINT64_C(1073741824)));
    }
    for (i = 0u; i < 4u; ++i) output[i] = result[i];
    return true;
}
