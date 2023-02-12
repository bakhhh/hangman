#include "word.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


word* animalWords() {
  word* words = (word*)malloc(20 * sizeof(word));

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
 
    strcpy(words[11].word, "horse");
    strcpy(words[11].characteristic, "A large domesticated mammal with a mane and tail, used for riding and transportation.");

    strcpy(words[12].word, "fish");
    strcpy(words[12].characteristic, "A cold-blooded aquatic animal with fins and scales, often used for food and recreation.");

    strcpy(words[13].word, "snake");
    strcpy(words[13].characteristic, "A long, legless reptile with smooth scales, often feared because of its reputation as a predator.");

    strcpy(words[14].word, "monkey");
    strcpy(words[14].characteristic, "A primate with opposable thumbs and a long tail, found in tropical regions around the world.");

    strcpy(words[15].word, "wolf");
    strcpy(words[15].characteristic, "A large carnivorous mammal with keen senses, known for its distinctive howl and pack behavior.");
    
    strcpy(words[16].word, "hippopotamus");
    strcpy(words[16].characteristic, "A large, semiaquatic mammal native to Africa, known for its aggressive behavior and powerful jaws.");
    
    strcpy(words[17].word, "squirrel");
    strcpy(words[17].characteristic, "A small, bushy-tailed rodent known for gathering and storing food for the winter.");

    strcpy(words[18].word, "dolphin");
    strcpy(words[18].characteristic, "A highly intelligent marine mammal with a streamlined body and flippers, known for its playful behavior.");

    strcpy(words[19].word, "gorilla");
    strcpy(words[19].characteristic, "A large, ground-dwelling primate native to Africa, known for its strength and intelligence.");





    return words;
}
