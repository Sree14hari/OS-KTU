#include <stdio.h> #include <stdlib.h>

// Function to calculate total head movement void fcfsDiskScheduling(int requests[], int n, int head) { int totalMovement = 0; printf("Sequence of movement: %d", head);

for (int i = 0; i < n; i++) {
    totalMovement += abs(requests[i] - head);
    head = requests[i];
    printf(" -> %d", head);
}

printf("\nTotal head movement: %d cylinders\n", totalMovement);

}

int main() { int n, head;

printf("Enter the number of disk requests: ");
scanf("%d", &n);

int requests[n];
printf("Enter the request queue: ");
for (int i = 0; i < n; i++) {
    scanf("%d", &requests[i]);
}

printf("Enter the initial head position: ");
scanf("%d", &head);

fcfsDiskScheduling(requests, n, head);

return 0;

}

