#ifndef PRIMITIVECORE_VECTOR_ROTATE2_Q_H
#define PRIMITIVECORE_VECTOR_ROTATE2_Q_H
#include <stdbool.h>
#include <stdint.h>

/* Rotate signed-Q15 2D vector by unsigned Q0.32 turns using CORDIC; components saturate to int16. */
bool rm_vector_rotate2_q(const int16_t input_q15[2], uint32_t angle_turns_q0_32, int16_t output_q15[2]);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_vector_rotate2_q
#define pc_vector_rotate2_q rm_vector_rotate2_q
#endif
#ifndef pc_vector_rotate2_q
#define pc_vector_rotate2_q rm_vector_rotate2_q
#endif
#ifndef PC_PRIMITIVECORE_VECTOR_ROTATE2_Q_H
#define PC_PRIMITIVECORE_VECTOR_ROTATE2_Q_H PRIMITIVECORE_VECTOR_ROTATE2_Q_H
#endif

