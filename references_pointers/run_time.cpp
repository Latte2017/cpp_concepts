// CPP program to illustrate 
// concept of Virtual Functions 
//function overriding
/*
Virtual functions allow us to create a list of base class pointers 
and call methods of any of the derived classes without even knowing kind of derived class object
*/
#include<iostream> 
using namespace std;

class base
{
public:
	virtual void print()
	{
		cout << "print base class" << endl;
	}

	void show()
	{
		cout << "show base class" << endl;
	}
};

class derived :public base
{
public:
	void print()
	{
		cout << "print derived class" << endl;
	}

	void show()
	{
		cout << "show derived class" << endl;
	}
};

int main()
{
	base* bptr;
	derived d;
	bptr = &d;

	//virtual function, binded at runtime 
	bptr->print();

	// Non-virtual function, binded at compile time 
	bptr->show();

	derived d1;

	d1.show();
}


