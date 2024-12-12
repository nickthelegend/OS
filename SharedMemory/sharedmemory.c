
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main() {
    int id = shmget(IPC_PRIVATE, 20, 0666 | IPC_CREAT);


    if (fork() == 0) { printf("Received: %s\n", shmat(id, NULL, 0));

 }
    else { strcpy(shmat(id, NULL, 0), "Hello, Shared Memory!");

 }
    shmctl(id, IPC_RMID, NULL);


    return 0;


}