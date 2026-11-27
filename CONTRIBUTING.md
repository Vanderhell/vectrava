# Contributing

Keep changes focused on correctness, portability, documentation accuracy and
maintainability of the existing API. Preserve C99 compatibility and the
documented numerical and failure behavior.

Before submitting a change, build and run the CTest suite in Debug and Release
with strict warnings enabled. For arithmetic changes, add deterministic
boundary cases and an independent reference or invariant. Do not use the
production function as its own oracle, and do not rely on assertions that are
disabled in Release.

Production code must not require dynamic allocation, an operating system or
third-party libraries. Keep compiler options target-local. Report hardware
and performance results only with the target, compiler, optimization, clock
and measurement method recorded.
