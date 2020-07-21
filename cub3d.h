/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 01:29:46 by lnoaille          #+#    #+#             */
/*   Updated: 2020/07/22 01:45:23 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include <X11/keysymdef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_wall
{
	void *mlx_ptr;
	void  *img;
	void  *img_addr;
	int width;
	int height;
	int bpp;
	int size_line;
	int endian;
	int **color_tab;
}				t_wall;

typedef struct	 s_textures
{
	int f;
	int c;
	t_wall *E;
	t_wall *N;
	t_wall *W;
	t_wall *S;
	t_wall *Sp;
}				t_textures;

typedef struct	 s_img
{
	double pos_x;
	double pos_y;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double sidedist_x;
	double sidedist_y;
	int 	map_x;
	int		map_y;
	double raydir_x;
	double raydir_y;
	void 	*mlx_ptr;
	void 	*mlx_wd;
	void 	*img;
	void 	*img_addr;
	int 	res_x;
	int 	res_y;
	int   	bits_per_pixel;
    int  	line_length;
    int  	endian;
	char 	**map;
	size_t  map_width;
	size_t  map_heigth;
	t_textures *skin;
	char 	side;
}				t_img;

int		until_next_wall(t_img *param, int step_x, int step_y);
int ft_view(t_img *param, int res_x);
void            ft_mlx_pixel_put(t_img *data, int x, int y, int color);
void	ft_create_wall(double dist_wall, int pixel, t_img *img);
double ft_abs(double a);
double ft_distance_to_wall(t_img *param, double screenx);
int		ft_extract_map(t_img *param, char *map);
int		ft_convert_map(char *map, t_img *param);
void ft_pos_and_angle(size_t heigth, size_t width, t_img *param, char cardinal);
void	ft_convert_map_utils(size_t *w, size_t *i, char *a, char *b);
int		ft_ispos(int ok, char face);
int		ft_initial(int *ok, size_t *h, size_t *w);
int		ft_verif(char map, int *ok);
void	ft_initialize_data(size_t *nbr_flags, int *ok, size_t *h, size_t *w);
int	ft_verif_map_h(t_img *param);
int	ft_verif_map_w(t_img *param);
int	**ft_color_tab(t_wall *face);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int ft_err_code(int i);
int ft_err_code_2(int i);
int ft_putstr(char *str);
int	ft_extract_color(char *line, t_img *param);
int ft_create_img(t_img *param, char* temp, char face);
int ft_create_img2(t_img *param, char* temp, char face);
int	ft_extract_data(t_img *param, char *line);
int	ft_extract_data_next(t_img *param, char *line, int i);
int	ft_extract_reso(char *line, t_img *param);
int	ft_parsing(char *pathname, t_img *param);
int	ft_while_parsing(int fd, char *line, char **map, t_img *param);
int	ft_while_while_parsing(int fd, char *line, char **map, int *ret);
size_t	ft_strlen(const char *s);
char	*ft_strjoin_f(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strchr(const char *s, int c);
int		get_next_line(int fd, char **line);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_extract_img(t_img *param, char *line, char face);
char	*ft_path_extract(char *line);
int		ft_atoi(const char *str);
int ft_create_rgb(int r, int g, int b);
t_img *ft_init_s_img(void);
int sidedist_direction(double *sideDist, double raydir, double pos, int map);
void init_vect_pos(t_img *param);


#endif
