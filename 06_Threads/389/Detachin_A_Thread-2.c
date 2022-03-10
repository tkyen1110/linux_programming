#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
void *thread_func(void*arg) 
{
	//pthread_detach(pthread_self());
	return NULL;
}
int main(void) 
{
	int error;
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	// pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	if((error=pthread_create(&tid, &attr, thread_func, NULL)))
		fprintf(stderr, "Failed to create thread: %s\n", strerror(error));
	pthread_attr_destroy(&attr);

	if((error=pthread_join(tid, NULL)))
		fprintf(stderr, "Failed to join thread: %s\n", strerror(error));
	fprintf(stderr, "main thread finished\n");
	return 0;
}

