#include "pc_quat_normalize_q.h"

#include <limits.h>
#include <stddef.h>
#include <stdint.h>

#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)

int main(void)
{
    int32_t input[4] = { INT32_MIN, INT32_MIN, INT32_MIN, INT32_MIN };
    int32_t output[4] = { 7, 8, 9, 10 };
    unsigned i;
    uint32_t state = UINT32_C(0x1362cafe);

    CHECK(!pc_quat_normalize_q(NULL, output));
    CHECK(!pc_quat_normalize_q(input, NULL));
    CHECK(output[0] == 7 && output[1] == 8 && output[2] == 9 && output[3] == 10);
    input[0] = input[1] = input[2] = input[3] = 0;
    CHECK(!pc_quat_normalize_q(input, output));
    CHECK(output[0] == 7 && output[1] == 8 && output[2] == 9 && output[3] == 10);

    input[0] = INT32_MIN;
    input[1] = INT32_MIN;
    input[2] = INT32_MIN;
    input[3] = INT32_MIN;
    CHECK(pc_quat_normalize_q(input, output));
    for (i = 0u; i < 4u; ++i) CHECK(output[i] == -INT32_C(536870912));

    input[0] = INT32_C(1073741824);
    input[1] = input[2] = input[3] = 0;
    CHECK(pc_quat_normalize_q(input, output));
    CHECK(output[0] == INT32_C(1073741824));
    CHECK(output[1] == 0 && output[2] == 0 && output[3] == 0);

    input[0] = INT32_C(1); input[1] = INT32_C(2);
    input[2] = INT32_C(3); input[3] = INT32_C(4);
    CHECK(pc_quat_normalize_q(input, input));
    CHECK(input[0] > 0 && input[1] > 0 && input[2] > 0 && input[3] > 0);

    for (i = 0u; i < 10000u; ++i) {
        unsigned j;
        for (j = 0u; j < 4u; ++j) {
            state = state * UINT32_C(1664525) + UINT32_C(1013904223);
            input[j] = (int32_t)state;
        }
        if ((input[0] | input[1] | input[2] | input[3]) == 0) input[0] = 1;
        CHECK(pc_quat_normalize_q(input, output));
        for (j = 0u; j < 4u; ++j) {
            CHECK((input[j] < 0) == (output[j] < 0) || output[j] == 0);
            CHECK(output[j] >= -INT32_C(1073741824) && output[j] <= INT32_C(1073741824));
        }
        {
            uint64_t norm2 = 0u;
            uint64_t one2 = UINT64_C(1073741824) * UINT64_C(1073741824);
            for (j = 0u; j < 4u; ++j) {
                int64_t component = output[j];
                norm2 += (uint64_t)(component * component);
            }
            CHECK(norm2 > one2 - (UINT64_C(1) << 36));
            CHECK(norm2 < one2 + (UINT64_C(1) << 36));
        }
    }
    return 0;
}
