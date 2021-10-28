# include "includes/so_long.h"

void    set_possible_moves(t_config *c)
{
    c->down = c->player;
    c->up = c->player;
    c->left = c->player;
    c->right = c->player;
    if (c->map[c->up.y - 1][c->up.x] != '1')
        c->up.y = c->player.y - 1;
    if (c->map[c->down.y +1][c->down.x] != '1')
        c->down.y = c->player.y + 1;
    if (c->map[c->right.y][c->right.x + 1] != '1')
        c->right.x = c->player.x + 1;
    if (c->map[c->left.y][c->left.x - 1] != '1')
        c->left.x = c->player.x - 1;
    if (c->collected == c->collectibles)
        c->map[c->exit.y][c->exit.x] = 'O';
}

void    move(t_config *c, char keycode)
{
    set_possible_moves(c);
    if (keycode == 's')
    {
        if (c->map[c->down.y][c->down.x] == '0' 
        || c->map[c->down.y][c->down.x] == 'C'
        || c->map[c->down.y][c->down.x] == 'O')

        {
            if (c->map[c->down.y][c->down.x] == 'C')
                c->collected++;
            c->map[c->player.y][c->player.x] = '0';
            c->map[c->down.y][c->down.x] = 'P';
            c->player = c->down;
        }
    }
    else if (keycode == 'w')
    {
        if (c->map[c->up.y][c->up.x] == '0' 
        || c->map[c->up.y][c->up.x] == 'C'
        || c->map[c->up.y][c->up.x] == 'O')
        {
            if (c->map[c->up.y][c->up.x] == 'C')
                c->collected++;
            c->map[c->player.y][c->player.x] = '0';
            c->map[c->up.y][c->up.x] = 'P';
            c->player = c->up;
        }
    }
    else if (keycode == 'a')
    {
        if (c->map[c->left.y][c->left.x] == '0' 
        || c->map[c->left.y][c->left.x] == 'C'
        || c->map[c->left.y][c->left.x] == 'O')
        {
            if (c->map[c->left.y][c->left.x] == 'C')
                c->collected++;
            c->map[c->player.y][c->player.x] = '0';
            c->map[c->left.y][c->left.x] = 'P';
            c->player = c->left;
        }
    }
    else if (keycode == 'd')
    {
        if (c->map[c->right.y][c->right.x] == '0' 
        || c->map[c->right.y][c->right.x] == 'C'
        || c->map[c->right.y][c->right.x] == 'O')
        {
            if (c->map[c->right.y][c->right.x] == 'C')
                c->collected++;
            c->map[c->player.y][c->player.x] = '0';
            c->map[c->right.y][c->right.x] = 'P';
            c->player = c->right;
        }
    }
}