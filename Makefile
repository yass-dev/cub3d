SRCS = srcs/events.c  srcs/get_next_line.c  srcs/get_next_line_utils.c  srcs/main.c  srcs/map.c  srcs/player.c  srcs/ray.c srcs/ray_2.c srcs/sprite.c  srcs/utils.c srcs/utils_2.c srcs/utils_3.c srcs/utils_4.c srcs/wall.c srcs/ft_lstadd_back_bonus.c srcs/ft_lstnew_bonus.c srcs/ft_lstclear_bonus.c srcs/ft_lstsize_bonus.c srcs/bitmap.c srcs/map_2.c srcs/map_3.c srcs/map_4.c srcs/map_5.c srcs/utils_5.c srcs/utils_6.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
INCLUDE			= ./inc/
CFLAGS			= -Wall -Wextra -Werror -I ${INCLUDE}
LIBS			= -Lmlx -Llibft -Lft_printf -lmlx -lft -lftprintf -framework OpenGL -framework AppKit
MLX				= libmlx.a

NAME			= Cub3D

all:			$(NAME)

$(NAME):		$(MLX) $(OBJS)
				gcc -fsanitize=address -I ${INCLUDE} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

$(MLX):
				@$(MAKE) -C libft
				@$(MAKE) -C mlx
				@$(MAKE) -C ft_printf
				@mv mlx/$(MLX) .

clean:
				@$(MAKE) -C mlx clean
				@$(MAKE) -C libft clean
				@$(MAKE) -C ft_printf clean
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				@$(MAKE) -C libft fclean
				@$(MAKE) -C ft_printf fclean
				$(RM) $(NAME) $(MLX)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
