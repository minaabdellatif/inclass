//CS 315 Lab 1
//replace.c

//#include "replace.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "map.h"
#include "map.c"

//returns a char*
char *replace(char *input, char *key, char *value)
{
    int count = 0;
    int i = 0;
    int keyLen = strlen(key);
    int valueLen = strlen(value);

    for (i=0; input[i] != '\0'; i++)
    {
        char *text_pointer = &input[i];
        char *result = strstr (text_pointer, key);

        if (text_pointer == result)
        {
            count++;
            i+= keyLen-1;
        }
    }
    int diff = (valueLen - keyLen);
    char *out_string = (char*) malloc((count * diff) + i + 1);
    i = 0;

    while (*input != '\0')
    {
        if (strstr(input, key) == input)
        {
            char *new_pointer = &out_string[i];
            strcpy (new_pointer, value);
            i += valueLen;
            input += keyLen;
        }
        else
        {
            out_string[i] = *input;
            input++;
            i++;
        }
        
    }
    return out_string;
}

int main(int argc, char** argv) //Arg c = total num of command line args, Argv = array that holds each of the comm line args
{
    //create map and adding all key value pairs to map
    struct map map_m;
    map_init(&map_m);
    struct map* map_pointer = &map_m;

    for (int i=3; i<argc; i+=2)
    {
        map_add(map_pointer, argv[i], argv[i+1]); //add to map, Argv[i] gives key, argv[i+1] gives value
    }

    //reading from the input file into a string called input
    FILE *file_pointer;
    long fileLen;
    char *input;
    file_pointer = fopen(argv[1], "r");
    fseek(file_pointer, 0L, SEEK_END);
    fileLen = ftell(file_pointer);
    rewind(file_pointer);
    input = calloc(1, fileLen + 1);
    fread(input, sizeof(char), fileLen, file_pointer);
    //printf("%s\n", input);
    char *result;

    for (int i=0; i<map_pointer->count; i++)
    {
        char *key = map_pointer->table[i].key;
        char *value = map_pointer->table[i].value;
        result = replace(input, key, value);
        input = result;
    }

    FILE *file = fopen(argv[2], "w");

    fputs(result, file);

    fclose(file_pointer);
    fclose(file);
    
    return 0;

}