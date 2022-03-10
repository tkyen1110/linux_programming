#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

pid_t childpid;
void *thread_func(void *arg) 
{
	// non portable code

	// sleep(4);

	// pid_t childpid;
	// childpid=fork();
	system("ls");
	// execlp("ps", "ps", "-ax",  (char *)0);
	fprintf(stderr, "pid:%ld, tid:%lx\n", (long)getpid(), (unsigned long)pthread_self());
	return NULL;
}

int main(void)
{
	int error;
	pid_t childpid;
	pthread_t tid;

	// childpid=fork();
	// if (childpid==0) {
	// 	fprintf(stderr, "parent pid:%ld\n", (long)getppid());
	// 	fprintf(stderr, "child  pid:%ld\n", (long)getpid());
	// }

	if((error=pthread_create(&tid, NULL, thread_func, NULL)))
		fprintf(stderr, "Failed to create thread: %s\n", strerror(error));

	// sleep(2);
	// childpid=fork();
	// if (childpid==0) {
	// 	fprintf(stderr, "parent pid:%ld\n", (long)getppid());
	// 	fprintf(stderr, "child  pid:%ld\n", (long)getpid());
	// }

	if((error=pthread_join(tid, NULL)))
		fprintf(stderr, "Failed to join thread: %s\n", strerror(error));

	childpid=fork();
	if (childpid==0) {
		fprintf(stderr, "parent pid:%ld\n", (long)getppid());
		fprintf(stderr, "child  pid:%ld\n", (long)getpid());
	}

	if(childpid>0)
	{
		wait(NULL);
		fprintf(stderr, "pid:%ld, tid:%lx (main thread),parent process\n", (long)getpid(), (unsigned long)pthread_self());
	}
	else
		fprintf(stderr, "pid:%ld, tid:%lx (main thread),child process\n", (long)getpid(), (unsigned long)pthread_self());
	return 0;
}
