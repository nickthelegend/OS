#include <stdio.h>

int main() {
    int n, i, qt, current_time = 0;
    int at[20], bt[20], rt[20];
    int wt[20], tat[20];
    int total_wt = 0, total_tat = 0, completed = 0;
    int flag = 0;

    // Input number of processes and time quantum
    printf("Enter total number of processes (maximum 20): ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &qt);

    // Input arrival time and burst time for each process
    printf("\nEnter Process Arrival Time and Burst Time\n");
    for (i = 0; i < n; i++) {
        printf("P[%d] Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("P[%d] Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // Initialize remaining time to burst time
    }

    // Display the process information
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    while (completed < n) {
        flag = 0;
        for (i = 0; i < n; i++) {
            if (at[i] <= current_time && rt[i] > 0) {
                flag = 1; // A process is found
                if (rt[i] > qt) {
                    current_time += qt; // Process runs for time quantum
                    rt[i] -= qt; // Remaining time decreases by quantum
                } else {
                    current_time += rt[i]; // Process finishes
                    wt[i] = current_time - at[i] - bt[i]; // Calculate waiting time
                    tat[i] = wt[i] + bt[i]; // Calculate turnaround time
                    rt[i] = 0; // Process is completed
                    completed++; // Increase count of completed processes

                    // Display process details
                    printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n",
                           i + 1, at[i], bt[i], wt[i], tat[i]);

                    total_wt += wt[i]; // Accumulate total waiting time
                    total_tat += tat[i]; // Accumulate total turnaround time
                }
            }
        }

        // If no process is available, increment current time
        if (flag == 0) {
            current_time++;
        }
    }

    // Calculate and display average waiting time and turnaround time
    printf("\nAverage Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);

    return 0;
}
