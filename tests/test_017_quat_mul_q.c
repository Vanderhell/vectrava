#include "pc_quat_mul_q.h"

#include <limits.h>
#include <stddef.h>
#include <stdint.h>

#define ONE INT32_C(1073741824)
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)

int main(void)
{
    int32_t identity[4] = { ONE, 0, 0, 0 };
    int32_t a[4] = { ONE, 0, 0, 0 };
    int32_t b[4] = { 0, ONE, 0, 0 };
    int32_t out[4] = { 7, 8, 9, 10 };
    CHECK(!pc_quat_mul_q(NULL, b, out));
    CHECK(!pc_quat_mul_q(a, NULL, out));
    CHECK(!pc_quat_mul_q(a, b, NULL));
    CHECK(pc_quat_mul_q(identity, b, out));
    CHECK(out[0] == 0 && out[1] == ONE && out[2] == 0 && out[3] == 0);
    CHECK(pc_quat_mul_q(a, identity, out));
    CHECK(out[0] == ONE && out[1] == 0 && out[2] == 0 && out[3] == 0);

    a[0] = 1; a[1] = a[2] = a[3] = 0;
    b[0] = ONE / 2; b[1] = b[2] = b[3] = 0;
    CHECK(pc_quat_mul_q(a, b, out));
    CHECK(out[0] == 0);
    a[0] = 3;
    CHECK(pc_quat_mul_q(a, b, out));
    CHECK(out[0] == 2);
    a[0] = -3;
    CHECK(pc_quat_mul_q(a, b, out));
    CHECK(out[0] == -2);

    a[0] = ONE + 1;
    out[0] = ONE; out[1] = out[2] = out[3] = 0;
    CHECK(!pc_quat_mul_q(a, b, out));
    CHECK(out[0] == ONE && out[1] == 0 && out[2] == 0 && out[3] == 0);

    a[0] = ONE; a[1] = a[2] = a[3] = 0;
    b[0] = ONE; b[1] = b[2] = b[3] = 0;
    CHECK(pc_quat_mul_q(a, b, a));
    CHECK(a[0] == ONE && a[1] == 0 && a[2] == 0 && a[3] == 0);

    a[0] = a[1] = a[2] = a[3] = ONE;
    b[0] = b[1] = b[2] = b[3] = ONE;
    out[0] = 31; out[1] = 32; out[2] = 33; out[3] = 34;
    CHECK(!pc_quat_mul_q(a, b, out));
    CHECK(out[0] == 31 && out[1] == 32 && out[2] == 33 && out[3] == 34);
    return 0;
}
