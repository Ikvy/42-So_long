/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:16:51 by mmidon            #+#    #+#             */
/*   Updated: 2022/07/17 08:34:25 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

///textures
# define FLOOR "./images/floor/flowerzzzzz.xpm"
# define WALL "./images/wall/rock.xpm"
# define ENEMY "./images/enemy/bernard.xpm"
# define ESCAPE "./images/escape/zoui.xpm"
# define PJ "./images/char/stevensenpai.xpm"

typedef struct s_player
{
	int		total_c;
	int		atm_c;
	int		pos;
	int		pv;
	size_t	move;
}			t_player;

typedef struct s_maping
{
	char	*strmap;
	int		columns;
	int		lines;
	int		img_height;
	int		img_width;
	void	**anim;
	size_t	tempo;
}			t_maping;

typedef struct s_mlx
{
	void		*img;
	void		*addr;
	void		*mlx;
	void		*mlx_win;
	t_maping	map;
	t_player	player;
}				t_mlx;

//////get_next_line + printf/////
# define BUFFER_SIZE 42

char	*get_next_line(int fd);
int		ft_printf(const char *format, ...);
int		ft_put_p(char select, unsigned long long x);
int		ft_putcharv2(int x);
int		ft_puthexa(char select, unsigned int x);
int		ft_putnbr_p(unsigned long long x, char *base);
int		ft_putnbrhexa(unsigned int x, char *base);
int		ft_putnbru2(unsigned int x);
int		ft_putnbrv2(int x);
int		ft_putstrv2(char *x);

//utils
size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strchr(char *s, int c);
char	*ft_strcat(char *dest, char *src);
char	*ft_strdup(char *src);
void	ft_error(char *msg);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_itoa(int n);
int		ft_strncmp(char *s1, char *s2, size_t n);

//parsing
void	ft_texture(t_mlx *mlx);
void	set_the_prettiest_thing_you_ve_ever_seen(t_mlx *mlx);
void	open_image(char *path_to_file, t_mlx *mlx, int *i, int *j);
void	ft_check_map(t_mlx mlx, char *map);
void	ft_is_rectangular(char *map);
void	ft_error(char *msg);
void	init_params(t_mlx *mlx);
char	*get_map(char *av, t_mlx *mlx);
int		do_open(char *av);

//events
size_t	find_next_thing(char *map, size_t pos, char select);
size_t	find_first_thing(char *map, char select);
void	hooking(t_mlx *mlx);
void	ft_move(t_player *player, int x, t_mlx *mlx);
void	ft_victory(void);
void	ft_loose(void);
void	update_sprite(t_mlx *mlx, int direction);
void	open_everything(t_mlx *mlx, int j, int i, size_t *map);
void	set_anim(t_mlx *mlx);
void	open_anim(t_mlx *mlx, int *i, int *j);
int		pos(char *str, int pos);
int		plus(char *str);
int		update_collectible(t_mlx *mlx);

//////leaks check : close, error, main

#endif
