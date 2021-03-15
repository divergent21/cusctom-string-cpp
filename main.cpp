#include <iostream>
#include "MyString.h"
#include <fstream>

int main() {
    std::cout << "MyString" << std::endl;
    std::cout << "Author: Zakharchenko Dmitry" << std::endl;

    const MyString const_string = "const string";

    std::cout << "enter test string: ";
    MyString test;
    std::cin >> test;

    MyString double_test = test + test;
    std::cout << "Double test (+): " << double_test << std::endl;

    test += const_string;
    std::cout << "test plus const (+=): " << test << std::endl;

    std::cout << "Read from file_read.txt" << std::endl;
    MyString from_file;
    std::ifstream file_read ("file_read.txt");
    if (file_read.is_open()) {
        file_read >> from_file;
        std::cout << "Text from file: " << from_file << std::endl;
    } else {
        std::cout << "fail open file" << std::endl;
    }
    file_read.close();

    std::cout << "Write to file_write.txt" << std::endl;
    std::ofstream file_write ("file_write.txt");
    if (file_write.is_open()) {
        std::cout << "enter string for write to file: ";
        MyString for_write;
        std::cin >> for_write;
        file_write << for_write;
    } else {
        std::cout << "fail open file" << std::endl;
    }
    file_write.close();

    if (test == const_string) std::cout << "test string equals const (==)" << std::endl;
    if (test != const_string) std::cout << "test string not equals const (!=)" << std::endl;

    if (test < const_string) std::cout << "test string less to const (<)" << std::endl;
    if (double_test <= const_string) std::cout << "double test string less or equals const (<=)" << std::endl;

    std::cout << "length test string - " << test.length() << std::endl;

    std::cout << "enter string for find in test: ";
    auto *find = new MyString;
    std::cin >> *find;
    if (test.find(*find)) std::cout << "sub string (" << *find << ") has been find" << std::endl;
    else std::cout << "sub string (" << *find << ") has been not find" << std::endl;
    delete find;

    test.replace("fr", "NEW");
    std::cout << "result after replace fr to NEW - " << test << std::endl;

    test.toUpperCase();
    std::cout << "test to upper case - " << test << std::endl;

    double_test.toLowerCase();
    std::cout << "double test to lower case - " << double_test << std::endl;

    test.swap(double_test);
    std::cout << "test after swap - " << test << std::endl;
    std::cout << "double test after swap - " << double_test << std::endl;

    std::cout << "Thanks. Bye :)";

    return 0;
}
