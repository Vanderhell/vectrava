#include "pc_quat_identity_q.h"

#include <stdint.h>
#include <stddef.h>

#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)

int main(void)
{
    int32_t q[4] = { -1, 12, 23, 34 };
    CHECK(!pc_quat_identity_q(NULL));
    CHECK(q[0] == -1 && q[1] == 12 && q[2] == 23 && q[3] == 34);
    CHECK(pc_quat_identity_q(q));
    CHECK(q[0] == INT32_C(1073741824));
    CHECK(q[1] == 0 && q[2] == 0 && q[3] == 0);
    return 0;
}
