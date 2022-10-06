Exercises HowTo
===============

 - List of exercises per day, with preferred order and solution overview.
 - Each exercise is in its own directory and referred to in the following by the name of the directory
 - We tried to provide more material than many participants can finish during the sessions. That's not a problem, as additional exercises can also be done later.
 - For each day, the exercises are given in order in which they should be done.

Setup requirements
------------------

### Required

 - decent C++ editor
 - any C++ compiler supporting C++ 20
 - C++ 17 compiler will do for most of the exercises though
 - git for getting/managing your code

### Good to have

 - gdb to debug your problems
 - valgrind, kcachegrind, cppcheck, ... for corresponding exercises

### C++ and python specific needs

 - python3, libpython3-dev
 - ctypes, matplotlib, numpy python packages


Getting exercises’ code
-----------------------

```
git clone https://github.com/hsf-training/cpluspluscourse.git
cd cpluspluscourse/code
```

Anatomy of an exercise
----------------------

Each exercise is in a subdirectory with mainly 3 sets of files

### *.hpp and *.cpp files

  - the code to understand and fix/complete
  - you never start from scratch

### Makefile / cmake

  - prepared Makefile for easy compilation
  - “make” and “make clean” are available
  - cmake is also supported

### solution subdirectory

  - the solution to the exercise (“make solution”)
  - please do not use before trying !

Just follow the instructions
----------------------------

 - Each exercise comes with a set of instructions in the course
 - Also present in exercise subdir in markdown format
 - Very practical to read on github

How to test your setup
----------------------

### Just use hello exercise

 - go to code/hello
 - follow the README

### How to compile ?

  - cd code/hello
  - make
  - export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:.
  - ./hello

### Practically for valgrind/cppcheck

  - valgrind --tool=callgrind ./hello; kcachegrind
  - cppcheck .

Using lxplus
------------

  - lxplus is perfectly suitable for the exercises
  - it has all the needed compilers/tools in cvmfs

### Practically on lxplus8

  - source /cvmfs/sft.cern.ch/lcg/releases/gcc/12.1.0/x86_64-centos8-gcc12-opt/setup.sh
  - alternative options :
    + centos8 -> centos7
    + setup.sh -> setup.csh
  - export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:.
  - git clone https://github.com/hsf-training/cpluspluscourse.git
  - cd cpluspluscourse/code
  - cd hello
  - make
  - ./hello
