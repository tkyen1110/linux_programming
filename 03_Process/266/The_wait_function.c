#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h> 
int main()
{
	pid_t pid; 
	char *message;
	int n; 
	int exit_code;

	printf("fork program starting\n");
	pid = fork();
	switch(pid)
	{
		case -1:
			exit(1) ;
		case 0:
			message = "This is the child";
			n=8;
			exit_code=37;
			break;
		default:
			message = "This is the parent";
			n=5;
			exit_code=0;
			break;
	}
	for(; n > 0; n--)
	{
		// puts(message);
		printf("%s pid:%ld\n", message, (long)getpid());
		sleep(1);
	}

	// This section of the program waits for the child process to finish.
	if(pid) 
	{
		int stat_val;
		pid_t child_pid;
		child_pid = wait(&stat_val);
		printf("Child has finished: PID = %d\n", child_pid);
		if(WIFEXITED(stat_val))
			printf("Child exited with code %d\n", WEXITSTATUS(stat_val)); 
		else
			printf("Child terminated abnormally\n");
	}
	exit(exit_code);
}


