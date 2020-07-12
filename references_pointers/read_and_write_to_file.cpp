/*
Read and write to file
*/

#include<string>
#include <iostream>
#include<istream>
#include<list>
#include <fstream>
#include <algorithm>
#include <time.h>
#include<filesystem>
#include <string>
#include <windows.h>
using namespace std;

class FileIO {
private:
	string f_name;
	//char filename[] ;
public:
	FileIO() {
		
		
		f_name = "ints.dat";
	}

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

	void CreateFile() {
		ofstream f1;
		f1.open(f_name, ios::out);
		int iter = 1;
		srand(time(0));
		while (iter < 101) {
			f1 << rand() % iter << endl;
			iter++;
		}
		f1.close();
	}

	void ReadFile() {
		ifstream myfile;
		string line;
		myfile.open(f_name, ios::in);
		if (myfile.is_open()) {
			while (getline(myfile, line)) {
				cout << line << endl;
			}
			myfile.close();
		}
		else {
			cout << "Error reading file " << endl;
		}
		return;
	}

	void SeekFile() {
		ifstream myfile;
		string line;
		myfile.open(f_name);
		if (myfile.is_open()) {
			//myfile.seekg(9, myfile.beg()); //Move 9 positions from beginning
			getline(myfile, line);
			cout << line << endl;
		}

	}


	void DeleteFile() {
		
		if (remove(f_name.c_str()) == 0) {
			cout << "Deleted file" << endl;
		}
		else {
			cerr << "Unable to delete" << endl;
		}
	}
};





int main() {
	FileIO f1;
	f1.CreateFile();
	//f1.readLine();
	//f1.readLine2();

	ifstream dataFile("ints.dat");
	//list<int> data1(istream_iterator<int>(dataFile), istream_iterator<int>()); 
	//Doest work as expected missing braces around istream_iterator<int>(dataFile)
	list<int> data2((istream_iterator<int>(dataFile)), istream_iterator<int>());

}