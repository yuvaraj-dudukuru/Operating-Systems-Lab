#include <stdio.h>

int main() {
    int bt[20], p[20], wt[20], tat[20], pri[20], i, j, k, n, total = 0, pos, temp;
    float avg_wt, avg_tat;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input Burst Time
    printf("\nEnter Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("p%d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1; // Contains process number
    }

    // Input Priority
    printf("\nEnter Priority of the process:\n");
    for (i = 0; i < n; i++) {
        printf("p%d: ", i + 1);
        scanf("%d", &pri[i]);
    }

    // Sorting processes based on priority (Ascending Order)
    for (i = 0; i < n; i++) {
        for (k = i + 1; k < n; k++) {
            if (pri[i] > pri[k]) {
                // Swap process number
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;

                // Swap burst time
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                // Swap priority
                temp = pri[i];
                pri[i] = pri[k];
                pri[k] = temp;
            }
        }
    }

    // Waiting time calculation
    wt[0] = 0; // Waiting time for the first process is zero

    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
        total += wt[i];
    }

    avg_wt = (float)total / n; // Average waiting time
    total = 0;

    // Display results
    printf("\nProcess\t    Burst Time\t    Priority\t    Waiting Time\t    Turnaround Time");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i]; // Calculate turnaround time
        total += tat[i];

        printf("\np%d\t\t%d\t\t%d\t\t%d\t\t%d", p[i], bt[i], pri[i], wt[i], tat[i]);
    }

    avg_tat = (float)total / n; // Average turnaround time

    printf("\n\nAverage Waiting Time = %f", avg_wt);
    printf("\nAverage Turnaround Time = %f\n", avg_tat);

    return 0;
}
