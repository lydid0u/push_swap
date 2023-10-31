/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:30:18 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/31 17:31:18 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	countword(const char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] != '\0' && s[i] == c)
		{
			i++;
		}
		if (s[i] != '\0')
			len++;
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
		}
	}
	return (len);
}

//copy une str jusqua un caratere donne ou la fin dans un malloc et le renvoi
char	*copystr(const char *original, char c)
{
	char	*copy;
	int		i;

	i = 0;
	while (original[i] != '\0' && original[i] != c)
		i++;
	copy = malloc(sizeof(char) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (original[i] && original[i] != c)
	{
		copy[i] = original[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	**ft_fill_tab(char const *s, char c, char **tab, int len_tab)
{
	int	i;

	i = 0;
	while (i != len_tab)
	{
		while (*s != '\0' && *s == c)
			s++;
		tab[i] = copystr(s, c);
		if (!tab[i])
		{
			i--;
			while (i >= 0)
				free(tab[i--]);
			return (NULL);
		}
		while (*s != '\0' && *s != c)
			s++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		len_tab;
	char	**tab;

	len_tab = countword(s, c);
	if (!s)
		return (NULL);
	tab = malloc (sizeof(char *) * (len_tab + 1));
	if (!tab)
		return (NULL);
	return (ft_fill_tab(s, c, tab, len_tab));
}
