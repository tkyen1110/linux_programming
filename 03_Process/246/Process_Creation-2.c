#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char **argv)
{
	pid_t   pid;
	int     status;
	switch(pid = fork())
	{
	case -1:
		perror("Fork failed");
		return -1;
	case 0:
		// sleep(1);
		printf("Child: I'm %d and my parent is %d\n", getpid(), getppid());
		return 0;
	default:
		// printf("child pid: %d\n", wait(&status));
		if(wait(&status) == -1)
		{
			perror("Wait failed");
			return -1;
		}
		printf("status: %d\n", status);
		printf("Parent: I'm %d and my child is %d\n", getpid(), pid);
	}	
	return 0;
}

