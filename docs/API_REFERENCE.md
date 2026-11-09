# Vectrava API reference

This reference explains every public header in the Vectrava product. It is generated from the current headers and test sources; the header remains authoritative when a detail conflicts.

## Reading the entries
Each entry states the public symbol, implementation unit, contract, edge/failure behavior and a call extracted from the validating test source. The examples are evidence-oriented; adapt buffer ownership and numeric units to the application.

## include/vectrava/geometry/pc_affine2_apply_q.h

**Public symbol:** pc_affine2_apply_q

**Implementation unit:** src/pc_affine2_apply_q.c

**Purpose and contract:** Apply a row-major 2x2 Q matrix and Q translation. Each dot product is rounded nearest-even once. False on invalid pointers/fractional_bits or result overflow; failure preserves output. Output may alias point/translation.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_bbox_of_points2_i32.h

**Public symbol:** pc_bbox_of_points2_i32

**Implementation unit:** src/pc_bbox_of_points2_i32.c

**Purpose and contract:** Compute the closed AABB of count points. Reject null pointers or count==0; on failure, preserve *bounds. The input array is read-only.

**Validation source:** tests/test_001_bbox_of_points2_i32.c

**Test-derived call:**
```c
pc_bbox_of_points2_i32(NULL,1,&b)&&b.min_x==11);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_bearing2_q.h

**Public symbol:** pc_bearing2_q

**Implementation unit:** src/pc_bearing2_q.c

**Purpose and contract:** CORDIC estimate of bearing from an int32 origin to target as unsigned Q0.32 turns CCW from +X. Equal points return zero. Coordinates need not share a specific Q scale. Differential tests observed <= 16 phase-code error; this empirical limit is not a formal global bound.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_calibrate_piecewise_i32.h

**Public symbol:** pc_calibrate_piecewise_i32

**Implementation unit:** src/pc_calibrate_piecewise_i32.c

**Purpose and contract:** Piecewise-linear map, clamp beyond endpoints, nearest/ties-away rounding. Count is 2..255; input knots must be strictly increasing.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_circle_aabb_overlap_i32.h

**Public symbol:** pc_circle_aabb_overlap_i32

**Implementation unit:** src/pc_circle_aabb_overlap_i32.c

**Purpose and contract:** Closed circle/AABB overlap; inverted box bounds return false.

**Validation source:** tests/test_002_circle_aabb_overlap_i32.c

**Test-derived call:**
```c
pc_circle_aabb_overlap_i32(cx,cy,r,x0,y0,x1,y1)==oracle(cx,cy,r,x0,y0,x1,y1\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_distance_to_stop_q.h

**Public symbol:** pc_distance_to_stop_q

**Implementation unit:** src/pc_distance_to_stop_q.c

**Purpose and contract:** Constant-deceleration stopping distance: ceil(|v|^2/(2*a)). Velocity is signed Q16.16 units/s, positive braking deceleration is Q16.16 units/s^2, result is unsigned Q16.16 distance. Zero speed returns 0; nonzero speed with zero deceleration fails atomically.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_hash_probe_linear_u32.h

**Public symbol:** pc_hash_probe_linear_u32

**Implementation unit:** src/pc_hash_probe_linear_u32.c

**Purpose and contract:** Return (start + ordinal) modulo capacity without uint32 overflow. Requires capacity > 0 and start < capacity; failure preserves *index.

**Validation source:** tests/test_003_hash_probe_linear_u32.c

**Test-derived call:**
```c
pc_hash_probe_linear_u32(0u, 0u, 0u, &result\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_homogeneous2_apply_q.h

**Public symbol:** pc_homogeneous2_apply_q

**Implementation unit:** src/pc_homogeneous2_apply_q.c

**Purpose and contract:** Apply a row-major 3x3 Q matrix to a homogeneous 3-vector. Each row dot product is rounded nearest-even once. Returns homogeneous output; it does not divide by W. False preserves output. Output may alias matrix/vector.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_checked_add_i64.h

**Public symbol:** pc_checked_add_i64

**Implementation unit:** src/pc_checked_add_i64.c

**Purpose and contract:** Store a+b exactly. False for null output or signed overflow; failure writes nothing to result.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_checked_neg_i64.h

**Public symbol:** pc_checked_neg_i64

**Implementation unit:** src/pc_checked_neg_i64.c

**Purpose and contract:** Store -value exactly; false for null output or INT64_MIN, preserving output.

**Validation source:** tests/test_006_matrix2_adjugate_q.c

**Test-derived call:**
```c
pc_checked_neg_i64(input.element[1], &neg_b\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_linear_interp_ratio_i32.h

**Public symbol:** pc_linear_interp_ratio_i32

**Implementation unit:** src/pc_linear_interp_ratio_i32.c

**Purpose and contract:** Convex interpolation at numerator/denominator in [0,1]. The exact result rounds to nearest, ties-to-even. Invalid ratio/output preserves *result.

**Validation source:** tests/test_004_linear_interp_ratio_i32.c

**Test-derived call:**
```c
pc_linear_interp_ratio_i32(a, b, n, d, &got\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_linear_interp_ratio_u32.h

**Public symbol:** pc_linear_interp_ratio_u32

**Implementation unit:** src/pc_linear_interp_ratio_u32.c

**Purpose and contract:** Convex interpolation for a ratio in [0,1]. Rounds nearest, ties-to-even; invalid ratios or output pointer preserve *result.

**Validation source:** tests/test_005_linear_interp_ratio_u32.c

**Test-derived call:**
```c
pc_linear_interp_ratio_u32(a, b, n, d, &got\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_matrix2_add_q.h

**Public symbol:** pc_matrix2_add_q

**Implementation unit:** src/pc_matrix2_add_q.c

**Purpose and contract:** Exact elementwise addition. On any component overflow, write nothing.

**Validation source:** tests/test_007_matrix2_sub_q.c

**Test-derived call:**
```c
pc_matrix2_add_q(&actual, &b, &restored) && equal(&restored, &a\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_matrix2_adjugate_q.h

**Public symbol:** pc_matrix2_adjugate_q

**Implementation unit:** src/pc_matrix2_adjugate_q.c

**Purpose and contract:** Adjugate [[a,b],[c,d]] to [[d,-b],[-c,a]], checked and alias-safe.

**Validation source:** tests/test_006_matrix2_adjugate_q.c

**Test-derived call:**
```c
pc_matrix2_adjugate_q(NULL, &actual) && equal(&actual, &expected\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_matrix2_q.h

**Public symbol:** pc_matrix2_q

**Implementation unit:** src/pc_matrix2_q.c

**Purpose and contract:** Row-major 2x2 signed Q matrix; all elements share one caller-selected scale.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_matrix2_sub_q.h

**Public symbol:** pc_matrix2_sub_q

**Implementation unit:** src/pc_matrix2_sub_q.c

**Purpose and contract:** Exact elementwise subtraction. On any component overflow, write nothing.

**Validation source:** tests/test_007_matrix2_sub_q.c

**Test-derived call:**
```c
pc_matrix2_sub_q(NULL, &b, &actual) && equal(&actual, &expected\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_matrix2_transpose_q.h

**Public symbol:** pc_matrix2_transpose_q

**Implementation unit:** src/pc_matrix2_transpose_q.c

**Purpose and contract:** Transpose a row-major 2x2 Q matrix; result may alias input.

**Validation source:** tests/test_008_matrix2_transpose_q.c

**Test-derived call:**
```c
pc_matrix2_transpose_q(NULL, &actual\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_matrix3_q.h

**Public symbol:** pc_matrix3_q

**Implementation unit:** src/pc_matrix3_q.c

**Purpose and contract:** The public header contains the authoritative signature and input/output contract.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_mod_interval_contains_u32.h

**Public symbol:** pc_mod_interval_contains_u32

**Implementation unit:** src/pc_mod_interval_contains_u32.c

**Purpose and contract:** Closed forward arc on the uint32_t ring; equal endpoints denote one point.

**Validation source:** tests/test_009_mod_interval_contains_u32.c

**Test-derived call:**
```c
pc_mod_interval_contains_u32(10u, 20u, 10u\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_offset_range_check_u32.h

**Public symbol:** pc_offset_range_check_u32

**Implementation unit:** src/pc_offset_range_check_u32.c

**Purpose and contract:** Check the half-open span [offset, offset + length) against capacity. An empty span at offset == capacity is valid.

**Validation source:** tests/test_029_span_contains_span_u32.c

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_perpendicular_vectors2_i32.h

**Public symbol:** pc_perpendicular_vectors2_i32

**Implementation unit:** src/pc_perpendicular_vectors2_i32.c

**Purpose and contract:** True iff the exact dot product of the two int32 vectors is zero. A zero vector is perpendicular to every vector under this definition.

**Validation source:** tests/test_011_perpendicular_vectors2_i32.c

**Test-derived call:**
```c
pc_perpendicular_vectors2_i32(v[i][0],v[i][1],v[j][0],v[j][1])==ref(v[i][0],v[i][1],v[j][0],v[j][1]\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_piecewise_segment_index_i32.h

**Public symbol:** pc_piecewise_segment_index_i32

**Implementation unit:** src/pc_piecewise_segment_index_i32.c

**Purpose and contract:** Find clamped interval i for strictly increasing points[].input, count 2..255. Segment i spans knot i to i+1; exact interior knots select the segment to their right, and endpoints/outside clamp to [0,count-2].

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_q_hypot3.h

**Public symbol:** pc_q_hypot3

**Implementation unit:** src/pc_q_hypot3.c

**Purpose and contract:** Nearest-even Euclidean norm of three same-scale signed Q raw values. False on null output or int32 overflow; failure preserves *out.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_quat_conjugate_q.h

**Public symbol:** pc_quat_conjugate_q

**Implementation unit:** src/pc_quat_conjugate_q.c

**Purpose and contract:** Conjugate scalar-first Q1.30 quaternion; reject unnegatable INT32_MIN.

**Validation source:** tests/test_013_quat_conjugate_q.c

**Test-derived call:**
```c
pc_quat_conjugate_q(NULL, out\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_quat_dot_q.h

**Public symbol:** pc_quat_dot_q

**Implementation unit:** src/pc_quat_dot_q.c

**Purpose and contract:** Dot scalar-first Q1.30 quaternion components in [-1,1]; round to Q1.30.

**Validation source:** tests/test_014_quat_dot_q.c

**Test-derived call:**
```c
pc_quat_dot_q(NULL, b, &dot\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_quat_from_axis_angle_q.h

**Public symbol:** pc_quat_from_axis_angle_q

**Implementation unit:** src/pc_quat_from_axis_angle_q.c

**Purpose and contract:** Q0.32 full-turn angle and nonzero Q1.30 axis -> scalar-first Q1.30 quaternion.

**Validation source:** tests/test_015_quat_from_axis_angle_q.c

**Test-derived call:**
```c
pc_quat_from_axis_angle_q(NULL, 0u, out\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_quat_identity_q.h

**Public symbol:** pc_quat_identity_q

**Implementation unit:** src/pc_quat_identity_q.c

**Purpose and contract:** Store scalar-first Q1.30 identity quaternion [w, x, y, z].

**Validation source:** tests/test_016_quat_identity_q.c

**Test-derived call:**
```c
pc_quat_identity_q(NULL\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_quat_mul_q.h

**Public symbol:** pc_quat_mul_q

**Implementation unit:** src/pc_quat_mul_q.c

**Purpose and contract:** Hamilton product of scalar-first Q1.30 quaternions with components in [-1,1].

**Validation source:** tests/test_017_quat_mul_q.c

**Test-derived call:**
```c
pc_quat_mul_q(NULL, b, out\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_quat_nlerp_q.h

**Public symbol:** pc_quat_nlerp_q

**Implementation unit:** src/pc_quat_nlerp_q.c

**Purpose and contract:** Shortest-path normalized lerp; scalar-first Q1.30, ratio numerator/denominator.

**Validation source:** tests/test_018_quat_nlerp_q.c

**Test-derived call:**
```c
pc_quat_nlerp_q(NULL, b, 0u, 1u, out\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_quat_norm2_q.h

**Public symbol:** pc_quat_norm2_q

**Implementation unit:** src/pc_quat_norm2_q.c

**Purpose and contract:** Exact sum of squares for scalar-first Q1.30 quaternion in [-1,1]^4.

**Validation source:** tests/test_019_quat_norm2_q.c

**Test-derived call:**
```c
pc_quat_norm2_q(NULL, &norm2\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_quat_normalize_q.h

**Public symbol:** pc_quat_normalize_q

**Implementation unit:** src/pc_quat_normalize_q.c

**Purpose and contract:** Normalize scalar-first Q1.30 quaternion; reject zero and preserve output.

**Validation source:** tests/test_020_quat_normalize_q.c

**Test-derived call:**
```c
pc_quat_normalize_q(NULL, output\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_quat_rotate_vec3_q.h

**Public symbol:** pc_quat_rotate_vec3_q

**Implementation unit:** src/pc_quat_rotate_vec3_q.c

**Purpose and contract:** Rotate a Q1.30 vector whose components are in [-1,1] by a scalar-first quaternion. The nonzero quaternion is normalized internally.

**Validation source:** tests/test_021_quat_rotate_vec3_q.c

**Test-derived call:**
```c
pc_quat_rotate_vec3_q(NULL,v,o\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_quat_sign_canonical_q.h

**Public symbol:** pc_quat_sign_canonical_q

**Implementation unit:** src/pc_quat_sign_canonical_q.c

**Purpose and contract:** Canonicalize q/-q by making the first nonzero scalar-first component positive. Components must be in the inclusive Q1.30 range [-1,1].

**Validation source:** tests/test_022_quat_sign_canonical_q.c

**Test-derived call:**
```c
pc_quat_sign_canonical_q(NULL,o\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_quat_small_angle_update_q.h

**Public symbol:** pc_quat_small_angle_update_q

**Implementation unit:** src/pc_quat_small_angle_update_q.c

**Purpose and contract:** Apply a body-frame gyro sample (Q16.16 rad/s) over dt microseconds. Rejects when |gyro|*dt exceeds 0.01 rad; intended for small high-rate steps.

**Validation source:** tests/test_023_quat_small_angle_update_q.c

**Test-derived call:**
```c
pc_quat_small_angle_update_q(NULL,g,1,o\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_range_contains_i32.h

**Public symbol:** pc_range_contains_i32

**Implementation unit:** src/pc_range_contains_i32.c

**Purpose and contract:** Closed interval predicate. An inverted interval returns false.

**Validation source:** tests/test_024_range_contains_i32.c

**Test-derived call:**
```c
pc_range_contains_i32(5, 5, 5\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_range_distance_i32.h

**Public symbol:** pc_range_distance_i32

**Implementation unit:** src/pc_range_distance_i32.c

**Purpose and contract:** Distance from value to closed interval; zero inside; inverted interval fails.

**Validation source:** tests/test_025_range_distance_i32.c

**Test-derived call:**
```c
pc_range_distance_i32(5, 0, 10, &d) && d == 0);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_ring_distance_forward_u32.h

**Public symbol:** pc_ring_distance_forward_u32

**Implementation unit:** src/pc_ring_distance_forward_u32.c

**Purpose and contract:** Return forward distance from one valid ring index to another.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_rotation_matrix2_from_angle_q.h

**Public symbol:** pc_rotation_matrix2_from_angle_q

**Implementation unit:** src/pc_rotation_matrix2_from_angle_q.c

**Purpose and contract:** Active CCW 2D rotation matrix, row-major Q1.30 coefficients.

**Validation source:** tests/test_026_rotation_matrix2_from_angle_q.c

**Test-derived call:**
```c
pc_rotation_matrix2_from_angle_q(0,NULL\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_rotation_matrix3_transpose_q.h

**Public symbol:** pc_rotation_matrix3_transpose_q

**Implementation unit:** src/pc_rotation_matrix3_transpose_q.c

**Purpose and contract:** Transpose a row-major 3x3 Q matrix. Input and output may be the same object. For an orthogonal rotation matrix, the result is its inverse.

**Validation source:** tests/test_027_rotation_matrix3_transpose_q.c

**Test-derived call:**
```c
pc_rotation_matrix3_transpose_q(&m,&out\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_segment_progress_q.h

**Public symbol:** pc_segment_progress_q

**Implementation unit:** src/pc_segment_progress_q.c

**Purpose and contract:** Return the clamped projection parameter of point P on segment A->B as unsigned Q16.16 in [0,65536]. Coordinates are int16 grid units. False on A==B or null output; failure preserves *out.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_size_add_checked_u32.h

**Public symbol:** pc_size_add_checked_u32

**Implementation unit:** src/pc_size_add_checked_u32.c

**Purpose and contract:** Add two uint32 size/count values. False for null output or overflow; on failure, leave *sum unchanged.

**Validation source:** tests/test_028_span_contains_offset_u32.c

**Test-derived call:**
```c
pc_size_add_checked_u32(start, length, &end32);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_span_contains_offset_u32.h

**Public symbol:** pc_span_contains_offset_u32

**Implementation unit:** src/pc_span_contains_offset_u32.c

**Purpose and contract:** Test offset membership in a valid half-open [start, start+length) span.

**Validation source:** tests/test_028_span_contains_offset_u32.c

**Test-derived call:**
```c
pc_span_contains_offset_u32(start, length, offset);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_span_contains_span_u32.h

**Public symbol:** pc_span_contains_span_u32

**Implementation unit:** src/pc_span_contains_span_u32.c

**Purpose and contract:** Check whether a valid half-open inner span is contained by an outer span.

**Validation source:** tests/test_029_span_contains_span_u32.c

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_span_intersection_u32.h

**Public symbol:** pc_span_intersection_u32

**Implementation unit:** src/pc_span_intersection_u32.c

**Purpose and contract:** Write the nonempty half-open intersection. False preserves both outputs.

**Validation source:** tests/test_030_span_intersection_u32.c

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_sphere_aabb_overlap_i32.h

**Public symbol:** pc_sphere_aabb_overlap_i32

**Implementation unit:** src/pc_sphere_aabb_overlap_i32.c

**Purpose and contract:** Closed sphere/AABB overlap; any inverted box axis returns false.

**Validation source:** tests/test_031_sphere_aabb_overlap_i32.c

**Test-derived call:**
```c
pc_sphere_aabb_overlap_i32(x,y,z,r,x0,y0,z0,x1,y1,z1)==oracle(c,r,lo,hi\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_tof_distance_from_time_q.h

**Public symbol:** pc_tof_distance_from_time_q

**Implementation unit:** src/pc_tof_distance_from_time_q.c

**Purpose and contract:** Convert monostatic ultrasonic round-trip time to one-way distance. Time is in microseconds; sound speed is in millimetres/second; output is micrometres rounded to nearest, ties to even. Zero speed or null output fails without modifying the output.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_tof_time_from_distance_q.h

**Public symbol:** pc_tof_time_from_distance_q

**Implementation unit:** src/pc_tof_time_from_distance_q.c

**Purpose and contract:** Convert one-way distance to monostatic ultrasonic round-trip time. Distance is in micrometres; sound speed is in millimetres/second; result is microseconds rounded to nearest, ties to even. Zero speed or null output fails without modifying the output.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_trajectory_segment_select_u32.h

**Public symbol:** pc_trajectory_segment_select_u32

**Implementation unit:** src/pc_trajectory_segment_select_u32.c

**Purpose and contract:** Select interval i in strictly increasing time_knots[0..count-1]. Exact interior knots select the interval to their right; endpoints clamp to the first/last segment. count must be at least 2.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_translate_point2_i32.h

**Public symbol:** pc_translate_point2_i32

**Implementation unit:** src/pc_translate_point2_i32.c

**Purpose and contract:** Add a delta to an int32 coordinate pair. False on null/aliased outputs or if either result overflows; failure preserves both output values.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_vector_clamp_mag2_q.h

**Public symbol:** pc_vector_clamp_mag2_q

**Implementation unit:** src/pc_vector_clamp_mag2_q.c

**Purpose and contract:** Limit signed-Q15 int16 vector magnitude to a nonnegative raw-Q15 radius.

**Validation source:** tests/test_032_vector_clamp_mag2_q.c

**Test-derived call:**
```c
pc_vector_clamp_mag2_q(in,cap,out)||out[0]!=ref[0]||out[1]!=ref[1]);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_vector_cross3_i32.h

**Public symbol:** pc_vector_cross3_i32

**Implementation unit:** src/pc_vector_cross3_i32.c

**Purpose and contract:** Exact cross product of two signed int32 3D vectors; output components are int64.

**Validation source:** tests/test_033_vector_cross3_i32.c

**Test-derived call:**
```c
pc_vector_cross3_i32(a,b,c)||!pc_vector_cross3_i32(b,a,d\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_vector_dominant_axis3_i32.h

**Public symbol:** pc_vector_dominant_axis3_i32

**Implementation unit:** src/pc_vector_dominant_axis3_i32.c

**Purpose and contract:** Return the lowest index whose component has greatest absolute magnitude.

**Validation source:** tests/test_034_vector_dominant_axis3_i32.c

**Test-derived call:**
```c
pc_vector_dominant_axis3_i32((int32_t[3]){INT32_MIN,INT32_MAX,0},&got)||got!=0);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_vector_rotate2_q.h

**Public symbol:** pc_vector_rotate2_q

**Implementation unit:** src/pc_vector_rotate2_q.c

**Purpose and contract:** Rotate signed-Q15 2D vector by unsigned Q0.32 turns using CORDIC; components saturate to int16.

**Validation source:** tests/test_035_vector_rotate2_q.c

**Test-derived call:**
```c
pc_vector_rotate2_q(in,phase,out\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/vectrava/geometry/pc_waypoint_distance2_i32.h

**Public symbol:** pc_waypoint_distance2_i32

**Implementation unit:** src/pc_waypoint_distance2_i32.c

**Purpose and contract:** Exact squared Euclidean distance between int32 coordinates. False on null output or uint64 result overflow; failure preserves *out.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

