
## Instructions

In this exercise, we will take the `tuple` implementation from the slides
and extend it step by step to make the example code in `main` compile.

Feel free to comment out parts of main to test parts of your implementation sooner.
All instructions are given in more detail in the source code as well, especially inside `main`.

This example neglects const correctness so there is less code to write.
Making it const correct would require adding several overloads with almost the same code as the non-const version.
You can try this is a bonus exercise at the end!

1. make `tuple` default-constructible
2. avoid implicit construction from a single value
3. write `head(tuple)`, which returns the first element of a tuple
4. implement `get<I>(tuple)`
5. specialize `std::tuple_size`
6. specialize `std::tuple_element`
7. implement a binary `tuple_cat(tuple, tuple)`
8. implement `sum(tuple)`
9. implement `operator<<`, producing comma separated output
