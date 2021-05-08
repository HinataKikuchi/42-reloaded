/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:36:52 by hkikuchi          #+#    #+#             */
/*   Updated: 2020/12/04 11:23:54 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"
#include "./libft/libft.h"
#include <stdio.h>

static int		ft_count_file(const char *pathname)
{
	DIR				*dir;
	struct dirent	*dp;
	int				res;

	if (!(dir = opendir(pathname)))
		return (-1);
	if (!(dp = readdir(dir)))
		return (-1);
	res = 0;
	while (dp)
	{
		if (*dp->d_name != '.')
			res++;
		dp = readdir(dir);
	}
	closedir(dir);
	return (res);
}

static t_dir	*ft_set_array(DIR *dir, struct dirent *dp, int f_count)
{
	t_dir		*array;
	struct stat	buf;

	array = malloc(sizeof(t_dir) * f_count);
	(void)buf;
	while (dp && dir)
	{
		if (*dp->d_name != '.')
		{
			if (!(lstat(dp->d_name, &buf)) && --f_count >= 0)
			{
				array[f_count].name = dp->d_name;
				array[f_count].time = buf.st_mtime;
				array[f_count].n_time = buf.st_mtimespec.tv_nsec;
			}
			else
				perror("STAT ERROR");
		}
		dp = readdir(dir);
	}
	closedir(dir);
	return (array);
}

static t_dir	*ft_read(int f_count)
{
	DIR				*dir;
	struct dirent	*dp;
	t_dir			*array;

	if (!(dir = opendir("./")))
		return (NULL);
	if (!(dp = readdir(dir)))
		return (NULL);
	array = malloc(sizeof(t_dir) * f_count);
	array = ft_set_array(dir, dp, f_count);
	return (array);
}

static void		ft_print(t_dir *array, int a_size)
{
	int	i;

	i = 0;
	while (i < a_size)
	{
		ft_putstr_fd(array[i].name, 1);
		write(1, "\n", 1);
		i++;
	}
}

void			ft_mini_ls(void)
{
	t_dir	*array;
	int		i;

	if ((i = ft_count_file("./")) == -1)
	{
		perror("CANNOT OPEN OR READ DIR");
		return ;
	}
	array = malloc(sizeof(t_dir) * i);
	if (!(array = ft_read(i)))
		perror("CANNOT OPEN OR READ DIR");
	array = ft_bubble(array, i);
	ft_print(array, i);
}
