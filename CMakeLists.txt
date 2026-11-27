cmake_minimum_required(VERSION 3.16)
project(Vectrava VERSION 0.2.0 LANGUAGES C)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

option(VECTRAVA_BUILD_TESTS "Build Vectrava tests" OFF)
option(VECTRAVA_BUILD_EXAMPLES "Build Vectrava examples" OFF)
option(VECTRAVA_STRICT_WARNINGS "Treat supported compiler warnings as errors" ON)

function(vectrava_apply_warnings target)
    if(MSVC)
        target_compile_options(${target} PRIVATE /W4)
        if(VECTRAVA_STRICT_WARNINGS)
            target_compile_options(${target} PRIVATE /WX)
        endif()
    else()
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)
        if(VECTRAVA_STRICT_WARNINGS)
            target_compile_options(${target} PRIVATE -Werror)
        endif()
    endif()
endfunction()

add_library(vectrava STATIC
    src/vectrava_affine2_apply_q.c
    src/vectrava_bbox_of_points2_i32.c
    src/vectrava_bearing2_q.c
    src/vectrava_calibrate_piecewise_i32.c
    src/vectrava_checked_add_i64.c
    src/vectrava_checked_neg_i64.c
    src/vectrava_circle_aabb_overlap_i32.c
    src/vectrava_distance_to_stop_q.c
    src/vectrava_hash_probe_linear_u32.c
    src/vectrava_homogeneous2_apply_q.c
    src/vectrava_linear_interp_ratio_i32.c
    src/vectrava_linear_interp_ratio_u32.c
    src/vectrava_matrix2_add_q.c
    src/vectrava_matrix2_adjugate_q.c
    src/vectrava_matrix2_sub_q.c
    src/vectrava_matrix2_transpose_q.c
    src/vectrava_mod_interval_contains_u32.c
    src/vectrava_offset_range_check_u32.c
    src/vectrava_perpendicular_vectors2_i32.c
    src/vectrava_piecewise_segment_index_i32.c
    src/vectrava_q_hypot3.c
    src/vectrava_quat_conjugate_q.c
    src/vectrava_quat_dot_q.c
    src/vectrava_quat_from_axis_angle_q.c
    src/vectrava_quat_identity_q.c
    src/vectrava_quat_mul_q.c
    src/vectrava_quat_nlerp_q.c
    src/vectrava_quat_norm2_q.c
    src/vectrava_quat_normalize_q.c
    src/vectrava_quat_rotate_vec3_q.c
    src/vectrava_quat_sign_canonical_q.c
    src/vectrava_quat_small_angle_update_q.c
    src/vectrava_range_contains_i32.c
    src/vectrava_range_distance_i32.c
    src/vectrava_ring_distance_forward_u32.c
    src/vectrava_rotation_matrix2_from_angle_q.c
    src/vectrava_rotation_matrix3_transpose_q.c
    src/vectrava_segment_progress_q.c
    src/vectrava_size_add_checked_u32.c
    src/vectrava_span_contains_offset_u32.c
    src/vectrava_span_contains_span_u32.c
    src/vectrava_span_intersection_u32.c
    src/vectrava_sphere_aabb_overlap_i32.c
    src/vectrava_tof_distance_from_time_q.c
    src/vectrava_tof_time_from_distance_q.c
    src/vectrava_trajectory_segment_select_u32.c
    src/vectrava_translate_point2_i32.c
    src/vectrava_vector_clamp_mag2_q.c
    src/vectrava_vector_cross3_i32.c
    src/vectrava_vector_dominant_axis3_i32.c
    src/vectrava_vector_rotate2_q.c
    src/vectrava_waypoint_distance2_i32.c
)
add_library(Vectrava::Vectrava ALIAS vectrava)
target_compile_features(vectrava PUBLIC c_std_99)
set_target_properties(vectrava PROPERTIES C_STANDARD 99 C_STANDARD_REQUIRED YES C_EXTENSIONS NO EXPORT_NAME Vectrava)
target_include_directories(vectrava PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
vectrava_apply_warnings(vectrava)

if(VECTRAVA_BUILD_EXAMPLES)
    add_executable(vectrava_example_minimal examples/minimal.c)
    target_link_libraries(vectrava_example_minimal PRIVATE Vectrava::Vectrava)
    target_compile_features(vectrava_example_minimal PRIVATE c_std_99)
    set_target_properties(vectrava_example_minimal PROPERTIES C_STANDARD 99 C_STANDARD_REQUIRED YES C_EXTENSIONS NO)
    vectrava_apply_warnings(vectrava_example_minimal)
endif()

if(VECTRAVA_BUILD_TESTS)
    enable_testing()
    enable_language(CXX)
    set(VECTRAVA_TESTS
        api_gaps
        bbox_of_points2_i32
        circle_aabb_overlap_i32
        hash_probe_linear_u32
        linear_interp_ratio_i32
        linear_interp_ratio_u32
        matrix2_adjugate_q
        matrix2_sub_q
        matrix2_transpose_q
        mod_interval_contains_u32
        mod_interval_contains_u32_extra2
        perpendicular_vectors2_i32
        perpendicular_vectors2_i32_extra2
        quat_conjugate_q
        quat_dot_q
        quat_from_axis_angle_q
        quat_identity_q
        quat_mul_q
        quat_nlerp_q
        quat_norm2_q
        quat_normalize_q
        quat_rotate_vec3_q
        quat_sign_canonical_q
        quat_small_angle_update_q
        range_contains_i32
        range_distance_i32
        rotation_matrix2_from_angle_q
        rotation_matrix3_transpose_q
        span_contains_offset_u32
        span_contains_span_u32
        span_intersection_u32
        sphere_aabb_overlap_i32
        vector_clamp_mag2_q
        vector_cross3_i32
        vector_dominant_axis3_i32
        vector_rotate2_q
    )
    foreach(test_name IN LISTS VECTRAVA_TESTS)
        add_executable(vectrava_test_${test_name} tests/test_${test_name}.c)
        target_link_libraries(vectrava_test_${test_name} PRIVATE Vectrava::Vectrava)
        target_compile_features(vectrava_test_${test_name} PRIVATE c_std_99)
        set_target_properties(vectrava_test_${test_name} PROPERTIES C_STANDARD 99 C_STANDARD_REQUIRED YES C_EXTENSIONS NO)
        # Keep assert-based legacy checks active with NDEBUG in Release.
        if(MSVC)
            target_compile_options(vectrava_test_${test_name} PRIVATE /UNDEBUG)
        else()
            target_compile_options(vectrava_test_${test_name} PRIVATE -UNDEBUG)
        endif()
        vectrava_apply_warnings(vectrava_test_${test_name})
        if(test_name STREQUAL "api_gaps" AND UNIX)
            target_link_libraries(vectrava_test_${test_name} PRIVATE m)
        endif()
        add_test(NAME vectrava.${test_name} COMMAND vectrava_test_${test_name})
    endforeach()
    set(VECTRAVA_PUBLIC_HEADERS
        affine2_apply_q.h
        bbox_of_points2_i32.h
        bearing2_q.h
        calibrate_piecewise_i32.h
        checked_add_i64.h
        checked_neg_i64.h
        circle_aabb_overlap_i32.h
        distance_to_stop_q.h
        hash_probe_linear_u32.h
        homogeneous2_apply_q.h
        linear_interp_ratio_i32.h
        linear_interp_ratio_u32.h
        matrix2_add_q.h
        matrix2_adjugate_q.h
        matrix2_q.h
        matrix3_q.h
        matrix2_sub_q.h
        matrix2_transpose_q.h
        mod_interval_contains_u32.h
        offset_range_check_u32.h
        perpendicular_vectors2_i32.h
        piecewise_segment_index_i32.h
        q_hypot3.h
        quat_conjugate_q.h
        quat_dot_q.h
        quat_from_axis_angle_q.h
        quat_identity_q.h
        quat_mul_q.h
        quat_nlerp_q.h
        quat_norm2_q.h
        quat_normalize_q.h
        quat_rotate_vec3_q.h
        quat_sign_canonical_q.h
        quat_small_angle_update_q.h
        range_contains_i32.h
        range_distance_i32.h
        ring_distance_forward_u32.h
        rotation_matrix2_from_angle_q.h
        rotation_matrix3_transpose_q.h
        segment_progress_q.h
        size_add_checked_u32.h
        span_contains_offset_u32.h
        span_contains_span_u32.h
        span_intersection_u32.h
        sphere_aabb_overlap_i32.h
        tof_distance_from_time_q.h
        tof_time_from_distance_q.h
        trajectory_segment_select_u32.h
        translate_point2_i32.h
        vector_clamp_mag2_q.h
        vector_cross3_i32.h
        vector_dominant_axis3_i32.h
        vector_rotate2_q.h
        waypoint_distance2_i32.h
    )
    foreach(header IN LISTS VECTRAVA_PUBLIC_HEADERS)
        string(REPLACE ".h" "" header_test_name "${header}")
        set(header_smoke_source "${CMAKE_CURRENT_BINARY_DIR}/header_${header_test_name}.c")
        file(WRITE "${header_smoke_source}" "#include <vectrava/geometry/${header}>\nint main(void) { return 0; }\n")
        add_executable(vectrava_header_${header_test_name} "${header_smoke_source}")
        target_link_libraries(vectrava_header_${header_test_name} PRIVATE Vectrava::Vectrava)
        target_compile_features(vectrava_header_${header_test_name} PRIVATE c_std_99)
        set_target_properties(vectrava_header_${header_test_name} PROPERTIES C_STANDARD 99 C_STANDARD_REQUIRED YES C_EXTENSIONS NO)
        vectrava_apply_warnings(vectrava_header_${header_test_name})
        add_test(NAME vectrava.header.${header_test_name} COMMAND vectrava_header_${header_test_name})
    endforeach()
    set(VECTRAVA_CPP_SMOKE "")
    foreach(header IN LISTS VECTRAVA_PUBLIC_HEADERS)
        string(APPEND VECTRAVA_CPP_SMOKE "#include <vectrava/geometry/${header}>\n")
    endforeach()
    string(APPEND VECTRAVA_CPP_SMOKE "int main() { int64_t result = 0; return vectrava_checked_add_i64(2, 3, &result) && result == 5 ? 0 : 1; }\n")
    file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/headers_cpp.cpp" "${VECTRAVA_CPP_SMOKE}")
    add_executable(vectrava_headers_cpp "${CMAKE_CURRENT_BINARY_DIR}/headers_cpp.cpp")
    target_link_libraries(vectrava_headers_cpp PRIVATE Vectrava::Vectrava)
    vectrava_apply_warnings(vectrava_headers_cpp)
    add_test(NAME vectrava.headers_cpp COMMAND vectrava_headers_cpp)
endif()

install(TARGETS vectrava EXPORT VectravaTargets ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT VectravaTargets FILE VectravaTargets.cmake NAMESPACE Vectrava:: DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Vectrava)
configure_package_config_file(cmake/VectravaConfig.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/VectravaConfig.cmake INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Vectrava)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/VectravaConfigVersion.cmake VERSION ${PROJECT_VERSION} COMPATIBILITY SameMinorVersion)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/VectravaConfig.cmake ${CMAKE_CURRENT_BINARY_DIR}/VectravaConfigVersion.cmake DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Vectrava)
