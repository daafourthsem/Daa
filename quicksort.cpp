#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;
void quick(int a[], int si,int ei)
{
	int n=ei-si+1,i=si+1,j=ei,temp=0;
	if(n>1)
	{
		while(j>i && i<=ei)
		{
			while(a[i]<a[si])
			{
				i++;
				if(i>ei)
					break;
			}
			if(i>j)
				break;
			while(a[j]>a[si])
			{
				if(j<i)
					break;
				j--;
			}
			if(j<i||j==si)
				break;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		if(j!=si)
		{
			temp=a[si];
			a[si]=a[j];
			a[j]=temp;
		}
		quick(a,si,j-1);
		quick(a,j+1,ei);
	}
}
int cquick(int a[], int si,int ei)
{
	int n=ei-si+1,i=si+1,j=ei,temp=0,c=0,x,y;
	if(n>1)
	{
		while(j>i && i<=ei)
		{
			while(a[i]<a[si])
			{
				i++;
				c++;
				if(a[i]>a[si])
					c++;
				if(i>ei)
					break;
			}
			if(i>j)
				break;
			while(a[j]>a[si])
			{
				if(j<i)
					break;
				c++;
				if(a[j]<a[si])
					c++;
				j--;
			}
			if(j<i||j==si)
				break;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		if(j!=si)
		{
			temp=a[si];
			a[si]=a[j];
			a[j]=temp;
		}
		x=cquick(a,si,j-1);
		y=cquick(a,j+1,ei);
		return (x+y+c);
	}
}
int main()
{
	int n,c,choice,c1,c2,c3,no;
	int a[100];
	while(1)
	{
	
		cout<<"1.Quicksort\n2.Complexity\n3.Exit\nEnter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter number of elements : ";
				cin>>n;	
				cout<<"Enter elements : ";
				for(int i=0;i<n;i++)
				{
					cin>>a[i];
				}
				quick(a,0,n-1);
				cout<<"Array is : ";
				for(int i=0;i<n;i++)
				{
					cout<<a[i]<<" ";
				}
				cout<<"\n";
			break;
			case 2:	
				cout<<"\nNumber of comparisons = "<<"\n";
				for(no=8;no<=128;no=no*2)
				{
					for(int i=0;i<no;i++)
					{
						a[i]=i;
					}
					c1=cquick(a,0,no-1);
					for(int i=0;i<n;i++)
					{
						a[i]=no-i;
					}
					c2=cquick(a,0,no-1);
					for(int i=0;i<no;i++)
					{
						a[i]=(int)rand()%1000;
					}
					c3=cquick(a,0,no-1);
					cout<<c1<<setw(8)<<c2<<setw(8)<<c3;
					cout<<"\n";
				}
			break;
			case 3: 
				return 0;
		}
	}
}
