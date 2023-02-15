#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "word.h"
#include <unistd.h>
#define true 1
#define false 0



void animate_print(char *str) {
    int i;
    for (i = 0; str[i]; i++) {
        printf("%c", str[i]);
        fflush(stdout);
        usleep(100000);
    }
}

void makeLower(char option[], char lowerGuess[]){
    int i;
    for (i = 0; option[i]; i++) {
        lowerGuess[i] = tolower(option[i]);
    }
    lowerGuess[i] = '\0';
}

void clue(word *words,int randomIndex){
    printf("\n*CLUE* %s\n",words[randomIndex].characteristic);

}

void gameLoop(char *display, word *words, int randomIndex, int *correct_guesses, int *incorrect_guesses, int *score){
    int found = false;
    char letter;
    char option[100];
    char guess[100];
    char lowerOption[100];
    char lowerGuess[100];
    char lowerLetter[100];
    int i,j;
    while (*incorrect_guesses < 7 && *correct_guesses < strlen(words[randomIndex].word) && (strcmp(guess, words[randomIndex].word) != 0)){
        printf("\nCorrect Guesses %d/%lu                             Lives %d/7\n",*correct_guesses,strlen(words[randomIndex].word),*incorrect_guesses);
        printf("\nScore: %d",*score);
        printf("\nWord: %s\n", display);

        printf("\nWould you like to guess the word [YES][NO]: ");
        scanf("%s", option);
        makeLower(option,lowerOption);

        if (strcmp(lowerOption, "yes") == 0) {
            printf("\nEnter your guess: ");
            scanf(" %s", guess);
            makeLower(guess,lowerGuess);
            
            if (strcmp(lowerGuess, words[randomIndex].word) == 0) {
                printf("\nCongratulations! You guessed the word correctly.\n");
                *correct_guesses =0;
                (*score) ++;
                break;
            }
            else if (strcmp(lowerGuess, words[randomIndex].word) != 0){
                printf("\nYour guess is incorrect.\n");
                (*incorrect_guesses)+=2;
                system("clear");
            }

        }
        else if (strcmp(lowerOption, "no") == 0) {
            printf("\nEnter your letter guess: ");
            scanf(" %c", &letter);
            makeLower(&letter,lowerLetter);

            found = false;
            for (i = 0; i < strlen(words[randomIndex].word); i++) {
                if ((words[randomIndex].word)[i] == *lowerLetter) {
                    printf("\nThe letter '%s' was found in the word.\n", lowerLetter);
                    display[i] = *lowerLetter;
                    found = true;
                    (*correct_guesses)++;

                    for (j = i + 1; j < strlen(words[randomIndex].word); j++) {
                        if ((words[randomIndex].word)[j] == *lowerLetter) {
                            display[j] = *lowerLetter;
                            (*correct_guesses)++;
                        }
                    }
                    system("clear");
                    break;
                }
            }

            if (found == false) {
                printf("\nThe letter '%s' was not found in the word.\n", lowerLetter);
                (*incorrect_guesses) ++;
                system("clear");
            }
            if (*correct_guesses == strlen(words[randomIndex].word)) {
                printf("\nCongratulations! You guessed the word correctly.\n");
                *correct_guesses = 0;
                (*score) ++;
                break;
    }
        if (*incorrect_guesses == 5){
            clue(words,randomIndex);
    }

    }
    }
}

