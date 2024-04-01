/*
** EPITECH PROJECT, 2022
** ia
** File description:
** ia
*/

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <list>

extern "C" {
    #include "./include/client.h"
}

extern "C" {
    void handle_selecting(client_t *client);
    void create_buff(buffer_t **buff, const char *str);
    client_t *settup_client(int port, char *ip);
}

class IA {
    public:
        IA(int argc, char **argv);
        ~IA();
        void forward();
        void left();
        void right();
        void look();
        void inventory();
        void broadcast(std::string msg);
        void connect_nbr();
        void fork();
        void eject();
        void take_object(std::string object);
        void set_object(std::string object);
        void incantation();
        client_t *client;
        buffer_t *head;
        buffer_t *current_head;
        int _level;
        std::string _role;
        std::string _team;
        int _food;
        std::string _inventory;
};