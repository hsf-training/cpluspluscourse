# C++ course

[![HSF Training Center](https://img.shields.io/badge/HSF%20Training%20Center-browse-ff69b4)](https://hepsoftwarefoundation.org/training/curriculum.html)
<!-- ALL-CONTRIBUTORS-BADGE:START - Do not remove or modify this section -->
[![All Contributors](https://img.shields.io/badge/all_contributors-11-orange.svg?style=flat-square)](#contributors-)
<!-- ALL-CONTRIBUTORS-BADGE:END -->

[![pre-commit.ci status](https://results.pre-commit.ci/badge/github/hsf-training/cpluspluscourse/master.svg)](https://results.pre-commit.ci/latest/github/hsf-training/cpluspluscourse/master)
[![gh actions](https://github.com/hsf-training/cpluspluscourse/actions/workflows/build-slides.yml/badge.svg)](https://github.com/hsf-training/cpluspluscourse/actions)
[![gh actions](https://github.com/hsf-training/cpluspluscourse/actions/workflows/build-exercises.yml/badge.svg)](https://github.com/hsf-training/cpluspluscourse/actions)
[![gh actions](https://github.com/hsf-training/cpluspluscourse/actions/workflows/publish-slides.yml/badge.svg)](https://github.com/hsf-training/cpluspluscourse/actions)

This repository contains all material for the C++ Course taught at CERN from
Sebastien Ponce (LHCb).

## Next events

Please check the [Indico agenda](https://indico.cern.ch/category/11733/).

## 📎 Getting the latest PDF

For each commit to master, the slides are compiled to a PDF and uploaded to the [download](https://github.com/hsf-training/cpluspluscourse/tree/download) branch.

 - Latest [essentials course PDF](https://github.com/hsf-training/cpluspluscourse/raw/download/talk/C%2B%2BCourse_essentials.pdf).
 - Latest [full course PDF](https://github.com/hsf-training/cpluspluscourse/raw/download/talk/C%2B%2BCourse_full.pdf).

## 📹 Video recordings & events

Video recordings are available in the past events.

* [8th HEP C++ Course and Hands-on Training (essentials), Manchester, August 2023](https://indico.cern.ch/event/1266661/)
* [7th HEP C++ Course and Hands-on Training (essentials), JLAB, May 2023](https://indico.cern.ch/event/1266632/)
* [6th HEP C++ Course and Hands-on Training (essentials), CERN, March 2023](https://indico.cern.ch/event/1229412/)
* [5th HEP C++ Course and Hands-on Training (advanced), CERN, October 2022](https://indico.cern.ch/event/1172498/)
* [4nd HEP C++ Course and Hands-on Training (essentials), CERN, March 2022](https://indico.cern.ch/event/1119339/)
* [3rd HEP C++ Course and Hands-on Training, CERN, August 2021](https://indico.cern.ch/event/1019089/)
* [2nd HEP C++ Course and Hands-on Training, virtual, January 2021](https://indico.cern.ch/event/979067/)
* [1st HEP C++ Course and Hands-on Training (2020 October)](https://indico.cern.ch/event/946584/)

Check [this page](https://hepsoftwarefoundation.org/Schools/events.html) for announcements of upcoming training events (including those with this material).

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

### Instructions for mentors and students

Students should start with the README in the respective exercise folders. These have the basic building instructions, give the name of the main program file, and possibly give a summary of the exercise goals and steps.

Inside the code, one gets more precise help on what should/could be done. If the code is longer and only some parts need to be touched, this is often pointed out with comments.

### Solutions to exercises

Each exercise should provide a solution in the `solution` subdirectory. For any `<name>.cpp` exercise, the solution should be called `solution/<name>.sol.cpp`.
We invite students to only consult the solution when they completed an exercise or when they are really stuck. The preferred order is:
1. Work on the exercise and consult the slides
2. Discuss problems and questions with the class and the mentor
3. Consult the solution

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

### For Mentors

Depending on which course is running, consult the schedule for exercise sessions in [essentials](exercises/ExerciseSchedule_EssentialCourse.md) or [advanced](exercises/ExerciseSchedule_AdvancedCourse.md).
For mentors, there is a [cheat sheet](exercises/ExercisesCheatSheet.md) with hints towards the solutions and key points to discuss during the exercise sessions.

## Contributors ✨

Thanks go to these wonderful people ([emoji key](https://allcontributors.org/docs/en/emoji-key)):

<!-- ALL-CONTRIBUTORS-LIST:START - Do not remove or modify this section -->
<!-- prettier-ignore-start -->
<!-- markdown-link-check-disable -->
<table>
  <tr>
    <td align="center"><a href="http://includeio.stream/"><img src="https://avatars.githubusercontent.com/u/1433152?v=4?s=100" width="100px;" alt=""/><br /><sub><b>Abhishek L</b></sub></a><br /><a href="#content-theanalyst" title="Content">🖋</a></td>
    <td align="center"><a href="https://github.com/krasznaa"><img src="https://avatars.githubusercontent.com/u/30694331?v=4?s=100" width="100px;" alt=""/><br /><sub><b>Attila Krasznahorkay</b></sub></a><br /><a href="#content-krasznaa" title="Content">🖋</a></td>
    <td align="center"><a href="https://github.com/bernhardmgruber"><img src="https://avatars.githubusercontent.com/u/1224051?v=4?s=100" width="100px;" alt=""/><br /><sub><b>Bernhard Manfred Gruber</b></sub></a><br /><a href="#content-bernhardmgruber" title="Content">🖋</a></td>
    <td align="center"><a href="https://github.com/chavid"><img src="https://avatars.githubusercontent.com/u/4421289?v=4?s=100" width="100px;" alt=""/><br /><sub><b>David Chamont</b></sub></a><br /><a href="#content-chavid" title="Content">🖋</a></td>
    <td align="center"><a href="https://github.com/eguiraud"><img src="https://avatars.githubusercontent.com/u/10999034?v=4?s=100" width="100px;" alt=""/><br /><sub><b>Enrico Guiraud</b></sub></a><br /><a href="#content-eguiraud" title="Content">🖋</a></td>
    <td align="center"><a href="https://github.com/graeme-a-stewart"><img src="https://avatars.githubusercontent.com/u/8511620?v=4?s=100" width="100px;" alt=""/><br /><sub><b>Graeme A Stewart</b></sub></a><br /><a href="#content-graeme-a-stewart" title="Content">🖋</a></td>
    <td align="center"><a href="https://www.lieret.net/"><img src="https://avatars.githubusercontent.com/u/13602468?v=4?s=100" width="100px;" alt=""/><br /><sub><b>Kilian Lieret</b></sub></a><br /><a href="#infra-klieret" title="Infrastructure (Hosting, Build-Tools, etc)">🚇</a></td>
  </tr>
  <tr>
    <td align="center"><a href="https://github.com/sponce"><img src="https://avatars.githubusercontent.com/u/731524?v=4?s=100" width="100px;" alt=""/><br /><sub><b>Sebastien Ponce</b></sub></a><br /><a href="#content-sponce" title="Content">🖋</a></td>
    <td align="center"><a href="https://github.com/roiser"><img src="https://avatars.githubusercontent.com/u/807095?v=4?s=100" width="100px;" alt=""/><br /><sub><b>Stefan Roiser</b></sub></a><br /><a href="#content-roiser" title="Content">🖋</a></td>
    <td align="center"><a href="https://github.com/hageboeck"><img src="https://avatars.githubusercontent.com/u/16205615?v=4?s=100" width="100px;" alt=""/><br /><sub><b>Stephan Hageboeck</b></sub></a><br /><a href="#content-hageboeck" title="Content">🖋</a></td>
    <td align="center"><a href="https://github.com/bcouturi"><img src="https://avatars.githubusercontent.com/u/7208288?v=4?s=100" width="100px;" alt=""/><br /><sub><b>bcouturi</b></sub></a><br /><a href="#content-bcouturi" title="Content">🖋</a></td>
  </tr>
</table>

<!-- prettier-ignore-end -->

<!-- ALL-CONTRIBUTORS-LIST:END -->

This project follows the [all-contributors](https://github.com/all-contributors/all-contributors) specification. Contributions of any kind welcome!
