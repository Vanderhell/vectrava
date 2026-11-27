# Performance and footprint

## Current revision

Current-revision ESP32-S3 cycle counts, isolated flash contribution, static RAM and per-function stack usage are **NOT MEASURED**. No embedded performance guarantee is made from host execution or source inspection.

## Historical selected-path evidence

A previous source revision was exercised on an ESP32-S3 v0.2 at 240 MHz with Arduino-ESP32 3.3.10. The recorded tests measured selected bearing and vector-rotation numerical error and quaternion identity invariants. That was a correctness sample, not a performance benchmark or full API hardware suite. The report is retained internally; only the summarized, device-independent result appears in [TESTING.md](TESTING.md).

Several operations use bounded loops, CORDIC iterations or 64-bit division. These source-level properties do not establish target latency. Measure the intended compiler, optimization level, clock and input distribution before tuning; compare identical workloads and separate harness overhead from function cost. Do not infer WCET from sampled timing.
