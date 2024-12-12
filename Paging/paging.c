#include <stdio.h>

#define FRAME_SIZE 4  // Size of each frame
#define TOTAL_FRAMES 8  // Total number of frames in physical memory
#define TOTAL_PAGES 6   // Total number of pages in the process

// Define the page table
int page_table[TOTAL_PAGES];

// Simulate the paging process
void simulate_paging() {
    int frame_number = 0;
    for (int i = 0; i < TOTAL_PAGES; i++) {
        // If a page is not yet assigned a frame
        if (page_table[i] == -1) {
            page_table[i] = frame_number++;  // Assign a frame to the page
            if (frame_number >= TOTAL_FRAMES) {
                printf("Memory Full. No more frames to allocate.\n");
                break;
            }
        }
    }

    // Display the page table with frame mappings
    printf("Page Table:\n");
    for (int i = 0; i < TOTAL_PAGES; i++) {
        printf("Page %d -> Frame %d\n", i, page_table[i]);
    }
}

int main() {
    // Initialize the page table with -1 (indicating no frame assigned)
    for (int i = 0; i < TOTAL_PAGES; i++) {
        page_table[i] = -1;
    }

    // Simulate Paging
    simulate_paging();
    return 0;
}
