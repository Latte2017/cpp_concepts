/*
Sort a 2d vector by 2nd column
*/

#include<vector>
#include<algorithm>
#include <iostream>
using namespace std;

/*
class Sorted {
private:
	bool SortByColumn(const vector<int>& v1, const vector<int>& v2) {
		return v1[1] > v2[1];
	}

	
public:
	Sorted operator () (vector<int> v1, vector<int>v2){
		
	}
	void ByColumn(vector<vector<int>>& input_vec){
		sort(input_vec.begin(), input_vec.end(), SortByColumn);
		return;
	}
};

*/

bool sortcol(const vector<int>& v1, const vector<int>& v2) {
	return v1[1] > v2[1];
}

int main() {
	vector<vector<int>> input_vec = {
		{1,2,3},
		{4,5,6},
		{2,3,4}
	};
	
	//Sorted s1;
	//s1.ByColumn(input_vec);
	sort(input_vec.begin(), input_vec.end(), sortcol);
	/*
	for (auto it = input_vec.begin(); it != input_vec.end(); ++it) {
		for (auto ix = (*it).begin(); ix != (*it).end(); ++ix) {
			cout << *ix << "\t";
		}
		cout << endl;
	}
	*/
}


