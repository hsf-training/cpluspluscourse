mendel.so:mendel_module.o mendel_cwrapper.o libmendel.so
	g++ -shared $^ -o $@

mendel_module.o:mendel_module.cpp libmendelc.so
	g++ -pthread -O3 -Wall -std=c++14 -fPIC -I. -I/usr/include/python2.7 -c $< -o $@

libmendelc.so:mendel_cwrapper.o libmendel.so
	g++ -shared $^ -o $@

mendel_cwrapper.o:mendel_cwrapper.cpp
	g++ -O3 -Wall -std=c++14 -fPIC -c $< -o $@

libmendel.so:mendel.cpp Complex.hpp
	g++ -shared -O3 -Wall -std=c++14 -fPIC $< -o $@

clean:
	rm -rf *.o *.so *~ *pyc *pyo *svg
