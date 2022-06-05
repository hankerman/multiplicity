#include <iostream>
#include "Sets.h"
using namespace std;

int main()
{
   
    int a = 2;
    int arr[]{ 2,4 };

    Sets one(a, arr);
    one.add(5);
    cout << one;
    cin >> one;
    cout << one;
}
