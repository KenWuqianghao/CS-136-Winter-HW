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

// Implementation of a string stack (sstack) ADT

// This is a "wrapper" ADT that provides a stack ADT interface, but all of the data
// is actually stored inside of an SOS ADT

// IMPORTANT: Each of the functions should only be a few lines long

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "cs136-trace.h"
#include "sos.h"
#include "sstack.h"

//////////////////////////////////////////////////////////////////////////////
// DO NOT MODIFY THE FOLLOWING DEFINITIONS

struct sstack {
  struct sos *seq;
};

// we have provided sstack_is_empty() for you :)

// see sstack.h
bool sstack_is_empty(const struct sstack *ss) {
  assert(ss);
  return sos_length(ss->seq) == 0;
}

//////////////////////////////////////////////////////////////////////////////

struct sstack *sstack_create(void) {
  struct sstack *new_sstack = malloc(sizeof(struct sstack));
  new_sstack->seq = sos_create();
  return new_sstack;
}

const char *sstack_top(const struct sstack *ss) {
  assert(ss);
  return sos_item_at(ss->seq, sos_length(ss->seq) - 1);
}

char *sstack_pop(struct sstack *ss) {
  assert(ss);
  char *top = malloc(sizeof(char) * (strlen(sstack_top(ss)) + 1));
  strcpy(top, sstack_top(ss));
  sos_remove_at(ss->seq, sos_length(ss->seq) - 1);
  return top;
}

void sstack_push(const char *str, struct sstack *ss) {
  assert(ss);
  assert(str);
  sos_insert_end(ss->seq, str);
}

void sstack_destroy(struct sstack *ss) {
  assert(ss);
  sos_destroy(ss->seq);
  free(ss);
}