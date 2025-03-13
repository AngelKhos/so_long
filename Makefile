NAME=so_long

# /////////////////////////

CC=cc
CC_FLAGS=-Wall -Wextra -Werror

# /////////////////////////
DIR_OBJS=.objs
DIR_DEPS=.deps

# /////////////////////////

SRCS=srcs/map_parsing.c

LIB= libft/libft.a
MLX= minilibx_opengl_20191021/libmlx.a
INCS= incs/so_long.h
OBJS=$(SRCS:srcs/%.c=$(DIR_OBJS)/%.o)
DEPS=$(SRCS:srcs/%.c=$(DIR_DEPS)/%.d)

# /////////////////////////

all: compile_start libft libmlx $(NAME) compile_done

compile_start:
	echo "$(COLOUR_GREEN) Compile start ... $(COLOUR_END)"

compile_done:
	echo "$(COLOUR_GREEN) Compiling done $(COLOUR_END)"

libft:
	$(MAKE) --silent -C ./libft

libmlx:
	$(MAKE) --silent -C ./minilibx_opengl_20191021 2> /dev/null

$(NAME): $(OBJS) $(DEPS) $(INCS)
	$(CC) $(CC_FLAGS) $(OBJS) $(LIB) $(MLX) -o $@
	echo "$(COLOUR_BLUE) Your so_long is ready $(COLOUR_END)"


$(DIR_OBJS)/%.o: srcs/%.c | $(DIR_OBJS) $(DIR_DEPS)
	$(CC) $(CC_FLAGS) -MMD -MP -MF $(DIR_DEPS)/$*.d -c -o $@ $<

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

$(DIR_DEPS):
	mkdir -p $(DIR_DEPS)

clean:
	echo "$(COLOUR_RED)Removing files... $(COLOUR_END)"
	$(MAKE) --silent -C  ./libft fclean
	$(MAKE) --silent -C  ./minilibx_opengl_20191021 clean
	rm -rf $(DIR_OBJS)
	rm -rf $(DIR_DEPS)

fclean: clean
	echo "$(COLOUR_RED)Removing executable... $(COLOUR_END)"
	$(MAKE) --silent -C  ./libft fclean
	$(MAKE) --silent -C  ./minilibx_opengl_20191021 clean
	rm -rf $(NAME)

re: fclean all

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

.PHONY: all clean fclean re libft
.SILENT: