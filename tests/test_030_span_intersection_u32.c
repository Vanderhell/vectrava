#include "pc_span_intersection_u32.h"
#include "pc_offset_range_check_u32.h"
#include <stddef.h>
#include <stdint.h>

static uint32_t state = UINT32_C(0x2290C0DE);

static uint32_t next_u32(void)
{
    state ^= state << 13u;
    state ^= state >> 17u;
    state ^= state << 5u;
    return state;
}

static int check(uint32_t as, uint32_t al, uint32_t bs, uint32_t bl)
{
    const uint64_t ae = (uint64_t)as + al;
    const uint64_t be = (uint64_t)bs + bl;
    const uint32_t start = as > bs ? as : bs;
    const uint64_t end = ae < be ? ae : be;
    const int valid = ae <= UINT32_MAX && be <= UINT32_MAX &&
                      al != 0u && bl != 0u && start < end;
    uint32_t out_start = UINT32_C(0x13579BDF);
    uint32_t out_length = UINT32_C(0x2468ACE0);
    const int actual = pc_span_intersection_u32(as, al, bs, bl,
                                                &out_start, &out_length);
    int composed = 0;
    if (pc_offset_range_check_u32(as, al, UINT32_MAX) &&
        pc_offset_range_check_u32(bs, bl, UINT32_MAX) && al != 0u && bl != 0u) {
        const uint32_t local_start = as > bs ? as : bs;
        const uint32_t local_end = (uint32_t)(ae < be ? ae : be);
        composed = local_start < local_end;
        if (composed && (out_start != local_start || out_length != local_end - local_start))
            return 1;
    }
    if (actual != valid || composed != valid) return 2;
    if (valid) return out_start == start && out_length == end - start ? 0 : 3;
    return out_start == UINT32_C(0x13579BDF) &&
           out_length == UINT32_C(0x2468ACE0) ? 0 : 4;
}

int main(void)
{
    static const uint32_t edges[] = {
        0u, 1u, 2u, UINT32_MAX - 2u, UINT32_MAX - 1u, UINT32_MAX
    };
    uint32_t i, j, k, m, a, b, c, d, checks = 0u;
    for (a = 0u; a < 10u; ++a)
        for (b = 0u; b < 10u; ++b)
            for (c = 0u; c < 10u; ++c)
                for (d = 0u; d < 10u; ++d) {
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
    {
        uint32_t out_start = 1u, out_length = 2u;
        if (pc_span_intersection_u32(0u, 2u, 1u, 2u, NULL, &out_length)) return 4;
        if (out_length != 2u) return 5;
        if (pc_span_intersection_u32(0u, 2u, 1u, 2u, &out_start, &out_start)) return 6;
        if (out_start != 1u) return 7;
    }
    return checks == UINT32_C(1011296) ? 0 : 8;
}
