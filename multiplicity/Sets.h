#pragma once
#include <iostream>
using namespace std;

class Sets
{
private:
	int size;
	int* variety;
	void remove();
	friend ostream& operator<<(ostream&, const Sets& a);
	friend istream& operator>>(istream&, const Sets& a);
	bool unique(int a);

public:
	Sets(int size, int* arr);
	Sets(int size);
	Sets();
	~Sets();
	Sets& add(int a);

};

