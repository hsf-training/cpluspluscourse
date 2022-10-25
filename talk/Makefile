all: C++Course.pdf

LATEXMK=latexmk
OPTIONS=-pdf -shell-escape -halt-on-error

essentials: all
essentials: OPTIONS+=-pretex='\basictrue'

preview: all
preview: OPTIONS+=-pvc

ifneq ($(V), 1)
	OPTIONS+=-quiet
else
	OPTIONS+=-interaction=nonstopmode
endif

.PHONY: clean clobber FORCE

%.pdf: %.tex FORCE
	$(LATEXMK) $(OPTIONS) $<

clean:
	$(LATEXMK) -quiet -c

clobber:
	$(LATEXMK) -quiet -C
