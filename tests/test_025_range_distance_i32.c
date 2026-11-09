#include "pc_range_distance_i32.h"
#include <limits.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void)
{
    uint32_t d = 77;
    CHECK(pc_range_distance_i32(5, 0, 10, &d) && d == 0);
    CHECK(pc_range_distance_i32(-1, 0, 10, &d) && d == 1);
    CHECK(pc_range_distance_i32(11, 0, 10, &d) && d == 1);
    CHECK(pc_range_distance_i32(INT32_MAX, INT32_MIN, INT32_MIN, &d) && d == UINT32_MAX);
    d = 77;
    CHECK(!pc_range_distance_i32(0, 2, 1, &d) && d == 77);
    CHECK(!pc_range_distance_i32(0, 0, 1, 0));
    return 0;
}
