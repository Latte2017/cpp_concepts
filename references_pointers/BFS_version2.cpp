#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Graph {
private:
	int V; //number of vertices
	vector<int>* adj;
	bool* visited;
	vector<int> ret_vt;
	queue<int> qu;
public:
	Graph(int NumOfNodes) {
		this->V = NumOfNodes;
		adj = new vector<int>[V];
	}

	void addEge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void printRoute() {
		vector<int>::iterator it;
		for (it = ret_vt.begin(); it != ret_vt.end(); ++it) {
			cout << *it << " -> ";
		}
		cout << "NULL " << endl;
	}

	void BFS(int node) {
		visited = new bool[V];
		for (int i = 0; i < V; i++) {
			visited[i] = false;
		}
		BfsUtil(node, visited);
		printRoute();
	}

	void BfsUtil(int node, bool visited[]) {
		qu.push(node);
		while (!qu.empty()) {
			vector<int>::iterator it;
			node = qu.front();
			for (it = adj[node].begin(); it != adj[node].end(); ++it) {
				if(visited[*it] == false)
					qu.push(*it);
			}
			visited[node] = true;
			ret_vt.push_back(node);
			qu.pop();
		}
		return;
	}
};


int main() {
	Graph g(6);
	g.addEge(0, 1);
	g.addEge(0,5);
	g.addEge(5,2);
	g.addEge(1,4);
	g.addEge(4,3);
	g.BFS(0);
	return 0;
}