/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_put.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lboudjel <lboudjel@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/05/12 12:26:00 by lboudjel		  #+#	#+#			 */
/*   Updated: 2023/05/12 15:34:20 by lboudjel		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_putstr(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * -1);
	}
	else if (nb <= 9)
	{
		ft_putchar(nb + '0');
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	ft_putnbr_positive(unsigned int n)
{
	unsigned long long int	nb;

	nb = n;
	if (nb > 9)
	{
		ft_putnbr_positive(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb % 10 + '0');
}

/*
putnbr_base :  tu divises par 16 : 
42/16 = 2 donc dans la base hexa 0123456789abcdef 
on va a la 2e position qui est 2 puis 
il reste 10 (42 - 32) donc on va a la 10e position qui est un a
donc 42 en hexa = 2a
*/

void	ft_putnbr_base(unsigned long long int nb, const char *base)
{
	if (nb >= 16)
	{
		ft_putnbr_base(nb / 16, base);
		ft_putchar(base[nb % 16]);
	}
	else
		ft_putchar(base[nb]);
}
