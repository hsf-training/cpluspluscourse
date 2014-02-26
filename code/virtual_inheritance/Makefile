all: libtextbox.so test

clean:
	rm -f *o *so test *~ test.sol

libtextbox.so: TextBox.cpp TextBox.hpp
	$(CXX) -Wall -Wextra -shared -fPIC -o $@ $<

test : test.cpp libtextbox.so
	$(CXX) -Wall -Wextra -L. -l textbox -o $@ $<

test.sol : test.sol.cpp libtextbox.so
	$(CXX) -Wall -Wextra -L. -l textbox -o $@ $<
