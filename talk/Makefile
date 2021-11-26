all: compile2
fast: compile

compile: *.tex
	pdflatex -shell-escape C++Course.tex

compile2: *.tex
	pdflatex -shell-escape C++Course.tex
	pdflatex -shell-escape C++Course.tex

clean:
	rm -rf *.aux */*.aux *.log *.nav *.out *.pyg *.snm *.vrb *.toc _minted-C++Course

clobber: clean
	rm -f C++Course.pdf
