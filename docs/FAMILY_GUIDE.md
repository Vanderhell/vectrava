# Vectrava family guide

Vectrava provides fixed-width geometry, transform, range, quaternion,
bounding-volume, and spatial calculations for embedded C applications. Pick
the individual operation whose documented units, rounding, failure behavior,
and input limits fit the calling code.

## Integration

- Include `<vectrava/geometry/operation_name.h>` and compile its matching
  `src/vectrava_operation_name.c` source unit, or link the
  `Vectrava::Vectrava` CMake target.
- Check every boolean return before using output values.
- Respect each header's aliasing and failure-preservation contract.
- Fixed-point formats and units belong to each API; similarly named formats
  are not interchangeable.

The public interface consists of 52 functions and two matrix type headers.
Every callable function is referenced by at least one automated test source.
The current coverage and verified toolchain status are tracked in
[TESTING.md](TESTING.md). Historical ESP32-S3 checks cover selected numerical
paths only; current-revision hardware verification has not been performed.
