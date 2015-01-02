#include <iostream>
using namespace std;

class Base
{
public:
	Base() {}
	virtual ~Base() {}
	virtual void func1() {}
	virtual void func2() {}
	virtual void func3() {}

private:
	int a;
	int b;
	static int c;
};

class Derived : public Base
{
public:
	Derived() {}
	virtual ~Derived() {}

	virtual void func1() {}
	virtual void func2() {}

	/* data */

};

int main()
{
	Base b;
	Derived d;
	cout<<"Base size: "<<sizeof(b)<<endl;
	cout<<"Base class size: "<<sizeof(Base)<<endl;
	
	cout<<"Derived size: "<<sizeof(d)<<endl;

	return 0;
}