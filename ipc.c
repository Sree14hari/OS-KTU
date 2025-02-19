//sender
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024 // Size of the shared memory segment

int main() {
    key_t key = ftok("shmfile", 65); // Generate a unique key
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Create the shared memory segment
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the process's address space
    char *data = (char *)shmat(shmid, NULL, 0);
    if (data == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // Write data to the shared memory
    printf("Enter a message to write to shared memory: ");
    fgets(data, SHM_SIZE, stdin);
    printf("Data written to shared memory: %s\n", data);

    // Detach the shared memory segment
    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}

//reciver 

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024 // Size of the shared memory segment

int main() {
    key_t key = ftok("shmfile", 65); // Generate the same key as the writer
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Get the shared memory segment
    int shmid = shmget(key, SHM_SIZE, 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the process's address space
    char *data = (char *)shmat(shmid, NULL, 0);
    if (data == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // Read data from the shared memory
    printf("Data read from shared memory: %s\n", data);

    // Detach the shared memory segment
    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Delete the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}