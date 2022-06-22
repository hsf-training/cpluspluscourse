# The art of <=>

Here we explore:
- how <=> are == differing.
- when to use or not to use the compiler default implementations.

## Prerequisites

* Being able to overload an operator, especially `==` and `<=>`.

## Instructions

0. Compile and run the program. We are not fully happy with the default implementation of `<=>` for our `Complex` class, which considers 1|2 as smaller than 1.5|1.5.
1. Modify it so that the ordering is based on the norm of the complexes.
2. Because you do not use any more the default implementation of `<=>` you had to provide also an implementation for `==`. What happens if you deduce it from `<=>` (using `(((*this)<=>other)==0)`) ?
3. Try to restore the default implementation for `==` only.
