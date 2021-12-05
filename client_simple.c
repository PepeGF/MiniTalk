#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int	ft_atoi(const char *str);
void	ft_sendlen(char *str, int pid_server);
size_t	ft_strlen(const char *str);

int main (int argc, char *argv[])
{
	int				i;
	int				j;
	unsigned int	aux;
	int				pid_server;
	int				pid_client;
	int				len;
	(void)len;
	(void)j;

	pid_server = ft_atoi(argv[1]);
	pid_client = getpid();
	//agrupar verificación de datos en una sola función
	if (argc != 3)
	{
		write(1, "Entrada de datos incorrecta.\n", 29);
		return (1);
	}
	if (pid_server < 0)
	{
		write(1, "PID del servidor incorrecto.\n", 29);
		return (2);
	}
	i = 0;
aux = pid_client;	
	while (i < 22)
	{
		if (pid_client % 2 == 0)
			kill(pid_server, SIGUSR2);
		else
			kill(pid_server, SIGUSR1);
		pid_client >>= 1;
		i++;
		usleep(1000);
			
	}

	printf("PID_client: %d\n", aux);
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