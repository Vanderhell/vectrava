# Testing and validation

## Coverage

The public surface contains 52 callable C functions and two public matrix-type
headers. Each function has a direct test invocation in `tests/`; the enabled
suite also compiles every public header independently as C and all public
headers together as C++. Test executables keep `assert` enabled in Release so
existing assertions are evaluated with `NDEBUG` build configurations.

The suite consists of 36 behavior test programs, 54 standalone C header smoke
tests and one C++ aggregate-header/link smoke test: 91 CTest entries total.
The 36 behavior programs retain the original cases and add direct coverage for
the previously uncovered operations. Differential references are separate
from production code. Some oracle cases use `long double`; the available
precision is implementation-dependent and does not constitute a formal error
bound.

## Reproduce

```sh
cmake -S . -B build -DVECTRAVA_BUILD_TESTS=ON -DVECTRAVA_STRICT_WARNINGS=ON -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel
ctest --test-dir build --output-on-failure -C Debug

cmake -S . -B build-release -DVECTRAVA_BUILD_TESTS=ON -DVECTRAVA_STRICT_WARNINGS=ON -DCMAKE_BUILD_TYPE=Release
cmake --build build-release --parallel
ctest --test-dir build-release --output-on-failure -C Release
```

GCC or Clang sanitizer builds can be run separately:

```sh
cmake -S . -B build-asan -DVECTRAVA_BUILD_TESTS=ON -DVECTRAVA_STRICT_WARNINGS=ON -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_FLAGS="-fsanitize=address -fno-omit-frame-pointer" -DCMAKE_EXE_LINKER_FLAGS="-fsanitize=address"
cmake --build build-asan --parallel
ctest --test-dir build-asan --output-on-failure

cmake -S . -B build-ubsan -DVECTRAVA_BUILD_TESTS=ON -DVECTRAVA_STRICT_WARNINGS=ON -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_FLAGS="-fsanitize=undefined -fno-omit-frame-pointer" -DCMAKE_EXE_LINKER_FLAGS="-fsanitize=undefined"
cmake --build build-ubsan --parallel
ctest --test-dir build-ubsan --output-on-failure
```

## Executed host results

Results for the current namespaced source tree on 2026-11-27:

| Compiler/configuration | Result |
|---|---|
| GCC 16.1 MinGW UCRT, Debug, strict warnings | PASS, 91/91 |
| GCC 16.1 MinGW UCRT, Release, strict warnings | PASS, 91/91; optional minimal example built and ran |
| MSVC 19.42.34444, Debug, strict warnings | PASS, 91/91 |
| MSVC 19.42.34444, Release, strict warnings | PASS, 91/91 |
| ClangCL 19.1.5, Debug, strict warnings | PASS, 91/91 |
| ClangCL 19.1.5, Release, strict warnings | PASS, 91/91 |
| Clang GNU driver on Linux | NOT RUN locally |
| ASan | NOT RUN locally; remote CI result pending for this revision |
| UBSan | NOT RUN locally; remote CI result pending for this revision |

The ClangCL oracle configuration uses an independent portable exact reference
where the compiler cannot link GCC's `__int128` runtime helpers. This is a
test portability adjustment; production algorithms and expected semantics
were not changed. Linux Clang and GCC sanitizer configurations are enabled in
GitHub Actions; their result must be checked on the commit that contains these
changes.

## Numerical evidence and limitations

The seeded tests measured maximum errors of 6 Q0.32 codes for bearing over
100,000 full-range coordinate pairs, 1 Q15 component code for 2D vector
rotation over 500,000 seeded cases, and 17 Q1.30 component codes for
axis-angle quaternion conversion over 100,000 seeded phases. The 3D fixed-point
hypotenuse was compared against an independent square-root reference for
100,000 seeded triples. These are empirical samples, not proven global error
bounds. Individual test inputs and thresholds are in the test sources.

## Hardware

Historical evidence: an earlier source revision was run on an ESP32-S3 at
240 MHz with Arduino-ESP32 3.3.10. It covered selected bearing, vector-rotation
and quaternion identity checks only. It did not exercise the complete public
surface and is not evidence for this migrated revision.

Current revision: **HW NOT VERIFIED**. Current API-wide target testing, cycle
measurements, isolated flash/static-RAM contribution and stack measurements
have not been performed. See [PERFORMANCE.md](PERFORMANCE.md).
