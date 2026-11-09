# Testing

| Test category | Count | Platform | Result | Evidence |
|---|---:|---|---|---|
| Migrated unit tests | 35 source programs; 32 MSVC executables | Windows host, MSVC 19.42.34444, Release | PASS 32/32; three `__int128` oracles skipped on MSVC | `tests/`, CTest |
| Hardware validation | 0 | ESP32-S3 | HW NOT VERIFIED | No firmware run yet |

```sh
cmake -S . -B build -DVECTRAVA_BUILD_TESTS=ON
cmake --build build --config Release
ctest --test-dir build --output-on-failure -C Release
```
