/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 02:42:09 by mlimami           #+#    #+#             */
/*   Updated: 2024/12/07 19:48:31 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "../parsing/gnl/get_next_line_bonus.h"
# include ".MLX42.h"

# define FALSE 0
# define TRUE 1

# define PI 3.14159265
# define TWO_PI 6.28318530
# define TILE_SIZE 16
# define MAX_FRAMES 180
# define WALK_SPEED 2
# define TURN_SPEED 0.0261
# define NUM_OF_RAYS SCREEN_WIDTH

# define MINIMAP_SCALE_FACTOR 1
# define FOV_ANGLE 1.044

# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define BROUN 0xCDAD93

typedef struct s_diraction
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*door;
}	t_diraction;

# define SCREEN_WIDTH 1200
# define SCREEN_HEIGTH 800
# define MINIMAP_WIDTH 200
# define MINIMAP_HEIGHT 200

/*_________define derections */
// north = 3 * PI / 2 wich is UP
# define NORTH 4.71238898038
// south = PI / 2 wich is DOWN
# define SOUTH 1.570
// west = PI wich is LEFT
# define WEST PI
// east = 0 wich is RIGHT
# define EAST 0

typedef struct s_gc_node
{
	struct s_gc_node	*next;
	size_t				size;
}	t_gc_node;

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
}	t_colors;

typedef struct s_map_data
{
	char	**map;
	int		*i;
	int		*map_state;
}	t_map_data;

typedef struct s_map
{
	char		**map;
	double		p_direction;
	int			player_x;
	int			player_y;
	t_diraction	directions;
	t_colors	flor;
	t_colors	ceiling;
}	t_map;

typedef struct s_player
{
	double	x;
	double	y;
	int		turn_dir;
	int		walk_dir;
	int		sidemove;
	double	rotation_angle;
	double	ard;
}	t_player;

typedef struct s_ray
{
	double		ray_angle;
	double		wall_hit_x;
	double		wall_hit_y;
	double		horz_wall_hit_x;
	double		horz_wall_hit_y;
	double		vert_wall_hit_x;
	double		vert_wall_hit_y;
	double		distance;
	int			was_hit_vertical;
	int			is_ray_facing_up;
	int			is_ray_facing_down;
	int			is_ray_facing_left;
	int			is_ray_facing_right;
	int			found_horz_wall_hit;
	int			found_vert_wall_hit;
	double		xintercept;
	double		yintercept;
	double		xstep;
	double		ystep;
	uint32_t	color;
}	t_ray;

typedef struct s_texture
{
	mlx_texture_t	*no_texture;
	mlx_texture_t	*so_texture;
	mlx_texture_t	*we_texture;
	mlx_texture_t	*ea_texture;
	mlx_image_t		*no_image_texture;
	mlx_image_t		*so_image_texture;
	mlx_image_t		*we_image_texture;
	mlx_image_t		*ea_image_texture;
	mlx_image_t		*tp;
	mlx_image_t		*door_image_texture;
	mlx_texture_t	*door_texture;
	char			**map;
	int				f_c;
	int				height;
	size_t			width;
	int				tex_width;
	int				tex_height;
	int				text_x;
	int				fram;
	double			step;
	double			text_pos;
	double			text_y;
	int				animt;
	int				i;
	mlx_texture_t	*s_sprite[180];
}					t_texture;

typedef struct s_data
{
	t_ray		ray[NUM_OF_RAYS];
	mlx_t		*mlx_ptr;
	mlx_image_t	*img_ptr;
	t_map		*map;
	t_player	player;
	t_texture	*texture;
	int			num_of_rows;
	int			num_of_cols;
	int			door_open_timer;
	int			cursor_hidden;
}		t_data;

typedef struct s_line_y
{
	long	from;
	long	to;
}		t_line_y;

typedef struct s_wall_height_data
{
	t_data	*data;
	int		i;
	double	w_height;
	int		from_y;
	int		to_y;
}	t_wall_height_data;

