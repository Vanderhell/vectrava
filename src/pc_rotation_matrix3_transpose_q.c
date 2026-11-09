#include "pc_rotation_matrix3_transpose_q.h"

#include <stddef.h>

bool pc_rotation_matrix3_transpose_q(const pc_matrix3_q *input,
                                     pc_matrix3_q *output)
{
    pc_matrix3_q result;

    if (input == NULL || output == NULL) return false;

    for (unsigned row = 0; row < 3; ++row) {
        for (unsigned column = 0; column < 3; ++column) {
            result.element[3u * row + column] = input->element[3u * column + row];
        }
    }
    *output = result;
    return true;
}