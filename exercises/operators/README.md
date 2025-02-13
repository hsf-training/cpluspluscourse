
## Instructions

STEP 1
- Add a free operator<<, reusing str(), and simplify main() first lines.
- Replace equal() with operator==(), and upgrade tests.
- Add operator!=(), reusing operator==(), and upgrade tests.
- Replace compare() with operator<=>(), reusing <=> between doubles,
  and upgrade tests.
- Replace multiply() with operator*(), and upgrade tests. 

STEP 2
- Replace TestResultPrinter::process() with operator()(), and upgrade CHECK().

OPTIONAL STEP 3
- Add an inplace multiplication operator*=(), and add tests.
- Review operator*() so to reuse operator*=().
- Ensure calls to operator*=() can be chained, the same as operator<<().

## Take aways

- Do not confuse equality and equivalence.
- We can very often implement an arithemtic operator@ in terms of operator@=.
- When implementing <=>, you get <, >, <=, >= for free.
- Object-functions are very used with standard algorithms,
  yet tend to be often replaced by lambdas in modern C++.

