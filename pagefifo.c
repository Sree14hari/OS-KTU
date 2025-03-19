#include <stdio.h>

void fifoPageReplacement(int pages[], int n, int frames) {
    int frame[frames], front = 0, faults = 0;
    
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
    }
    
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
                break;
            }
        }
        
        if (flag == 0) {
            frame[front] = pages[i];
            front = (front + 1) % frames;
            faults++;
        }
        
        printf("\nFrame state after accessing page %d: ", pages[i]);
        for (int j = 0; j < frames; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
    }
    
    printf("\n\nTotal Page Faults: %d\n", faults);
}

int main() {
    int n, frames;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter page reference string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    
    fifoPageReplacement(pages, n, frames);
    
    return 0;
}
