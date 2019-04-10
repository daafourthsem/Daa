//  Queen.cpp

//  Created by Yashash H L on 05/04/19.

#include<iostream>
#include<vector>
using namespace std;

class Queen {
    vector<vector<int> > queen_set;
    int size;
    int count;
public:
    Queen(int a) {
        count=0;
        size=a;
        queen_set.resize(size);
        for(int i=0;i<a;i++)
            queen_set[i].resize(size);
        
    }
    void get_input();
    bool check(int,int);
    void print_board();
    bool nqueens(int);
    int get_count() {
        return count;
    }
};

void Queen::get_input() {
    int flag=0;
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++)
            queen_set[i][j]=0;
    }
    //for(int k=0;k<size;k++) {
    
    cout<<endl<<"The chess boards with queens placed(1 represent queens):"<<endl;
    flag=nqueens(0);
    if(flag==1) {
        print_board();
    }
      //  flag=0;
    //}
}

bool Queen::nqueens(int k) {
    bool ans;
    if(k>=size) {
        count++;
        print_board();
        return true; //if all column are filled return
    }
    for(int i=0;i<size;i++) {
        if(check(k,i)) { //empty place in the corresponding row
            queen_set[i][k]=1; //place the queen
            ans=nqueens(k+1) || false ;//pass the next column
            queen_set[i][k]=0; // if its not true remove the queen from that place
        }
    }
    return ans;
}

bool Queen::check(int a,int b) {
    int i,j;
    for(int i=0;i<size;i++) {
        if(queen_set[i][a]==1) //check for queen in the same row
            return false; //check for queen in the same column
        if(queen_set[b][i]==1)
            return false;
    }
    /*for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            if((i+j)==(a+b) || (i-j)==(a-b)) { //check for queen in the daigonals
                if(board[i][j]==1)
                    return false;
            }
        }
    }*/
    for (i=b, j=a; i>=0 && j>=0; i--, j--)
        if (queen_set[i][j])
            return false;
    
    /* Check lower diagonal on left side */
    for (i=b, j=a; j>=0 && i<size; i++, j--)
        if (queen_set[i][j])
            return false;

    return true;
}

void Queen::print_board() {
    cout<<endl;
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            cout<<queen_set[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int n;
    cout<<"Enter the size of the chess board: ";
    cin>>n;
    Queen q(n);
    q.get_input();
    cout<<endl<<"The total no of possibilities are: "<<q.get_count()<<endl;
    return 0;
}//

