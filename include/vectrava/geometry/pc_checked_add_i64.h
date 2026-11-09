#ifndef PRIMITIVECORE_CHECKED_ADD_I64_H
#define PRIMITIVECORE_CHECKED_ADD_I64_H
#include <stdbool.h>
#include <stdint.h>
/* Store a+b exactly. False for null output or signed overflow; failure writes
 * nothing to result. */
bool rm_checked_add_i64(int64_t a, int64_t b, int64_t *result);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_checked_add_i64
#define pc_checked_add_i64 rm_checked_add_i64
#endif
#ifndef pc_checked_add_i64
#define pc_checked_add_i64 rm_checked_add_i64
#endif
#ifndef PC_PRIMITIVECORE_CHECKED_ADD_I64_H
#define PC_PRIMITIVECORE_CHECKED_ADD_I64_H PRIMITIVECORE_CHECKED_ADD_I64_H
#endif

