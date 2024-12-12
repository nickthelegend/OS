#include <stdio.h>
#define MAX_FRAMES 10
#define MAX_PAGES 50

void simulateFCFS(int pages[], int n, int frames[], int frame_count) {
    int page_faults = 0, frame_index = 0;

    // Initialize frames to -1 (indicating empty)
    for (int i = 0; i < frame_count; i++) {
        frames[i] = -1;
    }

    printf("\nPage Reference String: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", pages[i]);
    }
    printf("\n\nFrame States:\n");

    for (int i = 0; i < n; i++) {
        int found = 0;

        // Check if the page is already in one of the frames
        for (int j = 0; j < frame_count; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                
                break;
                
            }
        }

        // If the page is not found, replace the oldest page
        if (!found) {
            // Print the page being replaced for debugging
            printf("Page %d is not in frames. Replacing page %d.\n", pages[i], frames[frame_index]);
            
            frames[frame_index] = pages[i];
            frame_index = (frame_index + 1) % frame_count;  // Move to the next frame in a circular way
            page_faults++;
        }

        // Print the current state of frames
        for (int j = 0; j < frame_count; j++) {
            if (frames[j] == -1) {
                printf("- ");
            } else {
                printf("%d ", frames[j]);
            }
        }
        printf("\n");
    }

    // Print the total number of page faults
    printf("\nTotal Page Faults: %d\n", page_faults);
}

int main() {
    int pages[MAX_PAGES], frames[MAX_FRAMES];
    int n, frame_count;

    // Take input for number of pages and the page reference string
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the page reference string:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Take input for the number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &frame_count);

    // Check if the number of frames exceeds the max allowed
    if (frame_count > MAX_FRAMES) {
        printf("Error: Maximum frame count exceeded.\n");
        return 1;
    }

    // Call the FCFS simulation function
    simulateFCFS(pages, n, frames, frame_count);
    
    return 0;
}
