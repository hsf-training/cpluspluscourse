all: libtextbox.so test

clean:
	rm -f *o *so test *~ test.sol

libtextbox.so: TextBox.cpp
	g++ -g -Wall -Wextra -shared -fPIC -o $@ $<

test : test.cpp libtextbox.so
	g++ -Wall -Wextra -L. -l textbox -o $@ $<

test.sol : test.sol.cpp libtextbox.so
	g++ -g -Wall -Wextra -L. -l textbox -o $@ $<
