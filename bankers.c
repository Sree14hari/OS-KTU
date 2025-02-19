#include <stdio.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

int allocation[MAX_PROCESSES][MAX_RESOURCES];
int max[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int available[MAX_RESOURCES];
int safeSequence[MAX_PROCESSES];
int processCompleted[MAX_PROCESSES] = {0};

void calculateNeed() {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            need[i][j] = max[i][j] - allocation[i][j];

        }
    
}
printf("Computed Need Matrix:\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
    for (int j = 0; j < MAX_RESOURCES; j++) {
        printf("%d ", need[i][j]);
    }
    printf("\n");

}
}
int isSafeState() {
    int temp[MAX_RESOURCES];
    for (int i = 0; i < MAX_RESOURCES; i++)
        temp[i] = available[i];
    
    int flag = 0;
    while (flag < MAX_PROCESSES) {
        int found = 0;
        for (int i = 0; i < MAX_PROCESSES; i++) {
            if (!processCompleted[i]) {
                int canAllocate = 1;
                for (int j = 0; j < MAX_RESOURCES; j++) {
                    if (need[i][j] > temp[j]) {
                        canAllocate = 0;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int j = 0; j < MAX_RESOURCES; j++)
                        temp[j] += allocation[i][j];
                    safeSequence[flag++] = i;
                    processCompleted[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) return 0;
    }
    return 1;
}

void printSafeSequence() {
    printf("Safe sequence: ");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter allocation matrix:\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }
    
    printf("Enter max matrix:\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    
    printf("Enter available resources:\n");
    for (int i = 0; i < MAX_RESOURCES; i++) {
        scanf("%d", &available[i]);
    }
    printf("Allocation Matrix:\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            printf("%d ", allocation[i][j]);
    }
    printf("\n");
}

printf("Max Matrix:\n");
for (int i = 0; i < MAX_PROCESSES; i++) {
    for (int j = 0; j < MAX_RESOURCES; j++) {
        printf("%d ", max[i][j]);
    }
    printf("\n");
}

    calculateNeed();
    // printNeedMatrix();
    
    if (isSafeState()) {
        printSafeSequence();
    } else {
        printf("System is in an unsafe state. Deadlock may occur.\n");
    }
    return 0;
}
