# C++ course

[![gh actions](https://github.com/hsf-training/cpluspluscourse/actions/workflows/workflow.yml/badge.svg)](https://github.com/hsf-training/cpluspluscourse/actions)
[![pre-commit.ci status](https://results.pre-commit.ci/badge/github/hsf-training/cpluspluscourse/master.svg)](https://results.pre-commit.ci/latest/github/hsf-training/cpluspluscourse/master)
[![HSF Training Center](https://img.shields.io/badge/HSF%20Training%20Center-browse-ff69b4)](https://hepsoftwarefoundation.org/training/curriculum.html)

This repository contains all material for the C++ Course taught at CERN from
Sebastien Ponce (LHCb).

## 📎 Getting the latest PDF

For each commit, the slides are compiled as a PDF and uploaded as "artifact".
The [GitHub docs](https://docs.github.com/en/actions/managing-workflow-runs/downloading-workflow-artifacts)
explain how you can download the PDF.

## 🧰 Development setup

Make sure to install the pre-commit hooks:

```bash
pip3 install pre-commit
# cd to repository
pre-commit install
```

### Spell checking

Spell check is performed with the [codespell](https://github.com/codespell-project/codespell)
pre-commit hook on every commit. To ignore words you can put them in the
`codespell.txt` file. This file should list the supposedly misspelled words with
one word per line and is case-sensitive.

## C++ guidelines

- Prefer "east const" for new stuff.

## Exercises guidelines

### About instructions for mentors and students

Cheat sheet is only for mentors, with roadmap, solutions and key points to discuss.

Readmes are for stundents. They hosts the "basic building instructions, gives the name of the main program file, and possibly gives a
summary of the exercise goals and steps.

Inside the code, one get more precise help on what should/could be done and also where (when the code is long and only one part needs to be worked on).

### About solutions

Each exercice should provide some solution in `solution` subdirectory. For any `<name>.cpp` exercise, the solution should be called `solution/<name>.sol.cpp`.

### About building

For the time being, we maintain both a raw `Makefile` and a `CMakeLists.txt`.

The `make` command which should work straightfully on any linux-like system. The `make solution` command should build the solution.
- Do we require gmake ?
- Do we require bash shell ?

The `cmake` tool add support for Windows. It is meant to be used in a `build` subdirectory:
```
mkdir build
cd build
cmake ..
make
make solution
```
