#include <iostream>
#include <complex>
using namespace std;
class Base
{
public:
    Base() { cout<<"Base-ctor"<<endl; }
    ~Base() { cout<<"Base-dtor"<<endl; }
    virtual void f(int) { cout<<"Base::f(int)"<<endl; }
    virtual void f(double) {cout<<"Base::f(double)"<<endl; }
    virtual void g(int i = 15) {cout<<"Base::g()"<<i<<endl; }
};
class Derived: public Base
{
public:
    Derived() { cout<<"Derived-ctor"<<endl; }
    ~Derived() { cout<<"Derived-dtor"<<endl; }
    void f(complex<double>) { cout<<"Derived::f(complex)"<<endl; }
    virtual void g(int i = 20) {cout<<"Derived::g()"<<i<<endl; }
};

int main()
{
	Base b;
	Derived d;
	Base* pb = new Derived;
	// Select the correct one from the four choices:
	cout<<sizeof(Base)<<endl;	

	pb->f(1.0);
	pb->g();

	return 0;
}
