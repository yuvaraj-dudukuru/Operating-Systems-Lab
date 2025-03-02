#include <stdio.h>

int main() {
    int st[10], bt[10], wt[10], tat[10], n, tq;
    int i, count = 0, swt = 0, stat = 0, temp, sq = 0;
    float awt, atat;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input Burst Time
    printf("Enter the burst time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("p%d: ", i + 1);
        scanf("%d", &bt[i]);
        st[i] = bt[i]; // Copy burst time to service time
    }

    // Input Time Quantum
    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    // Round Robin Scheduling
    while (1) {
        count = 0;
        for (i = 0; i < n; i++) {
            temp = tq;

            if (st[i] == 0) {
                count++;
                continue;
            }

            if (st[i] > tq) {
                st[i] -= tq;
            } else {
                temp = st[i];
                st[i] = 0;
            }

            sq += temp;
            tat[i] = sq; // Turnaround time
        }

        if (count == n)
            break;
    }

    // Calculate Waiting Time
    for (i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        swt += wt[i];
        stat += tat[i];
    }

    // Calculate Average Waiting Time & Turnaround Time
    awt = (float)swt / n;
    atat = (float)stat / n;

    // Print Process Table
    printf("\nProcess No.\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    // Print Average Waiting Time & Turnaround Time
    printf("\nAverage Waiting Time = %.2f", awt);
    printf("\nAverage Turnaround Time = %.2f\n", atat);

    return 0;
}
