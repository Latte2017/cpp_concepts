#include<vector>
#include<iostream>

using namespace std;

int main() {
	int num_rows = 0, num_columns = 0;
	vector<vector<int>> multi_v1;
	srand(100);
	cout << "Print number of rows and columns" << endl;
	cin >> num_rows;
	cin >> num_columns;

	for (int i = 0; i < num_rows; ++i) {
		vector<int> temp(num_columns, 0);
		multi_v1.push_back(temp);
		for (int j = 0; j < num_columns; ++j) {
			multi_v1[i][j] = 10;
		}
	}
	cout << multi_v1[0][0] << endl;
}
