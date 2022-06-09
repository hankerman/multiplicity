#include <iostream>
#include "Sets.h"
using namespace std;

int main()
{
   
    int a = 7;
    int arr[]{ 2,4, 7, 9, 3, 1, 6 };

    Sets one(a, arr);
    Sets two(one);
    cout << one;
    one -= 9;
    cout << one;
}
