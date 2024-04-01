/*
** EPITECH PROJECT, 2022
** server
** File description:
** create_id
*/

#include <stdlib.h>
#include <uuid/uuid.h>

#define UUID_LEN 37

char *create_id(void)
{
    uuid_t uuid;
    char *id = malloc(sizeof(char) * UUID_LEN);

    if (!id)
        return (NULL);
    uuid_generate(uuid);
    uuid_unparse(uuid, id);
    return (id);
}
