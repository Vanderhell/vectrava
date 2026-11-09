# Vectrava API reference

Complete public-header inventory generated from the current source tree. Headers remain authoritative.

## include/vectrava/geometry/pc_affine2_apply_q.h

Public API: pc_affine2_apply_q

Contract: Apply a row-major 2x2 Q matrix and Q translation. Each dot product is rounded nearest-even once. False on invalid pointers/fractional_bits or result overflow; failure preserves output. Output may alias point/translation.

Header path: include/vectrava/geometry/pc_affine2_apply_q.h

## include/vectrava/geometry/pc_bbox_of_points2_i32.h

Public API: pc_bbox_of_points2_i32

Contract: Compute the closed AABB of count points. Reject null pointers or count==0; on failure, preserve *bounds. The input array is read-only.

Header path: include/vectrava/geometry/pc_bbox_of_points2_i32.h

## include/vectrava/geometry/pc_bearing2_q.h

Public API: pc_bearing2_q

Contract: CORDIC estimate of bearing from an int32 origin to target as unsigned Q0.32 turns CCW from +X. Equal points return zero. Coordinates need not share a specific Q scale. Differential tests observed <= 16 phase-code error; this empirical limit is not a formal global bound.

Header path: include/vectrava/geometry/pc_bearing2_q.h

## include/vectrava/geometry/pc_calibrate_piecewise_i32.h

Public API: pc_calibrate_piecewise_i32

Contract: Piecewise-linear map, clamp beyond endpoints, nearest/ties-away rounding. Count is 2..255; input knots must be strictly increasing.

Header path: include/vectrava/geometry/pc_calibrate_piecewise_i32.h

## include/vectrava/geometry/pc_circle_aabb_overlap_i32.h

Public API: pc_circle_aabb_overlap_i32

Contract: Closed circle/AABB overlap; inverted box bounds return false.

Header path: include/vectrava/geometry/pc_circle_aabb_overlap_i32.h

## include/vectrava/geometry/pc_distance_to_stop_q.h

Public API: pc_distance_to_stop_q

Contract: Constant-deceleration stopping distance: ceil(|v|^2/(2*a)). Velocity is signed Q16.16 units/s, positive braking deceleration is Q16.16 units/s^2, result is unsigned Q16.16 distance. Zero speed returns 0; nonzero speed with zero deceleration fails atomically.

Header path: include/vectrava/geometry/pc_distance_to_stop_q.h

## include/vectrava/geometry/pc_hash_probe_linear_u32.h

Public API: pc_hash_probe_linear_u32

Contract: Return (start + ordinal) modulo capacity without uint32 overflow. Requires capacity > 0 and start < capacity; failure preserves *index.

Header path: include/vectrava/geometry/pc_hash_probe_linear_u32.h

## include/vectrava/geometry/pc_homogeneous2_apply_q.h

Public API: pc_homogeneous2_apply_q

Contract: Apply a row-major 3x3 Q matrix to a homogeneous 3-vector. Each row dot product is rounded nearest-even once. Returns homogeneous output; it does not divide by W. False preserves output. Output may alias matrix/vector.

Header path: include/vectrava/geometry/pc_homogeneous2_apply_q.h

## include/vectrava/geometry/pc_checked_add_i64.h

Public API: pc_checked_add_i64

Contract: Store a+b exactly. False for null output or signed overflow; failure writes nothing to result.

Header path: include/vectrava/geometry/pc_checked_add_i64.h

## include/vectrava/geometry/pc_checked_neg_i64.h

Public API: pc_checked_neg_i64

Contract: Store -value exactly; false for null output or INT64_MIN, preserving output.

Header path: include/vectrava/geometry/pc_checked_neg_i64.h

## include/vectrava/geometry/pc_linear_interp_ratio_i32.h

Public API: pc_linear_interp_ratio_i32

Contract: Convex interpolation at numerator/denominator in [0,1]. The exact result rounds to nearest, ties-to-even. Invalid ratio/output preserves *result.

Header path: include/vectrava/geometry/pc_linear_interp_ratio_i32.h

## include/vectrava/geometry/pc_linear_interp_ratio_u32.h

Public API: pc_linear_interp_ratio_u32

Contract: Convex interpolation for a ratio in [0,1]. Rounds nearest, ties-to-even; invalid ratios or output pointer preserve *result.

