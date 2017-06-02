#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <ctime>
#include <climits>


using namespace std;

template <typename tname>
struct Pit 
{
	vector<tname> v1;
	int count;

	Pit(): count(0) {}

	void add(tname value) 
	{
			count++;
			v1.push_back(value);
	}
	void del() 
	{
		if(count > 0) {
			tname min = v1[0];
			int pos = 0;
			for(int i = 0; i < count; ++i) 
			{
				if(min > v1[i]) 
				{
					min = v1[i];
					pos = i;
				}
			}
			count--;
			v1.erase(v1.begin() + pos);
		} 
		else
			throw runtime_error("stack pust");
	}
	
	void get()
	{
		if(count > 0) 
		{
			tname min = INT_MAX;
			for(int i = 0; i < count; i++)
			{
				if(min > v1[i]) 
				{
					min = v1[i];
				}
			}
			cout << "min value = " << min << endl;
		} 
		else
			throw runtime_error("stack pust");
		
	}
	
	void output() 
	{
		if(count > 0)
		{
			for(int i = 0; i < count; i++)
			{
				cout << v1[i] << "  ";
			}
			cout << endl;
		} 
		else
			throw runtime_error("stack pust");
	}
}; 

int main() 
{
	try 
	{
		cout << "type int\n";
		
		Pit <int> stack;
		stack.add(12);
		stack.add(341);
		stack.add(-434);
		stack.add(312321);
		stack.add(-434343);
		stack.output();
		stack.get();
		stack.del();
		stack.del();
		stack.output();
		stack.get();
		
		cout<<"\n\ntype double\n";
		
		Pit <double> stack2;

		stack2.add(4.543);
		stack2.add(545.254);
		stack2.add(0.13232);
		stack2.add(-12.856);
		stack2.add(-5445.554);
		stack2.output();
		stack2.get();
		stack2.del();
		stack2.del();
		stack2.output();
		stack2.get();

	} 
	catch(const exception& e) 
	{
		cout << e.what() << endl;
	}
	return 0;
}