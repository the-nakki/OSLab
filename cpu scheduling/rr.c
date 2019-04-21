#include<stdio.h>

void main(){
	int at[20],bt[20],pid,n,rt[20],tq,proc_left;
	float wt=0,tat=0;
	
	printf("enter number of processes\n");
	scanf("%d",&n);
	proc_left=n;
	for (pid=0;pid<n;pid++)
	{
		printf("arrival and burst time for process %d: ",pid+1);
		scanf("%d%d",&at[pid],&bt[pid]);
		rt[pid]=bt[pid];
	}
	printf("enter time quantum\n");
	scanf("%d",&tq);
	
	printf("\nPID\tArrival time\tBurst time\tTurnaround time\t\tWait time\n");
	int time=0,flag=0;
	pid=0;
	
	while(proc_left)
	{
		if(rt[pid]<=tq&&rt[pid]>0)
		{
			time+=rt[pid];
			rt[pid]=0;
			flag=1;
		}
		else if(rt[pid]>0)
		{
			time+=tq;
			rt[pid]-=tq;
		}
		if(flag==1&&rt[pid]==0)
		{
			proc_left--;
			printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",pid+1,at[pid],bt[pid],time-at[pid],time-at[pid]-bt[pid]);
			wt+=time-at[pid]-bt[pid];
			tat+=time-at[pid];
			flag=0;
		}
		if(pid==n-1)
			pid=0;
		else if(at[pid+1]<=time)
			pid++;
		else
			pid=0;
	}

	printf("average waiting time:%f\naverage turnaround time=%f\n",wt/n,tat/n);
}
