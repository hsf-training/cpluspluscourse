
## Instructions

* Compile and run the executable, see if it races
    * If you have a bash shell, try `./run ./racing`, which keeps invoking the executable
      until a race condition is detected
* (Optional) You can use `valgrind --tool=helgrind ./racing` to prove your assumption
* (Optional) If your operating system supports it, recompile with thread sanitizer.
  With Makefile, use e.g. `make CXXFLAGS="-fsanitize=thread"`
* Use a mutex to fix the issue
* See the difference in execution time
* (Optional) Check again with `valgrind` or thread sanitizer if the problem is fixed
