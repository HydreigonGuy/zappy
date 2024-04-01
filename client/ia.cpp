/*
** EPITECH PROJECT, 2022
** ia
** File description:
** ia
*/

#include "ia.hpp"

void choose_member(IA ia);

IA::IA(int argc, char **argv)
{
    if (argc == 7) {
        client = settup_client(atoi(argv[2]), argv[6]);
    } else {
        client = settup_client(atoi(argv[2]), "1.27.0.0.1");
    }
    _level = 1;
    _role = "";
    _team = "";
    _inventory = "";
    _food = 1260;
    if (client) {
        head = client->read_buff;
        current_head = client->read_buff;
    }
}

IA::~IA()
{
}


void IA::forward() {
    create_buff(&client->write_buff, "Forward\n");
    handle_selecting(client);
}

void IA::left() {
    create_buff(&client->write_buff, "Left\n");
    handle_selecting(client);
}

void IA::right() {
    create_buff(&client->write_buff, "Right\n");
    handle_selecting(client);
}

void IA::look() {
    create_buff(&client->write_buff, "Look\n");
    handle_selecting(client);
}

void IA::inventory() {
    create_buff(&client->write_buff, "Inventory\n");
    handle_selecting(client);
}

void IA::broadcast(std::string msg) {
    msg = "Broadcast " + msg + "\n";
    create_buff(&client->write_buff, msg.c_str());
    handle_selecting(client);
}

void IA::connect_nbr() {
    create_buff(&client->write_buff, "Connect_nbr\n");
    handle_selecting(client);
}

void IA::fork() {
    create_buff(&client->write_buff, "Fork\n");
    handle_selecting(client);
}

void IA::eject() {
    create_buff(&client->write_buff, "Eject\n");
    handle_selecting(client);
}

void IA::take_object(std::string object) {
    std::string msg = "Take " + object + "\n";
    create_buff(&client->write_buff, msg.c_str());
    handle_selecting(client);
}

void IA::set_object(std::string object) {
    std::string msg = "Set " + object + "\n";
    create_buff(&client->write_buff, msg.c_str());
    handle_selecting(client);
}

void IA::incantation() {
    create_buff(&client->write_buff, "Incantation\n");
    handle_selecting(client);
}

