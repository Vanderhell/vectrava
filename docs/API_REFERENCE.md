# Vectrava API reference

This reference lists all 54 public headers (52 callable APIs and two matrix type headers). Contracts come from the public declarations; direct test-source mapping covers the 36 behavior programs.

## Reading the entries
Each entry states the public symbol, implementation unit, contract, edge/failure behavior and a call extracted from the validating test source. The examples are evidence-oriented; adapt buffer ownership and numeric units to the application.

## include/vectrava/geometry/affine2_apply_q.h

**Public symbol:** vectrava_affine2_apply_q

**Implementation unit:** src/vectrava_affine2_apply_q.c

**Purpose and contract:** Apply a row-major 2x2 Q matrix and Q translation. Each dot product is rounded nearest-even once. False on invalid pointers/fractional_bits or result overflow; failure preserves output. Output may alias point/translation.

**Executable test cases:** [`test_api_gaps.c`](../tests/test_api_gaps.c)





## include/vectrava/geometry/bbox_of_points2_i32.h

**Public symbol:** vectrava_bbox_of_points2_i32

**Implementation unit:** src/vectrava_bbox_of_points2_i32.c

**Purpose and contract:** Compute the closed AABB of count points. Reject null pointers or count==0; on failure, preserve *bounds. The input array is read-only.

**Executable test cases:** [`test_bbox_of_points2_i32.c`](../tests/test_bbox_of_points2_i32.c)


## include/vectrava/geometry/bearing2_q.h

**Public symbol:** vectrava_bearing2_q

**Implementation unit:** src/vectrava_bearing2_q.c

**Purpose and contract:** CORDIC estimate of bearing from an int32 origin to target as unsigned Q0.32 turns CCW from +X. Equal points return zero. Coordinates need not share a specific Q scale. Differential tests observed <= 16 phase-code error; this empirical limit is not a formal global bound.

**Executable test cases:** [`test_api_gaps.c`](../tests/test_api_gaps.c)





## include/vectrava/geometry/calibrate_piecewise_i32.h

**Public symbol:** vectrava_calibrate_piecewise_i32

**Implementation unit:** src/vectrava_calibrate_piecewise_i32.c

**Purpose and contract:** Piecewise-linear map, clamp beyond endpoints, nearest/ties-away rounding. Count is 2..255; input knots must be strictly increasing.

**Executable test cases:** [`test_api_gaps.c`](../tests/test_api_gaps.c)





## include/vectrava/geometry/circle_aabb_overlap_i32.h

**Public symbol:** vectrava_circle_aabb_overlap_i32

**Implementation unit:** src/vectrava_circle_aabb_overlap_i32.c

**Purpose and contract:** Closed circle/AABB overlap; inverted box bounds return false.

**Executable test cases:** [`test_circle_aabb_overlap_i32.c`](../tests/test_circle_aabb_overlap_i32.c)


## include/vectrava/geometry/distance_to_stop_q.h

**Public symbol:** vectrava_distance_to_stop_q

**Implementation unit:** src/vectrava_distance_to_stop_q.c

**Purpose and contract:** Constant-deceleration stopping distance: ceil(|v|^2/(2*a)). Velocity is signed Q16.16 units/s, positive braking deceleration is Q16.16 units/s^2, result is unsigned Q16.16 distance. Zero speed returns 0; nonzero speed with zero deceleration fails atomically.

**Executable test cases:** [`test_api_gaps.c`](../tests/test_api_gaps.c)





## include/vectrava/geometry/hash_probe_linear_u32.h

**Public symbol:** vectrava_hash_probe_linear_u32

**Implementation unit:** src/vectrava_hash_probe_linear_u32.c

**Purpose and contract:** Return (start + ordinal) modulo capacity without uint32 overflow. Requires capacity > 0 and start < capacity; failure preserves *index.

**Executable test cases:** [`test_hash_probe_linear_u32.c`](../tests/test_hash_probe_linear_u32.c)


## include/vectrava/geometry/homogeneous2_apply_q.h

**Public symbol:** vectrava_homogeneous2_apply_q

**Implementation unit:** src/vectrava_homogeneous2_apply_q.c

