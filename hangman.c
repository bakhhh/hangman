#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
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

int main() {
    int correct_guesses = 0;
    int incorrect_guesses = 0;
    char letter;
    int found = false;
    char *display;
    char option[100];
    char guess[100];
    char lowerOption[100];
    char lowerGuess[100];
    char lowerLetter[100];
    int i;
    int randomIndex;
    word *words;
    words = animalWords();

    srand(time(NULL));
    randomIndex = rand() % 11;
    display = malloc(strlen(words[randomIndex].word)*sizeof(char));

    /* initialize the display array with underscores*/
    for (i = 0; i < strlen(words[randomIndex].word); i++) {
        display[i] = '_';
    }
    display[i] = '\0';

    printf("\nWelcome to hangman\n");

    

    while (incorrect_guesses < 7 && correct_guesses < strlen(words[randomIndex].word) && (strcmp(guess, words[randomIndex].word) != 0)){
        printf("\nCorrect Guesses %d/%lu                             Lives %d/7\n",correct_guesses,strlen(words[randomIndex].word),incorrect_guesses);
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
                break;
            }
            else if (strcmp(lowerGuess, words[randomIndex].word) != 0){
                printf("\nYour guess is incorrect.\n");
                incorrect_guesses+=2;
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
                    correct_guesses++;
                    break;
                }
            }

            if (found == false) {
                printf("\nThe letter '%s' was not found in the word.\n", lowerLetter);
                incorrect_guesses ++;
            }
        if (incorrect_guesses == 3){
            clue(words,randomIndex);
    }

        }
    }

    if (incorrect_guesses >= 7) {
        printf("\nYou Lose the word was %s\n",words[randomIndex].word);
    }

    if (correct_guesses == strlen(words[randomIndex].word)) {
        printf("\nYou Win\n");
    }

    return 0;
}
