#include "pc_checked_neg_i64.h"
#include <limits.h>
#include <stddef.h>

bool rm_checked_neg_i64(int64_t value, int64_t *result)
{
    if (result == NULL || value == INT64_MIN) return false;
    *result = -value;
    return true;
}
