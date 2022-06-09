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

Sets& Sets::add(int a)
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

Sets& Sets::del(int a)
{
	int count_del = 0;
	int* temp = new int[size];
	for (int i = 0; i < size; i++) {
		temp[i] = variety[i];
	}
	remove();
	for (int i = 0; i < size; i++) {
		if (temp[i] == a) {
			break;
		}
		else {
			count_del++;
		}
	}
	if (count_del != 0) {
		size--;
		variety = new int[size];
		for (int i = 0; i < size; i++) {
			if (i < count_del) {
				variety[i] = temp[i];
			}
			else {
				variety[i] = temp[i + 1];
			}
		}
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

Sets& operator+(Sets& a, int i)
{
	
	a.add(i);
	return a;
}

Sets& operator+=(Sets& a, int i)
{
	a.add(i);
	return a;
}

Sets& operator-=(Sets& a, int i)
{
	a.del(i);
	return a;
}

Sets& operator-(Sets& a, int i)
{
	a.del(i);
	return a;
}

bool operator==(const Sets& a, const Sets& b)
{
	bool flag = true;
	int cont = 0;
	if (a.size == b.size) {
		for (int i = 0; i < a.size; i++) {
			for (int j = 0; j < b.size; j++) {
				if (a.variety[i] == b.variety[j]) {
					cont++;
				}
			}
		}
		if (cont == 0) {
			flag = false;
		}
		else if (cont == a.size) {
			flag = true;
		}
		else {
			flag = false;
		}
	}
	else {
		flag = false;
	}
	return flag;
}

bool operator!=(const Sets& a, const Sets& b)
{
	bool flag = false;
	int cont = 0;
	if (a.size == b.size) {
		for (int i = 0; i < a.size; i++) {
			for (int j = 0; j < b.size; j++) {
				if (a.variety[i] == b.variety[j]) {
					cont++;
				}
			}
		}
		if (cont == 0) {
			flag = true;
		}
		else if (cont == a.size) {
			flag = false;
		}
		else {
			flag = true;
		}
	}
	else {
		flag = true;
	}
	return flag;
}