**Purpose and contract:** Apply a row-major 3x3 Q matrix to a homogeneous 3-vector. Each row dot product is rounded nearest-even once. Returns homogeneous output; it does not divide by W. False preserves output. Output may alias matrix/vector.

**Executable test cases:** [`test_api_gaps.c`](../tests/test_api_gaps.c)





## include/vectrava/geometry/checked_add_i64.h

**Public symbol:** vectrava_checked_add_i64

**Implementation unit:** src/vectrava_checked_add_i64.c

**Purpose and contract:** Store a+b exactly. False for null output or signed overflow; failure writes nothing to result.

**Executable test cases:** [`test_api_gaps.c`](../tests/test_api_gaps.c)





## include/vectrava/geometry/checked_neg_i64.h

**Public symbol:** vectrava_checked_neg_i64

**Implementation unit:** src/vectrava_checked_neg_i64.c

**Purpose and contract:** Store -value exactly; false for null output or INT64_MIN, preserving output.

**Executable test cases:** [`test_matrix2_adjugate_q.c`](../tests/test_matrix2_adjugate_q.c)


## include/vectrava/geometry/linear_interp_ratio_i32.h

**Public symbol:** vectrava_linear_interp_ratio_i32

**Implementation unit:** src/vectrava_linear_interp_ratio_i32.c

**Purpose and contract:** Convex interpolation at numerator/denominator in [0,1]. The exact result rounds to nearest, ties-to-even. Invalid ratio/output preserves *result.

**Executable test cases:** [`test_linear_interp_ratio_i32.c`](../tests/test_linear_interp_ratio_i32.c)


## include/vectrava/geometry/linear_interp_ratio_u32.h

**Public symbol:** vectrava_linear_interp_ratio_u32

**Implementation unit:** src/vectrava_linear_interp_ratio_u32.c

**Purpose and contract:** Convex interpolation for a ratio in [0,1]. Rounds nearest, ties-to-even; invalid ratios or output pointer preserve *result.

**Executable test cases:** [`test_linear_interp_ratio_u32.c`](../tests/test_linear_interp_ratio_u32.c)


## include/vectrava/geometry/matrix2_add_q.h

**Public symbol:** vectrava_matrix2_add_q

**Implementation unit:** src/vectrava_matrix2_add_q.c

**Purpose and contract:** Exact elementwise addition. On any component overflow, write nothing.

**Executable test cases:** [`test_matrix2_sub_q.c`](../tests/test_matrix2_sub_q.c)


## include/vectrava/geometry/matrix2_adjugate_q.h

**Public symbol:** vectrava_matrix2_adjugate_q

**Implementation unit:** src/vectrava_matrix2_adjugate_q.c

**Purpose and contract:** Adjugate [[a,b],[c,d]] to [[d,-b],[-c,a]], checked and alias-safe.

**Executable test cases:** [`test_matrix2_adjugate_q.c`](../tests/test_matrix2_adjugate_q.c)


## include/vectrava/geometry/matrix2_q.h

**Public type:** `vectrava_matrix2_q`

**Purpose and representation:** Row-major 2×2 matrix with four signed 32-bit elements. The type carries no fractional-bit metadata; operations define the applicable scale.

**Validation:** The header is compiled independently as C and included in the C++ aggregate-header smoke test. It has no callable operation of its own.



## include/vectrava/geometry/matrix2_sub_q.h

**Public symbol:** vectrava_matrix2_sub_q

**Implementation unit:** src/vectrava_matrix2_sub_q.c

**Purpose and contract:** Exact elementwise subtraction. On any component overflow, write nothing.

**Executable test cases:** [`test_matrix2_sub_q.c`](../tests/test_matrix2_sub_q.c)


## include/vectrava/geometry/matrix2_transpose_q.h

**Public symbol:** vectrava_matrix2_transpose_q

**Implementation unit:** src/vectrava_matrix2_transpose_q.c

**Purpose and contract:** Transpose a row-major 2x2 Q matrix; result may alias input.

**Executable test cases:** [`test_matrix2_transpose_q.c`](../tests/test_matrix2_transpose_q.c)


