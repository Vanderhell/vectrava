# Architecture

Vectrava is a standalone C99 static library with 52 callable operations and two public matrix-type headers. The production CMake target compiles explicit implementation units and exports `Vectrava::Vectrava`. Public headers live under `include/vectrava/geometry/`; private implementation dependencies remain under `src/`.

The library has no runtime initialization, mandatory heap allocation, operating-system service or third-party runtime dependency. Caller-owned buffers and state remain explicit. Tests, the C++ public-header smoke target and examples are opt-in. Consuming the library with tests disabled requires only a C compiler.

Numerical formats, rounding, saturation, error handling, output preservation and aliasing contracts are documented per API. Current compiler, sanitizer and hardware evidence is summarized in [TESTING.md](TESTING.md).
