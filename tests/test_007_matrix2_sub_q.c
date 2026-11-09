#include "pc_matrix2_sub_q.h"
#include "pc_matrix2_add_q.h"
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

static int oracle_sub(const pc_matrix2_q *a, const pc_matrix2_q *b,
                      pc_matrix2_q *result)
{
    pc_matrix2_q tmp;
    size_t i;
    for (i = 0u; i < 4u; ++i) {
        const int64_t difference = (int64_t)a->element[i] - b->element[i];
        if (difference < INT32_MIN || difference > INT32_MAX) return 0;
        tmp.element[i] = (int32_t)difference;
    }
    *result = tmp;
    return 1;
}

static int equal(const pc_matrix2_q *a, const pc_matrix2_q *b)
{
    size_t i;
    for (i = 0u; i < 4u; ++i) if (a->element[i] != b->element[i]) return 0;
    return 1;
}

int main(void)
{
    pc_matrix2_q a = {{0, 0, 0, 0}}, b = {{0, 0, 0, 0}};
    pc_matrix2_q expected = {{11, 22, 33, 44}}, actual, reverse, restored, reverse_expected;
    uint32_t seed = UINT32_C(0x5225AB);
    size_t slot, i;

    actual = expected;
    CHECK(!pc_matrix2_sub_q(NULL, &b, &actual) && equal(&actual, &expected));
    CHECK(!pc_matrix2_sub_q(&a, NULL, &actual) && equal(&actual, &expected));
    CHECK(!pc_matrix2_sub_q(&a, &b, NULL));

    for (slot = 0u; slot < 4u; ++slot) {
        int32_t x, y;
        for (x = -256; x <= 256; ++x) {
            for (y = -256; y <= 256; ++y) {
                a.element[slot] = x; b.element[slot] = y;
                CHECK(pc_matrix2_sub_q(&a, &b, &actual));
                CHECK(actual.element[slot] == x - y);
                CHECK(actual.element[(slot + 1u) % 4u] == 0);
            }
        }
        a.element[slot] = 0; b.element[slot] = 0;
    }

    {
        const int32_t values[] = {INT32_MIN, INT32_MIN + 1, -1, 0, 1, INT32_MAX - 1, INT32_MAX};
        size_t ai, bi;
        for (ai = 0u; ai < sizeof(values) / sizeof(values[0]); ++ai) {
            for (bi = 0u; bi < sizeof(values) / sizeof(values[0]); ++bi) {
                size_t k;
                for (k = 0u; k < 4u; ++k) { a.element[k] = values[ai]; b.element[k] = values[bi]; }
                actual = expected;
                if (oracle_sub(&a, &b, &expected)) {
                    CHECK(pc_matrix2_sub_q(&a, &b, &actual) && equal(&actual, &expected));
                } else {
                    const pc_matrix2_q sentinel = {{11, 22, 33, 44}};
                    CHECK(!pc_matrix2_sub_q(&a, &b, &actual) && equal(&actual, &sentinel));
                }
                expected.element[0] = 11; expected.element[1] = 22;
                expected.element[2] = 33; expected.element[3] = 44;
            }
        }
    }

    for (i = 0u; i < 500000u; ++i) {
        size_t k;
        int valid;
        for (k = 0u; k < 4u; ++k) {
            a.element[k] = as_i32(next_u32(&seed));
            b.element[k] = as_i32(next_u32(&seed));
        }
        actual = expected;
        valid = oracle_sub(&a, &b, &expected);
        CHECK(pc_matrix2_sub_q(&a, &b, &actual) == (valid != 0));
        if (valid) {
            CHECK(equal(&actual, &expected));
            if (oracle_sub(&b, &a, &reverse_expected))
                CHECK(pc_matrix2_sub_q(&b, &a, &reverse) && equal(&reverse, &reverse_expected));
            {
                pc_matrix2_q zero = {{0, 0, 0, 0}};
                CHECK(pc_matrix2_sub_q(&a, &zero, &reverse) && equal(&reverse, &a));
            }
            CHECK(pc_matrix2_add_q(&actual, &b, &restored) && equal(&restored, &a));
        } else {
            const pc_matrix2_q sentinel = {{11, 22, 33, 44}};
            CHECK(equal(&actual, &sentinel));
        }
        expected.element[0] = 11; expected.element[1] = 22;
        expected.element[2] = 33; expected.element[3] = 44;
    }

    a = (pc_matrix2_q){{INT32_MIN, -7, 0, INT32_MAX}};
    b = (pc_matrix2_q){{-1, 8, INT32_MAX, 1}};
    expected = (pc_matrix2_q){{INT32_MIN + 1, -15, -INT32_MAX, INT32_MAX - 1}};
    CHECK(pc_matrix2_sub_q(&a, &b, &a) && equal(&a, &expected));
    a = (pc_matrix2_q){{INT32_MIN, -7, 0, INT32_MAX}};
    b = (pc_matrix2_q){{-1, 8, INT32_MAX, 1}};
    CHECK(pc_matrix2_sub_q(&a, &b, &b) && equal(&b, &expected));
    return 0;
}
