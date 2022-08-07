#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


int main()
{
	char buff[100];	
	int cnum;
       int ret = mkfifo("fifo1", 0666);
       printf("Read from fifo: ");   
       int fd = open("fifo1",O_RDONLY);
       while(1)
       {
       		cnum = read(fd,buff,100);
       		printf("Read: %s, Total text sent: %d\n",buff,cnum);
       }
}

