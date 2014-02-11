all: clean compile compile 
fast: clean compile 

compile: C++Course.tex basicconcepts.tex objectorientation.tex advanced.tex c++11.tex
	pdflatex -shell-escape C++Course.tex

clean:
	rm -f *.aux *.log *.nav *.out *.pyg *.snm *.vrb *.toc C++Course.pdf
