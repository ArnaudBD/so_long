/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:41:50 by abiju-du          #+#    #+#             */
/*   Updated: 2021/11/08 12:29:09 by abiju-du         ###   ########.fr       */
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

void	free_reachable_bytes(t_config *c)
{
	if (c->map)
		free(c->map);
	if (c->txts->wl_txt)
		free(c->txts->wl_txt);
	if (c->txts->fl_txt)
		free(c->txts->fl_txt);
	if (c->txts->key_txt)
		free(c->txts->key_txt);
	if (c->txts->kt_txt)
		free(c->txts->kt_txt);
	if (c->txts->dr_txt)
		free(c->txts->dr_txt);
	if (c->sizex)
		free(c->sizex);
	if (c->sizey)
		free(c->sizey);
	if (c->txts)
		free(c->txts);
}

void	imgs_distroyer(t_config *c)
{
	if (c->img->img != NULL)
		mlx_destroy_image(c->mlx, c->img->img);
	if (c->txts->dr_txt->img != NULL)
		mlx_destroy_image(c->mlx, c->txts->dr_txt->img);
	if (c->txts->fl_txt->img != NULL)
		mlx_destroy_image(c->mlx, c->txts->fl_txt->img);
	if (c->txts->wl_txt->img != NULL)
		mlx_destroy_image(c->mlx, c->txts->wl_txt->img);
	if (c->txts->key_txt->img != NULL)
		mlx_destroy_image(c->mlx, c->txts->key_txt->img);
	if (c->txts->kt_txt->img != NULL)
		mlx_destroy_image(c->mlx, c->txts->kt_txt->img);
	if (c->mlx_win != NULL)
		mlx_destroy_window(c->mlx, c->mlx_win);
}

int	terminator2(t_config *c, int code)
{
	t_list	*current;

	current = c->lines;
	imgs_distroyer(c);
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
	free_reachable_bytes(c);
	if (code != 0)
		return (display_error(code));
	write(1, "\n", 1);
	return (SUCCESS);
}
