CC=cc
CFLAGS = -Wall -Wextra -Werror -Ofast
NAME = cub3D
MLX_PATH = /Users/hmraizik/Desktop/push/MLX42
BONUS_NAME = cub3D_bonus
SRCS = Mandatory/parsing/main.c Mandatory/parsing/split.c Mandatory/parsing/fill_map.c Mandatory/parsing/parse_map.c Mandatory/parsing/libft2.c \
      Mandatory/parsing/tools.c Mandatory/parsing/diractions.c Mandatory/parsing/parsing.c Mandatory/parsing/extension.c Mandatory/parsing/utils.c Mandatory/parsing/gc_malloc.c \
      Mandatory/parsing/parsing_utils.c Mandatory/parsing/utils2.c Mandatory/parsing/map_utils.c Mandatory/parsing/gnl/get_next_line.c Mandatory/parsing/gnl/get_next_line_utils.c Mandatory/parsing/check_map.c\
      Mandatory/raycasting/init.c Mandatory/raycasting/castrays.c Mandatory/raycasting/calcul_rays.c Mandatory/raycasting/hooks.c Mandatory/raycasting/cub.c\
	Mandatory/raycasting/utils.c Mandatory/raycasting/utils2.c Mandatory/raycasting/check_func.c  \
	  Mandatory/rendering/render.c Mandatory/rendering/libft.c Mandatory/rendering/generate.c Mandatory/rendering/load.c Mandatory/rendering/vert_n_hrz.c

B_SRCS = bonus/parsing/main_bonus.c bonus/parsing/split_bonus.c bonus/parsing/fill_map_bonus.c bonus/parsing/parse_map_bonus.c bonus/parsing/lib_bonus.c \
      bonus/parsing/tools_bonus.c bonus/parsing/diractions_bonus.c bonus/parsing/parsing_bonus.c bonus/parsing/extension_bonus.c bonus/parsing/utils_bonus.c bonus/parsing/gc_malloc_bonus.c \
      bonus/parsing/parsing_utils_bonus.c bonus/parsing/utils2_bonus.c bonus/parsing/map_utils_bonus.c bonus/parsing/gnl/get_next_line_bonus.c bonus/parsing/gnl/get_next_line_utils_bonus.c \
      bonus/raycasting/init_bonus.c bonus/raycasting/castrays_bonus.c bonus/raycasting/calcul_rays_bonus.c bonus/raycasting/hooks_bonus.c bonus/raycasting/cub_bonus.c \
      bonus/raycasting/minimap_bonus.c bonus/raycasting/utils_bonus.c bonus/raycasting/utils2_bonus.c bonus/raycasting/check_func_bonus.c bonus/parsing/check_map_bonus.c \
      bonus/rendering/render_bonus.c bonus/rendering/libft_bonus.c bonus/rendering/generate_bonus.c bonus/rendering/load_bonus.c bonus/rendering/vert_n_hrz_bonus.c

MLX_FLAGS = -framework OpenGL -framework AppKit -O3
OBJ = $(SRCS:.c=.o)
B_OBJ = $(B_SRCS:.c=.o)

all: MLX $(NAME)

bonus: MLX $(BONUS_NAME)

MLX:
	@cmake -S $(MLX_PATH) -B $(MLX_PATH)/build
	@cmake --build $(MLX_PATH)/build -j4


$(NAME): $(OBJ) $(MLX_PATH)/build/libmlx42.a
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(MLX_PATH)/build/libmlx42.a -I Mandatory/includes -lglfw -L"$(shell brew --prefix glfw)/lib" $(OBJ) -o $(NAME)



$(BONUS_NAME): $(B_OBJ) $(MLX_PATH)/build/libmlx42.a bonus/includes/cub3d_bonus.h
	$(CC) $(FLAGS) $(MLX_FLAGS) $(MLX_PATH)/build/libmlx42.a -I bonus/includes -lglfw -L"$(shell brew --prefix glfw)/lib" $(B_OBJ) -o $(BONUS_NAME)

%_bonus.o: %_bonus.c bonus/includes/cub3d_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c Mandatory/includes/cub3d.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(B_OBJ)
fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	rm -rf $(MLX_PATH)/build
re: fclean all

.PHONY: all clean fclean re
