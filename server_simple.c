#include "minitalk.h"

char	*g_str;

static void	ft_print_pid(void)
{
	write (1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 1);
	write (1, "\n", 1);
	return ;
}

static void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	i;
	static int	j;

	i = 1;
	j = 0;
	//montar el byte
	if (i == 8)
		//almacenar en str[j]

}

int	main(void)
{
	int	i;
	struct sigaction	wololo;

	ft_print_pid();
	
	while (1)
	{
		i = 0;
		g_str = malloc(size_of(char) * 5);
		pause();
		while (i < 32)
		{

		}
		i = 0;
		while (i < len)
		{

		}
	}

	return (0);
}
