compile: *.tex
	pdflatex -shell-escape $<
	pdflatex -shell-escape $<

sol:
	@echo && cd hello && make && ./hello && echo
	@echo && cd polymorphism && make test.sol && ./test.sol && echo

clean:
	rm -f *.aux *.log *.nav *.out *.pyg *.snm *.vrb *.toc
	cd hello && make clean
	cd polymorphism && make clean

clobber: clean
	rm -f *.pdf

