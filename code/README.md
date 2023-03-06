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
 - any C++ compiler supporting C++20
 - C++17 compiler will do for most of the exercises though
 - git for getting/managing your code

### Good to have

 - `gdb` to debug your problems
 - `valgrind`, `kcachegrind`, `cppcheck`, `clang-format` and `clang-tidy` for corresponding exercises
 - `g++` or `clang++` as C++ compiler for sanitizer exercises

### C++ and python specific needs

 - `python3`, `libpython3-dev`
 - `ctypes`, `matplotlib`, `numpy` python packages

### A word on timing

  - several exercises ask you to "time" things
  - here it's always sufficient to use the `time` command line:
  ```shell
  time ./racing
  real 0m0.022s
  user 0m0.011s
  sys  0m0.021s
  ```
  - and just take the first number (real time)

Getting exercises’ code
-----------------------

```bash
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
  - `make` and `make clean` are available
  - CMake is also supported

### solution subdirectory

  - the solution to the exercise (`make solution`)
  - please do not use before trying!

Just follow the instructions
----------------------------

 - each exercise comes with a set of instructions in the course
 - also present in exercise subdir in markdown format
 - very practical to read on github

How to test your setup
----------------------

### Just use hello exercise

 - go to [`code/hello`](hello)
 - follow the `README.md`

### How to compile ?

```bash
cd code/hello
make
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:.
./hello
```

### Practically for valgrind/cppcheck

  - `valgrind --tool=callgrind ./hello; kcachegrind`
  - `cppcheck .`

Using lxplus
------------

  - lxplus is perfectly suitable for the exercises
  - it has all the needed compilers/tools

### Practically on lxplus9

```bash
ssh lxplus9.cern.ch
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:.
git clone https://github.com/hsf-training/cpluspluscourse.git
cd cpluspluscourse/code/hello
make
./hello
```

Using Windows
-------------

There are multiple options if you bring a Windows machine to the course:

1. Use the Windows Subsystem for Linux (WSL)
2. Use an ssh client and connect to lxplus
3. Use Visual Studio and the native Windows compiler (MSVC)

We advise to use either [WSL](#wsl) or [lxplus](#lxplus), so a non-Windows experience.
This way, you can follow all exercises, especially the ones on tools, which are mostly Linux focused.
Also, we can ensure that mentors can help you in case you get stuck.
Using lxplus is probably the easiest, but if you have a really hard time using the terminal,
you can go for WSL and use Visual Studio Code.

### WSL

Important: if you have [VirtualBox](https://www.virtualbox.org/) installed on Windows do not try to install WSL2,
due to [this issue](https://github.com/MicrosoftDocs/WSL/issues/798).
It will either not work or run very slow.
Instead, we recommend you use VirtualBox directly to set up a suitable virtualised Linux environment.
Or use [lxplus](#lxplus).

The procedure is described in detail [here](https://docs.microsoft.com/en-us/windows/wsl/install).

#### Windows 10 (version 2004 or higher)

The installation of WSL is as easy as running (with Administrator privileges):

    wsl --install
    # and reboot

This will activate WSL 2 and install Ubuntu 22.04.
If you prefer a different Linux distribution, run:

    wsl --list --online
    wsl --install -d <Distro>

#### Older Windows 10 versions

On older Windows versions, the procedure is more involved and documented [here](https://learn.microsoft.com/en-us/windows/wsl/install-manual).

It's lightly recommended to use WSL 2 as the Linux compatibility is better,
but everything in the C++ course should work on either the WSL 1 or 2 backends.

#### Setup your Linux

Start your Linux inside a terminal by calling either `wsl` or `bash`.
When you start for the first time you'll be asked to create a user account.
Then you can login and install the packages which are necessary for the tutorial:

    sudo -s # will ask for your password
    apt update
    apt upgrade
    apt install git g++ gdb valgrind cppcheck cmake clang-format clang-tidy python3

Verify that the tools are there by running:

    $ g++ --version
    g++-11 (Ubuntu 11.2.0-19ubuntu1) 11.2.0
    Copyright (C) 2021 Free Software Foundation, Inc.
    This is free software; see the source for copying conditions.  There is NO
    warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

You can install an editor inside the WSL system itself,
but we recommend to use [VS Code](#visual-studio-code) in Windows natively.

### lxplus

Recent versions of Windows 10 (version 1809 or higher) come with an ssh client.
If that does not work, you can install a third-party ssh client for Windows.
We have good experience with https://www.putty.org/.

Open Windows Terminal, or PowerShell if you run an older version of Windows.
Use `ssh lxplus9.cern.ch` to connect to lxplus.
Follow the [lxplus guide](#using-lxplus) from here.

If you are having troubles with the terminal based environment,
you can also try to use [VS Code](#visual-studio-code) natively on your Windows to connect to lxplus.
We have not tested this seriously yet, but it should work.

### Visual Studio

If you want to stay on Windows, make sure you have Visual Studio and cmake installed.
Visual Studio comes in a few distributions, some requiring a paid license.
The Community edition is free for academic use or for working on open source software.
During installation of Visual Studio, select the `Desktop development with C++` workload.

Visual Studio Community: https://visualstudio.microsoft.com/vs/community/
CMake: https://cmake.org/download/

For the exercises, you will use the standard CMake workflow as described in the course slides (create a build directory, run cmake, etc.).
CMake will create a Visual Studio solution file `.sln` in the build directory,
which you can open to start working on an example within the Visual Studio IDE.

### Visual Studio Code

For developing on Windows natively,
but compiling and running on a remote Linux system (including WSL),
we recommend using Visual Studio Code (VS Code).
VS Code is a more lightweight code editor and not to be confused with the full-blown IDE Visual Studio.
Please install VS Code from [this website](https://code.visualstudio.com/Download).

For remote development you will also need the following extensions to VS Code:

 - WSL
 - Remote - SSH
 - C/C++ Extension Pack

You can install them from the extension menu (Ctrl + Shift + X).

There are two ways to launch VS Code for working with WSL:

1. GUI first: Launch VS Code on Windows.
   Run from the command palette (Ctrl + Shift + P), `Remote-WSL New Window`.
   VS Code will now begin a session running inside the WSL Linux on your system.
   You can click on `Clone Git Repository...` or, if you already cloned the GitHub repository, click `Open Folder...`.
   You can also open a terminal with bash via the menu `Terminal` -> `New Terminal`.
   Use the newly opened terminal to type commands for building, debugging, etc.
2. Terminal first: Launch `bash` or `wsl` either via a powershell or from Windows Terminal (if installed).
   Navigate to your cloned GitHub repository, or `git clone` it if you have not done it yet.
   Inside the `<repo>/code` or any `<repo>/code/example` directory, run `code .`.
   This will launch VS Code on Windows, already connected to your WSL and set to the right folder.
   Use your initial terminal to type commands for building, debugging etc.

More documentation on using WSL with Visual Studio Code can be found [here](https://code.visualstudio.com/docs/remote/wsl).

Experimental (we have not tested this seriously):
You can also use VS Code to work on lxplus.
Run from the command palette (Ctrl + Shift + P), `Remote-SSH Connect to host...`.
Then enter `<user>@lxplus9.cern.ch`, then your password.
The first connection takes a while for VS Code to setup its server on lxplus.
