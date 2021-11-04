/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:44:45 by abiju-du          #+#    #+#             */
/*   Updated: 2021/11/04 19:45:43 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		i++;
	}
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (((unsigned char)s1[i] != '\0')
		&& ((unsigned char)s2[i] != '\0')
		&& (i < n - 1))
	{
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
		{
			i++;
		}
		else
		{
			break ;
		}
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
