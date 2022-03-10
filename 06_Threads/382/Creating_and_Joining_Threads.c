#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
void *thread_func(void *arg) 
{
	//non portable code
	sleep(2);
	fprintf(stderr, "pid:%ld, tid:%lx\n", (long)getpid(), (unsigned long)pthread_self());
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

// int main(void)
// {
// 	int error;
// 	pthread_t tid;
// 	if((error=pthread_create(&tid, NULL, thread_func, NULL)))
// 		fprintf(stderr, "Failed to create thread: %s\n", strerror(error));
// 	fprintf(stderr, "pid:%ld, tid:%lx (main thread)\n", (long)getpid(), (unsigned long)pthread_self());
// 	// pthread_exit(NULL);
// 	return 0;
// }
