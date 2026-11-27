#ifndef VECTRAVA_GEOMETRY_OFFSET_RANGE_CHECK_U32_H
#define VECTRAVA_GEOMETRY_OFFSET_RANGE_CHECK_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Check the half-open span [offset, offset + length) against capacity.
 * An empty span at offset == capacity is valid. */
bool vectrava_offset_range_check_u32(uint32_t offset, uint32_t length,
                               uint32_t capacity);

#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_OFFSET_RANGE_CHECK_U32_H */