## include/vectrava/geometry/matrix3_q.h

**Public type:** `vectrava_matrix3_q`

**Purpose and representation:** Row-major 3×3 matrix with nine signed 32-bit elements. The type carries no fractional-bit metadata; operations define the applicable scale.

**Validation:** The header is compiled independently as C and included in the C++ aggregate-header smoke test. It has no callable operation of its own.



## include/vectrava/geometry/mod_interval_contains_u32.h

**Public symbol:** vectrava_mod_interval_contains_u32

**Implementation unit:** src/vectrava_mod_interval_contains_u32.c

**Purpose and contract:** Closed forward arc on the uint32_t ring; equal endpoints denote one point.

**Executable test cases:** [`test_mod_interval_contains_u32.c`](../tests/test_mod_interval_contains_u32.c), [`test_mod_interval_contains_u32_extra2.c`](../tests/test_mod_interval_contains_u32_extra2.c), [`test_span_contains_offset_u32.c`](../tests/test_span_contains_offset_u32.c)


## include/vectrava/geometry/offset_range_check_u32.h

**Public symbol:** vectrava_offset_range_check_u32

**Implementation unit:** src/vectrava_offset_range_check_u32.c

**Purpose and contract:** Check the half-open span [offset, offset + length) against capacity. An empty span at offset == capacity is valid.

**Executable test cases:** [`test_span_contains_span_u32.c`](../tests/test_span_contains_span_u32.c), [`test_span_intersection_u32.c`](../tests/test_span_intersection_u32.c)


## include/vectrava/geometry/perpendicular_vectors2_i32.h

**Public symbol:** vectrava_perpendicular_vectors2_i32

**Implementation unit:** src/vectrava_perpendicular_vectors2_i32.c

**Purpose and contract:** True iff the exact dot product of the two int32 vectors is zero. A zero vector is perpendicular to every vector under this definition.

**Executable test cases:** [`test_perpendicular_vectors2_i32.c`](../tests/test_perpendicular_vectors2_i32.c), [`test_perpendicular_vectors2_i32_extra2.c`](../tests/test_perpendicular_vectors2_i32_extra2.c)


## include/vectrava/geometry/piecewise_segment_index_i32.h

**Public symbol:** vectrava_piecewise_segment_index_i32

**Implementation unit:** src/vectrava_piecewise_segment_index_i32.c

**Purpose and contract:** Find clamped interval i for strictly increasing points[].input, count 2..255. Segment i spans knot i to i+1; exact interior knots select the segment to their right, and endpoints/outside clamp to [0,count-2].

**Executable test cases:** [`test_api_gaps.c`](../tests/test_api_gaps.c)





## include/vectrava/geometry/q_hypot3.h

**Public symbol:** vectrava_q_hypot3

**Implementation unit:** src/vectrava_q_hypot3.c

**Purpose and contract:** Nearest-even Euclidean norm of three same-scale signed Q raw values. False on null output or int32 overflow; failure preserves *out.

**Executable test cases:** [`test_api_gaps.c`](../tests/test_api_gaps.c)





## include/vectrava/geometry/quat_conjugate_q.h

**Public symbol:** vectrava_quat_conjugate_q

**Implementation unit:** src/vectrava_quat_conjugate_q.c

**Purpose and contract:** Conjugate scalar-first Q1.30 quaternion; reject unnegatable INT32_MIN.

**Executable test cases:** [`test_quat_conjugate_q.c`](../tests/test_quat_conjugate_q.c)


## include/vectrava/geometry/quat_dot_q.h

**Public symbol:** vectrava_quat_dot_q

**Implementation unit:** src/vectrava_quat_dot_q.c

**Purpose and contract:** Dot scalar-first Q1.30 quaternion components in [-1,1]; round to Q1.30.

**Executable test cases:** [`test_quat_dot_q.c`](../tests/test_quat_dot_q.c)


## include/vectrava/geometry/quat_from_axis_angle_q.h

**Public symbol:** vectrava_quat_from_axis_angle_q

**Implementation unit:** src/vectrava_quat_from_axis_angle_q.c

**Purpose and contract:** Q0.32 full-turn angle and nonzero Q1.30 axis -> scalar-first Q1.30 quaternion.

