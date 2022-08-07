#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define msize 100
struct mbuff
{
	long mtype;
	char mdata[msize];
};

int main()
{
	key_t key = ftok("./mykey",65);
	int msgid = msgget(key, IPC_CREAT | 0666);
	//create msg-1 struct
	struct mbuff msg1;
	msg1.mtype = 100;
	strcpy(msg1.mdata,"Message with type 100!\n");
	
	int data = msgsnd(msgid, &msg1, sizeof(msg1.mdata),0);
	
	//create msg-2 struct
	struct mbuff msg2;
	msg2.mtype = 200;
	strcpy(msg2.mdata,"Message with type 200!\n");
	
	data = msgsnd(msgid, &msg2, sizeof(msg2.mdata),0);
	
	struct mbuff msg3;
	msg3.mtype = 300;
	strcpy(msg3.mdata,"Message with type 300!\n");
	
	data = msgsnd(msgid, &msg3, sizeof(msg3.mdata),0);
	
	struct mbuff msg4;
	msg4.mtype = 400;
	strcpy(msg4.mdata,"Message with type 400!\n");
	
	data = msgsnd(msgid, &msg4, sizeof(msg4.mdata),0);
	
	struct mbuff msg5;
	msg5.mtype = 500;
	strcpy(msg5.mdata,"Message with type 500!\n");
	
	data = msgsnd(msgid, &msg5, sizeof(msg5.mdata),0);
	return 0;	
}






















