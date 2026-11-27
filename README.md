# Vectrava

![CI](https://github.com/Vanderhell/vectrava/actions/workflows/ci.yml/badge.svg) ![License](https://img.shields.io/badge/license-Apache--2.0-blue.svg) ![Language](https://img.shields.io/badge/language-C99-informational.svg)

![Vectrava banner](docs/banner.svg)

Vectrava is a C99 library for fixed-point geometry and bounded spatial calculations. Its 52 public operations cover vectors, ranges, transforms, quaternions, bounding volumes and coordinate calculations. Two additional public headers define reusable matrix types.

## Engineering properties

- Deterministic fixed-point/integer implementations with caller-owned inputs, outputs and state.
- No mandatory heap allocation, operating-system service, thread or third-party library.
- Separate implementation units for selective linking.
- Strict compiler warnings and test/example targets are opt-in per library-specific CMake options.

## Quick start

```c
#include <vectrava/geometry/checked_add_i64.h>
#include <stdint.h>

int main(void)
{
    int64_t sum = 0;
    if (!vectrava_checked_add_i64(20, 22, &sum)) {
        return 1;
    }
    return sum == 42 ? 0 : 1;
}
```

## Build and test

```sh
cmake -S . -B build -DVECTRAVA_BUILD_TESTS=ON -DVECTRAVA_STRICT_WARNINGS=ON -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
ctest --test-dir build --output-on-failure -C Release
```

Tests and examples are disabled by default when consumed as a dependency. To build the example, enable `VECTRAVA_BUILD_EXAMPLES`.

## Integrate

With an installed CMake package:

```cmake
find_package(Vectrava CONFIG REQUIRED)
target_link_libraries(your_firmware PRIVATE Vectrava::Vectrava)
```

`add_subdirectory()` is also supported. For direct source integration, include `<vectrava/geometry/<operation>.h>` and compile the matching `src/vectrava_<operation>.c` unit plus any private dependency listed in the API reference.

## Documentation

| Need | Read |
|---|---|
| Select an operation by task | [Family guide](docs/FAMILY_GUIDE.md) |
| Review each API contract | [API reference](docs/API_REFERENCE.md) |
| Reproduce host tests and see limits | [Testing](docs/TESTING.md) |
| Understand design and dependencies | [Architecture](docs/ARCHITECTURE.md) |
| Review embedded evidence | [Performance](docs/PERFORMANCE.md) |

## Validation status

The audit suite directly calls all 52 public functions. The local host matrix and current ESP32-S3 status are recorded in [Testing](docs/TESTING.md). Earlier ESP32-S3 checks cover selected numeric paths only; they are historical evidence and do not establish complete API validation on the migrated revision. Current embedded cycles and isolated footprint are not claimed without a new measurement.

## License

Apache License 2.0, copyright Vanderhell. See [LICENSE](LICENSE) and [NOTICE](NOTICE).
