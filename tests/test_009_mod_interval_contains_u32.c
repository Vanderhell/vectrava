#include "pc_mod_interval_contains_u32.h"
#include <stdint.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void)
{
    CHECK(pc_mod_interval_contains_u32(10u, 20u, 10u));
    CHECK(pc_mod_interval_contains_u32(10u, 20u, 15u));
    CHECK(pc_mod_interval_contains_u32(10u, 20u, 20u));
    CHECK(!pc_mod_interval_contains_u32(10u, 20u, 9u));
    CHECK(!pc_mod_interval_contains_u32(10u, 20u, 21u));
    CHECK(pc_mod_interval_contains_u32(UINT32_MAX - 2u, 3u, 0u));
    CHECK(!pc_mod_interval_contains_u32(UINT32_MAX - 2u, 3u, 4u));
    CHECK(pc_mod_interval_contains_u32(7u, 7u, 7u));
    CHECK(!pc_mod_interval_contains_u32(7u, 7u, 8u));
    CHECK(pc_mod_interval_contains_u32(0u, UINT32_MAX, UINT32_C(0x80000000)));
    return 0;
}
