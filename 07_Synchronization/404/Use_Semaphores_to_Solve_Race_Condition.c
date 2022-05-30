#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t mutex;
void *thr_fun(void *arg)
{
	int i, *counter=(int*)arg;
	for(i=0; i<100000000; i++) {
		sem_wait(&mutex);
		(*counter)++;
		sem_post(&mutex);
	}
	return NULL;
}
int main(void)
{
	int i, tnum=2;
	int counter=0;
	pthread_t tid[tnum];
	sem_init(&mutex, 0, 1);
	//error handling omitted for clarity
	for(i=0; i<tnum; i++)
		pthread_create(&tid[i], NULL, thr_fun, (void*)&counter);
	for(i=0; i<tnum; i++)
		pthread_join(tid[i], NULL);
	fprintf(stderr, "global_counter=%d\n", counter);
	return 0;
}

