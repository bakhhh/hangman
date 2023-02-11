#include "word.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


word* animalWords() {
  word* words = malloc(11 * sizeof(word));

    strcpy(words[0].word, "dog");
    strcpy(words[0].characteristic, "A four-legged animal, often kept as a pet.");

    strcpy(words[1].word, "cat");
    strcpy(words[1].characteristic, "A small carnivorous animal, often kept as a pet.");

    strcpy(words[2].word, "frog");
    strcpy(words[2].characteristic, "A cold-blooded amphibian with smooth skin and long hind legs.");

    strcpy(words[3].word, "chicken");
    strcpy(words[3].characteristic, "A domesticated bird used as a source of food.");

    strcpy(words[4].word, "bird");
    strcpy(words[4].characteristic, "A warm-blooded egg-laying vertebrate with feathers and wings.");
    strcpy(words[5].word, "tiger");

    strcpy(words[5].characteristic, "A large carnivorous feline native to Asia, with distinctive orange fur and black stripes.");

    strcpy(words[6].word, "lion");
    strcpy(words[6].characteristic, "A large carnivorous feline native to Africa, with a mane and distinctive golden fur.");

    strcpy(words[7].word, "elephant");
    strcpy(words[7].characteristic, "The largest land animal, with a long trunk and large ears, native to Africa and Asia.");

    strcpy(words[8].word, "giraffe");
    strcpy(words[8].characteristic, "A long-necked African mammal with distinctive brown and white patches on its fur.");

    strcpy(words[9].word, "kangaroo");
    strcpy(words[9].characteristic, "An Australian marsupial with large hind legs and a tail, known for hopping as a means of locomotion.");

    strcpy(words[10].word, "turtle");
    strcpy(words[10].characteristic, "A slow-moving reptile with a hard shell that protects its body.");

    return words;
}
