/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 20:06:51 by josgarci          #+#    #+#             */
/*   Updated: 2021/12/12 12:40:11 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	write (1, "\nEstoy dentro\n", 14);
	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], sizeof(char));
		i++;
	}
	write(1, "\nOperador, necesito una salida\n", 31);
}
