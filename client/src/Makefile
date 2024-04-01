##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## My own Makefile <3
##

cc	=	gcc

#	VARIABLES	#

DEFAULT		=	"\033[00m"
GREEN		=	"\033[1;32m"
CYAN		=	"\033[1;36m"
YELLOW		=	"\033[1;184m"
MAGENTA		=	"\033[1;95m"
RED			=	"\033[1;31m"

#	SOURCES	#

SRC		=	check_select.c	\
			destroy_buffer.c	\
			fill_client_info.c	\
			new_buffer.c	\
			read_message.c	\
			read_socket.c	\
			send_response.c	\
			set_status.c	\
			write_on_socket.c	\
			handle_selecting.c	\
			settup_client.c	\
			create_buff.c

TESTS_SRC	=

#	OBJECTS	#

OBJ	=	$(SRC:.c=.o)

TESTS_OBJ	=	$(TESTS_SRC:.c=.o)

#	NAME	#

NAME	=

TESTS_NAME	=	unit_tests

#	FLAGS	#

CFLAGS	=	-W -Wpedantic -Wall -Wextra -fno-builtin -I../include/

TESTS_FLAGS	=	--coverage -lcriterion

#	RULES	#

all:
	@printf "\033[1;36m Compiling .C\n"
	@$(CC) -g -O -c $(SRC) $(CFLAGS)
	@printf "\033[1;32m DONE\n"
	@printf "\033[00m"

tests_run: $(OBJ)	$(TESTS_OBJ)
	@printf "\033[1;36m Compiling .C\n"
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