**Executable test cases:** [`test_quat_from_axis_angle_q.c`](../tests/test_quat_from_axis_angle_q.c)


## include/vectrava/geometry/quat_identity_q.h

**Public symbol:** vectrava_quat_identity_q

**Implementation unit:** src/vectrava_quat_identity_q.c

**Purpose and contract:** Store scalar-first Q1.30 identity quaternion [w, x, y, z].

**Executable test cases:** [`test_quat_identity_q.c`](../tests/test_quat_identity_q.c)


## include/vectrava/geometry/quat_mul_q.h

**Public symbol:** vectrava_quat_mul_q

**Implementation unit:** src/vectrava_quat_mul_q.c

**Purpose and contract:** Hamilton product of scalar-first Q1.30 quaternions with components in [-1,1].

**Executable test cases:** [`test_quat_mul_q.c`](../tests/test_quat_mul_q.c)


## include/vectrava/geometry/quat_nlerp_q.h

**Public symbol:** vectrava_quat_nlerp_q

**Implementation unit:** src/vectrava_quat_nlerp_q.c

**Purpose and contract:** Shortest-path normalized lerp; scalar-first Q1.30, ratio numerator/denominator.

**Executable test cases:** [`test_quat_nlerp_q.c`](../tests/test_quat_nlerp_q.c)


## include/vectrava/geometry/quat_norm2_q.h

**Public symbol:** vectrava_quat_norm2_q

**Implementation unit:** src/vectrava_quat_norm2_q.c

**Purpose and contract:** Exact sum of squares for scalar-first Q1.30 quaternion in [-1,1]^4.

**Executable test cases:** [`test_quat_norm2_q.c`](../tests/test_quat_norm2_q.c)


## include/vectrava/geometry/quat_normalize_q.h

**Public symbol:** vectrava_quat_normalize_q

**Implementation unit:** src/vectrava_quat_normalize_q.c

**Purpose and contract:** Normalize scalar-first Q1.30 quaternion; reject zero and preserve output.

**Executable test cases:** [`test_quat_normalize_q.c`](../tests/test_quat_normalize_q.c)


## include/vectrava/geometry/quat_rotate_vec3_q.h

**Public symbol:** vectrava_quat_rotate_vec3_q

**Implementation unit:** src/vectrava_quat_rotate_vec3_q.c

**Purpose and contract:** Rotate a Q1.30 vector whose components are in [-1,1] by a scalar-first quaternion. The nonzero quaternion is normalized internally.

**Executable test cases:** [`test_quat_rotate_vec3_q.c`](../tests/test_quat_rotate_vec3_q.c)


## include/vectrava/geometry/quat_sign_canonical_q.h

**Public symbol:** vectrava_quat_sign_canonical_q

**Implementation unit:** src/vectrava_quat_sign_canonical_q.c

**Purpose and contract:** Canonicalize q/-q by making the first nonzero scalar-first component positive. Components must be in the inclusive Q1.30 range [-1,1].

**Executable test cases:** [`test_quat_sign_canonical_q.c`](../tests/test_quat_sign_canonical_q.c)


## include/vectrava/geometry/quat_small_angle_update_q.h

**Public symbol:** vectrava_quat_small_angle_update_q

**Implementation unit:** src/vectrava_quat_small_angle_update_q.c

**Purpose and contract:** Apply a body-frame gyro sample (Q16.16 rad/s) over dt microseconds. Rejects when |gyro|*dt exceeds 0.01 rad; intended for small high-rate steps.

**Executable test cases:** [`test_quat_small_angle_update_q.c`](../tests/test_quat_small_angle_update_q.c)


## include/vectrava/geometry/range_contains_i32.h

**Public symbol:** vectrava_range_contains_i32

**Implementation unit:** src/vectrava_range_contains_i32.c

**Purpose and contract:** Closed interval predicate. An inverted interval returns false.

**Executable test cases:** [`test_range_contains_i32.c`](../tests/test_range_contains_i32.c)


## include/vectrava/geometry/range_distance_i32.h

**Public symbol:** vectrava_range_distance_i32

