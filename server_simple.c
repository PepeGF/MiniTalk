#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_data
{
	int		pid_client;
	int		len_str;
	char	*str;
}	t_data;
char	*str;
int		pid_client;

void	ft_confirmation()
{
	return ;
}


void	ft_fill_byte(int bit)
{
	int	index;

	pid_client >>= 1;
	if (bit == 1)
		pid_client += 2097152;//2^18

	(void)index;
	return ;
}

void	handler_sig1 (int sig)
{
	(void)sig;
	write(1, "Recibido un 1\n", 14);
	ft_fill_byte(1);
	return ;
}

void	handler_sig2 (int sig)
{
	(void)sig;
	write(1, "Recibido un 0\n", 14);
	ft_fill_byte(0);
	return ;
}


int main()
{
	int pid;
	int	i;
	int letra;
	int	len;

	(void)letra;
	(void)len;
	
	i = 0;
	pid = getpid();
	signal(SIGUSR1, &handler_sig1);
	signal(SIGUSR2, &handler_sig2);
	printf("Server PID: %d\n", pid);

	while (i < 22)
	{
		pause();
		i++;
	}
	printf("%d\n", pid_client);
/*	while (i  >= 0)
	{
		pause();
		if (i % 8 == 7)//esto son paquetes de 8 bits
		{
			if (i == 7)//primer byte

		}

		i++;
	}
*/
	return 0;
}
