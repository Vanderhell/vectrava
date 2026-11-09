#ifndef PC_CHECKED_ADD_I64_H
#define PC_CHECKED_ADD_I64_H
#include <stdbool.h>
#include <stdint.h>
/* Store a+b exactly. False for null output or signed overflow; failure writes
 * nothing to result. */
bool pc_checked_add_i64(int64_t a, int64_t b, int64_t *result);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_checked_add_i64
#define pc_checked_add_i64 pc_checked_add_i64
#endif
#ifndef pc_checked_add_i64
#define pc_checked_add_i64 pc_checked_add_i64
#endif
#ifndef PC_PC_CHECKED_ADD_I64_H
#define PC_PC_CHECKED_ADD_I64_H PC_CHECKED_ADD_I64_H
#endif

