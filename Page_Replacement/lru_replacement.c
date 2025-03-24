#include <stdio.h>

void LRU(int pages[], int n, int frames) {
    int frame[frames], recent[frames], pageFaults = 0;
    
    for (int i = 0; i < frames; i++) 
        frame[i] = -1; // Initialize frames as empty

    printf("\nPage Replacement Process:\n");
    for (int i = 0; i < n; i++) {
        int found = 0, lruIndex = 0;

        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) { // Page hit
                found = 1;
                recent[j] = i;
                break;
            }
        }

        if (!found) { // Page fault
            if (i < frames) { // Fill empty frames first
                frame[i] = pages[i];
                recent[i] = i;
            } else { // Replace least recently used page
                int min = recent[0];
                for (int j = 1; j < frames; j++) {
                    if (recent[j] < min) {
                        min = recent[j];
                        lruIndex = j;
                    }
                }
                frame[lruIndex] = pages[i];
                recent[lruIndex] = i;
            }
            pageFaults++;
        }

        // Print current frame status
        printf("Step %d: ", i + 1);
        for (int k = 0; k < frames; k++) 
            if (frame[k] != -1) printf("%d ", frame[k]);
            else printf("- ");
        printf("\n");
    }

    printf("\nTotal Page Faults (LRU): %d\n", pageFaults);
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

    LRU(pages, n, frames);
    return 0;
}
