#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display(vector<int>& v) {
    cout<<endl<<"subset: ";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
}
void subsetsIf(vector<int>& arr, vector<int>& con, int pos, int su, int sc, int d) {
    if(sc == d) {
        display(con);
        return;
    }
    if(pos == arr.size()) 
        return;
    if(su + sc >= d) {
        if(sc + arr[pos] <= d) {
            con.push_back(arr[pos]);
            subsetsIf(arr, con, pos+1, su-arr[pos], sc+arr[pos], d);
            con.pop_back(); // simulate a backtrack to its parent, next check right
        }
        if(sc <= d) {
            subsetsIf(arr, con, pos+1, su-arr[pos], sc, d);
        }
    }    
} 
int main() {
    int n, ele, d, su=0;
    vector<int> arr, con;
    cout<<"n -> ";
    cin>>n;
    cout<<"enter the elements: ";
    for(int i=0; i<n; i++) {
        cin>>ele;
        arr.push_back(ele);
        su+=ele;
    }
    cout<<"enter the subset sum: ";
    cin>>d;

    subsetsIf(arr, con, 0, su, 0, d);

}