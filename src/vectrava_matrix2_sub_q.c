#include <vectrava/geometry/matrix2_sub_q.h>
#include <stddef.h>

bool vectrava_matrix2_sub_q(const vectrava_matrix2_q *a, const vectrava_matrix2_q *b,
                      vectrava_matrix2_q *result)
{
    vectrava_matrix2_q temporary;
    size_t i;
    if (a == NULL || b == NULL || result == NULL) return false;
    for (i = 0u; i < 4u; ++i) {
        const int64_t difference = (int64_t)a->element[i] - (int64_t)b->element[i];
        if (difference < INT32_MIN || difference > INT32_MAX) return false;
        temporary.element[i] = (int32_t)difference;
    }
    *result = temporary;
    return true;
}
