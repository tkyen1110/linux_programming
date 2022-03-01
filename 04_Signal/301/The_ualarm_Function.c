#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
void alarm_handler(int signo)
{
        printf("%ld\n", time(NULL));
}
int main(void)
{
        signal(SIGALRM, alarm_handler);
        ualarm(500000, 100000);
        while(1)
             ;
        return 0;
}

