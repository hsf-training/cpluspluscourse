
# Hello World !

This example should help to check that your machine is well installed.

## make & cmake

On linux, provided you have a "recent enough" g++, this should work directly:
```
make
./hello
```

On windows, it may be mandatory to run `cmake` first:
```
cmake .
make
./hello
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
