#include <iostream>
#include "MyString.h"
#include <cstring>

int main() {
    std::cout << "Hello, World!" << std::endl;

    MyString ms = "Divergent";
    MyString two = "Divergent";

    std::cout << "length ms - " << ms.length() << std::endl;
    std::cout << "length two - " << two.length() << std::endl;
    MyString nw = ms + two;
    std::cout << nw.length() << std::endl;

    if (ms == two) std::cout << "ms == two" << std::endl;
    else std::cout << "ms != two" << std::endl;

    two[3] = 'D';
    std::cout << two[3] << std::endl;

    std::cout << "Enter your custom string: ";
    MyString custom;
    std::cin >> custom;

    std::cout << "Your custom string - " << custom << std::endl;
    std::cout << "Your custom string length - " << custom.length() << std::endl;

    return 0;
}
