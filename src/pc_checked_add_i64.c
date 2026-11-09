#include "pc_checked_add_i64.h"
#include <limits.h>
#include <stddef.h>

bool pc_checked_add_i64(int64_t a, int64_t b, int64_t *result)
{
    if (result == NULL) return false;
    if ((b > 0 && a > INT64_MAX - b) ||
        (b < 0 && a < INT64_MIN - b)) return false;
    *result = a + b;
    return true;
}
