/*
Read and write to file
*/

#include<string>
#include <iostream>

using namespace std;

class FileIO {
public:
	void readLine(){
		string str;
		while (cin >> str) {
			if (str == " "){
				cout << str << "Emptyline" << endl;
			}
			
		}
	}

	void readLine2() {
		string str;
		while (getline(cin, str)) {
			if (str.empty()) {
				cout << str << "Emptyline" << endl;
			}

		}
	}
};

int main() {
	FileIO f1;
	//f1.readLine();
	f1.readLine2();

}