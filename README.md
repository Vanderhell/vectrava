# Vectrava

Vectrava is a portable C99 geometry library for vectors, ranges, transforms,
quaternions, bounding volumes and deterministic spatial calculations.

The first extraction contains 45 public functions from the PrimitiveCore
`geometry/vectors_shapes_and_intersections` family. APIs retain the validated
`pc_` symbols and use explicit fixed-width representations. No heap or OS
service is required.

```sh
cmake -S . -B build -DVECTRAVA_BUILD_TESTS=ON
cmake --build build --config Release
ctest --test-dir build --output-on-failure -C Release
```

Host validation is the current gate. ESP32-S3 hardware and isolated footprint
measurements are pending.

The name combines *vector* and *trahere* (to draw/transform), describing the
library's focus on directed geometric transformation. Apache License 2.0,
copyright Vanderhell; see `LICENSE` and `NOTICE`.
