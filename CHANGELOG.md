# Changelog

## 0.2.0

- Namespaced the 52 callable operations, public matrix types, constants and header guards under Vectrava.
- Reorganized the 54 public headers under `include/vectrava/geometry/`.
- Added the `Vectrava::Vectrava` CMake package target, install/export support, and opt-in tests/examples.
- Preserved original headers, sources and test programs under `tests/oracle/legacy_*`.
- Updated selected test references to use portable exact arithmetic so the relevant API tests run under MSVC and Release configurations.
- Public symbol and header renaming is source-incompatible; existing consumers must update includes and call sites.

## 0.1.0

- Initial Vectrava fixed-point geometry library release.
