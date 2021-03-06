/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:32:40 by josgarci          #+#    #+#             */
/*   Updated: 2021/12/12 22:16:23 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	*g_str;

static void	ft_sig_handler_len(int sig, siginfo_t *info, void *ucontext)
{
	static int			i = 1;
	static int			j;
	static unsigned int	c;

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
	if (i % 33 == 0)
	{
		i = 1;
		j = 0;
	}
	usleep(100);
	if (kill(info->si_pid, SIGUSR1) == -1)
		exit(EXIT_FAILURE);
	return ;
}

static int	ft_receive_len(void)
{
	int					i;
	unsigned int		len_str;
	struct sigaction	sa_len;

	i = 0;
	len_str = 0;
	g_str = malloc(4);
	if (!g_str)
		exit(EXIT_FAILURE);
	sa_len.sa_flags = SA_SIGINFO;
	sa_len.sa_sigaction = &ft_sig_handler_len;
	sigaction(SIGUSR1, &sa_len, NULL);
	sigaction(SIGUSR2, &sa_len, NULL);
	while (++i <= 32)
		pause();
	len_str = (int)g_str[3] * 16777216 + (int)g_str[2] * 65536
		+ (int)g_str[1] * 256 + (int)g_str[0];
	free(g_str);
	return (len_str);
}

static void	ft_sig_handler_str(int sig, siginfo_t *info, void *ucontext)
{
	static int	i = 0;
	static int	j = -1;
	static int	c;

	(void)ucontext;
	if (sig == SIGUSR1)
	{
		c >>= 1;
		c += 128;
	}
	else
		c >>= 1;
	if (++i % 8 == 0)
	{
		g_str[++j] = (char)c;
		if ((char)c == '\0')
		{
			j = -1;
		}
	}
	usleep(100);
	if (kill(info->si_pid, SIGUSR2) == -1)
		exit(EXIT_FAILURE);
	return ;
}

static void	ft_receive_str(int len_str)
{
	int					i;
	struct sigaction	sa_char;

	g_str = malloc(sizeof(char) * (len_str + 1));
	if (!g_str)
		exit(EXIT_FAILURE);
	sa_char.sa_flags = SA_SIGINFO;
	sa_char.sa_sigaction = &ft_sig_handler_str;
	sigaction(SIGUSR1, &sa_char, NULL);
	sigaction(SIGUSR2, &sa_char, NULL);
	i = 0;
	while (++i <= (len_str + 1) * 8)
	{
		pause();
	}
	return ;
}

int	main(void)
{
	int	len_str;

	write (1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 1);
	write (1, "\n", 1);
	while (1)
	{
		len_str = ft_receive_len();
		ft_receive_str(len_str);
		ft_putstr_fd(g_str, 1);
		free(g_str);
		g_str = NULL;
	}
	return (0);
}
