all: mendel.so

%.o:%.cpp
	g++ -pthread -O3 -Wall -std=c++14 -fPIC -I. -I/usr/include/python2.7 -c $< -o $@

mendel.so:mendel_module.o mendel_cwrapper.o
	g++ -shared $? -o $@

clean:
	rm -rf *.o *.so build *~

