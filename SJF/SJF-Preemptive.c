#include <stdio.h>

int main() {
    int n, i;
    int at[20], bt[20], rt[20]; // Arrival time, burst time, remaining burst time
    int wt[20], tat[20]; // Waiting time, turnaround time
    int current_time = 0, total_completed = 0;
    float avwt = 0, avtat = 0;

    // Input number of processes
    printf("Enter total number of processes (maximum 20): ");
    scanf("%d", &n);

    // Input arrival time and burst time for each process
    printf("\nEnter Process Arrival Time and Burst Time\n");
    for (i = 0; i < n; i++) {
        printf("P[%d] Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("P[%d] Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // Initialize remaining burst time
    }

    // Output Header
    printf("\nProcess\t\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time");

    // Execute processes
    while (total_completed < n) {
        int selected_process = -1;

        // Find the process with the shortest remaining time that has arrived
        for (i = 0; i < n; i++) {
            if (at[i] <= current_time && rt[i] > 0) { // Process has arrived and is not finished
                if (selected_process == -1 || rt[i] < rt[selected_process]) {
                    selected_process = i; // Select the process with the shortest remaining time
                }
            }
        }

        if (selected_process != -1) {
            // Execute the selected process for one time unit
            rt[selected_process]--;
            current_time++;

            // If the process is completed
            if (rt[selected_process] == 0) {
                total_completed++;

                // Calculate waiting time and turnaround time
                wt[selected_process] = current_time - at[selected_process] - bt[selected_process];
                tat[selected_process] = wt[selected_process] + bt[selected_process];

                // Print details of the completed process
                printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t\t%d",
                       selected_process + 1, at[selected_process], bt[selected_process],
                       wt[selected_process], tat[selected_process]);

                avwt += wt[selected_process]; // Add to total waiting time
                avtat += tat[selected_process]; // Add to total turnaround time
            }
        } else {
            // If no process is ready, increment the current time
            current_time++;
        }
    }

    // Calculate averages
    avwt /= n;
    avtat /= n;

    // Print average waiting and turnaround times
    printf("\n\nAverage Waiting Time: %.2f", avwt);
    printf("\nAverage Turnaround Time: %.2f", avtat);

    return 0;
}
