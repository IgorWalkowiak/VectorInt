#ifndef VECTORINT_H_INCLUDED
#define VECTORINT_H_INCLUDED

#include <iostream>
struct number;

class VectorInt{
public:

VectorInt(void);
VectorInt(int);
int at(int);
void insert(int,int);
void pushBack(int);
int popBack(void);
void shrinkToFit(void);
void clear(void);
int size(void);
int capacity(void);
friend std::ostream& operator<<(std::ostream& wyjscie,const VectorInt &s)
{
    return wyjscie<<"test";
}

private:
    number* toTail(void);
    number* first;
};

#endif // VECTORINT_H_INCLUDED
