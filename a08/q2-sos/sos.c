// This is the implementation of the sequence of strings (sos) ADT

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cs136-trace.h"
#include "string-io.h"
#include "sos.h"

//////////////////////////////////////////////////////////////////////////////
// DO NOT MODIFY THE FOLLOWING DEFINITIONS

struct sos {
  int len;
  int maxlen;
  char **data;
};

// we have provided sos_read() for you :)
// also, there is no need for you to test sos_read()

// see sos.h
struct sos *sos_read(void) {
  struct sos *seq = sos_create();
  while (1) {
    char *line = read_line();
    if (line == NULL) {
      break;
    }
    sos_insert_end(seq, line);
    free(line);
  }
  return seq;
}

//////////////////////////////////////////////////////////////////////////////

// The following are the functions you must implement

// We recommend that you complete them in the order below, as that may help
// facilitate your testing

// For example, we recommend you write the first few functions
// (create,destroy,length,insert_end,print)
// and then create your own simple tests (.in files) that sufficiently test
// those functions

// Once those functions are tested and debugged, write just one function
// at a time and test it before moving on to the next funciton

// Attempting to write all of the functions before you do any debugging or
// testing is an unwise strategy

//////////////////////////////////////////////////////////////////////////////

struct sos *sos_create(void) {
  struct sos *new_seq = malloc(sizeof(struct sos));
  new_seq->len = 0;
  new_seq->maxlen = 1;
  new_seq->data = malloc(sizeof(char *) * new_seq->maxlen);
  assert(new_seq->data);
  return new_seq;
}

void sos_destroy(struct sos *seq) {
  assert(seq);
  for (int i = 0; i < seq->len; i++) {
    free(seq->data[i]);
  }

  free(seq->data);
  free(seq);
}

int sos_length(const struct sos *seq) {
  return seq->len;
}

void sos_insert_end(struct sos *seq, const char *s) {
  sos_insert_at(seq, seq->len, s);
}

void sos_print(const struct sos *seq) {
  assert(seq);
  for (int i = 0; i < seq->len; i++) {
    printf("%s\n", seq->data[i]);
  }
}

const char *sos_item_at(const struct sos *seq, int pos) {
  assert(seq);
  return seq->data[pos];
}

void sos_remove_end(struct sos *seq) {
  free(seq->data[seq->len - 1]);
  seq->len--;
}

void sos_insert_at(struct sos *seq, int pos, const char *s) {
  if (seq->len == seq->maxlen) {
    seq->maxlen *= 2;
    seq->data = realloc(seq->data, seq->maxlen * sizeof(char *));
  }

 
  for (int i = seq->len - 1; i >= pos; i--) {
    seq->data[i + 1] = seq->data[i];
  }


  seq->data[pos] = malloc((strlen(s) + 1) * sizeof(char));
  strcpy(seq->data[pos], s);

  seq->len++;
}

void sos_remove_at(struct sos *seq, int pos) {
  assert(seq);

  free(seq->data[pos]); 
  for (int i = pos + 1; i < seq->len; i++) {
    seq->data[i - 1] = seq->data[i]; 
  }
  seq->len--;
}

void sos_replace_at(struct sos *seq, int pos, const char *s) {
  assert(seq);
  sos_remove_at(seq, pos);
  sos_insert_at(seq, pos, s);
}

void sos_swap(struct sos *seq, int pos1, int pos2) {
  assert(seq);
  char *temp = seq->data[pos1];
  seq->data[pos1] = seq->data[pos2];
  seq->data[pos2] = temp;
}

struct sos *sos_dup(const struct sos *seq) {
  struct sos *new_seq = sos_create();
  new_seq->maxlen = seq->maxlen;

  for (int i = 0; i < seq->len; i++) {
    char *str = seq->data[i];
    sos_insert_end(new_seq, str);
  }

  return new_seq;
}