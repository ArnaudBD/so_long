/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:41:50 by abiju-du          #+#    #+#             */
/*   Updated: 2021/11/04 19:43:24 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	display_error(int code)
{
	printf("so_long: ERROR - ");
	if (code == ERR_ARGC)
		printf("wrong argument count\n");
	else if (code == ERR_ARGV)
		printf("wrong file name\n");
	else if (code == ERR_OPEN)
		printf("could not open() file\n");
	else if (code == ERR_MAP)
		printf("wrong map design\n");
	else if (code == ERR_MAP_MALLOC)
		printf("Malloc error while creating map\n");
	else if (code == ERR_MAP_LINE_MALLOC)
		printf("Malloc error while creating the linked chain\n");
	else if (code == ERR_DRAWING)
		printf("Error while drawing the map\n");
	else if (code == ERR_NAME)
		printf("The file has a wrong name\n");
	else if (code == ERR_READ)
		printf("Cannot read\n");
	exit(EXIT_FAILURE);
	return (FAILURE);
}

int	terminator2(t_config *c, int code)
{
	t_list	*current;

	current = c->lines;
	if (c->img->img != NULL)
		mlx_destroy_image(c->mlx, c->img->img);
	if (c->mlx_win != NULL)
		mlx_destroy_window(c->mlx, c->mlx_win);
	if (c->mlx != NULL)
	{
		mlx_destroy_display(c->mlx);
		free(c->mlx);
	}
	while (current)
	{
		current = c->lines->next;
		free(c->lines->data);
		free(c->lines);
		c->lines = current;
	}
	if (c->map)
		free(c->map);
	if (code != 0)
		return (display_error(code));
	return (SUCCESS);
}
