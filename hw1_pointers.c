#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_TIME 200
#define MAX_NUM 100
#define SQUARES 70

int move_tortoise(int *ptr, int total_steps){
  int num = rand() % 10 + 1; // Generate random number between 1 to 10
  int index = 0;
  int mov = 0;

  if (num>=1 && num<=5){
      index = total_steps + 3;
      mov = 3;
  }
  else if (num>=6 && num<=7){
      index = total_steps - 6;
      mov = -6;
  }
  else if (num>=8 && num<=10){
      index = total_steps + 1;
      mov = 1;
  }

  *(ptr+index) = 1;

  return mov;

}

/* Calculate the hare's movements */
int move_hare(int *ptr, int total_steps){
    int num = rand() % 10 + 1; // Generate random number between 1 to 10
    int index = 0;
    int mov = 0;

    if (num>=1 && num<=2){
        index = total_steps;
        mov = 0;
    }
    else if (num>=3 && num<=4){
        index = total_steps + 9;
        mov = 9;
    }
    else if (num == 5){
        index = total_steps - 12;
        mov = -12;
    }
    else if (num>=6 && num<=8){
        index = total_steps + 1;
        mov = 1;
    }
    else if (num>=9 && num<=10){
        index = total_steps - 2;
        mov = -2;
  }

  *(ptr+index) = 2;

  return mov;

}

int race(){

  srand(time(NULL));

  int squares[MAX_NUM] = {0};
  int tortoise_steps = 0;
  int hare_steps = 0;
  int tortoise_step = 0;
  int hare_step = 0;
  int tick = 0;
  int *ptr = squares;

  ptr = (int*) malloc(MAX_NUM * sizeof(int));


  for(int i = 0; i < MAX_TIME; i++){

    int squares[MAX_NUM] = {0};

    tortoise_step = move_tortoise(squares, tortoise_steps);
    hare_step = move_hare(squares, hare_steps);

    // update the tortoise steps according to the latest movement.
    tortoise_steps += tortoise_step; 

    // update the hare steps according to the latest movement.
    hare_steps += hare_step; 

    // If the steps <= 1 then reset the step to 0.
    if (tortoise_steps <= 0){tortoise_steps = 0; ptr = NULL; squares[0] = 1;}
    if (hare_steps <= 0){hare_steps = 0; ptr = NULL; squares[0] = 2;}

    if (tortoise_steps == hare_steps){
      printf("%*cOUCH!!!\n", tortoise_steps, ' ');
      continue;
    }

    // if the tortoise pass the 70th square, and if it's a tie with hare, then favor the tortoise.
    if ((tortoise_steps >= hare_steps) && (tortoise_steps >= SQUARES)){
        printf("\nTORTOISE WINS!!! YAY!!!\n");
        free (ptr);
        return tick;
    }

    // if the hare pass the 70th square.
    if ((hare_steps > tortoise_steps) && (hare_steps >= SQUARES)){ 
        printf("\nHARE WINS. YUCH.\n");
        free (ptr);
        return tick;
    }

    for(int i = 0; i < MAX_NUM; i++){

      if (squares[i] == 0){printf(" ");}
      else if (squares[i] == 1){printf("T");}
      else if (squares[i] == 2){printf("H");}
      
    }

    printf("\n"); // move to a new line

    tick = i; // update the clock tick

  }

  free (ptr);
  return MAX_TIME; // return the max time of the clock

}


int main(){

    int tick = race(); // return the tick value

    // If the no one wins, then reset the clock until there is a winner.
    while (1){
        if (tick < MAX_TIME){
            printf("TIME ELAPSED - %d seconds\n", tick);
            return 0;
            }
        else{
            printf("NEITHER OF THEM WINS, CLOCK RESTART!!!\n\n\n");
            tick = race();
        }
    }
        
    return 0;
}