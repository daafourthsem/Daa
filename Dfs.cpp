#include<iostream>

using namespace std;
void dfs(int **a,int *v,int r,int c,int n,int *count)
{
	int i,j;
	if(v[c]==1)
		return;
	v[r]=1;
	v[c]=1;
	if(v[r]==1)
	{
		if(count[r]==0)
		{
			cout<<r<<" ";
			count[r]=1;
		}
	}
	if(v[c]==1)
	{
		if(count[c]==0)
		{
			cout<<c<<" ";
			count[c]=1;
		}
	}
	for(i=c;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(v[j]==0 && a[i][j]==1)
			{	
				dfs(a,v,i,j,n,count);
			}
		}
	}	
}
int main()
{
	int n,r,c,v[10],*a[10],count[10],sv;
	cout<<"Enter size : ";
	cin>>n;
	for(r=0;r<n;r++)
		a[r]=new int[n];
	for(r=0;r<n;r++)
			v[r]=0;
	for(r=0;r<n;r++)
			count[r]=0;
	cout<<"Enter the adjacency matrix : ";
	for(r=0;r<n;r++)
		for(c=0;c<n;c++)
			cin>>a[r][c];
	cout<<"Enter the starting vertex : ";
	cin>>sv;
	for(r=sv;r<n;r++)
		for(c=0;c<n;c++)
		{
			if(v[r]==0 && a[r][c]==1)
				dfs(a,v,r,c,n,count);
		}
	for(r=0;r<n;r++)
	{
		if(count[r]==0)
			cout<<r<<" ";
	}
}
