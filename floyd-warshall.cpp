#include<iostream>
#include<algorithm>
using namespace std;

void floyds(int a[10][10],int n);

void warshall(int a[10][10],int n);

int main()
{
	int a[10][10],n,ch;
	
	cout<<"\nEnter your choice:\n\t1.Floyds's\n\t2.Warshall's"<<endl;
		cin>>ch;
		
	cout<<"\nEnter the size of matrix:\t";
	cin>>n;
	
	cout<<"\nEnter the matrix values:\t";
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	
	
	if(ch==1)
		floyds(a,n);
	else if(ch==2)
		warshall(a,n);
	else 
		cout<<"\nInvalid input, Try again."<<endl;
		
	return 0;
}

void floyds(int a[10][10],int n)
{
	int i,j,k;
	int d[n][n];
	
	for(i=0;i<n;i++)
		for(int j=0;j<n;j++)
			d[i][j]=a[i][j];
		
	for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		
		}
		
	cout<<"\nAfter applying floyds algorithm, Resulting distance matrix is:\n";

	for(i=0;i<n;i++)
		{
		for(int j=0;j<n;j++)
			cout<<d[i][j]<<" ";
		cout<<endl;
		}
		
}


void warshall(int a[10][10],int n)
{
	int i,j,k;
	int d[n][n];
	
	for(i=0;i<n;i++)
		for(int j=0;j<n;j++)
			d[i][j]=a[i][j];
		
	for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					d[i][j]=d[i][j]||(d[i][k]&&d[k][j]);
		
		}
		
	cout<<"\nAfter applying warshall algorithm:\n";

	for(i=0;i<n;i++)
		{
		for(int j=0;j<n;j++)
			cout<<d[i][j]<<" ";
		cout<<endl;
		}
		
}

/*
 Floyd's:
 Enter your choice:
 1.Floyds's
 2.Warshall's
 1
 
 Enter the size of matrix:    4
 
 Enter the matrix values:
 0 999 3 999
 2 0 999 999
 999 9 0 1
 6 999 999 0
 
 After applying floyds algorithm, Resulting distance matrix is:
 0 12 3 4
 2 0 5 6
 7 9 0 1
 6 18 9 0
*/

/*
 Warshall's:
 Enter your choice:
 1.Floyds's
 2.Warshall's
 2
 
 Enter the size of matrix:    4
 
 Enter the matrix values:
 0 1 0 1
 0 0 0 1
 0 0 0 0
 1 1 1 1
 
 After applying warshall algorithm:
 1 1 1 1
 1 1 1 1
 0 0 0 0
 1 1 1 1
*/
