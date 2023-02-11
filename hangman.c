#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "word.h"
#define true 1
#define false 0


int main() {
    int correct_guesses = 0;
    int incorrect_guesses = 0;
    char letter;
    int found = false;
    char option[100];
    char guess[100];
    word *words;
    words = animalWords();

    srand(time(NULL));
    int randomIndex = rand() % 10;

    printf("Welcome to hangman\n");
    printf("*CLUE* %s\n",words[randomIndex].characteristic);
    

    while (incorrect_guesses < 7 && correct_guesses < strlen(words[randomIndex].word) && (strcmp(guess, words[randomIndex].word) != 0)){
        printf("Would you like to guess the word [YES][NO]: ");
        scanf("%s", option);

        if (strcmp(option, "yes") == 0) {
            printf("Enter your guess: ");
            scanf(" %s", guess);
            
            if (strcmp(guess, words[randomIndex].word) == 0) {
                printf("Congratulations! You guessed the word correctly.\n");
                break;
            }
            else if (strcmp(guess, words[randomIndex].word) != 0){
                printf("Your guess is  incorrect.\n");
                incorrect_guesses+=2;
            }
        }
        else if (strcmp(option, "no") == 0) {
            printf("Enter your letter guess: ");
            scanf(" %c", &letter);

            found = false;
            for (int i = 0; i < strlen(words[randomIndex].word); i++) {
                if ((words[randomIndex].word)[i] == letter) {
                    printf("The letter '%c' was found in the word.\n", letter);
                    found = true;
                    correct_guesses++;
                    break;
                }
            }

            if (found == false) {
                printf("The letter '%c' was not found in the word.\n", letter);
                incorrect_guesses ++;
            }
        }
    }

    if (incorrect_guesses >= 7) {
        printf("\nUnlucky You Lose\n");
    }

    if (correct_guesses == strlen(words[randomIndex].word)) {
        printf("\nYou Win\n");
    }

    return 0;
}
