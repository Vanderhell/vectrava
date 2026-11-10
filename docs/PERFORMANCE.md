# Performance

No controlled MCU performance or footprint measurement is available for this
checkout. Flash, static RAM, stack, cycle count, and ESP32-S3 status remain
unmeasured; report `HW NOT VERIFIED`.

Several primitives use bounded integer loops (for example, binary square-root
search and fixed-iteration CORDIC), and other primitives use 64-bit division.
These operation counts alone do not predict target latency. Do not treat host
builds or source-level estimates as embedded measurements. Benchmark selected
translation units on the actual target before optimization, then compare the
same inputs, compiler options, and clock configuration before and after a
change.
