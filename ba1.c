 #include <stdio.h>

int max[100][100],alloc[100][100],need[100][100],available[100],req[100];


void checksafe(int n,int m){
    int i=0,j,count=0;
    int seq[n];
    int work[m],finished[n];
    for(i=0;i<n;i++){
        finished[i] = 0;   
    }
    for(i=0;i<m;i++){
        work[i] = available[i];
    }

    while(count<n){
        int given=0;
        for(i=0;i<n;i++){
            if(finished[i]==0){
                for(j=0;j<m;j++){
                    if(work[j] < need[i][j])
                        break;
            }

            if(j==m){
                for(j=0;j<m;j++){
                    work[j] = work[j] + alloc[i][j];           
                }
                finished[i] ==1;
                count++ ;
                given = 1;
        }

        }
    }

    if(given ==0){
        printf("system is not safe\n");
        return;
    }

   
    }
    printf("system is safe\n");


}

int main(){
    int n,m,i,j,proc;
    printf("enter number of process and resources\n");
    scanf("%d %d",&n,&m);
    printf("enter the available resources\n");
    for(i=0;i<m;i++)
        scanf("%d",&available[i]);

   
   
    printf("enter the allocated matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);
    }

    printf("enter the max matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&max[i][j]);
    }
    printf("the need matrix is\n");

    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<m;j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%2d",need[i][j]);
        }
    }
    printf("\n");

    checksafe(n,m);

   
    printf("process number\n" );
        scanf("%d",&proc);
    printf("enter the requested resources\n");
    for(i=0;i<m;i++)
        scanf("%d",&req[i]);
   
    for(i=0;i<m;i++)
    {
        if(req[i] > need[proc][i] || req[i] > available[i])
        {
            printf("cannot be executed\n");
            break;
        }
    }
    if(i==m)
    {
        for(i=0;i<m;i++)
        {
            available[i] = available[i] - req[i];
            need[proc][i] = need[proc][i] - req[i];
            alloc[proc][i] = alloc[proc][i] + req[i];
        }
        checksafe(n,m);

    }   

}

