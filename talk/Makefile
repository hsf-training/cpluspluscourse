all: C++Course.pdf

LATEXMK=latexmk
OPTIONS=-pdf -shell-escape -halt-on-error

essentials: all
essentials: OPTIONS+=-usepretex='\def\makebasic{}'

preview: all
preview: OPTIONS+=-pvc

ifeq ($(QUIET), 1)
	OPTIONS+=-quiet
else
	OPTIONS+=-interaction=nonstopmode
endif

ifeq ($(HEPCPP_ESSENTIALS), 1)
	OPTIONS+=-usepretex='\def\makebasic{}'
endif

.PHONY: clean clobber FORCE

%.pdf: %.tex FORCE
	$(LATEXMK) $(OPTIONS) $<

clean:
	$(LATEXMK) -C

clobber:
	$(LATEXMK) -C
	$(RM) C++Course.pdf
