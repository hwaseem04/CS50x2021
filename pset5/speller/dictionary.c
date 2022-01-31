// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

//Total words in dictionary
unsigned int total_words;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 65536;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Checking if the word exist in Dictionary
    unsigned int hash_no = 0;
    
    int size = strlen(word) ;
    char *copy = malloc(size + 1);
    
    for (int i = 0; i < size; i++)
    {
        copy[i] = tolower(word[i]);
    }
        
    copy[size] = '\0';
    
    hash_no = hash(copy);
    
    node *initial = table[hash_no];
    
    while (initial != NULL)
    {
        if (strcmp(initial->word, copy) == 0)
        {
            // word is in dictionary
            free(copy);
            return true;
        }
        else
        {
            // check next node
            initial = initial->next;
        }
    }
    free(copy);
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // source : stackoverflow
    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash << 2) ^ word[i];
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // loading the words
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Unable to open dictionary file \n");
        return 1;
    }
    //for (int i = 0; i < N; i++)
    //{
    //    table[i] = NULL;
    //}
    while (true)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Unable to allocate memory\n");
            return false;
        }
        
        fscanf(file, "%s", n->word);
        n -> next = NULL;
        
        if (feof(file))
        {
            free(n);
            break;
        }
        total_words ++;
        
        unsigned int hash_no = hash(n->word);
        
        
        if (table[hash_no] == NULL)
        {
            table[hash_no] = n;
        }
        else
        {
            n->next = table[hash_no];
            table[hash_no] = n;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // printing out the size
    return total_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Unloading the words
    node *initial = NULL;
    for (int i = 0; i < N; i++)
    {
        initial = table[i];
        while (initial != NULL)
        {
            node *tmp = initial -> next;
            free(initial);
            initial = tmp;
        }
    }
    return true;
}
