/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:59:50 by josgarci          #+#    #+#             */
/*   Updated: 2021/12/12 22:10:51 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_len(int pid_server, int len);
static void	ft_send_str(int pid_server, char *str);

int	main(int argc, char *argv[])
{
	int				pid_server;
	int				len;

	pid_server = ft_verify_input(argc, argv);
	len = ft_strlen(argv[2]);
	write(1, "\n", 1);
	ft_send_len(pid_server, len);
	write(1, "\n", 1);
	ft_send_str(pid_server, argv[2]);
	write(1, "\n\n", 2);
	return (0);
}

static void	ft_sig_confirm(int sig, siginfo_t *info, void *ucontext)
{
	(void)sig;
	(void)info;
	(void)ucontext;
	if (sig == SIGUSR1)
		write(1, "*", 1);
	else
		write(1, "|", 1);
	return ;
}

static void	ft_send_len(int pid_server, int len)
{
	int					i;
	int					aux;
	struct sigaction	sa_confirm;

	i = 0;
	sa_confirm.sa_sigaction = &ft_sig_confirm;
	sigaction(SIGUSR1, &sa_confirm, NULL);
	aux = len;
	while (++i <= 32)
	{
		if (aux % 2 == 0)
		{
			usleep(100);
			if (kill(pid_server, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
		else
		{
			usleep(100);
			if (kill(pid_server, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
		}
		aux >>= 1;
		pause();
	}
}

static void	ft_send_char(int pid_server, char letter)
{
	int		aux;
	int		k;

	k = 0;
	aux = letter;
	while (++k <= 8)
	{
		if (aux % 2 == 0)
		{
			usleep(100);
			if (kill(pid_server, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
		else
		{
			usleep(100);
			if (kill(pid_server, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
		}
		aux >>= 1;
		pause();
	}
}

static void	ft_send_str(int pid_server, char *str)
{
	int					i;
	struct sigaction	sa_confirm;

	i = -1;
	sa_confirm.sa_sigaction = &ft_sig_confirm;
	sigaction(SIGUSR2, &sa_confirm, NULL);
	while (str[++i])
		ft_send_char(pid_server, str[i]);
	i = -1;
	while (++i < 8)
	{
		usleep(100);
		if (kill(pid_server, SIGUSR2) == -1)
			exit(EXIT_FAILURE);
		pause();
	}
}
