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

#include "arrayfun_improved.h"

int divides_followers(const int a[], int n) {
  int sum = 0;
  int counter = 0;

  for (int i = 0; i < n; i++) {
    sum += a[i];
  }

  for (int i = 0; i < n; i++) {
    sum = sum - a[i];
    if (sum % a[i] == 0) {
      counter++;
    }
  }

  return counter;
}	

bool consec_sum(const int a[], int n, const int b[], int m) {
  int sum;
  int mid;
  int left = 0;
  int right = m - 1;

  for (int i = 0; i < n - 1; i++) {
    sum = a[i] + a[i + 1];
    left = 0;
    right = m - 1;
    
    while (left <= right) {
        mid = (left + right) / 2;

        if (b[mid] == sum) {
            return true;
        } else if (b[mid] < sum) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
  }

  return false;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void even_first(int a[], int n) {
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 0) {
      swap(&a[i], &a[0]);
    }
  }

  int current = 1;

  for (int i = 1; i < n; i++) {
    if (a[i] % 2 == 0) {
      swap(&a[i], &a[current]);
      current++;
    }
  }
}