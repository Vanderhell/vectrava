# Architecture

Vectrava is a static C99 library with 52 callable operations in independent
source units. The 54 public headers include two shared matrix type definitions.
State is explicit and caller-owned; there is no runtime initialization,
mandatory allocation, OS service, or external runtime dependency.

CMake exposes the `vectrava` static target and a `VECTRAVA_BUILD_TESTS` option.
Consumers can include `<vectrava/geometry/pc_name.h>` through the public
`include/` path, or compile only a selected `src/pc_name.c` translation unit.
The older direct geometry include directory remains available for source
compatibility.

Numerical functions document their fixed-point scales, rounding, saturation,
range checks, and failure output behavior in their headers. Temporary arrays
are used where transactional output or supported aliasing requires them.
The 64-bit integer intermediates are bounded by their API input ranges; CI
checks strict compiler diagnostics and offers ASan/UBSan runs on GCC/Clang.
The exact compiler and sanitizer evidence for this checkout is in
[TESTING.md](TESTING.md). Hardware-specific timing or footprint claims are not
made without target measurements.
