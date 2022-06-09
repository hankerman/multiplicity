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
	Sets& add(int a);
	Sets& del(int a);
	friend ostream& operator<<(ostream&, const Sets& a);
	friend istream& operator>>(istream&, Sets& a);
	friend Sets& operator+(Sets& a, int i);
	friend Sets& operator+=(Sets& a, int i);
	friend Sets& operator-=(Sets& a, int i);
	friend Sets& operator-(Sets& a, int i);
	friend bool operator==(const Sets& a, const Sets& b);
	friend bool operator!=(const Sets& a, const Sets& b);

	
};

