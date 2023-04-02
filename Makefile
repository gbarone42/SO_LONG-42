NAME = so_long

SRCS = ARCADE/main.c \
		ARCADE/check_init.c \
		ARCADE/animation.c \
		ARCADE/maps_check.c \
		ARCADE/map_check_tools.c \
		ARCADE/char_tool.c \
		ARCADE/map_generator.c \
		ARCADE/ghost_creator.c \
		ARCADE/ghost_creator2.c \
		ARCADE/image_creator.c \
		ARCADE/player_init.c \
		ARCADE/input_manager.c \
		ARCADE/updater.c \
		ARCADE/sfree.c \
		ARCADE/ft_close.c \


OBJS = $(SRCS:.c=.o)

LIBS = ARCADE/libftprintf.a \
		ARCADE/GNL.a \
		ARCADE/libmlx.a \
		ARCADE/libmlx_Linux.a \

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -lX11 -lXext -lm


all: $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MFLAGS) -o $(NAME) -g

clean:
		$(RM) $(OBJS)

fclean: clean
			$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re


