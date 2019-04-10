//
//  subset.cpp
//
//  Created by Yashash H L on 05/04/19.
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void display_set(vector<int>& temp) {
    cout<<endl<<"{ ";
    for(int i=0;i<temp.size();i++)
        cout<<" "<<temp[i];
    cout<<" }";
}

void subsetSum(vector<int>& gset,vector<int>& sset,int sc,int su,int pos,int req) {
    //sset.push_back(gset[pos]);
    if(sc == req) { //subset found
        display_set(sset);
        return;
    }
    if(pos==gset.size()) {
        //cout<<" hi ";
        //display_set(sset);
        return;
    }
    if((sc+su)>=req) {
         //left child
        if((sc+gset[pos]<=req)) {
            sset.push_back(gset[pos]);
            subsetSum(gset,sset,sc+gset[pos],su-gset[pos],pos+1,req);
            sset.pop_back();
        }
    //right child
        if(sc <= req) {
            subsetSum(gset,sset,sc,su-gset[pos],pos+1,req);
        }
    }
}

int main() {
    int n,a,sum=0,b;
    vector<int> pset;  // parent set
    vector<int> cset; // considered set
    cout<<"Enter the size of the set: ";
    cin>>n;
    cout<<endl<<"Enter the elements of the set: ";
    for(int i=0;i<n;i++) {
        cin>>a;
        sum=sum+a;
        pset.push_back(a);
    }
    cout<<endl<<"Enter the required sum : ";
    cin>>b;
    
    sort(pset.begin(),pset.end());
    subsetSum(pset,cset,0,sum,0,b);
    return 0;
}
