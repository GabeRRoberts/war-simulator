#include "cards.h"

void print_diamond(int value, int row){

    switch(row){
        case 1: printf("         #         "); break;
        case 2: printf("        ###        "); break;
        case 3: printf("       #####       "); break;
        case 4: printf("      #######      "); break;
        case 5: printf("     ##     ##     "); break;
        case 6: if(value < 11) 
                    {printf("    ### %2d  ###    ", value);} 
                else
                    switch (value)
                    {
                    case 11: printf("    ###  J  ###    "); break;
                    case 12: printf("    ###  Q  ###    "); break;
                    case 13: printf("    ###  K  ###    "); break;
                    case 14: printf("    ###  A  ###    "); break;
                    }     
            break;

        case 7: printf("     ##     ##     "); break;
        case 8: printf("      #######      "); break;
        case 9: printf("       #####       "); break;
        case 10: printf("        ###        "); break;
        case 11: printf("         #         "); break;

    }
}

void print_heart(int value, int row){

    switch(row){
        case 1: printf("   ####     ####   "); break;
        case 2: printf("  ######   ######  "); break;
        case 3: printf(" ######## ######## "); break;
        case 4: printf(" ################# "); break;
        case 5: printf(" ######     ###### "); break;
        case 6: if(value < 11) 
                    {printf("  ##### %2d  #####  ", value);} 
                else
                    switch (value)
                    {
                    case 11: printf("  #####  J  #####  "); break;
                    case 12: printf("  #####  Q  #####  "); break;
                    case 13: printf("  #####  K  #####  "); break;
                    case 14: printf("  #####  A  #####  "); break;
                    }     
            break;
            
        case 7: printf("    ###     ###    "); break;
        case 8: printf("     #########     "); break;
        case 9: printf("      #######      "); break;
        case 10: printf("        ###        "); break;
        case 11: printf("         #         "); break;

    }
}

void print_spade(int value, int row){

    switch(row){
        case 1: printf("         #         "); break;
        case 2: printf("        ###        "); break;
        case 3: printf("       #####       "); break;
        case 4: printf("      #######      "); break;
        case 5: printf("    ###     ###    "); break;
        case 6: if(value < 11) 
                    {printf("   #### %2d  ####   ", value);} 
                else
                    switch (value)
                    {
                    case 11: printf("   ####  J  ####   "); break;
                    case 12: printf("   ####  Q  ####   "); break;
                    case 13: printf("   ####  K  ####   "); break;
                    case 14: printf("   ####  A  ####   "); break;
                    }     
            break;
            
        case 7: printf(" ######     ###### "); break;
        case 8: printf("###################"); break;
        case 9: printf("###################"); break;
        case 10: printf(" ####   ###   #### "); break;
        case 11: printf("      #######      "); break;

    }
}

void print_club(int value, int row){

    switch(row){
        case 1: printf("      #######      "); break;
        case 2: printf("     #########     "); break;
        case 3: printf("     #########     "); break;
        case 4: printf("     #########     "); break;
        case 5: printf("  #####     #####  "); break;
        case 6: if(value < 11) 
                    {printf(" ###### %2d  ###### ", value);} 
                else
                    switch (value)
                    {
                    case 11: printf(" ######  J  ###### "); break;
                    case 12: printf(" ######  Q  ###### "); break;
                    case 13: printf(" ######  K  ###### "); break;
                    case 14: printf(" ######  A  ###### "); break;
                    }     
            break;
            
        case 7: printf(" ######     ###### "); break;
        case 8: printf(" ################# "); break;
        case 9: printf("  #####  #  #####  "); break;
        case 10: printf("        ###        "); break;
        case 11: printf("      #######      "); break;

    }
}


void print_cards(Card p1, Card p2, Card p1disc[], Card p2disc[]){

    for(int i = 1; i <= 11; i++){

        switch (p1.suit)
        {
            case DIAMONDS: print_diamond(p1.value, i); break;
            case CLUBS: print_club(p1.value, i); break;
            case HEARTS: print_heart(p1.value, i); break;
            case SPADES: print_spade(p1.value, i); break;
        }
        
        if(i == 6)
            printf(" V. ");
        else
            printf("    ");
        
        switch (p2.suit)
        {
            case DIAMONDS: print_diamond(p2.value, i); break;
            case CLUBS: print_club(p2.value, i); break;
            case HEARTS: print_heart(p2.value, i); break;
            case SPADES: print_spade(p2.value, i); break;
        }
        
        puts("");

    }

    determine_winner(p1, p2, p1disc, p2disc);

}

void determine_winner(Card p1, Card p2, Card p1disc[], Card p2disc[]){

    //Numerical comparision
    if(p1.value > p2.value){
        //p1 needs the cards
        puts("\tPlayer 1 wins this round!");
        int i = 0;

        while(p1disc[i].suit != END)
            i++;

        //Gives new cards and marks the end
        p1disc[i] = p1;
        p1disc[i+1] = p2;
        p1disc[i+2].suit = END;

    }

    //Numerical comparision
    if(p1.value < p2.value){
        //p2 needs the cards
        puts("\tPlayer 2 wins this round!");

        int i = 0;

        while(p2disc[i].suit != END)
            i++;

        //Gives new cards and marks the end
        p2disc[i] = p1;
        p2disc[i+1] = p2;
        p2disc[i+2].suit = END;

    }

    //Numerical comparision
    if(p1.value == p2.value){
        //Just discard them
        puts("Draw. Cards discarded to original player.");
        int i = 0, j = 0;

        while(p1disc[i].suit != END)
            i++;

        while(p2disc[j].suit != END)
            j++;

        //Gives new cards and marks the end
        p1disc[i] = p1;
        p1disc[i+1].suit = END;
        
        p2disc[j] = p2;
        p2disc[j+1].suit = END;
    }

}
