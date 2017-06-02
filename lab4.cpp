#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct tree 
{
	vector<int> v;
    int value;
};
    tree massive[10];
    
int getTop(int* arr, int size) 
{
    int z;
    for(int i = 0; i < size; ++i) 
	{
        if(arr[i] == -1) 
		{
			z = i; 
		}
	}
    return z;
}
    
void match_tree(int* arr, int size, int base, int pos) 
{
    for(int i = 0; i < size; ++i) 
	{
        if(arr[i] == pos) 
		{
			massive[i].value = i;
            if(pos >= 0) 
			{
				massive[base].v.push_back(i); 
			}
            match_tree(arr, size, i, i);
		}
	}
}
void message_1(const tree& A, int a = 0) 
{
	cout << " ";
	cout << A.value << endl;
    for(vector<int>::const_iterator iter = A.v.begin(); iter != A.v.end(); ++iter) 
	{
        message_1(massive[*iter], (a + 1));
	}
}
void message_2(const tree& A, int a = 0) 
{
    for(vector<int>::const_iterator iter = A.v.begin(); iter != A.v.end(); ++iter) 
	{
        message_2(massive[*iter], (a + 1));
	}
	cout << " ";
	cout << A.value << endl;
}

void message_3(const tree& A, int a = 0) 
{
	vector<int>::const_iterator iter = A.v.begin();
    if (iter != A.v.end())
        message_3(massive[*iter++], (a + 1));
	cout << " ";
	cout << A.value << endl;
    for(; iter != A.v.end(); ++iter) 
	{
        message_3(massive[*iter], (a + 1));
	}
}
int main() 
{
    int mass[] = {-1, 0, 0, 0, 1, 2, 3, 1, 2};
    int m = sizeof(mass)/sizeof(int);
    int top = getTop(mass, m);
    
    match_tree(mass, m, top, -1);
    
    message_1(massive[top]);
	cout << endl;
    message_2(massive[top]);
	cout << endl;
    message_3(massive[top]);
    
    return 0;
}