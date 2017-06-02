#include <iostream>	 
#include <fstream>
#include <cstring>
	
using namespace std;
	
int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream file1,file2;
	file1.open("/filelaba/file1.txt",ios::binary);
	file2.open("/filelaba/file2.txt",ios::binary);
	

	int count1, count2; //считаем количество строк у обоих файлов
	count1 = 0; count2 = 0;
	string str;
	while(!file1.eof())
	{
		getline(file1, str);
	    count1++;
	}
	   
	file1.clear();
	file1.seekg(0,ios::beg);

	while(!file2.eof())
	{
		getline(file2, str);
	    count2++;
	}
	file2.clear();
	file2.seekg(0, ios::beg);
	

	if(count1 != count2) // сравниваем кол-во строк
	{
		cout << "Отличия в кол-ве строк" << "\n";
	    cout << "У 1 файла " << count1 << " строки, а у 2 "<< count2 << " строки" << "\n";
	}

	char string1[256], string2[256]; 
	int i = 0;
	while(!file1.eof())
	{
		file1.getline(string1, 256);
		file2.getline(string2, 256);
	    i++;
	    if(strcmp(string1, string2) != 0)
	    {
	    	cout << i << " строка отличается" << "\n";
	        cout << "   " << string1 << " - в первом файле \n";
	        cout << "   " << string2 << " - во втором файле\n";
	    }
	}
	return 0;
}