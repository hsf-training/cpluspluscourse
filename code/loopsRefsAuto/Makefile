all: loopsRefsAuto

clean:
	rm -f *o functions *~

%.o: %.cpp %.h
	${CXX} -std=c++17 -Wall -Wextra -c  -o $@ $<

loopsRefsAuto : loopsRefsAuto.cpp
	${CXX} -std=c++17 -Wall -Wextra -o $@ $^

