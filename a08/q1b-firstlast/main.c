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

// This program is an introduction to using dynamic memory

// A "word" is a sequence of printable non-whitespace charcters (see modules/string-io.h)

// all words in the input are read in and then two words are printed out,
// each on a separate line:
// * the lexicographically "first" word, and then
// * the lexicographially "last" word

// (comparing public.in and public.expect will help illustrate)

// If no words appear in the input then "INVALID INPUT\n" is printed
// If only one word appears, it is both the first and the last word and so it
// is printed twice

// Words should be compared lexicographically using strcmp()
// (you do not have to worry about about upper case, lower case, etc... just use strcmp)

// All input should be read using read_word() (see modules/string-io.h)
// All output should be printed as printf("%s\n", ...)

// Remember, this is an exercise in using dynamic memory, so endeavour to
// use malloc and free appropriately, and don't forget that the strings
// returned by read_word() must eventually be freed

//////////////////////////////////////////////////////////////////////////////

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cs136-trace.h"
#include "string-io.h"

int main(void) {
  char *min = read_word();
  
  if (min == NULL) {
    printf("INVALID INPUT\n");
    return 0;
  }

  char *max = malloc((strlen(min) + 1) * sizeof(char));
  strcpy(max, min);

  while (1) {
    char *word = read_word();
    if (word == NULL) {
      break;
    }
    
    if (strcmp(word, min) > 0) {
      int len = strlen(word);
      min = realloc(min, len + 1);
      strcpy(min, word);
    } else if (strcmp(word, max) < 0) {
      int len = strlen(word);
      max = realloc(max, len + 1);
      strcpy(max, word);
    }
    
    free(word);
  }
  
  printf("%s\n", max);
  printf("%s\n", min);
  
  free(min);
  free(max);
}