**Implementation unit:** src/vectrava_range_distance_i32.c

**Purpose and contract:** Distance from value to closed interval; zero inside; inverted interval fails.

**Executable test cases:** [`test_range_distance_i32.c`](../tests/test_range_distance_i32.c)


## include/vectrava/geometry/ring_distance_forward_u32.h

**Public symbol:** vectrava_ring_distance_forward_u32

**Implementation unit:** src/vectrava_ring_distance_forward_u32.c

**Purpose and contract:** Return forward distance from one valid ring index to another.

**Executable test cases:** [`test_api_gaps.c`](../tests/test_api_gaps.c)





## include/vectrava/geometry/rotation_matrix2_from_angle_q.h

**Public symbol:** vectrava_rotation_matrix2_from_angle_q

**Implementation unit:** src/vectrava_rotation_matrix2_from_angle_q.c

**Purpose and contract:** Active CCW 2D rotation matrix, row-major Q1.30 coefficients.

**Executable test cases:** [`test_rotation_matrix2_from_angle_q.c`](../tests/test_rotation_matrix2_from_angle_q.c)


## include/vectrava/geometry/rotation_matrix3_transpose_q.h

**Public symbol:** vectrava_rotation_matrix3_transpose_q

**Implementation unit:** src/vectrava_rotation_matrix3_transpose_q.c

**Purpose and contract:** Transpose a row-major 3x3 Q matrix. Input and output may be the same object. For an orthogonal rotation matrix, the result is its inverse.

**Executable test cases:** [`test_rotation_matrix3_transpose_q.c`](../tests/test_rotation_matrix3_transpose_q.c)


## include/vectrava/geometry/segment_progress_q.h

**Public symbol:** vectrava_segment_progress_q

**Implementation unit:** src/vectrava_segment_progress_q.c

**Purpose and contract:** Return the clamped projection parameter of point P on segment A->B as unsigned Q16.16 in [0,65536]. Coordinates are int16 grid units. False on A==B or null output; failure preserves *out.

**Executable test cases:** [`test_api_gaps.c`](../tests/test_api_gaps.c)





## include/vectrava/geometry/size_add_checked_u32.h

**Public symbol:** vectrava_size_add_checked_u32

**Implementation unit:** src/vectrava_size_add_checked_u32.c

**Purpose and contract:** Add two uint32 size/count values. False for null output or overflow; on failure, leave *sum unchanged.

**Executable test cases:** [`test_span_contains_offset_u32.c`](../tests/test_span_contains_offset_u32.c)


## include/vectrava/geometry/span_contains_offset_u32.h

**Public symbol:** vectrava_span_contains_offset_u32

**Implementation unit:** src/vectrava_span_contains_offset_u32.c

**Purpose and contract:** Test offset membership in a valid half-open [start, start+length) span.

**Executable test cases:** [`test_span_contains_offset_u32.c`](../tests/test_span_contains_offset_u32.c)


## include/vectrava/geometry/span_contains_span_u32.h

**Public symbol:** vectrava_span_contains_span_u32

**Implementation unit:** src/vectrava_span_contains_span_u32.c

**Purpose and contract:** Check whether a valid half-open inner span is contained by an outer span.

**Executable test cases:** [`test_span_contains_span_u32.c`](../tests/test_span_contains_span_u32.c)


## include/vectrava/geometry/span_intersection_u32.h

**Public symbol:** vectrava_span_intersection_u32

**Implementation unit:** src/vectrava_span_intersection_u32.c

**Purpose and contract:** Write the nonempty half-open intersection. False preserves both outputs.

**Executable test cases:** [`test_span_intersection_u32.c`](../tests/test_span_intersection_u32.c)


## include/vectrava/geometry/sphere_aabb_overlap_i32.h

**Public symbol:** vectrava_sphere_aabb_overlap_i32

**Implementation unit:** src/vectrava_sphere_aabb_overlap_i32.c

**Purpose and contract:** Closed sphere/AABB overlap; any inverted box axis returns false.

**Executable test cases:** [`test_sphere_aabb_overlap_i32.c`](../tests/test_sphere_aabb_overlap_i32.c)


