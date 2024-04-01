/*
** EPITECH PROJECT, 2022
** server
** File description:
** server
*/

#ifndef SERVER_H_

    #define SERVER_H_

    #include <netinet/in.h>
    #include <sys/time.h>

    enum Status {
        READ,
        WRITE,
        DEAD,
        DISCONNECTED
    };

    // quantity of each game material
    typedef struct contents_s {
        int food;
        int linemate;
        int deraumere;
        int sibur;
        int mendiane;
        int phiras;
        int thystame;
    } contents_t;

    // information about a game_tile
    typedef struct game_tile_s {
        // int x; int y;
        contents_t *contents;
    } game_tile_t;

    // list of commands a player must follow
    typedef struct command_s {
        char *command_str;
        int incantation;
        int started;
        struct command_s *next;
    } command_t;

    typedef struct crds_s {
        int x;
        int y;
        int facing;
    } crds_t;

    // info about a player
    typedef struct player_s {
        int level;
        char *id;
        contents_t *inventory;
        command_t *commands;
        crds_t *crds;
    } player_t;

    // list of players
    typedef struct player_list_s {
        player_t *player;
        struct player_list_s *next;
    } player_list_t;

    // game map data
    typedef struct map_s {
        int width;
        int heigth;
        int cooldown;
        game_tile_t **tiles;
    } map_t;

    typedef struct buffer_s {
        char *buff;
        struct buffer_s *next;
    } buffer_t;

    typedef struct server_s {
        int server_socket;
        struct sockaddr_in address;
        int can_accept;
        int stdin_ready;
    } server_t;

    typedef struct connection_s {
        int fd;
        player_t *player;
        enum Status status;
        int ready;
        int gui_con;
        buffer_t *read_buff;
        buffer_t *write_buff;
        struct connection_s *next;
    } connection_t;

    typedef struct egg_s {
        int time;
        char *id;
        crds_t *crds;
        connection_t *con;
        struct egg_s *next;
    } egg_t;

    // list of teams and their info
    typedef struct team_s {
        char *name;
        player_list_t *players;
        egg_t *eggs;
        struct team_s *next;
    } team_t;

    typedef struct game_data_s {
        map_t *map;
        player_list_t *players;
        team_t *teams;
        int frequency;
        int client_num;
        int port;
        struct timeval time_stamp;
    } game_data_t;

    #define FOOD_DENSITY    0.5f
    #define LINE_DENSITY    0.3f
    #define DERA_DENSITY    0.15f
    #define SIBU_DENSITY    0.1f
    #define MEND_DENSITY    0.1f
    #define PHIR_DENSITY    0.08f
    #define THYS_DENSITY    0.05f

    #define FACING_UP       0
    #define FACING_LEFT     1
    #define FACING_DOWN     2
    #define FACING_RIGHT    3

    #define FOOD_REFRESH    20
    #define SPAWN_LIFE      1260
    #define FOOD_TO_LIFE    126

    #define DEFAULT_WIDTH   20
    #define DEFAULT_HEIGHT  20

    #define DEFAULT_FREQUENCY   100
    #define DEFAULT_CLIENT_NUM  6

    #define MAX_BACKLOG 200
    #define BUFF_SIZE   2049
    #define READ_SIZE   1024

    // ---- GAME FUNCTIONS ----
    void run_game(game_data_t *data, connection_t *connects);
    int get_number_of_runs(game_data_t *data);
    void handle_player_deaths(game_data_t *data, connection_t *connect);
    void handle_win(game_data_t *data);

    // -- fill structs
    contents_t *new_contents(void);
    game_tile_t *new_game_tile(void);
    player_t *new_player(game_data_t *data);
    crds_t *new_crds(int max_width, int max_height);
    map_t *new_map(void);
    game_data_t *new_game_data(void);
    char *create_id(void);

    // -- destroy structs
    void destroy_game_data(game_data_t *data);
    void destroy_teams(team_t *teams);
    void destroy_command(command_t **cmd);
    void destroy_player(player_t *player, game_data_t *data, connection_t *);

    // -- player lists
    int check_player_in_list(player_t *player, player_list_t *list);
    void add_player_to_list(player_t *player, player_list_t **list);
    int init_player(connection_t *, char *, game_data_t *, connection_t *);
    int insert_new_player(connection_t *connect, game_data_t *data, team_t *);
    int get_player_list_size(player_list_t *list);
    int count_players_on_crds(player_list_t *players, int x, int y);

    // -- teams
    void add_team(team_t **teams, char *name);
    int check_if_team_name(char *name, team_t *teams);
    team_t *get_player_team(team_t *teams, player_t *player);

    // -- eggs
    int count_eggs(egg_t *eggs);
    egg_t *create_egg(egg_t **eggs, crds_t *crds);
    void handle_egg_life(game_data_t *data, connection_t *all);
    void assign_egg_to_player(connection_t *, egg_t *eggs);
    void destroy_egg(egg_t *egg, egg_t **);

    // -- commands
    void create_command(command_t **commands, char *command);
    int get_command_len(command_t *commands);
    void cycle_commands(game_data_t *data, connection_t *con);
    int get_command_enc_time(char *str);
    void start_command(player_t *player);
    void execute_command(char *, game_data_t *, connection_t *,
    connection_t *);

    // -- list of commands
    void forward(player_t *player, connection_t *, map_t *, connection_t *);
    void left(player_t *player, connection_t *con, connection_t *all);
    void right(player_t *player, connection_t *con, connection_t *all);
    void inventory(player_t *player, connection_t *con);
    void look(player_t *player, connection_t *con, game_data_t *data);
    void connect_nbr(connection_t *con, game_data_t *data);
    void eject(connection_t *con, game_data_t *data, connection_t *);
    void take(char *obj, connection_t *con, game_data_t *, connection_t *);
    void set(char *obj, connection_t *con, game_data_t *, connection_t *);
    void incantation(connection_t *con, game_data_t *data, connection_t *);
    void myfork(connection_t *con, game_data_t *data, connection_t *all);
    void broadcast(char *msg, connection_t *, connection_t *, map_t *);
    int get_broadcast_k(crds_t *sndr, crds_t *recvr, map_t *map);

    // -- extra functions for look
    int get_look_resp_len(int level, crds_t *crds, game_data_t *data);
    void fill_look_resp(int level, crds_t *crds, game_data_t *data, char *);

    // -- elevations
    void handle_elevation_starts(game_data_t *data, connection_t *connects);
    int check_for_valid_elevation(connection_t *con, game_data_t *data);
    void delete_elevation_ressources(game_tile_t *tile, int level);

    // -- map
    void fill_map_data(map_t *map);
    void fill_map_contents(map_t *map);
    void handle_food_spawn(map_t *map);
    game_tile_t *get_tile(map_t *map, int x, int y);
    void refresh_map_contents(map_t *map);
    int *fill_map_cnts_list(map_t *map);

    // ---- NETWORK FUNCTIONS ----
    void run_server(server_t *server, game_data_t *);
    void handle_responses(connection_t *connect, game_data_t *data);

    // -- start server
    int start_server(game_data_t *data);
    server_t *create_server(int port);
    int bind_server(server_t *server);
    int make_server_listen(server_t *server);

    // -- select handelling
    void check_select(server_t *server, connection_t *connect);
    void set_status(connection_t *connect);
    int get_select_num(int server, connection_t *con);
    void set_all_unready(server_t *server, connection_t *connect);

    // -- connections
    void handle_accept(server_t *server, connection_t **connect);
    int accept_connection(server_t *server);
    void create_connection(connection_t **connect, int fd);
    void handle_connection_ends(connection_t **connect, game_data_t *data);
    void destroy_connections(connection_t **connect, game_data_t *data);
    void close_connection(connection_t *, game_data_t *, connection_t *);

    // -- write
    void send_response(connection_t *connect);
    void write_on_socket(int fd, buffer_t **buff);

    // -- read
    void read_message(connection_t *connect);
    int read_socket(int fd, buffer_t **buff);

    // -- buffers
    buffer_t *new_buffer(void);
    void create_buff(buffer_t **buff, char *str);
    void destroy_all_buffers(buffer_t *buff);
    void destroy_buffer(buffer_t **buff);
    int find_command_end(char *str);
    void destroy_buff_command(buffer_t **buff);
    char *get_command_from_buff(buffer_t **buff);

    // -- GUI
    void handle_gui_resp(connection_t *, game_data_t *, connection_t *);
    void send_gui_info(char *, connection_t *, game_data_t *data);
    int check_if_gui_cmd(char *str);
    int get_gui_cmd_code(char *str);
    void init_gui_connection(connection_t *con, game_data_t *data);
    void send_gui_teams_list(connection_t *con, team_t *teams);
    void send_gui_all_tiles(connection_t *con, game_data_t *data);
    void send_gui_elvtn_res(connection_t *con, crds_t *crds, int res);
    void send_gui_elvtn_start(connection_t *con, player_t *player);
    void send_gui_broadcast(connection_t *con, player_t *player, char *msg);
    void send_gui_egg_laying(connection_t *con, player_t *player, egg_t *);
    void send_gui_death(connection_t *con, player_t *player);
    void send_all_gui_take(connection_t *all, crds_t *crds, int item);
    void send_all_gui_set(connection_t *all, crds_t *crds, int item);
    void send_gui_player_con(connection_t *con, char *id, crds_t *crds);
    void send_gui_egg_death(connection_t *all, char *id);
    void send_gui_egg_hatch(connection_t *all, egg_t *egg);
    void send_gui_player_moved(connection_t *all, player_t *player);
    void send_gui_player_info(connection_t *con, game_data_t *data, char *cmd);
    void send_gui_tile_info(connection_t *con, map_t *map, char *cmd);

    // -- AI
    void handle_player_command(connection_t *connect);

    // ---- ARGUMENT HANDELLING ----
    int handle_args(int ac, char **av);
    int add_arg(char **av, int i, game_data_t *game_data);
    int add_arg_teams(int i, int max, char **av, game_data_t *game_data);
    int check_arg_meaning(char *str);

    // ---- ERRORS ----
    int missing_teams(game_data_t *data);
    int malloc_error(void);
    int arg_error(void);
    int port_error(game_data_t *data);

    // ---- OTHER ----
    int handle_help(char *arg);

#endif /* !SERVER_H_ */
