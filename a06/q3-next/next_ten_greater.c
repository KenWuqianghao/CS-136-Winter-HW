/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// Name: Ken Wu
// login ID: 20999205
//////////////////////////////////////////////////////////////////////////////////////////

#include "next_ten_greater.h"

// Assume this is the maximum array length (if you want/need it)
const int MAX_LEN = 10000;

// copyArray(src,dest,n) copy a const array into a mutable array
// requires: n >= 0;
// effects: modifies dest
void copyArray(const int *src, int *dest, int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

// sort_ls(arr, len) sort an array into acsending order
// requires: length of result >= 10 [not asserted] 
//           (but at most 10 elements will be added)
//        - len > 0
//        - arr and result are not NULL
// effects： modifies arr[]
void sort_ls(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int next_ten_greater(const int arr[], int len, int value, int result[]) {
    int cp_arr[10000];
    copyArray(arr, cp_arr, len);
    sort_ls(cp_arr, len);
    int count = 0;
    for (int i = 0; i < len && count < 10; i++) {
        if (value < cp_arr[i]) {
            result[count] = cp_arr[i];
            count++;
        }
    }
    return count;
}