Header path: include/vectrava/geometry/pc_linear_interp_ratio_u32.h

## include/vectrava/geometry/pc_matrix2_add_q.h

Public API: pc_matrix2_add_q

Contract: Exact elementwise addition. On any component overflow, write nothing.

Header path: include/vectrava/geometry/pc_matrix2_add_q.h

## include/vectrava/geometry/pc_matrix2_adjugate_q.h

Public API: pc_matrix2_adjugate_q

Contract: Adjugate [[a,b],[c,d]] to [[d,-b],[-c,a]], checked and alias-safe.

Header path: include/vectrava/geometry/pc_matrix2_adjugate_q.h

## include/vectrava/geometry/pc_matrix2_q.h

Public API: pc_matrix2_q

Contract: Row-major 2x2 signed Q matrix; all elements share one caller-selected scale.

Header path: include/vectrava/geometry/pc_matrix2_q.h

## include/vectrava/geometry/pc_matrix2_sub_q.h

Public API: pc_matrix2_sub_q

Contract: Exact elementwise subtraction. On any component overflow, write nothing.

Header path: include/vectrava/geometry/pc_matrix2_sub_q.h

## include/vectrava/geometry/pc_matrix2_transpose_q.h

Public API: pc_matrix2_transpose_q

Contract: Transpose a row-major 2x2 Q matrix; result may alias input.

Header path: include/vectrava/geometry/pc_matrix2_transpose_q.h

## include/vectrava/geometry/pc_matrix3_q.h

Public API: pc_matrix3_q

Contract: The public header contains the authoritative signature and input/output contract.

Header path: include/vectrava/geometry/pc_matrix3_q.h

## include/vectrava/geometry/pc_mod_interval_contains_u32.h

Public API: pc_mod_interval_contains_u32

Contract: Closed forward arc on the uint32_t ring; equal endpoints denote one point.

Header path: include/vectrava/geometry/pc_mod_interval_contains_u32.h

## include/vectrava/geometry/pc_offset_range_check_u32.h

Public API: pc_offset_range_check_u32

Contract: Check the half-open span [offset, offset + length) against capacity. An empty span at offset == capacity is valid.

Header path: include/vectrava/geometry/pc_offset_range_check_u32.h

## include/vectrava/geometry/pc_perpendicular_vectors2_i32.h

Public API: pc_perpendicular_vectors2_i32

Contract: True iff the exact dot product of the two int32 vectors is zero. A zero vector is perpendicular to every vector under this definition.

Header path: include/vectrava/geometry/pc_perpendicular_vectors2_i32.h

## include/vectrava/geometry/pc_piecewise_segment_index_i32.h

Public API: pc_piecewise_segment_index_i32

Contract: Find clamped interval i for strictly increasing points[].input, count 2..255. Segment i spans knot i to i+1; exact interior knots select the segment to their right, and endpoints/outside clamp to [0,count-2].

Header path: include/vectrava/geometry/pc_piecewise_segment_index_i32.h

## include/vectrava/geometry/pc_q_hypot3.h

Public API: pc_q_hypot3

Contract: Nearest-even Euclidean norm of three same-scale signed Q raw values. False on null output or int32 overflow; failure preserves *out.

Header path: include/vectrava/geometry/pc_q_hypot3.h

## include/vectrava/geometry/pc_quat_conjugate_q.h

Public API: pc_quat_conjugate_q

Contract: Conjugate scalar-first Q1.30 quaternion; reject unnegatable INT32_MIN.

Header path: include/vectrava/geometry/pc_quat_conjugate_q.h

## include/vectrava/geometry/pc_quat_dot_q.h

Public API: pc_quat_dot_q

Contract: Dot scalar-first Q1.30 quaternion components in [-1,1]; round to Q1.30.

Header path: include/vectrava/geometry/pc_quat_dot_q.h

## include/vectrava/geometry/pc_quat_from_axis_angle_q.h

Public API: pc_quat_from_axis_angle_q

Contract: Q0.32 full-turn angle and nonzero Q1.30 axis -> scalar-first Q1.30 quaternion.

Header path: include/vectrava/geometry/pc_quat_from_axis_angle_q.h

## include/vectrava/geometry/pc_quat_identity_q.h

