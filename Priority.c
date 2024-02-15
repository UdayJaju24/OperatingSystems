#include <stdio.h>

int main() {
    int n, i, j, time = 0;
    int at[10], bt[10], ct[10], tat[10], wt[10], pr[10], done[10] = {0};
    int total_wt = 0, total_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the arrival time, burst time and priority of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
    }

    // Sort processes based on priority (higher priority first)
    for (i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (j = i + 1; j < n; j++) {
            if (pr[j] > pr[max_idx]) {
                max_idx = j;
            }
        }
        // Swap the elements
        int tmp = pr[i];
        pr[i] = pr[max_idx];
        pr[max_idx] = tmp;

        tmp = bt[i];
        bt[i] = bt[max_idx];
        bt[max_idx] = tmp;

        tmp = at[i];
        at[i] = at[max_idx];
        at[max_idx] = tmp;
    }

    printf("\nGantt Chart:\n");
    printf("| ");
    while (1) {
        int min_pr = -1, min_at = 99999;
        for (i = 0; i < n; i++) {
            if (done[i] == 0 && at[i] <= time) {
                if (pr[i] > min_pr || min_pr == -1) {
                    min_pr = pr[i];
                    min_at = at[i];
                    j = i;
                }
            }
        }
        if (min_pr == -1) {
            time++;
            continue;
        }
        printf("P%d | ", j+1);
        ct[j] = time + bt[j];
        tat[j] = ct[j] - at[j];
        wt[j] = tat[j] - bt[j];
        total_tat += tat[j];
        total_wt += wt[j];
        done[j] = 1;
        time = ct[j];
        if (done[n-1] == 1) {
            break;
        }
    }

    printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("Average waiting time: %.2f\n", (float)total_wt/n);
    printf("Average turnaround time: %.2f\n", (float)total_tat/n);

    return 0;
}
