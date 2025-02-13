
## Instructions

STEP 1
- Complete the class Fraction so that a Fraction can be construct from one or two integer.
  Check the first two lines of main() are working (comment out the rest)
- Add the function equal().
  Check the second section of main() works.
- Add the function multiply().
  Check the whole main() works.

STEP 2
- Replace the function printTestResult() by a class TestResultPrinter
  with a method process() that take the same arguments as before.
  Upgrade CHECK() and main().
- Transform the WIDTH constant into a variable member of TestResultPrinter,
  which is initialized in its constructor.
  Upgrade main().

OPTIONAL STEP 3
- Move multiply() and compare() as friend functions within the class Fraction.
  Check main() works.
- Remove the accessors numerator() and denominator().
  Check main() works.

OPTIONAL STEP 4
- Remove the systematic call to normalize().
- Add a equivalent() method to Fraction.
- Upgrade the tests accordingly.
- Transform the private normalize() into a public const normalized() method
  which return the normalized fraction.
- Add some tests to check normalized().
