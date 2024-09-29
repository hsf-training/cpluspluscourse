
# Writing leak-free and fault-free C++

Here we have five code snippets that will benefit from using smart pointers. By replacing every explicit `new` with `make_unique` or `make_shared`, (alternatively by explicitly instantiating smart pointers) we will fix memory leaks, segmentation faults, and make most cleanup code unnecessary.

## Prerequisites

* Do you know which kind of pointer is used for what?
  * Raw pointer
  * [`std::unique_ptr`](https://en.cppreference.com/w/cpp/memory/unique_ptr)
  * [`std::shared_ptr`](https://en.cppreference.com/w/cpp/memory/shared_ptr)
* C++-14 for `std::make_unique` / `std::make_shared`. Understand what these functions do.
* Helpful: Move semantics for `problem2()`, but one can do without.

## Instructions

* In the **essentials course**, work on `problem1` and `problem2`, and fix the leaks using smart pointers.
* In the **advanced course**, work on `problem1` to `problem5`. Skip `problem4` and `problem5` if you don't have enough time.
* Dedicated instructions are given in each cpp file.
* Each one is written so that you easily check if the problem is solved or not.
* If seen in course before, you are also advised to try external tools such as valgrind:
```
valgrind --leak-check=full --track-origins=yes ./problem1
```
