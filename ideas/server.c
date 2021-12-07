#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>


typedef struct s_data
{
	int		pid_client;
	int		len_str;
	char	*str;
	int		i;
}	t_data;

void	ft_confirmation();
void	ft_fill_byte(int bit);
void	handler_sig0 (int sig);
void	handler_sig1 (int sig);

int main()
{
	int pid;
	struct sigaction sa0;
	struct sigaction sa1;
	
	pid = getpid();
	printf("Server PID: %d\n", pid);
//sustituir por putnbr
	while (1)
	{
		sa.sa0_handler = &handler_sig0;

		sa.sa1_handler = &handler_sig1;
		while (i < 22)
		{
			pause();
			
		}
		if (i % 8 == 7)//esto son paquetes de 8 bits
		{
			if (i == 7)//primer byte

		}

		i++;
	}
	return 0;
}

void	ft_confirmation()
{
	return ;
}

void	ft_fill_byte(int bit)
{
	(void)bit;
	int	index;

	(void)index;

//enviar señal de recepcion.
	return ;
}

void	handler_sig1 (int sig)
{
	(void)sig;
	write(1, "Recibido un 1\n", 14);
	ft_fill_byte(1);
	return ;
}

void	handler_sig0 (int sig)
{
	(void)sig;
	write(1, "Recibido un 0\n", 14);
	ft_fill_byte(0);
	return ;
}
