#ifndef PRIMITIVECORE_RING_DISTANCE_FORWARD_U32_H
#define PRIMITIVECORE_RING_DISTANCE_FORWARD_U32_H
#include <stdbool.h>
#include <stdint.h>

/* Return forward distance from one valid ring index to another. */
bool rm_ring_distance_forward_u32(uint32_t from, uint32_t to,
                                  uint32_t capacity, uint32_t *distance);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_ring_distance_forward_u32
#define pc_ring_distance_forward_u32 rm_ring_distance_forward_u32
#endif
#ifndef pc_ring_distance_forward_u32
#define pc_ring_distance_forward_u32 rm_ring_distance_forward_u32
#endif
#ifndef PC_PRIMITIVECORE_RING_DISTANCE_FORWARD_U32_H
#define PC_PRIMITIVECORE_RING_DISTANCE_FORWARD_U32_H PRIMITIVECORE_RING_DISTANCE_FORWARD_U32_H
#endif

