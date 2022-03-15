
all: mandel.so libmandelc.so
solution: mandel.so libmandelc.so

mandel.so:mandel_module.o libmandel.so
	${CXX} -shared -Wl,-undefined,dynamic_lookup $^ -o $@ `python3-config --ldflags`

mandel_module.o:mandel_module.cpp
	${CXX} -pthread -O3 -Wall -std=c++14 -fPIC -I. `python3-config --cflags` -c $< -o $@

libmandelc.so:mandel_cwrapper.o libmandel.so
	${CXX} -shared $^ -o $@

mandel_cwrapper.o:mandel_cwrapper.cpp
	${CXX} -O3 -Wall -std=c++14 -fPIC -c $< -o $@

libmandel.so:mandel.cpp Complex.hpp
	${CXX} -shared -O3 -Wall -std=c++14 -fPIC $< -o $@

clean:
	rm -rf *.o *.so *~ *pyc *pyo *svg
