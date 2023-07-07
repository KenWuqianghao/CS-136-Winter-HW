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

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "hangman-io.h"
#include "words.h"

char to_upper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}

char to_lower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

int in_alpahbet(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool search_guessed(char *str, char ch) {
    for (int i = 0; i < 26; i++) {
      if (str[i] == ch) {
        return true;
      }
    }
    return false;
}

bool check_win(char* board, int len) {
    for (int i = 0; i < len; i++) {
        if (board[i] == '*') {
            return false; // if any character is still a '*', the game is not won yet
        }
    }
    return true; // if all characters have been revealed, the game is won
}

void print_board(char* board, int len) {
    for (int i = 0; i < len; i++) {
        printf("%c", board[i]);
    }
    printf("\n");
}

int main(void) {
    int game_number;
    const char *word;

    while (true) {
        printf(enter_game_number, max_words);
        if (scanf("%d", &game_number) != 1 || game_number < 1 || game_number > max_words) {
            printf("%s", invalid_game_number);
            continue;
        }

        word = get_word(game_number);
        
        char board[51];
        board[50] = '\0';
        char guessed[27];
        guessed[26] = '\0';
        
        for (int i = 0; i < 26; i++) {
            guessed[i] = '0';
        }
        int len = strlen(word);
        int strikes = 0;

        for (int i = 0; i < len; i++) {
            if (board[i] == '\n') {
                continue;
            } else {
                board[i] = '*';
            }
        }

        while (1) {
            print_hangman(strikes);
            printf("%s", letter_prompt);
            print_board(board, len);

            char letter;
            while (scanf(" %c", &letter) != 1) {
                scanf(" %c", &letter);
            }

            if (!in_alpahbet(letter)) {
                printf(not_a_letter, letter);
                continue;
            }

            letter = to_upper(letter);

            if (search_guessed(guessed, letter)) {
                printf(already_guessed_letter, letter);
                continue;
            }

            bool found = false;

            for (int i = 0; i < len; i++) {
                if (word[i] == letter) {
                    board[i] = letter;
                    found = 1;   
                }
            }

            int pos = letter - 'A';
            guessed[pos] = letter;

            if (!found) {
                strikes++;
                printf(not_in_word, letter);
                if (strikes == max_strikes) {
                    print_hangman(strikes);
                    printf(game_over, word);
                    break;
                } else {
                    printf(not_last_guess, max_strikes - strikes);
                }
            }

            guessed[letter - 'A'] = letter;
            if (check_win(board, len)) {
                printf(congratulations, word);
                break;
            }
        }

        printf("%s", play_again);

        char response;
        while (scanf(" %c", &response) != 1 || (to_lower(response) != 'y' && to_lower(response) != 'n')) {
            printf("%s", invalid_play_again_response);
            printf("%s", play_again);
        }

        if (to_lower(response) == 'n') {
            break;
        }
    }

    return 0;
}