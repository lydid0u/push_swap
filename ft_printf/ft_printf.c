/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printf.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lboudjel <lboudjel@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/05/12 12:23:53 by lboudjel		  #+#	#+#			 */
/*   Updated: 2023/05/12 12:23:53 by lboudjel		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	check(char c, va_list args)
{
	if (c == '%')
		return (print_pourcent());
	if (c == 'c')
		return (print_c(args));
	if (c == 'p')
		return (print_p(args));
	if (c == 's')
		return (print_s(args));
	if (c == 'd' || c == 'i')
		return (print_d_i(args));
	if (c == 'u')
		return (print_u(args));
	if (c == 'x')
		return (print_x(args));
	if (c == 'X')
		return (print_xx(args));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count = count + check(str[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

/*int main(void)
{
	char c = 'a';
	char *s = "Hello, World!";
	void *p = &s;
	int d = -42;
	unsigned int u = 42;
	unsigned int x = 0xDEADBEEF;

	ft_printf("%%c: %c\n", c);
	ft_printf("%%s: %s\n", s);
	ft_printf("%%p: %p\n", p);
	ft_printf("%%d: %d\n", d);
	ft_printf("%%i: %i\n", d);
	ft_printf("%%u: %u\n\n", u);
	ft_printf("%%x: %x\n", x);
	ft_printf("%%X: %X\n\n", x);

	printf("%%c: %c\n", c);
	printf("%%s: %s\n", s);
	printf("%%p: %p\n", p);
	printf("%%d: %d\n", d);
	printf("%%i: %i\n", d);
	printf("%%u: %u\n", u);
	printf("%%x: %x\n", x);
	printf("%%X: %X\n", x);

	ft_printf("mon print f : %c\n", 'a');
	printf("print f : %c\n", 'a');

	ft_printf("%%p: %p\n", s);
	printf("%%p: %p\n", s);

	ft_printf("mon print f : salut %s okok %s\n", "wsh", "ok");
	printf("print f : salut %s okok %s\n", "wsh", "ok");

	ft_printf("mon print f : salut %%\n");
	printf("print f : salut %%\n");

	ft_printf("mon print f : salut %d\n", 0);
	printf("print f : salut %d\n", 0);

	ft_printf("mon print f : salut %i\n", 10);
	printf("print f : salut %i\n", 10);

	ft_printf("mon print f : salut %u\n", 10);
	printf("print f : salut %u\n", 10);

	ft_printf("mon print f : salut %x\n", 0x3a);
	printf("print f : salut %x\n", 0x3a);

	ft_printf("mon print f : salut %X\n", 0x3A);
	printf("print f : salut %X\n", 0x3A);
}*/