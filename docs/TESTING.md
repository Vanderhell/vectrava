# Testing

| Test category | Count | Platform | Result | Evidence |
|---|---:|---|---|---|
| Migrated unit tests | 35 source programs; 32 MSVC executables | Windows host, MSVC 19.42.34444, Release | PASS 32/32; three `__int128` oracles skipped on MSVC | `tests/`, CTest |
| Strict warning build | 35 executables | GCC 13.3 / Ubuntu 24.04 | PASS 35/35 | `-Wall -Wextra -Werror`; `libm` linked for reference math. |
| Hardware validation | 0 | ESP32-S3 | HW NOT VERIFIED | No firmware run yet |

```sh
cmake -S . -B build -DVECTRAVA_BUILD_TESTS=ON
cmake --build build --config Release
ctest --test-dir build --output-on-failure -C Release
```

Strict GCC reproduction:

```sh
cmake -S . -B build-linux -DVECTRAVA_BUILD_TESTS=ON -DCMAKE_C_FLAGS="-Wall -Wextra -Werror"
cmake --build build-linux --parallel
ctest --test-dir build-linux --output-on-failure
```
