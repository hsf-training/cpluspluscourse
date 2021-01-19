#include "TextBox.hpp"
#include <iostream>

int main() {
    // create a TextBox and call draw
    TextBox tb("my text", 10, 5);
    // tb.draw();
    // error: request for member ‘draw’ is ambiguous

    // Fix the code to call both draws by using types    
    Rectangle &r = tb;
    r.draw();
    Text &t = tb;
    t.draw();

    // retry with virtual inheritance
    // error: no matching function for call to ‘Drawable::Drawable()’
    // add a default constructor to Drawable or call the constructor from TextBox
}
