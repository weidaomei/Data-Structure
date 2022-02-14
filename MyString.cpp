#include <iostream>
#include <string.h>
using namespace std;

class String
{
private:
    char *str;
    int length;

public:
    String(const char *s)
    {
        if (!s)
        {
            str = new char[1];
            *str = '\0';
            length = 0;
        }
        else
        {
            length = strlen(s);
            str = new char[length + 1];
            strcpy(str, s);
        }
    }
    ~String()
    {
        if (str != NULL)
        {
            delete[] str;
            length = 0;
        }
    }
    String(const String &other)
    {
        length = strlen(other.str);
        str = new char[length];
        strcpy(str, other.str);
    }
    void display()
    {
        cout << str << endl;
    }
    String &operator=(char *s)
    {
        delete[] str;
        length = strlen(s);
        str = new char[length];
        strcpy(str, s);
        return *this;
    }
    String &operator=(const String &s)
    {
        if (this == &s)
            return *this;
        delete[] str;
        length = strlen(s.str);
        str = new char[length];
        strcpy(str, s.str);
    }
    const char &operator[](unsigned int i) const
    {
        if (i < length)
            return str[i];
        else
            return str[length - 1];
    }
    char &operator[](unsigned int i)
    {
        if (i < length)
            return str[i];
        else
            return str[length - 1];
    }
    friend String operator+(const String &s1, const String &s2)
    {
        int len = strlen(s1.str) + strlen(s2.str);
        char *newstr = new char[len + 1];
        strcpy(newstr, s1.str);
        strcat(newstr, s2.str);
        String temp(newstr);
        temp.length = len;
        return temp;
    }
    String &operator+=(const String &s)
    {
        length += strlen(s.str);
        char *newstr = new char[length + 1];
        strcpy(newstr, str);
        strcat(newstr, s.str);
        delete[] str;
        str = newstr;
        return *this;
    }
    bool operator==(const String &s)
    {
        if (length != s.length)
            return false;
        return strcmp(str, s.str) ? false : true;
    }
    friend ostream &operator<<(ostream &out, const String &s)
    {
        out << s.str;
        return out;
    }
    friend istream &operator>>(istream &in, String &s)
    {
        char temp[4096];
        in >> temp;
        s.str = temp;
        return in;
    }
};