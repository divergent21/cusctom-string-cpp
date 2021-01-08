//
// Created by divergent on 04.01.2021.
//

#include "MyString.h"

MyString::MyString() {
    str = nullptr;
}

MyString::MyString(const char *str) {
    this->str = new char[MyString::length(str) + 1];

    for (int i = 0; i < MyString::length(str); i++) {
        this->str[i] = str[i];
    }

    this->str[this->length()] = '\0';
}

MyString::~MyString() {
    delete[] str;
}

int MyString::length() {
    int length = 0;

    while (this->str[length] != '\0') {
        length++;
    }

    return length;
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

        this->str = new char[MyString::length(other.str) + 1];

        for (int i = 0; i < MyString::length(other.str); i++) {
            this->str[i] = other.str[i];
        }

        this->str[this->length()] = '\0';
    }
}

MyString& MyString::operator =(const MyString &other) {
    if (&other != this) {
        delete[] str;

        this->str = new char[MyString::length(other.str) + 1];

        for (int i = 0; i < MyString::length(other.str); i++) {
            this->str[i] = other.str[i];
        }

        this->str[this->length()] = '\0';
    }

    return *this;
}

MyString MyString::operator+(const MyString &other) {
    MyString result(new char[this->length() + MyString::length(other.str) + 1]);

    int i = 0;
    for (; i < this->length(); i++) {
        result.str[i] = this->str[i];
    }

    for (int j = 0; j < MyString::length(other.str); j++, i++) {
        result.str[i] = other.str[j];
    }
    result.str[this->length() + MyString::length(other.str)] = '\0';

    return result;
}