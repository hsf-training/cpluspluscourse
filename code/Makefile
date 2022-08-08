compile: *.tex
	pdflatex -shell-escape $<
	pdflatex -shell-escape $<

TESTDIRS = callgrind cppcheck header_units control hello move python smartPointers templates virtual_inheritance \
	   debug helgrind lambdas memcheck polymorphism race stl valgrind
NOCOMPILETESTDIRS = constness

solution:
	for dir in ${TESTDIRS}; do \
		cd $${dir}; \
		make $@; \
		cd ..; \
	done

clean:
	rm -f *.aux *.log *.nav *.out *.pyg *.snm *.vrb *.toc
	for dir in ${TESTDIRS} ${NOCOMPILETESTDIRS}; do \
		cd $${dir}; \
		make clean; \
		cd ..; \
	done

clobber: clean
	rm -f *.pdf
