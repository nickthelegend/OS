#include<stdio.h>

int main() {
    int n, i, shortest_index;
    int at[20], bt[20], wt[20], tat[20], completed[20] = {0};
    float avwt = 0, avtat = 0;
    int current_time = 0, total_completed = 0;

    // Input number of processes
    printf("Enter total number of processes (maximum 20): ");
    scanf("%d", &n);

    // Input Arrival Time and Burst Time for each process
    printf("\nEnter Process Arrival Time and Burst Time\n");
    for (i = 0; i < n; i++) {
        printf("P[%d] Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("P[%d] Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
    }

    printf("\nProcess\t\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time");

    // SJF Scheduling (Non-Preemptive)
    while (total_completed < n) {
        int found = 0;
        int shortest_bt = 1e9; // Initialize with a very large number

        // Find the process with the shortest burst time that has arrived
        for (i = 0; i < n; i++) {
            if (at[i] <= current_time && completed[i] == 0 && bt[i] < shortest_bt) {
                shortest_bt = bt[i];
                shortest_index = i;
                found = 1;
            }
        }

        if (found) {
            // Execute the shortest job
            wt[shortest_index] = current_time - at[shortest_index];
            tat[shortest_index] = wt[shortest_index] + bt[shortest_index];
            current_time += bt[shortest_index];
            completed[shortest_index] = 1;
            total_completed++;

            // Print process details
            printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t\t%d",
                   shortest_index + 1, at[shortest_index], bt[shortest_index],
                   wt[shortest_index], tat[shortest_index]);

            avwt += wt[shortest_index];
            avtat += tat[shortest_index];
        } else {
            // If no process is ready, increment the current time
            current_time++;
        }
    }

    // Calculate average waiting time and turnaround time
    avwt /= n;
    avtat /= n;

    // Print average times
    printf("\n\nAverage Waiting Time: %.2f", avwt);
    printf("\nAverage Turnaround Time: %.2f", avtat);

    return 0;
}
