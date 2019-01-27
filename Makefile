SRC = main.cpp

SRC_CLASS = Enemy.cpp \
		Game.cpp \
		Menu.cpp \
		Player.cpp \

OBJ = $(SRC:.cpp=.o)
OBJ_CLASS = $(SRC_CLASS:.cpp=.o)

SRCDIR = src/
OBJDIR = objs/
SRCDIR_CLASS = class/
OBJDIR_CLASS = objs_class/

SRCS = $(addprefix $(SRCDIR), $(SRC))
OBJS = $(addprefix $(OBJDIR), $(OBJ))
SRCS_CLASS = $(addprefix $(SRCDIR_CLASS), $(SRC_CLASS))
OBJS_CLASS = $(addprefix $(OBJDIR_CLASS), $(OBJ_CLASS))

LIBS = -lncurses
HEADER = -I includes

CC = g++
CFLAG = -c
WFLAG = -Wall -Wextra -Werror

NAME = ft_retro

#.PHONY: all clean fclean re
#.SUFFIXES: .c .o

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAG) $(WFLAG) $(HEADER) $< -o $@

$(OBJDIR_CLASS)%.o: $(SRCDIR_CLASS)%.cpp
	@mkdir -p $(OBJDIR_CLASS)
	@$(CC) $(CFLAG) $(WFLAG) $(HEADER) $< -o $@

$(NAME): $(OBJS) $(OBJS_CLASS)
	@$(CC) $(OBJS) $(OBJS_CLASS) $(HEADER) $(LIBS) -o $@

clean:
	@/bin/rm -rf $(OBJDIR)
	@/bin/rm -rf $(OBJDIR_CLASS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all