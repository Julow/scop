#

# Executable name
NAME := scop

# Project directories
DIRS := srcs include

# Git submodule to init
MODULES := libft
# Makefiles to call
LIBS := libft

# Compilation and linking flags
FLAGS := -Wall -Wextra -O2
# Compilation flags
HEADS := $(addprefix -I,$(DIRS)) -Ilibft
# Linking flags
LINKS := -Llibft -lft -lglfw3 -framework OpenGL

# Objects directory
O_DIR := o

# Depend file name
DEPEND := depend.mk

# tmp
MODULE_RULES := $(addsuffix /.git,$(MODULES))

# Default rule (need to be before any include)
all: $(MODULE_RULES) $(LIBS) $(NAME)

# Include $(O_FILES) and dependencies
-include $(DEPEND)

# Linking
$(NAME): $(O_FILES)
	clang $(FLAGS) -o $@ $(O_FILES) $(LINKS) && printf '\033[32m$@\033[0m\n'

# Compiling
$(O_DIR)/%.o:
	clang $(FLAGS) $(HEADS) -c $< -o $@ && printf '\033[32m$<\033[0m\n'

# Init submodules
$(MODULE_RULES):
	git submodule init $(@:.git=)
	git submodule update $(@:.git=)

# Call sub Makefiles
$(LIBS):
	make -C $@

# Create obj directories
$(O_DIR)/%/:
	mkdir -p $@

# Clean obj files
clean:
	rm -f $(O_FILES)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Clean and make
re: fclean all

# Update $(DEPEND) file
$(DEPEND): Makefile
	makemake || printf "\033[31mCannot remake $(DEPEND)\033[0m\n"

.SILENT:
.PHONY: all $(LIBS) clean fclean re
