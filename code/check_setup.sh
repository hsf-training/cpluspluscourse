#!/bin/bash

RED='\033[0;31m'
YEL='\033[0;33m'
NORMAL='\033[0m'
COL=12

exit_status=0

# from: https://stackoverflow.com/a/4024263
function version_less() {
  [ "$1" = "`echo -e "$1\n$2" | sort -V | head -n1`" ]
}

function check_tool() {
  min_version=$2 || "0"
  required=$3 || true
  if [ -x "$(command -v $1)" ]
  then
    version=$($1 --version | grep -o -E "[0-9]+.[0-9]+(.[0-9]+)?" | head -1)
    if version_less $version $min_version
    then
      printf "%-${COL}s found, ${RED}version: ${version}, need at least: ${min_version}${NORMAL}\n" $1
    else
      printf "%-${COL}s found, version: ${version}\n" $1
      return 0
    fi
  elif $required
  then
    printf "${RED}%-${COL}s not found, but required${NORMAL}\n" $1
    exit_status=1
  else
    printf "${YEL}%-${COL}s not found, but optional${NORMAL}\n" $1
  fi
  return 1
}

# compiler
check_tool g++ 10.0.0 false || check_tool clang++ 11.0.0 false || { echo -e "${RED}No supported compiler found${NORMAL}"; exit_status=1; } # clang does not work for header_units exercise

# build tools
check_tool make
check_tool cmake 3.12.0
check_tool ccmake 3.12.0 false

# debugger
check_tool gdb 10.0.0 false || check_tool lldb 11.0.0 false || { echo -e "${RED}No supported debugger found${NORMAL}"; exit_status=1; }

# utils
check_tool nm
check_tool ldd 0.0 false || check_tool otool 0.0 false || { echo -e "${RED}Missing ldd or otool${NORMAL}"; exit_status=1; }

# tools
check_tool valgrind
check_tool kcachegrind
check_tool cppcheck
check_tool clang-format
check_tool clang-tidy
check_tool python3

exit $exit_status
