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

	pid_server = ft_atoi(argv[1]);
	pid_client = getpid();
	pid_client *= 1;
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
