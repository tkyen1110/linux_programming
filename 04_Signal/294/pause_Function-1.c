#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
void recvUSR1(int signo)
{
	printf("received SIGUSER1\n");
}
int main(void)
{
	//error handling omitted for clarity
	int childpid;
	signal(SIGUSR1, recvUSR1);
	childpid = fork();
	if(childpid==0)
	{
		sleep(3);
		printf("child\n");
		kill(getppid(),SIGUSR1);
		// sleep(1);
		// printf("child\n");
	}
	if(childpid>0)
	{
		// sleep(3);
		pause();
		printf("parent\n");
		wait(NULL);
		// printf("parent\n");
	}
	return 0;
}

