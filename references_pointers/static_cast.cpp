//Need to understand

struct A {};
struct B : A {};

int main()
{
	A a;
	A& a_ref = a;

	static_cast<B>(a); // *1
	static_cast<B&>(a_ref); // *2

	return 0;
}