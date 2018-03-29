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

 VectorInt xD(5);



    xD.pushBack(5);
    xD.pushBack(3);
    xD.pushBack(22);


    cout<<xD;

    cout<<xD.popBack()<<endl;
    cout<<xD.popBack()<<endl;

    cout<<xD;






    return 0;
}

