// Notes via learning


Converting number to string and vice versa
int number = 10;
string stringnumber = to_string(number);
int number = stoi(stringnumber);

Converting string to char and vice versa
char charecter = 'c';
string stringchar = string(1, charecter)
string backtostring = to_string(strinchar)

2D array creating using vectors:
vector<vector<int>> v{ { 1,2,3 }, { 4,5,6 } };

Strings
s.find(":");
s.substr(pos + 1);
s.substr(startindex, countincludingme); => geeks -> substr(1,3) = eek

Want to improve performance ?
Try iniline functions.
1. inline is a ask not a command, functions doesnt work is the functio has loops, recursion, goto, static variables.
2. Use inline if the function switch time is > than the function execution.

Array Decay:
Sending the array to function with parameter as pointer will get only the first address. this is called array decay.


References vs Pointers:
int x = 10;
int &y = 20;
now the value of x will be 20;

the major differences are
1. References cannot be NULL while initialzing (pointers can be null)
2. References cannot point to another variables after creation (pointers can be pointed to may others)
3. References return type cannot be void.

References can point to null locations by
int * x;
int &ref = *x; (x is not initalized and the reference is pointing to it) (Compile time error)

Explicit:
class myclass{
	int value;
	myclass(int x): value(x);
}
int somefunction(myclass class){
}
somefunction(20)-> Notice iam passing 20(int) to function parameter that has CLASS(class) -> bez the constructor of myclass is NOT explicit -> it will try to convert the 20 to variable in class(value)
				-> this does not occur when you specify the constructor as explicit.
Explicit is like you have to call the object creation based on the constructor
	eg: In unique_ptr you have to pass the object like uniquye_ptr<cars> up(new cars   => this is explicit);
Implicit -> you can just assign the value to the object and constructor implicity converts it. like example above.
https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean

Delete this:
Delete has to be performed on an object that is created with new, If you use delete with this -> its undefined behaviour


Dangling, Void, Null, Wild pointer and Memory leak:

Dangling Pointer: -> its a pointer pointing to nowhere.
int *p = nullptr;
{
	int a = 10;
	int *p =  &a;
}
at this point p is pointing to a reference thats not valid (the value(address) p holds is not valid)

Void pointers cannot be dereferenced;
Pointer arithmetic is not possible on pointers of void due to lack of concrete value and thus size.

Null Pointer:
Its a pointer pointing to nothing (NULL in this case, NULL is defined by the current system thats being used and assigns it with no address)
null pointer is a value while void pointer is a type.

WILD Pointer:
Pointer that is pointing to nothing is called WILD pointer.
int *x; -> this pointer is pointing to nothing, -> WILD POINTER


SmartPointers:
used to auto destroy the pointer memory

Unique Pointer
are used when you need one and only one ownership of the pointer.
unique_ptr<cars> up(new cars);
up->print();
cout << up.get() <<endl;
unique_ptr<cars> up2 = move(up);
up2->print();
cout << up2.get() <<endl;

unique_ptr<cars> up = make_unique<cars>(); -> is recommended usage for construction of object mainly bez of for exception safety

Shared Pointer
Shared pointers are used under reference counting ownership model.
Reference Counting, When a new pointer is assigned it increments, when that pointer is destroyed counting is decremented.
shared_ptr<cars> sp = make_shared<cars>(); -> is recommended, it constructs the object(cars) and the control block for (reference counting) at the same timne.

use_count() -> used to find the number of instances of shared pointer are pointing to the object


weak_pointer

weak_pointer<cars> wp = sp;
wp.expired() -> returns a boolen if its expired or not.


always use nullptr instead of NULL;
Reason being, both NULL nullptr can be used as a boolean -> FALSE
int x = NULL; // works
int y = nullptr; // compilation error

NULL is (void*)0
int *p = nullptr; if (nullptr) => False


malloc vs new:
new -> calls the constructor, throws on error, memory is assinged by compiler
malloc -> no constructor, returns NULL on error, have to specify the size
int *p = (*int) malloc(sizeof(int))


Object oriented programming:
Encapsulation, Abstraction, Polymorphism, Inheritance

Dynamic Binding -> virtual functions -> calling a fucntion happens in the run time,

