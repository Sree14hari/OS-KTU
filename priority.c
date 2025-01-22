#include<stdio.h>
typedef struct process{
    int pid;
    int bt;
    int wt;
    int tt;
    int proirity;
    }process;

void calculate_wt(int n,process p[]){
    p[0].wt=0;
    for(int i=1;i<n;i++){
        p[i].wt=p[i-1].wt + p[i-1].bt;
    }
}

void calculate_tt(int n,process p[]){
    for(int i=0;i<n;i++){
        p[i].tt=p[i].wt + p[i].bt;
    }
}

void priority_scheduling(int n,process p[]){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].proirity>p[j].proirity){
                process temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    calculate_wt(n,p);
    calculate_tt(n,p);
    printf("process\tburst time\twaiting time\tturnaround time\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tt);
    }
    printf("average waiting time:");
    float avg_wt=0;
    for(int i=0;i<n;i++){
        avg_wt+=p[i].wt;
    }
    avg_wt/=n;
    printf("%f\n",avg_wt);
    printf("average turnaround time:");
    float avg_tt=0;
    for(int i=0;i<n;i++){
        avg_tt+=p[i].tt;
    }
    avg_tt/=n;
    printf("%f\n",avg_tt);

}

void main(){
    int n;
    printf("enter the number of processes:");
    scanf("%d",&n);
    process p[n];
    for(int i=0;i<n;i++){
        printf("enter the burst time of process %d:",i+1);
        scanf("%d",&p[i].bt);
        p[i].pid=i+1;
        printf("enter the priority of process %d:",i+1);
        scanf("%d",&p[i].proirity);
    }
    priority_scheduling(n,p);
    
}
