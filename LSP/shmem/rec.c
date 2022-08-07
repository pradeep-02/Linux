#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define msize 100

int main()
{
	key_t key = ftok("./myshm",65);
	int shmid = shmget(key, msize ,IPC_CREAT | 0666);
		
	char *pdata = (char *)shmat(shmid,NULL,0); //shmflg = 0 for read/write permission
	printf("Printing mess from shared mem: \n");
	printf("%s\n",pdata);	
	//detach the mem after writing:
	int ret = shmdt(pdata);
	if(ret == 0)
		printf("Memory is removed after writing\n");
	shmctl(shmid,IPC_RMID,0);
	return 0;	
}






















