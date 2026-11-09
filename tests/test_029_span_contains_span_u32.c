#include "pc_span_contains_span_u32.h"
#include "pc_offset_range_check_u32.h"
#include <stdint.h>

static uint32_t state = UINT32_C(0x2288FACE);

static uint32_t next_u32(void)
{
    state ^= state << 13u;
    state ^= state >> 17u;
    state ^= state << 5u;
    return state;
}

static int check(uint32_t outer_start, uint32_t outer_length,
                 uint32_t inner_start, uint32_t inner_length)
{
    const uint64_t outer_end = (uint64_t)outer_start + outer_length;
    const uint64_t inner_end = (uint64_t)inner_start + inner_length;
    const int expected = outer_end <= UINT32_MAX && inner_end <= UINT32_MAX &&
                         outer_start <= inner_start && inner_end <= outer_end;
    int composed = 0;
    if (outer_end <= UINT32_MAX && inner_start >= outer_start) {
        composed = pc_offset_range_check_u32(inner_start - outer_start,
                                             inner_length, outer_length);
    }
    return pc_span_contains_span_u32(outer_start, outer_length,
                                     inner_start, inner_length) == expected &&
           composed == expected ? 0 : 1;
}

int main(void)
{
    static const uint32_t edges[] = {
        0u, 1u, 2u, UINT32_MAX - 2u, UINT32_MAX - 1u, UINT32_MAX
    };
    uint32_t i, j, k, m, a, b, c, d, checks = 0u;
    for (a = 0u; a < 16u; ++a)
        for (b = 0u; b < 16u; ++b)
            for (c = 0u; c < 16u; ++c)
                for (d = 0u; d < 16u; ++d) {
                    if (check(a, b, c, d) != 0) return 1;
                    ++checks;
                }
    for (i = 0u; i < (uint32_t)(sizeof(edges) / sizeof(edges[0])); ++i)
        for (j = 0u; j < (uint32_t)(sizeof(edges) / sizeof(edges[0])); ++j)
            for (k = 0u; k < (uint32_t)(sizeof(edges) / sizeof(edges[0])); ++k)
                for (m = 0u; m < (uint32_t)(sizeof(edges) / sizeof(edges[0])); ++m) {
                    if (check(edges[i], edges[j], edges[k], edges[m]) != 0) return 2;
                    ++checks;
                }
    for (i = 0u; i < 1000000u; ++i) {
        a = next_u32(); b = next_u32(); c = next_u32(); d = next_u32();
        if (check(a, b, c, d) != 0) return 3;
        ++checks;
    }
    if (!pc_span_contains_span_u32(10u, 4u, 10u, 0u)) return 4;
    if (!pc_span_contains_span_u32(10u, 4u, 14u, 0u)) return 5;
    if (pc_span_contains_span_u32(10u, 4u, 14u, 1u)) return 6;
    if (pc_span_contains_span_u32(UINT32_MAX - 1u, 2u, UINT32_MAX - 1u, 1u)) return 7;
    return checks == UINT32_C(1066832) ? 0 : 8;
}
