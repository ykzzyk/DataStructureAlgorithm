#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_TIME 200

/* Calculate the tortoise's movements */
int tortoise_movement(){
    int num = rand() % 10 + 1; // Generate random number between 1 to 10
    int mov = 0;

    if (num>=1 && num<=5){
        mov = 3;
    }
    else if (num>=6 && num<=7){
        mov = -6;
    }
    else if (num>=8 && num<=10){
        mov = 1;
    }

    return mov;

}

/* Calculate the hare's movements */
int hare_movement(){
    int num = rand() % 10 + 1; // Generate random number between 1 to 10
    int mov = 0;

    if (num>=1 && num<=2){
        mov = 0;
    }
    else if (num>=3 && num<=4){
        mov = 9;
    }
    else if (num == 5){
        mov = -12;
    }
    else if (num>=6 && num<=8){
        mov = 1;
    }
    else if (num>=9 && num<=10){
        mov = -2;
    }
    return mov;
}

/* Print the current location of the tortoise and the hare */
void print_location(tortoise_steps, hare_steps){
    // the tortoise faster than the hare
    if (tortoise_steps > hare_steps){
        printf("%*c", (hare_steps - 1), ' ');
        printf("H");
        printf("%*c", abs(tortoise_steps - hare_steps) - 1, ' ');
        printf("T");
    }
    // the tortoise slower than the hare
    else if (tortoise_steps < hare_steps){
        printf("%*c", (tortoise_steps - 1), ' ');
        printf("T");
        printf("%*c", abs(tortoise_steps - hare_steps) - 1, ' ');
        printf("H");
    }
    // the tortoise and the hare are in the same location
    else if (tortoise_steps == hare_steps){ 
        printf("%*c", (tortoise_steps - 1), ' ');
        printf("OUCH!!!");
    }
}

/* The race between tortoise and hare */
int race(){

    srand(time(NULL)); // for generating the random numbers

    // specify variales
    int tortoise_steps = 0;
    int hare_steps = 0;
    int tortoise_mov = 0;
    int hare_mov = 0;
    int tick = 0;

    printf("ON YOUR MARK, GET SET\n");
    printf("BANG             !!!!!\n");
    printf("AND THEY ARE OFF !!!!!\n");
    
    for(int i = 1; i <= MAX_TIME; i++){
        tortoise_mov = tortoise_movement(); // calculate the tortoise's latest movement.
        hare_mov = hare_movement(); // calculate the hare's latest movement.

        tortoise_steps += tortoise_mov; // update the tortoise steps according to the latest movement.
        hare_steps += hare_mov; // update the hare steps according to the latest movement.

        // If the steps <= 1 then reset the step to 0.
        if (tortoise_steps < 0){tortoise_steps = 0;}
        if (hare_steps < 0){hare_steps = 0;}
        
        print_location(tortoise_steps, hare_steps); // print the current location for the tortoise and the hare

        if ((tortoise_steps >= hare_steps) && (tortoise_steps >= 70)){  // if the tortoise pass the 70th square, and if it's a tie with hare, then favor the tortoise.
            printf("\nTORTOISE WINS!!! YAY!!!\n");
            return tick;
        }
        if ((hare_steps > tortoise_steps) && (hare_steps >= 70)){ // if the hare pass the 70th square.
            printf("\nHARE WINS. YUCH.\n");
            return tick;
        }

        printf("\n"); // move to a new line

        tick = i; // update the clock tick
    }

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