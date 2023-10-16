/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   print_xx.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lboudjel <lboudjel@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/05/12 17:19:05 by lboudjel		  #+#	#+#			 */
/*   Updated: 2023/05/12 17:19:09 by lboudjel		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int	print_xx(va_list args)
{
	unsigned long long int	n;

	n = (unsigned long long int)va_arg(args, unsigned int);
	ft_putnbr_base(n, "0123456789ABCDEF");
	return (count_base(n));
}
