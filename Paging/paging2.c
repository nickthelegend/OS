#include <stdio.h>

#define FRAME_SIZE 4  // Size of each frame in memory

int main() {
    int page_table[10];  // Page table to map page numbers to frame numbers
    int num_pages, page_num, offset;

    // Enter the number of pages
    printf("Enter the number of pages in the process: ");
    scanf("%d", &num_pages);

    // Input the frame numbers for each page
    for (int i = 0; i < num_pages; i++) {
        printf("Enter the frame number for page %d: ", i);
        scanf("%d", &page_table[i]);
    }

    // Enter the logical address
    printf("Enter a logical address (page number and offset):\n");
    printf("Page number: ");
    scanf("%d", &page_num);
    printf("Offset: ");
    scanf("%d", &offset);

    // Calculate the physical address
    int frame_number = page_table[page_num];  // Get the frame number for the given page
    int physical_address = frame_number * FRAME_SIZE + offset;  // Calculate the physical address

    // Output the results
    printf("Logical Address: (Page: %d, Offset: %d)\n", page_num, offset);
    printf("Physical Address: (Frame: %d, Offset: %d)\n", frame_number, offset);
    printf("Physical Address: %d\n", physical_address);  // Total physical address

    return 0;
}
