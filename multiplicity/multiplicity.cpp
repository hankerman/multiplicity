#include <iostream>
#include "Sets.h"
using namespace std;

int main()
{
   
    int a = 2;
    int arr[]{ 2,4 };

    Sets one(a, arr);
    cout << one;
    one.add(5);
    Sets two(one);
    cout << two;
    two = two + 7;
    cout << two;
}
