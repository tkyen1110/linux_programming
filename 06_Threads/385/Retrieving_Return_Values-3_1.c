#include <stdio.h>
#include <pthread.h>
#include <string.h>
void *thread_func(void *arg) 
{
	//non portable code
	fprintf(stderr, "tid:%x\n", (int)pthread_self());
	double *ret=(double*)arg;
	*ret=1.0f;
	pthread_detach(pthread_self());
	fprintf(stderr, "in thread_func : %.1f\n", *ret);
	return NULL;
}
int main(void)
{
	int error;
	double ret;
	pthread_t tid;
	if((error=pthread_create(&tid, NULL, thread_func, (void*)&ret)))
		fprintf(stderr, "Failed to create thread: %s\n", strerror(error));
	if((error=pthread_join(tid, NULL)))
		fprintf(stderr, "Failed to join thread: %s\n", strerror(error));
	fprintf(stderr, "in main : %.1f\n", ret);
	return 0;
}
