#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
typedef struct key {
    char *word;
    struct key *next;
}key;

struct hash_t {
    key **bucket;
    unsigned int size, fill;
};

hash_t* hash_table_new(unsigned int size){
    hash_t *table = malloc(sizeof(hash_t));
    table->bucket = malloc(sizeof(key *) * size);
    table->size = size;
    table->fill = 0;

    memset(table->bucket, 0, sizeof(key*) * size);
    return table;
}

void hash_table_destroy(hash_t* table){
    for (unsigned int i = 0; i < table->size; i++){
        key *temp = table->bucket[i];
        while (table->bucket[i] != NULL){
            temp = table->bucket[i];
            table->bucket[i] = temp->next; 
            free(temp->word);
            free(temp);
        }
    }
    free(table);
}

unsigned int hash_function(char *word, int size){
    unsigned int hash = 0;
    for (; *word; word++){
        hash = hash + *word;
    }
    return hash % size;
}

void hash_table_insert(hash_t* table, void* word, void* value){
    unsigned int hash = hash_function(word, table->size);
    key *bucket = table->bucket[hash];
    key *newkey = malloc(sizeof(key));
    newkey->word = word;
    newkey->next = bucket;
    table->bucket[hash] = newkey;

    table->fill++;

}

void* hash_table_lookup(hash_t* table, void* word){
    unsigned int hash = hash_function(word, table->size);
    key *bucket = table->bucket[hash];
    while(bucket != NULL){
        if (!strcmp(bucket->word, word)){
            return table;
        }
        bucket = bucket->next;
    }
    return NULL;
}

unsigned int hash_table_size(hash_t* table){
    return table->size;
}

unsigned int hash_table_fill(hash_t* table){
    return table->fill;
}
