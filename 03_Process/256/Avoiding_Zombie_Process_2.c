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
		pid_t pid1, pid2;
		pid1 = wait(NULL);
		printf("pid1:%d\n", pid1);
		pid2 = wait(NULL);
		printf("pid2:%d\n", pid2);
		printf("parent, pid:%ld ppid:%ld\n", (long)getpid(), (long)getppid());
	}
	return 0;
}

