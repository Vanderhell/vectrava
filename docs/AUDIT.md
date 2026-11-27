# Vectrava audit register

Audit scope: all 52 implemented public functions, their 54 public headers, and
all 36 test programs. `OK` means reviewed against the declared API contract and
covered by automated testing. `RISK` records a remaining unproven property;
there were no confirmed `BUG` findings in this review. Each implementation is
in `src/vectrava_<name>.c`; the header gives the authoritative representation,
rounding, validity, aliasing, and failure-output contract.

| API | Finding | Automated test | Evidence / remaining point |
|---|---|---|---|
| `vectrava_affine2_apply_q` | OK | `test_api_gaps.c` | Source range analysis and automated behavior tests. |
| `vectrava_bbox_of_points2_i32` | OK | `test_bbox_of_points2_i32.c` | Source range analysis and automated behavior tests. |
| `vectrava_bearing2_q` | RISK | `test_api_gaps.c` | 100,000 sampled full-range pairs measured 6 Q0.32 phase codes maximum; no global proof. |
| `vectrava_calibrate_piecewise_i32` | OK | `test_api_gaps.c` | Source range analysis and automated behavior tests. |
| `vectrava_checked_add_i64` | OK | `test_api_gaps.c` | Source range analysis and automated behavior tests. |
| `vectrava_checked_neg_i64` | OK | `test_matrix2_adjugate_q.c` | Source range analysis and automated behavior tests. |
| `vectrava_circle_aabb_overlap_i32` | OK | `test_circle_aabb_overlap_i32.c` | Source range analysis and automated behavior tests. |
| `vectrava_distance_to_stop_q` | OK | `test_api_gaps.c` | Source range analysis and automated behavior tests. |
| `vectrava_hash_probe_linear_u32` | OK | `test_hash_probe_linear_u32.c` | Source range analysis and automated behavior tests. |
| `vectrava_homogeneous2_apply_q` | OK | `test_api_gaps.c` | Source range analysis and automated behavior tests. |
| `vectrava_linear_interp_ratio_i32` | OK | `test_linear_interp_ratio_i32.c` | Source range analysis and automated behavior tests. |
| `vectrava_linear_interp_ratio_u32` | OK | `test_linear_interp_ratio_u32.c` | Source range analysis and automated behavior tests. |
| `vectrava_matrix2_add_q` | OK | `test_matrix2_sub_q.c` | Source range analysis and automated behavior tests. |
| `vectrava_matrix2_adjugate_q` | OK | `test_matrix2_adjugate_q.c` | Source range analysis and automated behavior tests. |
| `vectrava_matrix2_sub_q` | OK | `test_matrix2_sub_q.c` | Source range analysis and automated behavior tests. |
| `vectrava_matrix2_transpose_q` | OK | `test_matrix2_transpose_q.c` | Source range analysis and automated behavior tests. |
| `vectrava_mod_interval_contains_u32` | OK | `test_mod_interval_contains_u32.c` | Source range analysis and automated behavior tests. |
| `vectrava_offset_range_check_u32` | OK | `test_span_contains_span_u32.c` | Source range analysis and automated behavior tests. |
| `vectrava_perpendicular_vectors2_i32` | OK | `test_perpendicular_vectors2_i32.c` | Source range analysis and automated behavior tests. |
| `vectrava_piecewise_segment_index_i32` | OK | `test_api_gaps.c` | Source range analysis and automated behavior tests. |
| `vectrava_quat_conjugate_q` | OK | `test_quat_conjugate_q.c` | Source range analysis and automated behavior tests. |
| `vectrava_quat_dot_q` | OK | `test_quat_dot_q.c` | Source range analysis and automated behavior tests. |
| `vectrava_quat_from_axis_angle_q` | OK | `test_quat_from_axis_angle_q.c` | Source range analysis and automated behavior tests. |
| `vectrava_quat_identity_q` | OK | `test_quat_identity_q.c` | Source range analysis and automated behavior tests. |
| `vectrava_quat_mul_q` | OK | `test_quat_mul_q.c` | Source range analysis and automated behavior tests. |
| `vectrava_quat_nlerp_q` | OK | `test_quat_nlerp_q.c` | Source range analysis and automated behavior tests. |
| `vectrava_quat_norm2_q` | OK | `test_quat_norm2_q.c` | Source range analysis and automated behavior tests. |
| `vectrava_quat_normalize_q` | OK | `test_quat_normalize_q.c` | Source range analysis and automated behavior tests. |
| `vectrava_quat_rotate_vec3_q` | OK | `test_quat_rotate_vec3_q.c` | Source range analysis and automated behavior tests. |
| `vectrava_quat_sign_canonical_q` | OK | `test_quat_sign_canonical_q.c` | Source range analysis and automated behavior tests. |
| `vectrava_quat_small_angle_update_q` | OK | `test_quat_small_angle_update_q.c` | Source range analysis and automated behavior tests. |
| `vectrava_q_hypot3` | OK | `test_api_gaps.c` | Source range analysis and automated behavior tests. |
| `vectrava_range_contains_i32` | OK | `test_range_contains_i32.c` | Source range analysis and automated behavior tests. |
| `vectrava_range_distance_i32` | OK | `test_range_distance_i32.c` | Source range analysis and automated behavior tests. |
| `vectrava_ring_distance_forward_u32` | OK | `test_api_gaps.c` | Source range analysis and automated behavior tests. |
| `vectrava_rotation_matrix2_from_angle_q` | OK | `test_rotation_matrix2_from_angle_q.c` | Source range analysis and automated behavior tests. |
| `vectrava_rotation_matrix3_transpose_q` | OK | `test_rotation_matrix3_transpose_q.c` | Source range analysis and automated behavior tests. |
| `vectrava_segment_progress_q` | OK | `test_api_gaps.c` | Source range analysis and automated behavior tests. |
| `vectrava_size_add_checked_u32` | OK | `test_span_contains_offset_u32.c` | Source range analysis and automated behavior tests. |
| `vectrava_span_contains_offset_u32` | OK | `test_span_contains_offset_u32.c` | Source range analysis and automated behavior tests. |
| `vectrava_span_contains_span_u32` | OK | `test_span_contains_span_u32.c` | Source range analysis and automated behavior tests. |
| `vectrava_span_intersection_u32` | OK | `test_span_intersection_u32.c` | Source range analysis and automated behavior tests. |
| `vectrava_sphere_aabb_overlap_i32` | OK | `test_sphere_aabb_overlap_i32.c` | Source range analysis and automated behavior tests. |
| `vectrava_tof_distance_from_time_q` | OK | `test_api_gaps.c` | Source range analysis and automated behavior tests. |
| `vectrava_tof_time_from_distance_q` | OK | `test_api_gaps.c` | Source range analysis and automated behavior tests. |
| `vectrava_trajectory_segment_select_u32` | OK | `test_api_gaps.c` | Source range analysis and automated behavior tests. |
| `vectrava_translate_point2_i32` | OK | `test_api_gaps.c` | Source range analysis and automated behavior tests. |
| `vectrava_vector_clamp_mag2_q` | OK | `test_vector_clamp_mag2_q.c` | Source range analysis and automated behavior tests. |
| `vectrava_vector_cross3_i32` | OK | `test_vector_cross3_i32.c` | Source range analysis and automated behavior tests. |
| `vectrava_vector_dominant_axis3_i32` | OK | `test_vector_dominant_axis3_i32.c` | Source range analysis and automated behavior tests. |
| `vectrava_vector_rotate2_q` | OK | `test_vector_rotate2_q.c` | Source range analysis and automated behavior tests. |
| `vectrava_waypoint_distance2_i32` | OK | `test_api_gaps.c` | Source range analysis and automated behavior tests. |
## Audit-wide checks

