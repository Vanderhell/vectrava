# Vectrava audit register

Audit scope: all 52 implemented public functions, their 54 public headers, and
all 36 test programs. `OK` means reviewed against the declared API contract and
covered by automated testing. `RISK` records a remaining unproven property;
there were no confirmed `BUG` findings in this review. Each implementation is
in `src/pc_<name>.c`; the header gives the authoritative representation,
rounding, validity, aliasing, and failure-output contract.

| API | Finding | Automated test | Evidence / remaining point |
|---|---|---|---|
| `pc_affine2_apply_q` | OK | `test_036_api_gaps.c` | Source range analysis and automated behavior tests. |
| `pc_bbox_of_points2_i32` | OK | `test_001_bbox_of_points2_i32.c` | Source range analysis and automated behavior tests. |
| `pc_bearing2_q` | RISK | `test_036_api_gaps.c` | 100,000 sampled full-range pairs measured 6 Q0.32 phase codes maximum; no global proof. |
| `pc_calibrate_piecewise_i32` | OK | `test_036_api_gaps.c` | Source range analysis and automated behavior tests. |
| `pc_checked_add_i64` | OK | `test_036_api_gaps.c` | Source range analysis and automated behavior tests. |
| `pc_checked_neg_i64` | OK | `test_006_matrix2_adjugate_q.c` | Source range analysis and automated behavior tests. |
| `pc_circle_aabb_overlap_i32` | OK | `test_002_circle_aabb_overlap_i32.c` | Source range analysis and automated behavior tests. |
| `pc_distance_to_stop_q` | OK | `test_036_api_gaps.c` | Source range analysis and automated behavior tests. |
| `pc_hash_probe_linear_u32` | OK | `test_003_hash_probe_linear_u32.c` | Source range analysis and automated behavior tests. |
| `pc_homogeneous2_apply_q` | OK | `test_036_api_gaps.c` | Source range analysis and automated behavior tests. |
| `pc_linear_interp_ratio_i32` | OK | `test_004_linear_interp_ratio_i32.c` | Source range analysis and automated behavior tests. |
| `pc_linear_interp_ratio_u32` | OK | `test_005_linear_interp_ratio_u32.c` | Source range analysis and automated behavior tests. |
| `pc_matrix2_add_q` | OK | `test_007_matrix2_sub_q.c` | Source range analysis and automated behavior tests. |
| `pc_matrix2_adjugate_q` | OK | `test_006_matrix2_adjugate_q.c` | Source range analysis and automated behavior tests. |
| `pc_matrix2_sub_q` | OK | `test_007_matrix2_sub_q.c` | Source range analysis and automated behavior tests. |
| `pc_matrix2_transpose_q` | OK | `test_008_matrix2_transpose_q.c` | Source range analysis and automated behavior tests. |
| `pc_mod_interval_contains_u32` | OK | `test_009_mod_interval_contains_u32.c` | Source range analysis and automated behavior tests. |
| `pc_offset_range_check_u32` | OK | `test_029_span_contains_span_u32.c` | Source range analysis and automated behavior tests. |
| `pc_perpendicular_vectors2_i32` | OK | `test_011_perpendicular_vectors2_i32.c` | Source range analysis and automated behavior tests. |
| `pc_piecewise_segment_index_i32` | OK | `test_036_api_gaps.c` | Source range analysis and automated behavior tests. |
| `pc_quat_conjugate_q` | OK | `test_013_quat_conjugate_q.c` | Source range analysis and automated behavior tests. |
| `pc_quat_dot_q` | OK | `test_014_quat_dot_q.c` | Source range analysis and automated behavior tests. |
| `pc_quat_from_axis_angle_q` | OK | `test_015_quat_from_axis_angle_q.c` | Source range analysis and automated behavior tests. |
| `pc_quat_identity_q` | OK | `test_016_quat_identity_q.c` | Source range analysis and automated behavior tests. |
| `pc_quat_mul_q` | OK | `test_017_quat_mul_q.c` | Source range analysis and automated behavior tests. |
| `pc_quat_nlerp_q` | OK | `test_018_quat_nlerp_q.c` | Source range analysis and automated behavior tests. |
| `pc_quat_norm2_q` | OK | `test_019_quat_norm2_q.c` | Source range analysis and automated behavior tests. |
| `pc_quat_normalize_q` | OK | `test_020_quat_normalize_q.c` | Source range analysis and automated behavior tests. |
| `pc_quat_rotate_vec3_q` | OK | `test_021_quat_rotate_vec3_q.c` | Source range analysis and automated behavior tests. |
| `pc_quat_sign_canonical_q` | OK | `test_022_quat_sign_canonical_q.c` | Source range analysis and automated behavior tests. |
| `pc_quat_small_angle_update_q` | OK | `test_023_quat_small_angle_update_q.c` | Source range analysis and automated behavior tests. |
| `pc_q_hypot3` | OK | `test_036_api_gaps.c` | Source range analysis and automated behavior tests. |
| `pc_range_contains_i32` | OK | `test_024_range_contains_i32.c` | Source range analysis and automated behavior tests. |
| `pc_range_distance_i32` | OK | `test_025_range_distance_i32.c` | Source range analysis and automated behavior tests. |
| `pc_ring_distance_forward_u32` | OK | `test_036_api_gaps.c` | Source range analysis and automated behavior tests. |
| `pc_rotation_matrix2_from_angle_q` | OK | `test_026_rotation_matrix2_from_angle_q.c` | Source range analysis and automated behavior tests. |
| `pc_rotation_matrix3_transpose_q` | OK | `test_027_rotation_matrix3_transpose_q.c` | Source range analysis and automated behavior tests. |
| `pc_segment_progress_q` | OK | `test_036_api_gaps.c` | Source range analysis and automated behavior tests. |
| `pc_size_add_checked_u32` | OK | `test_028_span_contains_offset_u32.c` | Source range analysis and automated behavior tests. |
| `pc_span_contains_offset_u32` | OK | `test_028_span_contains_offset_u32.c` | Source range analysis and automated behavior tests. |
| `pc_span_contains_span_u32` | OK | `test_029_span_contains_span_u32.c` | Source range analysis and automated behavior tests. |
| `pc_span_intersection_u32` | OK | `test_030_span_intersection_u32.c` | Source range analysis and automated behavior tests. |
| `pc_sphere_aabb_overlap_i32` | OK | `test_031_sphere_aabb_overlap_i32.c` | Source range analysis and automated behavior tests. |
| `pc_tof_distance_from_time_q` | OK | `test_036_api_gaps.c` | Source range analysis and automated behavior tests. |
| `pc_tof_time_from_distance_q` | OK | `test_036_api_gaps.c` | Source range analysis and automated behavior tests. |
| `pc_trajectory_segment_select_u32` | OK | `test_036_api_gaps.c` | Source range analysis and automated behavior tests. |
| `pc_translate_point2_i32` | OK | `test_036_api_gaps.c` | Source range analysis and automated behavior tests. |
| `pc_vector_clamp_mag2_q` | OK | `test_032_vector_clamp_mag2_q.c` | Source range analysis and automated behavior tests. |
| `pc_vector_cross3_i32` | OK | `test_033_vector_cross3_i32.c` | Source range analysis and automated behavior tests. |
| `pc_vector_dominant_axis3_i32` | OK | `test_034_vector_dominant_axis3_i32.c` | Source range analysis and automated behavior tests. |
| `pc_vector_rotate2_q` | OK | `test_035_vector_rotate2_q.c` | Source range analysis and automated behavior tests. |
| `pc_waypoint_distance2_i32` | OK | `test_036_api_gaps.c` | Source range analysis and automated behavior tests. |
## Audit-wide checks

