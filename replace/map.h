#ifndef _MAP_H
#define _MAP_H

#define MAP_KEY_LEN 64
#define MAP_VALUE_LEN 64
#define MAP_TABLE_LEN 128

struct pair {
    char* key;
    char* value;
};

struct map {
    struct pair table[MAP_TABLE_LEN]; 
    int count;
};

void map_init(struct map *map);
void map_add(struct map *map, char *key, char *value);
char * map_lookup(struct map *map, char *key);

#endif