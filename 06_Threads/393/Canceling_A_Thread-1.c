#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
void *thread_func(void *arg) 
{
	int oldstate, oldtype;
	fprintf(stderr, "tid:%x\n", (unsigned int)pthread_self()); //non portable code
	srand(time(NULL));
	while(1) 
	{
		pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, &oldtype);
		pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &oldstate);
		char msg[100];
		float randnum = rand()/(float)RAND_MAX;
		sprintf(msg, "random number(0-1.0) : %.5f\n", randnum);
		char *c=msg;
		while(*c!='\0') 
		{	
			fputc(*c, stderr); 
			c++;
		}
		pthread_setcanceltype(oldtype, NULL); 
		pthread_setcancelstate(oldstate, NULL);
		pthread_testcancel();
	}
	return NULL;
}
int main(void) 
{
	int error; 
	pthread_t tid;
	if((error=pthread_create(&tid, NULL, thread_func, NULL)))
		fprintf(stderr, "Failed to create thread: %s\n", strerror(error));
	// sleep(1);
	pthread_cancel(tid);
	// sleep(1);
	if((error=pthread_join(tid,NULL)))
		fprintf(stderr, "Failed to join thread: %s\n", strerror(error));
	return 0;
}

