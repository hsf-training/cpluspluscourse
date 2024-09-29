
## Instructions

The program `racing.cpp` is incrementing a shared integer many times, within several threads, which should lead to race conditions if no specific protection is used. The values of the global parameters `nThread`, `nInc` and `nRepeat` can be custommized for your own computer.

Tasks
- Compile and run the executable, check it races.
- If you have a bash shell, try `./run ./racing`, which keeps invoking the executable until a race condition is detected.
- (Optional) You can use `valgrind --tool=helgrind ./racing` to prove your assumption
- (Optional) If your operating system supports it, recompile with thread sanitizer.
  With Makefile, use e.g. `make CXXFLAGS="-fsanitize=thread"`
- Use a `std::mutex` to fix the issue.
- See the difference in execution time, for example with `time ./racing`.
  You might have to increase `nRepeat` if it completes too fast, or lower it if it takes too long.
- (Optional) Check again with `valgrind` or thread sanitizer if the problem is fixed.
- Try to use `std::atomic` instead of the mutex, and compare the execution time.
