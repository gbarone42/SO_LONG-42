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

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -lmlx -framework OpenGL -framework AppKit

CORSIVO='\033[3m'
GREEN='\033[32m'
GRAY='\033[2;37m'

all: $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MFLAGS) -o $(NAME) -g

play:	all
	@echo $(CORSIVO)"     - Playing all maps... \n"$(GRAY)
	@make -C ./ clean
	@./$(NAME) map1.ber
	@./$(NAME) map1a.ber
	@./$(NAME) map2.ber
	@./$(NAME) map3.ber
	@./$(NAME) maperror.ber
	@./$(NAME) maonopath.ber
	
clean:
		$(RM) $(OBJS)

fclean: clean
	@echo $(GREEN)"     - Removing object files..."
			$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re


