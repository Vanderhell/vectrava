#include "pc_linear_interp_ratio_u32.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>

static uint32_t rng = 0x862C1A4u;
static uint32_t next_u32(void)
{
    rng ^= rng << 13; rng ^= rng >> 17; rng ^= rng << 5; return rng;
}
static uint32_t oracle(uint32_t a, uint32_t b, uint32_t n, uint32_t d)
{
    uint64_t weighted = (uint64_t)a * (d - n) + (uint64_t)b * n;
    uint64_t q = weighted / d, r = weighted % d;
    if (r > (uint64_t)d - r ||
        (r == (uint64_t)d - r && (q & 1u) != 0u)) ++q;
    return (uint32_t)q;
}

int main(void)
{
    uint32_t got, tested = 0u;
    uint32_t a, b, d, n;
    for (a = 0u; a <= 40u; ++a) {
        for (b = 0u; b <= 40u; ++b) {
            for (d = 1u; d <= 20u; ++d) {
                uint32_t previous = a;
                for (n = 0u; n <= d; ++n) {
                    assert(pc_linear_interp_ratio_u32(a, b, n, d, &got));
                    assert(got == oracle(a, b, n, d));
                    assert(got >= (a < b ? a : b) && got <= (a > b ? a : b));
                    if (n != 0u) assert(b >= a ? got >= previous : got <= previous);
                    previous = got;
                    ++tested;
                }
            }
        }
    }
    for (uint32_t i = 0u; i < 200000u; ++i) {
        uint32_t x = next_u32(), y = next_u32(), den = next_u32() | 1u;
        uint32_t num = next_u32();
        if (num > den) num = den;
        assert(pc_linear_interp_ratio_u32(x, y, num, den, &got));
        assert(got == oracle(x, y, num, den));
        assert(got >= (x < y ? x : y) && got <= (x > y ? x : y));
        {
            uint32_t reverse;
            assert(pc_linear_interp_ratio_u32(y, x, den - num, den, &reverse));
            assert(reverse == got);
        }
        ++tested;
    }
    {
        static const uint32_t wide_numerators[] = {
            0u, 1u, UINT32_C(0x7fffffff), UINT32_C(0x80000000), UINT32_MAX - 1u, UINT32_MAX
        };
        for (uint32_t i = 0u; i < sizeof(wide_numerators) / sizeof(wide_numerators[0]); ++i) {
            uint32_t nwide = wide_numerators[i];
            assert(pc_linear_interp_ratio_u32(0u, UINT32_MAX, nwide, UINT32_MAX, &got));
            assert(got == oracle(0u, UINT32_MAX, nwide, UINT32_MAX));
        }
        assert(pc_linear_interp_ratio_u32(0u, 1u, 1u, 2u, &got) && got == 0u);
        assert(pc_linear_interp_ratio_u32(1u, 2u, 1u, 2u, &got) && got == 2u);
        assert(pc_linear_interp_ratio_u32(0u, UINT32_MAX, 1u, 2u, &got) &&
               got == UINT32_MAX / 2u + 1u);
        got = 123u;
        assert(!pc_linear_interp_ratio_u32(0u, 1u, 0u, 0u, &got) && got == 123u);
        assert(!pc_linear_interp_ratio_u32(0u, 1u, 2u, 1u, &got) && got == 123u);
        assert(!pc_linear_interp_ratio_u32(0u, 1u, 0u, 1u, NULL));
    }
    printf("unsigned ratio interpolation tests passed: exhaustive+seeded=%lu\n", (unsigned long)tested);
    return 0;
}
