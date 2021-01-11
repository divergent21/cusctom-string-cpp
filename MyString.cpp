//
// Created by divergent on 04.01.2021.
//

#include "MyString.h"

/**
 * TODO: operator +=
 * TODO: operator <
 * TODO: operator >
 * TODO: operator <=
 * TODO: operator >=
 *
 * TODO: function find sub string
 * TODO: function find and replace sub string
 * TODO: function str to uppercase
 * TODO: function str to lowercase
 */

MyString::MyString() {
    str = nullptr;
    this->Length = 0;
}
MyString::MyString(const char *str) {
    this->Length = MyString::length(str);
    this->str = new char[this->length() + 1];

    for (int i = 0; i < this->length(); i++) {
        this->str[i] = str[i];
    }

    this->str[this->length()] = '\0';
}
MyString::MyString(MyString &&other) {
    this->Length = other.Length;
    this->str = other.str;
    other.str = nullptr;
}
MyString::~MyString() {
    delete[] str;
}
int MyString::length() {
    return this->Length;
}
int MyString::length(const char *str) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}
MyString::MyString(const MyString &other) {
    if (&other != this) {
        delete[] str;

        this->Length = MyString::length(other.str);
        this->str = new char[this->length() + 1];

        for (int i = 0; i < this->length(); i++) {
            this->str[i] = other.str[i];
        }

        this->str[this->length()] = '\0';
    }
}
void MyString::resize() {
    Length = 0;
    while (str[Length] != '\0') Length++;
}


MyString& MyString::operator =(const MyString &other) {
    if (&other != this) {
        delete[] str;

        this->Length = MyString::length(other.str);
        this->str = new char[this->length() + 1];

        for (int i = 0; i < this->length(); i++) {
            this->str[i] = other.str[i];
        }

        this->str[this->length()] = '\0';
    }

    return *this;
}
MyString MyString::operator+(const MyString &other) {
    MyString result;
    result.str = new char[this->length() + other.Length + 1];
    result.Length = this->length() + other.Length;

    int i = 0;
    for (; i < this->length(); i++) {
        result.str[i] = this->str[i];
    }

    for (int j = 0; j < other.Length; j++, i++) {
        result.str[i] = other.str[j];
    }

    result.str[result.length()] = '\0';

    return result;
}
bool MyString::operator==(const MyString &other) {
    if (this->Length != other.Length) {
        return false;
    }

    for (int i = 0; i < this->Length; i++) {
        if (this->str[i] != other.str[i]) {
            return false;
        }
    }

    return true;
}
bool MyString::operator!=(const MyString &other) {
    return !(this->operator==(other));
}
char& MyString::operator[](int index) {
    return this->str[index];
}

std::ostream& operator<< (std::ostream& out, const MyString& myString) {
    out << myString.str;
    return out;
}
std::istream& operator>> (std::istream& in, MyString& myString) {
    /**
     * TODO: В задании к курсовому указано какой должен быть максимальный размер. Удостоверится что сейчас нужный !.
     * TODO: Сделать чтение до первого символа переноса строки либо до \0
     */

    myString.str = new char;
//    in >> myString.str;
//    myString.resize();

    in.getline(myString.str, INTMAX_MAX);
    myString.resize();

    return in;
}