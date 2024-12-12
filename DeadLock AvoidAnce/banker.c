#include <stdio.h>

void main() {
    int instance[20], avail[20], P[10], n, m;
    
    // Input: Number of resources
    printf("\nEnter the number of resources: ");
    scanf("%d", &n);
    
    // Input: Max instances of each resource
    printf("\nEnter the max instances of each resource:\n");
    for (int i = 0; i < n; i++) {
        printf("%c = ", (i + 97)); // Using 'a', 'b', ... for resource names
        scanf("%d", &instance[i]);
    }
    
    // Input: Number of processes
    printf("\nEnter the number of processes: ");
    scanf("%d", &m);
    
    // Input: Allocation Matrix
    printf("\nEnter the allocation matrix:\n");
    int alloc[m][n];
    for (int i = 0; i < m; i++) {
        printf("P[%d]: ", i);
        for (int j = 0; j < n; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    
    // Input: MAX Matrix
    printf("\nEnter the MAX matrix:\n");
    int MAX[m][n];
    for (int i = 0; i < m; i++) {
        printf("P[%d]: ", i);
        for (int j = 0; j < n; j++) {
            scanf("%d", &MAX[i][j]);
        }
    }
    
    // Calculate Available Resources
    for (int j = 0; j < n; j++) {
        avail[j] = instance[j]; // Start with total resources
        for (int i = 0; i < m; i++) {
            avail[j] -= alloc[i][j]; // Subtract allocated resources
        }
    }
    
    // Print Available Resources
    printf("\nAvailable resources:\n");
    for (int j = 0; j < n; j++) {
        printf("%c = %d\n", (j + 97), avail[j]);
    }
    
    // Calculate Need Matrix
    int need[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            need[i][j] = MAX[i][j] - alloc[i][j];
        }
    }
    
    // Banker's Algorithm
    int f[m], ans[m], ind = 0;
    for (int i = 0; i < m; i++) {
        f[i] = 0; // Initialize all processes as unfinished
    }
    
    int safe = 1; // Flag to check if system is in a safe state
    while (ind < m) {
        int found = 0;
        for (int i = 0; i < m; i++) {
            if (f[i] == 0) { // Process not finished
                int flag = 1;
                for (int j = 0; j < n; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 0; // Cannot allocate resources to this process
                        break;
                    }
                }
                if (flag) {
                    // Allocate resources to process i
                    for (int j = 0; j < n; j++) {
                        avail[j] += alloc[i][j];
                    }
                    ans[ind++] = i; // Add process to the safe sequence
                    f[i] = 1;       // Mark process as finished
                    found = 1;
                }
            }
        }
        
        if (!found) {
            safe = 0; // System is not in a safe state
            break;
        }
    }
    
    // Output the result
    if (safe) {
        printf("\nFollowing is the SAFE Sequence:\n");
        for (int i = 0; i < ind; i++) {
            printf("P%d", ans[i]);
            if (i < ind - 1) {
                printf(" -> ");
            }
        }
        printf("\n");
    } else {
        printf("\nThe system is not in a safe state.\n");
    }
}