- Checked signed arithmetic uses widened or explicit checked operations; reviewed
  vector products, squared distances, and range deltas against full input bounds.
- Fixed-point conversion and interpolation tests exercise rounding, saturation,
  invalid parameters, output preservation, and supported aliases where declared.
- CORDIC bearing covers all eight octants and 100,000 seeded full-range pairs
  against `atan2l`; the measured maximum was 6 Q0.32 phase codes (test threshold 24).
- `vectrava_q_hypot3` covers 100,000 seeded signed triples against independent
  long-double square roots with nearest-even rounding and int32 overflow checks.
- Axis-angle CORDIC sine/cosine measured 17 Q1.30 component codes maximum over
  100,000 seeded phases (threshold 20); Q1.30 errors are near the Q30 LSB.
- Quaternion normalization, multiplication, rotation, interpolation, and small
  updates retain their independent regression sources and randomized checks.
- The current product tree has 52 directly tested callable APIs, 54 public
  headers, 36 behavior executables, 54 standalone C header builds and one C++
  aggregate-header/link test (91 CTest entries). GCC 16.1, MSVC 19.42 and
  ClangCL 19.1.5 Debug and Release each passed 91/91 with strict warnings.
- The former ClangCL failure was in test-only `__int128` oracle linkage. A
  portable independent exact reference is now used for that compiler. No
  production algorithm was changed. GCC/Clang Linux sanitizer results for
  this revision are pending its remote CI run; local Windows sanitizer runs
  were not performed.
- Historical ESP32-S3 evidence covers selected bearing, 2D rotation and
  quaternion identity checks on an earlier source revision at 240 MHz. It
  does not cover all APIs and is not current-revision hardware validation.
  Current hardware testing and performance/footprint measurements are
  **NOT VERIFIED / NOT MEASURED**.

`RISK` is not a demonstrated bug. Formal worst-case error proofs for the CORDIC
approximations and full hardware API coverage remain open. Representative hardware checks and sanitizer runs passed.
No implementation algorithm was changed because no reproducible product
defect was confirmed. See [TESTING.md](TESTING.md) for commands and full status.
