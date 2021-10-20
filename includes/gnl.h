#ifndef GNL_H
# define GNL_H
# define BUFFER_SIZE 15
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

int		get_next_line(int fd, char **line);
char	*mv_next_line(char **line_dest, char *str);
int		n_search(char *str);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(char const *str);
char	*first_line(char *str);
char	*cut_first_line(char *str);
int		mv_first_line(char *str, char **dest);
char	*sup_first_line(char *str);
void	*ft_memmove(void *dst, const void *src, size_t len);

#endif