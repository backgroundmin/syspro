#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
void alarmHandler(int signo);
struct sigaction newact;
struct sigaction oldact;

int main( )
{
	newact.sa_handler = alarmHandler;
  sigaction(SIGALRM,&newact,&oldact);
  alarm(5);    /* 알람 시간 설정 */
  short i = 0;
  while (1) {
    sleep(1);
    i++;
    printf("%d second\n", i);
  }
  printf("end\n");
}

void alarmHandler(int signo)
{
   printf("Wake up\n");
   exit(0);
}

