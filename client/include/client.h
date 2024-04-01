/*
** EPITECH PROJECT, 2022
** client
** File description:
** client
*/

#ifndef CLIENT_H_
    #define CLIENT_H_

    #include <netinet/in.h>

    enum Status {
        READ,
        WRITE,
        DISCONNECTED
    };

    typedef struct buffer_s {
        char *buff;
        struct buffer_s *next;
    } buffer_t;

    typedef struct client_s {
        int socket;
        struct sockaddr_in address;
        enum Status status;
        int ready;
        int shutdown;
        buffer_t *read_buff;
        buffer_t *write_buff;
    } client_t;

    #define READ_SIZE   1024

    // SETUP
    client_t *settup_client(int port, char *ip);
    void fill_client_info(client_t *client, int port, char *ip);

    // SELECT
    void handle_selecting(client_t *client);
    void set_status(client_t *client);
    void check_select(client_t *client);
    void write_on_socket(int fd, buffer_t **w_buff);
    void destroy_buffer(buffer_t **buff);
    void read_message(client_t *client);
    void send_response(client_t *client);
    int read_socket(int fd, buffer_t **buff);

    // WRITE
    void create_buff(buffer_t **buff, const char *str);
    buffer_t *new_buffer(void);

#endif /* !CLIENT_H_ */
