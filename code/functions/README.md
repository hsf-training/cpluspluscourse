# Functions and how arguments are passed in C++

Here, we will look a bit into how arguments are passed into functions.
You will find an example where everything is passed by value (by copy), but there is a struct that is slow to copy.
We will try to work with it without copying it.

# Instructions

## Step 1

Check out `functions.cpp`, compile it (`make`) and run the program.
Check out `Structs.h`. It defines two structs that we will work with : `FastToCopy` and `SlowToCopy`.
They are exactly what their name says, so let's try to avoid copying the latter.

## Step 2

Using `printFiveCharacters()` as an example, write a function that prints the first five characters of `SlowToCopy`. Call it in `main()`.

## Step 3

Try passing by copy and passing by reference, see the difference.

## Step 4

When passing by reference, ensure that your `printFiveCharacters` cannot inadvertently modify the original object.
To test its const correctness, try adding something like `argument.name[0] = 'a';` to your print function.
Try both with and without const attributes in your print function's signature.
