# include "includes/so_long.h"

int init_struct_config(t_config *c)
{
    c->txts = malloc(sizeof(t_all_txts));
    if (!c->txts)
        return (terminator2(c, ERR_TXT_MALLOC));
    c->txts->wl_txt = malloc(sizeof(t_txt));
    if (!c->txts->wl_txt)
        return (terminator2(c, ERR_TXT_MALLOC));
    c->txts->fl_txt = malloc(sizeof(t_txt));
    if (c->txts->fl_txt == NULL)
        return (terminator2(c, ERR_TXT_MALLOC));
    c->txts->key_txt = malloc(sizeof(t_txt));
    if (c->txts->key_txt == NULL)
        return (terminator2(c, ERR_TXT_MALLOC));
    c->txts->kt_txt = malloc(sizeof(t_txt));
    if (c->txts->kt_txt == NULL)
        return (terminator2(c, ERR_TXT_MALLOC));
    c->txts->dr_txt = malloc(sizeof(t_txt));
    if (c->txts->dr_txt == NULL)
        return (terminator2(c, ERR_TXT_MALLOC));
    c->sizex = malloc(sizeof(*c->sizex));
    if (!c->sizex)
        return (terminator2(c, ERR_MALLOC));
    c->sizey = malloc(sizeof(*c->sizey));
    if (!c->sizey)
        return (terminator2(c, ERR_MALLOC));
    c->mlx = NULL;
    c->mlx_win = NULL;
    c->map = NULL;
    c->img->img = NULL;
    c->img->addr = NULL;
    c->txts->wl_txt->img = NULL;
    c->txts->wl_txt->addr = NULL;
    c->txts->fl_txt->img = NULL;
    c->txts->fl_txt->addr = NULL;
    c->txts->key_txt->img = NULL;
    c->txts->key_txt->addr = NULL;
    c->txts->dr_txt->img = NULL;
    c->txts->dr_txt->addr = NULL;
    c->txts->kt_txt->img = NULL;
    c->txts->kt_txt->addr = NULL;
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
    c->zoom = ZOOM;
    return (SUCCESS);
}
