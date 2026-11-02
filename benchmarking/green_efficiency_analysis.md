# Green Efficiency Analysis

## Measurement Methodology
I compiled the provided programs with `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long`. Both `baseline_loop` and `comparison_algorithms` compiled without errors. I ran each program five times on the same machine, in the same terminal session, using `time ./program`. For each run I recorded two kinds of values: the time printed by the program itself (measured with `clock()`, which counts CPU time) and the `real`, `user` and `sys` times reported by `time`. No other heavy program was started on purpose during the runs. The averages below are computed from the five runs.

## Observed Performance Differences
`baseline_loop` executes 100000000 iterations. Its `clock()` times were 0.222600, 0.222358, 0.224372, 0.223050 and 0.222873 seconds, an average of 0.2231 s with a spread of only 0.002 s. The `real` times ranged from 0.768 s to 0.894 s (average 0.809 s).

`comparison_algorithms` runs two implementations. The naive algorithm took between 2.695872 s and 2.741082 s, an average of 2.710 s. The single-pass algorithm took between 0.000103 s and 0.000110 s, an average of about 0.000107 s. The naive version is therefore roughly 25000 times slower than the single-pass version in my measurements. The `user` time of the whole program stayed between 2.697 s and 2.743 s, which matches the naive timing, because the single-pass part is negligible.

The measurements were very stable: the naive algorithm varied by less than 2% between its fastest and slowest run. The difference between the two algorithms is therefore far larger than the run-to-run noise. This is consistent with an algorithm that does much less work, but my measurements only show the time difference, not the exact complexity of each algorithm.

## Relation Between Runtime and Energy Consumption
I did not measure power in watts, so I cannot give an energy figure. Runtime is used as a proxy: the longer a program keeps the CPU busy, the more energy it generally uses. In my runs, the naive algorithm kept the CPU busy for about 2.7 s (`user` time), while the single-pass algorithm needed about 0.0001 s. If such a program ran thousands of times on a server, this difference in CPU activity would probably add up to a difference in energy use. I do not have measurements to quantify it.

## Limitations of the Experiment
First, no watts were measured, so the link between runtime and energy is an assumption. Second, `real` time was always much larger than `user` time: for `comparison_algorithms` it was about 10.77 s against 2.71 s, and for `baseline_loop` about 0.81 s against 0.22 s. This means the process was not running on the CPU during the whole elapsed time, so the environment was not fully dedicated to my program, and I did not identify the cause. For this reason I rely on `user` and `clock()` times rather than `real` time. Third, I ran only five repetitions on one machine, and `clock()` measures CPU time only. Fourth, the two algorithms returned different values (625025000 and 25000), so I cannot claim that they solve exactly the same problem; my comparison concerns execution time only.

## Practical Engineering Takeaway
Measure before drawing conclusions: repeating each run five times showed that the timings were stable and that the gap between the two algorithms (about 2.710 s against 0.000107 s) is not noise. Prefer CPU time (`user`, `clock()`) when the machine is shared, since `real` time was inflated and variable in my runs. Choosing a more efficient algorithm reduces CPU activity much more than small tuning, and CPU activity is the best proxy I have for energy use. Finally, a fair comparison needs the same machine, the same conditions and outputs that are checked for equivalence.
