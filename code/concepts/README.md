# Concepts

Here we explore:
- how <=> are == differing.
- when to use or not to use the compiler default implementations.

## Prerequisites

- slides about C++20 concepts

## Instructions

In the file `concepts.cpp`, we provide two implementations of the function `increment()`.
The second one is optimized for the iterators which fulfill the requirements of
the concept `RandomAccessIterator`.

1. Complete the concept `RandomAccessIterator` : check that the class `IterT` has some operator `+=`.
2. Find an existing concept in the standard library, which can replace the previous user-defined concept.
