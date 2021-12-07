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
	static int	c;

	(void)ucontext;
	if (sig == SIGUSR1)
	{
		c >>= 1;
		c += 128;
	}
	else
		c >>= 1;
	//kill(info->si_pid, SIGUSR1);
	(void)info;
	if (i % 8 == 0)
		g_str[j++] = c;
	i++;
	if (i == 33)
		i = 1;
	return ;
}

static void	sig_handler_char(int sig, siginfo_t *info, void *ucontext)
{
	//es posible que se puedan juntar las dos funciones en una sola
	static int	i = 1;
	static int	j;
	static int	c;

	(void)ucontext;
	if (sig == SIGUSR1)
	{
		c >>= 1;
		c += 128;
	}
	return ;
}

int	main(void)
{
	int					i;
	int					len_str;
	struct sigaction	sa_len;
	struct sigaction	sa_char;

	ft_print_pid();
	while (1)
	{
		i = 0;
		g_str = malloc(sizeof(char) * 5);
		sa_len.sa_flags = SA_SIGINFO;
		sa_len.sa_sigaction = &sig_handler_len;
		sigaction(SIGUSR1, &sa_len, NULL);
		sigaction(SIGUSR2, &sa_len, NULL);
		while (i++ < 32)
			pause();
		len_str = (int)g_str[3] * 16777216 + (int)g_str[2] * 65536
			+ (int)g_str[1] * 256 + (int)g_str[0];
		free(g_str);
		g_str = calloc(sizeof(char) * (len_str + 1));
		sa_char.flags = SA_SIGINFO;
		sa_char.sa_sigaction = &sig_handler_char;
		sigaction(SIGUSR1, &sa_char, NULL);
		sigaction(SIGUSR2, &sa_char, NULL);
		i = 0;
		while (i++ < len)
			pause();
		free (g_str);
		ft_putstr_fd(g_str, 1);
	}
	return (0);
}


		//write(1, "---\n", 4);
		//ft_putnbr_fd(c, 1);
		//
		//ft_putnbr_fd(c, 1);

/*		i = 0;
		while (i < len)
		{
			i++;
		}
*/	
