CC = cc

CFLAGS = -Wall -Wextra -Werror -I MLX42/include -I ~/glfw/include

LIBS = $(HOME)/libs/libmlx42.a $(HOME)/glfw/build/src/libglfw3.a \
       -framework Cocoa -framework OpenGL -framework IOKit \
       -framework Metal -framework QuartzCore

SRCS = libft/ft_atoi.c libft/ft_bzero.c libft/ft_split.c libft/ft_strchr.c libft/ft_substr.c \
       libft/ft_memcmp.c libft/ft_strlen.c libft/ft_putendl_fd.c libft/ft_strdup.c libft/ft_strjoin.c \
	   color.c draw.c ft_free.c ft_init.c get_next_line.c main.c utils.c key.c parse.c

BONUS = libft/ft_atoi.c libft/ft_bzero.c libft/ft_split.c libft/ft_strchr.c libft/ft_substr.c \
       libft/ft_memcmp.c libft/ft_strlen.c libft/ft_putendl_fd.c libft/ft_strdup.c libft/ft_strjoin.c \
	   color.c draw.c ft_free.c ft_init.c get_next_line.c main.c utils.c key_bonus.c parse.c

SRC_OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

NAME = fdf
BONUS_NAME = fdf_bonus

all: $(NAME)

$(NAME): $(SRC_OBJS)
	$(CC) $(CFLAGS) $(SRC_OBJS) $(LIBS) -o $(NAME)

%.o: %.c libft/libft.h error_message.h fdf.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBS) -o $(BONUS_NAME)

clean:
	rm -f $(SRC_OBJS) $(BONUS_OBJS)
	
fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

