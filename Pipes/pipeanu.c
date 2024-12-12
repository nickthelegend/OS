#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2]; 
    pipe(fd); // Create a pipe
    if (fork() == 0) { 
        char buf[20]; 
        read(fd[0], buf, sizeof(buf)); // Child reads from the pipe
        printf("Received: %s\n", buf); 
    }
    else { 
        write(fd[1], "Hello, World!", 14); // Parent writes into the pipe
        printf("Inside the parent process");
    }
    return 0;
} 
