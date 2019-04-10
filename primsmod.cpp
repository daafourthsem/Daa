#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

struct Edge {
    int weight;
    int from;
    Edge(): weight(numeric_limits<int>::max()) {} // infinity weight by default
};

void addMinimumEdge(vector<vector<int> >& g, Edge* edges, vector<int>& inMST) {
    int min, lastVertex, n;
    lastVertex = inMST.back(); // the new vertex from previous iteration
    n = g[lastVertex].size();
    
    for(int col=0; col<n; col++) {
        if(find(inMST.begin(), inMST.end(), col) != inMST.end())
            continue; // vertex already in the MST (skip this column)

        if(g[lastVertex][col] && g[lastVertex][col] < edges[col].weight) { 
            edges[col].weight = g[lastVertex][col]; // the weight is less than what we have
            edges[col].from = lastVertex; // so update it
        } 
    }
    for(int i=0; i<n; i++) {
        vector<int>::iterator it = find(inMST.begin(), inMST.end(), i);
        if(it == inMST.end()) {
            min = i; // find an element which is not in inMST, assume it is minimum
            break;
        }
    }
    for(int i=min+1; i<n; i++) {
        vector<int>::iterator it = find(inMST.begin(), inMST.end(), i);
        if(it == inMST.end())
            if(edges[i].weight < edges[min].weight)
                min = i; // find the minimum edge of them all
    }
    inMST.push_back(min); // add it to the MST and fix its position
}

Edge* prims(vector<vector<int> >& g) {
    int n = g.size(); // number of vertices
    Edge* edges = new Edge[n]; // representing n-1 edges

    vector<int> inMST; // vector to tell if a vertex is in the MST

    inMST.push_back(0); // first vertex in MST
    
    for(int i=1; i<n; i++) // repeat for n-1 vertices
        addMinimumEdge(g, edges, inMST);

    return edges;
}


int main() {
    int n, ele;
    vector<vector<int> > g;
    cout<<"Enter the number of vertices: "<<endl;
    cin>>n;
    cout<<"Enter the adjacency matrix:"<<endl;
    g.resize(n);
    for(int i=0; i<n; i++) {        
        g[i].resize(n);
        for(int j=0; j<n; j++) {
            cin>>ele;
            if(ele == -1)
                g[i][j] = numeric_limits<int>::max();
            else
                g[i][j] = ele;
        }
    }
    Edge *edges = prims(g);
    
    // edges[0] is dummy since we are starting from 0
    cout<<"Starting from vertex 0"<<endl;
    for(int i=1; i<n; i++)
        cout<<"Vertex "<<i<<" connected by "<<edges[i].from<<", weight "<<edges[i].weight<<endl;

    delete[] edges;
}

