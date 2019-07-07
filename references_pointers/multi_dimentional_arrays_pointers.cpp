// C program to understand difference between 
// pointer to an integer and pointer to an 
// array of integers. 
#include<stdio.h> 
#include<iostream>

using namespace std;


int main()
{
	// Pointer to an integer 
	int* p;

	// Pointer to an array of 5 integers 
	int(*ptr)[5];
	int arr[5] = {1,3,4,5,6};

	// Points to 0th element of the arr. 
	p = arr;

	// Points to the whole array arr. 
	ptr = &arr;

	printf("p = %p, ptr = %p\n", p, ptr);
	cout << "Pointer is " << ptr[1] << endl;

	p++;
	ptr++;

	printf("p = %p, ptr = %p\n", p, ptr);

	int* ptra;
	int val;
	ptra = &val;
	*ptra = 20;
	cout << "Value at " << *ptra << " and val is " << val << endl;

	return 0;
}
