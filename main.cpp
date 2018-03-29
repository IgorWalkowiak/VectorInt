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

 VectorInt xD(0);

    xD.pushBack(5);



    cout<<xD.popBack()<<endl;
    cout<<xD.popBack()<<endl;
    cout<<xD.popBack()<<endl;





    return 0;
}

