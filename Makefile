CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

PROJ_NAME = pathfinder
LIBMX = libmx/libmx.a
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

.PHONY: all clean uninstall

all: $(LIBMX) $(PROJ_NAME)

$(LIBMX):
	make -C libmx/

$(PROJ_NAME): $(OBJ_FILES) | $(LIBMX)
	clang $(CFLAGS) $(OBJ_FILES) -o $(PROJ_NAME) -I$(INC_DIR) -Llibmx -lmx

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	clang $(CFLAGS) -I$(INC_DIR) -Ilibmx/inc -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf ./obj

uninstall:
	rm -rf ./obj $(PROJ_NAME)
	make -C libmx/ uninstall

