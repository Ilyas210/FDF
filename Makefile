CC = cc

CFLAGS = -Wall -Wextra -Werror -I MLX42/include -I ~/glfw/include

LIBS =  libmlx42.a libglfw3.a \
       -framework Cocoa -framework OpenGL -framework IOKit \
       -framework Metal -framework QuartzCore

SRCS = libft/ft_atoi.c libft/ft_bzero.c libft/ft_split.c libft/ft_strchr.c libft/ft_substr.c \
       libft/ft_memcmp.c libft/ft_strlen.c libft/ft_putendl_fd.c libft/ft_strdup.c libft/ft_strjoin.c \
	   draw.c ft_free.c ft_init.c get_next_line.c main.c utils.c key.c parse.c utils2.c

BONUS = libft/ft_atoi.c libft/ft_bzero.c libft/ft_split.c libft/ft_strchr.c libft/ft_substr.c \
       libft/ft_memcmp.c libft/ft_strlen.c libft/ft_putendl_fd.c libft/ft_strdup.c libft/ft_strjoin.c \
	   bonus/draw_bonus.c ft_free.c bonus/ft_init_bonus.c get_next_line.c bonus/main_bonus.c utils.c \
	   bonus/key_bonus.c bonus/parse_bonus.c utils2.c bonus/mouse_hook_bonus.c

SRC_OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

NAME = fdf
BONUS_NAME = fdf_bonus

all: $(NAME)

$(NAME): $(SRC_OBJS) 
	$(CC) $(CFLAGS) $(SRC_OBJS) $(LIBS) -o $(NAME)

%.o: %.c libft/libft.h error_message.h bonus/fdf_bonus.h fdf.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBS) -o $(BONUS_NAME)

clean:
	rm -f $(SRC_OBJS) $(BONUS_OBJS)
	
fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all
