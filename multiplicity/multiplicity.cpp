#include <iostream>
#include "Sets.h"
using namespace std;

int main()
{
   
    int a = 6;
    int arr[]{ 2, 4, 7, 9, 3, 1};
    int arr2[]{ 2, 5, 7, 8, 3, 6 };
    Sets one(a, arr);
    Sets two(a, arr2);
    cout << one << endl << two << endl;
    one *= two;
    cout << one << endl;    
}
