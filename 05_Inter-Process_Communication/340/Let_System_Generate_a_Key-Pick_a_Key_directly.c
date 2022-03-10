#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
int main(void)
{
	int shmid_1=-1;
	int shmid_2=-1;
	int shm_size=100;
	// let system pick a key
	if((shmid_1=shmget(IPC_PRIVATE, shm_size, S_IRUSR | S_IWUSR | IPC_CREAT)) == -1)
		perror("Failed to create shared memory 1");
	fprintf(stderr,"Shared memory id: %d\n", shmid_1);

	// pick a key directly
	if((shmid_2=shmget(123457, shm_size, S_IRUSR | S_IWUSR | IPC_CREAT)) == -1)
		perror("Failed to create shared memory 2");
	fprintf(stderr,"Shared memory id: %d\n", shmid_2);

	return 0;
}
