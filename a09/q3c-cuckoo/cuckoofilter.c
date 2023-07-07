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

// This is the implementation of the cuckoo filter ADT.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cs136-trace.h"
#include "cuckoofilter.h"
#include "random.h"

// -----------------------------------------------------------------------
// DO NOT CHANGE THESE
// See cuckoofilter.h for documentation
const int CUCKOO_SUCCESS = 0;
const int CUCKOO_FAILURE = 1;
// -----------------------------------------------------------------------

// See cuckoofilter.h for documentation
struct cuckoofilter {
  // Your fields go here.
};

// See cuckoofilter.h for documentation
struct cuckoofilter *cuckoo_create(int (*hash_func)(const char *, int), 
                                  int hash_len, int nof_entries, int fp_len, 
                                  int max_num_kicks) {
  // Your implementation goes here.
  return NULL;
}

// See cuckoofilter.h for documentation
void cuckoo_destroy(struct cuckoofilter *cf) {
  // Your implementation goes here.
}

// See cuckoofilter.h for documentation
int cuckoo_insert(struct cuckoofilter *cf, const char *key) {
  // Your implementation goes here.
  return -1;
}

// See cuckoofilter.h for documentation
bool cuckoo_lookup(const struct cuckoofilter *cf, const char *key) {
  // Your implementation goes here.
  return false;
}

// See cuckoofilter.h for documentation
int cuckoo_remove(struct cuckoofilter *cf, const char *key) {
  // Your implementation goes here.
  return -1;
}

// See cuckoofilter.h for documentation
void cuckoo_print(const struct cuckoofilter *cf) {
  // Your implementation goes here.
  // Use printf("%3d: ", foo); for printing labels for the entries.
}
