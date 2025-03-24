#include <stdio.h>

#define MAX_PAGES 10
#define MAX_FRAMES 10

int main() {
    int pageTable[MAX_PAGES];  // Page Table storing frame numbers
    int numPages, pageSize, frameSize, logicalAddr, pageNum, offset, physicalAddr;

    printf("Enter number of pages: ");
    scanf("%d", &numPages);
    
    printf("Enter page size: ");
    scanf("%d", &pageSize);

    printf("Enter frame size: ");
    scanf("%d", &frameSize);

    printf("Enter the frame number for each page:\n");
    for (int i = 0; i < numPages; i++) {
        printf("Page %d -> Frame: ", i);
        scanf("%d", &pageTable[i]);
    }

    // Taking Logical Address as input
    printf("\nEnter logical address to translate: ");
    scanf("%d", &logicalAddr);

    // Calculating Page Number and Offset
    pageNum = logicalAddr / pageSize;
    offset = logicalAddr % pageSize;

    if (pageNum >= numPages) {
        printf("Invalid logical address! Page number out of range.\n");
    } else {
        // Getting corresponding frame and calculating physical address
        physicalAddr = (pageTable[pageNum] * frameSize) + offset;
        printf("Logical Address %d -> Physical Address %d\n", logicalAddr, physicalAddr);
    }

    return 0;
}
