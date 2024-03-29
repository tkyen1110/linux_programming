#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
int main(void) 
{
	int i, delay=1000000;
	pid_t childpid;
	sem_t *psem;
	char *sem_name = "/mytestsem";
	psem=sem_open(sem_name, O_CREAT, S_IRUSR|S_IWUSR, 0);

	char msg[128];
	snprintf(msg, 128, "i:%d PID:%ld Parent PID:%ld Child PID:%ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);
	char *c = msg;

	while(*c != '\0') 
	{
		fputc(*c, stderr);
		c++;
		for(i=0; i<delay; i++) ;
	}
//	sleep(3);
	printf("post\n");
	sem_post(psem);
	sem_close(psem);
	if(i==1)
		sem_unlink(sem_name);
	return 0;
}

