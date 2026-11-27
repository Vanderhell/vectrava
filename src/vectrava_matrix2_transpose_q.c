#include <vectrava/geometry/matrix2_transpose_q.h>
#include <stddef.h>

bool vectrava_matrix2_transpose_q(const vectrava_matrix2_q *input, vectrava_matrix2_q *result)
{
    vectrava_matrix2_q temporary;
    if (input == NULL || result == NULL) return false;
    temporary.element[0] = input->element[0];
    temporary.element[1] = input->element[2];
    temporary.element[2] = input->element[1];
    temporary.element[3] = input->element[3];
    *result = temporary;
    return true;
}
