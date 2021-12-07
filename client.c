#include "minitalk.h"

static int	ft_verify_input(int argc, char argv[2])

int	main(int argc, char *argv[])
{
	int		pid_server;
	int		i;
	int		aux;

	pid_server = ft_verify_input(argc, argv[2]);
	i = 1;
	while (argv[2][i])
	{
		aux = (int)argv[2][i];
		if (aux % 2 == 0)
			kill(pid_server, SIGUSR2);
		else
			kill(pid_server, SIGUSR1);
		aux >>= 1;
		i++;
		usleep(1000);
		//pause();
	}
	i = 1;
	while (i <= 8)
	{
		kill(pid_server, SIGUSR2);
		usleep(1000);
		//enviar señal 0
	}
	return (0);
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