- Checked signed arithmetic uses widened or explicit checked operations; reviewed
  vector products, squared distances, and range deltas against full input bounds.
- Fixed-point conversion and interpolation tests exercise rounding, saturation,
  invalid parameters, output preservation, and supported aliases where declared.
- CORDIC bearing covers all eight octants and 100,000 seeded full-range pairs
  against `atan2l`; the measured maximum was 6 Q0.32 phase codes (test threshold 24).
- `pc_q_hypot3` covers 100,000 seeded signed triples against independent
  long-double square roots with nearest-even rounding and int32 overflow checks.
- Axis-angle CORDIC sine/cosine measured 17 Q1.30 component codes maximum over
  100,000 seeded phases (threshold 20); Q1.30 errors are near the Q30 LSB.
- Quaternion normalization, multiplication, rotation, interpolation, and small
  updates retain their independent regression sources and randomized checks.
- GCC strict passed 36/36; MSVC Debug and Release passed 33/33 each; Clang-cl
  strict passed 33/33. Three `__int128` oracle tests are optional and excluded
  on MSVC. ASan and UBSan each passed 33/33 tests under Clang 22. ESP32-S3 remains HW NOT VERIFIED.

`RISK` is not a demonstrated bug. Formal worst-case error proofs for the CORDIC
approximations and hardware-target evidence remain open. Sanitizer runs passed.
No implementation algorithm was changed because no reproducible product
defect was confirmed. See [TESTING.md](TESTING.md) for commands and full status.
