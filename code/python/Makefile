PYTHON_VERSION=$(word 2, $(shell python3 --version))
PYTHON_LOCATION=$(dir $(shell which python3))
PYTHON_MAJOR=$(word 1,$(subst ., ,$(PYTHON_VERSION)))
PYTHON_MINOR=$(word 2,$(subst ., ,$(PYTHON_VERSION)))
PYTHON_INCLUDE_BASE=$(PYTHON_LOCATION)../include/python$(PYTHON_MAJOR).$(PYTHON_MINOR)
PYTHON_INCLUDE=$(if $(wildcard $(PYTHON_INCLUDE_BASE)m/Python.h),$(PYTHON_INCLUDE_BASE)m, $(PYTHON_INCLUDE_BASE))

all: mandel.so libmandelc.so
solution: mandel.so libmandelc.so

mandel.so:mandel_module.o libmandel.so
	${CXX} -shared $^ -o $@

mandel_module.o:mandel_module.cpp
	${CXX} -pthread -O3 -Wall -std=c++14 -fPIC -I. -I$(PYTHON_INCLUDE) -c $< -o $@

libmandelc.so:mandel_cwrapper.o libmandel.so
	${CXX} -shared $^ -o $@

mandel_cwrapper.o:mandel_cwrapper.cpp
	${CXX} -O3 -Wall -std=c++14 -fPIC -c $< -o $@

libmandel.so:mandel.cpp Complex.hpp
	${CXX} -shared -O3 -Wall -std=c++14 -fPIC $< -o $@

clean:
	rm -rf *.o *.so *~ *pyc *pyo *svg

debug:
	@echo Python minor version: $(PYTHON_INCLUDE)
