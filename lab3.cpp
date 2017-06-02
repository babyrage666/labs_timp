#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Stack 
{
	int* Arr;
	int size;
	int place;
public:
	const int sizeStack() const 
	{
		return size;
	}

	const int& operator()(size_t i) const 
	{
		return Arr[i];
	}
	
	int& operator()(size_t i) 
	{
		return Arr[i];
	}

	void push(int value) 
	{
		if(place >= size) 
			throw runtime_error("stack is full"); 
			
		Arr[place] = value;
		place++;
	}

	void fail() {
		if(place < 1) 
		    throw runtime_error("stack is empty");
		place--;
		Arr[place] = 0;
	}

	Stack(size_t sz, int value): place(0), size(sz) 
	{
		Arr = new int[sz];
		for(int i = 0; i < sz; ++i)
			Arr[i] = value;
	}
	Stack(Stack& C): size(C.sizeStack()), place(0) 
	{
		Arr = new int[size];
		for(int i = 0; i < size; ++i)
			Arr[i] = C(i);
	}
	virtual ~Stack() { delete[] Arr; }
};

void print(const Stack& x) 
{
	for(int i = 0; i < x.sizeStack(); ++i) 
	{
		cout << x(i) << " ";
	}
	cout << endl;
}

int main() {
	try 
	{
		Stack s1(10, 0);
		print(s1);
		
		for(int i = 0; i < 10; ++i)
			s1.push(1);
			
		print(s1);
		Stack s2(s1);
		print(s2);
		
		for(int j = 0; j < 10; ++j) {
			s1.fail();
		}
		print(s1);
	} 
	
	catch(const exception& e) 
	{
		cout << e.what() << endl;
	}
	return 0;
}