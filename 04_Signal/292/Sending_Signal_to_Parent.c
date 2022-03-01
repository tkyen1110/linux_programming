#include <stdio.h>
#include <unistd.h>
#include <signal.h>
int main(void)
{
	pid_t childpid;
	childpid = fork();
	//error handling omitted
	if(childpid == 0)
	{
		printf("child pid = %d\n", getpid());
		sleep(5);
		kill(getppid(), SIGUSR1);
	}
	else
	{
		printf("parent pid = %d\n", getpid());
		int i;
		for(i=0;;i++) {
			printf("i:%d\n", i);
			sleep(1);
		}
	}
	printf("pid = %d ends\n", getpid());
	return 0;
}
