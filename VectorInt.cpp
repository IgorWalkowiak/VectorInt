#include "VectorInt.h"

#include <iostream>

struct number
{
bool fill;
int value;
number *previous;
number *next;
};

VectorInt::VectorInt(void)
{
    first=new number;
    first->fill=false;
    first->previous=NULL;
    first->next=NULL;

    number* buf=first;
    for(int i=0;i<15;i++)
    {
        buf->next=new number;
        buf->next->fill=false;
        buf->next->previous=buf;
        buf=buf->next;
    }
}
VectorInt::VectorInt(int a)
{
    if(a!=0)
    {
        first=new number;
        first->fill=false;
        first->previous=NULL;
        first->next=NULL;

        number* buf=first;
        for(int i=0;i<a;i++)
        {
            buf->next=new number;
            buf->next->fill=false;
            buf->next->previous=buf;
            buf=buf->next;
        }
    }
    else first=NULL;
}

number* VectorInt::toTail(void)
{
    number* buf=first;


    if(first!=NULL)
    {
        if(first->fill==NULL) return NULL;
        while(buf->next!=NULL)
        {
            if(buf->next->fill==false)
            {
                break;
            }
            buf=buf->next;
        }
    }

    return buf;
}

void VectorInt::pushBack(int a)
{
    number* buf=toTail();

    if(buf==NULL)
    {
        first=new number;
        first->value=a;
        first->next=NULL;
        first->previous=NULL;
        first->fill=true;
    }
    else
    {
        if(buf->next==NULL) //Need to add next element
        {
        buf->next=new number;
        buf->next->value=a;
        buf->next->next=NULL;
        buf->next->previous=buf;
        buf->next->fill=true;
        }
        else
        {
            buf->next->value=a;
            buf->next->fill=true;
        }

    }
}

int VectorInt::popBack(void)
{
    number* lastElem=toTail();


    if(lastElem==NULL)
    {
        std::cout<<"There is no elements in vector, I return you -1";
        return (-1);
    }
    lastElem->fill=false;
    return lastElem->value;


}
