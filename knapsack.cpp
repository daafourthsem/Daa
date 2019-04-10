#include<iostream>
using namespace std;
int max(int,int);
int main()
{
	int n,i,j,m,c;
	cout<<"Enter the number of items:";
	cin>>n;
	cout<<"\nEnter the maximum capacity of knapsack:";
	cin>>c;
	int v[n+1],w[n+1];
	cout<<"\nEnter the weights of items:";
	for(i=1;i<=n;i++)
		cin>>w[i];
	cout<<"\nEnter the value of items:";
	for(i=1;i<=n;i++)
		cin>>v[i];
	int a[n+1][c+1];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=c;j++)
		{
			if(i==0 || j==0)
				a[i][j]=0;
			else
				a[i][j]=-1;			
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=c;j++)
		{
			if(w[i]>j)
				a[i][j]=a[i-1][j];
			else
				a[i][j]=max(a[i-1][j],a[i-1][j-w[i]]+v[i]);
		}
	}
	cout<<"\nMaximum profit="<<a[n][c];
	return 0;
}
	
		
int max(int a,int b)
{
	return a>b?a:b;
}
