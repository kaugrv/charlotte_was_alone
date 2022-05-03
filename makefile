CC		= gcc
CFLAGS	= -Wall -O2 -g
LDFLAGS	= -lSDL2 -lGLU -lGL -lm

BIN_DIR	= bin/
INC_DIR = -I include
SRC_DIR	= src/
OBJ_DIR	= obj/

SRC_FILES 	= $(shell find $(SRC_DIR)/ -type f -name '*.c')
OBJ_FILES 	= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRC_FILES))

EXEC_BIN = jeu.out


# Regles compilation

all : $(OBJ_FILES)

jeu : $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)/
	$(CC) -o $(BIN_DIR)/$(EXEC_BIN) $(OBJ_FILES) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p "$(@D)"
	$(CC) -c $< -o $@ $(CFLAGS) $(INC_DIR)

clean :
	rm -rf *~
	rm -rf $(SRC_DIR)/*/*~
	rm -rf $(OBJ_DIR)/
	rm -rf $(BIN_DIR)/*