void wait(client_t *client) {
    while (client->read_buff == NULL) {
        handle_selecting(client);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int show_help() {
    std::cout << "Usage: ./zappy_ai -p port -n name -h machine" << std::endl;
    std::cout << "\tport\tis the port number" << std::endl;
    std::cout << "\tname\tis the name of the team" << std::endl;
    std::cout << "\tmachine\tis the name of the machine; localhost by default" << std::endl;
    return (84);
}

int count_occurence(std::string line, std::string to_find) {
    int count = 0;
    std::string str = line;
    while (str.find(to_find) != std::string::npos) {
        str = str.substr(str.find(to_find) + to_find.length());
        count++;
    }
    return (count);
}

bool check_last_connection(IA ia)
{
    std::string line;
    line = ia.client->read_buff->buff;
    ia.current_head = ia.client->read_buff->next;
    line = line.substr(line.find_first_of("\n") + 1, line.size());
    line = line.substr(0, line.find_first_of("\n"));
    if (line == "0")
        return (true);
    return false;
}

int check_msg(IA ia, std::string msg)
{
    std::string line;
    int counter = 0;
    ia.client->read_buff = ia.current_head;
    while (ia.client->read_buff != NULL) {
        line = ia.client->read_buff->buff;
        if (line.find(msg) != std::string::npos) {
            counter += 1;
        } else {
            destroy_buffer(&ia.client->read_buff);
        }
    }
    ia.client->read_buff = ia.current_head;
    return counter;
}

std::string get_look_result(IA ia)
{
    ia.client->read_buff = ia.current_head;
    wait(ia.client);
    std::string line = ia.client->read_buff->buff;
    while (line.find("[") == std::string::npos) {
        ia.client->read_buff = ia.client->read_buff->next;
        wait(ia.client);
        line = ia.client->read_buff->buff;
    }
    if (line.find("message") == std::string::npos)
        destroy_buffer(&ia.client->read_buff);
    ia.client->read_buff = ia.current_head;
    return line;
}

std::string get_msg(IA ia, std::string msg)
{
    ia.client->read_buff = ia.current_head;
    wait(ia.client);
    std::string line = ia.client->read_buff->buff;
    while (line.find(msg) == std::string::npos) {
        ia.client->read_buff = ia.client->read_buff->next;
        wait(ia.client);
        line = ia.client->read_buff->buff;
    }
    destroy_buffer(&ia.client->read_buff);
    ia.client->read_buff = ia.current_head;
    return line;
}

void get_incantation_confirmation(IA ia)
{
    ia.client->read_buff = ia.current_head;
    wait(ia.client);
    std::string line(ia.client->read_buff->buff);
    while (line.find("Elevation underway") == std::string::npos) {
        ia.client->read_buff = ia.client->read_buff->next;
        wait(ia.client);
        line = ia.client->read_buff->buff;
    }
    if (line.find("message") == std::string::npos)
        destroy_buffer(&ia.client->read_buff);
    ia.client->read_buff = ia.current_head;
}

void wait_delete(IA ia)
{
    ia.client->read_buff = ia.current_head;
    wait(ia.client);
    std::string line(ia.client->read_buff->buff);
    while (line.find("ok") == std::string::npos && line.find("ko") == std::string::npos) {
        ia.client->read_buff = ia.client->read_buff->next;
        wait(ia.client);
        line = ia.client->read_buff->buff;
    }
    if (line.find("message") == std::string::npos)
        destroy_buffer(&ia.client->read_buff);
    ia.client->read_buff = ia.current_head;
}

void harvest(IA ia)
{
    ia._role = "Harvest";
    ia.incantation();
    get_incantation_confirmation(ia);
    int counter = 0;
    while (1) {
        while(check_msg(ia, "Arthouuur ?") == 0) {
            ia.look();
            std::string line = get_look_result(ia);
            line = line.substr(0, line.find_first_of(","));
            line = line.substr(line.find_first_of("[") + 2);
            if (count_occurence(line, "player") == 1) {
                while (line.find_first_of(" ") != std::string::npos) {
                    std::string tmp = line.substr(0, line.find_first_of(" "));
                    if (tmp != "player")
                        ia.take_object(tmp);
                        wait_delete(ia);
                    line = line.substr(line.find_first_of(" ") + 1);
                }
            }
            counter += 1;
            if (counter < 10) {
                ia.forward();
            } else {
                counter = 0;
                ia.right();
                ia.forward();
                ia.left();
            }
            wait(ia.client);
            if (check_msg(ia, "Food ?") == 1) {
                ia.inventory();
                ia._inventory = get_look_result(ia);
                std::string food = ia._inventory.substr(ia._inventory.find_first_of("food ") + 5);
                ia._food = atoi(food.c_str());
                ia.broadcast(std::to_string(ia._food));
                wait(ia.client);
            }
            if (check_msg(ia, std::to_string(ia._food)) == 1) {
                std::string line = get_msg(ia, "Team ");
                ia._team = line.substr(line.find_first_of("Team ") + 1);
                if (line.find_first_of("Member") == std::string::npos) {
                    ia._role = "Leader";
                    choose_member(ia);
                    return;
                } else {
                    ia._role = "Member";
                    choose_member(ia);
                    return;
                }
            }
        }
        ia.broadcast("Couillère !");
    }
}

void get_lv_two(IA ia)
{
    int counter = 0;
    while(1) {
        ia.look();
        std::string line = get_look_result(ia);
        line = line.substr(0, line.find_first_of(","));
        if (count_occurence(line, "player") == 1 && count_occurence(line, "linemate") > 0) {
            harvest(ia);
            return;
        } else if (int i = count_occurence(line, "food") > 0) {
            while (i > 0) {
                ia.take_object("food");
                wait(ia.client);
                i--;
            }
        }
        counter += 1;
        if (counter < 10) {
            ia.forward();
        } else {
            counter = 0;
            ia.right();
            ia.forward();
            ia.left();
        }
        wait(ia.client);
        check_msg(ia, "message");
    }
}

void move_head(IA ia) {
    ia.client->read_buff = ia.head;
    while (ia.client->read_buff != NULL) {
        destroy_buffer(&ia.client->read_buff);
    }
    ia.current_head = ia.client->read_buff;
}

std::string get_max_food(IA ia)
{
    ia.client->read_buff = ia.current_head;
    std::string line = ia.client->read_buff->buff;
    std::list<int> foodlist;
    while (ia.client->read_buff != NULL) {
        line = ia.client->read_buff->buff;
        foodlist.push_back(atoi(line.c_str()));
        ia.client->read_buff = ia.client->read_buff->next;
    }
    ia.current_head = ia.client->read_buff;
    int max = 0;
    for (std::list<int>::iterator it = foodlist.begin(); it != foodlist.end(); ++it) {
        if (*it > max)
            max = *it;
    }
    return std::to_string(max);
}

int get_player_without_team(std::string team)
{
    if (team == "Team 1") {
        return 7;
    } else if (team == "Team 2") {
        return 5;
    } else if (team == "Team 3") {
        return 3;
    } else {
        return 1;
    }
}

void choose_member(IA ia) {
    move_head(ia);
    ia.broadcast("Food ?");
    wait(ia.client);
    int player = get_player_without_team(ia._team);
    while(check_msg(ia, "message") <  player) {
        ia.look();
        std::string line = get_look_result(ia);
        line = line.substr(0, line.find_first_of(","));
        if (int j = count_occurence(line, "food") > 0) {
            while (j > 0) {
                ia.take_object("food");
                wait(ia.client);
                j--;
            }
        }
        ia.forward();
        wait(ia.client);
    }
    std::string max_food = get_max_food(ia);
    if (ia._role == "Leader") {
        ia.broadcast(max_food + "Member " + ia._team);
        wait(ia.client);
        // la suite : ramasser de la bouffe, check food, check pierre, ramener son partenaire
        return;
    } else {
        int tmp = atoi(ia._team.substr(ia._team.find_first_of("Team ") + 5).c_str());
        tmp = tmp + 1;
        ia.broadcast(max_food + "Team " + std::to_string(tmp));
        wait(ia.client);
        // ramasser bouffe et pierre et attendre ordre
        return;
    }
}

void choose_leader(IA ia) {
    move_head(ia);
    ia.broadcast("Food ?");
    wait(ia.client);
    while(check_msg(ia, "message") < 7) {
        ia.look();
        std::string line = get_look_result(ia);
        line = line.substr(0, line.find_first_of(","));
        if (int j = count_occurence(line, "food") > 0) {
            while (j > 0) {
                ia.take_object("food");
                wait(ia.client);
                j--;
            }
        }
        ia.forward();
        wait(ia.client);
    }
    std::string max_food = get_max_food(ia);
    ia.broadcast(max_food + "Team 1");
    wait(ia.client);
    get_lv_two(ia);
}

void default_behaviour(IA ia)
{
    if (!check_last_connection(ia)) {
        get_lv_two(ia);
        return;
    } else {
        ia.broadcast("Arthouuur ?");
        move_head(ia);
        wait(ia.client);
        if (check_msg(ia, "Couillère !") < 7) {
            ia.fork();
            get_lv_two(ia);
            return;
        } else {
            choose_leader(ia);
            return;
        }
    }
}

int main(int argc, char **argv) 
{
    if (argc != 5 && argc != 7)
        return (show_help());
    IA ia(argc, argv);
    if (!ia.client)
        return (84);
    std::string team = argv[4];
    team = team + "\n";
    create_buff(&ia.client->write_buff, team.c_str());
    wait(ia.client);
    default_behaviour(ia);
    return 0;
}