#include <stdio.h>

void Optimal(int pages[], int n, int frames) {
    int frame[frames], pageFaults = 0;

    for (int i = 0; i < frames; i++) 
        frame[i] = -1; // Initialize frames as empty

    printf("\nPage Replacement Process:\n");
    for (int i = 0; i < n; i++) {
        int found = 0, replaceIndex = -1, farthest = -1;

        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) { // Page hit
                found = 1;
                break;
            }
        }

        if (!found) { // Page fault
            if (i < frames) { // Fill empty frames first
                frame[i] = pages[i];
            } else { // Find the optimal page to replace
                for (int j = 0; j < frames; j++) {
                    int nextUse = -1;
                    for (int k = i + 1; k < n; k++) {
                        if (frame[j] == pages[k]) {
                            nextUse = k;
                            break;
                        }
                    }
                    if (nextUse == -1) { // Page never used again
                        replaceIndex = j;
                        break;
                    }
                    if (nextUse > farthest) {
                        farthest = nextUse;
                        replaceIndex = j;
                    }
                }
                frame[replaceIndex] = pages[i];
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

    printf("\nTotal Page Faults (Optimal): %d\n", pageFaults);
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

    Optimal(pages, n, frames);
    return 0;
}
