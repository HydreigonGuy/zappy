##
## EPITECH PROJECT, 2022
## server
## File description:
## Makefile
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

SRC		=	handle_help.c	\
			args/handle_args.c	\
			args/check_arg_meaning.c	\
			args/add_arg_teams.c	\
			args/add_arg.c	\
			errors/missing_teams.c	\
			errors/malloc_error.c	\
			errors/arg_error.c	\
			errors/port_error.c	\
			game/fill_structs/new_contents.c	\
			game/fill_structs/new_game_tile.c	\
			game/fill_structs/new_player.c	\
			game/fill_structs/new_map.c	\
			game/fill_structs/new_game_data.c	\
			game/fill_structs/new_crds.c	\
			game/fill_structs/create_id.c	\
			game/destroy/destroy_teams.c	\
			game/destroy/destroy_game_data.c	\
			game/destroy/destroy_command.c	\
			game/destroy/destroy_player.c	\
			game/player_list/check_player_in_list.c	\
			game/player_list/add_player_to_list.c	\
			game/player_list/init_player.c	\
			game/player_list/get_player_list_size.c	\
			game/player_list/count_players_on_crds.c	\
			game/teams/add_team.c	\
			game/teams/check_if_team_name.c	\
			game/teams/get_player_team.c	\
			game/eggs/count_eggs.c	\
			game/eggs/create_egg.c	\
			game/eggs/handle_egg_life.c	\
			game/eggs/assign_egg_to_player.c	\
			game/eggs/destroy_egg.c	\
			game/commands/list/look/get_look_resp_len.c	\
			game/commands/list/look/fill_look_resp.c	\
			game/commands/list/look.c	\
			game/commands/list/forward.c	\
			game/commands/list/left.c	\
			game/commands/list/right.c	\
			game/commands/list/inventory.c	\
			game/commands/list/connect_nbr.c	\
			game/commands/list/eject.c	\
			game/commands/list/take.c	\
			game/commands/list/set.c	\
			game/commands/list/incantation.c	\
			game/commands/list/fork.c	\
			game/commands/list/broadcast.c	\
			game/commands/list/get_broadcast_k.c	\
			game/commands/execute_command.c	\
			game/commands/create_command.c	\
			game/commands/get_command_len.c	\
			game/commands/cycle_commands.c	\
			game/commands/get_command_enc_time.c	\
			game/commands/start_command.c	\
			game/elevation/handle_elevation_starts.c	\
			game/elevation/check_for_valid_elevation.c	\
			game/elevation/delete_elevation_ressources.c	\
			game/map/fill_map_data.c	\
			game/map/fill_map_contents.c	\
			game/map/handle_food_spawn.c	\
			game/map/get_tile.c	\
			game/map/refresh_map_contents.c	\
			game/map/fill_map_cnts_list.c	\
			game/handle_win.c	\
			game/handle_player_deaths.c	\
			game/get_number_of_runs.c	\
			game/run_game.c	\
			network/start_server/start_server.c	\
			network/start_server/create_server.c	\
			network/start_server/bind_server.c	\
			network/start_server/make_server_listen.c	\
			network/select/set_status.c	\
			network/select/get_select_num.c	\
			network/select/set_all_unready.c	\
			network/select/check_select.c	\
			network/connections/handle_accept.c	\
			network/connections/create_connection.c	\
			network/connections/accept_connection.c	\
			network/connections/handle_connection_ends.c	\
			network/connections/destroy_connections.c	\
			network/connections/close_connection.c	\
			network/buffer/new_buffer.c	\
			network/buffer/create_buff.c	\
			network/buffer/destroy_buffer.c	\
			network/buffer/destroy_all_buffers.c	\
			network/buffer/destroy_buff_command.c	\
			network/buffer/get_command_from_buff.c	\
			network/GUI/check_if_gui_cmd.c	\
			network/GUI/handle_gui_resp.c	\
			network/GUI/send_gui_info.c	\
			network/GUI/get_gui_cmd_code.c	\
			network/GUI/init_gui_connection.c	\
			network/GUI/send_gui_teams_list.c	\
			network/GUI/send_gui_all_tiles.c	\
			network/GUI/send_gui_elvtn_res.c	\
			network/GUI/send_gui_elvtn_start.c	\
			network/GUI/send_gui_broadcast.c	\
			network/GUI/send_gui_egg_laying.c	\
			network/GUI/send_gui_death.c	\
			network/GUI/send_all_gui_take.c	\
			network/GUI/send_all_gui_set.c	\
			network/GUI/send_gui_player_con.c	\
			network/GUI/send_gui_egg_death.c	\
			network/GUI/send_gui_egg_hatch.c	\
			network/GUI/send_gui_player_moved.c	\
			network/GUI/send_gui_player_info.c	\
			network/GUI/send_gui_tile_info.c	\
			network/AI/handle_player_command.c	\
			network/write/send_response.c	\
			network/write/write_on_socket.c	\
			network/read/read_message.c	\
			network/read/read_socket.c	\
			network/handle_responses.c	\
			network/run_server.c	\
			main.c

TESTS_SRC	=

$(eval SRC = $(addprefix src/, $(SRC)))

#	OBJECTS	#

OBJ	=	$(SRC:.c=.o)

TESTS_OBJ	=	$(TESTS_SRC:.c=.o)

#	NAME	#

NAME	=	zappy_server

TESTS_NAME	=	unit_tests

#	FLAGS	#

CFLAGS	=	-W -Wpedantic -Wall -Wextra -fno-builtin -I./include/ -luuid

TESTS_FLAGS	=	--coverage -lcriterion

#	RULES	#

all:	$(NAME)

$(NAME):	$(OBJ)
	@printf "\033[1;36m Compiling .C\n"
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)
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
