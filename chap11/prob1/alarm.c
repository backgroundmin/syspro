#include <stdio.h>
#include <unistd.h>
#include <signal.h>
int main( )
{
   alarm(5);
   printf("무한 루프 \n");
   int a=0;
   while (1) {
	   a++;
      sleep(1);
      printf("%d초 경과 \n",a);
   }
   printf("실행되지 않음 \n");
}


