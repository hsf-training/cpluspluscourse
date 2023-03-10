
## Instructions

Beginners
* Look at the `OrderedVector` code
* Compile and run `playwithsort.cpp`. See the ordering
* Modify `playwithsort.cpp` and reuse `OrderedVector` with `Complex`

Intermediary
* Extend `OrderedVector` to allow to customize the ordering via an additional template parameter.
  This template parameter should be a comparison object that defaults to `std::less`.
  Hint:
  You have to customize the loop in OrderedVector::add where the insertion point is defined.
* Try ordering by reversed strings (from the last letter, don't change the strings!)
* Test order based on [Manhattan distance](https://en.wikipedia.org/wiki/Taxicab_geometry) with complex type

Bonus
* Check the implementation of `Complex`
* Try ordering complex of complex
