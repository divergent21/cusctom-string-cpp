//
// Created by divergent on 04.01.2021.
//

#ifndef KURSACH_MYSTRING_H
#define KURSACH_MYSTRING_H


class MyString {
public:
    MyString();
    explicit MyString(const char *str);
    MyString(const MyString &other);
    ~MyString();

    int length();
    static int length(const char *str);

    MyString& operator =(const MyString &other);
    MyString operator +(const MyString &other);

private:
    char *str;
};


#endif //KURSACH_MYSTRING_H
