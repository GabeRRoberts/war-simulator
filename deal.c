#include "deal.h"

//this is the tough part i think

void shuffle(Card p1deck[], Card p2deck[]){

    srand(time(NULL));

    //Shuffles p1's deck.
    for(int i = 0; i < 30; i++){

        int c1 = 0, c2 = 0;
        Card temp;

        while(c1 == c2){
            c1 = rand() % 26;
            c2 = rand() % 26;
        }
        
        temp = p1deck[c1];
        p1deck[c1] = p1deck[c2];
        p1deck[c2] = temp;

    }

    //Shuffles p2's deck.
    for(int i = 0; i < 30; i++){

        int c1 = 0, c2 = 0;
        Card temp;

        while(c1 == c2){
            c1 = rand() % 26;
            c2 = rand() % 26;
        }
        
        temp = p2deck[c1];
        p2deck[c1] = p2deck[c2];
        p2deck[c2] = temp;

    }

    puts("Decks successfully shuffled.");
}

void deal_cards(Card p1deck[], Card p2deck[]){

    srand(time(NULL));

    //initializes to all zeroes.
    int draw[13][4]  = {0};

    int *p;

    int cards1 = 0, cards2 = 0;
    int coin;

    for(p = &draw[0][0]; p <= &draw[12][3]; p++){

        coin = rand() % 2;        

        if((cards1 < 26) && (cards2 < 26)){

            *p = coin;

            if(coin)
                cards1++;
            else
                cards2++;

        } else if (cards1 == 26){

            ;
            //card just stays 0

        } else if (cards2 == 26){

            *p = 1;

        }
        
    }

    for(p = &draw[0][0]; p <= &draw[12][3]; p++)
        printf("%d", *p);

    //We now have a draw array with 26 1's and 26 0's.
    //some indexing variables
    int p1index = 0, p2index = 0;

    //Runs through the entire draw array
    for(int row = 0; row < 13; row++)
        for(int column = 0; column < 4; column++){

        if(draw[row][column]){

            p1deck[p1index].value = row + 2;
            
            //Because enumerations are just disguised int values, this works.
            //values 0-3 will be CLUBS, DIAMONDS, HEARTS, and SPADES in that order.
            p1deck[p1index].suit = column;

            //increase index for next card.
            p1index++;

        } else {
            
            p2deck[p2index].value = row + 2;
            p2deck[p2index].suit = column;

            //increase index for next card.
            p2index++;
        
        }
    }

    puts("Cards successfully dealt.");

    shuffle(p1deck, p2deck);

    //Marks the end for each deck.
    p1deck[26].suit = END;
    p2deck[26].suit = END;

}
