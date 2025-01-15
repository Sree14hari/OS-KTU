#include<stdio.h>
int i,j;
typedef struct process{
    int bt;
    int wt;
    int tt;
}process;
void sort_bt(process pro[],int n){
    for( i=0;i<n-1;i++){
        for( j=0;j<n-i-1;j++){
            if(pro[j].bt>pro[j+1].bt){
                process temp=pro[j];
                pro[j]=pro[j+1];
                pro[j+1]=temp;
            }
        }
    }
}
void calculate(process pro[],int n){
    pro[0].wt=0;
    for( i=1;i<n;i++){
        pro[i].wt=pro[i-1].wt+pro[i-1].bt;
    }
    for(i=0;i<n;i++){
        pro[i].tt=pro[i].wt+pro[i].bt;
    }
}
void print(process pro[],int n){
    printf("process\tburst time\twaiting time\tturnaround time\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\n",i+1,pro[i].bt,pro[i].wt,pro[i].tt);
    }
}
int main(){
    int n;
    printf("enter the number of processes:");
    scanf("%d",&n);
    process pro[n];
    for( i=0;i<n;i++){
        printf("enter the burst time of process %d:",i+1);
        scanf("%d",&pro[i].bt);
    }
    sort_bt(pro,n);
    calculate(pro,n);
    print(pro,n);
    float avg_wt=0,avg_tt=0;
    for(i=0;i<n;i++){
        avg_wt+=pro[i].wt;
        avg_tt+=pro[i].tt;
    }
    avg_wt/=n;
    avg_tt/=n;
    printf("average waiting time:%f\n",avg_wt);
    printf("average turnaround time:%f\n",avg_tt);
    return 0;
}