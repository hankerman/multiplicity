#include <iostream>
#include "Sets.h"
using namespace std;

int main()
{
   
    int a = 7;
    int arr[]{ 2,4, 7, 9, 3, 1, 6 };
    int arr2[]{ 2,4, 7, 8, 3, 1, 6 };
    Sets one(a, arr);
    Sets two(a, arr2);
    if (one != two) {
        cout << "one != two " << endl;
    }
    else {
        cout << "one == two" << endl;
    }

}
