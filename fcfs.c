#include<stdio.h>
int main(){
    int n ,i;
    int bt[20],wt[20],tat[20];
    float avg_wt,avg_tat;
    printf("enter the number of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("enter the burst time of process %d:",i+1);
        scanf("%d",&bt[i]);
    }
    wt[0]=0;
    for(i=1;i<n;i++){
            wt[i]=wt[i-1]+bt[i-1];
    }
    for(i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
        avg_tat+=tat[i];
        avg_wt+=wt[i];
    }
    avg_tat/=n;
    avg_wt/=n;
    printf("process\tburst time\twaiting time\tturnaround time\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);
    }
    printf("average waiting time:%f\n",avg_wt);
    printf("average turnaround time:%f\n",avg_tat);
    return 0;
}