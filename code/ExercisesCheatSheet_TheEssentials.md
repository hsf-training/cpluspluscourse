HEP C++ Course cheat sheet
==========================

List of exercises per day, with preferred order and solution overview.
Each exercise is in its own directory and referred to in the following by the name of the directory
For each day, the exercises are given in order in which they should be done.

Day 1 - Basics Exercises
----

### Hello World (directory: `hello`)

Just try to compile and run `./hello` to make sure that everything is set up correctly.

### Functions (directory: `functions`)

pass by copy / pass by reference

- Write a `printFiveCharacters(SlowToCopy)` function using the existing function as a model. Change its name
  if overloading isn't desired.
- Call it in `main()`.
- Make sure that the signature is `(SlowToCopy const & a)` to avoid copies.
- Try to modify the data in the structs. Compare what happens for each of `(SlowToCopy a), (SlowToCopy & a), (SlowToCopyy const & a)`.

### Control Structures (directory: `control`)

The idea of this exercise is to play with all kinds of possible loops and control structures and to understand how they work.

- change from a C++98 style for loop to range-based loop
- replace if / else statement with conditional operator
- change from a for loop to while and do/while loop
- change an if statement to a switch statement

### Auto & Refercences (directory: `loopsRefsAuto`)

- Write an indexed for loop to initialise the members of the structs. The program should not print garbage numbers.
- Use `auto const &` to prevent copies in the second loop.
- Understand the difference to `auto &`, get in the habit of using const references.


### Operators (directory: `operators`)

TBD

Day 2 - Tools Exercises
-----


The tools exercises of day 2 are special as they will have been played (quickly) during the course. But people should replay them and discover the tools by themselves.


### Compiler

Based on the functions exercise, we are replaying the compilation steps manually.

A "break the ice" exercise here would be to ask people to do the first step (preprocessor) and make a poll on how many lines of C++ are present in the output. It will vary depending on setups, versions, OS, etc...

Then the important part is to play with nm and the -C option of C++filt to be able to decode symbols, find them and thus address a build error that mentions missing symbols.

Another important bit is ldd and inspecting library dependencies.

Notes:
- `--std=` >= c++11 is needed to initialise the structs.
- The Makefile skips the generation of the object file for functions.cpp. This might surprise some people.

### Debugging (directory: `debug`)

The goal there is really to play, look around and try things. Tutors may have a lot of questions here on "how do you...".

The solution of the crash is simply an inversion of 2 lines in the code where definition of v and it's randomization are inverted.

### Clang format



## Day 2 - OO Exercises


### Polymorphism (directory: `polymorphism`)

First create a Pentagon and an Hexagon and call computePerimeter. Can be used to break the ice.
Second step is to call parent's computePerimeter methods meaning :

```cpp
Polygon *poly = new Hexagon(1.0);
poly->computePerimeter();
```
and check what is called, in regular and virtual method case


### Virtual inheritance (directory: `virtual_inheritance`)

First create a TextBox and try to call draw.
There will be an error that the member is ambiguous, due to multiple inheritance.
Fix code by calling it on both parents using types :

```cpp
  TextBox *tb = new TextBox(...)
  Rectangle *r = tb;
  r->draw();
```

See the output and check the ids printed, 2 different ones.

Retry with virtual inheritance.
See and solve the compilation issue about missing Drawable constructor. Understand that it's now called directly from TextBox constructor and call it explicitly from there with a new id.
See the new id being printed twice.


Day 3 - Modern C++ Exercises
----

### Constness (directory: `constness`)

The idea is to find out which lines are not correct, due to constness.
Ideal to break the ice as can be organized as a quizz of which line would fail or not with correction under the form of compiler validation.

### Generic programming (directory: `templates`)

This exercise has several levels. People not at ease can stop after first level and go to next exercise. Alternatively, they may do level 1 and 3 and skip 2.

Level 1 : just use the given Complex class in OrderedVector and see it works out of the box thanks to generic code in OrderedVector.

Level 2 : add a template argument for the ordering in OrderedVector.
The idea is to add an extra template argument "Compare" that is a functor comparing 2 arguments and an extra member "m_compare" of type "Compare" to the OrderedVector class. Then the comparison in the add function can be replaced by

```cpp
m_compare(arg1, arg2);
```
It can then be tried with e.g. reverse ordering of strings or an order of Complex based on Manhattan distance (https://en.wikipedia.org/wiki/Taxicab_geometry)

Level 3 : use the genericity of the Complex class and play with Complex of integers or Complex of Complex

### Standard algorithms (directory: `stl`)

The goal is to use STL algorithms. I would advise to start in this order :

  - random_shuffle
  - adjacent_difference
  - first accumulate (the one for sums)
  - second accumulate (sum of squares) with usage of "sumsquare<T>()" as BinaryOperation
  - generate

One may want to only do the first 3 and go to next exercise to directly use lambdas for step 4 and 5;

### Lambda functions (directory: `lambdas`)

Can be merged into previous exercise as the easy (and modern) solution to step 4 and 5 where functors were needed in the STL exercises.

The accumulate lambda is a simple one, the one for generate involves a state to be captured by reference.

### Smart pointers (directory: `smartPointers`)

Here we have four code snippets that will benefit from using smart pointers.

 - `problem1` is a simple case of usage of `make_unique` with an observer pattern where the raw pointer should be used.
 - `problem2` is an example of a collection of pointers. Move semantic has to be used to transfer ownership of newly created objects to the container (alternatively, `emplace_back`).
 - `problem3` is an example of shared ownership where `std::shared_pointer` should be used.
 - `problem4` demonstrates the usage of `shared_ptr` as class members. It has a second part where a `weak_ptr` can be used, but can be skipped if not enough time.
