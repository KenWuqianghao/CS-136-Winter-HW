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

#include <assert.h>
#include <stdbool.h>
#include "cs136-trace.h"
#include <string.h>

bool is_valid_password(const char *s){
  int len = strlen(s);
  if (len != 8) {
    return 0;
  }

  for (int i = 0; i < len; i++) {
    if (65 <= s[i] && s[i] <= 90) {
      break;
    } else if (i == len - 1) {
      return false;
    }
  }

  for (int i = 0; i < len; i++) {
    if (97 <= s[i] && s[i] <= 122) {
      break;
    } else if (i == len - 1) {
      return false;
    }
  }

  for (int i = 0; i < len; i++) {
    if (48 <= s[i] && s[i] <= 57) {
      break;
    } else if (i == len - 1) {
      return false;
    }
  }

  for (int i = 0; i < len; i++) {
    if ((33 <= s[i] && s[i] <= 47) || (33 <= s[i] && s[i] <= 47) || (33 <= s[i] && s[i] <= 47) ||   (33 <= s[i] && s[i] <= 47)) {
      break;
    } else if (i == len - 1) {
      return false;
    }
  }

  for (int i = 0; i < len; i++) {
    if (s[i] == 32 || s[i] > 126 || s[i] < 32) {
      return false;
    }
  }
  
  return true;
}

int main(void){
  assert(is_valid_password("Tru$tNo1"));
  assert(!is_valid_password("trustno1"));
  // add tests!
  trace_msg("ALL ASSERTIONS PASSED!")
}