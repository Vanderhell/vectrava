#include "pc_size_add_checked_u32.h"
#include <stddef.h>

bool pc_size_add_checked_u32(uint32_t a, uint32_t b, uint32_t *sum)
{
    if (sum == NULL || b > UINT32_MAX - a) {
        return false;
    }
    *sum = a + b;
    return true;
}
