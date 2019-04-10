#include<iostream>
#include<map>
#include<cstring>
using namespace std;
int horspool(const char *input,const char *search,int l,map<char,int>shift)
{
	int i=l-1,j=l-1,ts,prev;
	while(j<=strlen(input))
	{	
		prev=j;
		if(search[i]==input[j])
		{
			i--;
			j--;
			if(i<0)
			return 1;
		}
		else if(search[i]!=input[j])
		{
			ts=shift.find(input[prev])->second;
			j=j+ts;
			i=l-1;
		}
	}
	return 0;
}
int horspoolcount(const char *input,const char *search,int l,map<char,int>shift)
{
	int i=l-1,j=l-1,ts,prev,count=0;
	while(j<=strlen(input))
	{	
		cout<<"**";
		prev=j;
		if(search[i]==input[j])
		{
			i--;
			j--;
			if(i<0)
			{
				j=j+(2*l);
				count++;
				if(j>=strlen(input))
					break;
				i=l-1;
			}
		}
		else if(search[i]!=input[j])
		{
			ts=shift.find(input[prev])->second;
			j=j+ts;
			i=l-1;
		}
	}
	return count;
}
int main()
{
	map<char,int>distance;
	char input[256],search[256];
	map<char,int>::iterator k;
	int l,i,m=1,match,noc=0;
	cout<<"Enter input string : ";
	cin>>input;
	cout<<"Enter search string : ";
	cin>>search;
	l=strlen(search);
	for(i=97;i<=122;i++)
		distance.insert(pair<char,int>((char)i,l));
	for(i=l-2;i>=0;i--)
	{
		if(distance.find(search[i])->second<l)
			{}
		else
			distance.find(search[i])->second=m;
		m++;
	}
	match=horspool(input,search,l,distance);
	noc=horspoolcount(input,search,l,distance);
	if(match==1)
		cout<<"\nMatch has been found "<<noc<<" times\n";
	else
		cout<<"\nMatch is not found\n";
}
