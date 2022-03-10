#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void *thread_func2(void *arg) 
{
	//non portable code
	fprintf(stderr, "pid:%ld, tid:%lx (thread_func2)\n", (long)getpid(), (unsigned long)pthread_self());
	return NULL;
}

void *thread_func(void *arg) 
{
	int error2;
	pthread_t tid2;

	if((error2=pthread_create(&tid2, NULL, thread_func2, NULL)))
		fprintf(stderr, "Failed to create thread: %s\n", strerror(error2));
	if((error2=pthread_join(tid2, NULL)))
		fprintf(stderr, "Failed to join thread: %s\n", strerror(error2));
	fprintf(stderr, "pid:%ld, tid:%lx (thread_func)\n", (long)getpid(), (unsigned long)pthread_self());
	return NULL;
}
int main(void)
{
	int error;
	pthread_t tid;
	if((error=pthread_create(&tid, NULL, thread_func, NULL)))
		fprintf(stderr, "Failed to create thread: %s\n", strerror(error));
	if((error=pthread_join(tid, NULL)))
		fprintf(stderr, "Failed to join thread: %s\n", strerror(error));
	fprintf(stderr, "pid:%ld, tid:%lx (main thread)\n", (long)getpid(), (unsigned long)pthread_self());
	return 0;
}

