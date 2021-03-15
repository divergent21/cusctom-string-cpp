#include <iostream>

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
    MyString operator +(char *other);
    MyString operator +(char other);

    MyString& operator +=(const MyString &other);
    MyString& operator +=(const char *other);
    MyString& operator +=(char *other);
    MyString& operator +=(char other);
    bool operator< (const MyString &other);
    bool operator< (const char *other);
    bool operator> (const MyString &other);
    bool operator> (const char *other);
    bool operator<= (const MyString &other);
    bool operator>= (const MyString &other);
    bool operator<= (const char *other);
    bool operator>= (const char *other);
    bool operator ==(const MyString &other);
    bool operator !=(const MyString &other);
    char& operator [](int index);

    int find (MyString find);
    int find (const char* find);
    bool replace (MyString find, MyString replace);
    bool replace (const char* find, MyString replace);
    bool replace (MyString find, const char* replace);
    bool replace (const char* find, const char* replace);

    void toUpperCase();
    void toLowerCase();

    void swap(MyString &other);

    friend std::ostream& operator<< (std::ostream& out, const MyString& myString);
    friend std::istream& operator>> (std::istream& in, MyString& myString);

private:
    char *str;
    int Length;

    static int length(const char *str);
    void resize();
};
