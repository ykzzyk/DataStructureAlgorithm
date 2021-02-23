#include <stdio.h>
#include <stdlib.h>


int main(){

  char * article[5] = {"the", "a", "one", "some", "any"};

  char * noun[5] = {"boy", "girl", "dog", "town", "car"};

  char * verb[5] = {"drove", "jumped", "ran", "walked", "skipped"};

  char * preposition[5] = {"to", "from", "over", "under", "on"};

  char * sentence[6];

  int i = 0;
  int j = 0;
  int num = 0;

  for (i = 0; i < 20; i++){
    num = rand() % 5; // generate number from 0 to 4
    sentence[0] = article[num]; // generate the random article

    num = rand() % 5; // generate number from 0 to 4
    sentence[1] = noun[num]; // generate the random noun

    num = rand() % 5; // generate number from 0 to 4
    sentence[2] = verb[num]; // generate the random verb

    num = rand() % 5; // generate number from 0 to 4
    sentence[3] = preposition[num]; // generate the random preposition

    num = rand() % 5; // generate number from 0 to 4
    sentence[4] = article[num]; // generate the random article again

    num = rand() % 5; // generate number from 0 to 4
    sentence[5] = noun[num]; // generate the random noun again

    // print out the sentence
    for (j = 0; j < 6; j++){
      printf("%s ", sentence[j]);
    }

    printf("\n");
  
  }