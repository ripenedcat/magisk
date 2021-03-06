#include <stdio.h>

#include <rtai.h>
#include <rtai_nam2num.h>
#include <rtai_shm.h>
#include <sys/msg.h>

#define BUFFER 1


struct mymsgbuf {
	long mtype;
	int data[BUFFER];
}message;


int main(void)
{  
    int i;
	int status;
	int queue;
	key_t msgkey;

	msgkey = ftok(".haha", 'm222');

	queue = msgget(msgkey, 0660 | IPC_CREAT );
	
	message.mtype = 1;

	while (1)
	{ 
		printf("input a value:");
        scanf("%d", &message.data[0]);
		printf("setpoint:%d\n", message.data[0]);

		status = msgsnd(queue, &message, sizeof(message.data), 0);
	}
	
	

	return 0;
}
