/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printf.h										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lboudjel <lboudjel@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/05/12 17:19:37 by lboudjel		  #+#	#+#			 */
/*   Updated: 2023/05/12 17:19:37 by lboudjel		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		check(char c, va_list args);

int		print_c(va_list args);
int		print_d_i(va_list args);
int		print_pourcent(void);
int		print_s(va_list args);
int		print_u(va_list args);
int		print_x(va_list args);
int		print_p(va_list args);
int		print_xx(va_list args);

int		count_len(long long int n);
int		count_len_u(unsigned int n);
int		count_base(unsigned long long int n);
int		ft_strlen(char *str);

int		ft_putstr(const char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putnbr_positive(unsigned int n);
void	ft_putnbr_base(unsigned long long int nb, const char *base);

#endif