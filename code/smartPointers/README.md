# Writing leak-free C++.

Here we have four code snippets that will benefit from using smart pointers.
By replacing every explicit `new` with `make_unique` or `make_shared`,
(alternatively by explicitly instantiating smart pointers) we will fix memory leaks,
and make most cleanup code unnecessary.

## Prerequisites

* Which pointer is used for what?
  * Raw pointer
  * [`std::unique_ptr`](https://en.cppreference.com/w/cpp/memory/unique_ptr)
  * [`std::shared_ptr`](https://en.cppreference.com/w/cpp/memory/shared_ptr)
* C++-14 for `std::make_unique` / `std::make_shared`. Understand what these functions do.
* Helpful: Move semantics for `problem2()`, but can do without.

## Instructions

* Compile and run the program. It doesn't generate any output.
* Run with valgrind to check for leaks
```
valgrind --leak-check=full --track-origins=yes ./smartPointers
```
* Go through `problem1()` to `problem3()` and fix the leaks using smart pointers.
* `problem4()` is the most difficult. Skip if not enough time.
