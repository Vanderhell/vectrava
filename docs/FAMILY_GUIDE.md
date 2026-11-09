# Vectrava family guide

## What this family solves

**Geometry and transforms.** Vectors, ranges, transforms, quaternions, bounding volumes and spatial calculations.

This guide describes the complete public family as an independent embedded-C product. Each primitive remains separately linkable; select only the headers and source units required by the application.

## When to use this family

Use Vectrava when the application needs the operations listed below and requires deterministic behavior, explicit caller-owned memory, and no mandatory operating-system services.

## Family at a glance

```mermaid
flowchart LR
    A[Application input] --> B[Validate representation and bounds]
    B --> C[Select one public primitive]
    C --> D[Check status or output contract]
    D --> E[Use result with documented units]
```

## Primitive map

| Public header | Symbol | Purpose and contract | Validation source |
|---|---|---|---|
| `include/vectrava/geometry/pc_affine2_apply_q.h` | `pc_affine2_apply_q` | Apply a row-major 2x2 Q matrix and Q translation. Each dot product is rounded nearest-even once. False on invalid pointers/fractional_bits or result overflow; failure preserves output. Output may alias point/translation. | No enabled test source was found by symbol search. |
| `include/vectrava/geometry/pc_bbox_of_points2_i32.h` | `pc_bbox_of_points2_i32` | Compute the closed AABB of count points. Reject null pointers or count==0; on failure, preserve *bounds. The input array is read-only. | tests/test_001_bbox_of_points2_i32.c |
| `include/vectrava/geometry/pc_bearing2_q.h` | `pc_bearing2_q` | CORDIC estimate of bearing from an int32 origin to target as unsigned Q0.32 turns CCW from +X. Equal points return zero. Coordinates need not share a specific Q scale. Differential tests observed <= 16 phase-code error; this empirical limit is not a formal global bound. | No enabled test source was found by symbol search. |
| `include/vectrava/geometry/pc_calibrate_piecewise_i32.h` | `pc_calibrate_piecewise_i32` | Piecewise-linear map, clamp beyond endpoints, nearest/ties-away rounding. Count is 2..255; input knots must be strictly increasing. | No enabled test source was found by symbol search. |
| `include/vectrava/geometry/pc_circle_aabb_overlap_i32.h` | `pc_circle_aabb_overlap_i32` | Closed circle/AABB overlap; inverted box bounds return false. | tests/test_002_circle_aabb_overlap_i32.c |
| `include/vectrava/geometry/pc_distance_to_stop_q.h` | `pc_distance_to_stop_q` | Constant-deceleration stopping distance: ceil(/v/^2/(2*a)). Velocity is signed Q16.16 units/s, positive braking deceleration is Q16.16 units/s^2, result is unsigned Q16.16 distance. Zero speed returns 0; nonzero speed with zero deceleration fails atomically. | No enabled test source was found by symbol search. |
| `include/vectrava/geometry/pc_hash_probe_linear_u32.h` | `pc_hash_probe_linear_u32` | Return (start + ordinal) modulo capacity without uint32 overflow. Requires capacity > 0 and start < capacity; failure preserves *index. | tests/test_003_hash_probe_linear_u32.c |
| `include/vectrava/geometry/pc_homogeneous2_apply_q.h` | `pc_homogeneous2_apply_q` | Apply a row-major 3x3 Q matrix to a homogeneous 3-vector. Each row dot product is rounded nearest-even once. Returns homogeneous output; it does not divide by W. False preserves output. Output may alias matrix/vector. | No enabled test source was found by symbol search. |
| `include/vectrava/geometry/pc_checked_add_i64.h` | `pc_checked_add_i64` | Store a+b exactly. False for null output or signed overflow; failure writes nothing to result. | No enabled test source was found by symbol search. |
| `include/vectrava/geometry/pc_checked_neg_i64.h` | `pc_checked_neg_i64` | Store -value exactly; false for null output or INT64_MIN, preserving output. | tests/test_006_matrix2_adjugate_q.c |
| `include/vectrava/geometry/pc_linear_interp_ratio_i32.h` | `pc_linear_interp_ratio_i32` | Convex interpolation at numerator/denominator in [0,1]. The exact result rounds to nearest, ties-to-even. Invalid ratio/output preserves *result. | tests/test_004_linear_interp_ratio_i32.c |
| `include/vectrava/geometry/pc_linear_interp_ratio_u32.h` | `pc_linear_interp_ratio_u32` | Convex interpolation for a ratio in [0,1]. Rounds nearest, ties-to-even; invalid ratios or output pointer preserve *result. | tests/test_005_linear_interp_ratio_u32.c |
| `include/vectrava/geometry/pc_matrix2_add_q.h` | `pc_matrix2_add_q` | Exact elementwise addition. On any component overflow, write nothing. | tests/test_007_matrix2_sub_q.c |
| `include/vectrava/geometry/pc_matrix2_adjugate_q.h` | `pc_matrix2_adjugate_q` | Adjugate [[a,b],[c,d]] to [[d,-b],[-c,a]], checked and alias-safe. | tests/test_006_matrix2_adjugate_q.c |
| `include/vectrava/geometry/pc_matrix2_q.h` | `pc_matrix2_q` | Row-major 2x2 signed Q matrix; all elements share one caller-selected scale. | No enabled test source was found by symbol search. |
| `include/vectrava/geometry/pc_matrix2_sub_q.h` | `pc_matrix2_sub_q` | Exact elementwise subtraction. On any component overflow, write nothing. | tests/test_007_matrix2_sub_q.c |
| `include/vectrava/geometry/pc_matrix2_transpose_q.h` | `pc_matrix2_transpose_q` | Transpose a row-major 2x2 Q matrix; result may alias input. | tests/test_008_matrix2_transpose_q.c |
| `include/vectrava/geometry/pc_matrix3_q.h` | `pc_matrix3_q` | The public header contains the authoritative signature and input/output contract. | No enabled test source was found by symbol search. |
| `include/vectrava/geometry/pc_mod_interval_contains_u32.h` | `pc_mod_interval_contains_u32` | Closed forward arc on the uint32_t ring; equal endpoints denote one point. | tests/test_009_mod_interval_contains_u32.c |
| `include/vectrava/geometry/pc_offset_range_check_u32.h` | `pc_offset_range_check_u32` | Check the half-open span [offset, offset + length) against capacity. An empty span at offset == capacity is valid. | tests/test_029_span_contains_span_u32.c |
| `include/vectrava/geometry/pc_perpendicular_vectors2_i32.h` | `pc_perpendicular_vectors2_i32` | True iff the exact dot product of the two int32 vectors is zero. A zero vector is perpendicular to every vector under this definition. | tests/test_011_perpendicular_vectors2_i32.c |
| `include/vectrava/geometry/pc_piecewise_segment_index_i32.h` | `pc_piecewise_segment_index_i32` | Find clamped interval i for strictly increasing points[].input, count 2..255. Segment i spans knot i to i+1; exact interior knots select the segment to their right, and endpoints/outside clamp to [0,count-2]. | No enabled test source was found by symbol search. |
| `include/vectrava/geometry/pc_q_hypot3.h` | `pc_q_hypot3` | Nearest-even Euclidean norm of three same-scale signed Q raw values. False on null output or int32 overflow; failure preserves *out. | No enabled test source was found by symbol search. |
| `include/vectrava/geometry/pc_quat_conjugate_q.h` | `pc_quat_conjugate_q` | Conjugate scalar-first Q1.30 quaternion; reject unnegatable INT32_MIN. | tests/test_013_quat_conjugate_q.c |
| `include/vectrava/geometry/pc_quat_dot_q.h` | `pc_quat_dot_q` | Dot scalar-first Q1.30 quaternion components in [-1,1]; round to Q1.30. | tests/test_014_quat_dot_q.c |
| `include/vectrava/geometry/pc_quat_from_axis_angle_q.h` | `pc_quat_from_axis_angle_q` | Q0.32 full-turn angle and nonzero Q1.30 axis -> scalar-first Q1.30 quaternion. | tests/test_015_quat_from_axis_angle_q.c |
| `include/vectrava/geometry/pc_quat_identity_q.h` | `pc_quat_identity_q` | Store scalar-first Q1.30 identity quaternion [w, x, y, z]. | tests/test_016_quat_identity_q.c |
| `include/vectrava/geometry/pc_quat_mul_q.h` | `pc_quat_mul_q` | Hamilton product of scalar-first Q1.30 quaternions with components in [-1,1]. | tests/test_017_quat_mul_q.c |
| `include/vectrava/geometry/pc_quat_nlerp_q.h` | `pc_quat_nlerp_q` | Shortest-path normalized lerp; scalar-first Q1.30, ratio numerator/denominator. | tests/test_018_quat_nlerp_q.c |
| `include/vectrava/geometry/pc_quat_norm2_q.h` | `pc_quat_norm2_q` | Exact sum of squares for scalar-first Q1.30 quaternion in [-1,1]^4. | tests/test_019_quat_norm2_q.c |
| `include/vectrava/geometry/pc_quat_normalize_q.h` | `pc_quat_normalize_q` | Normalize scalar-first Q1.30 quaternion; reject zero and preserve output. | tests/test_020_quat_normalize_q.c |
| `include/vectrava/geometry/pc_quat_rotate_vec3_q.h` | `pc_quat_rotate_vec3_q` | Rotate a Q1.30 vector whose components are in [-1,1] by a scalar-first quaternion. The nonzero quaternion is normalized internally. | tests/test_021_quat_rotate_vec3_q.c |
| `include/vectrava/geometry/pc_quat_sign_canonical_q.h` | `pc_quat_sign_canonical_q` | Canonicalize q/-q by making the first nonzero scalar-first component positive. Components must be in the inclusive Q1.30 range [-1,1]. | tests/test_022_quat_sign_canonical_q.c |
| `include/vectrava/geometry/pc_quat_small_angle_update_q.h` | `pc_quat_small_angle_update_q` | Apply a body-frame gyro sample (Q16.16 rad/s) over dt microseconds. Rejects when /gyro/*dt exceeds 0.01 rad; intended for small high-rate steps. | tests/test_023_quat_small_angle_update_q.c |
| `include/vectrava/geometry/pc_range_contains_i32.h` | `pc_range_contains_i32` | Closed interval predicate. An inverted interval returns false. | tests/test_024_range_contains_i32.c |
| `include/vectrava/geometry/pc_range_distance_i32.h` | `pc_range_distance_i32` | Distance from value to closed interval; zero inside; inverted interval fails. | tests/test_025_range_distance_i32.c |
| `include/vectrava/geometry/pc_ring_distance_forward_u32.h` | `pc_ring_distance_forward_u32` | Return forward distance from one valid ring index to another. | No enabled test source was found by symbol search. |
| `include/vectrava/geometry/pc_rotation_matrix2_from_angle_q.h` | `pc_rotation_matrix2_from_angle_q` | Active CCW 2D rotation matrix, row-major Q1.30 coefficients. | tests/test_026_rotation_matrix2_from_angle_q.c |
| `include/vectrava/geometry/pc_rotation_matrix3_transpose_q.h` | `pc_rotation_matrix3_transpose_q` | Transpose a row-major 3x3 Q matrix. Input and output may be the same object. For an orthogonal rotation matrix, the result is its inverse. | tests/test_027_rotation_matrix3_transpose_q.c |
| `include/vectrava/geometry/pc_segment_progress_q.h` | `pc_segment_progress_q` | Return the clamped projection parameter of point P on segment A->B as unsigned Q16.16 in [0,65536]. Coordinates are int16 grid units. False on A==B or null output; failure preserves *out. | No enabled test source was found by symbol search. |
| `include/vectrava/geometry/pc_size_add_checked_u32.h` | `pc_size_add_checked_u32` | Add two uint32 size/count values. False for null output or overflow; on failure, leave *sum unchanged. | tests/test_028_span_contains_offset_u32.c |
| `include/vectrava/geometry/pc_span_contains_offset_u32.h` | `pc_span_contains_offset_u32` | Test offset membership in a valid half-open [start, start+length) span. | tests/test_028_span_contains_offset_u32.c |
| `include/vectrava/geometry/pc_span_contains_span_u32.h` | `pc_span_contains_span_u32` | Check whether a valid half-open inner span is contained by an outer span. | tests/test_029_span_contains_span_u32.c |
| `include/vectrava/geometry/pc_span_intersection_u32.h` | `pc_span_intersection_u32` | Write the nonempty half-open intersection. False preserves both outputs. | tests/test_030_span_intersection_u32.c |
| `include/vectrava/geometry/pc_sphere_aabb_overlap_i32.h` | `pc_sphere_aabb_overlap_i32` | Closed sphere/AABB overlap; any inverted box axis returns false. | tests/test_031_sphere_aabb_overlap_i32.c |
| `include/vectrava/geometry/pc_tof_distance_from_time_q.h` | `pc_tof_distance_from_time_q` | Convert monostatic ultrasonic round-trip time to one-way distance. Time is in microseconds; sound speed is in millimetres/second; output is micrometres rounded to nearest, ties to even. Zero speed or null output fails without modifying the output. | No enabled test source was found by symbol search. |
| `include/vectrava/geometry/pc_tof_time_from_distance_q.h` | `pc_tof_time_from_distance_q` | Convert one-way distance to monostatic ultrasonic round-trip time. Distance is in micrometres; sound speed is in millimetres/second; result is microseconds rounded to nearest, ties to even. Zero speed or null output fails without modifying the output. | No enabled test source was found by symbol search. |
| `include/vectrava/geometry/pc_trajectory_segment_select_u32.h` | `pc_trajectory_segment_select_u32` | Select interval i in strictly increasing time_knots[0..count-1]. Exact interior knots select the interval to their right; endpoints clamp to the first/last segment. count must be at least 2. | No enabled test source was found by symbol search. |
| `include/vectrava/geometry/pc_translate_point2_i32.h` | `pc_translate_point2_i32` | Add a delta to an int32 coordinate pair. False on null/aliased outputs or if either result overflows; failure preserves both output values. | No enabled test source was found by symbol search. |
| `include/vectrava/geometry/pc_vector_clamp_mag2_q.h` | `pc_vector_clamp_mag2_q` | Limit signed-Q15 int16 vector magnitude to a nonnegative raw-Q15 radius. | tests/test_032_vector_clamp_mag2_q.c |
| `include/vectrava/geometry/pc_vector_cross3_i32.h` | `pc_vector_cross3_i32` | Exact cross product of two signed int32 3D vectors; output components are int64. | tests/test_033_vector_cross3_i32.c |
| `include/vectrava/geometry/pc_vector_dominant_axis3_i32.h` | `pc_vector_dominant_axis3_i32` | Return the lowest index whose component has greatest absolute magnitude. | tests/test_034_vector_dominant_axis3_i32.c |
| `include/vectrava/geometry/pc_vector_rotate2_q.h` | `pc_vector_rotate2_q` | Rotate signed-Q15 2D vector by unsigned Q0.32 turns using CORDIC; components saturate to int16. | tests/test_035_vector_rotate2_q.c |
| `include/vectrava/geometry/pc_waypoint_distance2_i32.h` | `pc_waypoint_distance2_i32` | Exact squared Euclidean distance between int32 coordinates. False on null output or uint64 result overflow; failure preserves *out. | No enabled test source was found by symbol search. |

## Selection guidance

- Choose the primitive whose width, representation, rounding, saturation, wrapping, and error contract match the application.
- Do not substitute a similarly named function without checking the public header.
- Allocate state and buffers in the caller; respect documented aliasing and output-preservation rules.
- Treat entries marked without a validation source as requiring additional product-level tests before release.

## Integration checklist

1. Include only the required public header.
2. Compile the matching source translation unit or use the product CMake target.
3. Check every boolean/status return before consuming an output.
4. Add application-specific boundary tests for units, widths, invalid inputs, and overflow behavior.
5. Run the documented host tests before target integration.

## Complexity and footprint

The product is split into independent translation units. Exact flash, RAM, stack, and cycle costs depend on the selected functions, compiler, optimization, and MCU; unmeasured values remain explicitly marked PENDING in the testing documentation.

## Validation boundary

The API reference links each public entry to its implementation and available validation source. Hardware status is reported only when reproducible target evidence exists.
