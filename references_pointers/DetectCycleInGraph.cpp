#include<iostream>


using namespace std;

class Edge {
public:
	int u, v;
};

class Graph {
public:
	int V, E;
	Edge* ed;
	void CreateGraph(int V, int E) {
		//Graph* graph = new Graph();
		this->E = E;
		this->V = V;
		this->ed = new Edge[this->E * sizeof(Edge)];
		return; //graph;
	}

	//If the parent doesnt exist then return vertex if it exists go until the parents --> parent is found and return grand grand parent
	int find(int parent[], int vertex) {
		if (parent[vertex] == -1)
			return vertex;
		find(parent, parent[vertex]);
	}

	void Union(int parent[], int x, int y) {
		int a = find(parent, x);
		int b = find(parent, y);
		if (a != b) {
			parent[a] = b;
		}
		return;
	}


	bool isCycle(Graph* gp) {
		int* parent = new int[sizeof(int) * this->V];
		for (int i = 0; i < this->V; ++i) {
			parent[i] = -1;
		}
		for (int i= 0; i < this->E; i++) {
			int x = find(parent, gp->ed[i].u);
			int y = find(parent, gp->ed[i].v);

			if (x == y) {
				return true;
			}
			Union(parent, x, y);
		}
		return false;
	}
};


// Driver code 
int main()
{
	/* Let us create the following graph
		0
		| \
		| \
		1-----2 */
	int V = 3, E = 3;
	Graph* graph = new Graph();


	graph->CreateGraph(V, E);

	// add edge 0-1 
	graph->ed[0].u = 0;
	graph->ed[0].v = 1;

	// add edge 1-2 
	graph->ed[1].u = 1;
	graph->ed[1].v = 2;

	// add edge 0-2 
	graph->ed[2].u = 0;
	graph->ed[2].v = 2;

	if (graph->isCycle(graph))
		cout << "graph contains cycle";
	else
		cout << "graph doesn't contain cycle";

	return 0;
}
