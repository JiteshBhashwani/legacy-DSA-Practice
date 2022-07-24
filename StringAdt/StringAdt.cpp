#include "StringAdt.hpp"

String::String(const char* input) 
{
    this->data = new char[std::strlen(input)];
    std::strcpy(this->data,input);
}

String::~String()
{
}

std::ostream& operator<<(std::ostream& os,const String& that)
{
    os << that.data;
    return os;
}