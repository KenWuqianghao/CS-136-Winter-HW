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

// This is the implementation of the generic hash table ADT with binary search 
//   trees.

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
struct hashtable {
  // Your fields go here.
};

// See hashtable.h for documentation
struct hashtable *ht_create(void *(*key_clone)(const void *),
                            int (*hash_func)(const void *, int), 
                            int hash_length,
                            int (*key_compare)(const void *, const void *),
                            void (*key_destroy)(void *),
                            void (*key_print)(const void *)) {
  // Your implementation goes here.
  return NULL;
}

// See hashtable.h for documentation
void ht_destroy(struct hashtable *ht) {
  // Your implementation goes here.
}

// See hashtable.h for documentation
int ht_insert(struct hashtable *ht, const void *key) {
  // Your implementation goes here.
  return -1;
}

// See hashtable.h for documentation
int ht_remove(struct hashtable *ht, const void *key) {
  // Your implementation goes here.
  return -1;
}

// See hashtable.h for documentation
void ht_print(const struct hashtable *ht) {
  // Your implementation goes here.
  // See string_public.expect and fancyline_public.expect for examples.
}