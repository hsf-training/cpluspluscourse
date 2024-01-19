# Undefined Behaviour Sanitizer

This directory contains a program that's full of evil bugs. Many of those would cause compiler warnings,
but the problems can easily be obscured by making the code slightly more complicated, e.g. by passing
pointers or indices through functions or similar.

UBSan is a run-time tool, so it can catch these bugs even if the compilers don't emit warnings.
This should illustrate why every larger project should have a UBSan and a ASan build as part of
it Continuous Integration.

## Instructions

- Compile and run this program using a compiler invocation like
  `<compiler> -g -std=c++17 -o undefinedBehaviour undefinedBehaviour.cpp`

- You might see warnings depending on the compiler, but on most platforms the program runs without observable issues.

- Recompile with "-fsanitize=undefined", and observe that almost every second line contains a serious bug.
  NOTE: If this fails, your compiler does not support UBSan (yet). In this case, you can try to read the
        program and catch the bugs, or continue with the next exercise.

- Try to understand what's wrong. The solution contains a few comments what kind of bugs are hidden in the program.

