
## Instructions for the "polymorphism" exercise

* look at the code
* open `test.cpp`
* create a Pentagon, call its `perimeter` method
* create an Hexagon, call its `perimeter` method
* create an Hexagon, call its parent’s `perimeter` method
* retry with virtual methods


## Instructions for the "compiler chain" exercise

* preprocess `Polygons.cpp` (`cpp` or `gcc -E -o output`)
* compile `Polygons.o` and `test.o` (`g++ -c -o output`)
* use `nm` to check symbols
* see link statement using `g++ -v`
* see library dependencies with `ldd`
* look at the `Makefile`
* try `make clean; make`