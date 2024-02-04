//WAP to implement priority scheduling (non-preemptive)  in C
#include <stdio.h>

int main() {
    int a[10], b[10], x[10];
    int waiting[10], turnaround[10], completion[10], p[10];
    int i, j, smallest, count = 0, time, n;
    double avg = 0, tt = 0, end;

    printf("\nEnter the number of Processes: ");
    scanf("%d", &n);

    // Input arrival time, burst time, and priority for each process
    for (i = 0; i < n; i++) {
        printf("Enter arrival time of process %d: ", i);
        scanf("%d", &a[i]);

        printf("Enter burst time of process %d: ", i);
        scanf("%d", &b[i]);

        printf("Enter priority of process %d: ", i);
        scanf("%d", &p[i]);
    }

    for (i = 0; i < n; i++)
        x[i] = b[i];

    p[9] = -1;

    for (time = 0; count != n; time++) {
        smallest = 9;
        for (i = 0; i < n; i++) {
            // Check if the process has arrived, has higher priority, and has remaining burst time
            if (a[i] <= time && p[i] > p[smallest] && b[i] > 0) {
                smallest = i;
            }
        }

        // Decrement the burst time for the selected process
        b[smallest]--;

        if (b[smallest] == 0) {
            count++;
            end = time + 1;
            completion[smallest] = end;
            waiting[smallest] = end - a[smallest] - x[smallest];
            turnaround[smallest] = end - a[smallest];
        }
    }

    // Print the table with process details
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\tCompletion Time\tPriority\n");
    for (i = 0; i < n; i++) {
        printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, x[i], a[i],
               waiting[i], turnaround[i], completion[i], p[i]);
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }

    // Print average waiting time and average turnaround time
    printf("\n\nAverage waiting time = %lf", avg / n);
    printf("\nAverage Turnaround time = %lf\n", tt / n);

    return 0;
}
