#include <iostream>
using namespace std;
#define SIZE 2009



int main()
{
	int i;
	int j;
	int tmp = 10;
	int result = 0;

	for (i=0;i<SIZE;i++)
	{
		tmp = 10;
		for (j=0;j<i-1;j++)
		{
			tmp *= 10;
		}
		result += tmp;
	}

	result /= 9;

	cout<<"result = "<<result;
}
