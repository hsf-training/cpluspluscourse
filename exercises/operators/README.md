
## Instructions

### Main Tasks
- Write an ostream operator with the following signature: `operator<<(ostream &, Fraction const &)`.
  The `str()` function of Fraction will help you to implement it. Use this operator to make the `cout`s in the first lines of `main()` look a bit more natural.
  - **Note**: If you do this exercise as part of the advanced course, implement the operators as hidden friends.
- Replace the function `equal()` with `operator==()`, and upgrade tests.
  Note that equality isn't the same as equivalence. The compare function returns 0
  for 1/1, 2/2, etc, but these are not equal.
- Add `operator!=()`, reusing `operator==()`, and upgrade tests.
- Replace `multiply()` with `operator*()`, and upgrade tests.

### Optional if you have time
- Add an inplace multiplication `operator*=()`, and add tests.
- Review `operator*()` so to reuse `operator*=()`.
- Ensure calls to `operator*=()` can be chained, the same as `operator<<()`.

## Take away

- Operators can make certain expressions much more readable.
- Do not confuse equality and equivalence.
- We can very often implement an arithmetic operator@ in terms of operator@=.
