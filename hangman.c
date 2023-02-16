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
    int score=0;
    char ready[10];
    int exitloop = true;
    int randomIndex;


    word *words;
    words = animalWords();


    
    while(exitloop == true){
        animate_print("\nWelcome to hangman\n");
        printf("\nGOAL: YOU NEED TO FIGURE OUT THE WORD BEFORE THE PLAYER GETS HUNG\nYOU HAVE 7 CHANCES FOR EACH INCORRECT LETTER YOU LOSE A CHANCE AND FOR EACH INCORRECT GUESS YOU LOSE 2 CHANCES\n");
        animate_print("\nARE YOU READY [YES][NO]: ");
        scanf("%s",ready);

        if (strcmp(ready, "yes") == 0){
            exitloop= false;
            while(incorrect_guesses!= 7){
                srand(time(NULL));
                randomIndex = rand() % 20;
                display = malloc(strlen(words[randomIndex].word)*sizeof(char));
                /* initialize the display array with underscores*/
                for (i = 0; i < strlen(words[randomIndex].word); i++) {
                    display[i] = '_';
                }
                display[i] = '\0';
                
                system("clear");
                gameLoop(display,words,randomIndex,&correct_guesses,&incorrect_guesses,&score);
            }

        }
    
        else if (strcmp(ready, "no") == 0) {
            system("clear");
            continue;
  }
    }

    if (incorrect_guesses >= 7) {
        printf("-------\n"
                "|     |\n"
                "|     0\n"
                "|    /|\\\n"
                "|    | |\n"
                "|\n"
                "|---------\n");

        printf("\nYou Lose the word was %s\n",words[randomIndex].word);
        printf("\nScore %d\n",score);



    }



    free(display);

    return 0;
}



