#include <iostream>
using namespace std;

void exchange(int & a, int & b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
	return;
}

int partition(int input[], int low, int high)
{
	int pivot = input[high];
	int i;
	int end = low-1;

	for (i=low;i<high;i++)
	{
		if (input[i]<pivot)
		{
			exchange(input[++end], input[i]);
		}
	}
	exchange(input[high], input[++end]);

	return end;
}

void quicksort(int input[], int low, int high)
{
	int mid = -1;
	printf("low=%d, high=%d\n", low, high);
	if (low < high)
	{
		mid = partition(input, low, high);
		printf("low=%d, mid=%d, high=%d\n", low, mid, high);
		quicksort(input, low, mid-1);
		quicksort(input, mid+1, high);
	}
}

int main()
{
	int input[10] = { 3, 9, 7, 432, 93, 22, 64, 12, 66, 24 };
	int i = 0;
	quicksort(input, 0, 9);

	for (i=0;i<10;i++)
	{
		cout<<input[i]<<"\t";
	}
	cout<<endl;

	return 0;
}