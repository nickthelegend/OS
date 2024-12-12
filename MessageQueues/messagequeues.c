#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

struct msg { long type;

 char text[100];

 } message;



int main() {
    int id = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);


    if (fork() == 0) { msgrcv(id, &message, sizeof(message), 1, 0);

 printf("Received: %s\n", message.text);

 msgctl(id, IPC_RMID, NULL);

 }
    else { message.type = 1;

 strcpy(message.text, "Hello, MQ!");

 msgsnd(id, &message, sizeof(message), 0);

 }
    return 0;


}
