#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int main() {
    int n, m, i, j, k;
    int alloc[MAX_PROCESSES][MAX_RESOURCES], max[MAX_PROCESSES][MAX_RESOURCES], need[MAX_PROCESSES][MAX_RESOURCES];
    int avail[MAX_RESOURCES], work[MAX_RESOURCES], finish[MAX_PROCESSES];
    int safeSequence[MAX_PROCESSES], index = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    
    printf("Enter allocation matrix (%d x %d):\n", n, m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    
    printf("Enter maximum demand matrix (%d x %d):\n", n, m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    
    printf("Enter available resources (%d):\n", m);
    for (i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    // Calculate the need matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Initialize Work and Finish arrays
    for (i = 0; i < m; i++)
        work[i] = avail[i];

    for (i = 0; i < n; i++)
        finish[i] = 0;

    // Check for a safe sequence
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (!finish[i]) {
                int flag = 1;
                for (j = 0; j < m; j++)
                    if (need[i][j] > work[j]) {
                        flag = 0;
                        break;
                    }

                if (flag) {
                    safeSequence[index++] = i;
                    for (j = 0; j < m; j++)
                        work[j] += alloc[i][j];

                    finish[i] = 1;
                }
            }
        }
    }

    // Check if all processes are finished
    int isSafe = 1;
    for (i = 0; i < n; i++) {
        if (!finish[i]) {
            isSafe = 0;
            break;
        }
    }

    if (isSafe) {
        printf("System is in a safe state.\nSafe sequence: ");
        for (i = 0; i < n; i++)
            printf("P%d ", safeSequence[i]);
        printf("\n");
    } else {
        printf("System is in an unsafe state! Deadlock detected.\n");
    }

    return 0;
}
