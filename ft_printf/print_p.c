/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   print_p.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lboudjel <lboudjel@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/05/12 17:18:19 by lboudjel		  #+#	#+#			 */
/*   Updated: 2023/05/12 17:18:30 by lboudjel		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(va_list args)
{
	unsigned long	n;

	n = (unsigned long)va_arg(args, void *);
	if (n == 0)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	ft_putnbr_base(n, "0123456789abcdef");
	return (count_base(n) + 2);
}
