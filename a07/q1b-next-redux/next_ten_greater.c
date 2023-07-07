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

#include "next_ten_greater.h"

// Assume this is the maximum array length (if you want/need it)
const int MAX_LEN = 10000;

// time:
//   justification:
int next_ten_greater(const int arr[], int len, int value, int result[]) {
  int greater_arr[10000];
  int current = 0;

  for (int i = 0; i < len; i++) {
    if (arr[i] > value) {
      greater_arr[current] = arr[i];
      current++;
    }
  }

  int result_len = current;
  int base = value;

  for (int i = 0; i < current; i++) {
    int min = greater_arr[i];
    int min_index = i;
    for (int j = i + 1; j < current; j++) {
      if ((greater_arr[j] < min) && (greater_arr[j] > base)) {
        min = greater_arr[j];
        min_index = j;
      }
    }
    result[i] = min;
    base = min;
    greater_arr[min_index] = greater_arr[i];
  }
  
  if (result_len > 10) {
    result_len = 10;
  }

  return result_len;
}

