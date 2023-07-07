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

#include "cs136-trace.h"
#include <stdio.h>
#include <assert.h>

#include "cs136-trace.h"
#include <stdio.h>
#include <assert.h>

#include <stdio.h>
#include <stdlib.h>

struct nums {
    int first;
    int second;
    int third;
};

int main(void) {
    int length;
    scanf("%d", &length);

    struct nums number[1000];

    for (int i = 0; i < length; i++) {
        scanf("%d", &number[i].first);
    }
    for (int i = 0; i < length; i++) {
        scanf("%d", &number[i].second);
    }
    for (int i = 0; i < length; i++) {
        scanf("%d", &number[i].third);
    }

    for (int i = 0; i < length; i++) {
        int first_num  = number[i].first;
        int second_num = number[i].second;
        int third_num  = number[i].third;
        int sum = first_num + second_num + third_num;
        printf("%d\n", sum);
    }

    return 0;
}

