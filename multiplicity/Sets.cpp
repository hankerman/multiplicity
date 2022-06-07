#include "Sets.h"

void Sets::remove()
{
	delete[] variety;
}

bool Sets::unique(int a)
{
	int counter = 0;
	bool flag = true;
	for (int i = 0; i < size; i++) {
		if (variety[i] == a) {
			counter++;
		}
	}
	if (counter) {
		flag = false;
	}
	else {
		flag = true;
	}
	return flag;
}

Sets::Sets(int size, int* arr)
{
	this->size = size;
	variety = new int[size];
	for (int i = 0; i < size; i++) {
		this->variety[i] = arr[i];
	}
}

Sets::Sets(int size)
{
	this->size = size;
	variety = new int[size];
}

Sets::Sets()
{
	size = 0;
	variety = nullptr;
}

Sets::Sets(const Sets& other)
{

	this->size = other.size;
	this->variety = new int[size];
	for (int i = 0; i < size; i++) {
		this->variety[i] = other.variety[i];
	}

}

Sets::~Sets()
{
	remove();		
}

Sets& Sets::add(const int a)
{
	if (unique(a)) {
		int* temp = new int[size];
		for (int i = 0; i < size; i++) {
			temp[i] = variety[i];
		}
		remove();
		size++;
		variety = new int[size];
		for (int i = 0; i < size - 1; i++) {
			variety[i] = temp[i];
		}
		variety[size - 1] = a;
		delete[]temp;
	}
	return *this;
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

istream& operator>>(istream& input, Sets& a)
{
	int i;
	input >> i;
	a.add(i);
	return input;
}

const Sets operator+(const Sets& a, int i)
{
	Sets temp(a);
	temp.add(i);
	return temp;
}
