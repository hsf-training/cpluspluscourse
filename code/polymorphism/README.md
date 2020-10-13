## Instructions for the "polymorphism" exercise

* look at the code
* open `trypoly.cpp`
* create a Pentagon, call its `perimeter` method
* Compile via `make`, execute via `./trypoly`
  * you may have to add current directory to your LD_LIBRARY_PATH :
```shell
  export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:. 
```
* create an Hexagon, call its `perimeter` method
* recompile and check what happens
* create an Hexagon, call its parent’s `perimeter` method
* recompile and check again
* retry with virtual methods


## Instructions for the "compiler chain" exercise

* preprocess `Polygons.cpp` (`cpp` or `gcc -E -o output`)
* compile `Polygons.o` and `trypoly.o` (`g++ -c -o output`)
* use `nm` to check symbols in '.o' files
* look at the `Makefile`
* try `make clean; make`
* see linking stage using `g++ -v`
  * just add a -v in the Makefile command for trypoly
  * run make clean; make
  * look at the collect 2 line, from the end up to '-o trypoly'
* see library dependencies with `ldd`
