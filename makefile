CC		= gcc
CFLAGS	= -Wall -O2 -g
LDFLAGS	= -lSDL2 -lGLU -lGL -lm

BINDIR	= bin/
SRCDIR	= src/
OBJDIR	= obj/

# Fichiers JEU

# Fichiers programme
OBJ_JEU = $(OBJDIR)jeu.o $(OBJDIR)fakesdlimage.o $(OBJDIR)lodepng.o
EXEC_JEU = jeu.out


# Regles compilation

all :

jeu : $(OBJ_JEU)
	$(CC) $(CFLAGS) $(JEU) $^ -o $(BINDIR)$(EXEC_JEU) $(LDFLAGS)

clean :
	rm -rf *~
	rm -rf $(SRCDIR)*/*~
	rm -rf $(OBJDIR)
	rm -rf $(BINDIR)*

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p `dirname $@`
	$(CC) -o $@ -c $< $(CFLAGS)

