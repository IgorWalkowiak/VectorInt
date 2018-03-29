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

    number* buf=first;
    for(int i=0;i<15;i++)
    {
        buf->next=new number;
        buf->next->fill=false;
        buf->next->previous=buf;
        last=buf;

        buf=buf->next;
    }
    buf->next=NULL;

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

        for(int i=0;i<a-1;i++)
        {

            buf->next=new number;
            buf->next->fill=false;
            buf->next->previous=buf;
            last=buf;
            buf=buf->next;

        }
        buf->next=NULL;


    }

    else
    {
        first=NULL;
        last=NULL;
    }
}

number* VectorInt::lastFilledFromFront(void)
{
    number* buf=first;
    if(first!=NULL)
    {
        if(first->fill==false)
            return first;

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

number* VectorInt::firstFilledFromBack(void)
{
    number* buf=last;
    if(last!=NULL)
    {
        if(last->fill==true)
            return last;
        while(buf->previous!=NULL)
        {
            if(buf->previous->fill==true)
            {
                return buf=buf->previous;
            }
            buf=buf->previous;
        }

        return first;
    }
}

void VectorInt::pushBack(int a)
{

    number* buf=lastFilledFromFront();


    if(buf==NULL )
    {
        first=new number;
        first->value=a;
        first->next=NULL;
        first->previous=NULL;
        first->fill=true;
        last=first;
    }
    else if(first->fill==false)
    {
        first->value=a;
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
        last=buf->next;
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

    number* lastElem=firstFilledFromBack();


    if(lastElem==NULL || lastElem->fill==false)
    {
        std::cout<<"There is no elements in vector, I return you -1";
        return (-1);
    }
    lastElem->fill=false;
    return lastElem->value;
}

int VectorInt::capacity(void)
{
    if(first!=NULL)
    {
    number* buf=first;
    int i=1;
        for(; buf->next!=NULL ;i++)
        {
            buf=buf->next;
        }
        return i;
    }
    else return 0;
}

int VectorInt::size(void)
{
    if(first!=NULL)
    {
    number* buf=first;
    int i=0;
    if(buf->fill==true)i++;
        while(buf->next!=NULL)
        {
            buf=buf->next;
            if(buf->fill==true)i++;
        }
        return i;
    }
    else return 0;
}

void VectorInt::clear(void)
{

 if(last!=NULL)
    {
        if(last->previous!=NULL)
        {
            number* buf=last;
            while(buf->previous!=NULL )
            {
                buf=buf->previous;
                delete buf->next;
            }
                delete first;
                first=NULL;
                last=NULL;

        }
    }

}

void VectorInt::shrinkToFit(void)
{
    if(last!=NULL)
    {
        if(last->previous!=NULL)
        {
            number* buf=last;
            while(buf->previous!=NULL )
            {
                if(buf->previous->fill==false)
                {
                buf=buf->previous;
                delete buf->next;
                }
                else
                {
                    buf=buf->previous;
                    delete buf->next;
                    break;
                }
            }
            buf->next=NULL;
            if(buf->previous==NULL)
            {
                delete first;
                first=NULL;
                last=NULL;
            }
        }
    }
}

int VectorInt::at(int a)
{
    if(a>=0)
    {
        number* buf=first;
        for(int i=0;i<a;i++)
        {
            if(buf->next!=NULL)
            {
            buf=buf->next;
            }
            else
            {
                std::cout<<"You go out of Vector";
                return (-1);
            }
        }
        return buf->value;
    }
    std::cout<<"You send me wrong index";
    return 0;
}

void VectorInt::insert(int index, int data)
{
    if(index>=0)
    {
        number* buf=first;
        for(int i=0;i<index;i++)
        {
            if(buf->next!=NULL)
            {
            buf=buf->next;
            }
            else
            {
                std::cout<<"You go out of Vector";
                break;
            }
        }
        buf->value=data;
    }
    else
    {
        std::cout<<"You send me wrong index";
    }

}

std::ostream& operator<<(std::ostream& wyjscie,const VectorInt &s)
{
    if(s.first!=NULL)
    {
    number* buf=s.first;
    int i=0;



        for(; buf->next!=NULL ;i++)
        {
            if(buf->fill==true) std::cout<<"["<<i<<"]: "<<buf->value<<"   "<<std::endl;
            else std::cout<<"["<<i<<"]: "<<"EMPTY   "<<std::endl;
            buf=buf->next;
        }
         if(buf->fill==true) std::cout<<"["<<i<<"]: "<<buf->value<<"   "<<std::endl;
            else std::cout<<"["<<i<<"]: "<<"EMPTY   "<<std::endl;
    }
    return wyjscie;
}









