#ifndef PRIMITIVECORE_CHECKED_NEG_I64_H
#define PRIMITIVECORE_CHECKED_NEG_I64_H
#include <stdbool.h>
#include <stdint.h>
/* Store -value exactly; false for null output or INT64_MIN, preserving output. */
bool rm_checked_neg_i64(int64_t value, int64_t *result);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_checked_neg_i64
#define pc_checked_neg_i64 rm_checked_neg_i64
#endif
#ifndef pc_checked_neg_i64
#define pc_checked_neg_i64 rm_checked_neg_i64
#endif
#ifndef PC_PRIMITIVECORE_CHECKED_NEG_I64_H
#define PC_PRIMITIVECORE_CHECKED_NEG_I64_H PRIMITIVECORE_CHECKED_NEG_I64_H
#endif

