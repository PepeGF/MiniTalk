/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_simple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:59:53 by josgarci          #+#    #+#             */
/*   Updated: 2021/12/09 13:50:58 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (i % 8 == 0)
		g_str[j++] = c;
	i++;
	if (i == 33)
		i = 1;
	kill(info->si_pid, SIGUSR1);
	return ;
}

static void	sig_handler_char(int sig, siginfo_t *info, void *ucontext)
{
	static int	i = 1;
	static int	j = -1;
	static int	c;

write (1, "\n", 1);
ft_putnbr_fd(i, 1);
	(void)ucontext;
	if (sig == SIGUSR1)
	{
		c >>= 1;
		c += 128;
		write(1, " - Recibidido un 1", 18);
	}
	else
	{
		c >>= 1;
		write(1, " - Recibidido un 0", 18);
	}
	if (i % 8 == 0)
	{
		g_str[++j] = (char)c;
//		ft_putchar_fd(g_str[j], 1);
	}
	i++;
	kill(info->si_pid, SIGUSR1);
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
		i = 1;
		g_str = malloc(sizeof(char) * 5);
		sa_len.sa_flags = SA_SIGINFO;
		sa_len.sa_sigaction = &sig_handler_len;
		sigaction(SIGUSR1, &sa_len, NULL);
		sigaction(SIGUSR2, &sa_len, NULL);
		while (i <= 32)
		{	//write(1, "x\n", 2);
			pause();
			i++;
		}
		len_str = (int)g_str[3] * 16777216 + (int)g_str[2] * 65536
			+ (int)g_str[1] * 256 + (int)g_str[0];
		free(g_str);
/*	write(1, "\n", 1);
	ft_putnbr_fd(len_str, 1);
	write(1, "\n", 1);
*/		g_str = malloc(sizeof(char) * (len_str + 1));
		g_str[len_str] = 0;
		sa_char.sa_flags = SA_SIGINFO;
		sa_char.sa_sigaction = &sig_handler_char;
		sigaction(SIGUSR1, &sa_char, NULL);
		sigaction(SIGUSR2, &sa_char, NULL);
		i = 1;
		//write (1, "XXXX\n", 5);
		while (i <= len_str * 8)
		{
			pause();
			if (i % 8 == 0)
				ft_putstr_fd(g_str, 1);
			i++;
		}
		ft_putstr_fd(g_str, 1);
		free (g_str);
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
