#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void)
{
	pid_t childpid;
	childpid = fork();
	if(childpid == -1)
		perror("Failed to fork\n");
	else if (childpid ==0)
		printf("child, pid:%ld ppid:%ld\n", (long)getpid(), (long)getppid());	
	else
	{
		wait(NULL);
		//sleep(10);
		printf("parent, pid:%ld ppid:%ld\n", (long)getpid(), (long)getppid());
	}
	return 0;
}

