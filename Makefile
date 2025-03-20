NAME=so_long

# /////////////////////////

CC=cc
CC_FLAGS=-Wall -Wextra -Werror -g3 -fsanitize=address

# /////////////////////////

DIR_OBJS=.objs
DIR_DEPS=.deps

# /////////////////////////

SRCS=srcs/map_checking.c\
	srcs/main.c\
	srcs/parse_utils.c\
	srcs/error.c\
	srcs/player.c

LIB= libft/libft.a
MLX= minilibx/libmlx.a
INCS= incs/so_long.h
OBJS=$(SRCS:srcs/%.c=$(DIR_OBJS)/%.o)
DEPS=$(SRCS:srcs/%.c=$(DIR_DEPS)/%.d)

# /////////////////////////

all: compile_start libft libmlx $(NAME) compile_done

compile_start:
	echo "$(GREEN) Compile start ... $(END)"

compile_done:
	echo "$(GREEN) Compiling done $(END)"

libft:
	$(MAKE) --silent -C ./libft

libmlx:
	$(MAKE) --silent -C ./minilibx 2> /dev/null

$(NAME): $(OBJS) $(DEPS) $(INCS)
	$(CC) $(CC_FLAGS) $(OBJS) $(LIB) $(MLX) -o $@
	echo "$(BLUE) Your so_long is ready $(END)"


$(DIR_OBJS)/%.o: srcs/%.c | $(DIR_OBJS) $(DIR_DEPS)
	$(CC) $(CC_FLAGS) -MMD -MP -MF $(DIR_DEPS)/$*.d -c -o $@ $<

# /////////////////////////

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

$(DIR_DEPS):
	mkdir -p $(DIR_DEPS)

# /////////////////////////

clean:
	echo "$(RED)Removing files... $(END)"
	$(MAKE) --silent -C  ./libft fclean
	$(MAKE) --silent -C  ./minilibx clean
	rm -rf $(DIR_OBJS)
	rm -rf $(DIR_DEPS)

fclean: clean
	echo "$(RED)Removing executable... $(END)"
	$(MAKE) --silent -C  ./libft fclean
	$(MAKE) --silent -C  ./minilibx clean
	rm -rf $(NAME)

re: fclean all

# /////////////////////////

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

# /////////////////////////

.PHONY: all clean fclean re libft
.SILENT: