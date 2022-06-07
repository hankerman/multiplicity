#pragma once
#include <iostream>
using namespace std;

class Sets
{
private:
	int size;
	int* variety;
	void remove();	
	bool unique(int a);

public:
	Sets(int size, int* arr);
	Sets(int size);
	Sets();
	Sets(const Sets& other);
	~Sets();
	Sets& add(const int a);
	friend ostream& operator<<(ostream&, const Sets& a);
	friend istream& operator>>(istream&, Sets& a);
	friend const Sets operator+(const Sets& a, int i);

};

