/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 01:34:00 by hkikuchi          #+#    #+#             */
/*   Updated: 2020/12/04 23:38:38 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"
#include "./libft/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*s1_t;
	unsigned char	*s2_t;

	s1_t = (unsigned char*)s1;
	s2_t = (unsigned char*)s2;
	while (*s1_t != '\0' || *s2_t != '\0')
	{
		if (*s1_t != *s2_t)
			return (*s1_t - *s2_t);
		s1_t++;
		s2_t++;
	}
	return (0);
}

void	ft_swap(t_dir *a, t_dir *b)
{
	t_dir tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_dir	*ft_bubble(t_dir *ans, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size - 1)
	{
		j = size - 1;
		while (j >= i + 1)
		{
			if (ans[j].time < ans[j - 1].time)
				ft_swap(&ans[j], &ans[j - 1]);
			else if ((ans[j].time == ans[j - 1].time)
					&& (ans[j].n_time < ans[j - 1].n_time))
				ft_swap(&ans[j], &ans[j - 1]);
			else if ((ans[j].n_time == ans[j - 1].n_time)
					&& (ft_strcmp(ans[j].name, ans[j - 1].name) < 0))
				ft_swap(&ans[j], &ans[j - 1]);
			j--;
		}
		i++;
	}
	return (ans);
}
