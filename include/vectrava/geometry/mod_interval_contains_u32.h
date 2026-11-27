#ifndef VECTRAVA_GEOMETRY_MOD_INTERVAL_CONTAINS_U32_H
#define VECTRAVA_GEOMETRY_MOD_INTERVAL_CONTAINS_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Closed forward arc on the uint32_t ring; equal endpoints denote one point. */
bool vectrava_mod_interval_contains_u32(uint32_t start, uint32_t end,
                                  uint32_t point);


#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_MOD_INTERVAL_CONTAINS_U32_H */
