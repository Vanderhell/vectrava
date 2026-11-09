#ifndef PRIMITIVECORE_PC_HASH_PROBE_LINEAR_U32_H
#define PRIMITIVECORE_PC_HASH_PROBE_LINEAR_U32_H
#include <stdbool.h>
#include <stdint.h>

/* Return (start + ordinal) modulo capacity without uint32 overflow.
 * Requires capacity > 0 and start < capacity; failure preserves *index. */
bool pc_hash_probe_linear_u32(uint32_t start, uint32_t ordinal,
                              uint32_t capacity, uint32_t *index);

#endif
