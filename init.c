# include "includes/so_long.h"

void init_struct_config(t_config *c)
{
    c->mlx = NULL;
    c->mlx_win = NULL;
    c->map = NULL;
    c->img->img = NULL;
    c->img->addr = NULL;
    c->lines = NULL;
    c->player.x = -1;
    c->player.y = -1;
    c->collectibles = 0;
    c->exit = 0;
}