Inheritance:
MODES of inheritance: Public, Protected, Private
By Default it takes private if you dont specify any mode of inheritance
Public Inheritance:
	public - public
	protected - protected
Protected Inheritance:
	Public	-	Protected
	Protected -	Protected
Private Inheritance:
	Public	-	Private
	Protected - Private



Following are the things which a derived class doesn't inherits from its parent :
1) The base class's constructors and destructor.
2) The base class's friends

Outside object can access ANY functions in PUBLIC.
It CANNOT access any PROTECTEC or PRIVATE from outside. Only the member functions can access them.

TYPES of inheritance:
1. Single
2. Multilevel
3. Multiple (diamond problem)
4. hybrid


Structure vs class:
Default access modifier: structure(public) vs class(private)


Size of a empty class is never zero -> just to ensure the created object address are different.
1.	Class variable cannot have its own type as datamember,
	however it can have static or pointer type.


Static Functions and variables:
Static variables holds the lifetime untill the program is killed.
Static variables has to be defined using scope resolution operator to call the constructor

class bmw {
public:
	static cars c;     => This will not call the construcotr of cars, even though its defined here
	bmw() {
		cout << "Bmw Constructor" << endl;
	}
	~bmw() {
		cout << "BMW destructor" << endl;
	}
	static void func(){
		cout << "calling the static function withouit object" << endl;
	}
};
cars bmw:: c; => This will call the constructor of the cars.

static member functions doesnt need a class object to be invoked
bmw::func() => this will call the function without having to create an object for BMW


Static Member Functions:
static Test * fun() {
	return this; // compiler error -> Cannot return a this pointer.
}
1. Cannot have this pointer (retuned)
2. Member functions cannot be virtual
   static void fun() {}
   void fun() {} // compiler error -> Cannot be overloaded
3. Member functions cannot be overloaded with same function name if one of them are static functions.
4. static void fun() const {} => Static functions cannot be declared as const, volatile, const volatile.

Friend Functions:
Friend functions are used if you need to access private member variables or functions;
class cars {
	void access() {
		cout << "accesing bmw class in private" << endl;
	}
public:
	friend class bmw; => Now bmw public member function can access private (access() member function) in cars class;
};



class bmw {
public:
	void canyou(cars &c) {
		c.access();
	}
};
bmw b; cars c;
b.canyou(c) => wil print => accesing bmw class in private => this can access the private members of cars from public member function of bmw.


Constructor | Copy Constructor:
Types of constructors:
1. Default constructor
2. Parameterized constructor

Copy constructor:
1. Copy constructor is used when you need to copy the values of the object to another object of same class.
Copy constructor is called when you assign a existing object to newly created object,
In C++, a Copy Constructor may be called in following cases:
1. When an object of the class is returned by value
2. When an object of the class is passed (to a function) by value as an argument.
3. When an object is constructed based on another object of the same class.
4. When compiler generates a temporary object.

The above things may or may not call the copy constructor, its depending on the compiler
This phenomena is called RVO (Return value optimization)

cars c1;
cars c = c1; => copy constructor is called
c = c1 => assignment operator is called

Shallow vs Deep copy:
1. If you dont specify any constructor then default copy constructor is assinged by the compiler and it does shallow copy.
2. you need to specify your own copy constructor if you are intrested in the deep copy.

Deep copy is wll suited if you have a pointer in the class and you need to copy all the elements to the object.


Initialization list of constructors:
1. use this when you initialise base class constructopr
2. Use this if you have const memeber variable.
3. its faster in performance.
4. Inititlizing reference numbers.

IF YOU WRITE ANY CONSTRUCTOR  then you MUST  have to write the default constructor.
COMPILER doesnt create a default constructor when you create any constructor (including copy constructor)

Virtual:
1. Constructors CANNOT be virtual
2. Destructors CAN be virtual


Destructor:
Desctructor is called when the class object goes out of scope.
Destructors can be virtual

Constructor and Destructor can be called explicitly.

Function overloading:
Overloading happens at runtime. (POLYMORPHISM)

which CANNOT overloading:
1. functions only differ in the return type.
2. if one of them is a static member function.
3.	int fun(int *ptr);
	int fun(int ptr[]);  => this is not overloading, bez ptr[] is == *ptr
