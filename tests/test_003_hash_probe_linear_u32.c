#include "pc_hash_probe_linear_u32.h"
#include <stdint.h>
#include <stdio.h>

#define CHECK(x) do { if (!(x)) { fprintf(stderr,"failed line %d\n",__LINE__); return 1; } } while (0)

static uint32_t reference(uint32_t start, uint32_t ordinal, uint32_t capacity)
{
    return (uint32_t)(((uint64_t)start + (uint64_t)ordinal) % (uint64_t)capacity);
}

int main(void)
{
    uint32_t result = UINT32_C(0xA5A5A5A5);
    CHECK(!pc_hash_probe_linear_u32(0u, 0u, 0u, &result));
    CHECK(result == UINT32_C(0xA5A5A5A5));
    CHECK(!pc_hash_probe_linear_u32(4u, 0u, 4u, &result));
    CHECK(result == UINT32_C(0xA5A5A5A5));
    CHECK(!pc_hash_probe_linear_u32(0u, 0u, 1u, NULL));
    CHECK(pc_hash_probe_linear_u32(9u, UINT32_MAX, 10u, &result));
    CHECK(result == 4u);
    for (uint32_t capacity = 1u; capacity <= 64u; ++capacity) {
        for (uint32_t start = 0u; start < capacity; ++start) {
            for (uint32_t ordinal = 0u; ordinal < 4u * capacity + 1u; ++ordinal) {
                CHECK(pc_hash_probe_linear_u32(start, ordinal, capacity, &result));
                CHECK(result == reference(start, ordinal, capacity));
            }
        }
    }
    CHECK(pc_hash_probe_linear_u32(UINT32_MAX - 1u, UINT32_MAX,
                                    UINT32_MAX, &result));
    CHECK(result == reference(UINT32_MAX - 1u, UINT32_MAX, UINT32_MAX));
    return 0;
}
