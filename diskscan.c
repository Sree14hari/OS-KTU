#include <stdio.h> #include <stdlib.h>

// Function to perform SCAN disk scheduling void scanDiskScheduling(int requests[], int n, int head, int direction, int disk_size) { int totalMovement = 0; int sorted[n + 2], index = 0;

// Adding the head position
sorted[index++] = head;

// Adding all requests
for (int i = 0; i < n; i++) {
    sorted[index++] = requests[i];
}

// Adding boundary based on direction
if (direction == 1) {
    sorted[index++] = disk_size - 1;
} else {
    sorted[index++] = 0;
}

// Sorting the requests
for (int i = 0; i < index - 1; i++) {
    for (int j = 0; j < index - i - 1; j++) {
        if (sorted[j] > sorted[j + 1]) {
            int temp = sorted[j];
            sorted[j] = sorted[j + 1];
            sorted[j + 1] = temp;
        }
    }
}

// Finding the position of the head in sorted array
int pos;
for (int i = 0; i < index; i++) {
    if (sorted[i] == head) {
        pos = i;
        break;
    }
}

printf("Sequence of movement: %d", head);

// Moving towards higher cylinder numbers
if (direction == 1) {
    for (int i = pos; i < index; i++) {
        totalMovement += abs(sorted[i] - head);
        head = sorted[i];
        printf(" -> %d", head);
    }
    for (int i = pos - 1; i >= 0; i--) {
        totalMovement += abs(sorted[i] - head);
        head = sorted[i];
        printf(" -> %d", head);
    }
}
// Moving towards lower cylinder numbers
else {
    for (int i = pos; i >= 0; i--) {
        totalMovement += abs(sorted[i] - head);
        head = sorted[i];
        printf(" -> %d", head);
    }
    for (int i = pos + 1; i < index; i++) {
        totalMovement += abs(sorted[i] - head);
        head = sorted[i];
        printf(" -> %d", head);
    }
}

printf("\nTotal head movement: %d cylinders\n", totalMovement);

}

int main() { int n, head, direction, disk_size;

printf("Enter the number of disk requests: ");
scanf("%d", &n);

int requests[n];
printf("Enter the request queue: ");
for (int i = 0; i < n; i++) {
    scanf("%d", &requests[i]);
}

printf("Enter the initial head position: ");
scanf("%d", &head);

printf("Enter the disk size: ");
scanf("%d", &disk_size);

printf("Enter the direction (1 for high, 0 for low): ");
scanf("%d", &direction);

scanDiskScheduling(requests, n, head, direction, disk_size);

return 0;

}

