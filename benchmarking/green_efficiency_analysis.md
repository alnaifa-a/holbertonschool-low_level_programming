# Green Efficiency Analysis

## Measurement Methodology

All measurements were taken on the same machine and in the same terminal environment. Every program was compiled with `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long` and run three times, and the raw outputs were recorded. Time was measured inside each program with `clock()` from `<time.h>`, converted to seconds by dividing by `CLOCKS_PER_SEC`.

In `instrumentation_lab.c`, I placed a `clock()` call immediately before and after each phase call (`build_dataset`, `process_dataset`, `reduce_checksum`). TOTAL starts before the first phase and ends after the last one, so it covers all three phases and is at least as large as each of them. The `printf` calls are outside every measured interval, because printing is slow and is not part of the computation being studied. No algorithmic logic was modified.

## Observed Performance Differences

The baseline loop (100,000,000 iterations) took 0.229549 s, 0.289948 s and 0.224636 s, an average of about 0.248 s. The identical computation varied by roughly 29% between the fastest and slowest run, which shows that a single measurement is not reliable.

In the algorithm comparison, the naive implementation took 4.415311 s, 4.896409 s and 4.260009 s (average 4.523910 s). The single-pass implementation took 0.000363 s, 0.000201 s and 0.000110 s (average 0.000225 s). The naive version was therefore about 20,000 times slower. This matches the complexity: for n = 50,000, the naive version is O(n^2) and performs about 1.25 billion inner iterations, while the single-pass version is O(n) and performs 50,000.

In the instrumented program, the phases measured BUILD_DATA X.XXXXXX s, PROCESS X.XXXXXX s and REDUCE X.XXXXXX s, with a TOTAL of X.XXXXXX s. These phases are linear in the dataset size, so their times are very small compared with the naive algorithm above.

## Relation Between Runtime and Energy Consumption

This project did not measure power in watts, so I cannot state any energy value. Runtime is used only as a proxy: a program that runs longer keeps the CPU active longer, which generally means more energy consumed. Under that assumption, the naive implementation kept the CPU busy for about 4.5 s where the single-pass implementation needed a fraction of a millisecond. If both ran many times on many machines, the difference in CPU activity would grow with the number of runs. This is an inference from measured runtime, not a measured energy result.

## Limitations of the Experiment

- Only three runs were made per program. The baseline varied by about 29% and the naive algorithm by about 15% (4.26 s to 4.90 s), so the averages are rough estimates.
- The single-pass times (0.000110 s to 0.000363 s) are close to the resolution of `clock()`, so the 20,000x ratio is approximate. The single-pass times varied by more than a factor of three between runs.
- `clock()` measures CPU time, not power draw. Different CPU frequencies, other processes and the operating system can change results.
- All results come from one machine, so they may not hold on other hardware.
- The naive and single-pass functions return different counts (625025000 and 25000), so they do not compute identical outputs. The comparison shows the cost of the nested loop pattern, not two perfectly equivalent solutions.

## Practical Engineering Takeaway

Algorithmic choice had a far larger effect on runtime than any variation between runs: changing from O(n^2) to O(n) reduced the measured time from about 4.5 s to well under a millisecond. Engineers should measure before drawing conclusions, repeat measurements to see the variability, and report averages together with the spread. Reducing unnecessary work is the most reliable way to reduce CPU activity, and therefore the likely energy use, but real energy claims need dedicated measurement tools.
