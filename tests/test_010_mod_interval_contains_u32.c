#include "pc_mod_interval_contains_u32.h"
#include <stdint.h>
int main(void)
{
    for (uint32_t start = 0; start < 256u; ++start) {
        uint32_t base = start << 24;
        for (uint32_t length = 0; length < 256u; ++length) {
            uint32_t end = base + (length << 24);
            for (uint32_t offset = 0; offset < 256u; ++offset) {
                uint32_t point = base + (offset << 24);
                if (pc_mod_interval_contains_u32(base, end, point) !=
                    (offset <= length)) return 1;
            }
        }
    }
    return 0;
}
