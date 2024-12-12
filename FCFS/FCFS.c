#include<stdio.h>

int main() {
    int n, i, j;
    int at[20], bt[20], wt[20], tat[20], p[20];
    int avwt = 0, avtat = 0, current_time = 0;
    int temp;

    // Input number of processes
    printf("Enter total number of processes (maximum 20): ");
    scanf("%d", &n);

    // Input Arrival Time and Burst Time for each process
    printf("\nEnter Process Arrival Time and Burst Time\n");
    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("P[%d] Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("P[%d] Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Sort processes by Arrival Time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                // Swap arrival time
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // Swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap process numbers
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculate Waiting Time and Turnaround Time
    wt[0] = 0; // First process has no waiting time
    tat[0] = bt[0];
    current_time = at[0] + bt[0];
    avwt += wt[0];
    avtat += tat[0];

    printf("\nProcess\t\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time");
    printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d", p[0], at[0], bt[0], wt[0], tat[0]);

    for (i = 1; i < n; i++) {
        if (current_time < at[i]) {
            current_time = at[i];
        }
        wt[i] = current_time - at[i];
        tat[i] = wt[i] + bt[i];
        current_time += bt[i];

        printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d", p[i], at[i], bt[i], wt[i], tat[i]);

        avwt += wt[i];
        avtat += tat[i];
    }

    // Calculate and display average Waiting Time and Turnaround Time
    avwt /= n;
    avtat /= n;

    printf("\n\nAverage Waiting Time: %d", avwt);
    printf("\nAverage Turnaround Time: %d", avtat);

    return 0;
}
