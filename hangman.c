#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "word.h"
#include "gameFunctions.h"
#include <unistd.h>
#define true 1
#define false 0



int main() {
    int correct_guesses = 0;
    int incorrect_guesses = 0;
    char *display;
    int i;
    char ready[10];
    int exitloop = true;
    int randomIndex;

    word *words;
    words = animalWords();

    srand(time(NULL));
    randomIndex = rand() % 20;
    display = malloc(strlen(words[randomIndex].word)*sizeof(char));

    /* initialize the display array with underscores*/
    for (i = 0; i < strlen(words[randomIndex].word); i++) {
        display[i] = '_';
    }
    display[i] = '\0';
    
    while(exitloop == true){
        animate_print("\nWelcome to hangman\n");
        printf("\nGOAL: YOU NEED TO FIGURE OUT THE WORD BEFORE THE PLAYER GETS HUNG\nYOU HAVE 7 CHANCES FOR EACH INCORRECT LETTER YOU LOSE A CHANCE AND FOR EACH INCORRECT GUESS YOU LOSE 2 CHANCES\n");
        animate_print("\nARE YOU READY [YES][NO]: ");
        scanf("%s",ready);

        if (strcmp(ready, "yes") == 0){
            exitloop= false;
            system("clear");
            gameLoop(display,words,randomIndex,&correct_guesses,&incorrect_guesses);

        }
    
        else if (strcmp(ready, "no") == 0) {
            system("clear");
            continue;
  }
    }

    if (incorrect_guesses >= 7) {
        printf("\nYou Lose the word was %s\n",words[randomIndex].word);
    }

    if (correct_guesses == strlen(words[randomIndex].word)) {
        printf("\nCongratulations! You guessed the word correctly.\n");
    }

    free(display);

    return 0;
}
