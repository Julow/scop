#
# scop
#
# Makefile
#

#
# Config
#

# Project name
NAME := scop

# Project directories
DIRS := srcs include

# Obj directory
O_DIR := o

# Makefiles to call (directory)
LIBS := libft

# Modules to init (directory)
MODULES := libft

# Number of threads
THREADS := 1

# C compiler
C_CC := clang

# Linking compiler
LD_CC := clang

# C flags
C_FLAGS := -Wall -Wextra -Werror -O2

# Linking flags
LD_FLAGS := -L libft -l ft -l glfw3 -framework OpenGL

# C include flags
C_HEADS := -I include -I libft

#
# Internal
#

O_FILES := o/srcs/callback.o \
	o/srcs/create_mesh.o \
	o/srcs/create_shader.o \
	o/srcs/ft_time.o \
	o/srcs/main.o \
	o/srcs/window.o \
	o/srcs/ft_loadimg/ft_loadimage.o \
	o/srcs/ft_loadimg/tga_parser.o \
	o/srcs/ft_math/ft_mat4mult.o \
	o/srcs/ft_math/ft_mat4rotate.o \
	o/srcs/ft_math/ft_mat4scale.o \
	o/srcs/ft_math/ft_mat4translate.o

O_DIRS := o/srcs/ft_math o/srcs/ft_loadimg o/srcs

MSG_0 := printf '\033[0;32m%-33.33s\033[0;0m\r'
MSG_1 := printf '\033[0;31m%-33.33s\033[0;0m\n'
MSG_END := printf '\n'

.SILENT:

all: $(addsuffix /.git,$(MODULES)) $(LIBS) $(NAME)
.PHONY: all

$(NAME): $(O_FILES)
	@$(MSG_0) $@ ; $(LD_CC) -o $@ $(O_FILES) $(LD_FLAGS) && $(MSG_END) || $(MSG_1) $@

o/srcs/callback.o: srcs/callback.c include/ft_loadimg.h include/scop.h | o/srcs
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/create_mesh.o: srcs/create_mesh.c include/ft_loadimg.h include/scop.h | o/srcs
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/create_shader.o: srcs/create_shader.c include/ft_loadimg.h include/scop.h | o/srcs
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_time.o: srcs/ft_time.c include/ft_loadimg.h include/scop.h | o/srcs
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/main.o: srcs/main.c include/ft_loadimg.h include/scop.h | o/srcs
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/window.o: srcs/window.c include/ft_loadimg.h include/scop.h | o/srcs
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_loadimg/ft_loadimage.o: srcs/ft_loadimg/ft_loadimage.c include/ft_loadimg.h | o/srcs/ft_loadimg
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_loadimg/tga_parser.o: srcs/ft_loadimg/tga_parser.c include/ft_loadimg.h | o/srcs/ft_loadimg
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_math/ft_mat4mult.o: srcs/ft_math/ft_mat4mult.c include/ft_3dmath.h | o/srcs/ft_math
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_math/ft_mat4rotate.o: srcs/ft_math/ft_mat4rotate.c include/ft_3dmath.h | o/srcs/ft_math
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_math/ft_mat4scale.o: srcs/ft_math/ft_mat4scale.c include/ft_3dmath.h | o/srcs/ft_math
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_math/ft_mat4translate.o: srcs/ft_math/ft_mat4translate.c include/ft_3dmath.h | o/srcs/ft_math
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

$(LIBS):
	@make -C $@
.PHONY: $(LIBS)

$(addsuffix /.git,$(MODULES)):
	@git submodule init $(@:.git=)
	@git submodule update $(@:.git=)

$(O_DIRS):
	@mkdir -p $@ 2> /dev/null || true

clean:
	@rm -f $(O_FILES) 2> /dev/null || true
	@rmdir -p $(O_DIRS) $(O_DIR) 2> /dev/null || true
.PHONY: clean

fclean: clean
	@rm -f $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re
