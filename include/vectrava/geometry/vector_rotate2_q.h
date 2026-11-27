#ifndef VECTRAVA_GEOMETRY_VECTOR_ROTATE2_Q_H
#define VECTRAVA_GEOMETRY_VECTOR_ROTATE2_Q_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Rotate signed-Q15 2D vector by unsigned Q0.32 turns using CORDIC; components saturate to int16. */
bool vectrava_vector_rotate2_q(const int16_t input_q15[2], uint32_t angle_turns_q0_32, int16_t output_q15[2]);


#ifdef __cplusplus
}
#endif

#endif /* VECTRAVA_GEOMETRY_VECTOR_ROTATE2_Q_H */
