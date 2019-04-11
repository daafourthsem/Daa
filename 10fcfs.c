#include<stdio.h>

int main()
{
	int n,i;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	int bt[n],wt[n],tt[n];
	float avgwt = 0,avgtt = 0;
	printf("Enter the burst time of the processes : \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
	}
	wt[0] = 0; 
	for(i=0;i<n;i++)
	{
		if(i>0)
			wt[i] = bt[i-1]+wt[i-1];
		tt[i] = wt[i] + bt[i];
		avgwt += wt[i];
		avgtt += tt[i];
	}
	avgwt = avgwt/n;
	avgtt = avgtt/n;
	printf("\n\nProcess\t    Burst_time\t   Waiting_time\t    Turnaround_time\n");
	for(i=0;i<n;i++)
	{
		printf("%7d\t%11d\t%12d\t%16d\n",i,bt[i],wt[i],tt[i]);
	}
	printf("\nThe average waiting time of the processes are : %f\n",avgwt);
	printf("The average turn around time of the processes are : %f\n",avgtt);
	return 0;
}
