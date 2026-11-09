#include "pc_matrix2_adjugate_q.h"
#include "pc_checked_neg_i64.h"
#include <limits.h>
#include <stddef.h>
#include <stdint.h>

#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)

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

static int oracle_adjugate(const pc_matrix2_q *input, pc_matrix2_q *output)
{
    const int64_t raw[4] = {input->element[3], -(int64_t)input->element[1],
                            -(int64_t)input->element[2], input->element[0]};
    pc_matrix2_q tmp;
    unsigned i;
    for (i = 0u; i < 4u; ++i) {
        if (raw[i] < INT32_MIN || raw[i] > INT32_MAX) return 0;
        tmp.element[i] = (int32_t)raw[i];
    }
    *output = tmp;
    return 1;
}

static int equal(const pc_matrix2_q *a, const pc_matrix2_q *b)
{
    unsigned i;
    for (i = 0u; i < 4u; ++i) if (a->element[i] != b->element[i]) return 0;
    return 1;
}

int main(void)
{
    pc_matrix2_q input = {{0, 0, 0, 0}}, expected = {{11, 22, 33, 44}}, actual, twice, composition;
    uint32_t seed = UINT32_C(0x526AD6), iteration;
    const int32_t edges[] = {INT32_MIN, INT32_MIN + 1, -1, 0, 1,
                             INT32_MAX - 1, INT32_MAX};
    unsigned a, b, c, d;

    actual = expected;
    CHECK(!pc_matrix2_adjugate_q(NULL, &actual) && equal(&actual, &expected));
    CHECK(!pc_matrix2_adjugate_q(&input, NULL));
    input = (pc_matrix2_q){{1, INT32_MIN, 2, 3}};
    CHECK(!pc_matrix2_adjugate_q(&input, &actual) && equal(&actual, &expected));
    input = (pc_matrix2_q){{1, 2, INT32_MIN, 3}};
    CHECK(!pc_matrix2_adjugate_q(&input, &actual) && equal(&actual, &expected));

    for (a = 0u; a < 33u; ++a)
        for (b = 0u; b < 33u; ++b)
            for (c = 0u; c < 33u; ++c)
                for (d = 0u; d < 33u; ++d) {
                    input = (pc_matrix2_q){{(int32_t)a - 16, (int32_t)b - 16,
                                            (int32_t)c - 16, (int32_t)d - 16}};
                    CHECK(oracle_adjugate(&input, &expected));
                    CHECK(pc_matrix2_adjugate_q(&input, &actual) && equal(&actual, &expected));
                    CHECK(pc_matrix2_adjugate_q(&actual, &twice) && equal(&twice, &input));
                }
    for (a = 0u; a < 7u; ++a)
        for (b = 0u; b < 7u; ++b)
            for (c = 0u; c < 7u; ++c)
                for (d = 0u; d < 7u; ++d) {
                    const pc_matrix2_q sentinel = {{11, 22, 33, 44}};
                    input = (pc_matrix2_q){{edges[a], edges[b], edges[c], edges[d]}};
                    actual = sentinel;
                    if (oracle_adjugate(&input, &expected)) {
                        CHECK(pc_matrix2_adjugate_q(&input, &actual) && equal(&actual, &expected));
                    } else {
                        CHECK(!pc_matrix2_adjugate_q(&input, &actual) && equal(&actual, &sentinel));
                    }
                }
    for (iteration = 0u; iteration < 250000u; ++iteration) {
        const pc_matrix2_q sentinel = {{11, 22, 33, 44}};
        unsigned k;
        int valid;
        for (k = 0u; k < 4u; ++k) input.element[k] = as_i32(next_u32(&seed));
        actual = sentinel;
        valid = oracle_adjugate(&input, &expected);
        CHECK(pc_matrix2_adjugate_q(&input, &actual) == (valid != 0));
        if (valid) {
            int64_t neg_b, neg_c;
            CHECK(equal(&actual, &expected));
            CHECK(pc_checked_neg_i64(input.element[1], &neg_b));
            CHECK(pc_checked_neg_i64(input.element[2], &neg_c));
            composition = (pc_matrix2_q){{input.element[3], (int32_t)neg_b,
                                          (int32_t)neg_c, input.element[0]}};
            CHECK(equal(&composition, &expected));
            CHECK(pc_matrix2_adjugate_q(&actual, &twice) && equal(&twice, &input));
        } else CHECK(equal(&actual, &sentinel));
        {
            pc_matrix2_q inplace = input;
            CHECK(pc_matrix2_adjugate_q(&inplace, &inplace) == (valid != 0));
            if (valid) CHECK(equal(&inplace, &expected));
            else CHECK(equal(&inplace, &input));
        }
        expected = sentinel;
    }
    return 0;
}
