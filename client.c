/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:59:50 by josgarci          #+#    #+#             */
/*   Updated: 2021/12/09 22:07:21 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_verify_input(int argc, char **argv);
static void	ft_send_len(int pid_server, int len);
static void	ft_send_str(int pid_server, char *str);

int	main(int argc, char *argv[])
{
	int				pid_server;
	int				len;

	pid_server = ft_verify_input(argc, argv);
	len = ft_strlen(argv[2]);
//write (1, "XXXX\n", 5);
usleep(1);
	ft_send_len(pid_server, len);
usleep(10);
	ft_send_str(pid_server, argv[2]);
	return (0);
}

static void	ft_sig_confirm(int sig, siginfo_t *info, void *ucontext)
{
	(void)sig;
	(void)info;
	(void)ucontext;
	write(1, "*", 1);
	return ;
}

static void	ft_send_len(int pid_server, int len)
{
	int					i;
	int					aux;
	struct sigaction	sa_confirm;

	i = 1;
	sa_confirm.sa_sigaction = &ft_sig_confirm;
	sigaction(SIGUSR1, &sa_confirm, NULL);
	aux = len;
	while (i <= 32)
	{
	//	write(1, "/", 1);
		if (aux % 2 == 0)
		{
			usleep(1);
			kill(pid_server, SIGUSR2);
		}
		else
		{
			usleep(1);
			kill(pid_server, SIGUSR1);
		}
		aux >>= 1;
		i++;
		pause();
	}
}

static void	ft_send_str(int pid_server, char *str)
{
	int					i;
	int					j;
	int					aux;
	struct sigaction	sa_confirm;
//write (1, "\n", 1);
	i = 0;
	sa_confirm.sa_sigaction = &ft_sig_confirm;
	sigaction(SIGUSR1, &sa_confirm, NULL);
//	write(1, "\n", 1);
	while (str[i])
	{
		aux = str[i];
		j = 0;
		while (j < 8)
		{
			//ft_putnbr_fd(aux, 1);
		if (aux % 2 == 0)
		{
	usleep(1);
			kill(pid_server, SIGUSR2);
			//write (1, " - Enviado un 0\n", 16);
		}
		else
		{
	usleep(1);
			kill(pid_server, SIGUSR1);
			//write (1, " - Enviado un 1\n", 16);
		}
		aux >>= 1;
		j++;
		pause();
		}
		//write (1, "\n", 1);
		i++;
	}
}

static int	ft_verify_input(int argc, char **argv)
{
	int	pid_server;

	if (argc != 3)
	{
		write(1, "Entrada de datos incorrecta.\n", 29);
		exit(1);
	}
	pid_server = ft_atoi(argv[1]);
	if (pid_server < 0)
	{
		write(1, "PID del servidor incorrecto.\n", 29);
		exit (1);
	}
	return (pid_server);
}
