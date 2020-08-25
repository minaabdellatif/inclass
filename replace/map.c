//map.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "map.h"

//set list (array of pair structs) to empty and set count to zero
void map_init(struct map *map_m)
{
    //set map.tables to an array of pairs
    //map is a struct, table is the array in the struct of key value pair objects

    //map.table is empty
    map_m->count = 0;  
}

//create new key value pair and add to the array (table in map (in parameters of map_add)) and incrememnt count by 1
void map_add(struct map *map_m, char *key, char *value)
{
    //struct pair p = {.key=*key, .value:*value};
    struct pair p = {.key= key, .value= value};
    map_m->table[map_m->count] = p;
    map_m->count += 1;
}

//given map and key to look for, iterate through map.table (array containing all pairs) and checks if the key = key I have, then return value
char * map_lookup(struct map *map_m, char *key)
{
    //use for loop, iterate through table to see if key = key in this parameter, if yes return the value associate w that key
    for (int i=0; i<map_m->count; i++)
    {
        if (strcmp(map_m->table[i].key,key) == 0)
        {
            return map_m->table[i].value;
        }
    }
    return NULL;
}