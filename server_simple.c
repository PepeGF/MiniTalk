#include "minitalk.h"

char	*g_str;

static void	ft_print_pid(void)
{
	write (1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 1);
	write (1, "\n", 1);
	return ;
}

static void	sig_handler_len(int sig, siginfo_t *info, void *ucontext)
{
	static int	i = 1;
	static int	j;
	static char	c;

	(void)ucontext;
	ft_putnbr_fd(i, 1);
	if (sig == SIGUSR1)
	{
		c >>= 1;
		c += 128;
	//	write(1, "Recibido 1", 10);
	}
	else
	{
		c >>= 1;
	//	write(1, "Recibido 0", 10);
	}
	//kill(info->si_pid, SIGUSR1);
	(void)info;
	if (i % 8 == 0)
	{
		write (1, "-", 1);
		ft_putnbr_fd((int)c, 1);
		write (1, "-", 1);
		g_str[j] = c;
		
		j++;
	}
	i++;
	if (i == 32)
		i = 1;
	return ;
}

int	main(void)
{
	int	i;
	struct sigaction	sa_len;
//	struct sigaction	sa_char;

	ft_print_pid();
	
	while (1)
	{
		i = 0;
		g_str = malloc(sizeof(char) * 5);
		sa_len.sa_flags = SA_SIGINFO;
		sa_len.sa_sigaction = &sig_handler_len;
		g_str[4] = 0;
		sigaction(SIGUSR1, &sa_len, NULL);
		sigaction(SIGUSR2, &sa_len, NULL);
		while (i < 32)
		{
			pause();
		}
/*		i = 0;
		while (i < len)
		{
			i++;
		}
*/	}

	return (0);
}
