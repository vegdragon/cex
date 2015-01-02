#include <iostream>

int s(int v) 
{
	int count=0; 
	int x=v; 
	while (x)
	{
		count++;
		x=x&(x-1); 
	}
	return count; 
}

int main()
{
	std::cout<<s(9999)<<std::endl;
	return 0;
}