4.	int f ( int x) {
		return x+10;
	}

	int f ( const int x) {
		return x+10;
	}						=> presence or absence of CONST / VOLATILE => is NOT overloading functions.
							=> C++ allows them if the parameters is a pointer or reference and const
								eg: int f(const int* p) and int f(int *p)  => this is considered OVERLOADING

5.	int f ( int x, int y)
	int f ( int x, int y = 10) => Difference in default parameters is equivalent.


Which CAN be overloading

1. Functions can have the same name but different parameters. (number of parameters, type of parameters)
2. functions that has const types
	void fun() const
    void fun()
3. Const parameter is a reference or a pointer.

IMP in case of function overloading:
when you pass func(3.5) => 3.5 is noted as double by the compiler
and if you have 	void func(double i)  and void func(int i), compiler calls the double parameter function
					void func(float i ) and void func(int i ), compiler throws error of ambiguity, double can be converted to float or int.
	To avoid this instead of passing as (3.5) you have to speciofy the value as float by passing (3.5f)



Operator Overloading:
1. Operators can be overloaded to work with the functionality that we need.
2. . (dot)
   ::
   ?:
   sizeof    => These operators cannot be overloaded.

3. Reasons to use our own operator overloading, -> when you need the assignemnt operator to be private you canb do tat (single ton class)



Operator overloading for increments:
void operator++(int)  => calls the post increment => C++
void operator++()=> calls pre increment

Virtual Functions:
Virtual functions help in run time polymorphism.
virtual function is basically creating a base class pointer and accessing the derived class objects. or the one's that it is assigned with.,

Virtual functions with default parameters - > http://www.geeksforgeeks.org/output-of-c-program-set-12-2/

Virtual defined in the base class applies to the functions in the derived class without mentioning them as virtual.
1. Static functions cannot be virtual.
2. Virtual functions can be private (to use them utilize friend functions).
3. Virtual functions cannot be inline.

Modifying the access specifiers with virtual:
1. If you change the modifiers in base class to private and try to access that member function using base class pointer => IT WILL WORK.
class b {
public:
	virtual void func() {
		cout << "func in the class b " << endl;
	}
};

class d : public b {
private:
	void func() {
		cout << "func in the d class " << endl;
	}
};

int main()
{
	b* b1 = new d;
	b1->func(); => This will work !!
}



Virtual constructors and destructors:
1. Constructors CANNOT be virtual
2. Destructors CAN be virtual

Virtual Destructors:
1. If you assign derived class object to base class pointer and delete the pointer, it will destruct the base class dest not the derived class.
2. To solve that, we use virtual to base class destructors.
Eg:
class base {
  public:
	base()
	{ cout<<"Constructing base \n"; }
	~base()
	{ cout<<"Destructing base \n"; }
};

class derived: public base {
  public:
	derived()
	{ cout<<"Constructing derived \n"; }
	~derived()
	{ cout<<"Destructing derived \n"; }
};

int main(void)
{
  base *b = new derived();
  delete b;
  getchar();
  return 0;
}


Abstract Class and Pure virtual functions:
1. A class that has ATLEAST ONE pure virtual function is called abstract class
2. // An abstract class
	class Test
	{
		// Data members of class
	public:
		// Pure Virtual Function
		virtual void show() = 0;
	}
3. We cannot create objects for abstract class , we can however create references and pointers to the abstract class.
4. If you DONT override the pure virtual functions in derived class -> Then derived class becomes ABSTRACT CLASS
5. Abstract class CAN HAVE CONSTRUCTORS and DESTRUCTORS (since it can have pointers) !!!!
	class ab {
	public:
		virtual void show() = 0;
		ab() {
			cout << "having a constructor" << endl;
		}
		virtual ~ab() {
			cout << "having a destructor" << endl;
		}
	};
6. Pure virtual destructors are ALLOWED buuuuuuutt you need to provide the body of it.
				class Base
				{
				public:
					virtual ~Base()=0; // Pure virtual destructor
				};
				Base::~Base()
				{
					std::cout << "Pure virtual destructor is called";   => Without this it throws error
				}

				class Derived : public Base
				{
				public:
					~Derived()
					{
						std::cout << "~Derived() is executed\n";
					}
				};

				int main()
				{
					Base *b = new Derived();
					delete b;
					return 0;
				}


Object Slicing:

