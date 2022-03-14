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

## Exercises guidelines

- Prefer "east const" for new stuff.
- For the time being, maintain both a `Makefile` and a `CMakeLists.txt`.
- Each exercise should have a `solution` subdirectory.
- `CheatSheet` file(s) is/are a roadmap for mentors.
- Instructions for students stay in `README.md` files and/or directly in the main exercise file.
