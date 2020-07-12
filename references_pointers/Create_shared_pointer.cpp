/*
Create a shared pointer class 

Link: https://www.geeksforgeeks.org/how-to-implement-user-defined-shared-pointers-in-c/


*/

#include <ostream>
#include<iostream>

using namespace std;

//Class representing reference count;
class Counter {
private:
	unsigned int m_counter{};
public:
	Counter(){
		m_counter = 0;
	};

	Counter(const Counter&) = delete; //Delete the Copy Constructor
	Counter& operator=(const Counter&) = delete; //Delete Assignment Constuctor

	//Destructor
	~Counter(){
	}

	//Overload post operator
	//To differenciate post from prefix operator postfix takes
	//Additional argument int
	void operator++(int) {
		m_counter++;
	}

	//Overload pre operator
	void operator++() {
		++m_counter;
	}

	//Overload post decrement operator
	void operator--(int) {
		m_counter--;
	}

	//Overload pre decrement operator
	void operator--() {
		--m_counter;
	}

	//overload << operator
	//The ostream object must be declared as a friend of class Counter 
	// Or else it wont be able to access the private memebers
	// of Counter class
	friend ostream& operator<<(ostream& os, const Counter& counter) {
		os << "Counter value is  " << counter.m_counter << endl;
		return os;
	}

	unsigned int get() {
		return m_counter;
	}

	void reset() {
		m_counter = 0;
	}
};


//class representing shared pointer
template <typename T>

class Shared_ptr {
private:
	//Reference Counter
	Counter* m_counter;

	// Shared counter
	T* m_ptr;
public:

	/*Constructor
	class has a constructor which can be called with a single argument,
	then this constructor becomes conversion constructor 
	because such a constructor allows conversion of the single argument to the class being constructed
	*/
	explicit Shared_ptr(T* ptr = nullptr) {
		m_ptr = ptr;
		m_counter = new Counter();
		if (ptr) {
			++(*m_counter);
		}
	}

	//Copy Constructor
	Shared_ptr(Shared_ptr<T>& sp) {
		m_ptr = sp.m_ptr;
		m_counter = sp.m_counter;
		(*m_counter)++;
	}

	//Reference count
	unsigned int use_count() {
		return m_counter->get();
	}

	//Get the pointer
	T* get() {
		return m_ptr;
	}

	//Overload star pointer
	T& operator*() {
		return *m_ptr;
	}

	//Overload arrow operator
	const T operator->() {
		return m_ptr;
	}

	~Shared_ptr() {
		(*m_counter)--;
		if (m_counter->get() == 0) {
			delete m_counter;
			delete m_ptr;
		}
	}

	friend ostream& operator<<(ostream& os, Shared_ptr<T>& sp)
	{
		os << "Address pointed : "
			<< sp.get() << endl;
		cout << "Reference count is " << *(sp.m_counter) << endl;
		return os;
	}
};

int main() {
	Shared_ptr<int> p1(new int(140));
	*p1 = 100;
	cout << *p1 << endl;
	cout << p1 << endl;
	{
		Shared_ptr<int> p2 = p1;
		cout << *p2 << endl;
		cout << p2 << endl;
	}

}