## include/vectrava/geometry/tof_distance_from_time_q.h

**Public symbol:** vectrava_tof_distance_from_time_q

**Implementation unit:** src/vectrava_tof_distance_from_time_q.c

**Purpose and contract:** Convert monostatic ultrasonic round-trip time to one-way distance. Time is in microseconds; sound speed is in millimetres/second; output is micrometres rounded to nearest, ties to even. Zero speed or null output fails without modifying the output.

**Executable test cases:** [`test_api_gaps.c`](../tests/test_api_gaps.c)





## include/vectrava/geometry/tof_time_from_distance_q.h

**Public symbol:** vectrava_tof_time_from_distance_q

**Implementation unit:** src/vectrava_tof_time_from_distance_q.c

**Purpose and contract:** Convert one-way distance to monostatic ultrasonic round-trip time. Distance is in micrometres; sound speed is in millimetres/second; result is microseconds rounded to nearest, ties to even. Zero speed or null output fails without modifying the output.

**Executable test cases:** [`test_api_gaps.c`](../tests/test_api_gaps.c)





## include/vectrava/geometry/trajectory_segment_select_u32.h

**Public symbol:** vectrava_trajectory_segment_select_u32

**Implementation unit:** src/vectrava_trajectory_segment_select_u32.c

**Purpose and contract:** Select interval i in strictly increasing time_knots[0..count-1]. Exact interior knots select the interval to their right; endpoints clamp to the first/last segment. count must be at least 2.

**Executable test cases:** [`test_api_gaps.c`](../tests/test_api_gaps.c)





## include/vectrava/geometry/translate_point2_i32.h

**Public symbol:** vectrava_translate_point2_i32

**Implementation unit:** src/vectrava_translate_point2_i32.c

**Purpose and contract:** Add a delta to an int32 coordinate pair. False on null/aliased outputs or if either result overflows; failure preserves both output values.

**Executable test cases:** [`test_api_gaps.c`](../tests/test_api_gaps.c)





## include/vectrava/geometry/vector_clamp_mag2_q.h

**Public symbol:** vectrava_vector_clamp_mag2_q

**Implementation unit:** src/vectrava_vector_clamp_mag2_q.c

**Purpose and contract:** Limit signed-Q15 int16 vector magnitude to a nonnegative raw-Q15 radius.

**Executable test cases:** [`test_vector_clamp_mag2_q.c`](../tests/test_vector_clamp_mag2_q.c)


## include/vectrava/geometry/vector_cross3_i32.h

**Public symbol:** vectrava_vector_cross3_i32

**Implementation unit:** src/vectrava_vector_cross3_i32.c

**Purpose and contract:** Exact cross product of two signed int32 3D vectors; output components are int64.

**Executable test cases:** [`test_vector_cross3_i32.c`](../tests/test_vector_cross3_i32.c)


## include/vectrava/geometry/vector_dominant_axis3_i32.h

**Public symbol:** vectrava_vector_dominant_axis3_i32

**Implementation unit:** src/vectrava_vector_dominant_axis3_i32.c

**Purpose and contract:** Return the lowest index whose component has greatest absolute magnitude.

**Executable test cases:** [`test_vector_dominant_axis3_i32.c`](../tests/test_vector_dominant_axis3_i32.c)


## include/vectrava/geometry/vector_rotate2_q.h

**Public symbol:** vectrava_vector_rotate2_q

**Implementation unit:** src/vectrava_vector_rotate2_q.c

**Purpose and contract:** Rotate signed-Q15 2D vector by unsigned Q0.32 turns using CORDIC; components saturate to int16.

**Executable test cases:** [`test_vector_rotate2_q.c`](../tests/test_vector_rotate2_q.c)


## include/vectrava/geometry/waypoint_distance2_i32.h

**Public symbol:** vectrava_waypoint_distance2_i32

**Implementation unit:** src/vectrava_waypoint_distance2_i32.c

**Purpose and contract:** Exact squared Euclidean distance between int32 coordinates. False on null output or uint64 result overflow; failure preserves *out.

**Executable test cases:** [`test_api_gaps.c`](../tests/test_api_gaps.c)
