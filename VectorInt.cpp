#include "VectorInt.h"

#include <iostream>

struct number
{
int value;
number *next;

};

VectorInt::VectorInt(void)
{
    first=NULL;
}
VectorInt::VectorInt(int a)
{
    first=NULL;
    std::cout<<"xD";
}

number* VectorInt::toTail(void)
{
    number* buf=first;
    if(first!=NULL)
    {
        while(buf->next!=NULL)
        {
            buf=buf->next;
        }
    }
    return buf;
}
void VectorInt::pushBack(int a)
{
    number* buf;
    buf=toTail();
    buf=new number;
    buf->value=a;
    buf->next=NULL;
}
int VectorInt::popBack(void)
{

    int buf;
    if(toTail()!=NULL)
    {
       buf=toTail()->value;
       delete toTail();
    }
    return buf;
}
