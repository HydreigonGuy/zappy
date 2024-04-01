/*
** EPITECH PROJECT, 2022
** server
** File description:
** get_broadcast_k
*/

#include "server.h"
#include <stdlib.h>

int calc_k_from_new_crds(crds_t s, crds_t r)
{
    if (r.y - s.y == r.x - s.x && r.x > s.x)
        return ((1 + 6 * r.facing) % 8 + 1);
    if (s.y - r.y == r.x - s.x && r.x > s.x)
        return ((3 + 6 * r.facing) % 8 + 1);
    if (r.y - s.y == s.x - r.x && s.x > r.x)
        return ((5 + 6 * r.facing) % 8 + 1);
    if (s.y - r.y == s.x - r.x && s.x > r.x)
        return ((7 + 6 * r.facing) % 8 + 1);
    if ((r.x - s.x) * (r.x - s.x) < (r.y - s.y) * (r.y - s.y) && r.y > s.y)
        return ((6 * r.facing) % 8 + 1);
    if ((r.x - s.x) * (r.x - s.x) < (r.y - s.y) * (r.y - s.y) && r.y < s.y)
        return ((4 + 6 * r.facing) % 8 + 1);
    if ((r.x - s.x) * (r.x - s.x) > (r.y - s.y) * (r.y - s.y) && r.x > s.x)
        return ((2 + 6 * r.facing) % 8 + 1);
    if ((r.x - s.x) * (r.x - s.x) > (r.y - s.y) * (r.y - s.y) && r.x < s.x)
        return ((6 + 6 * r.facing) % 8 + 1);
    return (0);
}

int calc_broadcast_k(crds_t *sndr, crds_t *recvr, int index, map_t *map)
{
    crds_t sender;
    crds_t reciever;

    sender.x = sndr->x;
    sender.y = sndr->y;
    reciever.x = recvr->x;
    reciever.y = recvr->y;
    reciever.facing = recvr->facing;
    if (index % 2 == 1)
        reciever.x += map->width;
    if ((index % 4) / 2 == 1)
        sender.x += map->width;
    if ((index % 8) / 4 == 1)
        reciever.y += map->heigth;
    if (index / 8 == 1)
        reciever.y += map->heigth;
    return (calc_k_from_new_crds(sender, reciever));
}

int get_broadcast_k(crds_t *sndr, crds_t *recvr, map_t *map)
{
    int index = 0;

    if (sndr->x == recvr->x && sndr->y == recvr->y)
        return (0);
    if (abs(sndr->x - recvr->x) > map->width - sndr->x + recvr->x)
        index++;
    if (abs(sndr->x - recvr->x) > map->width - recvr->x + sndr->x)
        index += 2;
    if (abs(sndr->y - recvr->y) > map->heigth - sndr->y + recvr->y)
        index += 4;
    if (abs(sndr->y - recvr->y) > map->heigth - recvr->y + sndr->y)
        index += 8;
    return (calc_broadcast_k(sndr, recvr, index, map));
}
