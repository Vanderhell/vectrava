#ifndef PC_CHECKED_NEG_I64_H
#define PC_CHECKED_NEG_I64_H
#include <stdbool.h>
#include <stdint.h>
/* Store -value exactly; false for null output or INT64_MIN, preserving output. */
bool pc_checked_neg_i64(int64_t value, int64_t *result);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_checked_neg_i64
#define pc_checked_neg_i64 pc_checked_neg_i64
#endif
#ifndef pc_checked_neg_i64
#define pc_checked_neg_i64 pc_checked_neg_i64
#endif
#ifndef PC_PC_CHECKED_NEG_I64_H
#define PC_PC_CHECKED_NEG_I64_H PC_CHECKED_NEG_I64_H
#endif

