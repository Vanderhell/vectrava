# Testing and audit status

The public surface has 54 headers: 52 callable functions and two matrix type
headers. `tests/test_001` through `test_035` are retained; `test_036_api_gaps`
adds deterministic checks for the 15 functions that previously had no test
source, including 100,000 seeded differential bearing and three-dimensional
norm cases against independent long-double references. Existing tests retain
optional `__int128` oracles where supported.

## Reproduction

Strict GCC or Clang C99 build:

```sh
cmake -S . -B build -DVECTRAVA_STRICT_WARNINGS=ON
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

The strict option selects `/W4 /WX` on MSVC and
`-Wall -Wextra -Wpedantic -Werror` on GCC/Clang. Sanitizers on GCC/Clang:

```sh
cmake -S . -B build-san -DVECTRAVA_STRICT_WARNINGS=ON \
  -DCMAKE_C_FLAGS="-fsanitize=address,undefined -fno-omit-frame-pointer"
cmake --build build-san --parallel
ctest --test-dir build-san --output-on-failure
```

## Local evidence (2026-11-10)

| Configuration | Result |
|---|---|
| GCC 16.1, MinGW, strict C99 warnings | PASS, build succeeds; 36/36 tests |
| Clang-cl 19.1.5, strict warnings | PASS, 33/33 tests (three optional `__int128` oracles excluded) |
| Clang GNU driver | NOT RUN: Windows MSVC runtime/sysroot unavailable |
| MSVC 19.42 Debug and Release | PASS, 33/33 tests in each configuration |
| AddressSanitizer | PASS, Clang 22.1.8 x64, 33/33 tests |
| UndefinedBehaviorSanitizer | PASS, Clang 22.1.8 x64, 33/33 tests |
| ESP32-S3 | HW NOT VERIFIED |

The previous checked-in `build-audit` cache refers to a different absolute
workspace path and is not valid evidence for this checkout. The legacy suite
contains duplicate tests 009/010 and 011/012; they remain unchanged.

ASan and UBSan were run separately because this Windows Clang linker reports a runtime-library conflict when both sanitizer runtimes are linked together. Both instrumented runs passed all tests available in the MSVC-compatible configuration (three optional `__int128` oracle tests excluded); GCC strict ran the full 36-test set.

The CORDIC checks measured maximum errors of 1 Q15 component code for
`pc_vector_rotate2_q` over 500,000 seeded vector/angle cases, 6 Q0.32 phase
codes for `pc_bearing2_q` over 100,000 seeded full-range origin/target pairs,
and 17 Q1.30 component codes for `pc_quat_from_axis_angle_q` over 100,000
seeded phases. The respective test thresholds are 2, 24, and 20 codes. These
are sampled empirical results, not formal worst-case proofs. `pc_q_hypot3` is
checked against nearest-even long-double square roots for 100,000 seeded
triples. No confirmed production defect was found; no implementation algorithm
was changed. A test-oracle undefined conversion in an early negative-angle
reference was corrected by normalizing the phase before converting it to an
unsigned value; production code was unaffected.
