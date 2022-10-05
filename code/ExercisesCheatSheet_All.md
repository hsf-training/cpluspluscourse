HEP C++ Course cheat sheet
==========================

List of exercises per day, with preferred order and solution overview.
Each exercise is in its own directory and referred to in the following by the name of the directory
For each day, the exercises are given in order in which they should be done.

Day 1 - Basics Exercises
------------------------

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

Day 2 - OO Exercises
--------------------

### Polymorphism (directory: `polymorphism`)

First create a Pentagon and an Hexagon and call computePerimeter. Can be used to break the ice.
Second step is to call parent's computePerimeter methods meaning :

```cpp
Polygon *poly = new Hexagon(1.0);
poly->computePerimeter();
```
and check what is called, in regular and virtual method case

### `modern_oo`

Insert one `= delete`, one `= default` and one `override`.

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


### Operators (directory: `operators`)

This exercise is about making `main` run successfully by completing the implementation of `Fraction`.
Implement a constructor for `Fraction` and add two integer data members for numerator and denominator.
Comment out everything in `main` except the first two LOCs.
This should compile now and print nothing.

Then uncomment the `std::cout` statements and implement `operator<<` for `Fraction`.
Compile and run.

Proceed this way through the entire exercise.
There are multiple possibilities to implement some operators, e.g. as members, as hidden friends, or as free functions.
Also when and where to normalize a fraction is up to the students.
All solutions are fine, as long as the `main` function runs successfully.

Day 3
-----

Exercises of day 3 are special as they will have been played (quickly) during the course. But people should replay them and discover the tools by themselves.

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

### Clang format (any directory)

The students can try this on any example.
Please warn the students: If they want to revert later, they should pick an example with no local changes.
Just follow the instructions on the slide deck.
It is also fine if the mentor demonstrates it quickly.
Please advise the students they should use `.clang-format` files from their projects before they start developing their own one.

### Address sanitizer (`asan`)

The goal is to play with asan, and learn to read the very detailed hints it gives when it detects an error.

There's two bugs and one memory leak:
- `stackOverflow()` overflows the stack by writing past the end of an array in the for loop.
- `useAfterFree()` returns a reference to a temporary. One should return a copy.
- `memoryLeak()` lets a string leak.

### `valgrind`

Again the point is to play with the tool.
In this example, we use an already deleted array. Simply the delete statement in the code appears too early

Second part of the exercise goes back to the gdb exercise. Here we see an access out of array bound. It's due to bad case in 'len' in createAndFillVector (or why should you name your variables wisely and avoid macros).
Interestingly this out of bound access will usually not fail but read the next variable in memory and thus biais the computation.
Second part can be skipped if time is missing

### `cppcheck`

Simple example of a static analysis tool.
The code shows no problem, even with valgrind and still mayb biais its result.

The basic goal is to run the tool, find the problem and fix it. The problem is a typo in the declaration of the v vector where + has become -, thus creating a out of bound error.

The second goal is to understand why it os not crashing neither detected by valgrind. Here gdb is useful and one needs to inspect the address of variables in memory to understand that the compiler aligns variables and thus leaves space after v that is considered allocated by valgrind.
That second part can be skipped.

### `memcheck`

Simple example of a memory leak and how valgrind helps a lot with this.
Not so simple solution here. And the use of gdb with steping at the level of the destructor call is recommended. Give it as a hint to people.

The solution is that the wrong destructor is called when calling "delete hexa" because the constructor is not virtual while it should be.

### `callgrind`

The goal is again to play. With the optimized version, it's interesting to see how much the startup time dominates the few computations done.
This exercise can be skipped

### `helgrind`

This is a concurrency exercise and thus rather be kept for Day 5 although the tool is presented on Day 3.
Usually the program works fine, and valgrind is happy. The race condition is indeed hard to trigger, but nevertheless spotted easily by helgrind.
The title string is just deleted too early.
This exercise should be skipped if time is missing


Day 4 - Modern C++ Exercises
----------------------------

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

### Variadic templates (directory: `variadic`)

The goal of the exercise is to implement a simple tuple, ignoring const correctness (to make it simpler).
If students encounter any constness problems, make sure they pass by value or mutable reference.
When you are unsure yourself, check the solution.

Solutions:

1. Add a default constructor
2. Add an `explicit` to the tuple constructor
3. head(tuple&) should just return the member m_head
4. get<I>(tuple&) should be implemented recursively. You can use SFINAE (like on the slides), but prefer `if constexpr`.
5. Specialize `std::tuple_size`. The value of the trait is sizeof...(Ts) of the template parameter pack in tuple<Ts...>
6. Specialize `std::tuple_element`. You can implement this recursively with Head/Tail... template parameters.
   But since get() already does something like that, it is the easiest to just decltype(get<I>(...))
7. tuple_cat(tuple, tuple): Delegate to a helper tuple_cat(tuple, tuple, index_seq, index_seq) then then just construct a result tuple{get<Is1>(t1)..., get<Is2>(t2)...}
8. sum(tuple): you need a helper again with a single index sequence, but make it a local lambda this time. Inside the lambda, fold over get<Is>(t)
9. operator<<: again, needs a helper for the index sequence.
   To intersperse the ", " between elements, you need more logic so a fold over << won't work. Use a fold over comma.
   Finally, to omit the last ", ", just use a conditional expression comparing the expanded index pack against the index pack size


### Smart pointers (directory: `smartPointers`)

Here we have four code snippets that will benefit from using smart pointers.

- `problem1` is a simple case of usage of `make_unique` with an observer pattern where the raw pointer should be used.
- `problem2` is an example of a collection of pointers. Move semantic has to be used to transfer ownership of newly created objects to the container (alternatively, `emplace_back`).
- `problem3` is an example of shared ownership where `std::shared_pointer` should be used.
- `problem4` demonstrates the usage of `shared_ptr` as class members. It has a second part where a `weak_ptr` can be used, but can be skipped if not enough time.

### Standard algorithms and lambdas (directory: `stl`)

The goal is to use STL algorithms. I would advise to start in this order :

  - random_shuffle
  - adjacent_difference
  - first accumulate (the one for sums)
  - second accumulate (using lambda to compute sum of squares)
  - generate (involves a state to be captured by reference)

### Move semantic (directory: `move`)

See with valgrind the number of copies and memory allocations in the problem, due to lack of move semantic.
Implement the move semantic based on swap (copy paste from the slides).
See in valgrind the improvements.


Day 5
-----

On day 5, the advice it to first work on exercises from Day 3 and 4 that were left aside.

### `race`

Typical race condition where a simple mutex and lock_guard "solves" the problem.

The second step is to look at the execution time and find out that it's not really a solution. One could then try an atomic and see the difference, although I do not introduce them in the course

### `atomic`

Exactly the same race condition as above. Fix them using an `atomic<int>`.

*Optional*: Compare run times for lock and atomic solution. Those are likely not very different, as many locks are implemented using atomics.

### condition_variable

Small example where 4 consumer threads are notified by a producer.
1. The production phase is not protected by a lock.
2. When the consumers are waking up, they don't release the lock that's tied to the condition variable, so they cannot wake up in parallel.

### `python`

This is playing with low level C++/python interfacing. All the c code is provided, so the only task is to use the different implementations (C, C++ manual interface, ctype) from python and see the speed of each of them.
