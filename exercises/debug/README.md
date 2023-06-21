## Instructions for the "debug" exercise

* compile, run, see the crash
* run it in gdb
* inspect backtrace, variables to understand the problem
* try stepping through the code using 'step' and 'next', use breakpoints and continue to get familiar with gdb
* fix the bug

### Some useful gdb commands

| Command                   | Effect                                                        |
|---------------------------|---------------------------------------------------------------|
| `gdb ./randomize`         | launch the debugger with the given executable                 |
| `gdb --tui ./randomize`   | same as above, but with terminal user interface enabled       |
| `tui enable`              | enabled the terminal user interface                           |
| `run`                     | runs the program                                              |
| `bt, backtrace`           | show a backtrace (list of stack frames) of the current thread |
| `up`                      | navigate one stack frame up                                   |
| `down`                    | navigate one stack frame down                                 |
| `s, step`                 | execute current line, stop at earliest next occasion          |
| `n, next`                 | continue until next line or function exits                    |
| `c, continue`             | continue execution                                            |
| `print <var>`             | show current value of variable <var>                          |
| `info locals`             | show the values of all local variables                        |
| `info args`               | show the values of all function arguments                     |
| `br <linenr>`             | put a breakpoint at line <linenr>                             |
| `info br`:                | list active breakpoints                                       |
| `enable/disable/delete #` | enable/disable/delete breakpoints                             |
