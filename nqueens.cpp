#include <iostream>
#include <vector>
using namespace std;
static int COUNT = 0;

struct Coor {
    int x;
    int y;
};

bool isPlaceable(vector<Coor>& coor, int row, int col) {
    for(vector<Coor>::iterator it = coor.begin(); it != coor.end(); it++) {
        if(it->x == row || it->y == col || (it->x+it->y)==(row+col) ||  (it->x-it->y) == (row-col))
            return false;
        // check if placed queens come same row, same col, primary and sec. diagonal of the queen 
        // being placed now, if yes, cant place it there
    }
    return true;
}

//kth row
void placeQueens(int n, int k, vector<Coor>& coor) {
    
    for(int i=0; i<n; i++) {
        if(isPlaceable(coor, k, i)) {
            coor.push_back({k, i}); // place the queen at k,i
            if(k == n-1) {
                // placed queens in all rows
                COUNT++;
                cout<<"placed as: "<<endl;
                for(vector<Coor>::iterator it = coor.begin(); it != coor.end(); it++)
                    cout<<"("<<it->x<<","<<it->y<<") ";  
                cout<<endl;     
            }
            else {
                placeQueens(n, k+1, coor);
            } 
            coor.pop_back(); // placing it at k,i didnt yield the result, so remove, try next
        }
    }
}

int main() {
    int n;
    cout<<"\nno. of queens to be placed: "<<endl;
    cin>>n;
    vector<Coor> coor;
    placeQueens(n, 0, coor);
    cout<<endl<<"Total count: "<<COUNT;
}