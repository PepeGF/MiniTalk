#include "minitalk.h"

void	ft_sendlen(char *str, int pid_server);
static int	ft_verify_input(int argc, char argv[2]);
static void	ft_send_len(int pid_server, int len);

int main (int argc, char *argv[])
{
	int				i;
	int				pid_server;
	int				len;

	pid_server = ft_verify_input(argc, argv[2]);
	len = ft_strlen(argv[2]);
	ft_send_len(pid_server, len);
}
static void	ft_send_len(int pid_server, int len);
{
	int	i;
	int	aux;

	i = 1;
	aux = len;
	while (i <= 32)
	{
		if (aux % 2 == 0)
			kill(pid_server, SIGUSR2);
		else
			kill(pid_server, SIGUSR1);
		aux >>= 1;
		i++;
		//pause();
		usleep(1000);
	}


}

static int	ft_verify_input(int argc, char argv[2])
{
	int	pid_server;

	if (argc != 3)
	{
		write(1, "Entrada de datos incorrecta.\n", 29);
		exit();
	}
	pid_server = ft_atoi(argv[1]);
	if (pid_server < 0)
	{
		write(1, "PID del servidor incorrecto.\n", 29);
		exit ();
	}
	return (pid_server);
}

/*
	ft_sendlen(argv[2], pid_server);
	write(1, "----------\n", 11);
	i = 0;
	while (argv[2][i])
	{
		aux = (unsigned int)argv[2][i];
		j = 0;
		while (j < 8)
		{
			if (aux % 2 == 0)
			{
				kill(pid_server, SIGUSR2);
				write(1, "Enviado un 0\n", 13);
			}
			else
			{
				kill(pid_server,SIGUSR1);
				write(1, "Enviado un 1\n", 13);
			}
			usleep(10);
			aux = aux >> 1;
			j++;
		}
		i++;
	}
*/
	return (0);
}

void	ft_sendlen(char *str, int pid_server)
{
	int	i;
	int	aux;
	int	len;

	i = 0;
	len = ft_strlen(str);
	aux = len;
	while (i < 8)
	{
		if (aux % 2 == 0)
		{
			kill(pid_server, SIGUSR2);
			write(1, "Enviado un 0\n", 13);
		}
		else
		{
			kill(pid_server,SIGUSR1);
			write(1, "Enviado un 1\n", 13);
		}
		usleep(1000);
		aux = aux >> 1;
		i++;
	}
	write (1, "Len enviada\n", 12);
}