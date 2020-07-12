#include<iostream>
#include<memory>

using namespace std;

class Entity {
public:
	Entity() {
		cout << "created" << endl;
	}
	~Entity() {
		cout << "destroyed" << endl;
	}
	void print() {

	}
};

int main() {
		{
			//Need explicit calling of construnctor
			//Cannot be copied.
			//donot use new Entity() for exception safety.
			unique_ptr<Entity> e1 = make_unique<Entity>();
			e1->print();
			/*
			unique_ptr<Entity>* e2 = &make_unique<Entity>();
			e2->print();
			*/
		}

		/*Shared pointers work on reference counters. 
		Once all the references all deleted then share pointer is destroyed.
		Can be copied all around.
		Shared pointer allocates 2 blocks one for object and another one for reference.
		*/
		{
			shared_ptr<Entity> e3;
			{
				shared_ptr<Entity> e4 = make_shared<Entity>();
				//e3 = e4;
			}
		}

		/* Weak pointers are pointers where reference count is not increased
		*/
		{
			shared_ptr<Entity> e7 = make_shared<Entity>();
			weak_ptr<Entity> e6 = e7;
			{
				shared_ptr<Entity> e5 = e6.lock();
				if (e5) {
					cout << "I made a shared pointer from weak pointer" << endl;
				}
			}
			
			//If we dont use lock e6 points to invalid memory
			//
		}
}