##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## My own Makefile <3
##

cc	=	g++

#	VARIABLES	#

DEFAULT		=	"\033[00m"
GREEN		=	"\033[1;32m"
CYAN		=	"\033[1;36m"
YELLOW		=	"\033[1;184m"
MAGENTA		=	"\033[1;95m"
RED			=	"\033[1;31m"

#	SOURCES	#

SRC		=	ia.cpp

TESTS_SRC	=

#	OBJECTS	#

OBJ	=	$(SRC:.cpp=.o)

TESTS_OBJ	=	$(TESTS_SRC:.cpp=.o)

#	NAME	#

NAME	=	zappy_ai

TESTS_NAME	=	unit_tests

#	FLAGS	#

CXXFLAGS	=	-fno-builtin -I./include/

TESTS_FLAGS	=	--coverage -lcriterion

#	RULES	#

all:	$(NAME)

$(NAME):	$(OBJ)
	@printf "\033[1;36m Compiling .CPP\n"
	@$(cc) -o $(NAME) $(OBJ) ./src/*.o $(CXXFLAGS)
	@printf "\033[1;32m DONE\n"
	@printf "\033[00m"

tests_run: $(OBJ)	$(TESTS_OBJ)
	@printf "\033[1;36m Compiling .CPP\n"
	@gcc -o $(TESTS_NAME) $(OBJ) $(TESTS_OBJ) $(TESTS_FLAGS)
	@printf "\033[1;32m DONE\n"
	@printf "\033[00m"

clean:
	@printf "\033[1;31m Cleanning .o\n"
	@rm -f $(OBJ) $(TESTS_OBJ)
	@printf "\033[1;32m DONE\n"
	@printf "\033[00m"

fclean: clean
	@printf "\033[1;31m Cleanning binaries\n"
	@rm -f $(NAME) $(TESTS_NAME)
	@printf "\033[1;32m DONE\n"
	@printf "\033[1;31m cleanning vgcore\n"
	@rm -f vgcore.*
	@printf "\033[1;32m DONE\n"
	@printf "\033[00m"

re:	fclean	all
	@printf "\033[1;32m REBULDING DONE\n"
	@printf "\033[00m"

#	END		-Made by VulkreoN	#