int				isdigit(int c);
int				err(char *str);
char			*removespaces(char *line);
void			ft_free(char **map);
int				isspace(int c);
int				if_only_spaces(char *line);
int				colums_len(const char *filename);
char			*removeendline(char *line);
int				has_cub_extension(const char *filename);
int				is_valid_direction(char *line);
char			*substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
int				is_digit_space(char *line);
int				is_valid_rgb(char *line);
char			*strtrim(char *s);
int				parsing(char *filename, t_map *map);
int				ft_countword(char const *str, char c);
int				is_valid(char *filename);
int				check_directions(char **map);
size_t			ft_strlen(const char *s);
char			*ft_strchr(char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strdup(char *src);
int				calculate_largest_line(char **map);
int				validate_first_and_last_lines(char *line, int is_first);
void			pad_map_lines(char **map, size_t largest_line);
char			*pad_line_with_spaces(char *line, int target_length);
int				check_first_and_last_walls(char **line, char *filename);
int				duplicate_player(char **map);
int				is_avalidckaracter(char *line);
int				is_itmap(char *line);
int				map_clms(char *filename);
char			**fill_map(char *filename, int i, \
						int line_count, int map_state);
int				is_valid_char(char c);
int				ft_atoi(char *str);
int				is_whitespace(char c);
int				is_floor_line(char *line);
int				is_ceiling_line(char *line);
int				check_adjacent_spaces(char **map, int line_index, \
									int largest_line);
int				validate_line(char *line, int largest_line);
char			**fillmap(char *filename);
int				validate_flor_and_ceiling(char **line);
void			set_p_direction(char c, t_map *map);
int				parse_map(char **map, char *filename);
int				no_check(char *line, int *nf);
int				so_check(char *line, int *sf);
int				we_check(char *line, int *wf);
int				ea_check(char *line, int *ef);
int				ft_count_map(char **map);
void			calculate_wall_height(t_wall_height_data *h_data);
mlx_image_t		*get_horizontal_texture(t_data *data, int i, int x, int y);
mlx_image_t		*get_vertical_texture(t_data *data, int i, int x, int y);
char			*gc_and_cpy(char *src);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strdupp(char *src);
/********************************************************************/
//                      rendering  functions           				/
/*******************************************************************/

void			*gc_malloc(size_t size);
void			gc_free_all(void);
void			load_sprite_textures(t_data *cube);
mlx_texture_t	*my_mlx_load_png(char *path);
mlx_image_t		*my_mlx_texture_to_image(void *mlx, mlx_texture_t *texture);
void			ft_texture_to_image(t_data *cube);
void			load_textures(t_data *cube);
char			*ft_strjoinn(char *s1, char *s2);
char			*ft_itoa(int n);
mlx_image_t		*find_text(t_data *data, int i, int x, int y);
void			sel_calculate_texture(t_data *data, int index, \
									mlx_image_t *cur_texture);
void			calculate_tex_pos(t_data *cube, mlx_image_t *tex, \
								double w_h, int f_y);
uint32_t		get_texture_pixel(mlx_image_t *texture, int x, int y);
void			put_pixel_safe(mlx_image_t *img, long x, long y, long color);
void			draw_text(t_line_y line_y, mlx_image_t *cur_tex, \
						t_data *cube, long x);
int				rgb_to_hex(t_colors color);
void			fill_sky_floor(t_data *data, int i);
void			generate_3d_projection(t_data *data);
void			ft_animation(t_data *cub);

/********************************************************************/
//             minimap rendering function           				/
/*******************************************************************/

void			draw_mini_circle(t_data *data, double x, double y, int color);
void			render_player(t_data *data);
uint32_t		find_color(t_data *data, int i, int j);
void			draw_tile(t_data *data, int tileX, int tileY, \
						uint32_t tile_color);
void			render_mini_map(t_data *data);
//
void			free_data_struct(t_data *data);
bool			check_walls(double x, double y, t_data *cube);
int				rgb_to_hex2(int r, int g, int b);
bool			is_player_near_door(t_data *data, int door_x, int door_y);
//
void			render(t_data *data);
void			update(t_data *data);
void			update_and_render(void *void_data);

/********************************************************************/
//             				hooks			           				/
/*******************************************************************/
void			process_keys(struct mlx_key_data keydata, void *void_data);
void			handle_key_release(mlx_key_data_t keydata, t_data *cube);
void			mlx_keys_release(struct mlx_key_data keydata, t_data *data);
void			ft_mouse(double xpos, double ypos, void *param);

/********************************************************************/
//                     rays calculation				   				/
/*******************************************************************/

void			increment_vert_steps(t_data *data, int strip_id);
void			verticaltay(t_data *data, double rayangle, int strip_id);
void			increment_horiz_steps(t_data *data, int strip_id);
void			horizontalray(t_data *data, double rayangle, int strip_id);

// mlx init functions

int				initialize(t_map *map);

//check functions
void			checkrayfacing(double rayangle, t_data *data, int strip_id);
int				is_wall(double x, double y, t_data *p);

/********************************************************************/
//                      rays-casting  functions           			/
/*******************************************************************/

void			move_player(t_data *data);
int				castallrays(t_data *data);
void			castray(double rayangle, t_data *data, int strip_id);
int				rows_length(char **map);
double			normaliz(double angle);
void			ft_close_door(t_data *cube, int i, int j);
void			ft_open_door(t_data *data, int i);
void			close_game(t_data *data);

#endif
