HSF C++ Course cheat sheet
==========================

List of exercises per day, with prefered order and solution overview.
Each exercise is in its own directory and refered to in the following by the name of the directory
For each day, the exercises are given in order in which they should be done.

Day 1
-----
No actual exercise, only setup of the environment, using the "hello" exercise.

Day 2
-----
### polymorphim
First create a Pentagon and an Hexagon and call computePerimeter. Can be used to break the ice.
Second step is to call parent's computePerimeter methods meaning :
```cpp
Polygon *poly = new Hexagon(1.0);
poly->computePerimeter();
```
and check what is called, in regular and virtual method case

### virtual_inheritance
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
See and solve the compilation issue about missing Drawable constructor. Understand that it's now called directly from TextBox constructor and call it explicitely from there with a new id.
See the new id being printed twice.

Day 3
-----

Exercises of day 3 are special as they will have been played (quickly) during the course. But people should replay them and discover the tools by themselves.

### Compiler / polymorphism

This reuses the polymorphism exercise.

A "break the ice" exercise here would be to ask people to do the first step (preprocessor) and make a poll on how many lines of C++ are present in the output. It will vary depending on setups, versions, OS, etc...

Then the important part is to play with nm and the -C option of C++filt to be able to decode symbols, find them and thus address a build error that mentions missing symbols.

Another important bit is ldd and inspecting library dependencies.

### debug

The goal there is really to play, look around and try things. Tutors may have a lot of questions here on "how do you...".

The solution of the crash is simply an inversion of 2 lines in the code where definition of v and it's randomization are inverted.

### valgrind

Again the point is to play with the tool.
In this example, we use an already deleted array. Simply the delete statement in the code appears too early

Second part of the exercise goes back to the gdb exercise. Here we see an access out of array bound. It's due to bad case in 'len' in createAndFillVector (or why should you name your variables wisely and avoid macros).
Interestingly this out of bound access will usually not fail but read the next variable in memory and thus biais the computation.
Second part can be skipped if time is missing

### cppcheck

Simple example of a static analysis tool.
The code shows no problem, even with valgrind and still mayb biais its result.

The basic goal is to run the tool, find the problem and fix it. The problem is a typo in the declaration of the v vector where + has become -, thus creating a out of bound error.

The second goal is to understand why it os not crashing neither detected by valgrind. Here gdb is useful and one needs to inspect the address of variables in memory to understand that the compiler aligns variables and thus leaves space after v that is considered allocated by valgrind.
That second part can be skipped.

### memcheck

Simple example of a memory leak and how valgrind helps a lot with this.
Not so simple solution here. And the use of gdb with steping at the level of the destructor call is recommended. Give it as a hint to people.
The solution is that the wrong destructor is called when calling "delete hexa" because the constructor is not virtual while it should be.

### callgrind

The goal is again to play. With the optimized version, it's interesting to see how much the startup time dominates the few computations done.
This exercise can be skipped

### helgrind

This is a concurrency exercise and thus rather be kept for Day 5 although the tool is presented on Day 3.
Usually the program works fine, and valgrind is happy. The race condition is indeed hard to trigger, but nevertheless spotted easily by helgrind.
The title string is just deleted too early.
This exercise should be skipped if time is missing


Day 4
-----

### constness
The idea is to find out which lines are not correct, due to constness.
Ideal to break the ice as can be organized as a quizz of which line would fail or not with correction under the form of compiler validation.

### templates
This exercise has several levels. People not at ease can stop after first level and go to next exercise. Alternatively, they may do level 1 and 3 and skip 2.

Level 1 : just use the given Complex class in OrderedVector and see it works out of the box thanks to generic code in OrderedVector.

Level 2 : add a template for the ordering in OrderedVector.
The idea is to add an extra template argument "Compare" that is a functor comparing 2 arguments and an extra member "m_compare" of type "Compare" to the OrderedVector class. Then the comparison in the add function can be replaced by 
```cpp
m_compare(arg1, arg2);
```
It can then be tried with e.g. reverse ordering of strings or an order of Complex based on Manhattan distance (https://en.wikipedia.org/wiki/Taxicab_geometry)

Level 3 : use the genericity of the Complex class and play with Complex of integers or Complex of Complex

### smartPointer

Here we have four code snippets that will benefit from using smart pointers.
 * `problem1` is a simple case of usage of `make_unique` with an observer pattern where the raw pointer should be used.
 * `problem2` is an example of a collection of pointers. Move semantic has to be used to transfer ownership of newly created objects to the container (alternatively, `emplace_back`).
 * `problem3` is an example of shared ownership where `std::shared_pointer` should be used.
 * `problem4` demonstrates the usage of `shared_ptr` as class members. It has a second part where a `weak_ptr` can be used, but can be skipped if not enough time.

### stl
The goal is to use STL algorithms. I would advise to start in this order :
  - random_shuffle
  - adjacent_difference
  - first accumulate (the one for sums)
  - second accumulate (sum of squares) with usage of "sumsquare<T>()" as BinaryOperation
  - generate
  
One may want to only do the first 3 and go to next exercise to directly use lambdas for step 4 and 5;

### lambdas

Can be merged into previous exercise as the easy (and modern) solution to step 4 and 5 where functors were needed in the STL exercises.
The accumulate lambda is a simple one, the one for generate involves a state to be captured by reference.

### move semantic
See with valgrind the number of copies and memory allocations in the problem, due to lack of move semantic.
Implement the move semantic based on swap (copy paste from the slides).
See in valgrind the improvements

Day 5
-----

On day 5, the advice it to first work on exercises from Day 3 and 4 that were left aside.

### race

Typical race condition where a simple mutex and lock_guard "solves" the problem.

The second step is to look at the execution time and find out that it's not really a solution. One could then try an atomic and see the difference, although I do not introduce them in the course

### python

This is playing with low level C++/python interfacing. All the c code is provided, so the only task is to use the different implementations (C, C++ manual interface, ctype) from python and see the speed of each of them.
