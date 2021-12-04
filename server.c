#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>

void	ft_fill_byte(int bit, int num)
{
	(void)bit;
	(void)num;
	return ;
}

int	wololo (int sig)
{
	(void)sig;
	write(1, "Recibido un 1\n", 14);
	return (1);
}

int wololo2 (int sig)
{
	(void)sig;
	write(1, "Recibido un 0\n", 14);
	return (0);
}


int main()
{
	int pid;
	int	i;
	int letra;
	
	i = 0;
	pid = getpid();
	signal(SIGUSR1, &wololo);
	signal(SIGUSR2, &wololo2);
	printf("Server PID: %d\n", pid);
	while (i < 8)
	{
		pause();
		i++;
	}
	return 0;
}
