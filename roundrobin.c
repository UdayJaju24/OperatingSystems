#include <stdio.h>

#define MAX_PROCESS 10

int main()
{
    int arrival_time[MAX_PROCESS], burst_time[MAX_PROCESS], remaining_time[MAX_PROCESS];
    int waiting_time[MAX_PROCESS], turnaround_time[MAX_PROCESS];
    int quantum, num_process, time = 0, remaining_process = 0;

    printf("Enter number of processes: ");
    scanf("%d", &num_process);

    for (int i = 0; i < num_process; i++) {
        printf("Enter arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
        remaining_time[i] = burst_time[i];
        remaining_process++;
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    printf("\nGantt Chart\n");

    while (remaining_process > 0) {
        for (int i = 0; i < num_process; i++) {
            if (remaining_time[i] > 0) {
                printf("P%d \t", i+1);
                if (remaining_time[i] > quantum) {
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    time += remaining_time[i];
                    waiting_time[i] = time - arrival_time[i] - burst_time[i];
                    remaining_time[i] = 0;
                    turnaround_time[i] = time - arrival_time[i];
                    remaining_process--;
                }
            }
        }
    }

    printf("\n\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    int total_waiting_time = 0, total_turnaround_time = 0;

    for (int i = 0; i < num_process; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1, arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    double avg_waiting_time = (double) total_waiting_time / num_process;
    double avg_turnaround_time = (double) total_turnaround_time / num_process;

    printf("\nAverage Waiting Time: %.2lf\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2lf\n", avg_turnaround_time);

    return 0;
}

