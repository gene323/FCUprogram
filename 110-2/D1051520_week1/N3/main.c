#include "deal.c"
#include "shuffle.c"

int main(){
    //SUITS 4
    //FACES 13
    //CARDS 52
    int poker[SUITS][FACES] = {0};

    srand(time(NULL));
    
    shuffle(poker);

    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *face[FACES] = 
    {"Ace", "Deuce", "Three", "Four",         
    "Five", "Six", "Seven", "Eight",         
    "Nine", "Ten", "Jack", "Queen", "King"};

    deal(poker, suit, face);
    return 0;
}