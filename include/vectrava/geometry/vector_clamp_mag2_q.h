#ifndef VECTRAVA_GEOMETRY_VECTOR_CLAMP_MAG2_Q_H
#define VECTRAVA_GEOMETRY_VECTOR_CLAMP_MAG2_Q_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Limit signed-Q15 int16 vector magnitude to a nonnegative raw-Q15 radius. */
bool vectrava_vector_clamp_mag2_q(const int16_t input_q15[2], int16_t max_magnitude_q15, int16_t output_q15[2]);


#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_VECTOR_CLAMP_MAG2_Q_H */
