# include "includes/so_long.h"

void init_struct_config(t_config *c)
{
    c->mlx = NULL;
    c->mlx_win = NULL;
    c->map = NULL;
    c->img->img = NULL;
    c->img->addr = NULL;
    c->wl_txt->img = NULL;
    c->wl_txt->addr = NULL;
    c->lines = NULL;
    c->player.x = -1;
    c->player.y = -1;
    c->size_map.x = -1;
    c->size_map.y = 0;
    c->collectibles = 0;
    c->exit.x = -2;
    c->exit.y = -1;
    c->lines = NULL;
    c->collected = 0;
    c->open = 0;
    c->on_exit = FALSE;
}
