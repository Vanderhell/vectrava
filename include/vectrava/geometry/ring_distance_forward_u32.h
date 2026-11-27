#ifndef VECTRAVA_GEOMETRY_RING_DISTANCE_FORWARD_U32_H
#define VECTRAVA_GEOMETRY_RING_DISTANCE_FORWARD_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Return forward distance from one valid ring index to another. */
bool vectrava_ring_distance_forward_u32(uint32_t from, uint32_t to,
                                  uint32_t capacity, uint32_t *distance);


#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_RING_DISTANCE_FORWARD_U32_H */