1. Object slicing happens if you assign a derived class object to base class object.

The way to avoid object slicing
1. Make the base class as abstract class (atleast one pure virtual function) => there by cannot create any objects.
2. Make the base class object as pointer or reference -> there by it inherits the address.

	b b1(20); => initially this B1 object has x = 20
	d d1(45, 55); => this d1 is public from b => so this gets the x from base => this contains x = 45, y =55
	b1 = d1; => When you assign it, 45 of derived X is replaced with 20 of base X, and the rest of Y is dropped -> this is object slicing
	b1.display();

	To resolve this;
	b1 has to be a reference or poiinter.
	b* b2 = new b(20);
	d* d2 = new d(45, 55);
	b2 = d2; // this will not cause any problem bez b1 pointing to the address of d2 // No object slicing happpens here.
	b2->display();
	https://www.geeksforgeeks.org/object-slicing-in-c/




	Multithreading:

	1. thread t1(fucntion pointer) => Creates the thread
	2. t1.join() => makes the main program to wait untill the t1 thread is done  and ready to join.
	3. t1.detach() => makes the t1 to detach and become a DEAMON process.
	4. t1(functionpointer, parameter) => to send the value by reference to a thread.
	5. t1(functionpointer, std::ref(parameter)) => Send value by reference
	6. t1(functionpointer, std::move(parameter)) => complety moves the localvariable/parameter from the main therad to the t1 thread
	7. thread t2 = std::move(t1) => Threads cannot be copied, it can only be moved (just like unique_ptr)
	8. this_thread::get_id() => will give your the ID for your thread.
	9. t1.get_id() => will get you the id of the child (t1) thread.

	10. Over subscription: Using more threads than whats the hardware is capable of, this can be known from thread::hardware_concurrency()
	11. RaceCondition: to solve the race condition we can use the mutex #include <mutex>
		DataRace: to avoid	1.	Use mutex to synchronize the data.
							2.	Never expose the data to outside world.
							3.	Design your Class/Interface appropriately

	12.	mutex mu; mu.lock(); mu.unlock()
	13. To avoid lockig forever -> lock_guard<mutex> guard(mu); => this locks when its called and unlocks when out of scope.
	14. Every mutex has to be closely coupled with the resource (wrap that in a class)
	15: Deadlock:
		To avoid deadlock:	1.	Prefer locking a single mutex at once.
							2.	Avoid locking and calling a user defined function
							3.	If you need to lock more than one mutex, consider using lock()
								lock(mutex1, mutex2); lock_guard<mutex> lock1(mutex1, adopt_lock) => mutex is already locked just adopt that lock.
							4.	In general try locking the mutex in same order in every thread.
							5.	Try to create a hierarchy of mutex so, lower level mutex cannot lock higher level mutex
	16.	Granularity:	fine-grained-lock: Protects small amount of data.
											1. If fine grained, your program becomes more tricky and (expose to errors) hard to handle.
						coarse-grained-lock: You might not be using multithreading to its extent
	17.	unique_lock<mutex> ul(mutex):
			1.	Unique lock gives you the flexiblity of locking and unlocking the resource any number of times.
			2.	ul.lock(); ul.unlock();
			3.	you can defer the locking by unique_lock<mutex> ul(mu, defer_lock) => this dosent lock the mutex;
					Later you have to call ul.lock() and ul.unlock();
			4.	Unique lock is heavy when compared with lock_guard. => ALways use lock_guard<mutex> if your are concerned about performance.

	18.	call_once(flag, [&](){ _f.open('file.txt')}) => If you need to make this open file only once, C++ standard library let us use call_once functions,
		where the file will be opened only once.

	19.	condition_variable cond; => to synchronize both threads.
				unique_lock<mutex> locker(mutex);
			1.	cond.wait(locker) => conditional variables makes the thread to wait, by releasing the locker(mutex)
				cond.wait(locker, [](){ return !q.empty(); }) => 2nd parameter is called, Predicate => if the thread starts running even without the lock this predicate will let it wait.
			2.	cond.notify_one() => To notify other ONE thread about the condition variable
				cond.notify_all() => To notify all other threads.


	20. Passing values from main thread to child thread, different ways.
			1.	thread t1(functionpointer, parameter)
			2.	thread t2(functionpointer, ref(parameter))
			3.	thread t3(functionpointer, move(parameter))
			4.	thread t4([](int x){return x;}, x);

			mutex mu;
			condition_variable cv;
			bool isit = true;

			void function(int &parameter) {
				unique_lock<mutex> uq(mu, defer_lock);		=> You have to lock it later, its a defer_lock => Pay attention to the lock names, doesnt need to be same name as main function.
				for (int i = 0; i < 20; i++) {
					uq.lock();
					cv.wait(uq);							=> this will wait untill its notified (which is the main thread)
					cout << "From child thread: " << parameter << endl;
					uq.unlock();
				}
				parameter = 7888;
			}

			int main() {
				int variable = 22;
				thread t1(function, ref(variable));
				unique_lock<mutex> uniquelock(mu, defer_lock);
					for (int i = 0; i >-10 ; i--) {
						this_thread::sleep_for(chrono::milliseconds(500));
						uniquelock.lock();
						cout << "            From main thread: " << i << endl;
						cv.notify_one();
						uniquelock.unlock();
					}
				t1.join();														=>	main thread will wait untill this is done.
				cout << " in the rest of main thread : " << variable <<  endl;
				return 0;

			}


	21.	Future, Promise, async() : If you want to send the values later to the thread not by the time they are inititalised.

				promise<int> p;
				future<int> fu1 = p.get_future();
				future<int> fu = async(launch::async, threadFunction, ref(fu1));
				cout << "From main afterall" << endl;
				this_thread::sleep_for(chrono::milliseconds(2000));
				p.set_value(10);
				cout << fu.get() << endl;








	C++ STL vs Python

	1. Priority queue (heaps)

		1. by default: max heap
			priority_queue<int> pq;
		2. To make it min heap
			priority_queue<int,vector<int>, greater<int>> pq;
		3. To make a custom compare
			You can make a functor in the comparator -> but this is less key strokes
			auto comp = [&](int a, int b) { return a < b; }; => here < is all the less elements are in the end => So its max heap (front are large)
			priority_queue<int, vector<int>, decltype(comp) > pq(comp);
		4. You Cannot iterate with iterator for pq;
		5. pq.top(); pq.empty(); pq.pop(); pq.push(); pq.size();

	2. Arrays - Vectors
		// Initializing the array
		vector<int> vv = { 1,2,3 };
		vv[0] = 20;
		// Python
		arr = [1,2,3]
		arr[0]

		// finding an element in the array
		auto it = find(vv.begin(), vv.end(), 2);
		cout << it - vv.begin() << endl; => to find the index
		// Python
		arr.find(1) // returns index


		// Traversing the vector front and back -> v.begin() starts at first element; v.end() ends after the last element.
		for (vector<int>::iterator it = vv.end() - 1; it >= vv.begin(); it--) {
			cout << *it << endl;
		}
		// Python
		for v in vv:
			print (v)

		// Initializing 2d array of length 3
		vector<vector<int>> vv({ { 1,2,3 } });
		vector<vector<int>> vv(5, vector<int> (5, 1.5)); => Initialize 5x5 array with default values to 1.5


		// Python
		arr = [[0]*3 for _ in range(3)] => Initialize values with 0 in the arrays

	3. deque

		deque<int> dq; // FRONT MIDDLE BACK
		//Python
		import deque
		dq = deque([])

		dq.push_front(10);
		// Python
		dq.appendleft()

		dq.push_back(20);
		// Python
		dq.append(10);

		dq.front();
		//Python
		dq[0]

		dq.back();
		//Python
		dq[-1]

		dq.pop_front();
		//Python
		dq.popleft();

		dq.pop_back();
		//Python
		dq.pop();

		auto iterator = find(dq.begin(), dq.end(), value);
		for(auto d: dq) => CAN iterate to this.


	4. MAP

		unordered_map<int, int> um;

		um.first, um.second.

		um.at(key)
		um.erase(key)
		um.size()


		Can iterate

	5. SET

		set<int> s;
		s.insert(100);
		s.remove(100);
		s.find(20); => returns iterator

		Can iterate


	6. Stack

		stack<int> s;
		s.push(20);
		s.pop(20);
		s.top(20);





Findings on the stl;

int position = find_first_not_of("abcd  -")
