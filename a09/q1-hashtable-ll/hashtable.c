/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// Name: Qianghao Wu
// login ID: 20999205
//////////////////////////////////////////////////////////////////////////////////////////

// This is the implementation of the hash tree ADT with linked lists.

#include <stdlib.h>
#include "hashtable.h"
#include "cs136-trace.h"

// -----------------------------------------------------------------------
// DO NOT CHANGE THESE
// See hashtable.h for documentation
const int HT_SUCCESS        = 0;
const int HT_ALREADY_STORED = 1;
const int HT_NOT_STORED     = 2;
// -----------------------------------------------------------------------

// See hashtable.h for documentation
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "hashtable.h"
#include "cs136-trace.h"

// See hashtable.h for documentation
char *get_strdup(const char *s) {
    size_t len = strlen(s) + 1;
    char *dest = malloc(len);
    if (dest == NULL) {
        return NULL;
    }
    for (size_t i = 0; i < len; i++) {
        dest[i] = s[i];
    }
    return dest;
}

struct node {
    char *key;
    struct node *next;
};

struct hashtable {
    struct node **table;
    int length;
    int (*hash_func)(const char *, int);
    int hash_length;
};

struct hashtable *ht_create(int (*hash_func)(const char *, int), int hash_length) {
    assert(hash_func > 0);
    assert(hash_length > 0);

    struct hashtable *htable = malloc(sizeof(struct hashtable));
    if (htable == NULL) {
        return NULL;
    }

    htable->table = calloc(1 << hash_length, sizeof(struct node *));
    if (htable->table == NULL) {
        free(htable);
        return NULL;
    }

    htable->length = 1 << hash_length;
    htable->hash_func = hash_func;
    htable->hash_length = hash_length;

    return htable;
}

void ht_destroy(struct hashtable *ht) {
    if (ht == NULL) {
        return;
    }

    for (int i = 0; i < ht->length; i++) {
        struct node *temp = ht->table[i];
        while (temp != NULL) {
            struct node *tmp = temp;
            temp = temp->next;
            free(tmp->key);
            free(tmp);
        }
    }

    free(ht->table);
    free(ht);
}

int ht_insert(struct hashtable *ht, const char *str) {
    int value = ht->hash_func(str, ht->hash_length);

    struct node *temp = ht->table[value];
    while (temp != NULL) {
        if (strcmp(temp->key, str) == 0) {
            return HT_ALREADY_STORED;
        }
        temp = temp->next;
    }

    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        return HT_NOT_STORED;
    }

    new_node->key = get_strdup(str);
    new_node->next = ht->table[value];
    ht->table[value] = new_node;

    return HT_SUCCESS;
}

int ht_remove(struct hashtable *ht, const char *str) {
    int value = ht->hash_func(str, ht->hash_length);

    struct node **before = &ht->table[value];
    struct node *now = *before;

    while (now != NULL) {
        if (strcmp(now->key, str) == 0) {
            *before = now->next;
            free(now->key);
            free(now);
            return HT_SUCCESS;
        }
        before = &now->next;
        now = *before;
    }

    return HT_NOT_STORED;
}

void ht_print(const struct hashtable *ht) {
  for (int i = 0; i < ht->length; i++) {
    printf("%d: ", i);
    struct node *temp = ht->table[i];
    while (temp != NULL) {
      printf("%s", temp->key);
      if (temp->next != NULL) {
        printf(" -> ");
      }
      temp = temp->next;
    }
    printf("\n");
  }
}