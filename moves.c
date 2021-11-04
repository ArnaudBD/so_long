/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:35:52 by abiju-du          #+#    #+#             */
/*   Updated: 2021/11/04 20:39:11 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	move_down(t_config *c)
{
	if (c->map[c->down.y][c->down.x] != 'P')
	{
		ft_putstr_fd("\rMoves = ", STDOUT_FILENO);
		ft_putnbr_fd(++c->moves, STDOUT_FILENO);
		if (c->map[c->down.y][c->down.x] == 'C')
			c->collected++;
		if (c->on_exit == TRUE)
		{
			c->on_exit = FALSE;
			c->map[c->player.y][c->player.x] = 'E';
		}
		else
			c->map[c->player.y][c->player.x] = '0';
		if (c->map[c->down.y][c->down.x] == 'E')
			c->on_exit = TRUE;
		c->map[c->down.y][c->down.x] = 'P';
		c->player = c->down;
	}
}

void	move_up(t_config *c)
{
	if (c->map[c->up.y][c->up.x] != 'P')
	{
		ft_putstr_fd("\rMoves = ", STDOUT_FILENO);
		ft_putnbr_fd(++c->moves, STDOUT_FILENO);
		if (c->map[c->up.y][c->up.x] == 'C')
			c->collected++;
		if (c->on_exit == TRUE)
		{
			c->on_exit = FALSE;
			c->map[c->player.y][c->player.x] = 'E';
		}
		else
			c->map[c->player.y][c->player.x] = '0';
		if (c->map[c->up.y][c->up.x] == 'E')
			c->on_exit = TRUE;
		c->map[c->up.y][c->up.x] = 'P';
		c->player = c->up;
	}
}

void	move_left(t_config *c)
{
	if (c->map[c->left.y][c->left.x] != 'P')
	{
		ft_putstr_fd("\rMoves = ", STDOUT_FILENO);
		ft_putnbr_fd(++c->moves, STDOUT_FILENO);
		if (c->map[c->left.y][c->left.x] == 'C')
			c->collected++;
		c->map[c->player.y][c->player.x] = '0';
		if (c->on_exit == TRUE)
		{
			c->on_exit = FALSE;
			c->map[c->player.y][c->player.x] = 'E';
		}
		else
			c->map[c->player.y][c->player.x] = '0';
		if (c->map[c->left.y][c->left.x] == 'E')
			c->on_exit = TRUE;
		c->map[c->left.y][c->left.x] = 'P';
		c->player = c->left;
	}
}

void	move_right(t_config *c)
{
	if (c->map[c->right.y][c->right.x] != 'P')
	{
		ft_putstr_fd("\rMoves = ", STDOUT_FILENO);
		ft_putnbr_fd(++c->moves, STDOUT_FILENO);
		if (c->map[c->right.y][c->right.x] == 'C')
			c->collected++;
		c->map[c->player.y][c->player.x] = '0';
		if (c->on_exit == TRUE)
		{
			c->on_exit = FALSE;
			c->map[c->player.y][c->player.x] = 'E';
		}
		else
			c->map[c->player.y][c->player.x] = '0';
		if (c->map[c->right.y][c->right.x] == 'E')
			c->on_exit = TRUE;
		c->map[c->right.y][c->right.x] = 'P';
		c->player = c->right;
	}
}

void	move(t_config *c, char keycode)
{
	c->down = c->player;
	c->up = c->player;
	c->left = c->player;
	c->right = c->player;
	if (c->map[c->up.y - 1][c->up.x] != '1')
		c->up.y = c->player.y - 1;
	if (c->map[c->down.y + 1][c->down.x] != '1')
		c->down.y = c->player.y + 1;
	if (c->map[c->right.y][c->right.x + 1] != '1')
		c->right.x = c->player.x + 1;
	if (c->map[c->left.y][c->left.x - 1] != '1')
		c->left.x = c->player.x - 1;
	if (keycode == 's')
		move_down(c);
	else if (keycode == 'w')
		move_up(c);
	else if (keycode == 'a')
		move_left(c);
	else if (keycode == 'd')
		move_right(c);
}
