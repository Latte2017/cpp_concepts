#include<iostream>
#include <array>

using namespace std;

class bitManipulations {
private:
	unsigned int res;
public:
	unsigned int bitAnd(const char& a, const char& b) {
		
		res = a & b;
		return res;
	}
	
	unsigned int bitOr(unsigned char& a, unsigned char& b) {
		res = a | b;
		return res;
	}
	unsigned int bitXor(unsigned char& a, unsigned char& b) {
		res = a ^ b;
		return res;
	}
	unsigned int bitLeftShift(unsigned char& a) {
		res = a << 1;
		return res;
	}
	unsigned int bitRightShift(unsigned char& a) {
		res = a >> 1;
		return res;
	}
	unsigned int bitNot(const unsigned char& a) {
		res = ~a;
		return res;
	}
	//XOR sample questions
	int findOddNumber(const std::array<int, 5> &arr) {
		res =0;
		for (int i = 0; i < arr.size(); i++) {
			res ^= arr[i];
		}
		return res;
	}
	int returnMissingNumber(int arr[], int arr_size) {
		int missing_num = 0, xor_res_n = 1, xor_res_arr = arr[0];
		
		for (int i = 1; i < arr_size; i++) {
			xor_res_arr ^= arr[i];
		}
		for (int i = 2; i <= arr_size + 1; i++) {
			xor_res_n ^= i;
		}
     	return (xor_res_n ^ xor_res_arr);
	}
	int swapTwoNumbers(int *a, int *b) {
		/*example x = 10 and y = 5
		10 = 1010, 5 = 0101
		10 ^ 5 = 1111
		x = 1111 (15)
		y = 1111 ^ y (=10) 
		x = 1111 ^ y (=5)
		*/
		*a = *a ^ *b;
		*b = *a ^ *b;
		*a = *a ^ *b;
		return 0;
	}
	void get2NonRepeatingNos(int arr[], int n, int* x, int* y)
	{
		int Xor = arr[0]; /* Will hold Xor of all elements */
		int set_bit_no; /* Will have only single set bit of Xor */
		int i;
		*x = 0;
		*y = 0;

		/* Get the Xor of all elements */
		for (i = 1; i < n; i++)
			Xor ^= arr[i];

		/* Get the rightmost set bit in set_bit_no */
		set_bit_no = Xor & ~(Xor - 1);

		/* Now divide elements in two sets by comparing rightmost set
		bit of Xor with bit at same position in each element. */
		for (i = 0; i < n; i++)
		{
			if (arr[i] & set_bit_no)
				* x = *x ^ arr[i]; /*Xor of first set */
			else
				*y = *y ^ arr[i]; /*Xor of second set*/
		}
	}
	void leftShiftByNumber(int* x) {
		*x =  (1 << *x);
	}

	//Check if string has unique characters. Works for a-z
	bool isUniqueChars(string s) {
		int checker = 0;
		for (int i = 0; i < s.size(); i++) {
			int val = s.at(i) - 'a';
			if ((checker & (1 << val)) > 0) {
				return false;
			}
			checker |= (1 << val);
		}
		return true;
	}
};

int main() {
	unsigned char a = 5, b = 9;
	int num1, before_val, num2, after_val;
	num1 = before_val = 5;
	num2 = after_val = 10;
	string s = "abc";
	bool isuniq;
	array <int, 5> arr1 = { 1,1,2,2,4 };
	int arr3[] = { 2, 3, 7, 9, 11, 2, 3, 11 };
	int* r1, * r2;
	r1 = new int[(sizeof(int))];
	r2 = new int[(sizeof(int))];
	int arr2[] = { 1,2,4};
	int arr2_size = (sizeof(arr2) / sizeof(int));
	unsigned int res, res1;
	bitManipulations test1;
	res = test1.bitAnd(a, b);
	cout << "A Bitwise And B is " << res << endl;
	
	res = test1.bitOr(a, b);
	cout << "A Bitwise Or B is " << res << endl;
	res = test1.bitXor(a, b);
	cout << "A Bitwise Xor B is " << res << endl;
	res = test1.bitLeftShift(a);
	cout << "A Bitwise LeftShift is " << res << endl;
	res = test1.bitRightShift(a);
	cout << "A Bitwise RightShift is " << res << endl;
	res = test1.bitNot(a);
	cout << "A Bitwise Not is " << test1.bitNot(a) << endl;
	res = test1.findOddNumber(arr1);
	cout << "Odd number is " << res << endl;
	res = test1.returnMissingNumber(arr2, arr2_size);
	cout << "Missing value is " << res << endl;
	test1.swapTwoNumbers(&num1, &num2);
	cout << "First number was " << before_val <<  " Now its " << num1 << " Second number was " << after_val << " Now its " << num2 << endl;
	test1.get2NonRepeatingNos(arr3, 8, r1, r2);
	cout << "Non repeating number are " << *r1 << " " << *r2 << endl;
	test1.leftShiftByNumber(r1);
	cout << "Left shifted number is " << *r1 << endl;
	isuniq = test1.isUniqueChars(s);
	cout << "The given string " << s << " is " << isuniq << endl;
	/*
	res = test1.bitAnd(a, b);
	cout << "A Bitwise And B is " << res << endl;
	*/
	 
}