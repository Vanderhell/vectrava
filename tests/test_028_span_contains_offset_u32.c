#include "pc_span_contains_offset_u32.h"
#include "pc_mod_interval_contains_u32.h"
#include "pc_size_add_checked_u32.h"
#include <stdint.h>

static uint32_t state = UINT32_C(0x2287BEEF);

static uint32_t next_u32(void)
{
    state ^= state << 13u;
    state ^= state >> 17u;
    state ^= state << 5u;
    return state;
}

static int check(uint32_t start, uint32_t length, uint32_t offset)
{
    const uint64_t endpoint = (uint64_t)start + length;
    const int valid = endpoint <= UINT32_MAX && start <= offset && offset < endpoint;
    uint32_t end32;
    const int composed = pc_size_add_checked_u32(start, length, &end32) &&
                         offset >= start && offset < end32;
    return pc_span_contains_offset_u32(start, length, offset) == valid &&
           composed == valid ? 0 : 1;
}

int main(void)
{
    static const uint32_t edges[] = {
        0u, 1u, 2u, UINT32_MAX - 2u, UINT32_MAX - 1u, UINT32_MAX
    };
    uint32_t start, length, offset, i, j, k, checks = 0u;
    for (start = 0u; start < 256u; ++start) {
        for (length = 0u; length < 256u; ++length) {
            for (offset = 0u; offset < 256u; ++offset) {
                if (check(start, length, offset) != 0) return 1;
                ++checks;
            }
        }
    }
    for (i = 0u; i < (uint32_t)(sizeof(edges) / sizeof(edges[0])); ++i) {
        for (j = 0u; j < (uint32_t)(sizeof(edges) / sizeof(edges[0])); ++j) {
            for (k = 0u; k < (uint32_t)(sizeof(edges) / sizeof(edges[0])); ++k) {
                if (check(edges[i], edges[j], edges[k]) != 0) return 2;
                ++checks;
            }
        }
    }
    for (i = 0u; i < 1000000u; ++i) {
        start = next_u32();
        length = next_u32();
        offset = next_u32();
        if (check(start, length, offset) != 0) return 3;
        ++checks;
    }
    if (!pc_span_contains_offset_u32(10u, 1u, 10u)) return 4;
    if (pc_span_contains_offset_u32(10u, 1u, 11u)) return 5;
    if (pc_span_contains_offset_u32(10u, 0u, 10u)) return 6;
    if (pc_span_contains_offset_u32(UINT32_MAX - 1u, 2u, UINT32_MAX - 1u)) return 7;
    if (pc_span_contains_offset_u32(5u, 3u, 8u)) return 8;
    if (!pc_mod_interval_contains_u32(5u, 8u, 8u)) return 9;
    return checks == UINT32_C(17777432) ? 0 : 10;
}
