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

// This is the implementation of the counting Bloom filter ADT.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "countingbloomfilter.h"

// -----------------------------------------------------------------------
// DO NOT CHANGE THESE
// See countingbloomfilter.h for documentation
const int CBF_SUCCESS = 0;
const int CBF_FAILURE = 1;
// -----------------------------------------------------------------------

// See countingbloomfilter.h for documentation
struct countingbloomfilter {
    int **tables;
    int hash_len;
    int nof_tables;
    int (*hash_funcs[5])(const char *, int);
};

struct countingbloomfilter *cbf_create(int (**hash_funcs)(const char *, int), int hash_len, int nof_tables) { 
    struct countingbloomfilter *cbf = (struct countingbloomfilter *)malloc(sizeof(struct countingbloomfilter));
    
    cbf->hash_len = hash_len;
    cbf->nof_tables = nof_tables;
    
    for (int i = 0; i < 3; i++) {
        cbf->hash_funcs[i] = hash_funcs[i];
    }
    
    cbf->tables = (int **)calloc(nof_tables, sizeof(int *));
    
    for (int i = 0; i < nof_tables; i++) {
        cbf->tables[i] = (int *)calloc(1 << hash_len, sizeof(int));
    }
    
    return cbf;
}

void cbf_destroy(struct countingbloomfilter *cbf) {
    for (int i = 0; i < cbf->nof_tables; i++) {
        free(cbf->tables[i]);
    }
    
    free(cbf->tables);
    free(cbf);
}

void cbf_insert(struct countingbloomfilter *cbf, const char *key) {
    for (int i = 0; i < cbf->nof_tables; i++) {
        int value = cbf->hash_funcs[i](key, cbf->hash_len);
        cbf->tables[i][value] += 1;
    }
}

bool cbf_lookup(const struct countingbloomfilter *cbf, const char *key) {
    for (int i = 0; i < cbf->nof_tables; i++) {
        int value = cbf->hash_funcs[i](key, cbf->hash_len);
        if (cbf->tables[i][value] <= 0) {
            return false;
        }
    }
    return true;
}

int cbf_remove(struct countingbloomfilter *cbf, const char *key) {
    bool removeable = true;
    for (int i = 0; i < cbf->nof_tables; i++) {
        int value = cbf->hash_funcs[i](key, cbf->hash_len);
        if (cbf->tables[i][value] <= 0) {
            removeable = false;
            break;
        }
    }
    if (removeable) {
        for (int i = 0; i < cbf->nof_tables; i++) {
            int hash_value = cbf->hash_funcs[i](key, cbf->hash_len);
            cbf->tables[i][hash_value]--;
        }
        return CBF_SUCCESS;
    } 
    else {
        return CBF_FAILURE;
    }
}

void cbf_print(const struct countingbloomfilter *cbf) {
    for (int i = 0; i < cbf->nof_tables; i++) {
        printf("table %d:\n", i);
        for (int j = 0; j < (1 << cbf->hash_len); j++) {
            printf("  %d\n", cbf->tables[i][j]);
        }
    }
}
