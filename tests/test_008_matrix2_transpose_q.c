#include "pc_matrix2_transpose_q.h"
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

#define CHECK(c) do { if (!(c)) { fprintf(stderr, "check failed at %d\n", __LINE__); return 1; } } while (0)

static uint32_t next_u32(uint32_t *state)
{
    *state = *state * UINT32_C(1664525) + UINT32_C(1013904223);
    return *state;
}

static int32_t as_i32(uint32_t value)
{
    return value <= (uint32_t)INT32_MAX
               ? (int32_t)value
               : (int32_t)((int64_t)value - INT64_C(4294967296));
}

static void oracle_transpose(const pc_matrix2_q *input, pc_matrix2_q *output)
{
    size_t row, column;
    for (row = 0u; row < 2u; ++row)
        for (column = 0u; column < 2u; ++column)
            output->element[row * 2u + column] = input->element[column * 2u + row];
}

static int equal(const pc_matrix2_q *a, const pc_matrix2_q *b)
{
    size_t i;
    for (i = 0u; i < 4u; ++i) if (a->element[i] != b->element[i]) return 0;
    return 1;
}

int main(void)
{
    pc_matrix2_q input = {{11, 22, 33, 44}}, expected, actual, twice;
    uint32_t seed = UINT32_C(0x5237A);
    size_t slot, i;
    CHECK(!pc_matrix2_transpose_q(NULL, &actual));
    CHECK(!pc_matrix2_transpose_q(&input, NULL));

    for (slot = 0u; slot < 4u; ++slot) {
        int32_t value;
        for (value = -4096; value <= 4096; ++value) {
            input = (pc_matrix2_q){{11, 22, 33, 44}};
            input.element[slot] = value;
            oracle_transpose(&input, &expected);
            CHECK(pc_matrix2_transpose_q(&input, &actual) && equal(&actual, &expected));
            CHECK(pc_matrix2_transpose_q(&actual, &twice) && equal(&twice, &input));
        }
    }
    {
        const int32_t edges[] = {INT32_MIN, INT32_MIN + 1, -1, 0, 1, INT32_MAX - 1, INT32_MAX};
        size_t a, b, c, d;
        for (a = 0u; a < 7u; ++a)
            for (b = 0u; b < 7u; ++b)
                for (c = 0u; c < 7u; ++c)
                    for (d = 0u; d < 7u; ++d) {
                        input = (pc_matrix2_q){{edges[a], edges[b], edges[c], edges[d]}};
                        oracle_transpose(&input, &expected);
                        CHECK(pc_matrix2_transpose_q(&input, &actual) && equal(&actual, &expected));
                    }
    }
    for (i = 0u; i < 1000000u; ++i) {
        size_t k;
        for (k = 0u; k < 4u; ++k) input.element[k] = as_i32(next_u32(&seed));
        oracle_transpose(&input, &expected);
        CHECK(pc_matrix2_transpose_q(&input, &actual) && equal(&actual, &expected));
        CHECK(pc_matrix2_transpose_q(&actual, &twice) && equal(&twice, &input));
        {
            pc_matrix2_q inplace = input;
            CHECK(pc_matrix2_transpose_q(&inplace, &inplace) && equal(&inplace, &expected));
        }
    }
    input = (pc_matrix2_q){{INT32_MIN, 22, 33, INT32_MAX}};
    expected = (pc_matrix2_q){{INT32_MIN, 33, 22, INT32_MAX}};
    CHECK(pc_matrix2_transpose_q(&input, &input) && equal(&input, &expected));
    return 0;
}
