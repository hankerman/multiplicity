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

bool Sets::chek_variety(int a)
{
	for (int i = 0; i < size; i++) {
		if (a == variety[i]) {
			return true;
		}
	}
	return false;
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
	bool chek_a = false;
	if (chek_variety(a)) {		
		int* temp = new int[size];
		for (int i = 0; i < size; i++) {
			temp[i] = variety[i];			
		}
		remove();
		this->size--;
		this->variety = new int[size];
		for (int i = 0, j = 1; i < size; i++, j++) {
			if (temp[i] == a) {
				chek_a = true;
			}
			if (chek_a) {
				variety[i] = temp[j];
			}
			else {
				variety[i] = temp[i];
			}
		}
		delete[]temp;
	}
	return *this;
}

Sets& Sets::operator=(const Sets& a)
{
	if (this == &a) {
		return *this;
	}
	remove();
	this->size = a.size;
	this->variety = new int[size];
	for (int i = 0; i < size; i++) {
		variety[i] = a.variety[i];
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

Sets& operator+=(Sets& a, Sets& b)
{
	for (int i = 0; i < b.size; i++) {
		a.add(b.variety[i]);
	}
	return a;
}

Sets& operator+(Sets& a, Sets& b)
{
	for (int i = 0; i < b.size; i++) {
		a.add(b.variety[i]);
	}
	return a;
}

Sets& operator-=(Sets& a, int i)
{
	a.del(i);
	return a;
}

Sets& operator-=(Sets& a, Sets& b)
{
	for (int i = 0; i < b.size; i++) {
		a.del(b.variety[i]);
	}
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

Sets& operator*(Sets& a, Sets& b)
{
	int counSize = 0, size2 = a.size > b.size ? a.size : b.size, t = 0;
	int* temp = new int[size2];
	for (int i = 0; i < a.size; i++) {
		for (int j = 0; j < b.size; j++) {
			if (a.variety[i] == b.variety[j]) {
				temp[t] = a.variety[i];
				t++;
				counSize++;
			}
		}
	}
	delete[]a.variety;
	a.size = counSize;
	a.variety = new int[a.size];
	for (int i = 0; i < a.size; i++) {
		a.variety[i] = temp[i];
	}
	delete[]temp;
	return a;
}

Sets& operator*=(Sets& a, Sets& b)
{
	int counSize = 0, size2 = a.size > b.size ? a.size : b.size, t = 0;
	int* temp = new int[size2];
	for (int i = 0; i < a.size; i++) {
		for (int j = 0; j < b.size; j++) {
			if (a.variety[i] == b.variety[j]) {
				temp[t] = a.variety[i];
				t++;
				counSize++;
			}
		}
	}
	delete[]a.variety;
	a.size = counSize;
	a.variety = new int[a.size];
	for (int i = 0; i < a.size; i++) {
		a.variety[i] = temp[i];
	}
	delete[]temp;
	return a;
}
