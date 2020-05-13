#include "lab4_util.h"


#define SYS_READ 0
#define SYS_WRITE 1
#define SYS_OPEN 2
#define SYS_LSEEK 8
#define STDIN 0
#define STDOUT 1
#define RDWR 2
#define EXIT 60



extern int system_call();

int main (int argc , char* argv[])
{
char buffer[30];
int bytes_received;
bytes_received=system_call(SYS_READ,STDIN,buffer,sizeof(char)*30);
int file=0;
file=system_call(SYS_OPEN,"greeting",RDWR,256);
if(file<0)
system_call(EXIT,85);
system_call(SYS_LSEEK,file,4117,0);
int bytes_written;
bytes_written=system_call(SYS_WRITE,file,buffer,sizeof(char)*30);
	

  return 0;
}
