/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:47:44 by ealrick           #+#    #+#             */
/*   Updated: 2016/12/01 15:45:52 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ctl(char const *s, char c, int i)
{
	int nb_l;

	nb_l = 0;
	while (s[i] && s[i] != c)
	{
		nb_l++;
		i++;
	}
	return (nb_l);
}

char		**ft_strsplit(char const *s, char c)
{
	int		nb_l;
	int		i;
	int		k;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	if (!s || (tmp = (char **)malloc(sizeof(char *) * (ft_ctw(s, c) + 1)))
			== NULL)
		return (NULL);
	while (i < ft_ctw(s, c))
	{
		k = 0;
		while (s[j] == c)
			j++;
		nb_l = ft_ctl(s, c, j);
		if ((tmp[i] = (char *)malloc(sizeof(char) * nb_l + 1)) == NULL)
			return (NULL);
		while (s[j] != c && s[j] != '\0')
			tmp[i][k++] = s[j++];
		tmp[i++][k] = '\0';
	}
	tmp[ft_ctw(s, c)] = NULL;
	return (tmp);
}
