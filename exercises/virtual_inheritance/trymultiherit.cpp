#include "TextBox.hpp"
#include <iostream>

int main() {
    
    TextBox tb("my text", 10, 5);
    Rectangle &r = tb;
    r.draw();
    Text &t = tb;
    t.draw();


}