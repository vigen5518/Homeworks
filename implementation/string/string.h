#ifndef STRING_H
#define STRING_H

#include <iostream>

class String
{
private:
    char* m_Buffer;
    unsigned int m_Size;

public:
    String();
    String(const char* string);
    String(const String& other);
    ~String();

    String& operator=(const String& other);
    char& operator[](unsigned int index);
    const char& operator[](unsigned int index) const;

    unsigned int Size() const;
    const char* CStr() const;

    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

#endif
