/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:48:30 by hkikuchi          #+#    #+#             */
/*   Updated: 2020/11/26 19:25:21 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_front(const char *s, char const *set)
{
	size_t i;

	i = 0;
	while (*(s + i) != '\0')
	{
		if (!ft_strchr(set, *(s + i)))
			break ;
		i++;
	}
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char		*ans;
	size_t		i;
	size_t		j;

	if (!s1)
		return (NULL);
	else if (!set)
		return (ft_strdup(s1));
	i = 0;
	j = ft_strlen(s1);
	i = ft_count_front(s1, set);
	while (j > i)
	{
		if (!ft_strchr(set, *(s1 + j - 1)))
			break ;
		j--;
	}
	if (!(ans = (char *)ft_calloc(((j - i) + 1), sizeof(char))))
		return (NULL);
	ft_memcpy(ans, s1 + i, (j - i));
	return (ans);
}
