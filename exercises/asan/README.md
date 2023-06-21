# Using address sanitizer

Here, we explore address sanitizer (asan). The program `asan.cpp` has two bugs and a memory leak,
which should be relatively easy to find. It might or might not crash when run in its current state.
The goal is to compile the program with and without asan instrumentation and learn to read the very
detailed analysis of the program it generates.

## Instructions
There's three tasks listed in the source code.
