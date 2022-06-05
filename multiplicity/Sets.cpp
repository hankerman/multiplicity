#include "Sets.h"

void Sets::remove()
{
	delete[] variety;
}

Sets::Sets(int size, int* arr)
{
	this->size = size;
	variety = new int[size];
	for (int i = 0; i < size; i++) {
		this->variety[i] = arr[i];
	}
}

Sets::Sets()
{
	size = 0;
	variety = nullptr;
}

Sets::~Sets()
{
	remove();
}

void Sets::print()
{
	for (int i = 0; i < size; i++) {
		cout << variety[i] << " ";
	}
	cout << endl;
}

ostream& operator<<(ostream& output, const Sets& a)
{
	for (int i{ 0 }; i < a.size; ++i) 
	{
		output << a.variety[i] << " ";
	}
	cout << endl;
	return output;
}

istream& operator>>(istream& input, const Sets& a)
{
	
	for (size_t i{ 0 }; i < a.size; ++i) {
		input >> a.variety[i];
	}
	return input;
}
