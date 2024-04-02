#pragma once

#include <bitset>
#include <iostream>
#include <iomanip>
#include <string>

#ifdef _MSC_VER
std::string demangle(std::string_view input) { return std::string{input}; }
#else
#include <cxxabi.h>
std::string demangle(std::string_view input) {
  int status;
  return abi::__cxa_demangle(input.data(), NULL, NULL, &status);
}
#endif

// This helper prints type and value of an expression
void printWithTypeInfo(std::string expression, auto const & t, bool useBitset = false) {
  const auto & ti = typeid(t);
  const std::string realname = demangle(ti.name());

  std::cout << std::left << std::setw(30) << expression << " type=" << std::setw(20) << realname << "value=";
  if (useBitset) {
    std::cout << std::bitset<16>(t) << "\n";
  } else {
    std::cout << std::setprecision(25) << t << "\n";
  }
}

// This macro both prints and evaluates an expression:
#define print(A) printWithTypeInfo("Line " + std::to_string(__LINE__) + ": "#A, A);
#define printBinary(A) printWithTypeInfo("Line " + std::to_string(__LINE__) + ": "#A, A, true);
