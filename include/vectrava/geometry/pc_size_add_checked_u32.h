#ifndef PC_SIZE_ADD_CHECKED_U32_H
#define PC_SIZE_ADD_CHECKED_U32_H

#include <stdbool.h>
#include <stdint.h>

/* Add two uint32 size/count values. False for null output or overflow;
 * on failure, leave *sum unchanged. */
bool pc_size_add_checked_u32(uint32_t a, uint32_t b, uint32_t *sum);

#endif
