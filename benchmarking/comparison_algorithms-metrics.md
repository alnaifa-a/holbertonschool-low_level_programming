# Comparison Algorithms Metrics

## Raw runs

| Run | Naive (s) | Single-pass (s) |
|-----|-----------|-----------------|
| 1   | 4.415311  | 0.000363        |
| 2   | 4.896409  | 0.000201        |
| 3   | 4.260009  | 0.000110        |

Results printed by every run: Naive = 625025000, Single-pass = 25000.

## Averages

- Naive: 4.523910 s
- Single-pass: 0.000225 s

## Relative difference

The naive implementation is ~20,000 times slower than the single-pass implementation (4.523910 / 0.000225 = ~20,100).

## Notes

- Naive is O(n^2): about 1.25 billion inner iterations for n = 50000. Single-pass is O(n): 50000 iterations.
- Naive times varied from 4.26 s to 4.90 s between runs, which is timing variability caused by other processes on the machine.
- Single-pass times (0.000110 to 0.000363 s) are very small and close to the resolution of clock(), so the ratio is approximate.
- The two functions print different results because naive recounts earlier elements for every i. The task says not to modify the logic.
- All runs were done on the same machine. Runtime is used as a proxy for CPU activity and energy use, not a direct power measurement.
