#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


int main()
{
	
       int ret = mkfifo("fifo1", 0666);
       char buff[100];;
       printf("Write to fifo: ");
       
       int fd = open("fifo1",O_WRONLY);
       while(1)
       {
       		fgets(buff,100, stdin);
       		write(fd,buff,strlen(buff));
       }
}

