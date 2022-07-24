#include <cstring>
#include <iostream>

#ifndef _StringAdt_
#define _StringAdt_
class String
{
private:
    char* data;
public:
    String(const char* data = "");
    ~String();
    void display(){std::cout << data;}
    void cat(const char* s){std::strcat(this->data,s);}

    friend std::ostream& operator<<(std::ostream& os,const String& that);
};
#endif //_StringAdt_