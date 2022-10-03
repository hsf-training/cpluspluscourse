# Concepts

Here we explore:
- how concepts helps to have some optimized implementation for a subset of possible type parameters.
- benefits of using existing concepts from the standard library.
- how to decipher compiling errors.

## Prerequisites

- slides about C++20 concepts

## Instructions

In the file `concepts.cpp`, we provide two implementations of the function `increment()`.
The commented one is optimized for iterators which fulfill the requirements of
the concept `RandomAccessIterator`.

1. Uncomment and complete the concept `RandomAccessIterator`: check that the class `IterT` has operator `+=`.
2. Find an existing concept in the standard library, which can replace the previous user-defined concept.
3. If you comment out the default general implementation of `increment()`, why the compiler refuse to use remaining implementation with the list ? (which requirement is not fulfilled ?)
