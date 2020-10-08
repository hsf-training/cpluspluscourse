compile: *.tex
	pdflatex -shell-escape $<
	pdflatex -shell-escape $<

sol:
	@echo && cd polymorphism && make test.sol && ./test.sol && echo
	@echo && cd virtual_inheritance && make test.sol && ./test.sol && echo
	@-echo && cd constness && make test.sol && ./test.sol && echo
	@echo && cd move && make test.sol && valgrind --tool=callgrind ./test.sol && echo
	@-echo && cd templates && make test.sol && ./test.sol && echo
	@echo && cd stl && make test.sol && ./test.sol && echo
	@echo && cd lambdas && make test.sol && ./test.sol && echo
	@echo && cd debug && make test.sol && ./test.sol && echo
	@echo && cd valgrind && make test.sol && ./test.sol && echo
	@echo && cd memcheck && cp -f Polygons.hpp Polygons.hpp.bak && cp Polygons.sol.hpp Polygons.hpp
	@-cd memcheck && make test && valgrind ./test
	@cd memcheck && mv -f Polygons.hpp.bak Polygons.hpp && echo
	@echo && cd helgrind && make test.sol && ./test.sol && echo
	@echo && cd cppcheck && make test.sol && ./test.sol && echo

clean:
	rm -f *.aux *.log *.nav *.out *.pyg *.snm *.vrb *.toc
	cd hello && make clean
	cd polymorphism && make clean
	cd virtual_inheritance && make clean
	cd constness && make clean
	cd move && make clean
	cd templates && make clean
	cd stl && make clean
	cd lambdas && make clean
	cd debug && make clean
	cd valgrind && make clean
	cd memcheck && make clean
	cd callgrind && make clean
	cd helgrind && make clean
	cd cppcheck && make clean

clobber: clean
	rm -f *.pdf

