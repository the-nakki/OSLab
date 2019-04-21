#include<stdio.h>
void main(){
    int p,bt[100],wt[100],at[100],tat[100],i;
    float atat=0,awt=0;
    
    printf("enter number of processes\n");
    scanf("%d",&p);
    for(i=0;i<p;i++)
    {
        printf("p[%d]arrival time=",i+1);
        scanf("%d",&at[i]);
        printf("p[%d]burst time=",i+1);
        scanf("%d",&bt[i]);
    }
    
    wt[0]=0;
    int st=0;//service time
    for(i=1;i<p;i++)
    {
        st+=bt[i-1];
        wt[i]=st[i]-at[i];//wait time
        if (wt[i] < 0) 
            wt[i] = 0; 
    }

    printf("\nprocess no\tarrival time\tburst time\twait time\tturnaround time\n");
    for(i=0;i<p;i++)
    {
        tat[i]=wt[i]+bt[i];//turnaround time
        awt+=wt[i];
        atat+=tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\n",i+1,at[i],bt[i],wt[i],tat[i]);
    }

    awt/=i;
    atat/=i;
    printf("average wait time=%f\naverage turnaround time=%f\n",awt,atat);   
}