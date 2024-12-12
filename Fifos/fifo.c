#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    mkfifo("fifo", 0666);

 
    if (fork() == 0) { char buf[20];

 read(open("fifo", O_RDONLY), buf, 20);

 printf("Received: %s\n", buf);

 }
    else { write(open("fifo", O_WRONLY), "Hello, FIFO!", 13);

//  unlink("fifo");

 }
    return 0;


} 
