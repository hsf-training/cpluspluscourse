all: libtextbox.so trymultiherit
solution: libtextbox.so trymultiherit.sol

clean:
	rm -f *o *so trymultiherit *~ trymultiherit.sol

libtextbox.so: TextBox.cpp TextBox.hpp
	$(CXX) -Wall -Wextra -shared -fPIC -o $@ $<

trymultiherit : trymultiherit.cpp libtextbox.so
	$(CXX) -Wall -Wextra -L. -l textbox -o $@ $^

libtextboxsol.so: solution/TextBox.cpp solution/TextBox.hpp
	$(CXX) -Wall -Wextra -shared -fPIC -o $@ $<

trymultiherit.sol : solution/trymultiherit.sol.cpp libtextboxsol.so
	$(CXX) -Wall -Wextra -I. -L. -l textbox -o $@ $^
