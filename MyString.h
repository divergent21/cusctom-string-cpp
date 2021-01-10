//
// Created by divergent on 04.01.2021.
//
#pragma once
#include <iostream>

#ifndef KURSACH_MYSTRING_H
#define KURSACH_MYSTRING_H


class MyString {
public:
    MyString();
    MyString(const char *str);
    MyString(const MyString &other);
    MyString(MyString &&other);
    ~MyString();

    int length();

    MyString& operator =(const MyString &other);
    MyString operator +(const MyString &other);
    bool operator ==(const MyString &other);
    bool operator !=(const MyString &other);
    char& operator [](int index);
    friend std::ostream& operator<< (std::ostream& out, const MyString& myString); 
    friend std::istream& operator>> (std::istream& in, MyString& myString);

private:
    char *str;
    int Length;

    static int length(const char *str);
    void resize();
};


#endif //KURSACH_MYSTRING_H
