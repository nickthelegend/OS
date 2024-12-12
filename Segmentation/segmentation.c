#include <stdio.h>

#define MAX_SEGMENTS 10  // Maximum number of segments in a process

int main() {
    int segment_table[MAX_SEGMENTS][2];  // Each entry contains [Base Address, Size]
    int num_segments, segment_num, offset, base_address, segment_size;
    int physical_address;

    // Enter the number of segments in the process
    printf("Enter the number of segments in the process: ");
    scanf("%d", &num_segments);

    // Input the base address and size for each segment
    for (int i = 0; i < num_segments; i++) {
        printf("Enter the base address for segment %d: ", i);
        scanf("%d", &base_address);
        printf("Enter the size of segment %d: ", i);
        scanf("%d", &segment_size);

        // Store the base address and size for the segment in the segment table
        segment_table[i][0] = base_address;  // Store base address
        segment_table[i][1] = segment_size;  // Store segment size
    }

    // Enter the logical address (segment number and offset)
    printf("\nEnter a logical address (segment number and offset):\n");
    printf("Segment number: ");
    scanf("%d", &segment_num);
    printf("Offset: ");
    scanf("%d", &offset);

    // Validate the segment number and offset
    if (segment_num >= num_segments || segment_num < 0) {
        printf("Error: Invalid segment number!\n");
        return 1;
    }

    base_address = segment_table[segment_num][0];  // Get the base address for the given segment
    segment_size = segment_table[segment_num][1];  // Get the size of the given segment

    // Check if the offset is valid (it should be within the segment's size)
    if (offset < 0 || offset >= segment_size) {
        printf("Error: Invalid offset! It must be between 0 and the segment size.\n");
        return 1;
    }

    // Calculate the physical address by adding the base address and offset
    physical_address = base_address + offset;

    // Output the results
    printf("\nLogical Address: (Segment: %d, Offset: %d)\n", segment_num, offset);
    printf("Physical Address: %d (Base Address: %d, Offset: %d)\n", physical_address, base_address, offset);

    return 0;
}
