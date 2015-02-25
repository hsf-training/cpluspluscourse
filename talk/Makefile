all: clean compile2
fast: clean compile 

compile: C++Course.tex basicconcepts.tex objectorientation.tex advanced.tex c++11.tex
	pdflatex -shell-escape C++Course.tex

compile2: C++Course.tex basicconcepts.tex objectorientation.tex advanced.tex c++11.tex
	pdflatex -shell-escape C++Course.tex
	pdflatex -shell-escape C++Course.tex

clean:
	rm -f *.aux *.log *.nav *.out *.pyg *.snm *.vrb *.toc

clobber: clean
	rm -f C++Course.pdf
