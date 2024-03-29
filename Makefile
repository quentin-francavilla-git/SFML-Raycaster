#Windows
SRC = $(wildcard ./src/*.cpp ./src/Classes/*.cpp)
OBJECTS += $(filter %.o,$(SRC:.cpp=.o))
CFLAGS  = -w -g
LIBPATH = -L/C:/Users/Quentin/Documents/Projets/Libs/SFML-2.5.1/lib/
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
INCLUDES = -I./include/ -I./C:/Users/Quentin/Documents/Projets/Libs/SFML-2.5.1/include/
NAME	=	doom.exe
CC = g++

all:	$(NAME)

# generate $(NAME), require $(OBJECT)
$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(LIBPATH) $(LIBS)

# generate .o, require .cpp
# $@ aim for target being generate (.o), $< aim for first prerequisite (.cpp)
%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm -f $(NAME)

re: all
	rm -f $(OBJECTS) 

# Explicitly tell Make "all, clean, fclean, re"are not files names
.PHONY: all clean fclean re

# $@: The filename representing the target.
# $%: The filename element of an archive member specification.
# $<: The filename of the first prerequisite.
# $?: The names of all prerequisites that are newer than the target, separated by spaces.
# $^: The filenames of all the prerequisites, separated by spaces.
# $+: Similar to $^, this is the names of all the prerequisites separated by spaces, except that $+ includes duplicates.
# $*: The stem of the target filename. A stem is typically a filename without its suffix.