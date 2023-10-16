/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   print_d_i.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lboudjel <lboudjel@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/05/12 17:19:14 by lboudjel		  #+#	#+#			 */
/*   Updated: 2023/05/12 17:19:16 by lboudjel		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int	print_d_i(va_list args)
{
	long long int	n;

	n = va_arg(args, int);
	ft_putnbr(n);
	return (count_len(n));
}
