##
## EPITECH PROJECT, 2022
## B-YEP-410-TLS-4-1-zappy-arthur.duhot
## File description:
## Makefile
##

all:
	@make -C server
	@make -C client/src
	@make -C client
	cp -r client/zappy_ai ./zappy_ai
	cp -r server/zappy_server ./zappy_server

clean:
	@make -C client clean
	@make -C client/src clean
	@make -C server clean

fclean:
	@make -C client fclean
	@make -C client/src fclean
	@make -C server fclean
	rm -rf zappy_ai
	rm -rf zappy_server

re: fclean all

.PHONY: all clean fclean re
