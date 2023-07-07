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

// Implementation of a triple_s (SSS) ADT

// This is a "wrapper" ADT that provides a triple_s ADT interface, but all of the data
// is actually stored inside of an SOS ADT

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "cs136-trace.h"
#include "sos.h"
#include "sss.h"

//////////////////////////////////////////////////////////////////////////////
// DO NOT MODIFY THE FOLLOWING DEFINITION

struct triple_s {
  struct sos *seq;
};

//////////////////////////////////////////////////////////////////////////////
struct triple_s *sss_create(void) {
  struct triple_s *new_sss = malloc(sizeof(struct triple_s));
  new_sss->seq = sos_create();
  return new_sss;
}

void sss_destroy(struct triple_s *sss) {
  assert(sss);
  sos_destroy(sss->seq);
  free(sss);
}

int sss_count(const struct triple_s *sss) {
  assert(sss);
  return sos_length(sss->seq);
}

int sss_search(const struct triple_s *sss, const char *s) {
  for (int i = 0; i < sos_length(sss->seq); i++) {
    if (strcmp(sos_item_at(sss->seq, i), s) == 0) {
      return i;
    }
  }
  return -1;
}

const char *sss_get(const struct triple_s *sss, int idx) {
  return sos_item_at(sss->seq, idx);
}

void sss_add(struct triple_s *sss, const char *s) {
  if (sos_length(sss->seq) == 0) {
    sos_insert_end(sss->seq, s);
    return;
  }

  if (sss_search(sss, s) == -1) {
    for (int i = 0; i < sos_length(sss->seq); i++) {
      if (strcmp(sos_item_at(sss->seq, i), s) > 0) {
        sos_insert_at(sss->seq, i, s);
        return;
      }
    }
  } else {
    return;
  }
}

void sss_add_follows(struct triple_s *sss, const char *s) {
  sos_insert_end(sss->seq, s);
}

void sss_remove(struct triple_s *sss, const char *s) {
  if (sss_search(sss, s) != -1) {
    sos_remove_at(sss->seq, sss_search(sss, s));
  }
}