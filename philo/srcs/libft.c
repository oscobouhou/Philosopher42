/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:57:14 by oboutarf          #+#    #+#             */
/*   Updated: 2023/01/02 03:28:40 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_putchar(char c)
{
	int		i;

	i = write(1, &c, 1);
	(void)i;
}

void	ft_putstr(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

void	ft_putnbr(int n)
{
	if (n <= 9)
		ft_putchar(n + '0');
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int	ft_atoi(char *str)
{
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb);
}
