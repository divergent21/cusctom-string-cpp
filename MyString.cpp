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
MyString MyString::operator+(char *other) {
    MyString result;
    result.str = new char[this->length() + MyString::length(other) + 1];
    result.Length = this->length() + MyString::length(other);

    int i = 0;
    for (; i < this->length(); i++) {
        result.str[i] = this->str[i];
    }

    for (int j = 0; j < MyString::length(other); j++, i++) {
        result.str[i] = other[j];
    }

    result.str[result.length()] = '\0';

    return result;
}
MyString MyString::operator+(char other) {
    MyString result;
    result.str = new char[this->length() + 2];
    result.Length = this->length() + 1;

    int i = 0;
    for (; i < this->length(); i++) {
        result.str[i] = this->str[i];
    }

    result.str[i] = other;

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
    myString.str = new char;
    in >> myString.str;
    myString.resize();
    return in;
}
MyString& MyString::operator+=(const MyString &other) {
    *this = *this + other;
    return *this;
}
MyString& MyString::operator+=(const char *other) {
    *this = *this + other;
    return *this;
}
MyString& MyString::operator+=(char *other) {
    *this = *this + other;
    return *this;
}
MyString& MyString::operator+=(char other) {
    *this = *this + other;

    return *this;
}

bool MyString::operator<(const MyString &other) {
    if (this->Length < other.Length) {
        return true;
    } else {
        return false;
    }
}
bool MyString::operator<(const char *other) {
    if (this->Length < MyString::length(other)) {
        return true;
    } else {
        return false;
    }
}
bool MyString::operator>(const MyString &other) {
    if (this->length() > other.Length) {
        return true;
    } else {
        return false;
    }
}
bool MyString::operator>(const char *other) {
    if (this->Length > MyString::length(other)) {
        return true;
    } else {
        return false;
    }
}
bool MyString::operator<=(const MyString &other) {
    return !(this->operator>(other));
}
bool MyString::operator>=(const MyString &other) {
    return !(this->operator<(other));
}
bool MyString::operator<=(const char* other) {
    return !(this->operator>(other));
}
bool MyString::operator>=(const char* other) {
    return !(this->operator<(other));
}

int MyString::find (MyString find) {
    if (this->length() < find.Length) return -1;
    if (this->length() == find.Length) {
        if (this->operator==(find)) return 0;
        else return -1;
    }

    int result = -1;
    for (int i = 0; i <= this->length() - find.length(); i++) {
        if (i + find.length() > this->length()) return -1;
        if (result == -1 && this->str[i] == find.str[0]) {
            result = i;
            continue;
        }
        if (this->str[i] == find.str[i - result]) {
            if (result == -1) result = i;
            if (i - result + 1 == find.length()) return result;
        } else {
            result = -1;
        }
    }

    return result;
}
int MyString::find(const char *find) {
    if (this->length() < MyString::length(find)) return -1;
    if (this->length() == MyString::length(find)) {
        if (this->operator==(find)) return 0;
        else return -1;
    }

    int result = -1;
    for (int i = 0; i < this->length() - MyString::length(find); i++) {
        if (i + MyString::length(find) > this->length()) return -1;
        if (this->str[i] == find[0]) {
            result = i;
            continue;
        }
        if (this->str[i] == find[i - result]) {
            if (result == -1) result = i;
            if (i - result + 1 == MyString::length(find)) return result;
        } else {
            result = -1;
        }
    }

    return result;
}
bool MyString::replace(MyString find, MyString replace) {
    if (this->find(find) != -1) {
        int index = this->find(find);
        if (find.length() == replace.length()) {
            for (int i = 0; i < find.length(); i++, index++) {
                this->str[index] = replace[i];
            }
            return true;
        } else {
            const int new_length = this->length() - find.length() + replace.length();
            const char* temp = this->str;
            this->str = new char[new_length];
            this->Length = new_length + 1;

            int i = 0;
            for (; i < index; i++) {
                this->str[i] = temp[i];
            }
            for (int j = 0; j < replace.length(); j++, i++) {
                this->str[i] = replace.str[j];
            }
            for (int k = index + find.length(); k < MyString::length(temp); k++, i++) {
                this->str[i] = temp[k];
            }

            this->str[this->Length] = '\0';
            return true;
        }
    }
    return false;
}
bool MyString::replace(const char *find, MyString replace) {
    MyString s_find = find;
    return this->replace(s_find, replace);
}
bool MyString::replace(MyString find, const char *replace) {
    MyString s_replace = replace;
    return this->replace(find, s_replace);
}
bool MyString::replace(const char *find, const char *replace) {
    MyString s_find = find;
    MyString s_replace = replace;
    return this->replace(s_find, s_replace);
}

void MyString::toUpperCase() {
    for (int i = 0; i < this->length(); i++) {
        if (this->str[i] >= 'a' && this->str[i] <= 'z') this->str[i] = char(int(this->str[i]) - 32);
    }
}
void MyString::toLowerCase() {
    for (int i = 0; i < this->length(); i++) {
        if (this->str[i] >= 'A' && this->str[i] <= 'Z') this->str[i] = char(int(this->str[i]) + 32);
    }
}

void MyString::swap(MyString &other) {
    MyString temp = other;
    other = *this;
    *this = temp;
}