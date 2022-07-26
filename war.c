#include "cards.h"
#include "deal.h"

//This will be the game loop that contains main

int main(void){

    Card p1_draw[53], p2_draw[53], p1_discard[53], p2_discard[53];

    //Deals and shuffles the cards.
    deal_cards(p1_draw, p2_draw);

    int p1_index = 0, p2_index = 0;
    int p1_score = 0, p2_score = 0;

    //Short game that goes through the deck once.
    while(p1_index <= 25){

        //Prints the battle
        print_cards(p1_draw[p1_index], p2_draw[p2_index], p1_discard, p2_discard);

        //If player 1 wins
        if(p1_draw[p1_index].value > p2_draw[p2_index].value)
            p1_score++;
        //If player 2 wins
        else if(p1_draw[p1_index].value < p2_draw[p2_index].value)
            p2_score++;
        //Draw
        else;

        //Print the score.
        printf("Current score | Player 1: %d, Player 2: %d\n", p1_score, p2_score);

        p1_index++;
        p2_index++;


        getchar();

    }

    printf("Final score | Player 1: %d, Player 2: %d\n", p1_score, p2_score);

    if(p1_score > p2_score)
        puts("Congratulations to player 1!");
    else if(p2_score > p1_score)
        puts("Congratulations to player 2!");
    else
        puts("Well fought, but this is a draw.");

    return 0;

}