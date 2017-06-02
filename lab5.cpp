#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <stdexcept>

using namespace std;

struct Pit 
{
	vector<int> v1;
	int count;

	Pit(): count(0) {}

	void add(int value) 
	{
			count++;
			v1.push_back(value);
	}

	void del() 
	{
		if(count > 0) {
			int min = v1[0];
			int top = 0;
			for(int i = 0; i < count; ++i) 
			{
				if(min > v1[i]) 
				{
					min = v1[i];
					top = i;
				}
			}

			count--;
			v1.erase(v1.begin() + top);
		} 
		else
			throw runtime_error("stack pust");
	}
	
	void get() 
	{
		if(count > 0) 
		{
			int min = INT_MAX;
			for(int i = 0; i < count; ++i) 
			{
				if(min > v1[i]) 
				{
					min = v1[i];
				}
			}
			cout << "Min value " << min << endl;
		} 
		else
			throw runtime_error("stack pust");
	}
};

void message(const Pit& x) 
{
	if(x.count < 1)
			throw runtime_error("stack psut");
			
	for(int i = 0; i < x.v1.size(); ++i) 
	{
		cout << x.v1[i] << " ";
	}
	cout << endl;
}

int main() 
{
	try {
		Pit Stack;
    
		Stack.add(1);
		Stack.add(2);
		Stack.add(3);
		Stack.add(4);
		Stack.add(5);
    
		message(Stack);
    
		Stack.get();
    
		Stack.del();
		Stack.del();

		message(Stack);
    
		Stack.get();
    
	} 
	catch(const exception& e) 
	{
		cout << e.what() << endl;
	}

	return 0;
}