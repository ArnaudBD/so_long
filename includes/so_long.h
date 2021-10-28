#ifndef SO_LONG_H
# define SO_LONG_H
#define RES_Y 1080
#define RES_X 1920
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define BLACK 0x0
#define WHITE 0xFFFFFF
#define SUCCESS 0
#define FAILURE 1
#define MES_COUILLES 123
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

enum    
{
    ERR_ARGC = 1,
    ERR_ARGV,
    ERR_OPEN,
    ERR_READ,
    ERR_MAP_MALLOC,
    ERR_MAP_LINE_MALLOC,
    ERR_MAP
};

typedef struct  s_data {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_data;

typedef struct  s_pt
{
    int x;
    int y;
}               t_pt;

typedef struct  s_list
{
    void            *data;
    struct s_list   *next;
}               t_list;


typedef struct  s_config
{
    void    *mlx;
    void    *mlx_win;
    t_data  *img;
    t_pt    player;
    t_pt    size_map;
    int     exit;
    int     collectibles;
    char    **map;
    t_list  *lines;
}              t_config;

// init.c
void init_struct_config(t_config *c);

// kill.c
int     terminator(t_config *c); /*, int error AVEC CODES D'ERREUR CORRESPONDANTS)*/
int     terminator2(t_config *c, int code);

// libft_utils.c
int     ft_strlen(const char *s);
int     ft_strncmp(const char *s1, const char *s2, size_t n);

// mlx_utils.c
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);

// parsing.c
int last_check(t_config *c);
int check_arg_name(char const *argv[], t_config *c);
int parsing(int argc, const char *argv[], t_config *c);

// map.c
int create_map(t_config *c);
int add_line_in_lines(char *line, t_config *c);
void show_list(t_config *c);
void    show_map(t_config *c);

#endif
