# Contributing

[HSF Training][hsf-training] is an open source project, and we welcome
contributions of all kinds: fixes to existing material, new exercises, bug
reports, and reviews of proposed changes.

## Contributor agreement

By contributing, you agree that we may redistribute your work under the
[license](LICENSE) of this repository. Everyone involved in HSF Training agrees
to abide by our [code of conduct][conduct].

## How to contribute

- **Report a problem or suggest an improvement** by [opening an issue][issues].
  Mistakes, awkward wording, outdated software and broken links are all
  worth reporting.
- **Propose a change** with a pull request:
  1. Fork this repository and create a branch from `master`.
  2. Make your changes, following the C++ and exercise guidelines in the
     [README](README.md). If you change an exercise, check that it still
     builds with both `make` and CMake (see "About building" in the README).
  3. Install the [pre-commit][pre-commit] hooks (`pip install pre-commit && pre-commit install`)
     so that formatting and spelling checks run before you commit.
  4. Open a pull request against `master` and describe what you changed and why.

If you're looking for ideas, see this repository's issues, or the
[good first issues][gfis] across all HSF Training repositories.

The course maintainers are volunteers, so it may take a few days to get a reply. If
nobody responds, feel free to mention the previous contributors or the training
conveners (`@hsf-training/training-conveners`) in your issue or pull request.

[hsf-training]: https://hepsoftwarefoundation.org/activities/training.html
[conduct]: https://github.com/hsf-training/.github/blob/main/CODE_OF_CONDUCT.md
[issues]: https://github.com/hsf-training/cpluspluscourse/issues
[pre-commit]: https://pre-commit.com/
[gfis]: https://github.com/search?q=org%3Ahsf-training+label%3A%22good+first+issue%22+is%3Aissue+is%3Aopen+archived%3Afalse&type=issues
