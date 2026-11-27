#ifndef VECTRAVA_GEOMETRY_VECTOR_DOMINANT_AXIS3_I32_H
#define VECTRAVA_GEOMETRY_VECTOR_DOMINANT_AXIS3_I32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Return the lowest index whose component has greatest absolute magnitude. */
bool vectrava_vector_dominant_axis3_i32(const int32_t vector[3], uint8_t *axis);


#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_VECTOR_DOMINANT_AXIS3_I32_H */
