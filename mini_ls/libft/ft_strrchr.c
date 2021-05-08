/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:38:39 by hkikuchi          #+#    #+#             */
/*   Updated: 2020/11/26 17:16:56 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *buf;

	buf = (char *)(s + ft_strlen(s));
	while (buf != s)
	{
		if (*buf == (char)c)
			return (buf);
		buf--;
	}
	if (*buf == (char)c)
		return (buf);
	return (NULL);
}
