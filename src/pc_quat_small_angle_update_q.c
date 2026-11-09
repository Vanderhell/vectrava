#include "pc_quat_small_angle_update_q.h"
#include "pc_quat_normalize_q.h"
#include "pc_q_hypot3.h"
#include "pc_quat_mul_q.h"

#include <stddef.h>

#define ONE INT32_C(1073741824)
#define MAX_RATE INT32_C(65536000)

static int64_t round_signed_div(int64_t x, uint64_t d)
{
    uint64_t m = x < 0 ? (uint64_t)(-x) : (uint64_t)x;
    uint64_t q = m / d;
    uint64_t r = m % d;
    if (r > d - r || (r == d - r && (q & 1u) != 0u)) ++q;
    return x < 0 ? -(int64_t)q : (int64_t)q;
}

bool pc_quat_small_angle_update_q(const int32_t orientation[4],
                                  const int32_t gyro[3], uint32_t dt,
                                  int32_t output[4])
{
    int32_t q[4], delta[4] = { ONE, 0, 0, 0 }, product[4], result[4], magnitude;
    uint64_t step;
    unsigned i;

    if (orientation == NULL || gyro == NULL || output == NULL || dt > 100000u) return false;
    for (i = 0u; i < 3u; ++i) {
        if (gyro[i] < -MAX_RATE || gyro[i] > MAX_RATE) return false;
    }
    if (!pc_q_hypot3(gyro[0], gyro[1], gyro[2], &magnitude)) return false;
    step = (uint64_t)(uint32_t)magnitude * dt;
    if (step > UINT64_C(655360000)) return false;
    if (!pc_quat_normalize_q(orientation, q)) return false;
    for (i = 0u; i < 3u; ++i) {
        delta[i + 1u] = (int32_t)round_signed_div(
            (int64_t)gyro[i] * dt * 8192, UINT64_C(1000000));
    }
    if (!pc_quat_mul_q(q, delta, product) || !pc_quat_normalize_q(product, result)) return false;
    for (i = 0u; i < 4u; ++i) output[i] = result[i];
    return true;
}
