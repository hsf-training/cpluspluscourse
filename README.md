# C++ course
<!-- ALL-CONTRIBUTORS-BADGE:START - Do not remove or modify this section -->
[![All Contributors](https://img.shields.io/badge/all_contributors-10-orange.svg?style=flat-square)](#contributors-)
<!-- ALL-CONTRIBUTORS-BADGE:END -->

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

The [cheat sheet](code/ExercisesCheatSheet_All.md) is only for mentors, with roadmap, solutions and key points to discuss.

Readmes are for students. These host the basic building instructions, give the name of the main program file, and possibly give a summary of the exercise goals and steps.

Inside the code, one gets more precise help on what should/could be done and also where (e.g. when the code is long and only one part needs to be worked on).

### About solutions

Each exercice should provide a solution in the `solution` subdirectory. For any `<name>.cpp` exercise, the solution should be called `solution/<name>.sol.cpp`.

### About building

For the time being, we maintain both a raw `Makefile` and a `CMakeLists.txt`.

The `make` command should work directly on any linux-like system. The `make solution` command should build the solution.

The `cmake` tool adds support for building on Windows. It is meant to be used in a `build` subdirectory:
```
mkdir build
cd build
cmake ..
make
make solution
```

## Contributors ✨

Thanks goes to these wonderful people ([emoji key](https://allcontributors.org/docs/en/emoji-key)):

<!-- ALL-CONTRIBUTORS-LIST:START - Do not remove or modify this section -->
<!-- prettier-ignore-start -->
<!-- markdownlint-disable -->
<table>
  <tr>
    <td align="center"><a href="http://includeio.stream/"><img src="https://avatars.githubusercontent.com/u/1433152?v=4?s=100" width="100px;" alt=""/><br /><sub><b>Abhishek L</b></sub></a><br /><a href="#content-theanalyst" title="Content">🖋</a></td>
    <td align="center"><a href="https://github.com/krasznaa"><img src="https://avatars.githubusercontent.com/u/30694331?v=4?s=100" width="100px;" alt=""/><br /><sub><b>Attila Krasznahorkay</b></sub></a><br /><a href="#content-krasznaa" title="Content">🖋</a></td>
    <td align="center"><a href="https://github.com/bernhardmgruber"><img src="https://avatars.githubusercontent.com/u/1224051?v=4?s=100" width="100px;" alt=""/><br /><sub><b>Bernhard Manfred Gruber</b></sub></a><br /><a href="#content-bernhardmgruber" title="Content">🖋</a></td>
    <td align="center"><a href="https://github.com/chavid"><img src="https://avatars.githubusercontent.com/u/4421289?v=4?s=100" width="100px;" alt=""/><br /><sub><b>David Chamont</b></sub></a><br /><a href="#content-chavid" title="Content">🖋</a></td>
    <td align="center"><a href="https://github.com/eguiraud"><img src="https://avatars.githubusercontent.com/u/10999034?v=4?s=100" width="100px;" alt=""/><br /><sub><b>Enrico Guiraud</b></sub></a><br /><a href="#content-eguiraud" title="Content">🖋</a></td>
    <td align="center"><a href="https://github.com/graeme-a-stewart"><img src="https://avatars.githubusercontent.com/u/8511620?v=4?s=100" width="100px;" alt=""/><br /><sub><b>Graeme A Stewart</b></sub></a><br /><a href="#content-graeme-a-stewart" title="Content">🖋</a></td>
    <td align="center"><a href="https://github.com/sponce"><img src="https://avatars.githubusercontent.com/u/731524?v=4?s=100" width="100px;" alt=""/><br /><sub><b>Sebastien Ponce</b></sub></a><br /><a href="#content-sponce" title="Content">🖋</a></td>
  </tr>
  <tr>
    <td align="center"><a href="https://github.com/roiser"><img src="https://avatars.githubusercontent.com/u/807095?v=4?s=100" width="100px;" alt=""/><br /><sub><b>Stefan Roiser</b></sub></a><br /><a href="#content-roiser" title="Content">🖋</a></td>
    <td align="center"><a href="https://github.com/hageboeck"><img src="https://avatars.githubusercontent.com/u/16205615?v=4?s=100" width="100px;" alt=""/><br /><sub><b>Stephan Hageboeck</b></sub></a><br /><a href="#content-hageboeck" title="Content">🖋</a></td>
    <td align="center"><a href="https://github.com/bcouturi"><img src="https://avatars.githubusercontent.com/u/7208288?v=4?s=100" width="100px;" alt=""/><br /><sub><b>bcouturi</b></sub></a><br /><a href="#content-bcouturi" title="Content">🖋</a></td>
  </tr>
</table>

<!-- markdownlint-restore -->
<!-- prettier-ignore-end -->

<!-- ALL-CONTRIBUTORS-LIST:END -->

This project follows the [all-contributors](https://github.com/all-contributors/all-contributors) specification. Contributions of any kind welcome!
