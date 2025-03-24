#include <stdio.h>

#define MAX_SEGMENTS 10

typedef struct {
    int base;
    int limit;
} SegmentTableEntry;

int main() {
    int numSegments, logicalAddr, segNum, offset, physicalAddr;
    SegmentTableEntry segmentTable[MAX_SEGMENTS];

    printf("Enter number of segments: ");
    scanf("%d", &numSegments);

    printf("Enter base address and limit for each segment:\n");
    for (int i = 0; i < numSegments; i++) {
        printf("Segment %d - Base Address: ", i);
        scanf("%d", &segmentTable[i].base);
        printf("Segment %d - Limit: ", i);
        scanf("%d", &segmentTable[i].limit);
    }

    // Taking Logical Address input
    printf("\nEnter logical address (segment number offset): ");
    scanf("%d %d", &segNum, &offset);

    // Check if the segment number is valid
    if (segNum >= numSegments) {
        printf("Invalid segment number!\n");
    } else if (offset >= segmentTable[segNum].limit) {
        printf("Offset exceeds segment limit!\n");
    } else {
        // Calculate Physical Address
        physicalAddr = segmentTable[segNum].base + offset;
        printf("Logical Address (Segment %d, Offset %d) -> Physical Address: %d\n", segNum, offset, physicalAddr);
    }

    return 0;
}
