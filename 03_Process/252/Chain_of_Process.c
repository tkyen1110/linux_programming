#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void)
{
	int i, n=10;
	pid_t childpid;
	for(i=1; i<=n; i++)
	{
		childpid = fork();
		if(childpid)
			break;
	}
	fprintf(stderr, "i:%d pid:%ld parentid:%ld childid:%ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);
	wait(NULL);
	return 0;
}

