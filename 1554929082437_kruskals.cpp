#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

// represents an edge (u, v) with weight weight
// undirected graph: (u, v) === (v, u)
struct Edge {
    int u; 
    int v;
    int weight;
    Edge(int x, int y, int z) : u(x), v(y), weight(z) {}
};

void addAllEdges(vector<vector<int> >& graph, vector<Edge>& allEdges) {
    int n=graph.size();
    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++) 
            if(i>j && graph[i][j] < numeric_limits<int>::max()) // upper traingular matrix elements
                allEdges.push_back(Edge(i, j, graph[i][j]));
}

vector<Edge> kruskals(vector<vector<int> >& graph) {
    vector<Edge> allEdges;
    vector<Edge> mstEdges;
    addAllEdges(graph, allEdges);
    // without overloading < in the struct, we can use lambda expressions to define the operation performed
    sort(allEdges.begin(), allEdges.end(), [](const Edge& e1, const Edge& e2) {
        return e1.weight < e2.weight;
    });

    vector<int> set;
    int count = 0; // to maintain trees
    set.resize(graph.size());
    for(count=0; count<set.size(); count++)
        set[count] = count; // each vertex belongs to its own set
    
    for(int i=0; i<allEdges.size(); i++) {
        if(set[allEdges[i].u] != set[allEdges[i].v]) {
            mstEdges.push_back(allEdges[i]);
            int tree1 = set[allEdges[i].u];
            int tree2 = set[allEdges[i].v];
            
            replace_if(set.begin(), set.end(), [tree1, tree2](int& t) { // capture tree1 and tree2 by copy
                return t == tree1 || t == tree2;
            }, count++);
        }
    }
    return mstEdges;
}

int main() {
    vector<vector<int> > graph;
    int ele, n;
    cout<<"Enter the number of vertices: "<<endl;
    cin>>n;
    cout<<"Enter the adjacency matrix: "<<endl;
    graph.resize(n);
    for(int i=0; i<n; i++) {
        graph[i].resize(n);
        for(int j=0; j<n; j++) {
            cin>>ele;
            if(ele == -1) 
                graph[i][j] = numeric_limits<int>::max();
            else
                graph[i][j] = ele;   
        }
    }

    vector<Edge> edges = kruskals(graph);
    for(int i=0; i<edges.size(); i++) 
        cout<<"Vertices "<<edges[i].u<<" and "<<edges[i].v<<" are "<<" connected with weight "<<edges[i].weight<<endl;
}


/*
 
 Enter the number of vertices:
 5
 Enter the adjacency matrix:
 0 3 2 1 -1
 3 0 4 1 5
 2 4 0 6 -1
 1 1 6 0 4
 -1 5 -1 4 0
 Vertices 3 and 0 are  connected with weight 1
 Vertices 3 and 1 are  connected with weight 1
 Vertices 2 and 0 are  connected with weight 2
 Vertices 4 and 3 are  connected with weight 4

*/
