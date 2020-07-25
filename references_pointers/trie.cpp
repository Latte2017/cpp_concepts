/*

Sample questions

 Q) Given an a list of words search for list of words 

tree, ant, elephant, crocodile, crocochoclate search for ele, croco

*/


#include<iostream>
#include<map>
#include<vector>
#include <queue>
#include <set>
#include <string>
using namespace std;

class TrieNode {
public:
	char ch;
	map<char, TrieNode*> children;
	bool is_leaf = false;
	TrieNode(char ch = NULL) {
		this->ch = ch;
	}
};

class Trie {
private:
	TrieNode *pre = nullptr;
public:
	TrieNode* CreateTrieNode(char ch = NULL) {
		TrieNode* t1 = new TrieNode(ch);
		return t1;
	}

	void Insert(TrieNode* head, string s1) {
		TrieNode* curr = head;

		for (auto it = s1.begin(); it != s1.end(); ++it) {
			if (curr->children.find(*it) == curr->children.end()) {
				TrieNode *tmp = new TrieNode(*it);
				curr->children[*it] = tmp;
			}
			curr = curr->children[*it];
		}
		curr->is_leaf = true;
	}


	vector<string> SearchPrefix(TrieNode* root, string sub_string) {
		vector<string> ret_vec;
		bool search_val = Search(root, sub_string, true);
		if (search_val) {
			//do bfs and get all remaining parts
			deque<pair<TrieNode*, string>> que;
			que.push_back(make_pair(pre, ""));
			set<TrieNode*> visited;
			while (!que.empty()) {
				pair<TrieNode*, string> curr = que.front();
				que.pop_front();
				visited.insert(curr.first);
				for (auto child = (curr.first)->children.begin(); child != (curr.first)->children.end(); ++child) {
					if (visited.find((*child).second) == visited.end()) {
						
						que.push_back(make_pair((*child).second, curr.second + (*child).second->ch));
					}
				}

				if ((curr.first)->is_leaf) {  //think about 2 words such as "as" and "ass" we should both the sub words
					ret_vec.push_back(sub_string + curr.second);
				}
			}
			return ret_vec;
		}


		return ret_vec;
	}


	bool Search(TrieNode* head, string s1, bool is_substring=false) {

		if (head == nullptr) {
			return "";
		}

		TrieNode* curr = head;

		for (auto it = s1.begin(); it != s1.end(); ++it) {
			if (curr->children.find(*it) == curr->children.end()) {
				return false;
			}
			curr = curr->children[*it];
		}
		if (curr->is_leaf == true) {
			return true;
		}
		else if (is_substring == true) {
			pre = curr;
			return true;
		}
		return false;
	}
};

int main() {
	//tree, ant, elephant, crocodile, crocochoclate search for ele, croco
	Trie* t1 = new Trie();
	TrieNode* head = t1->CreateTrieNode();
	//t1->Insert(head, "tree");
	//t1->Insert(head, "ant");
	//t1->Insert(head, "elephant");
	t1->Insert(head, "abkjl");
	t1->Insert(head, "abcde");
	TrieNode *curr = head;
	

	bool val = t1->Search(head, "abkjl");
	//Search for prefix 
	// search for croco should return crocodile crocochoclate
	vector<string> ret_str = t1->SearchPrefix(head, "ab");
	//Search for rank number of occourances of a word
}