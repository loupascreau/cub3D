/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:15:08 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/10 11:42:55 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

static int		ft_count_words(char *s, char c)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void		*ft_strduplicate(char *s, char *tab, int size, int i)
{
	int		j;

	j = 0;
	if (!(tab = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (j < size)
	{
		tab[j] = s[i];
		i++;
		j++;
	}
	tab[j] = '\0';
	return (tab);
}

static void		ft_malloc_words(char *s, int c, char **tab)
{
	int		i;
	int		k;
	int		size;

	i = 0;
	k = 0;
	while (s[i])
	{
		size = 0;
		while (s[i] != c && s[i] != '\0')
		{
			size++;
			i++;
		}
		if (size != 0)
		{
			tab[k] = ft_strduplicate((char *)s, tab[k], size, i - size);
			k++;
		}
		else
			i++;
	}
//	tab[k] = 0;
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;

	if (!s)
		return (NULL);
	words = ft_count_words((char *)s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * words + 1)))
		return (NULL);
	ft_malloc_words((char *)s, c, tab);
	return (tab);
}
