/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:46:07 by abiju-du          #+#    #+#             */
/*   Updated: 2021/11/04 19:47:03 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, const char *argv[])
{
	t_data		img;
	t_config	c;

	c.img = &img;
	if (init_struct_config(&c) == FAILURE)
		return (FAILURE);
	if (parsing(argc, argv, &c) == FAILURE)
		return (FAILURE);
	if (create_map(&c) != SUCCESS)
		return (FAILURE);
	if (start_mlx(&c) != SUCCESS)
		return (FAILURE);
	map_drawer(&c);
	mlx_hook(c.mlx_win, 33, 0L, cross_clicked, &c);
	if (mlx_key_hook(c.mlx_win, key_hook, &c) == FAILURE)
		return (FAILURE);
	mlx_loop_hook(c.mlx, nada, NULL);
	mlx_loop(c.mlx);
	terminator2(&c, 0);
	return (1);
}
