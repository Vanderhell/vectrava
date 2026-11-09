#include "pc_range_contains_i32.h"
#include <limits.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void)
{
    CHECK(pc_range_contains_i32(5, 5, 5));
    CHECK(pc_range_contains_i32(INT32_MIN, INT32_MIN, INT32_MAX));
    CHECK(pc_range_contains_i32(INT32_MAX, INT32_MIN, INT32_MAX));
    CHECK(!pc_range_contains_i32(4, 5, 9));
    CHECK(!pc_range_contains_i32(10, 5, 9));
    CHECK(!pc_range_contains_i32(5, 9, 5));
    CHECK(!pc_range_contains_i32(INT32_MIN, INT32_MIN + 1, INT32_MAX));
    return 0;
}
