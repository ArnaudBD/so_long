#include "includes/so_long.h"
#include "includes/gnl.h"

int last_check(t_config *c)
{
    int     i;
    t_list  *last_line;

    i = 0;
    last_line = c->lines;
    while (last_line->next)
    {
        last_line = last_line->next;
    }
    while (((char *)last_line->data)[i] == '1')
        {
            if ((((char *)last_line->data)[i]) != '1' 
                || ((char *)c->lines->data)[i] != '1')
                break ;
            i++;
        } 
        if (i != c->size_map.x)
            return (FAILURE);
    if (c->collectibles == 0 || c->exit.x != -1 || c->player.x == -1)
        return (FAILURE);
    return (SUCCESS);
}

int parse_line(char *line, t_config *c)
{
    int i;

    i = 0;
    c->size_map.x = strlen(line);
    while (line[i])
    {
        if (line[i] != '1' && line[i] != '0' && line[i] != 'P' \
            && line[i] != 'E' && line[i] != 'C')
            return (FAILURE);
        if (line[0] != '1' || line[c->size_map.x - 1] != '1')
            return (FAILURE);
        if (line[i] == 'P' && c->player.x >= 0)
            return (FAILURE);
        else if (line[i] == 'P')
            c->player.x = i;
        if (line[i] == 'E')
            c->exit.x++;
        if (line[i] == 'C')
            c->collectibles++;
        i++;
    }
    if (add_line_in_lines(line, c) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}

int check_arg_name(char const *argv[], t_config *c)
{
    int i;
    char    *str;

    i = ft_strlen(argv[1]) - 4;
    str = ".ber";
    if (ft_strncmp((str), &argv[1][i], 5))
        return (terminator2(c, ERR_NAME));
    return (SUCCESS);
}

int parsing(int argc, const char *argv[], t_config *c)
{
    int                 fd;
    char                *line;
    long unsigned int   len;
    char                buf;

    len = 0;
    if (argc != 2 || argv[1] == NULL)
        return (terminator2(c, ERR_ARGC));
    if (check_arg_name(argv, c) == FAILURE)
        return (terminator2(c, ERR_ARGV));
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return (terminator2(c, ERR_OPEN));
    if (read(fd, &buf, 0) == -1)
        return (terminator2(c, ERR_READ));
    while (get_next_line(fd, &line) == 1)
    {
        if (parse_line(line, c) == FAILURE)
        {
            free(line);
            return (terminator2(c, ERR_MAP));
        }
        if (len > 0 && len != strlen(line))
            return (terminator2(c, ERR_MAP));
        len = strlen(line);
    }
    if (strlen(line) == 0 && len == 0)
        return(terminator2(c, ERR_READ));
    free(line);
    if (last_check(c) == FAILURE)
        return (terminator2(c, ERR_MAP));
    return (SUCCESS);
}