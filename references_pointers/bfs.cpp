#include<iostream>
#include<queue>
#include<vector>
#include<stack>

using namespace std;


class Graph
{
private:
	int V;    // No. of vertices 
	// Pointer to an array containing adjacency. Single matrix for the whole graph 
	int adj[16] = {0};
	
	vector<int> ret_vt;
	// prints traversal from a given source s 
	void printtraversal(vector<int>* s) {
		for (int i = 0; i < s->size(); i++) {
			cout << s->at(i) << endl;
		}
		return;
	}
public:
	Graph(int v) {
		V = v;
	}

	void addEdge(int v, int u) {
		adj[u + (V * v)] = 1;
		adj[v + (V * u)] = 1;
	}


	void BFS(int node) {
		queue<int> qu;
		
		bool* visited = new bool(V);
		for (int i = 0; i < V; i++)
			visited[i] = false;
		qu.push(node);
		while (!qu.empty()) {
			int node = qu.front();
			if (!visited[node]) {
				ret_vt.push_back(node);
				visited[node] = true;
				for (int i = 0; i < V; i++) {
					if (adj[(node * V) + i] == 1 && visited[i] == false) {
						qu.push(i);
					}
				}
			}
			qu.pop();
		}
		//printtraversal(&ret_vt);
		//delete visited;
		return;
	}

	void DFS(int node) {
		stack<int> st;
		int col;
		bool* visited = new bool(V);
		for (int i = 0; i < V; i++)
			visited[i] = false;
		st.push(node);
		ret_vt.push_back(node);
		while (!st.empty()) {
			col = 0;
			while (true) {
				if (adj[V * node + col] == 1 and visited[col] == false) {
					st.push(col);
					ret_vt.push_back(col);
					visited[node] = true;
					break;
				}
				else if (adj[V * node + col] == 1 and visited[col] == true)
					st.pop();
				col++;
			}
		}
		printtraversal(&ret_vt);
		return;
	}

	
};


int main() {
	Graph g(8);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(1, 2);
	g.addEdge(1, 7);
	g.addEdge(1, 5);
	g.addEdge(3,4);
	g.addEdge(3,5);
	g.addEdge(4,5);
	g.BFS(0);
	//g.DFS(0);
	return 0;
}

