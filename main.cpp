#include <iostream>
#include "MyString.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    MyString ms("Hi");
    MyString two("Divergent");
    MyString nw = ms + two;
    std::cout << nw.length() << std::endl;

    return 0;
}
