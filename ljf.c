#include<stdio.h>

void main(){

	int n,i,j,k=1,temp,at[20],bt[20],p[20],max,wt[20],tt[20],sum,wsum,ta,tsum,btime;
	float wavg,tavg;

	printf("enter number of processes\n");
	scanf("%d",&n);
	printf("enter arrival time and burst time of each process\n");
	for(i=0;i<n;i++)
		scanf("%d%d",&at[i],&bt[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(at[i]<at[j])
			{
				temp=p[j];
				p[j]=p[i];
				p[i]=temp;
				temp=at[j];
				at[j]=at[i];
				at[i]=temp;
				temp=bt[j];
				bt[j]=bt[i];
				bt[i]=temp;
			}
		}
	}

	for(j=0;j<n;j++)
	{
		btime+=bt[j];
		max=bt[k];
		for(i=k;i<n;i++)
		{
			if (btime>=at[i] && bt[i]>max)
			{
				temp=p[k];
				p[k]=p[i];
				p[i]=temp;
				temp=at[k];
				at[k]=at[i];
				at[i]=temp;
				temp=bt[k];
				bt[k]=bt[i];
				bt[i]=temp;
			}
		}
		k++;
	}

	wt[0]=0;
	for(i=1;i<n;i++)
	{
		sum+=bt[i-1];
		wt[i]=sum-at[i];
		wsum+=wt[i];
	}
	 
	for(i=0;i<n;i++)
	{
		ta+=bt[i];
		tt[i]=ta-at[i];
		tsum=tsum+tt[i];
	
	}
	wavg=(wsum/n);
	tavg=(tsum/n);

	printf("process no\tarrival time\tburst time\twait time\tturnaround time\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],at[i],bt[i],wt[i],tt[i]);
	}
	printf("average wait time:%f\n",wavg);
	printf("average turnaround time:%f\n",tavg);
}