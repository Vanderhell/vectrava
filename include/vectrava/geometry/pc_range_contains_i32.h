#ifndef PRIMITIVECORE_RANGE_CONTAINS_I32_H
#define PRIMITIVECORE_RANGE_CONTAINS_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Closed interval predicate. An inverted interval returns false. */
bool rm_range_contains_i32(int32_t value, int32_t lower, int32_t upper);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_range_contains_i32
#define pc_range_contains_i32 rm_range_contains_i32
#endif
#ifndef pc_range_contains_i32
#define pc_range_contains_i32 rm_range_contains_i32
#endif
#ifndef PC_PRIMITIVECORE_RANGE_CONTAINS_I32_H
#define PC_PRIMITIVECORE_RANGE_CONTAINS_I32_H PRIMITIVECORE_RANGE_CONTAINS_I32_H
#endif

