#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void)
{
	pid_t pid=fork();
	if(pid==0) {
		// sleep(1);
		execl("/bin/ls", "ls", "-l", NULL);
	}

	if(pid>0) {
		// sleep(1);
		waitpid(pid, NULL, 0);
	}

	return 0;
}

