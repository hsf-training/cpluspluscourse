compile: *.tex
	pdflatex -shell-escape $<
	pdflatex -shell-escape $<

clean:
	rm -f *.aux *.log *.nav *.out *.pyg *.snm *.vrb *.toc

clobber: clean
	rm -f *.pdf
