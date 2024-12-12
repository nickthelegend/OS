#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2]; // File descriptors for the pipe
    pid_t pid;
    char write_msg[] = "Hello from parent!";
    char read_msg[100];

    // Create a pipe
    if (pipe(fd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid = fork(); // Create a child process
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid > 0) { // Parent Process
        close(fd[0]); // Close reading end
        write(fd[1], write_msg, strlen(write_msg) + 1);
        close(fd[1]); // Close writing end
    } else { // Child Process
        close(fd[1]); // Close writing end
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);
        close(fd[0]); // Close reading end
    }
    return 0;
}
