#include "word.h"
#ifndef GAME_FUNCTIONS
#define GAME_FUNCTIONS

void animate_print(char *str);
void makeLower(char option[], char lowerGuess[]);
void clue(word *words,int randomIndex);
void gameLoop(char *display, word *words, int randomIndex, int *correct_guesses, int *incorrect_guesses,int *score);



#endif

