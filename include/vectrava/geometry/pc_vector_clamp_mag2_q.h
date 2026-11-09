#ifndef PRIMITIVECORE_VECTOR_CLAMP_MAG2_Q_H
#define PRIMITIVECORE_VECTOR_CLAMP_MAG2_Q_H
#include <stdbool.h>
#include <stdint.h>

/* Limit signed-Q15 int16 vector magnitude to a nonnegative raw-Q15 radius. */
bool rm_vector_clamp_mag2_q(const int16_t input_q15[2], int16_t max_magnitude_q15, int16_t output_q15[2]);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_vector_clamp_mag2_q
#define pc_vector_clamp_mag2_q rm_vector_clamp_mag2_q
#endif
#ifndef pc_vector_clamp_mag2_q
#define pc_vector_clamp_mag2_q rm_vector_clamp_mag2_q
#endif
#ifndef PC_PRIMITIVECORE_VECTOR_CLAMP_MAG2_Q_H
#define PC_PRIMITIVECORE_VECTOR_CLAMP_MAG2_Q_H PRIMITIVECORE_VECTOR_CLAMP_MAG2_Q_H
#endif

