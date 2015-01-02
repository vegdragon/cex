#include <iostream>
using namespace std;

int main()
{
	int array[] = { 3,7,2,4,9,10,25,87,32,22 };
	int i = 0, j = 0;
	int size = sizeof(array) / sizeof(int);
	int insData = array[1];

	for (i=0;i<size;i++)
	{
		insData = array[i];
		for (j=i;(j-1)>=0 && insData<array[j-1];j--)
		{
			array[j] = array[j-1];
		}
		array[j] = insData;
	}

	for (i=0;i<size;i++)
	{
		cout<<array[i]<<endl;
	}

	return 0;
}