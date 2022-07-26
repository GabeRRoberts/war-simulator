#ifndef CARDS_H
#define CARDS_H

//Things I'll need (maybe)

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    
    int value;
    enum suit_value {CLUBS, DIAMONDS, HEARTS, SPADES, END} suit; 

} Card;

void print_cards(Card p1, Card p2, Card p1disc[], Card p2disc[]);

#endif