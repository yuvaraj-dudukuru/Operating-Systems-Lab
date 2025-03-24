#include <stdio.h>

void FCFS(int pages[], int n, int frames) {
    int frame[frames], front = 0, count = 0, pageFaults = 0;

    for (int i = 0; i < frames; i++) 
        frame[i] = -1; // Initialize frames as empty

    printf("\nPage Replacement Process:\n");
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) { // Page hit
                found = 1;
                break;
            }
        }

        if (!found) { // Page fault
            frame[front] = pages[i];
            front = (front + 1) % frames;
            pageFaults++;
        }

        // Print current frame status
        printf("Step %d: ", i + 1);
        for (int k = 0; k < frames; k++) 
            if (frame[k] != -1) printf("%d ", frame[k]);
            else printf("- ");
        printf("\n");
    }

    printf("\nTotal Page Faults (FCFS): %d\n", pageFaults);
}

int main() {
    int n, frames;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter the page sequence: ");
    for (int i = 0; i < n; i++) 
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    FCFS(pages, n, frames);
    return 0;
}
