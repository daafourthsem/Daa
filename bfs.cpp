#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {

    void visit(int index);
    vector<int> visited;

public:    
    Graph(int n): v(n) {
        visited.resize(v);
        matrix.resize(v);
        cout<<"Enter the adjacency matrix: "<<endl;
        for(int i=0; i<v; i++) {
            matrix[i].resize(v);
            visited[i] = 0;
            for(int j=0; j<v; j++)
                cin>>matrix[i][j];
        }
    }
    vector<vector<int> > matrix;
    vector<int> bfsOrder;
    int v;
    void order() {
        cout<<"BFS Order: "<<endl;
        for(vector<int>::iterator it = bfsOrder.begin(); it != bfsOrder.end(); it++)
            cout<<*it<<" ";
        cout<<endl;
    }
    void bfs();
};


void Graph::bfs() {
    for(int i=0; i<v; i++)
        if(visited[i] == 0)
            visit(i);
}

void Graph::visit(int index) {
    visited[index] = 1;
    queue<int> bfsQueue;
    bfsQueue.push(index);
    int rowIndex = index;

    while(!bfsQueue.empty()) {
        rowIndex = bfsQueue.front();
        for(int i=0; i<v; i++) {
            if(matrix[rowIndex][i] == 1 && visited[i] == 0) {
                bfsQueue.push(i);
                visited[i] = 1;
            }
        }
        bfsOrder.push_back(bfsQueue.front());
        bfsQueue.pop();
    }    
}

int main() {
    int n;
    cout<<"Enter the number of vertices: "<<endl;
    cin>>n;
    Graph graph(n);
    graph.bfs();
    graph.order();
}
