#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

int allocation[MAX_PROCESSES][MAX_RESOURCES];
int max[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int available[MAX_RESOURCES];
int temp[MAX_RESOURCES];
bool finish[MAX_PROCESSES];
int safeSequence[MAX_PROCESSES];

void calculateNeed() {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

bool isSafeState() {
    for (int i = 0; i < MAX_RESOURCES; i++)
        temp[i] = available[i];
    
    for (int i = 0; i < MAX_PROCESSES; i++)
        finish[i] = false;
    
    int count = 0;
    while (count < MAX_PROCESSES) {
        bool found = false;
        for (int i = 0; i < MAX_PROCESSES; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < MAX_RESOURCES; j++)
                    if (need[i][j] > temp[j])
                        break;
                
                if (j == MAX_RESOURCES) {
                    for (int k = 0; k < MAX_RESOURCES; k++)
                        temp[k] += allocation[i][k];
                    
                    safeSequence[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found)
            return false;
    }
    return true;
}

void printSafeSequence() {
    printf("Safe sequence: ");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");
}

bool requestResources(int process, int request[]) {
    for (int i = 0; i < MAX_RESOURCES; i++) {
        if (request[i] > need[process][i] || request[i] > available[i])
            return false;
    }
    
    for (int i = 0; i < MAX_RESOURCES; i++) {
        available[i] -= request[i];
        allocation[process][i] += request[i];
        need[process][i] -= request[i];
    }
    
    if (isSafeState()) {
        return true;
    } else {
        for (int i = 0; i < MAX_RESOURCES; i++) {
            available[i] += request[i];
            allocation[process][i] -= request[i];
            need[process][i] += request[i];
        }
        return false;
    }
}

void deadlockDetection() {
    if (isSafeState()) {
        printf("No deadlock detected.\n");
    } else {
        printf("Deadlock detected!\n");
    }
}

int main() {
    printf("Enter allocation matrix:\n");
    for (int i = 0; i < MAX_PROCESSES; i++)
        for (int j = 0; j < MAX_RESOURCES; j++)
            scanf("%d", &allocation[i][j]);
    
    printf("Enter max matrix:\n");
    for (int i = 0; i < MAX_PROCESSES; i++)
        for (int j = 0; j < MAX_RESOURCES; j++)
            scanf("%d", &max[i][j]);
    
    printf("Enter available resources:\n");
    for (int i = 0; i < MAX_RESOURCES; i++)
        scanf("%d", &available[i]);
    
    calculateNeed();
    
    if (isSafeState()) {
        printf("System is in a safe state.\n");
        printSafeSequence();
    } else {
        printf("System is in an unsafe state. Deadlock may occur.\n");
    }
    
    int process, request[MAX_RESOURCES];
    printf("Enter process number for resource request (0-%d): ", MAX_PROCESSES - 1);
    scanf("%d", &process);
    printf("Enter resource request: ");
    for (int i = 0; i < MAX_RESOURCES; i++)
        scanf("%d", &request[i]);
    
    if (requestResources(process, request)) {
        printf("Request granted.\n");
        printSafeSequence();
    } else {
        printf("Request denied to avoid unsafe state.\n");
    }
    
    deadlockDetection();
    
    return 0;
}
