#include <iostream>
#include <vector>
#include <unordered_set>
#include <limits>

using namespace std;

struct Path {
    vector<int> via;
    int totalWeight;
    Path(): totalWeight(numeric_limits<int>::max()) {}
};

int add(int a, int b) {
    if(a == numeric_limits<int>::max() || b == numeric_limits<int>::max())
        return numeric_limits<int>::max();
    else
        return a+b;
}

vector<Path> dijkstras(vector<vector<int> >& g, int source) {
    int n = g.size();
    vector<bool> selected(n, false);
    vector<Path> paths(n);

    int min = source;
    selected[min] = true;
    paths[source].totalWeight = 0;

    for(int i=1; i<n; i++) { // find shortest path to n-1 other vertices

        for(int j=0; j<n; j++) {
            if(!selected[j]) {
                int sum = add(g[min][j], paths[min].totalWeight);
                if(sum < paths[j].totalWeight) {
                    paths[j].totalWeight = sum;
                    paths[j].via = paths[min].via;
                    paths[j].via.push_back(min);
                }
            }
        }

        for(int j=0; j<n; j++) {
            if(!selected[j]) {
                min = j;
                break;
            }
        }
        for(int j=min+1; j<n; j++) {
            if(!selected[j]) {
                if(paths[j].totalWeight < paths[min].totalWeight)
                    min=j;
            }
        }

        selected[min] = true;

    }
    return paths;
}

int main() {
    vector<vector<int> > graph;
    int ele, n, source;
    
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

    cout<<"Enter the source vertex: "<<endl;
    cin>>source;
    vector<Path> paths = dijkstras(graph, source);

    cout<<endl<<"Source is: "<<source<<endl;
    for(int i=0; i<n; i++) {
        cout<<i<<": ";
        for(int j=0; j<paths[i].via.size(); j++) 
            cout<<paths[i].via[j]<<"->";
        cout<<i;

        cout<<", total distance: "<<paths[i].totalWeight;
        cout<<endl<<endl;
    }

}