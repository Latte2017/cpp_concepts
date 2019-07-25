#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

class Graph {
private:
	vector<int>* adj;
	int V; //number of vertices
	vector<int>ret_vt;
	stack<int> st;
	bool *visited;
public:
	Graph(int v) {
		this->V = v;
		adj = new vector<int>[V];
		
	}
	void addEdge(int u, int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void dfs(int v) {
		visited = new bool[V];
		for (int i = 0; i < V; i++) {
			visited[i] = false;
		}
		dfsUtil(v, visited);
		printRoute();

	}
	void printRoute() {
		vector<int>::iterator it;
		for (it = ret_vt.begin(); it != ret_vt.end(); ++it) {
			cout << *it << " -> ";
		}
		cout << "NULL " << endl;
	}
	void dfsUtil(int v, bool visited[]) {
		st.push(v);
		visited[v] = true;
		ret_vt.push_back(v);
		vector<int>::iterator it;
		for (it = adj[v].begin(); it != adj[v].end(); ++it) {
			if (!visited[*it]) {
				dfsUtil(*it, visited);
			}
		}
	}
};

int main() {
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.dfs(1);
}