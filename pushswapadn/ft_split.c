/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:16:34 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/20 14:23:08 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_is_charset(char c, char charset)
{
	if (charset == c)
		return (1);
	return (0);
}

int	ft_is_word(char *str, char charset)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		while (str[i] && ft_is_charset(str[i], charset))
			i++;
		if (str[i] && !ft_is_charset(str[i], charset))
		{
			while (!ft_is_charset(str[i], charset) && str[i])
				i++;
			word++;
		}
	}
	return (word);
}

char	**ft_malloc_word(char *str, char charset, char **dest, int word)
{
	int	i;
	int	j;
	int	letter;

	i = 0;
	j = 0;
	while (str[i])
	{
		letter = 0;
		while (str[i] && ft_is_charset(str[i], charset))
			i++;
		while (str[i] && !ft_is_charset(str[i], charset))
		{
			letter++;
			i++;
		}
		if (j < word)
			dest[j++] = malloc((sizeof(char) * letter) + 1);
	}
	return (dest);
}

char	**ft_put_word(char *str, char charset, char **dest)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] && ft_is_charset(str[i], charset))
			i++;
		if (str[i] && !ft_is_charset(str[i], charset))
		{
			while (str[i] && !ft_is_charset(str[i], charset))
				dest[k][j++] = str[i++];
			dest[k][j] = '\0';
			k++;
		}
	}
	return (dest);
}

char	**ft_split(const char *str, char charset)
{
	char	**dest;
	int		word;
	char	*cast_str;

	cast_str = (char *)str;
	word = ft_is_word(cast_str, charset);
	dest = malloc(sizeof(char *) * (word + 1));
	if (!dest)
		return (0);
	dest = ft_malloc_word(cast_str, charset, dest, word);
	if (!dest)
		return (0);
	dest = ft_put_word(cast_str, charset, dest);
	dest[word] = NULL;
	return (dest);
}