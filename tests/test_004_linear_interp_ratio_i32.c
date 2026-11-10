#include "pc_linear_interp_ratio_i32.h"
#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

static uint32_t rng = 0x861C1A4u;
static uint32_t next_u32(void)
{
    rng ^= rng << 13; rng ^= rng >> 17; rng ^= rng << 5; return rng;
}
static int32_t from_bits(uint32_t bits)
{
    return bits <= (uint32_t)INT32_MAX ? (int32_t)bits
                                      : (int32_t)((int64_t)bits - 4294967296LL);
}
static int32_t oracle(int32_t a, int32_t b, uint32_t n, uint32_t d)
{
    int64_t weighted = (int64_t)a * (int64_t)(d - n) + (int64_t)b * n;
    int64_t q = weighted / d, r = weighted % d;
    uint64_t rem = (uint64_t)(r < 0 ? -r : r);
    if (rem > (uint64_t)d - rem ||
        (rem == (uint64_t)d - rem && q % 2 != 0))
        q += weighted < 0 ? -1 : 1;
    return (int32_t)q;
}

int main(void)
{
    int32_t got;
    uint32_t tested = 0u;
    int32_t a, b;
    uint32_t d, n;
    for (a = -20; a <= 20; ++a) {
        for (b = -20; b <= 20; ++b) {
            for (d = 1u; d <= 20u; ++d) {
                int32_t previous = a;
                for (n = 0u; n <= d; ++n) {
                    int32_t lower = a < b ? a : b;
                    int32_t upper = a > b ? a : b;
                    assert(pc_linear_interp_ratio_i32(a, b, n, d, &got));
                    assert(got == oracle(a, b, n, d));
                    assert(got >= lower && got <= upper);
                    if (n != 0u) assert(b >= a ? got >= previous : got <= previous);
                    previous = got;
                    ++tested;
                }
            }
        }
    }
    for (uint32_t i = 0u; i < 200000u; ++i) {
        int32_t x = from_bits(next_u32()), y = from_bits(next_u32());
        uint32_t den = next_u32() | 1u;
        uint32_t num = next_u32();
        if (num > den) num = den;
        assert(pc_linear_interp_ratio_i32(x, y, num, den, &got));
        assert(got == oracle(x, y, num, den));
        {
            int32_t reverse;
            assert(pc_linear_interp_ratio_i32(y, x, den - num, den, &reverse));
            assert(reverse == got);
        }
        ++tested;
    }
    {
        static const uint32_t wide_numerators[] = {
            0u, 1u, UINT32_C(0x7fffffff), UINT32_C(0x80000000), UINT32_MAX - 1u, UINT32_MAX
        };
        for (uint32_t i = 0u; i < sizeof(wide_numerators) / sizeof(wide_numerators[0]); ++i) {
            uint32_t wide_n = wide_numerators[i];
            assert(pc_linear_interp_ratio_i32(INT32_MIN, INT32_MAX, wide_n, UINT32_MAX, &got));
            assert(got == oracle(INT32_MIN, INT32_MAX, wide_n, UINT32_MAX));
        }
        assert(pc_linear_interp_ratio_i32(INT32_MIN, INT32_MAX, 0u, 1u, &got) && got == INT32_MIN);
        assert(pc_linear_interp_ratio_i32(INT32_MIN, INT32_MAX, 1u, 1u, &got) && got == INT32_MAX);
        assert(pc_linear_interp_ratio_i32(0, 1, 1u, 2u, &got) && got == 0);
        assert(pc_linear_interp_ratio_i32(1, 2, 1u, 2u, &got) && got == 2);
        assert(pc_linear_interp_ratio_i32(-2, -1, 1u, 2u, &got) && got == -2);
        got = 123;
        assert(!pc_linear_interp_ratio_i32(0, 1, 0u, 0u, &got) && got == 123);
        assert(!pc_linear_interp_ratio_i32(0, 1, 2u, 1u, &got) && got == 123);
        assert(!pc_linear_interp_ratio_i32(0, 1, 0u, 1u, NULL));
    }
    printf("ratio interpolation tests passed: exhaustive+seeded=%lu\n", (unsigned long)tested);
    return 0;
}
