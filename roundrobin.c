#include <stdio.h>

typedef struct Process {
    int id;        
    int bt; 
    int remt; 
    int wt; 
    int tt; 
}process;

void roundRobin(process p[], int n, int timeQuantum) {
    int currentTime = 0;
    int completed = 0;

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].remt > 0) { 
                if (p[i].remt > timeQuantum) {
                    currentTime += timeQuantum;
                    p[i].remt -= timeQuantum;
                } else {
                    currentTime += p[i].remt;
                    p[i].wt = currentTime - p[i].bt;
                    p[i].tt = currentTime;
                    p[i].remt = 0;
                    completed++;
                }
            }
        }
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n",
               p[i].id,
               p[i].bt,
               p[i].wt,
               p[i].tt);
    }

    float totalwt = 0, totaltt = 0;
    for (int i = 0; i < n; i++) {
        totalwt += p[i].wt;
        totaltt += p[i].tt;
    }

    printf("\nAverage Waiting Time: %.2f\n", totalwt / n);
    printf("Average Turnaround Time: %.2f\n", totaltt / n);
}

int main() {
    int n, timeQuantum;
    printf("Enter the number of p: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &p[i].bt);
        p[i].remt = p[i].bt; 
    }

    printf("Enter time quantum: ");
    scanf("%d", &timeQuantum);

    roundRobin(p, n, timeQuantum);

    return 0;
}
