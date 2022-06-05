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

public:
	Sets(int size, int* arr);
	Sets();
	~Sets();

	void print();
	

};

