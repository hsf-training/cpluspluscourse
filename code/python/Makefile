all: mandel.so libmandelc.so
solution: mandel.so libmandelc.so

mandel.so:mandel_module.o libmandel.so
	g++ -shared $^ -o $@

mandel_module.o:mandel_module.cpp
	g++ -pthread -O3 -Wall -std=c++14 -fPIC -I. -I/usr/include/python3.8 -c $< -o $@

libmandelc.so:mandel_cwrapper.o libmandel.so
	g++ -shared $^ -o $@

mandel_cwrapper.o:mandel_cwrapper.cpp
	g++ -O3 -Wall -std=c++14 -fPIC -c $< -o $@

libmandel.so:mandel.cpp Complex.hpp
	g++ -shared -O3 -Wall -std=c++14 -fPIC $< -o $@

clean:
	rm -rf *.o *.so *~ *pyc *pyo *svg
