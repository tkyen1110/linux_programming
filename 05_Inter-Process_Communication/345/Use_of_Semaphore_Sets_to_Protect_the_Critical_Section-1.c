#include <stdio.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <sys/wait.h>

int initelement(int semid, int semnum, int semvalue)
{
	union semun {
		int val;
		struct semid_ds *buf;
		unsigned short *array;
	} arg;
	arg.val = semvalue;
	return semctl(semid, semnum, SETVAL, arg);
}

void setsembuf(struct sembuf *s, int num, int op, int flg)
{
	s->sem_num = (short)num;
	s->sem_op = (short)op;
	s->sem_flg = (short)flg;
	return;
}

int main()
{
	int i, j, delay=1000;
	pid_t childpid;
	
	int semid;
	struct sembuf semsignal[1], semwait[1];
	//error handling omitted for clarity
	semid = semget(IPC_PRIVATE, 1, S_IRUSR | S_IWUSR);
	initelement(semid, 0, 2);
	setsembuf(semwait, 0, -2, 0);
	setsembuf(semsignal, 0, 2, 0);

	for(i=1; i<=100; i++)
		if(childpid = fork())
			break;
	char msg[128];
	snprintf(msg, 128, "i:%d PID:%ld Parent PID:%ld Child PID:%ld\n", i, (long)getpid(), (long)getppid(), (long)childpid); 
	char *c = msg;

	semop(semid, semwait, 1);

	while(*c != '\0') 
	{

		fputc(*c, stderr);
		c++;
		for(j=0; j<delay; j++) ;
	}

	semop(semid, semsignal, 1);

	while(wait(NULL)>0);

	if(i==1) {
		sleep(3);
		semctl(semid, 0, IPC_RMID);
	}

	return 0;
}

