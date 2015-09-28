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
#-Weverything
# Same but used in debug mode
DEBUG_FLAGS := -Wall -Wextra -g
# Compilation flags
HEADS := $(addprefix -I,$(DIRS)) -Ilibft
# Linking flags
ifeq ($(shell uname),Darwin)
	FLAGS += -DMAC_OS_MODE=1
	DEBUG_FLAGS += -DMAC_OS_MODE=1
	LINKS := -Llibft -lft -lglfw3 -lm -framework OpenGL
else
	LINKS := -Llibft -lft -lglfw -lGL -lGLEW -lm
endif

# Jobs
JOBS := 4

# Column output
COLUMN_OUTPUT := 1

ifeq ($(COLUMN_OUTPUT),0)
	COLUMN_INIT :=
	PRINT_OK = printf '\033[32m$<\033[0m\n'
	PRINT_LINK = printf '\033[32m$@\033[0m\n'
else
	COLUMN_INIT := column_init
	PRINT_OK = echo $< >> $(PRINT_FILE)
	PRINT_LINK = printf '\n\033[32m$@\033[0m\n'
endif

# Objects directory
O_DIR := o

# Depend file name
DEPEND := depend.mk

# tmp
MODULE_RULES := $(addsuffix /.git,$(MODULES))
PRINT_FILE := .tmp_print
SHELL := /bin/bash

# Default rule (need to be before any include)
all: $(MODULE_RULES) libs $(COLUMN_INIT)
	make -j$(JOBS) $(NAME)
# 	kill -9 `jobs -p`
# 	rm -f $(PRINT_FILE)

# Include $(O_FILES) and dependencies
-include $(DEPEND)

# Run omg scripts
omg:
	omg include/shader_loader.h srcs/shader_loader/load_shader.c | python
	omg include/resources.h srcs/resources/get_res.c | python

# Linking
$(NAME): $(LIBS_DEPEND) $(O_FILES)
	clang $(FLAGS) -o $@ $(O_FILES) $(LINKS) && $(PRINT_LINK)

# Compiling
$(O_DIR)/%.o:
	clang $(FLAGS) $(HEADS) -c $< -o $@ && $(PRINT_OK)

# Init submodules
$(MODULE_RULES):
	git submodule init $(@:.git=)
	git submodule update $(@:.git=)

# Create obj directories
$(O_DIR)/%/:
	mkdir -p $@

# Column output
column_init:
	MAX_LEN=1
	for o in $(O_FILES)
	do
		if [[ $${#o} -gt $$MAX_LEN ]]
		then
			MAX_LEN=$${#o}
		fi
	done
	PER_LINE=$$((`tput cols` / $$(($$MAX_LEN + 1))))
	CURR=0
	rm -f $(PRINT_FILE)
	touch $(PRINT_FILE)
	tail --pid=$$PPID -n0 -f $(PRINT_FILE) | while read l
	do
		if [[ $$CURR -ge $$PER_LINE ]]
		then
			CURR=0
			echo
		fi
		CURR=$$(($$CURR + 1))
		printf '\033[32m%-*s\033[0m ' $$MAX_LEN "$$l"
	done &

# Set debug mode and make
debug: _debug all

# Clean, set debug mode and make
rebug: fclean debug

# Clean obj files
clean:
	rm -f $(PRINT_FILE)
	rm -f $(O_FILES)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Clean and make
re: fclean all

# Update $(DEPEND) file
$(DEPEND): Makefile
	makemake || printf "\033[31mCannot remake $(DEPEND)\033[0m\n"

# Set debug flags
_debug:
	$(eval FLAGS := $(DEBUG_FLAGS))

.SILENT:
.ONESHELL:
.PHONY: all $(LIBS) clean fclean re debug rebug _debug
