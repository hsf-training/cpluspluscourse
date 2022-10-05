# Variants

Here we explore:
- how `std::optional` offers an alternative to errors codes and exceptions.
- how the insertion of a `std::optional` affects following functions.

## Prerequisites

- slides about `std::optional`

## Instructions

In the file `optional.cpp`, modify the function `mysqrt` below so that it returns an `std::optional<double>` rather than a double, and the program prints `nothing` rather than `nan` for the call with `-10`. It will also require to modify `square`.
