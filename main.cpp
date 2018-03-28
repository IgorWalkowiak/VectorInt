#include <iostream>
#include "VectorInt.h"


using namespace std;

struct number
{
int value;
number *next;

};


int main()
{
    VectorInt xD;
    xD.pushBack(3);

    cout<<xD.popBack();


    return 0;
}

