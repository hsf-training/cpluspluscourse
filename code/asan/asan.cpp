#include <string>
#include <iostream>
#include <memory>

// Task 1:
// Here we write past the end of a character array on the stack.
// This doesn't necessarily crash the program, but it's certainly a bad idea,
// as it will corrupt data.
//
// - Compile and run the program without address sanitizer. Maybe you are lucky
//   and it doesn't crash, but the arrays are probably corrupted now.
//   (To make it crash, you can write more characters, but that's not necessary for
//   what we want to try with asan.)
// - Add
//   -fsanitize=address -fno-omit-frame-pointer -g
//   to the compile options and retry.
//   - For the Makefile, just add the above flags to the command line.
//   - For CMake, either add to asan/CMakeLists.txt:
//     target_compile_options(asan PUBLIC -fsanitize=address -fno-omit-frame-pointer -g)
//     target_link_libraries(asan PUBLIC -fsanitize=address)
//     or reconfigure the entire project with:
//     cmake -DCMAKE_CXX_FLAGS="-fsanitize=address -fno-omit-frame-pointer -g" -DCMAKE_EXE_LINKER_FLAGS="-fsanitize=address" .
//     Note: If you reconfigure everything, all other exercises will also be built with asan instrumentation!
// - Run the program, and inspect asan's output. It should give a detailed description of
//   the problem, where the memory was allocated, etc.
// - Fix the problem.
void stackOverflow() {
  char a[] = "1234";
  char b[] = "5678";

  std::cout << "a='" << a << "\'\n";
  std::cout << "b='" << b << "\'\n";

  char* ptr = a;

  std::cout << "Now writing into the array:\n";
  for (unsigned int i = 0; i < 10; ++i) {
    ptr[i] = static_cast<char>('a' + i);
  }

  std::cout << "a='" << a << "\'\n";
  std::cout << "b='" << b << "\'\n";
}

// Task 2:
// Never return references or pointers to stack memory
// or temporary variables. They vanish when the function returns.
// - After you fixed the problem in Task 1, asan should immediately point to the function below. Try it.
// - If asan doesn't report a "use-after-free", the compiler might have inlined the function.
//   You can try different optimisation flags such as -O0 / -O1 / -O2
// - Fix the problem.
std::string& useAfterFree() {
  auto str = std::make_unique<std::string>("A temporary string");
  return *str;
}

// Task 3:
// Use this functions to test leak sanitizer.
// - Start the program with
//   ASAN_OPTIONS=detect_leaks=1 ./asan
//   and see how the information given there helps tracing down the leak.
// - The fix is relatively easy:
//   - Option 1: Do as in useAfterFree()
//   - Option 2: Put the string on the stack.
std::string& memoryLeak() {
  auto str = new std::string("This string will leak");
  return *str;
}

int main() {
  stackOverflow();
  std::cout << "String from useAfterFree is:'" << useAfterFree() << "\'\n";
  std::cout << "Dynamically allocated string is:'" << memoryLeak() << "\'\n";

  return 0;
}
