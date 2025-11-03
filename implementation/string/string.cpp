#include "String.h"
#include <cstring>

String::String()
    : m_Size(0)
{
    m_Buffer = new char[1];
    m_Buffer[0] = '\0';
}

String::String(const char* string)
{
    m_Size = strlen(string);
    m_Buffer = new char[m_Size + 1];
    strcpy(m_Buffer, string);
}

String::String(const String& other)
    : m_Size(other.m_Size)
{
    m_Buffer = new char[m_Size + 1];
    strcpy(m_Buffer, other.m_Buffer);
}

String::~String()
{
    delete[] m_Buffer;
}

String& String::operator=(const String& other)
{
    if (this != &other)
    {
        delete[] m_Buffer;
        m_Size = other.m_Size;
        m_Buffer = new char[m_Size + 1];
        strcpy(m_Buffer, other.m_Buffer);
    }
    return *this;
}

char& String::operator[](unsigned int index)
{
    return m_Buffer[index];
}

const char& String::operator[](unsigned int index) const
{
    return m_Buffer[index];
}

unsigned int String::Size() const
{
    return m_Size;
}

const char* String::CStr() const
{
    return m_Buffer;
}

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}
