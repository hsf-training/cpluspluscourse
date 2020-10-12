
# Hello World !

This example should help to check that your machine is well installed.

## g++ & make

Try:
```
make
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:.
./hello
```

## valgrind & callgrind & X11

Try:
```
valgrind --tool=callgrind ./hello
kcachegrind
```

## cppcheck

Try:
```
cppcheck .
```
