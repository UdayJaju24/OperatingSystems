#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int at[n], bt[n], ct[n], tat[n], wt[n];

    printf("\nEnter the Arrival time and Burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("\nProcess %d:\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
    }

    // Calculate Completion Time for each process
    ct[0] = at[0] + bt[0];
    for (i = 1; i < n; i++) {
        if (ct[i - 1] > at[i])
            ct[i] = ct[i - 1] + bt[i];
        else
            ct[i] = at[i] + bt[i];
    }

    // Calculate Turnaround Time and Waiting Time for each process
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Print Gantt Chart
    printf("\nGantt Chart:\n");
    printf(" ");

    for (i = 0; i < n; i++) {

        printf("P%d\t", i + 1);

    }

    // Print Table
    printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT");
    for (i = 0; i < n; i++)
        printf("\n%d\t%d\t%d\t%d\t%d\t%d", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);

    return 0;
}