Public API: pc_quat_identity_q

Contract: Store scalar-first Q1.30 identity quaternion [w, x, y, z].

Header path: include/vectrava/geometry/pc_quat_identity_q.h

## include/vectrava/geometry/pc_quat_mul_q.h

Public API: pc_quat_mul_q

Contract: Hamilton product of scalar-first Q1.30 quaternions with components in [-1,1].

Header path: include/vectrava/geometry/pc_quat_mul_q.h

## include/vectrava/geometry/pc_quat_nlerp_q.h

Public API: pc_quat_nlerp_q

Contract: Shortest-path normalized lerp; scalar-first Q1.30, ratio numerator/denominator.

Header path: include/vectrava/geometry/pc_quat_nlerp_q.h

## include/vectrava/geometry/pc_quat_norm2_q.h

Public API: pc_quat_norm2_q

Contract: Exact sum of squares for scalar-first Q1.30 quaternion in [-1,1]^4.

Header path: include/vectrava/geometry/pc_quat_norm2_q.h

## include/vectrava/geometry/pc_quat_normalize_q.h

Public API: pc_quat_normalize_q

Contract: Normalize scalar-first Q1.30 quaternion; reject zero and preserve output.

Header path: include/vectrava/geometry/pc_quat_normalize_q.h

## include/vectrava/geometry/pc_quat_rotate_vec3_q.h

Public API: pc_quat_rotate_vec3_q

Contract: Rotate a Q1.30 vector whose components are in [-1,1] by a scalar-first quaternion. The nonzero quaternion is normalized internally.

Header path: include/vectrava/geometry/pc_quat_rotate_vec3_q.h

## include/vectrava/geometry/pc_quat_sign_canonical_q.h

Public API: pc_quat_sign_canonical_q

Contract: Canonicalize q/-q by making the first nonzero scalar-first component positive. Components must be in the inclusive Q1.30 range [-1,1].

Header path: include/vectrava/geometry/pc_quat_sign_canonical_q.h

## include/vectrava/geometry/pc_quat_small_angle_update_q.h

Public API: pc_quat_small_angle_update_q

Contract: Apply a body-frame gyro sample (Q16.16 rad/s) over dt microseconds. Rejects when |gyro|*dt exceeds 0.01 rad; intended for small high-rate steps.

Header path: include/vectrava/geometry/pc_quat_small_angle_update_q.h

## include/vectrava/geometry/pc_range_contains_i32.h

Public API: pc_range_contains_i32

Contract: Closed interval predicate. An inverted interval returns false.

Header path: include/vectrava/geometry/pc_range_contains_i32.h

## include/vectrava/geometry/pc_range_distance_i32.h

Public API: pc_range_distance_i32

Contract: Distance from value to closed interval; zero inside; inverted interval fails.

Header path: include/vectrava/geometry/pc_range_distance_i32.h

## include/vectrava/geometry/pc_ring_distance_forward_u32.h

Public API: pc_ring_distance_forward_u32

Contract: Return forward distance from one valid ring index to another.

Header path: include/vectrava/geometry/pc_ring_distance_forward_u32.h

## include/vectrava/geometry/pc_rotation_matrix2_from_angle_q.h

Public API: pc_rotation_matrix2_from_angle_q

Contract: Active CCW 2D rotation matrix, row-major Q1.30 coefficients.

Header path: include/vectrava/geometry/pc_rotation_matrix2_from_angle_q.h

## include/vectrava/geometry/pc_rotation_matrix3_transpose_q.h

Public API: pc_rotation_matrix3_transpose_q

Contract: Transpose a row-major 3x3 Q matrix. Input and output may be the same object. For an orthogonal rotation matrix, the result is its inverse.

Header path: include/vectrava/geometry/pc_rotation_matrix3_transpose_q.h

## include/vectrava/geometry/pc_segment_progress_q.h

Public API: pc_segment_progress_q

Contract: Return the clamped projection parameter of point P on segment A->B as unsigned Q16.16 in [0,65536]. Coordinates are int16 grid units. False on A==B or null output; failure preserves *out.

Header path: include/vectrava/geometry/pc_segment_progress_q.h

## include/vectrava/geometry/pc_size_add_checked_u32.h

Public API: pc_size_add_checked_u32

