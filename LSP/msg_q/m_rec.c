#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

#define msize 100
struct mbuff
{
	long mtype;
	char mdata[msize];
};
 
int main(int argc, char *argv[])
{
	if(argc < 2){
		printf("Please pass one argument!!!\n");
		return 0;
	}
	long tye = (atoi)(argv[1]);
	key_t key = ftok("./mykey",65);
	int msgid = msgget(key, IPC_CREAT | 0666);
	struct mbuff msg1;
	ssize_t data = msgrcv(msgid, &msg1, msize, tye, IPC_NOWAIT);
	
	if(data == -1){
		printf("There is no msg\n");
		return 0;
	}
	
	printf("Data: %s\n",msg1.mdata);
	return 0;	
}
