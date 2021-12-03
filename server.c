#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void wololo (int sig)
{
	(void)sig;
	printf("Que te follen alemán!\n");
	return;
}

int main()
{
	int pid;
	
	pid = getpid();
	signal(SIGALRM, &wololo);
	
	while (1)
	{
		printf("%d\n",pid);
		sleep(1);
	}
	return 0;
}