Contract: Add two uint32 size/count values. False for null output or overflow; on failure, leave *sum unchanged.

Header path: include/vectrava/geometry/pc_size_add_checked_u32.h

## include/vectrava/geometry/pc_span_contains_offset_u32.h

Public API: pc_span_contains_offset_u32

Contract: Test offset membership in a valid half-open [start, start+length) span.

Header path: include/vectrava/geometry/pc_span_contains_offset_u32.h

## include/vectrava/geometry/pc_span_contains_span_u32.h

Public API: pc_span_contains_span_u32

Contract: Check whether a valid half-open inner span is contained by an outer span.

Header path: include/vectrava/geometry/pc_span_contains_span_u32.h

## include/vectrava/geometry/pc_span_intersection_u32.h

Public API: pc_span_intersection_u32

Contract: Write the nonempty half-open intersection. False preserves both outputs.

Header path: include/vectrava/geometry/pc_span_intersection_u32.h

## include/vectrava/geometry/pc_sphere_aabb_overlap_i32.h

Public API: pc_sphere_aabb_overlap_i32

Contract: Closed sphere/AABB overlap; any inverted box axis returns false.

Header path: include/vectrava/geometry/pc_sphere_aabb_overlap_i32.h

## include/vectrava/geometry/pc_tof_distance_from_time_q.h

Public API: pc_tof_distance_from_time_q

Contract: Convert monostatic ultrasonic round-trip time to one-way distance. Time is in microseconds; sound speed is in millimetres/second; output is micrometres rounded to nearest, ties to even. Zero speed or null output fails without modifying the output.

Header path: include/vectrava/geometry/pc_tof_distance_from_time_q.h

## include/vectrava/geometry/pc_tof_time_from_distance_q.h

Public API: pc_tof_time_from_distance_q

Contract: Convert one-way distance to monostatic ultrasonic round-trip time. Distance is in micrometres; sound speed is in millimetres/second; result is microseconds rounded to nearest, ties to even. Zero speed or null output fails without modifying the output.

Header path: include/vectrava/geometry/pc_tof_time_from_distance_q.h

## include/vectrava/geometry/pc_trajectory_segment_select_u32.h

Public API: pc_trajectory_segment_select_u32

Contract: Select interval i in strictly increasing time_knots[0..count-1]. Exact interior knots select the interval to their right; endpoints clamp to the first/last segment. count must be at least 2.

Header path: include/vectrava/geometry/pc_trajectory_segment_select_u32.h

## include/vectrava/geometry/pc_translate_point2_i32.h

Public API: pc_translate_point2_i32

Contract: Add a delta to an int32 coordinate pair. False on null/aliased outputs or if either result overflows; failure preserves both output values.

Header path: include/vectrava/geometry/pc_translate_point2_i32.h

## include/vectrava/geometry/pc_vector_clamp_mag2_q.h

Public API: pc_vector_clamp_mag2_q

Contract: Limit signed-Q15 int16 vector magnitude to a nonnegative raw-Q15 radius.

Header path: include/vectrava/geometry/pc_vector_clamp_mag2_q.h

## include/vectrava/geometry/pc_vector_cross3_i32.h

Public API: pc_vector_cross3_i32

Contract: Exact cross product of two signed int32 3D vectors; output components are int64.

Header path: include/vectrava/geometry/pc_vector_cross3_i32.h

## include/vectrava/geometry/pc_vector_dominant_axis3_i32.h

Public API: pc_vector_dominant_axis3_i32

Contract: Return the lowest index whose component has greatest absolute magnitude.

Header path: include/vectrava/geometry/pc_vector_dominant_axis3_i32.h

## include/vectrava/geometry/pc_vector_rotate2_q.h

Public API: pc_vector_rotate2_q

Contract: Rotate signed-Q15 2D vector by unsigned Q0.32 turns using CORDIC; components saturate to int16.

Header path: include/vectrava/geometry/pc_vector_rotate2_q.h

## include/vectrava/geometry/pc_waypoint_distance2_i32.h

Public API: pc_waypoint_distance2_i32

Contract: Exact squared Euclidean distance between int32 coordinates. False on null output or uint64 result overflow; failure preserves *out.

Header path: include/vectrava/geometry/pc_waypoint_distance2_i32.h
