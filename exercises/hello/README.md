
# Hello World !

This example should help to check that your machine is well installed.

## make vs cmake

On any linux like system, provided you have a "recent enough" g++, this should work out of the box:
```
make
./hello
```

On native Windows, build with `cmake`:
```
mkdir build
cd build
cmake ..
cmake --build .
Debug/hello.exe
```

## valgrind & callgrind & graphical tools

Try:
```
valgrind --tool=callgrind ./hello
kcachegrind
```

## cppcheck

Try:
```
cppcheck *.hpp *.cpp
```
