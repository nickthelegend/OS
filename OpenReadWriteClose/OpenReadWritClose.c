#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("ex.txt", O_RDONLY); // Open the file for reading
    if (fd < 0) { 
        perror("Error opening file");
        return 1;
    }

    char buffer[100];
    int bytes;

    // Read from the file and write to standard output
    while ((bytes = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytes); // Write to the terminal
    }

    if (bytes < 0) {
        perror("Error reading file");
    }

    close(fd); // Close the file
    return 0;
}
